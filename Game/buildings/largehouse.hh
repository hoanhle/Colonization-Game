#ifndef LARGEHOUSE_HH
#define LARGEHOUSE_HH
#include "buildings/housingbase.hh"

class LargeHouse : public HousingBase
{
public:

    const Course::ResourceMap BUILD_COST;
    /**
     * @brief Disabled parameterless constructor
     */
    LargeHouse() = delete;

    explicit LargeHouse(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& building  = {},
            const Course::ResourceMap& production = {},
            const int& numPeople = 4);

    /**
     * @brief Default destructor.
     */
    virtual ~LargeHouse() = default ;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;
};

#endif // LARGEHOUSE_HH
