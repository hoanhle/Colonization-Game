#ifndef LOGGER_HH
#define LOGGER_HH

#include "core/basicresources.h"
#include "newbasicworker.hh"
#include "core/nresourcemaps.hh"
#include "core/playerbase.h"
#include "interfaces/igameeventhandler.h"
#include "interfaces/iobjectmanager.h"

class Logger : public NewBasicWorker
{
public:
    /**
     * @brief Delete parameterless constructor
     */
    Logger() = delete ;

    Logger(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const std::shared_ptr<Course::PlayerBase>& owner,
           const int& tilespaces = 1,
           const Course::ResourceMap& cost = {},
           const Course::ResourceMapDouble efficiency =
            NewResourceMaps::NEW_BASIC_WORKER_EFFICIENCY,
           const Course::BasicResource focus = Course::WOOD);

    virtual ~Logger() override = default;

    /**
     * @copydoc Course::GameObject::getType
     */
    virtual std::string getType() const override;

};

#endif // LOGGER_HH
