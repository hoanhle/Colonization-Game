#ifndef APARTMENTBLOCK_HH
#define APARTMENTBLOCK_HH

#include "buildings/housingbase.hh"

namespace Student {

/**
 * @brief The ApartmentBlock class represents a apartment-building in the game
 *
 * The apartmentblock add 8 workers (2 each type) to the player.
 */
class ApartmentBlock : public HousingBase
{
public:

    const Course::ResourceMap BUILD_COST;
    /**
     * @brief Disabled parameterless constructor
     */
    ApartmentBlock() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the GameEventHandler.
     * @param object manager points to the ObjectManager
     * @param owner points to the owning player.
     *
     * @post Exception Guarantee: No guarantee.
     */
    explicit ApartmentBlock(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& building  = NewResourceMaps::APARTMENT_BUILD_COST,
            const Course::ResourceMap& production = NewResourceMaps::APARTMENT_PRODUCTION,
            const int& numPeople = 12);

    /**
     * @brief Default destructor.
     */
    virtual ~ApartmentBlock() = default ;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

}; // class Apartment
} // namespace Student

#endif // APARTMENTBLOCK_HH
