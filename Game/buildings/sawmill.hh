#ifndef SAWMILL_HH
#define SAWMILL_HH
#include "buildings/buildingbase.h"
#include "core/nresourcemaps.hh"

namespace Student {
class SawMill : public Course::BuildingBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    SawMill() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the GameEventHandler.
     * @param object manager points to the ObjectManager
     * @param owner points to the owning player.
     *
     * @post Exception Guarantee: No guarantee.
     */
    explicit SawMill(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost = NewResourceMaps::SKYSCRAPER_BUILD_COST,
            const Course::ResourceMap& production = NewResourceMaps::SKYSCRAPER_PRODUCTION
            );

    /**
     * @brief Default destructor.
     */
    virtual ~SawMill() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

};

} // namespace Student

#endif // SAWMILL_HH
