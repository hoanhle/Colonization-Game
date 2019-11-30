#include "housingbase.hh"

namespace Student {
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

std::string HousingBase::getType() const
{
    return "HousingBase";
}

void HousingBase::addWorkers()
{
    for (auto i = 0; i < numPeople_; i++){
        if (i % 4 == 0){
            std::shared_ptr<NewBasicWorker> newWorker =
                    std::make_shared<NewBasicWorker>(lockEventHandler(),
                                                     lockObjectManager(),
                                                     getOwner());
            std::dynamic_pointer_cast<Player>(getOwner())->addWorker(newWorker);
            std::dynamic_pointer_cast<Player>(getOwner())->addWorker("BasicWorker");
            std::dynamic_pointer_cast<ObjectManager>(lockObjectManager())->addWorker(
                        newWorker);
        } else if (i % 4 == 1){
            std::shared_ptr<Farmer> newFarmer =
                    std::make_shared<Farmer>(lockEventHandler(),
                                                     lockObjectManager(),
                                                     getOwner());
            std::dynamic_pointer_cast<Player>(getOwner())->addWorker(newFarmer);
            std::dynamic_pointer_cast<Player>(getOwner())->addWorker("Farmer");
            std::dynamic_pointer_cast<ObjectManager>(lockObjectManager())->addWorker(
                        newFarmer);
        } else if (i % 4 == 2){
            std::shared_ptr<Logger> newLogger =
                    std::make_shared<Logger>(lockEventHandler(),
                                                     lockObjectManager(),
                                                     getOwner());
            std::dynamic_pointer_cast<Player>(getOwner())->addWorker(newLogger);
            std::dynamic_pointer_cast<Player>(getOwner())->addWorker("Logger");
            std::dynamic_pointer_cast<ObjectManager>(lockObjectManager())->addWorker(
                        newLogger);
        } else if (i % 4 == 3){
            std::shared_ptr<Miner> newMiner =
                    std::make_shared<Miner>(lockEventHandler(),
                                            lockObjectManager(),
                                            getOwner());
            std::dynamic_pointer_cast<Player>(getOwner())->addWorker(newMiner);
            std::dynamic_pointer_cast<Player>(getOwner())->addWorker("Miner");
            std::dynamic_pointer_cast<ObjectManager>(lockObjectManager())->addWorker(
                        newMiner);
        }
    }
}

} // namespace Student
