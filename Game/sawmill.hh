#ifndef SAWMILL_HH
#define SAWMILL_HH
#include "buildings/buildingbase.h"

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
     * @param eventhandler points to the student's GameEventHandler.
     * @param owner points to the owning player.
     * @param tile points to the tile upon which the building is constructed.
     *
     * @post Exception Guarantee: No guarantee.
     * @exception OwnerConflict - if the building conflicts with tile's
     * ownership.
     */
    explicit SawMill(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost = {},
            const Course::ResourceMap& production = {}
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

#endif // SAWMILL_HH
