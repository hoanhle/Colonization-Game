#include "mapwindow.hh"
#include "ui_mapwindow.h"

#include "graphics/simplemapitem.h"
#include "highscoredialog.hh"
#include "assigndialog.hh"


#include <math.h>

int X_SIZE = 10;
int Y_SIZE = 10;

MapWindow::MapWindow(QWidget *parent,
                     std::shared_ptr<Course::iGameEventHandler> handler):
    QMainWindow(parent),
    m_ui(new Ui::MapWindow),
    m_GEHandler(handler),
    m_scene(new GameScene(this)),
    m_objectmanager(new ObjectManager())
{
    m_ui->setupUi(this);



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





}

MapWindow::~MapWindow()
{
    delete m_ui;
}


void MapWindow::setGEHandler(
        std::shared_ptr<Course::iGameEventHandler> nHandler)
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

void MapWindow::on_bwButton_toggled(bool checked)
{

}

void MapWindow::on_assignButton_clicked()
{
    int freeWorkers = m_ui->freeBwNumber->value();

    AssignDialog* assignDialog = new AssignDialog(freeWorkers);
    assignDialog->exec();

}

void MapWindow::on_bwButton_clicked()
{

}

void MapWindow::on_quitButton_clicked()
{
    qApp->exit(0);
}
