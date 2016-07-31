#include "ECS/BaseSystem.h"
#include "ECS/Manager.h"
#include "ECS/EntityHandle.h"

void ecs::BaseSystem::entityAdded(ecs::EntityID entityID) {
    if(satisfies(entityID)) {
        entities_.push_back(managerRef_->createHandle(entityID));
    }
}

void ecs::BaseSystem::entityRemoved(ecs::EntityID entityID) {
    if(satisfies(entityID)) {
        entities_.erase(findEntity(entityID));
    }
}

void ecs::BaseSystem::entityModified(ecs::EntityID entityID) {
    auto find = findEntity(entityID);
    if(satisfies(entityID) && find == entities_.end()) {
        entities_.push_back(managerRef_->createHandle(entityID));
    } else if(!satisfies(entityID) && find != entities_.end()) {
        entities_.erase(find);
    }
}

bool ecs::BaseSystem::satisfies(ecs::EntityID entityID) {
    return (filter_ & managerRef_->getMask(entityID)) == filter_;
}

std::vector<ecs::EntityHandle>::iterator ecs::BaseSystem::findEntity(ecs::EntityID entityID) {
    return std::find_if(entities_.begin(), entities_.end(), [&](ecs::EntityHandle& handle) {
        return handle.id() == entityID;
    });
}
