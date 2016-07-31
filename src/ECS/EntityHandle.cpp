#include "ECS/EntityHandle.h"

void ecs::EntityHandle::destroy() {
    managerRef_->removeEntity(id_);
    managerRef_ = nullptr;
}

ecs::EntityID ecs::EntityHandle::id() {
    return id_;
}
