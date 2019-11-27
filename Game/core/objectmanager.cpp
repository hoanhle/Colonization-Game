#include "objectmanager.hh"

ObjectManager::ObjectManager():
    m_tiles()
{

}



std::shared_ptr<Course::TileBase> ObjectManager::getTile(const Course::ObjectId &id)
{
    std::vector<std::shared_ptr<Course::TileBase>>::iterator it;
    for(it = m_tiles.begin(); it != m_tiles.end(); ++it)
    {
        if( (*it)->ID == id )
        {
            return *it;
        }
    }

    std::shared_ptr<Course::TileBase> empty;
    return empty;
}

std::shared_ptr<Course::TileBase> ObjectManager::getTile(const Course::Coordinate &coordinate)
{
    std::vector<std::shared_ptr<Course::TileBase>>::iterator it;
    for(it = m_tiles.begin(); it != m_tiles.end(); ++it)
    {
        if( (*it)->getCoordinate() == coordinate )
        {
            return *it;
        }
    }

    std::shared_ptr<Course::TileBase> empty;
    return empty;
}

void ObjectManager::addTiles(const std::vector<std::shared_ptr<Course::TileBase> > &tiles)
{
    for( auto tile = tiles.begin(); tile != tiles.end(); ++tile)
    {
        m_tiles.push_back(*tile);
    }
}

std::vector<std::shared_ptr<Course::TileBase> > ObjectManager::getTiles(const std::vector<Course::Coordinate> &coordinates)
{
    std::vector<std::shared_ptr<Course::TileBase>> tiles;


    for(auto it = coordinates.begin(); it != coordinates.end(); ++it)
    {
        std::shared_ptr<Course::TileBase> x = getTile(*it);
        if(x != nullptr)
        {
            tiles.push_back(x);
        }
    }
    return tiles;
}


std::vector<std::shared_ptr<Course::TileBase> > ObjectManager::getAllTiles()
{
    std::vector<std::shared_ptr<Course::TileBase>> tiles;

    for(auto tile = m_tiles.begin(); tile != m_tiles.end(); ++tile)
    {
        tiles.push_back(*tile);
    }
    return tiles;
}

void ObjectManager::addBuilding(std::shared_ptr<Course::BuildingBase> building )
{
    m_buildings.push_back(building);
}

void ObjectManager::addWorker(std::shared_ptr<NewBasicWorker> worker)
{
    m_workes.push_back(worker);
}


