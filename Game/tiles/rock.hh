    #ifndef ROCK_HH
#define ROCK_HH

#include "tiles/tilebase.h"
#include "core/objectmanager.hh"
#include "core/nresourcemaps.hh"

namespace Student {

/**
 * @brief The Rock class represents Rock in the gameworld.
 *
 * Rock has BasicProduction: \n
 * * Money = 3
 * * Food = 0
 * * Wood = 0
 * * Stone = 5
 * * Ore = 2
 *
 *
 * Tile supports 1 buildings.
 */
class Rock : public Course::TileBase
{
public:
    Rock() = delete;
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
    Rock(const Course::Coordinate& location,
         const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
         const std::shared_ptr<Course::iObjectManager>& objectmanager,
         const unsigned int& max_build = 1,
         const unsigned int& max_work = 3,
         const Course::ResourceMap& production = NewResourceMaps::ROCK_BP);

    /**
     * @brief Default destructor.
     */
    virtual ~Rock() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;


};

} // namespace Student

#endif // ROCK_HH
