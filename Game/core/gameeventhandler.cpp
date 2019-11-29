#include "gameeventhandler.hh"
#include "vector"
#include "interfaces/igameeventhandler.h"
#include "iostream"
#include "core/nresourcemaps.hh"
#include "algorithm"
#include "core/player.hh"
#include "tiles/tilebase.h"

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


void GameEventHandler::setCurrentTile(std::shared_ptr<Course::TileBase> tile)
{
    tile_ = tile;
}

std::shared_ptr<Course::TileBase> GameEventHandler::returnSelectedTile()
{
    return tile_;
}

void GameEventHandler::assignWorkers(int numberWorker, std::string workerType)
{
    std::vector<std::shared_ptr<NewBasicWorker>> workersToRemove =
            getCurrentPlayer()->findWorkerstoRemove(numberWorker, workerType);

    getCurrentPlayer()->removeWorkers(workersToRemove);

    for (int i = 0; i < numberWorker; i++){
        tile_->addWorker(workersToRemove[i]);
    }
}

std::vector<std::shared_ptr<NewBasicWorker> > GameEventHandler::getWorkerstoFree(
        int numberWorker, std::string workerType) const
{
//    std::vector<std::shared_ptr<NewBasicWorker>> freeWorkers;
//    std::vector< std::shared_ptr<Course::WorkerBase> > tileWorkers = tile_->getWorkers();

//    int found = 0;
//    for (auto it = tileWorkers.begin(); it < tileWorkers.end(); it++){
//        if (found == numberWorker){
//            break;
//        }
//        std::shared_ptr<NewBasicWorker> freeWorker = std::dynamic_pointer_cast<NewBasicWorker>(*it);
//        if (freeWorker->getType() == workerType){
//            freeWorkers.push_back(freeWorker);
//        }
//    }
//    return freeWorkers;
}

void GameEventHandler::unassignWorkers(int numberWorker, std::string workerType)
{
    std::vector<std::shared_ptr<NewBasicWorker>> freeWorkers =
            getWorkerstoFree(numberWorker, workerType);

    for (auto freeWorker : freeWorkers){
        tile_->removeWorker(freeWorker);
        getCurrentPlayer()->addWorkerBack(freeWorker);
    }
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

bool GameEventHandler::checkWinning()
{
    Course::ResourceMap* playerResource = players_[current_]->getCurrentResources();
    auto playerWorker = this->getCurrentPlayerWorkerNumber();

    bool win = false;

    int totalResource = 0;
    for (auto pair : *playerResource){
        totalResource += pair.second;
    }

    int totalWorker = 0;
    for (auto pair: *playerWorker){
        totalWorker += pair.second;
    }

    if (totalResource >= 3000 and totalWorker >= 10){
        win = true;
    }

    return win;
}
