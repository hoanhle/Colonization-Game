#ifndef SKYSCRAPER_HH
#define SKYSCRAPER_HH
#include "housingbase.hh"

class SkyScraper : public HousingBase
{
public:

    const Course::ResourceMap BUILD_COST;
    /**
     * @brief Disabled parameterless constructor
     */
    SkyScraper() = delete;

    explicit SkyScraper(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& building  = {},
            const Course::ResourceMap& production = {},
            const int& numPeople = 50);

    /**
     * @brief Default destructor.
     */
    virtual ~SkyScraper() = default ;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;
};


#endif // SKYSCRAPER_HH
