#include "skyscraper.hh"

namespace Student {

SkyScraper::SkyScraper(const std::shared_ptr<Course::iGameEventHandler> &eventhandler,
                         const std::shared_ptr<Course::iObjectManager> &objectmanager,
                         const std::shared_ptr<Course::PlayerBase> &owner,
                         const int &tilespaces,
                         const Course::ResourceMap &building,
                         const Course::ResourceMap &production,
                         const int &numPeople):
    HousingBase(eventhandler,
                objectmanager,
                owner,
                tilespaces,
                building,
                production,
                numPeople)
{

}

std::string SkyScraper::getType() const
{
    return "SkyScraper";
}

} // namespace Student
