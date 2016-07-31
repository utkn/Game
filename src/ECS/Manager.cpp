#include "ECS/Manager.h"
#include "ECS/EntityHandle.h"

ecs::EntityHandle ecs::Manager::newEntity() {
    ecs::EntityHandle handle = createHandle(++nextID_);
    entities_.push_back(handle.id());
    return handle;
}

ecs::EntityHandle ecs::Manager::createHandle(ecs::EntityID entityID) {
    return ecs::EntityHandle(this, entityID);
}

ecs::Mask& ecs::Manager::getMask(ecs::EntityID entityID) {
    return entityMaskMap_[entityID];
}

void ecs::Manager::removeEntity(ecs::EntityID entityID) {
    notifyEntityRemoved(entityID);
    // TODO Recycle ids
    for(auto& comp : entityCompMap_[entityID]) {
        if(comp != nullptr) {
            comp.reset(nullptr);
        }
    }
    entityMaskMap_[entityID].reset();
    entities_.erase(std::find(entities_.begin(), entities_.end(), entityID));
}

void ecs::Manager::attach(ecs::BaseSystem &system) {
    systems_.push_back(&system);
    system.managerRef_ = this;
    for(auto& entity : entities_) {
        system.entityAdded(entity);
    }
}

void ecs::Manager::notifyEntityRemoved(ecs::EntityID id) {
    for(auto& system : systems_) {
        system->entityRemoved(id);
    }
}

void ecs::Manager::notifyEntityModified(ecs::EntityID id) {
    for(auto& system : systems_) {
        system->entityModified(id);
    }
}

void ecs::Manager::update(double dt) {
    for(auto& system : systems_) {
        system->update(dt);
    }
}
