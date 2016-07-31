#ifndef GAME_APPROACHSYSTEM_H
#define GAME_APPROACHSYSTEM_H

#include <ECS/System.h>
#include <Components/Velocity.h>
#include <Components/VelApproach.h>

class ApproachSystem : public ecs::System<Velocity, VelApproach> {
public:
    void update(double dt) override;
};

#endif //GAME_APPROACHSYSTEM_H
