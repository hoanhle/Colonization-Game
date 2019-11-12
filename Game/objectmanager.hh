#ifndef OBJECTMANAGER_HH
#define OBJECTMANAGER_HH


#include "interfaces/iobjectmanager.h"

class ObjectManager : public Course::iObjectManager
{
public:
    ObjectManager();

    /**
     * @brief Default destructor.
     */
    ~ObjectManager() = default;

    /**
     * @brief Adds new tiles to the ObjectManager.
     * @param tiles a vector that contains the Tiles to be added.
     * @post The tile-pointers in the vector are stored in the ObjectManager.
     * Exception Guarantee: Basic
     *
     */
    virtual void addTiles(
            const std::vector<std::shared_ptr<Course::TileBase>>& tiles) = 0;

    /**
     * @brief Returns a shared pointer to a Tile that has specified coordinate.
     * @param coordinate Requested Tile's Coordinate
     * @return a pointer to a Tile that has the given coordinate.
     * If no for the coordinate exists, return empty pointer.
     * @post Exception Guarantee: Basic
     */
    virtual std::shared_ptr<Course::TileBase> getTile(
            const Course::Coordinate& coordinate) = 0;

    /**
     * @brief Returns a shared pointer to a Tile that has specified ID
     * @param id Tile's ObjectId.
     * @return a pointer to the Tile that has the given ID
     * If no for the id exists, return empty pointer.
     * @post Exception Guarantee: Basic
     */
    virtual std::shared_ptr<Course::TileBase> getTile(const Course::ObjectId& id) = 0;

    /**
     * @brief Returns a vector of shared pointers to Tiles specified by
     * a vector of Coordinates.
     * @param coordinates a vector of Coordinates for the requested Tiles
     * @return Vector of that contains pointers to Tile's that match
     * the coordinates. The vector is empty if no matches were made.
     * @post Exception Guarantee: Basic
     */
    virtual std::vector<std::shared_ptr<Course::TileBase>> getTiles(
            const std::vector<Course::Coordinate>& coordinates) = 0;


};

#endif // OBJECTMANAGER_HH