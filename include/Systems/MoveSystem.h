#ifndef GAME_COLLISIONSYSTEM_H
#define GAME_COLLISIONSYSTEM_H

#include <ECS/System.h>
#include <Components/Position.h>
#include <Components/Velocity.h>

class MoveSystem : public ecs::System<Position, Velocity> {
public:
    void update(double dt) override;
};

#endif //GAME_COLLISIONSYSTEM_H
