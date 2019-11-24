#include "mapwindow.hh"
#include "ui_mapwindow.h"

#include "graphics/simplemapitem.h"
#include "highscoredialog.hh"
#include "assigndialog.hh"
#include "unassigndialog.hh"
#include "startdialog.hh"
#include "setplayerdialog.hh"
#include "gamescene.hh"


#include <math.h>


int X_SIZE = 10;
int Y_SIZE = 10;


MapWindow::MapWindow(QWidget *parent,
                     std::shared_ptr<GameEventHandler> handler):
    QMainWindow(parent),
    m_ui(new Ui::MapWindow),
    m_GEHandler(handler),
    m_scene(new GameScene(this)),
    m_objectmanager(new ObjectManager())
{
    m_ui->setupUi(this);
    m_ui->assignButton->setEnabled(false);
    m_ui->unassignButton->setEnabled(false);
    m_ui->buildButton->setEnabled(false);


    m_workerButtonGroup = std::make_shared<QButtonGroup>(this);
    std::vector<QAbstractButton*> workerButtons = {m_ui->bwButton, m_ui->loggerButton,
                                               m_ui->farmerButton, m_ui->minerButton };


    m_buildingButtonGroup = std::make_shared<QButtonGroup>(this);
    std::vector<QAbstractButton*> buildingButtons = {m_ui->hqButton, m_ui->farmButton,
                                               m_ui->mineButton, m_ui->sawButton, m_ui->outpustButton,
                                                     m_ui->apartmentsButton, m_ui->skyscraperButton,
                                                     m_ui->largeHouseButton, m_ui->smallHouseButton };

    setupButtonGroup(workerButtons, m_workerButtonGroup);
    setupButtonGroup(buildingButtons, m_buildingButtonGroup);

    setStyleWorkerButtons();

    GameScene* sgs_rawptr = m_scene.get();

    Course::WorldGenerator& generator = Course::WorldGenerator::getInstance();
    addTiles(generator);

    for(int x = 0; x < X_SIZE; ++x){
        for(int y = 0; y < Y_SIZE; ++y){
            sgs_rawptr->drawItem(m_objectmanager->getTile(Course::Coordinate(x,y)));
        }
    }

    m_ui->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(sgs_rawptr));

    m_ui->bwButton->setCheckable(true);
    m_ui->bwButton->setStyleSheet(
                "QPushButton {border-image: url(:/workerIcons/worker.png)}"
                "QPushButton:checked {border-image: url(:/workerIcons/worker_selected.png)}");

    m_ui->loggerButton->setCheckable(true);
    m_ui->loggerButton->setStyleSheet(
                "QPushButton {border-image: url(:/workerIcons/axe.png)}"
                "QPushButton:checked {border-image: url(:/workerIcons/axe_selected.png)}");

    m_ui->farmerButton->setCheckable(true);
    m_ui->farmerButton->setStyleSheet(
                "QPushButton {border-image: url(:/workerIcons/tractor.png)}"
                "QPushButton:checked {border-image: url(:/workerIcons/tractor_selected.png)}");

    m_ui->minerButton->setCheckable(true);
    m_ui->minerButton->setStyleSheet(
                "QPushButton {border-image: url(:/workerIcons/mine.png)}"
                "QPushButton:checked {border-image: url(:/workerIcons/mine_selected.png)}");

    connect(m_scene.get(), SIGNAL(sendTilePointer(std::shared_ptr<Course::GameObject>)),
            this, SLOT(setSelectedTile(std::shared_ptr<Course::GameObject>)));

    connect(m_buildingButtonGroup.get(), SIGNAL(buttonClicked(QAbstractButton*)),
            this, SLOT(buildingButtonPressed(QAbstractButton*)));

    connect(m_workerButtonGroup.get(), SIGNAL(buttonClicked(QAbstractButton*)),
            this, SLOT(workerButtonPressed(QAbstractButton*)));
}


MapWindow::~MapWindow()
{
    delete m_ui;
}


