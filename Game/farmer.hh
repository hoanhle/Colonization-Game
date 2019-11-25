#ifndef FARMER_HH
#define FARMER_HH

#include "core/basicresources.h"
#include "newbasicworker.hh"
#include "nresourcemaps.hh"
#include "core/playerbase.h"
#include "interfaces/igameeventhandler.h"
#include "interfaces/iobjectmanager.h"

class Farmer : public NewBasicWorker
{
public:
    /**
     * @brief Delete parameterless constructor
     */
    Farmer() = delete;

    Farmer(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const std::shared_ptr<Course::PlayerBase>& owner,
           const int& tilespaces = 1,
           const Course::ResourceMap& cost = {},
           const Course::ResourceMapDouble efficiency =
            NewResourceMaps::NEW_BASIC_WORKER_EFFICIENCY,
           const Course::BasicResource focus = Course::FOOD);

    virtual ~Farmer() override = default;
    /**
     * @copydoc Course::GameObject::getType
     */
    virtual std::string getType() const override;
};

#endif // FARMER_HH
