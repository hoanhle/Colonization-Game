#ifndef GAMEEVENTHANDLER_HH
#define GAMEEVENTHANDLER_HH

#include "interfaces/igameeventhandler.h"
#include "tiles/tilebase.h"
#include "core/coordinate.h"
#include "core/gameobject.h"
#include "core/nresourcemaps.hh"
#include "core/player.hh"
#include <QDebug>


class GameEventHandler : public Course::iGameEventHandler
{
public:
    GameEventHandler();

    /**
     * @brief createPlayers
     * @param numberPlayers number of players in the game
     */
    void createPlayers(int numberPlayers);

    /**
     * @brief createBeginResource give basic resources to all players
     * in the beginning
     */
    void createBeginResource();

    /**
     * @brief createBeginWorker give each player 1 worker each type
     * in the beginning
     */
    void createBeginWorker();

    /**
     * @brief getCurrentPlayerResource
     * @return resourcemap of current player
     */
    Course::ResourceMap* getCurrentPlayerResource();

    /**
     * @brief getCurrentPlayerWorkerNumber
     * @return pointer to totalNumberWorker map of the player
     */
    std::map<std::string, int> *getCurrentPlayerWorkerNumber();

    /**
     * @brief getCurrentFreeWorkerNumber
     * @return pointer to freeNumberWorker map of the player
     */
    std::map<std::string, int> *getCurrentFreeWorkerNumber();

    /**
     * @brief changePlayer change player after ending turn
     */
    void changePlayer();

    /**
     * @brief print the name of the current player
     */
    void printCurrentPlayer();

    /**
     * @brief getCurrentPlayer
     * @return shared pointer to the current player
     */
    std::shared_ptr<Player> getCurrentPlayer();

    /**
     * @brief setCurrentTile save the current selected tile
     * @param tile tile pointer
     */
    void setCurrentTile(std::shared_ptr<Course::GameObject> tile);

    /**
     * @brief return the selected tile
     * @return tile tile pointer
     */
    std::shared_ptr<Course::GameObject> returnSelectedTile();

    void assignWorkers(int numberWorker, std::string workerType);

    bool modifyResource(std::shared_ptr<Course::PlayerBase> player,
                                    Course::BasicResource resource,
                                    int amount) override;
    bool modifyResources(std::shared_ptr<Course::PlayerBase> player,
                                     Course::ResourceMap resources) override;

    bool modifyResources(Course::ResourceMap resources);


private:
    std::vector<std::shared_ptr<Player>> players_;

    // Current player index
    int current_ = 0;

    // Current selected tile
    std::shared_ptr<Course::GameObject> tile_;
};


#endif // GAMEEVENTHANDLER_HH