void MapWindow::setGEHandler(
        std::shared_ptr<GameEventHandler> nHandler)
{
    m_GEHandler = nHandler;
}


void MapWindow::setSize(int width, int height)
{
    m_scene->setSize(width, height);
}


void MapWindow::setScale(int scale)
{
    m_scene->setScale(scale);
}


void MapWindow::resize()
{
    m_scene->resize();
}


void MapWindow::updateItem(std::shared_ptr<Course::GameObject> obj)
{
    m_scene->updateItem(obj);
}


void MapWindow::addTiles(Course::WorldGenerator &generator)
{
    generator.addConstructor<Course::Forest>(10);
    generator.addConstructor<Course::Grassland>(5);
    generator.addConstructor<Rock>(6);
    generator.addConstructor<Sand>(3);
    generator.addConstructor<Water>(4);

    generator.generateMap(X_SIZE, Y_SIZE, 99, m_objectmanager, m_GEHandler);
}

void MapWindow::updateResourceInfo()
{
    Course::ResourceMap playerResource = m_GEHandler->getCurrentPlayerResource();

    m_ui->lcdFood->display(playerResource.at(Course::FOOD));
    m_ui->lcdMoney->display(playerResource.at(Course::MONEY));
    m_ui->lcdWood->display(playerResource.at(Course::WOOD));
    m_ui->lcdStone->display(playerResource.at(Course::STONE));
    m_ui->lcdOre->display(playerResource.at(Course::ORE));
}

Course::ResourceMap MapWindow::turnCostToMinus(const Course::ResourceMap& cost)
{
    Course::ResourceMap subtract = cost;

    for ( auto it = cost.begin(); it != cost.end(); it++){
        subtract[it->first] = 0 - it->second;
    }
    return subtract;
}

bool MapWindow::checkEnoughResource()
{
    QAbstractButton* selected = m_buildingButtonGroup->checkedButton();
    bool success = true;
    Course::ResourceMap subtract;
    if (selected == m_ui->smallHouseButton){
        subtract = turnCostToMinus(NewResourceMaps::SMALLHOUSE_BUILD_COST);
        success = m_GEHandler->modifyResources(subtract);
    }else if (selected == m_ui->largeHouseButton)
    {
        subtract = turnCostToMinus(NewResourceMaps::LARGEHOUSE_BUILD_COST);
        success = m_GEHandler->modifyResources(subtract);
    }else if (selected == m_ui->farmButton)
    {
        subtract = turnCostToMinus(Course::ConstResourceMaps::FARM_BUILD_COST);
        success = m_GEHandler->modifyResources(subtract);
    }else if (selected == m_ui->hqButton)
    {
        subtract = turnCostToMinus(Course::ConstResourceMaps::HQ_BUILD_COST);
        success = m_GEHandler->modifyResources(subtract);
    }else if (selected == m_ui->outpustButton)
    {
        subtract = turnCostToMinus(Course::ConstResourceMaps::OUTPOST_BUILD_COST);
        success = m_GEHandler->modifyResources(subtract);
    }else if (selected == m_ui->apartmentsButton)
    {
        subtract = turnCostToMinus(NewResourceMaps::APARTMENT_BUILD_COST);
        success = m_GEHandler->modifyResources(subtract);
    }else if (selected == m_ui->skyscraperButton)
    {
        subtract = turnCostToMinus(NewResourceMaps::SKYSCRAPER_BUILD_COST);
        success = m_GEHandler->modifyResources(subtract);
    }else if (selected == m_ui->mineButton)
    {
        subtract = turnCostToMinus(NewResourceMaps::MINE_BUILD_COST);
        success = m_GEHandler->modifyResources(subtract);
    }else if (selected == m_ui->sawButton)
    {
        subtract = turnCostToMinus(NewResourceMaps::SAWMILL_BUILD_COST);
        success = m_GEHandler->modifyResources(subtract);
    }
    return success;
}


void MapWindow::removeItem(std::shared_ptr<Course::GameObject> obj)
{
    m_scene->removeItem(obj);
}


