#ifndef ROCK_HH
#define ROCK_HH

#include "tiles/tilebase.h"
#include "objectmanager.hh"
#include "nresourcemaps.hh"

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
 * Tile supports 4 buildings.
 */
class Rock : public Course::TileBase
{
public:
    Rock() = delete;

    Rock(const Course::Coordinate& location,
         const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
         const std::shared_ptr<Course::iObjectManager>& objectmanager,
         const unsigned int& max_build = 2,
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

#endif // ROCK_HH
