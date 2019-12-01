#ifndef MINER_HH
#define MINER_HH

#include "core/basicresources.h"
#include "newbasicworker.hh"
#include "core/nresourcemaps.hh"
#include "core/playerbase.h"
#include "interfaces/igameeventhandler.h"
#include "interfaces/iobjectmanager.h"

namespace Student {

/**
 * @brief The Miner class represents a miner in the game.
 *
 * Miner has following production-efficiency: \n
 * * Money - 0.50 \n
 * * Food - 0.25 \n
 * * Wood - 0.25 \n
 * * Stone - 1.00 \n
 * * Ore - 1.00 \n
 *
 * Miners consume Food and money. \n
 * * 1 Food - Or Miners refuses to work. \n
 * * 1 Money - Or Miners works at 50% efficiency. \n
 * * Resourcefocus adds 25% efficiency for the focused resource,
 * even if the miners is refusing work.
 */
class Miner : public NewBasicWorker
{
public:
    /**
     * @brief Delete parameterless constructor
     */
    Miner() = delete ;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the student's GameEventHandler.
     * @param objectmanager points to the student's ObjectManager
     * @param owner points to the owning player.
     */
    Miner(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const std::shared_ptr<Course::PlayerBase>& owner,
           const int& tilespaces = 1,
           const Course::ResourceMap& cost = {},
           const Course::ResourceMapDouble efficiency =
            NewResourceMaps::MINER_EFFICIENCY,
           const Course::BasicResource focus = Course::ORE);

    virtual ~Miner() override = default;

    /**
     * @copydoc Course::GameObject::getType
     */
    virtual std::string getType() const override;
};

}

#endif // MINER_HH
