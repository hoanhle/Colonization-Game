#include "basicworker.h"
#include "interfaces/igameeventhandler.h"
#include "interfaces/iobjectmanager.h"

namespace Course {



BasicWorker::BasicWorker(const std::shared_ptr<iGameEventHandler>& eventhandler,
                         const std::shared_ptr<iObjectManager>& objectmanager,
                         const std::shared_ptr<PlayerBase>& owner,
                         const int& tilespaces,
                         const ResourceMap& cost,
                         const ResourceMapDouble& efficiency):
    WorkerBase(
        eventhandler,
        objectmanager,
        owner,
        tilespaces,
        cost,
        efficiency)
{
}

std::string BasicWorker::getType() const
{
    return "BasicWorker";
}

void BasicWorker::doSpecialAction()
{

}

const ResourceMapDouble BasicWorker::tileWorkAction()
{
    auto player = getOwner();
    auto events = lockEventHandler();
    double satisfaction = 0;
    BasicResource focus = getResourceFocus();

    ResourceMapDouble final_modifier;

    if ( events->modifyResource(player, BasicResource::FOOD, -1) )
    {
        satisfaction = 0.5;
        if ( events->modifyResource(player, BasicResource::MONEY, -1) )
        {
            satisfaction = 1;
        }
    }


    if( focus != BasicResource::NONE )
    {
        final_modifier[focus] =
                WORKER_EFFICIENCY.at(focus) * (satisfaction + 0.25);
    }
    else
    {
        for( auto it = WORKER_EFFICIENCY.begin();
             it != WORKER_EFFICIENCY.end();
             ++it )
        {
            final_modifier[it->first] = it->second * satisfaction;
        }
    }

    return final_modifier;
}


} // namespace Course
