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

    QButtonGroup* workerButtonGroup = new QButtonGroup(this);
    std::vector<QAbstractButton*> workerButtons = {m_ui->bwButton, m_ui->loggerButton,
                                               m_ui->farmerButton, m_ui->minerButton };

    QButtonGroup* buildingButtonGroup = new QButtonGroup(this);
    std::vector<QAbstractButton*> buildingButtons = {m_ui->hqButton, m_ui->farmButton,
                                               m_ui->mineButton, m_ui->sawButton, m_ui->outpustButton,
                                                     m_ui->apartmentsButton, m_ui->skyscraperButton,
                                                     m_ui->largeHouseButton, m_ui->smallHouseButton };

    setupButtonGroup(workerButtons, workerButtonGroup);
    setupButtonGroup(buildingButtons, buildingButtonGroup);

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

    AssignDialog* assignDialog = new AssignDialog(freeWorkers);
    assignDialog->exec();
    delete assignDialog;

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


void MapWindow::setupButtonGroup(std::vector<QAbstractButton *> buttons, QButtonGroup *group)
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

    UnAssignDialog* unAssignDialog = new UnAssignDialog(0);
    unAssignDialog->exec();
    delete unAssignDialog;
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



void MapWindow::on_endTurnButton_clicked()
{
    // Change player when end turn
    m_GEHandler->changePlayer();

    m_GEHandler->printCurrentPlayer();
    qDebug() << m_GEHandler->returnSelectedTile()->ID;
}
