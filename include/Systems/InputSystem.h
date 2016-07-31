#ifndef GAME_INPUTSYSTEM_H
#define GAME_INPUTSYSTEM_H

#include <ECS/System.h>
#include <Components/Control.h>

class InputSystem : public ecs::System<Control> {
public:
    void update(double dt) override;
};

#endif //GAME_INPUTSYSTEM_H
