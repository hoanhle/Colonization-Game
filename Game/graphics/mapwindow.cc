#include "mapwindow.hh"
#include "ui_mapwindow.h"

#include "graphics/simplemapitem.h"
#include "graphics/highscoredialog.hh"
#include "graphics/assigndialog.hh"
#include "graphics/unassigndialog.hh"
#include "graphics/startdialog.hh"
#include "graphics/setplayerdialog.hh"
#include "core/gamescene.hh"
#include "graphics/windialog.hh"
#include "exceptions/noowner.hh"
#include "exceptions/notenoughspace.h"
#include "exceptions/invalidpointer.h"

#include <math.h>
#include <QDebug>

int X_SIZE = 10;
int Y_SIZE = 10;


MapWindow::MapWindow(QWidget *parent,
                     std::shared_ptr<Student::GameEventHandler> handler):
    QMainWindow(parent),
    m_ui(new Ui::MapWindow),
    m_GEHandler(handler),
    m_scene(new Student::GameScene(this)),
    m_objectmanager(new Student::ObjectManager())
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

    Student::GameScene* sgs_rawptr = m_scene.get();

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

    qDebug() << filePath();
}


MapWindow::~MapWindow()
{
    delete m_ui;
}


void MapWindow::setGEHandler(
        std::shared_ptr<Student::GameEventHandler> nHandler)
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
    generator.addConstructor<Student::Rock>(6);
    generator.addConstructor<Student::Sand>(3);
    generator.addConstructor<Student::Water>(4);

    generator.generateMap(X_SIZE, Y_SIZE, 99, m_objectmanager, m_GEHandler);
}

void MapWindow::updateResourceInfo()
{
    Course::ResourceMap* playerResource = m_GEHandler->getCurrentPlayerResource();
    auto resource = *playerResource;
    m_ui->lcdFood->display(playerResource->at(Course::FOOD));
    m_ui->lcdMoney->display(playerResource->at(Course::MONEY));
    m_ui->lcdWood->display(playerResource->at(Course::WOOD));
    m_ui->lcdStone->display(playerResource->at(Course::STONE));
    m_ui->lcdOre->display(playerResource->at(Course::ORE));
}

void MapWindow::updateWorkerInfo()
{
    std::map<std::string, int>* playerWorker;
    playerWorker = m_GEHandler->getCurrentPlayerWorkerNumber();

    m_ui->bwLcd->display(playerWorker->at("BasicWorker"));
    m_ui->farmerLcd->display(playerWorker->at("Farmer"));
    m_ui->loggerLcd->display(playerWorker->at("Logger"));
    m_ui->minerLcd->display(playerWorker->at("Miner"));
}

void MapWindow::updateFreeWorkerInfo()
{
    std::map<std::string, int>* playerFreeWorker = m_GEHandler->getCurrentFreeWorkerNumber();
    m_ui->freeBwNumber->display(playerFreeWorker->at("BasicWorker"));
    m_ui->freeFarmerNumber->display(playerFreeWorker->at("Farmer"));
    m_ui->freeLoggerNumber->display(playerFreeWorker->at("Logger"));
    m_ui->freeMinerNumber->display(playerFreeWorker->at("Miner"));
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
        subtract = turnCostToMinus(Student::NewResourceMaps::SMALLHOUSE_BUILD_COST);
        success = m_GEHandler->modifyResources(subtract);
    }else if (selected == m_ui->largeHouseButton)
    {
        subtract = turnCostToMinus(Student::NewResourceMaps::LARGEHOUSE_BUILD_COST);
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
        subtract = turnCostToMinus(Student::NewResourceMaps::SKYSCRAPER_BUILD_COST);
        success = m_GEHandler->modifyResources(subtract);
    }else if (selected == m_ui->skyscraperButton)
    {
        subtract = turnCostToMinus(Student::NewResourceMaps::SKYSCRAPER_BUILD_COST);
        success = m_GEHandler->modifyResources(subtract);
    }else if (selected == m_ui->mineButton)
    {
        subtract = turnCostToMinus(Student::NewResourceMaps::MINE_BUILD_COST);
        success = m_GEHandler->modifyResources(subtract);
    }else if (selected == m_ui->sawButton)
    {
        subtract = turnCostToMinus(Student::NewResourceMaps::SAWMILL_BUILD_COST);
        success = m_GEHandler->modifyResources(subtract);
    }
    return success;
}

