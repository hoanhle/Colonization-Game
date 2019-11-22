#include "gameeventhandler.hh"
#include "vector"
#include "core/playerbase.h"
#include "interfaces/igameeventhandler.h"
#include "iostream"
#include "nresourcemaps.hh"

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
        qDebug() << player->getName().data();
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

void GameEventHandler::printCurrentPlayer()
{
    qDebug() << players_[current_]->getName().data();
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

}
