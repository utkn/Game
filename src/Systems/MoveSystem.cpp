#include <Components/Velocity.h>
#include <Components/Position.h>
#include "Systems/MoveSystem.h"
#include <ECS/EntityHandle.h>

void MoveSystem::update(double dt) {
    for(auto& entity : entities_) {
        Velocity& velocity = entity.get<Velocity>();
        Position& position = entity.get<Position>();
        position.x += velocity.x * dt;
        position.y += velocity.y * dt;
    }
}