std::string MapWindow::getSelectedWorkerType()
{
    std::string selectedType;
    QAbstractButton* selected = m_workerButtonGroup->checkedButton();

    if (selected == m_ui->bwButton){
        selectedType = "BasicWorker";
    } else if (selected == m_ui->farmerButton){
        selectedType = "Farmer";
    } else if (selected == m_ui->minerButton){
        selectedType = "Logger";
    } else if (selected == m_ui->loggerButton){
        selectedType = "Miner";
    }

    return selectedType;
}

void MapWindow::checkWinning()
{
    bool win = m_GEHandler->checkWinning();

    if (win){
        WinDialog* winDialog = new WinDialog(this);
        if (winDialog->exec()){
            this->continueGame();
        } else {
            this->endGame();
        }
    }
}

QString MapWindow::filePath()
{
    QString path = qApp->applicationDirPath();
    if (path.contains("debug")){
        path.replace("debug", "scoreDb.txt");
    } else {
        path.append("scoreDb.txt");
    }

    return path;
}

std::vector<QString> MapWindow::readHighScoreFile()
{
    std::vector<QString> points_;
    QFile highScoreFile(filePath());

    if (highScoreFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&highScoreFile);
        QString line = stream.readLine();
        while (!line.isNull()) {
            points_.push_back(line);
            line = stream.readLine();
        }
        highScoreFile.close();
    }

    return points_;
}

void MapWindow::writeToHighScoreFile(QString pointToAppend)
{
    QFile ScoreFile(filePath());
    pointToAppend += "\n";
    if (ScoreFile.open(QFile::WriteOnly | QIODevice::Append)) {
        QTextStream out(&ScoreFile);
        out << pointToAppend;
    }

    ScoreFile.flush();
    ScoreFile.close();
}

void MapWindow::continueGame()
{
    int turns = m_GEHandler->returnTurnNumber();
    writeToHighScoreFile(QString::number(turns));
    hide();
    qApp->exit(200);
}

void MapWindow::endGame()
{
    int turns = m_GEHandler->returnTurnNumber();
    writeToHighScoreFile(QString::number(turns));
    qApp->exit(0);
}

void MapWindow::clearSelections()
{

    if(m_buildingButtonGroup->checkedButton())
    {
        m_buildingButtonGroup->setExclusive(false);
        m_buildingButtonGroup->checkedButton()->setChecked(false);
        m_buildingButtonGroup->setExclusive(true);
        m_ui->buildButton->setEnabled(false);
    }
    if(m_workerButtonGroup->checkedButton())
    {
        m_workerButtonGroup->setExclusive(false);
        m_workerButtonGroup->checkedButton()->setChecked(false);
        m_workerButtonGroup->setExclusive(true);
    }

    m_ui->unassignButton->setEnabled(false);
    m_ui->assignButton->setEnabled(false);
    m_ui->infoLabel->clear();

}


void MapWindow::updateInformationLabel(std::shared_ptr<Course::GameObject> tile)
{
    QString owner = "";
    int farmers = 0;
    int basicworkers = 0;
    int miners = 0;
    int loggers = 0;
    try {
        auto ownerPointer = tile->getOwner();
        if (ownerPointer != nullptr)
        {
            owner = QString::fromStdString(ownerPointer->getName());
        }else{
            throw NoOwner("Selected tile has no owner");
        }
    } catch(NoOwner)
    {
        owner = "none";
    }
    std::vector<std::shared_ptr<Course::WorkerBase>> workers =
            m_GEHandler->returnSelectedTile()->getWorkers();
    for (auto item = workers.begin();
         item != workers.end(); ++item)
    {
        QString name = QString::fromStdString(item->get()->getType());
        if (name == "Farmer")
        {
            farmers += 1;
        } else if (name == "BasicWorker")
        {
            basicworkers += 1;
        } else if (name == "Miner")
        {
            miners += 1;
        }else if (name == "Logger")
        {
            loggers += 1;
        }
    }


    m_ui->infoLabel->setText("Owner: " + owner + "   Basic Workers: " + QString::number(basicworkers)
                             + "   Farmers: " + QString::number(farmers)
                             + "   Loggers: " + QString::number(loggers)
                             + "   Miners: " + QString::number(miners));

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
    std::vector<QString> existPoints = readHighScoreFile();
    std::vector<int> scoreDb;

    for (int i = 0; i < existPoints.size(); i++){
        int point = existPoints[i].toInt();
        scoreDb.push_back(point);
    }

    if (scoreDb.size() > 0){
        std::sort(scoreDb.begin(), scoreDb.end());
    }

    highScoreDialog->setHighScoreInformation(scoreDb);
    highScoreDialog->exec();

    delete highScoreDialog;
}


