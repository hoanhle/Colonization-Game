#ifndef NRESOURCEMAPS_HH
#define NRESOURCEMAPS_HH


#include "core/basicresources.h"

namespace Student {

// Add new resourcemap elements
namespace NewResourceMaps {

// Resources allocated at beginning of game
const Course::ResourceMap BEGINNING_RESOURCE = {
    {Course::MONEY, 500},
    {Course::FOOD, 500},
    {Course::WOOD, 500},
    {Course::STONE, 500},
    {Course::ORE, 500},
};
//BUILDING RESOURCES
// Smallhouse resources
const Course::ResourceMap SMALLHOUSE_BUILD_COST = {
    {Course::MONEY, 50},
    {Course::FOOD, 100},
    {Course::WOOD, 25}

};
const Course::ResourceMap SMALLHOUSE_PRODUCTION = {
    {Course::MONEY, 0},
    {Course::FOOD, 0}
};

// Apartment block resources
const Course::ResourceMap APARTMENT_BUILD_COST = {
    {Course::MONEY, 250},
    {Course::FOOD, 200},
    {Course::WOOD, 100},
    {Course::STONE, 100},
};
const Course::ResourceMap APARTMENT_PRODUCTION = {
    {Course::MONEY, 0},
    {Course::FOOD, 0}
};

// SkyScraper resources
const Course::ResourceMap SKYSCRAPER_BUILD_COST = {
    {Course::MONEY, 1000},
    {Course::FOOD, 500},
    {Course::WOOD, 500},
    {Course::STONE, 500},
};
const Course::ResourceMap SKYSCRAPER_PRODUCTION = {
    {Course::MONEY, 0},
    {Course::FOOD, 0}
};

// LargeHouse resources
const Course::ResourceMap LARGEHOUSE_BUILD_COST = {
    {Course::MONEY, 100},
    {Course::FOOD, 150},
    {Course::WOOD, 35},
    {Course::STONE, 50},
};
const Course::ResourceMap LARGEHOUSE_PRODUCTION = {
    {Course::MONEY, 0},
    {Course::FOOD, 0}
};

// Mine resources
const Course::ResourceMap MINE_BUILD_COST = {
    {Course::MONEY, 200},
    {Course::FOOD, 100},
    {Course::WOOD, 100},
    {Course::ORE, 50}
};
const Course::ResourceMap MINE_PRODUCTION = {
    {Course::MONEY, 20},
    {Course::STONE, 50},
    {Course::FOOD, 5},
    {Course::ORE, 35}
};

// Sawmill resources
const Course::ResourceMap SAWMILL_BUILD_COST = {
    {Course::MONEY, 100},
    {Course::FOOD, 100},
    {Course::WOOD, 100}
};
const Course::ResourceMap SAWMILL_PRODUCTION = {
    {Course::MONEY, 20},
    {Course::WOOD, 50},
    {Course::FOOD, 5}
};



// TILE BASE PRODUCTIONS
// Rock base production
const Course::ResourceMap ROCK_BP = {
    {Course::MONEY, 3},
    {Course::FOOD, 0},
    {Course::WOOD, 0},
    {Course::STONE, 5},
    {Course::ORE, 2},
};

// Sand base production
const Course::ResourceMap SAND_BP = {
    {Course::MONEY, 1},
    {Course::FOOD, 1},
    {Course::WOOD, 0},
    {Course::STONE, 1},
    {Course::ORE, 2},
};

// Water base production
const Course::ResourceMap WATER_BP = {
    {Course::MONEY, 3},
    {Course::FOOD, 5},
    {Course::WOOD, 0},
    {Course::STONE, 0},
    {Course::ORE, 0},
};

const Course::ResourceMapDouble FARMER_EFFICIENCY = {
    {Course::MONEY, 0.5},
    {Course::FOOD, 1.5},
    {Course::WOOD, 0.5},
    {Course::STONE, 0.25},
    {Course::ORE, 0.25}
};

const Course::ResourceMapDouble NEW_BASIC_WORKER_EFFICIENCY = {
    {Course::MONEY, 0.25},
    {Course::FOOD, 1.00},
    {Course::WOOD, 0.75},
    {Course::STONE, 0.50},
    {Course::ORE, 0.50}
};

const Course::ResourceMapDouble LOGGER_EFFICIENCY = {
    {Course::MONEY, 0.50},
    {Course::FOOD, 0.25},
    {Course::WOOD, 1.50},
    {Course::STONE, 0.25},
    {Course::ORE, 0.50}
};

const Course::ResourceMapDouble MINER_EFFICIENCY = {
    {Course::MONEY, 0.50},
    {Course::FOOD, 0.25},
    {Course::WOOD, 0.25},
    {Course::STONE, 1.00},
    {Course::ORE, 1.00}
};

}
} // namespace Student


#endif // NRESOURCEMAPS_HH
