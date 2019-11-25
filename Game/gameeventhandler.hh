#ifndef GAMEEVENTHANDLER_HH
#define GAMEEVENTHANDLER_HH

#include "interfaces/igameeventhandler.h"
#include "core/playerbase.h"
#include "tiles/tilebase.h"
#include "core/coordinate.h"
#include "core/gameobject.h"
#include "core/gameobject.h"
#include "nresourcemaps.hh"
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

    void printPlayerNames();

    /**
     * @brief createBeginResource give basic resources to all players
     * in the beginning
     */
    void createBeginResource();

    /**
     * @brief getCurrentPlayerResource
     * @return resourcemap of current player
     */
    Course::ResourceMap getCurrentPlayerResource();

    /**
     * @brief changePlayer change player after ending turn
     */
    void changePlayer();

    std::shared_ptr<Course::PlayerBase> getCurrentPlayer();

    void printCurrentPlayer();
    /**
     * @brief Get all players in the game
     * @return a vector containing shared pointers to all players
     */
    std::vector<std::shared_ptr<Course::PlayerBase>> getPlayers();

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


    bool modifyResource(std::shared_ptr<Course::PlayerBase> player,
                                    Course::BasicResource resource,
                                    int amount) override;
    bool modifyResources(std::shared_ptr<Course::PlayerBase> player,
                                     Course::ResourceMap resources) override;

private:

    std::vector<std::shared_ptr<Course::PlayerBase>> players_;

    // Players resources with order respectively to players_ vector
    std::vector<Course::ResourceMap> playersResource_;

    // Current player index
    int current_ = 0;

    // Current selected tile
    std::shared_ptr<Course::GameObject> tile_;
};


#endif // GAMEEVENTHANDLER_HH
