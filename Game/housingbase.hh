#ifndef HOUSINGBASE_HH
#define HOUSINGBASE_HH

#include "buildings/buildingbase.h"
#include "nresourcemaps.hh"
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

    explicit HousingBase(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& building  = {},
            const Course::ResourceMap& production = {},
            const int& numPeople = 0);

private:
    int numPeople_;
};

#endif // HOUSINGBASE_HH
