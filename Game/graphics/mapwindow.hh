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
#include "core/gamescene.hh"

#include "core/objectmanager.hh"
#include "core/worldgenerator.h"
#include "tiles/forest.h"
#include "tiles/grassland.h"
#include "tiles/rock.hh"
#include "tiles/sand.hh"
#include "tiles/water.hh"

#include "graphics/highscoredialog.hh"
#include "graphics/assigndialog.hh"
#include "graphics/unassigndialog.hh"
#include "core/gameeventhandler.hh"
#include "buildings/smallhouse.hh"
#include "buildings/largehouse.hh"
#include "buildings/apartmentblock.hh"
#include "buildings/skyscraper.hh"
#include "buildings/mine.hh"
#include "buildings/sawmill.hh"
#include "buildings/farm.h"
#include "buildings/headquarters.h"
#include "buildings/outpost.h"


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


    /**
     * @brief update player's resource in mapwindow
     */
    void updateResourceInfo();

    /**
     * @brief update player's worker in mapwindwo
     */
    void updateWorkerInfo();

    /**
     * @brief turn Resourcemap building cost
     * element into negative
     */
    Course::ResourceMap turnCostToMinus(const Course::ResourceMap& cost);

    /**
     * @brief check if the player has enough resource to build
     * also minus the resource imidiately if the player has enough
     * @return
     * true: enough resource
     * false: not enough resource
     */
    bool checkEnoughResource();



private slots:
    void on_highScoreButton_clicked();

    void on_assignButton_clicked();

    void on_quitButton_clicked();

    void on_unassignButton_clicked();


    void on_endTurnButton_clicked();

    void on_buildButton_clicked();

public slots:
    void createPlayers(int numberPlayers);

    void setSelectedTile(std::shared_ptr<Course::GameObject> tile);

    /**
     * @brief enable to build when a building is selected
     */
    void buildingButtonPressed(QAbstractButton*);

    /**
     * @brief enable to assign or unassign when a worker is selected
     */
    void workerButtonPressed(QAbstractButton*);

private:
    Ui::MapWindow* m_ui;
    std::shared_ptr<GameEventHandler> m_GEHandler = nullptr;
    std::shared_ptr<GameScene> m_scene = nullptr;
    std::shared_ptr<ObjectManager> m_objectmanager = nullptr;
    std::shared_ptr<QButtonGroup> m_buildingButtonGroup = nullptr;
    std::shared_ptr<QButtonGroup> m_workerButtonGroup = nullptr;

    void setStyleWorkerButtons();
    void setupButtonGroup(std::vector<QAbstractButton*> buttons, std::shared_ptr<QButtonGroup> group);

};

#endif // MapWINDOW_HH