void MapWindow::drawItem( std::shared_ptr<Course::GameObject> obj)
{
    m_scene->drawItem(obj);
}


void MapWindow::on_highScoreButton_clicked()
{
    HighScoreDialog* highScoreDialog = new HighScoreDialog;

    playerInfo pair1 = {"haha", 1};
    std::vector<playerInfo> highScoreDb;
    highScoreDb.push_back(pair1);

    highScoreDialog->setHighScoreInformation(highScoreDb);
    highScoreDialog->exec();

    delete highScoreDialog;
}


void MapWindow::on_assignButton_clicked()
{
    /* TODO
     * Connect the signal to update assigned workers
     * After that assign the worker from the block
     */
    int freeWorkers = m_ui->freeBwNumber->value();

    AssignDialog* assignDialog = new AssignDialog(freeWorkers, this);
    assignDialog->exec();

    m_ui->assignButton->setEnabled(false);
}


void MapWindow::on_quitButton_clicked()
{
    qApp->exit(0);
}


void MapWindow::setStyleWorkerButtons()
{
    m_ui->bwButton->setStyleSheet(
                "QPushButton {border-image: url(:/workerIcons/worker.png)}"
                "QPushButton:checked {border-image: url(:/workerIcons/worker_selected.png)}");

    m_ui->loggerButton->setStyleSheet(
                "QPushButton {border-image: url(:/workerIcons/axe.png)}"
                "QPushButton:checked {border-image: url(:/workerIcons/axe_selected.png)}");

    m_ui->farmerButton->setStyleSheet(
                "QPushButton {border-image: url(:/workerIcons/tractor.png)}"
                "QPushButton:checked {border-image: url(:/workerIcons/tractor_selected.png)}");

    m_ui->minerButton->setStyleSheet(
                "QPushButton {border-image: url(:/workerIcons/mine.png)}"
                "QPushButton:checked {border-image: url(:/workerIcons/mine_selected.png)}");
}


void MapWindow::setupButtonGroup(std::vector<QAbstractButton *> buttons, std::shared_ptr<QButtonGroup>  group)
{
    for(auto iter = buttons.begin(); iter != buttons.end(); ++iter)
    {
        group->addButton(*iter);
        (*iter)->setCheckable(true);
    }
}


void MapWindow::on_unassignButton_clicked()
{
    /* TODO
     * Connect the signal to update free workers
     * After that free the workers from that block
     */

    UnAssignDialog* unAssignDialog = new UnAssignDialog(0, this);
    unAssignDialog->exec();
    m_ui->unassignButton->setEnabled(false);
}



void MapWindow::createPlayers(int numberPlayers)
{
    show();
    m_GEHandler->createPlayers(numberPlayers);

    // Give all the players the basic resources in the beginng
    m_GEHandler->createBeginResource();

    // Show the first player resource
    this->updateResourceInfo();
}

void MapWindow::setSelectedTile(std::shared_ptr<Course::GameObject> tile)
{
    m_GEHandler->setCurrentTile(tile);
}

void MapWindow::buildingButtonPressed(QAbstractButton*)
{
    m_ui->buildButton->setEnabled(true);
}

void MapWindow::workerButtonPressed(QAbstractButton*)
{
    m_ui->assignButton->setEnabled(true);
    m_ui->unassignButton->setEnabled(true);
}



void MapWindow::on_endTurnButton_clicked()
{
    // Change player when end turn
    m_GEHandler->changePlayer();

    m_GEHandler->printCurrentPlayer();
}

