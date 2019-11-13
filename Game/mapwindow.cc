#include "mapwindow.hh"
#include "ui_mapwindow.h"

#include "graphics/simplemapitem.h"
#include "highscoredialog.hh"

#include <math.h>

MapWindow::MapWindow(QWidget *parent,
                     std::shared_ptr<Course::iGameEventHandler> handler):
    QMainWindow(parent),
    m_ui(new Ui::MapWindow),
    m_GEHandler(handler),
    m_simplescene(new Course::SimpleGameScene(this))
{
    m_ui->setupUi(this);

    Course::SimpleGameScene* sgs_rawptr = m_simplescene.get();

    m_ui->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(sgs_rawptr));

    m_ui->bwButton->setCheckable(true);
    m_ui->bwButton->setStyleSheet(
                "QPushButton {border-image: url(:/workerIcons/worker.png)}"
                "QPushButton:checked {border-image: url(:/workerIcons/worker.png)}");

    m_ui->loggerButton->setCheckable(true);
    m_ui->loggerButton->setStyleSheet(
                "QPushButton {border-image: url(:/workerIcons/axe.png)}"
                "QPushButton:checked {border-image: url(:/workerIcons/axeLight.png)}");

    m_ui->farmerButton->setCheckable(true);
    m_ui->farmerButton->setStyleSheet(
                "QPushButton {border-image: url(:/workerIcons/tractor.png)}"
                "QPushButton:checked {border-image: url(:/workerIcons/tractor.png)}");

    m_ui->minerButton->setCheckable(true);
    m_ui->minerButton->setStyleSheet(
                "QPushButton {border-image: url(:/workerIcons/mine.png)}"
                "QPushButton:checked {border-image: url(:/workerIcons/mine.png)}");
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
    m_simplescene->setSize(width, height);
}

void MapWindow::setScale(int scale)
{
    m_simplescene->setScale(scale);
}

void MapWindow::resize()
{
    m_simplescene->resize();
}

void MapWindow::updateItem(std::shared_ptr<Course::GameObject> obj)
{
    m_simplescene->updateItem(obj);
}

void MapWindow::removeItem(std::shared_ptr<Course::GameObject> obj)
{
    m_simplescene->removeItem(obj);
}

void MapWindow::drawItem( std::shared_ptr<Course::GameObject> obj)
{
    m_simplescene->drawItem(obj);
}

void MapWindow::on_highScoreButton_clicked()
{
    HighScoreDialog* highScoreDialog = new HighScoreDialog;

    playerInfo pair1 = {"haha", 1};
    std::vector<playerInfo> highScoreDb;
    highScoreDb.push_back(pair1);

    highScoreDialog->setHighScoreInformation(highScoreDb);
    highScoreDialog->exec();
}

void MapWindow::on_bwButton_toggled(bool checked)
{

}
