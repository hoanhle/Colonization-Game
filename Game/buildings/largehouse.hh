#ifndef LARGEHOUSE_HH
#define LARGEHOUSE_HH
#include "buildings/housingbase.hh"

namespace Student {

/**
 * @brief The LargeHouse class represents a large house in the game
 *
 * It increase
 */
class LargeHouse : public HousingBase
{
public:

    const Course::ResourceMap BUILD_COST;
    /**
     * @brief Disabled parameterless constructor
     */
    LargeHouse() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the GameEventHandler.
     * @param object manager points to the ObjectManager
     * @param owner points to the owning player.
     *
     * @post Exception Guarantee: No guarantee.
     */
    explicit LargeHouse(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& building  = NewResourceMaps::LARGEHOUSE_BUILD_COST,
            const Course::ResourceMap& production = NewResourceMaps::LARGEHOUSE_PRODUCTION,
            const int& numPeople = 8);

    /**
     * @brief Default destructor.
     */
    virtual ~LargeHouse() = default ;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

}; // class LargeHouse

} // namespace Student

#endif // LARGEHOUSE_HH
