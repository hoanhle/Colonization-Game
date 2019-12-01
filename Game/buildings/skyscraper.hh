#ifndef SKYSCRAPER_HH
#define SKYSCRAPER_HH
#include "buildings/housingbase.hh"

namespace Student {
class SkyScraper : public HousingBase
{
public:

    const Course::ResourceMap BUILD_COST;
    /**
     * @brief Disabled parameterless constructor
     */
    SkyScraper() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the GameEventHandler.
     * @param object manager points to the ObjectManager
     * @param owner points to the owning player.
     *
     * @post Exception Guarantee: No guarantee.
     */
    explicit SkyScraper(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& building  = NewResourceMaps::SKYSCRAPER_BUILD_COST,
            const Course::ResourceMap& production = NewResourceMaps::SKYSCRAPER_PRODUCTION,
            const int& numPeople = 40);

    /**
     * @brief Default destructor.
     */
    virtual ~SkyScraper() = default ;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;
}; // class Skyscraper
} // namespace Student


#endif // SKYSCRAPER_HH
