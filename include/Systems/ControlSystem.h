#ifndef GAME_MOVESYSTEM_H
#define GAME_MOVESYSTEM_H

#include <ECS/System.h>
#include <Components/Flip.h>
#include <Components/Control.h>
#include <Components/VelApproach.h>

class ControlSystem : public ecs::System<Control, VelApproach, Flip> {
public:
    void update(double dt) override;
};

#endif //GAME_MOVESYSTEM_H
