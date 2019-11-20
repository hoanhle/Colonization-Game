#ifndef GAMEEVENTHANDLER_HH
#define GAMEEVENTHANDLER_HH

#include "interfaces/igameeventhandler.h"
#include "core/playerbase.h"
#include "tiles/tilebase.h"
#include "core/coordinate.h"
#include "core/gameobject.h"
#include "core/gameobject.h"
#include "nresourcemaps.hh"

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

    Course::ResourceMap getCurrentPlayerResource();

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
};

#endif // GAMEEVENTHANDLER_HH
