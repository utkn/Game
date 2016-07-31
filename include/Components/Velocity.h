#ifndef GAME_VELOCITY_H
#define GAME_VELOCITY_H

#include <ECS/Component.h>

struct Velocity : public ecs::Component {
    double x;
    double y;
    Velocity(double x = 0, double y = 0) : x(x), y(y) {}
};

#endif //GAME_VELOCITY_H
