#include "gameeventhandler.hh"
#include "vector"
#include "core/playerbase.h"
#include "interfaces/igameeventhandler.h"
#include "iostream"
#include "nresourcemaps.hh"
#include "algorithm"

GameEventHandler::GameEventHandler()
{
}

void GameEventHandler::createPlayers(int numberPlayers)
{
    std::vector<std::string> maximumNames = {"player1", "player2", "player3", "player4"};

    for (int i = 0; i < numberPlayers; i++){
        std::shared_ptr<Course::PlayerBase> newplayer =
                std::make_shared<Course::PlayerBase>(maximumNames[i]);
        players_.push_back(newplayer);
    }
}

void GameEventHandler::printPlayerNames()
{
    for (auto player : players_){
        std::cout << player->getName() << std::endl;
    }
}

void GameEventHandler::createBeginResource()
{
    for (int i = 0; i < players_.size(); i++){
        playersResource_.push_back(NewResourceMaps::BEGINNING_RESOURCE);
    }
}

Course::ResourceMap GameEventHandler::getCurrentPlayerResource()
{
    return playersResource_[current_];
}

void GameEventHandler::changePlayer()
{
    if (current_ == players_.size() - 1){
        current_ = 0;
    } else {
        current_ += 1;
    }
}

std::shared_ptr<Course::PlayerBase> GameEventHandler::getCurrentPlayer()
{
    return players_[current_];
}

void GameEventHandler::printCurrentPlayer()
{
    std::cout << players_[current_]->getName() << std::endl;
}

void GameEventHandler::setCurrentTile(std::shared_ptr<Course::GameObject> tile)
{
    tile_ = tile;
}

std::shared_ptr<Course::GameObject> GameEventHandler::returnSelectedTile()
{
    return tile_;
}

bool GameEventHandler::modifyResource(std::shared_ptr<Course::PlayerBase> player, Course::BasicResource resource, int amount)
{

}

bool GameEventHandler::modifyResources(std::shared_ptr<Course::PlayerBase> player, Course::ResourceMap resources)
{
    Course::ResourceMap currentResource = playersResource_[current_];
    Course::ResourceMap newResource = Course::mergeResourceMaps(currentResource, resources);
    bool success = true;

    for (auto it = newResource.begin(); it != newResource.end(); it++){
        if (it->second < 0){
            success = false;
        }
    }

    if (success){
        playersResource_[current_] = newResource;
    }

    return success;
}
