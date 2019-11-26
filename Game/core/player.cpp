#include "player.hh"
#include "core/nresourcemaps.hh"
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
