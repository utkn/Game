#ifndef GAME_POSITION_H
#define GAME_POSITION_H

#include <ECS/Component.h>

struct Position : public ecs::Component {
    double x;
    double y;
    Position(double x = 0, double y = 0) : x(x), y(y) {}
};

#endif //GAME_POSITION_H
