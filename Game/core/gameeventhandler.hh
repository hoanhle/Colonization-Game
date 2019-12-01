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


namespace Student {

/**
 * @brief The GameEventHandler represents a class handle all events in the game
 */
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
     * @param tile current tile pointer
     */
    void setCurrentTile(std::shared_ptr<Course::TileBase> tile);

    /**
     * @brief return the selected tile
     * @return tile current tile pointer
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

    /**
     * @brief Modify Player's resource. Can be used to both sum or subtract.
     * @param player Pointer to the Player whose resource is being modified.
     * @param resource Defines the modified resource.
     * @param amount Defines the amount of change.
     * @post Exception guarantee: Basic
     * @return
     * True - Modification was succesful. \n
     * False - Modification failed. \n
     */
    bool modifyResource(std::shared_ptr<Course::PlayerBase> player,
                                    Course::BasicResource resource,
                                    int amount) override;

    /**
     * @brief Modify Player's resources. Can be used to both sum or subtract
     * @param player Pointer to the Player whose resources are being modified.
     * @param resources ResourceMap containing change amounts.
     * @return
     * True - Modification was succesful. \n
     * False - Modification failed. \n
     */
    bool modifyResources(std::shared_ptr<Course::PlayerBase> player,
                                     Course::ResourceMap resources) override;

    /**
     * @brief Modify current Player's resources. Can be used to both sum or subtract
     * @param player Pointer to the Player whose resources are being modified.
     * @param resources ResourceMap containing change amounts.
     * @return
     * True - Modification was succesful. \n
     * False - Modification failed. \n
     */
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

    /**
     * @brief return the total number of turns one player has played
     * @return total turns
     */
    int returnTurnNumber();

private:
    // Vector contains all player-shared-pointers
    std::vector<std::shared_ptr<Player>> players_;

    // Total number of turns
    int turns_ = 0;

    // Current player index
    int current_ = 0;

    // Current selected tile
    std::shared_ptr<Course::TileBase> tile_;

}; // class GameEventHandler

} // namespace Student


#endif // GAMEEVENTHANDLER_HH
