#ifndef SMALLHOUSE_HH
#define SMALLHOUSE_HH

#include "buildings/housingbase.hh"

namespace Student {

/**
 * @brief The SmallHouse class represents a small house in the game
 *
 * It houses 4 workers (1 of each type)
 */
class SmallHouse : public HousingBase
{
public:

    const Course::ResourceMap BUILD_COST;
    /**
     * @brief Disabled parameterless constructor
     */
    SmallHouse() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the GameEventHandler.
     * @param object manager points to the ObjectManager
     * @param owner points to the owning player.
     *
     * @post Exception Guarantee: No guarantee.
     */
    explicit SmallHouse(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& building  = NewResourceMaps::SMALLHOUSE_BUILD_COST,
            const Course::ResourceMap& production = NewResourceMaps::SMALLHOUSE_PRODUCTION,
            const int& numPeople = 4);

    /**
     * @brief Default destructor.
     */
    virtual ~SmallHouse() = default ;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;
}; // class SmallHouse
} //namespace Student

#endif // SMALLHOUSE_HH
