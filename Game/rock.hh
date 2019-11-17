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
 * Building in the rock takes time. So buildings get extra hold-marker.
 *
 * Tile supports 4 buildings.
 */
class Rock : public Course::TileBase
{
public:
    Rock() = delete;

    Rock(const Course::Coordinate& location,
         const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
         const std::shared_ptr<ObjectManager>& objectmanager,
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

    /**
     * @brief Adds a new building-object to the tile. Building in rock adds
     * one hold-marker to the building.
     *
     * Phases: \n
     * 1. Check that there is space for the building. \n
     * 2. Call parent's addBuilding \n
     * 3. Add a HoldMarker for the building. \n
     *
     * @post Exception guarantee: Strong
     * @exception OwnerConflict - If the tile's ownership prevents placing the
     * \b building.
     * @exception NoSpace - If the tile doesn't have enough space for
     * the \b building.
     */
    void addBuilding(const std::shared_ptr<Course::BuildingBase>& building) override;
};

#endif // ROCK_HH
