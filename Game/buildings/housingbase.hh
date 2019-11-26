#ifndef HOUSINGBASE_HH
#define HOUSINGBASE_HH

#include "buildings/buildingbase.h"
#include "core/nresourcemaps.hh"
#include "core/resourcemaps.h"
#include "core/placeablegameobject.h"

/**
 * @brief The HousingBase class
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
     * @param numPeople indicates the number of workers housed by the tile
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

    void addWorkers();





private:
    int numPeople_;
};

#endif // HOUSINGBASE_HH
