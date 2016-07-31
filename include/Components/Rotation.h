#ifndef GAME_ROTATION_H
#define GAME_ROTATION_H

#include <ECS/Component.h>

struct Rotation : ecs::Component {
    double angle;
    Rotation(double angle = 0) : angle(angle) {}
};

#endif //GAME_ROTATION_H
