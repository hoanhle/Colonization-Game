#include "core/player.hh"
#include "core/nresourcemaps.hh"
#include <algorithm>
#include "QDebug"

Player::Player(const std::string &name):
    Course::PlayerBase(name)
{
}

Course::ResourceMap* Player::getCurrentResources()
{
    return &(resource_);
}

void Player::setBeginningResource()
{
    resource_ = NewResourceMaps::BEGINNING_RESOURCE;
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


