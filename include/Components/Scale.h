#ifndef GAME_SCALE_H
#define GAME_SCALE_H

#include <ECS/Component.h>

struct Scale : ecs::Component {
    double x;
    double y;
    Scale(double x = 1, double y = 1) : x(x), y(y) {}
};

#endif //GAME_SCALE_H
