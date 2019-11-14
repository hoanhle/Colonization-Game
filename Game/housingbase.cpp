#include "housingbase.hh"


HousingBase::HousingBase(const std::shared_ptr<Course::iGameEventHandler> &eventhandler,
                         const std::shared_ptr<Course::iObjectManager> &objectmanager,
                         const std::shared_ptr<Course::PlayerBase> &owner,
                         const int &tilespaces,
                         const Course::ResourceMap &building,
                         const Course::ResourceMap &production,
                         const int &numPeople):
    Course::BuildingBase(
        eventhandler,
        objectmanager,
        owner,
        tilespaces,
        building,
        production),
    numPeople_(numPeople)
{

}
