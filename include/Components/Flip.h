#ifndef GAME_FLIP_H
#define GAME_FLIP_H

#include <ECS/Component.h>

struct Flip : ecs::Component {
    bool x;
    bool y;
    Flip(bool x = false, bool y = false) : x(x), y(y) {}
};

#endif //GAME_FLIP_H
