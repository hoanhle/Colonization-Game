#ifndef PLAYER_HH
#define PLAYER_HH

#include "core/playerbase.h"
#include "workers/newbasicworker.hh"
#include "core/nresourcemaps.hh"

class Player : public Course::PlayerBase
{
public:
    /**
     * @brief Constructor for the class
     * @param name A std::string for player's name
     * @param objects (optional) A std::vector of shared-pointers to
     * TileBases pointer
     */
    Player(const std::string& name);

    ~Player() = default;

    /**
     * @brief get current resource of the player
     * @return pointer to resource_
     */
    Course::ResourceMap* getCurrentResources();

    /**
     * @brief set beginning resource for the player
     */
    void setBeginningResource();

    /**
     * @brief Add resources to current resource_ of the player
     * can be used to subtract to add to the resource_
     * @param resources
     * @return
     * true: the modification is successful
     * false: the modification is unsucessful
     */
    bool modifyPlayerResources(Course::ResourceMap resources);

    bool modifyPlayerResource(Course::BasicResource resource,
                              int amount);


private:
    Course::ResourceMap resource_;
    std::vector<std::weak_ptr<NewBasicWorker>> workers_;
};

#endif // PLAYER_HH
