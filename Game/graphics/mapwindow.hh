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
#include "core/nresourcemaps.hh"
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
#include "graphics/windialog.hh"


namespace Ui {
class MapWindow;

// Location of high score file
const QString directory = ":/scoreDb.txt";
}

class MapWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MapWindow(QWidget *parent = 0,
                       std::shared_ptr<Student::GameEventHandler> GEHandler = {}
                       );
    ~MapWindow();

    /**
     * @brief sets the game event handler
     * @param nHandler shared pointer to Game Event Handler
     */
    void setGEHandler(std::shared_ptr<Student::GameEventHandler> nHandler);

    /**
     * @brief set size of window
     * @param width of window
     * @param height of window
     */
    void setSize(int width, int height);

    /**
     * @brief set scale of window
     * @param scale of the window
     */
    void setScale(int scale);

    /**
     * @brief resize the window
     */
    void resize();

    /**
     * @brief draw item to the Map Window
     * @param obj: shared pointer to a Game Object
     */
    void drawItem( std::shared_ptr<Course::GameObject> obj);

    /**
     * @brief remove item from the Map Window
     * @param obj: shared pointer to a Game Object
     */
    void removeItem( std::shared_ptr<Course::GameObject> obj);

    /**
     * @brief update item on the Map Window
     * @param obj: shared pointer to a Game Object
     */
    void updateItem( std::shared_ptr<Course::GameObject> obj);

    /**
     * @brief add tiles to the world generator
     * @param generator: reference to the map generator
     */
    void addTiles(Course::WorldGenerator& generator);

    /**
     * @brief update player's resource in mapwindow
     */
    void updateResourceInfo();

    /**
     * @brief update player's total worker number
     */
    void updateWorkerInfo();

    /**
     * @brief update player's free worker number
     */
    void updateFreeWorkerInfo();

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

    /**
     * @brief get the pressed worker type
     * @return the worker type
     */
    std::string getSelectedWorkerType();

    /**
     * @brief check if the current player has won or not
     * A player will win if he/she has 5000 resources total
     * and 50 workers
     */
    void checkWinning();

    /**
     * @brief read from the file that contains high score db
     * @return vector of user's scores
     */
    std::vector<QString> readHighScoreFile();

    /**
     * @brief append new point to highscore database
     * @param pointToAppend: point to append
     */
    void writeToHighScoreFile(QString pointToAppend);

    /**
     * @brief players want to continue the game
     */
    void continueGame();

    /**
     * @brief players want to end game
     */
    void endGame();

    /**
     * @brief clear selected buttons
     */
    void clearSelections();

    /**
     * @brief update the information about the current selected tile
     * @param tile shared pointer to the current selected tile
     */
    void updateInformationLabel(std::shared_ptr<Course::GameObject> tile);

    /**
     * @brief Set the playerTurnLabel to show whose turn it is
     */
    void displayPlayerTurn();



private slots:
    void on_highScoreButton_clicked();

    void on_assignButton_clicked();

    void on_unassignButton_clicked();

    void on_quitButton_clicked();

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

    /**
     * @brief tell the gameeventhandler to assign free workers of player
     * to a tile
     * @param workerNumber: number of workers to assign
     */
    void assignWorkers(int workerNumber);


    /**
     * @brief tell the gameeventhandler to free workers of player
     * from a tile
     * @param workerNumber: number of workers to unassign
     */
    void unassignWorkers(int workerNumber);




private:
    Ui::MapWindow* m_ui;
    std::shared_ptr<Student::GameEventHandler> m_GEHandler = nullptr;
    std::shared_ptr<Student::GameScene> m_scene = nullptr;
    std::shared_ptr<Student::ObjectManager> m_objectmanager = nullptr;
    std::shared_ptr<QButtonGroup> m_buildingButtonGroup = nullptr;
    std::shared_ptr<QButtonGroup> m_workerButtonGroup = nullptr;

    void setStyleWorkerButtons();
    void setupButtonGroup(std::vector<QAbstractButton*> buttons, std::shared_ptr<QButtonGroup> group);

};

#endif // MapWINDOW_HH

