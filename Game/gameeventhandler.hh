#ifndef GAMEEVENTHANDLER_HH
#define GAMEEVENTHANDLER_HH

#include "interfaces/igameeventhandler.h"
#include "core/playerbase.h"
#include "tiles/tilebase.h"
#include "core/coordinate.h"
#include "core/gameobject.h"
#include "core/gameobject.h"

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

    bool modifyResource(std::shared_ptr<Course::PlayerBase> player,
                                    Course::BasicResource resource,
                                    int amount) override;
    bool modifyResources(std::shared_ptr<Course::PlayerBase> player,
                                     Course::ResourceMap resources) override;

private:
    std::vector<std::shared_ptr<Course::PlayerBase>> players_;
};

#endif // GAMEEVENTHANDLER_HH
