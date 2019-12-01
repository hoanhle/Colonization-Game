#ifndef FARMER_HH
#define FARMER_HH

#include "core/basicresources.h"
#include "newbasicworker.hh"
#include "core/nresourcemaps.hh"
#include "core/playerbase.h"
#include "interfaces/igameeventhandler.h"
#include "interfaces/iobjectmanager.h"

namespace Student {

/**
 * @brief The Farmer class represents a farmer in the game.
 *
 * Farmer has following production-efficiency: \n
 * * Money - 0.50 \n
 * * Food - 1.50 \n
 * * Wood - 0.5 \n
 * * Stone - 0.25 \n
 * * Ore - 0.25 \n
 *
 * Farmers consume Food and money. \n
 * * 1 Food - Or Farmers refuses to work. \n
 * * 1 Money - Or Farmers works at 50% efficiency. \n
 * * Resourcefocus adds 25% efficiency for the focused resource,
 * even if the farmer is refusing work.
 */
class Farmer : public NewBasicWorker
{
public:
    /**
     * @brief Delete parameterless constructor
     */
    Farmer() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the student's GameEventHandler.
     * @param objectmanager points to the student's ObjectManager
     * @param owner points to the owning player.
     */
    Farmer(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const std::shared_ptr<Course::PlayerBase>& owner,
           const int& tilespaces = 1,
           const Course::ResourceMap& cost = {},
           const Course::ResourceMapDouble efficiency =
            NewResourceMaps::FARMER_EFFICIENCY,
           const Course::BasicResource focus = Course::FOOD);

    virtual ~Farmer() override = default;

    /**
     * @copydoc Course::GameObject::getType
     */
    virtual std::string getType() const override;
};

} // namespace Student

#endif // FARMER_HH
