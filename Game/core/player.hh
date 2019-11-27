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

    /**
     * @brief modify part of player resources (e.g: FOOD)
     * @param resource the name of the resource
     * @param amount how many to modify
     * @return
     * true: the modification is successful
     * false: the modification is unsucessful
     */
    bool modifyPlayerResource(Course::BasicResource resource,
                              int amount);

    /**
     * @brief Store a weak NewBasicWorker-pointer
     * @param worker is a pointer to the store NewBasicWorker object
     * @post Exception guarantee: Strong
     * @exception See std::vector::push_back()
     */
    void addWorker(std::shared_ptr<NewBasicWorker> worker);

    /**
     * @brief stores a vector of weak NewBasicWorker-pointer
     * @param workers is an std::vector of pointer to NewBasicWorker
     * @post Exception guarantee: Strong
     * @exception See std::vector::insert()
     */
    void addWorkers(
            const std::vector<std::shared_ptr<NewBasicWorker>> workers);

    /**
     * @brief Removes a weak NewBasicWorker-pointer based on a objectId
     * and expired weak pointers
     * @param id An ObjctId for NewBasicWorker
     * @post Exception guarantee: Basic
     */
    void removeWorker(const Course::ObjectId& id);

    /**
     * @brief Remove a weak NewBasicWorker-pointer and expired weak pointers
     * @param a shared-pointer to NewBasicWorker
     * @post Exception guarantee: Basic
     * @exception ExpiredPointer - worker is expired
     * @exception KeyError - No workers match the search worker
     */
    void removeWorker(const std::shared_ptr<NewBasicWorker>& worker);


    /**
     * @brief removes a list of weak NewBasicWorker-pointers
     * based on the ObjectID
     * @param ids A vector of ObjectID for NewBasicWorker
     * @post Exception guarantee: No-throw
     * @note Even if some of the provided ID's are not found,
     * no exceptions are thrown.
     */
    void removeWorkers(const std::vector<Course::ObjectId>& ids);

    void removeWorkers(const std::vector<std::shared_ptr<NewBasicWorker>>& workers);


private:
    Course::ResourceMap resource_ = {};
    std::vector<std::weak_ptr<NewBasicWorker>> workers_;
};

#endif // PLAYER_HH
