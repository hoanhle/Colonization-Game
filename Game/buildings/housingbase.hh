#ifndef HOUSINGBASE_HH
#define HOUSINGBASE_HH

#include "buildings/buildingbase.h"
#include "core/nresourcemaps.hh"
#include "core/resourcemaps.h"
#include "core/placeablegameobject.h"
#include "workers/newbasicworker.hh"
#include "workers/farmer.hh"
#include "workers/logger.hh"
#include "workers/miner.hh"
#include "core/player.hh"
#include "core/objectmanager.hh"
#include "core/gameeventhandler.hh"


namespace Student {

/**
 * @brief The HousingBase class is a base-class for different
 * housing buildings in the game
 *
 * It increases the number of workers for the player
 */
class HousingBase : public Course::BuildingBase
{
public:
    const Course::ResourceMap BUILD_COST;
    /**
     * @brief Disabled parameterless constructor
     */
    HousingBase() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the GameEventHandler.
     * @param object manager points to the ObjectManager
     * @param owner points to the owning player.
     * @param tiles spaces indicates the number of positions it fills on the tile
     * @param building is a resource map including the cost of construction
     * @param production is a resource map indicating the production of building
     * @param numPeople indicates the number of workers housed it created
     *
     * @post Exception Guarantee: No guarantee.
     */
    explicit HousingBase(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& building  = {},
            const Course::ResourceMap& production = {},
            const int& numPeople = 0);


    /**
     * @brief Default destructor.
     */
    virtual ~HousingBase() = default ;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

    /**
     * @brief add numPeople/4 set of worker (1 basic, 1 farmer, 1 logger, 1 miner)
     * to player object and objectmanager object
     */
    void addWorkers();





private:
    int numPeople_;
}; // class HousingBase

} //namespace Student


#endif // HOUSINGBASE_HH
