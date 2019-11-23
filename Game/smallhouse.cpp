#include "smallhouse.hh"



SmallHouse::SmallHouse(const std::shared_ptr<Course::iGameEventHandler> &eventhandler,
                       const std::shared_ptr<Course::iObjectManager> &objectmanager,
                       const std::shared_ptr<Course::PlayerBase> &owner,
                       const int &tilespaces, const Course::ResourceMap &building,
                       const Course::ResourceMap &production, const int &numPeople):
    HousingBase(eventhandler,
                objectmanager,
                owner,
                tilespaces,
                building,
                production,
                numPeople)
{

}

std::string SmallHouse::getType() const
{
    return "SmallHouse";
}