void MapWindow::on_assignButton_clicked()
{   
    int maxWorkers = 0;
    QAbstractButton* selected = m_workerButtonGroup->checkedButton();

    if (selected == m_ui->bwButton){
        maxWorkers = m_ui->freeBwNumber->value();
    } else if (selected == m_ui->farmerButton){
        maxWorkers = m_ui->freeFarmerNumber->value();
    } else if (selected == m_ui->minerButton){
        maxWorkers = m_ui->freeMinerNumber->value();
    } else if (selected == m_ui->loggerButton){
        maxWorkers = m_ui->freeLoggerNumber->value();
    }

    // The maximum number of workers can be assigned to the selected tile
    int maxAddedWorkers = 3 - m_GEHandler->returnSelectedTile()->getWorkerCount();
    if (maxAddedWorkers > maxWorkers){
        maxAddedWorkers = maxWorkers;
    }

    AssignDialog* assignDialog = new AssignDialog(maxAddedWorkers, this);
    connect(assignDialog, SIGNAL(setWorkers(int)), this, SLOT(assignWorkers(int)));

    assignDialog->exec();

    clearSelections();
}

void MapWindow::assignWorkers(int workerNumber)
{
    std::string selectedType = getSelectedWorkerType();
    m_GEHandler->assignWorkers(workerNumber, selectedType);
    updateFreeWorkerInfo();
}

void MapWindow::unassignWorkers(int workerNumber)
{
    std::string selectedType = getSelectedWorkerType();
    m_GEHandler->unassignWorkers(workerNumber, selectedType);
    updateFreeWorkerInfo();
}

void MapWindow::displayPlayerTurn()
{
    QString turn = QString::fromStdString(m_GEHandler->getCurrentPlayer()->getName());

    m_ui->playerTurnLabel->setText(turn + "'s turn");
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
    std::string workerType = getSelectedWorkerType();
    int maxFreeWorkers = 0;

    std::vector<std::shared_ptr<Course::WorkerBase>> workers =
            m_GEHandler->returnSelectedTile()->getWorkers();
    for (auto item = workers.begin();
         item != workers.end(); ++item)
    {
        std::string name = item->get()->getType();
        if (name == workerType)
        {
            maxFreeWorkers += 1;
        }
    }

    UnAssignDialog* unAssignDialog = new UnAssignDialog(maxFreeWorkers, this);
    connect(unAssignDialog, SIGNAL(freeWorkers(int)), this, SLOT(unassignWorkers(int)));
    unAssignDialog->exec();

    clearSelections();
}



void MapWindow::createPlayers(int numberPlayers)
{
    show();
    m_GEHandler->createPlayers(numberPlayers);

    // Give all the players the basic resources in the beginning
    m_GEHandler->createBeginResource();

    // Give all the players 0 workers in the beginning
    m_GEHandler->createBeginWorker();

    // Show the first player resource and worker info
    this->updateResourceInfo();
    this->updateFreeWorkerInfo();

    displayPlayerTurn();
}


void MapWindow::setSelectedTile(std::shared_ptr<Course::GameObject> tile)
{ 
    std::shared_ptr<Course::Coordinate> pos = tile->getCoordinatePtr();
    m_GEHandler->setCurrentTile(m_objectmanager->getTile(*pos));
    updateInformationLabel(tile);
    m_ui->warningLabel->clear();
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

    std::vector<std::shared_ptr<Course::GameObject>> objects = m_GEHandler->getCurrentPlayer()->getObjects();
    for (auto x = objects.begin(); x != objects.end(); ++x){
        Course::Coordinate coord = x->get()->getCoordinate();
        std::shared_ptr<Course::TileBase> tile = m_objectmanager->getTile(coord);


        bool success = tile->generateResources();
    }

    updateResourceInfo();
    updateWorkerInfo();
    updateFreeWorkerInfo();
    clearSelections();
    checkWinning();
    displayPlayerTurn();
    m_ui->warningLabel->clear();
}


