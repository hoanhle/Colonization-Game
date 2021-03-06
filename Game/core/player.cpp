#include "core/player.hh"
#include "exceptions/keyerror.h"
#include <algorithm>
#include "QDebug"
#include "iostream"

namespace Student {
Player::Player(const std::string &name):
    Course::PlayerBase(name)
{
}

Course::ResourceMap* Player::getCurrentResources()
{
    return &(resource_);
}

std::map<std::string, int> *Player::getCurrentWorkers()
{
    return &(totalNumberWorker_);
}

std::map<std::string, int> *Player::getFreeWorkers()
{
    qDebug() << "Player call total free worker";
    return &(totalFreeWorker_);
}

void Player::setBeginningResource()
{
    resource_ = NewResourceMaps::BEGINNING_RESOURCE;
}

void Player::setBeginningWorker()
{
    totalNumberWorker_ = {{"BasicWorker", 0},
                          {"Farmer", 0},
                          {"Miner", 0},
                          {"Logger", 0}};

    totalFreeWorker_ = {{"BasicWorker", 0},
                        {"Farmer", 0},
                        {"Miner", 0},
                        {"Logger", 0}};
}

bool Player::modifyPlayerResources(Course::ResourceMap resources)
{
    Course::ResourceMap currentResource = resource_;
    Course::ResourceMap newResource = Course::mergeResourceMaps(currentResource, resources);

    bool success = true;

    for (auto it = newResource.begin(); it != newResource.end(); it++){
        if (it->second < 0){
            success = false;
        }
    }

    if (success) {
        resource_ = newResource;
    }

    return success;
}

bool Player::modifyPlayerResource(Course::BasicResource resource, int amount)
{
    bool success = true;
    int currentBasicResource = resource_.at(resource);

    currentBasicResource = currentBasicResource - amount;

    if (currentBasicResource < 0){
        success = false;
    }

    if (success) {
        resource_.at(resource) = currentBasicResource;
    }

    return success;
}

void Player::addWorker(std::shared_ptr<NewBasicWorker> worker)
{
    workers_.push_back(std::weak_ptr<NewBasicWorker>(worker));
}

void Player::addWorkers(const std::vector<std::shared_ptr<NewBasicWorker> > workers)
{
    workers_.insert(workers_.end(), workers.begin(), workers.end());
}

void Player::addWorker(std::string workerType)
{
    totalNumberWorker_.at(workerType) += 1;
    totalFreeWorker_.at(workerType) += 1;
}

void Player::addWorkerBack(std::shared_ptr<NewBasicWorker> worker)
{
    workers_.push_back(std::weak_ptr<NewBasicWorker>(worker));
    totalFreeWorker_.at(worker->getType()) += 1;
}

std::vector<std::shared_ptr<NewBasicWorker> > Player::findWorkerstoRemove(int numberWorker, std::string workertype)
{
    std::vector<std::shared_ptr<NewBasicWorker>> found_workers;
    int number_found = 0;

    std::cout << workers_.size();
    for (auto it = workers_.begin(); it != workers_.end(); it++){
        if (number_found == numberWorker){
            break;
        }

        std::shared_ptr<NewBasicWorker> locked = it->lock();
        if (locked){
            if (locked->getType() == workertype){
                found_workers.push_back(locked);
                number_found += 1;
            }

        }
    }

    // Update free workers info after this
    totalFreeWorker_.at(workertype) -= numberWorker;

    return found_workers;
}


void Player::removeWorker(const Course::ObjectId &id)
{
    bool found = false;

    auto it = std::remove_if(workers_.begin(), workers_.end(),
                             [id, &found](std::weak_ptr<NewBasicWorker>& x){
       auto locked = x.lock();

       if (not locked){
           return true;
       }
       if(locked->ID == id){
           found = true;
           return true;
       }
       return false;
    });

    workers_.erase(it, workers_.end());

    if (not found){
        throw Course::KeyError("Object not found.");
    }
}

void Player::removeWorker(const std::shared_ptr<NewBasicWorker> &worker)
{
    if (not worker){
        removeWorker(std::numeric_limits<Course::ObjectId>::max());
    }
    removeWorker(worker->ID);
}

void Player::removeWorkers(const std::vector<Course::ObjectId> &ids)
{
    for (auto it = ids.begin(); it != ids.end(); it++){
        try {
            removeWorker(*it);
        } catch (const Course::KeyError&) {
            continue;
        }
    }
}

void Player::removeWorkers(
        const std::vector<std::shared_ptr<NewBasicWorker>> &workers)
{
    for (auto it = workers.begin(); it!= workers.end(); it++){
        try{
            removeWorker(*it);
        }
        catch (const Course::KeyError&){
            continue;
        }
    }
}

} // namespace Student


