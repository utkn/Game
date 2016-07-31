#ifndef GAME_CENTER_H
#define GAME_CENTER_H

#include <ECS/Component.h>

struct Center : ecs::Component {
    int x;
    int y;
    Center(int x = 0, int y = 0) : x(x), y(y) {}
};

#endif //GAME_CENTER_H