void MapWindow::on_buildButton_clicked()
{
    bool enoughResource = checkEnoughResource();

    if (enoughResource){
        QAbstractButton* selected = m_buildingButtonGroup->checkedButton();
        std::shared_ptr<Course::Coordinate> pos = m_GEHandler->returnSelectedTile()->getCoordinatePtr();
        std::shared_ptr<Course::PlayerBase> player = m_GEHandler->getCurrentPlayer();
        std::shared_ptr<Course::BuildingBase> building = nullptr;
        if (selected == m_ui->smallHouseButton)
        {
            building = std::make_shared<SmallHouse>(m_GEHandler,
                                                    m_objectmanager,
                                                    player,
                                                    1,
                                                    NewResourceMaps::SMALLHOUSE_BUILD_COST,
                                                    NewResourceMaps::SMALLHOUSE_PRODUCTION,
                                                    4);



        }else if (selected == m_ui->largeHouseButton)
        {
            building = std::make_shared<LargeHouse>(m_GEHandler,
                                                    m_objectmanager,
                                                    player,
                                                    1,
                                                    NewResourceMaps::LARGEHOUSE_BUILD_COST,
                                                    NewResourceMaps::LARGEHOUSE_PRODUCTION,
                                                    8);
        }else if (selected == m_ui->farmButton)
        {
            building = std::make_shared<Course::Farm>(m_GEHandler,
                                                    m_objectmanager,
                                                    player,
                                                    1,
                                                    Course::ConstResourceMaps::FARM_BUILD_COST,
                                                    Course::ConstResourceMaps::FARM_PRODUCTION
                                                    );
        }else if (selected == m_ui->hqButton)
        {
            building = std::make_shared<Course::HeadQuarters>(m_GEHandler,
                                                            m_objectmanager,
                                                            player,
                                                            1,
                                                            Course::ConstResourceMaps::HQ_BUILD_COST,
                                                            Course::ConstResourceMaps::HQ_PRODUCTION
                                                            );
        }else if (selected == m_ui->outpustButton)
        {
            building = std::make_shared<Course::Outpost>(m_GEHandler,
                                                        m_objectmanager,
                                                        player,
                                                        1,
                                                        Course::ConstResourceMaps::OUTPOST_BUILD_COST,
                                                        Course::ConstResourceMaps::OUTPOST_PRODUCTION
                                                        );
        }else if (selected == m_ui->apartmentsButton)
        {
            building = std::make_shared<ApartmentBlock>(m_GEHandler,
                                                        m_objectmanager,
                                                        player,
                                                        1,
                                                        NewResourceMaps::APARTMENT_BUILD_COST,
                                                        NewResourceMaps::APARTMENT_PRODUCTION
                                                        );
        }else if (selected == m_ui->skyscraperButton)
        {
            building = std::make_shared<SkyScraper>(m_GEHandler,
                                                    m_objectmanager,
                                                    player,
                                                    1,
                                                    NewResourceMaps::SKYSCRAPER_BUILD_COST,
                                                    NewResourceMaps::SKYSCRAPER_PRODUCTION
                                                    );


        }else if (selected == m_ui->mineButton)
        {
            building = std::make_shared<Mine>(m_GEHandler,
                                                    m_objectmanager,
                                                    player,
                                                    1,
                                                    NewResourceMaps::MINE_BUILD_COST,
                                                    NewResourceMaps::MINE_PRODUCTION
                                                    );

        }else if (selected == m_ui->sawButton)
        {
            building = std::make_shared<SawMill>(m_GEHandler,
                                                    m_objectmanager,
                                                    player,
                                                    1,
                                                    NewResourceMaps::SAWMILL_BUILD_COST,
                                                    NewResourceMaps::SAWMILL_PRODUCTION
                                                    );

        }



        // Deselect the selected button after build
        m_buildingButtonGroup->setExclusive(false);
        m_buildingButtonGroup->checkedButton()->setChecked(false);
        m_buildingButtonGroup->setExclusive(true);


        // Update gamescene and objectmanager
        building->setCoordinate(pos);
        m_objectmanager->getTile(*pos)->addBuilding(building);
        m_scene->drawItem(building);

        // Disable buildButton again
        m_ui->buildButton->setEnabled(false);
        m_ui->buildButton->setChecked(false);

        // Update resource of the player
        updateResourceInfo();
    } else {
        m_ui->warningLabel->setText("You don't have enough resource");
    }

}
