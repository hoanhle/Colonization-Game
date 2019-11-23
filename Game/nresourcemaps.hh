#ifndef NRESOURCEMAPS_HH
#define NRESOURCEMAPS_HH


#include "core/basicresources.h"

// Add new resourcemap elements
namespace NewResourceMaps {

const Course::ResourceMap BEGINNING_RESOURCE = {
    {Course::MONEY, 500},
    {Course::FOOD, 500},
    {Course::WOOD, 500},
    {Course::STONE, 500},
    {Course::ORE, 500},
};

const Course::ResourceMap SMALLHOUSE_BUILD_COST = {
    {Course::MONEY, 50},
    {Course::FOOD, 100},
    {Course::WOOD, 25}
};
const Course::ResourceMap SMALLHOUSE_PRODUCTION = {
    {Course::MONEY, 0},
    {Course::FOOD, -1}
};

const Course::ResourceMap LARGEHOUSE_BUILD_COST = {
    {Course::MONEY, 100},
    {Course::FOOD, 150},
    {Course::WOOD, 35}
};
const Course::ResourceMap LARGEHOUSE_PRODUCTION = {
    {Course::MONEY, 0},
    {Course::FOOD, -2}
};

const Course::ResourceMap ROCK_BP = {
    {Course::MONEY, 3},
    {Course::FOOD, 0},
    {Course::WOOD, 0},
    {Course::STONE, 5},
    {Course::ORE, 2},
};

const Course::ResourceMap SAND_BP = {
    {Course::MONEY, 1},
    {Course::FOOD, 1},
    {Course::WOOD, 0},
    {Course::STONE, 1},
    {Course::ORE, 2},
};

const Course::ResourceMap WATER_BP = {
    {Course::MONEY, 3},
    {Course::FOOD, 5},
    {Course::WOOD, 0},
    {Course::STONE, 0},
    {Course::ORE, 0},
};


}


#endif // NRESOURCEMAPS_HH
