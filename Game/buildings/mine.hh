#ifndef MINE_HH
#define MINE_HH
#include "buildings/buildingbase.h"
#include "core/nresourcemaps.hh"

namespace Student {

/**
 * @brief The Mine class represents a mine-building in the game
 *
 * The mine adds
 */
class Mine : public Course::BuildingBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    Mine() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the GameEventHandler.
     * @param object manager points to the ObjectManager
     * @param owner points to the owning player.
     *
     * @post Exception Guarantee: No guarantee.
     */
    explicit Mine(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost = NewResourceMaps::MINE_BUILD_COST,
            const Course::ResourceMap& production = NewResourceMaps::MINE_PRODUCTION
            );

    /**
     * @brief Default destructor.
     */
    virtual ~Mine() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

}; // class Mine
} // namespace Student

#endif // MINE_HH
