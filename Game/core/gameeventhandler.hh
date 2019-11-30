#ifndef GAMEEVENTHANDLER_HH
#define GAMEEVENTHANDLER_HH

#include "tiles/tilebase.h"
#include "tiles/grassland.h"
#include "interfaces/igameeventhandler.h"
#include "core/coordinate.h"
#include "core/gameobject.h"
#include "core/nresourcemaps.hh"
#include "core/player.hh"
#include "workers/basicworker.h"
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
    void setCurrentTile(std::shared_ptr<Course::TileBase> tile);

    /**
     * @brief return the selected tile
     * @return tile tile pointer
     */
    std::shared_ptr<Course::TileBase> returnSelectedTile();

    /**
     * @brief remove the workers pointer from the player object
     * and add them to the tile
     * @param numberWorker
     * @param workerType
     */
    void assignWorkers(int numberWorker, std::string workerType);

    /**
     * @brief get the vector of workers pointers from the tile that the player want to
     * unassign
     * @return vector of worker pointers
     */
    std::vector<std::shared_ptr<NewBasicWorker>> getWorkerstoFree(
            int numberWorker, std::string workerType);

    /**
     * @brief remove the workers pointer from the tile and add them
     * back to the player object
     * @param numberWorker
     * @param workerType
     */
    void unassignWorkers(int numberWorker, std::string workerType);

    bool modifyResource(std::shared_ptr<Course::PlayerBase> player,
                                    Course::BasicResource resource,
                                    int amount) override;
    bool modifyResources(std::shared_ptr<Course::PlayerBase> player,
                                     Course::ResourceMap resources) override;

    bool modifyResources(Course::ResourceMap resources);

    /**
     * @brief check if the current player has won or not
     * A player will win if he/she has 5000 resources total
     * and 50 workers
     * @return
     * true: the player has won
     * false: the player hasn't won
     */
    bool checkWinning();

private:
    std::vector<std::shared_ptr<Player>> players_;

    int turns_ = 0;

    // Current player index
    int current_ = 0;

    // Current selected tile
    std::shared_ptr<Course::TileBase> tile_;
};


#endif // GAMEEVENTHANDLER_HH
