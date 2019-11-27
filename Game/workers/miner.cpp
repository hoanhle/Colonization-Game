#include "workers/miner.hh"


Miner::Miner(const std::shared_ptr<Course::iGameEventHandler> &eventhandler,
             const std::shared_ptr<Course::iObjectManager> &objectmanager,
             const std::shared_ptr<Course::PlayerBase> &owner,
             const int &tilespaces,
             const Course::ResourceMap &cost,
             const Course::ResourceMapDouble efficiency,
             const Course::BasicResource focus):
    NewBasicWorker(eventhandler,
                   objectmanager,
                   owner,
                   tilespaces,
                   cost,
                   efficiency)
{
    Course::WorkerBase::setResourceFocus(focus);
}

std::string Miner::getType() const
{
    return "Miner";
}
