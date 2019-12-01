#ifndef LOGGER_HH
#define LOGGER_HH

#include "core/basicresources.h"
#include "newbasicworker.hh"
#include "core/nresourcemaps.hh"
#include "core/playerbase.h"
#include "interfaces/igameeventhandler.h"
#include "interfaces/iobjectmanager.h"

namespace Student {

/**
 * @brief The Logger class represents a logger in the game.
 *
 * Logger has following production-efficiency: \n
 * * Money - 0.50 \n
 * * Food - 0.25 \n
 * * Wood - 1.50 \n
 * * Stone - 0.25 \n
 * * Ore - 0.50 \n
 *
 * Loggers consume Food and money. \n
 * * 1 Food - Or Loggers refuses to work. \n
 * * 1 Money - Or Loggers works at 50% efficiency. \n
 * * Resourcefocus adds 25% efficiency for the focused resource,
 * even if the logger is refusing work.
 */
class Logger : public NewBasicWorker
{
public:
    /**
     * @brief Delete parameterless constructor
     */
    Logger() = delete ;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the student's GameEventHandler.
     * @param objectmanager points to the student's ObjectManager
     * @param owner points to the owning player.
     */
    Logger(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const std::shared_ptr<Course::PlayerBase>& owner,
           const int& tilespaces = 1,
           const Course::ResourceMap& cost = {},
           const Course::ResourceMapDouble efficiency =
            NewResourceMaps::LOGGER_EFFICIENCY,
           const Course::BasicResource focus = Course::WOOD);

    virtual ~Logger() override = default;

    /**
     * @copydoc Course::GameObject::getType
     */
    virtual std::string getType() const override;

};

}

#endif // LOGGER_HH