void MapWindow::on_buildButton_clicked()
{
    m_ui->warningLabel->clear();
    try {
        if (checkEnoughResource()){
            QAbstractButton* selected = m_buildingButtonGroup->checkedButton();
            std::shared_ptr<Course::Coordinate> pos = m_GEHandler->returnSelectedTile()->getCoordinatePtr();

            std::shared_ptr<Course::PlayerBase> player = m_GEHandler->getCurrentPlayer();
            std::shared_ptr<Course::BuildingBase> building = nullptr;
            if (selected == m_ui->smallHouseButton)
            {
                building = std::make_shared<Student::SmallHouse>(m_GEHandler,
                                                        m_objectmanager,
                                                        player,
                                                        1,
                                                        Student::NewResourceMaps::SMALLHOUSE_BUILD_COST,
                                                        Student::NewResourceMaps::SMALLHOUSE_PRODUCTION,
                                                        4);
                std::dynamic_pointer_cast<Student::SmallHouse>(building)->addWorkers();

            }else if (selected == m_ui->largeHouseButton)
            {
                building = std::make_shared<Student::LargeHouse>(m_GEHandler,
                                                        m_objectmanager,
                                                        player,
                                                        1,
                                                        Student::NewResourceMaps::LARGEHOUSE_BUILD_COST,
                                                        Student::NewResourceMaps::LARGEHOUSE_PRODUCTION,
                                                        8);
                std::dynamic_pointer_cast<Student::LargeHouse>(building)->addWorkers();
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
                building = std::make_shared<Student::ApartmentBlock>(m_GEHandler,
                                                            m_objectmanager,
                                                            player,
                                                            1,
                                                            Student::NewResourceMaps::APARTMENT_BUILD_COST,
                                                            Student::NewResourceMaps::APARTMENT_PRODUCTION
                                                            );
                std::dynamic_pointer_cast<Student::ApartmentBlock>(building)->addWorkers();
            }else if (selected == m_ui->skyscraperButton)
            {
                building = std::make_shared<Student::SkyScraper>(m_GEHandler,
                                                        m_objectmanager,
                                                        player,
                                                        1,
                                                        Student::NewResourceMaps::SKYSCRAPER_BUILD_COST,
                                                        Student::NewResourceMaps::SKYSCRAPER_PRODUCTION
                                                        );
                std::dynamic_pointer_cast<Student::SkyScraper>(building)->addWorkers();
            }else if (selected == m_ui->mineButton)
            {
                building = std::make_shared<Student::Mine>(m_GEHandler,
                                                        m_objectmanager,
                                                        player,
                                                        1,
                                                        Student::NewResourceMaps::MINE_BUILD_COST,
                                                        Student::NewResourceMaps::MINE_PRODUCTION
                                                        );

            }else if (selected == m_ui->sawButton)
            {
                building = std::make_shared<Student::SawMill>(m_GEHandler,
                                                        m_objectmanager,
                                                        player,
                                                        1,
                                                        Student::NewResourceMaps::SAWMILL_BUILD_COST,
                                                        Student::NewResourceMaps::SAWMILL_PRODUCTION
                                                        );

            }



            // Deselect the selected button after build
            m_buildingButtonGroup->setExclusive(false);
            m_buildingButtonGroup->checkedButton()->setChecked(false);
            m_buildingButtonGroup->setExclusive(true);

            // Add tile to player
            m_GEHandler->getCurrentPlayer()->addObject(m_objectmanager->getTile(*pos));

            // Update gamescene and objectmanager
            building->setCoordinate(pos);
            m_objectmanager->getTile(*pos)->addBuilding(building);
            if (building->getType() == "Outpost")
            {
                building->onBuildAction();
            }

            m_objectmanager->getTile(*pos)->setOwner(m_GEHandler->getCurrentPlayer());
            m_scene->drawItem(building);

            // Disable buildButton again
            m_ui->buildButton->setEnabled(false);
            m_ui->buildButton->setChecked(false);

            // Update resource and worker of the player
            updateResourceInfo();
            updateWorkerInfo();
            updateFreeWorkerInfo();

        } else
        {
            m_ui->warningLabel->setText("You don't have enough resource");
        }
    } catch (Course::NotEnoughSpace)
    {
        m_ui->warningLabel->setText("You cannot place a building here");
    } catch (Course::IllegalAction)
    {
       m_ui->warningLabel->setText("You cannot place a building here");
    } catch (Course::InvalidPointer)
    {
        return;
    }

    clearSelections();
    checkWinning();
}


