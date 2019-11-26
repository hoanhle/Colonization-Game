#ifndef WATER_HH
#define WATER_HH

#include "tiles/tilebase.h"
#include "core/objectmanager.hh"
#include "core/nresourcemaps.hh"

/**
 * @brief The Sand class represents Sand in the gameworld.
 *
 * Sand has BasicProduction: \n
 * * Money = 3
 * * Food = 5
 * * Wood = 0
 * * Stone = 0
 * * Ore = 0
 *
 *
 * Tile supports 0 buildings.
 */
class Water : public Course::TileBase
{
public:
    Water() = delete;

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
    Water(const Course::Coordinate& location,
         const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
         const std::shared_ptr<Course::iObjectManager>& objectmanager,
         const unsigned int& max_build = 0,
         const unsigned int& max_work = 1,
         const Course::ResourceMap& production = NewResourceMaps::WATER_BP);

    /**
     * @brief Default destructor.
     */
    virtual ~Water() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;
};

#endif // WATER_HH
