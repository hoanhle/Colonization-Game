#ifndef OBJECTMANAGER_HH
#define OBJECTMANAGER_HH

#include <vector>

#include "interfaces/iobjectmanager.h"
#include "tiles/tilebase.h"
#include "core/coordinate.h"
#include "core/gameobject.h"
#include "workers/newbasicworker.hh"

namespace Student {

class ObjectManager : public Course::iObjectManager
{
public:
    ObjectManager();

    /**
     * @brief Default destructor.
     */
    virtual ~ObjectManager() = default;


    /**
     * @brief Adds new tiles to the ObjectManager.
     * @param tiles a vector that contains the Tiles to be added.
     * @post The tile-pointers in the vector are stored in the ObjectManager.
     * Exception Guarantee: Basic
     *
     */
    virtual void addTiles(
            const std::vector<std::shared_ptr<Course::TileBase>>& tiles);

    /**
     * @brief Returns a shared pointer to a Tile that has specified coordinate.
     * @param coordinate Requested Tile's Coordinate
     * @return a pointer to a Tile that has the given coordinate.
     * If no for the coordinate exists, return empty pointer.
     * @post Exception Guarantee: Basic
     */
    virtual std::shared_ptr<Course::TileBase> getTile(
            const Course::Coordinate& coordinate);

    /**
     * @brief Returns a shared pointer to a Tile that has specified ID
     * @param id Tile's ObjectId.
     * @return a pointer to the Tile that has the given ID
     * If no for the id exists, return empty pointer.
     * @post Exception Guarantee: Basic
     */
    virtual std::shared_ptr<Course::TileBase> getTile(const Course::ObjectId& id);

    /**
     * @brief Returns a vector of shared pointers to Tiles specified by
     * a vector of Coordinates.
     * @param coordinates a vector of Coordinates for the requested Tiles
     * @return Vector of that contains pointers to Tile's that match
     * the coordinates. The vector is empty if no matches were made.
     * @post Exception Guarantee: Basic
     */
    virtual std::vector<std::shared_ptr<Course::TileBase>> getTiles(
            const std::vector<Course::Coordinate>& coordinates);

    /**
     * @brief Returns a vector shared pointers to call the tiles on map
     *
     * @return Vector that contains to pointers to all tiles on the map.
     * @post Exception Guarantee: Basic
     */
    std::vector<std::shared_ptr<Course::TileBase>> getAllTiles();

    void addBuilding(std::shared_ptr<Course::BuildingBase> building);

    /**
     * @brief add worker pointer into m_worker
     * @param worker: pointer to a newbasicworker object
     * @post Exception Guarantee: Strong
     */
    void addWorker(std::shared_ptr<NewBasicWorker> worker);

private:
    std::vector<std::shared_ptr<Course::TileBase>> m_tiles;
    std::vector<std::shared_ptr<Course::BuildingBase>> m_buildings;
    std::vector<std::shared_ptr<NewBasicWorker>> m_workes;
};
} // namespace Student

#endif // OBJECTMANAGER_HH
