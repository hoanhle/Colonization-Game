#ifndef FARMER_HH
#define FARMER_HH

#include "workers/workerbase.h"
#include "nresourcemaps.hh"
#include "core/playerbase.h"
#include "interfaces/igameeventhandler.h"
#include "interfaces/iobjectmanager.h"

class Farmer : public Course::WorkerBase
{
public:
    /**
     * @brief Disabled parameterless constructor
     */
    Farmer() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the student's GameEventHandler.
     * @param owner points to the owning player.
     */
    Farmer(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const std::shared_ptr<Course::PlayerBase>& owner,
           const int& tilespaces = 1,
           const Course::ResourceMap& cost = {},
           const Course::ResourceMapDouble efficiency =
            NewResourceMaps::FARMER_EFFICIENCY);

    ~Farmer() override = default;

    /**
     * @brief Check if the farmer can be placed on the Tile according to
     * it's placement rule. Only rule is that the Tile must have same owner
     * as the worker.
     * @param target is the Tile that farmer is being placed on.
     * @return
     * True - If baseclass' method return true and target Tile has space
     * for worker.
     * False - If both conditions aren't met.
     * @note Override to change placement rules for derived worker.
     * @post Exception guarantee: Basic
     */
    virtual bool canBePlacedOnTile(const std::shared_ptr<Course::TileBase> &target) const override;

    /**
     * @brief Performs the Farmer's default action.
     */
    virtual void doSpecialAction() override;

    /**
     * @brief Returns Farmer's efficiency at resource production.
     * Worker consumes FOOD and MONEY. Resource consumption and resource
     * focus determine final multiplier that is based on WORKER_EFFICIENCY.
     *
     * @return
     */
    virtual const Course::ResourceMapDouble tileWorkAction() override;
};

#endif // FARMER_HH
