#ifndef SAND_HH
#define SAND_HH

#include "tiles/tilebase.h"
#include "objectmanager.hh"
#include "nresourcemaps.hh"

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

#endif // SAND_HH
