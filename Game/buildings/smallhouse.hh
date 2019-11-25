#ifndef SMALLHOUSE_HH
#define SMALLHOUSE_HH

#include "buildings/housingbase.hh"

class SmallHouse : public HousingBase
{
public:

    const Course::ResourceMap BUILD_COST;
    /**
     * @brief Disabled parameterless constructor
     */
    SmallHouse() = delete;

    explicit SmallHouse(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& building  = {},
            const Course::ResourceMap& production = {},
            const int& numPeople = 2);

    /**
     * @brief Default destructor.
     */
    virtual ~SmallHouse() = default ;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;
};

#endif // SMALLHOUSE_HH
