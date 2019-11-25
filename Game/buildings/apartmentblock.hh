#ifndef APARTMENTBLOCK_HH
#define APARTMENTBLOCK_HH

#include "buildings/housingbase.hh"

class ApartmentBlock : public HousingBase
{
public:

    const Course::ResourceMap BUILD_COST;
    /**
     * @brief Disabled parameterless constructor
     */
    ApartmentBlock() = delete;

    explicit ApartmentBlock(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& building  = {},
            const Course::ResourceMap& production = {},
            const int& numPeople = 15);

    /**
     * @brief Default destructor.
     */
    virtual ~ApartmentBlock() = default ;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;
};
#endif // APARTMENTBLOCK_HH
