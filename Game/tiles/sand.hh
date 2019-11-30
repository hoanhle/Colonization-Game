#ifndef SAND_HH
#define SAND_HH

#include "tiles/tilebase.h"
#include "core/objectmanager.hh"
#include "core/nresourcemaps.hh"

namespace Student {

/**
 * @brief The Sand class represents Sand in the gameworld.
 *
 * Sand has BasicProduction: \n
 * * Money = 1
 * * Food = 1
 * * Wood = 0
 * * Stone = 1
 * * Ore = 2
 *
 *
 * Tile supports 1 buildings.
 */
class Sand : public Course::TileBase
{
public:
    Sand() = delete;

    /**
     * @brief Constructor for the tile
     * @param location contains the Cooridnate of the tile
     * @param eventhandler points to the GameEventHandler
     * @param objectmanager points to the ObjectManager
     * @param max_build indicates the max number of buildings on the tile
     * @param max_work indicates the max number of workers which can be allocated to the tile
     * @param production is a resource map showing the base production of the tile
     *
     * @post Exception guarantee: no guarantee
     */
    Sand(const Course::Coordinate& location,
         const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
         const std::shared_ptr<Course::iObjectManager>& objectmanager,
         const unsigned int& max_build = 1,
         const unsigned int& max_work = 2,
         const Course::ResourceMap& production = NewResourceMaps::SAND_BP);

    /**
     * @brief Default destructor.
     */
    virtual ~Sand() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

};


} // namespace Student

#endif // SAND_HH
