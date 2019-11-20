#ifndef MAPWINDOW_HH
#define MAPWINDOW_HH

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QButtonGroup>

#include <map>

#include "interfaces/igameeventhandler.h"
#include "gamescene.hh"

#include "objectmanager.hh"
#include "core/worldgenerator.h"
#include "tiles/forest.h"
#include "tiles/grassland.h"
#include "rock.hh"
#include "sand.hh"
#include "water.hh"

#include "highscoredialog.hh"
#include "assigndialog.hh"
#include "unassigndialog.hh"
#include "gameeventhandler.hh"


namespace Ui {
class MapWindow;
}

class MapWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapWindow(QWidget *parent = 0,
                       std::shared_ptr<GameEventHandler> GEHandler = {}
                       );
    ~MapWindow();

    void setGEHandler(std::shared_ptr<GameEventHandler> nHandler);
    void setSize(int width, int height);
    void setScale(int scale);
    void resize();

    void drawItem( std::shared_ptr<Course::GameObject> obj);
    void removeItem( std::shared_ptr<Course::GameObject> obj);
    void updateItem( std::shared_ptr<Course::GameObject> obj);

    void addTiles(Course::WorldGenerator& generator);


    void updateResourceInfo();


private slots:
    void on_highScoreButton_clicked();

    void on_assignButton_clicked();

    void on_quitButton_clicked();

    void on_unassignButton_clicked();

public slots:
    void createPlayers(int numberPlayers);

private:
    Ui::MapWindow* m_ui;
    std::shared_ptr<GameEventHandler> m_GEHandler = nullptr;
    std::shared_ptr<GameScene> m_scene = nullptr;
    std::shared_ptr<ObjectManager> m_objectmanager = nullptr;

    void setStyleWorkerButtons();
    void setupButtonGroup(std::vector<QAbstractButton*> buttons, QButtonGroup* group);

};

#endif // MapWINDOW_HH

