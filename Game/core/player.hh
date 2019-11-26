#ifndef PLAYER_HH
#define PLAYER_HH

#include "core/playerbase.h"
#include "workers/newbasicworker.hh"

class Player : public Course::PlayerBase
{
public:
    /**
     * @brief Constructor for the class
     * @param name A std::string for player's name
     * @param objects (optional) A std::vector of shared-pointers to
     * TileBases pointer
     */
    Player(const std::string& name,
           const std::vector<std::shared_ptr<Course::GameObject> > objects ={});

    ~Player() = default;

private:
    std::vector<std::shared_ptr<NewBasicWorker>> workers_;
};

#endif // PLAYER_HH
