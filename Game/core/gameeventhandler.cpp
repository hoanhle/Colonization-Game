#include "gameeventhandler.hh"
#include "vector"
#include "interfaces/igameeventhandler.h"
#include "iostream"
#include "core/nresourcemaps.hh"
#include "algorithm"
#include "core/player.hh"

GameEventHandler::GameEventHandler()
{
}

void GameEventHandler::createPlayers(int numberPlayers)
{
    std::vector<std::string> maximumNames = {"player1", "player2", "player3", "player4"};

    for (int i = 0; i < numberPlayers; i++){
        std::shared_ptr<Player> newplayer =
                std::make_shared<Player>(maximumNames[i]);
        players_.push_back(newplayer);
    }
}

void GameEventHandler::createBeginResource()
{
    for (int i = 0; i < players_.size(); i++){
        players_[i]->setBeginningResource();
    }
}

void GameEventHandler::createBeginWorker()
{
    for (int i = 0; i < players_.size(); i++){
        players_[i]->setBeginningWorker();
    }
}

Course::ResourceMap* GameEventHandler::getCurrentPlayerResource()
{
    Course::ResourceMap* playerResource = players_[current_]->getCurrentResources();
    return playerResource;
}

std::map<std::string, int> *GameEventHandler::getCurrentPlayerWorkerNumber()
{
    return players_[current_]->getCurrentWorkers();
}

std::map<std::string, int> *GameEventHandler::getCurrentFreeWorkerNumber()
{
    qDebug() << "GE call get current free worker";
    return players_[current_]->getFreeWorkers();
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
    std::cout << players_[current_]->getName() << std::endl;
}

std::shared_ptr<Player> GameEventHandler::getCurrentPlayer()
{
    return players_[current_];
}


void GameEventHandler::setCurrentTile(std::shared_ptr<Course::GameObject> tile)
{
    tile_ = tile;
}

std::shared_ptr<Course::GameObject> GameEventHandler::returnSelectedTile()
{
    return tile_;
}

void GameEventHandler::assignWorkers(int numberWorker, std::string workerType)
{
    std::vector<std::shared_ptr<NewBasicWorker>> workersToRemove =
            getCurrentPlayer()->findWorkerstoRemove(numberWorker, workerType);

    getCurrentPlayer()->removeWorkers(workersToRemove);
}

bool GameEventHandler::modifyResource(std::shared_ptr<Course::PlayerBase> player,
                                      Course::BasicResource resource, int amount)
{
    if ( player == getCurrentPlayer())
    {
        bool success = getCurrentPlayer()->modifyPlayerResource(resource, amount);
        return success;
    }else
    {
        return false;
    }


}

bool GameEventHandler::modifyResources(std::shared_ptr<Course::PlayerBase> player, Course::ResourceMap resources)
{
    if (player == getCurrentPlayer())
    {
        return modifyResources(resources);
    }else {
        return false;
    }
}

bool GameEventHandler::modifyResources(Course::ResourceMap resources)
{
    bool success = getCurrentPlayer()->modifyPlayerResources(resources);
    return success;
}
