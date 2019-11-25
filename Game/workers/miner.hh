#ifndef MINER_HH
#define MINER_HH

#include "core/basicresources.h"
#include "newbasicworker.hh"
#include "core/nresourcemaps.hh"
#include "core/playerbase.h"
#include "interfaces/igameeventhandler.h"
#include "interfaces/iobjectmanager.h"

class Miner : public NewBasicWorker
{
public:
    /**
     * @brief Delete parameterless constructor
     */
    Miner() = delete ;

    Miner(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const std::shared_ptr<Course::PlayerBase>& owner,
           const int& tilespaces = 1,
           const Course::ResourceMap& cost = {},
           const Course::ResourceMapDouble efficiency =
            NewResourceMaps::NEW_BASIC_WORKER_EFFICIENCY,
           const Course::BasicResource focus = Course::ORE);

    virtual ~Miner() override = default;

    /**
     * @copydoc Course::GameObject::getType
     */
    virtual std::string getType() const override;

};

#endif // MINER_HH
