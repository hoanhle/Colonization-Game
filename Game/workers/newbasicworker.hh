#ifndef NEWBASICWORKER_HH
#define NEWBASICWORKER_HH

#include "workers/workerbase.h"
#include "core/nresourcemaps.hh"
#include "core/playerbase.h"
#include "interfaces/igameeventhandler.h"
#include "interfaces/iobjectmanager.h"

namespace Student {

/**
 * @brief The NewBasicWorker class represents a "normal worker" in the game.
 *
 * Worker has following production-efficiency: \n
 * * Money - 0.25 \n
 * * Food - 1.00 \n
 * * Wood - 0.75 \n
 * * Stone - 0.50 \n
 * * Ore - 0.50 \n
 *
 * NewBasicWorkers consume Food and money. \n
 * * 1 Food - Or NewBasicWorker refuses to work. \n
 * * 1 Money - Or NewBasicWorker works at 50% efficiency. \n
 * * Resourcefocus adds 25% efficiency for the focused resource,
 * even if the worker is refusing work.
 */
class NewBasicWorker : public Course::WorkerBase
{
public:
    /**
     * @brief Disabled parameterless
     */
    NewBasicWorker() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the student's GameEventHandler.
     * @param objectmanager points to the student's ObjectManager
     * @param owner points to the owning player.
     */
     NewBasicWorker(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
                    const std::shared_ptr<Course::iObjectManager>& objectmanager,
                    const std::shared_ptr<Course::PlayerBase>& owner,
                    const int& tilespaces = 1,
                    const Course::ResourceMap& cost = {},
                    const Course::ResourceMapDouble efficiency =
                     NewResourceMaps::NEW_BASIC_WORKER_EFFICIENCY);

     virtual ~NewBasicWorker() override = default;

     /**
      * @copydoc Course::GameObject::getType
      */
     virtual std::string getType() const override;

     /**
      * @brief Check if the worker can be placed on the Tile according to
      * it's placement rule. Only rule is that the Tile must have same owner
      * as the worker.
      * @param target is the Tile that worker is being placed on.
      * @return
      * True - If baseclass' method return true and target Tile has space
      * for worker.
      * False - If both conditions aren't met.
      * @note Override to change placement rules for derived worker.
      * @post Exception guarantee: Basic
      */
     virtual bool canBePlacedOnTile(const std::shared_ptr<Course::TileBase> &target) const override final;

     /**
      * @brief Performs the Worker's default action.
      */
     virtual void doSpecialAction() override final;

     /**
      * @brief Returns Worker's efficiency at resource production.
      * Worker consumes FOOD and MONEY. Resource consumption and resource
      * focus determine final multiplier that is based on WORKER_EFFICIENCY.
      *
      * @return
      */
     virtual const Course::ResourceMapDouble tileWorkAction() override final;

};

} // namespace Student

#endif // NEWBASICWORKER_HH
