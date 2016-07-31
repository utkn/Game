#ifndef GAME_BOUNDS_H
#define GAME_BOUNDS_H

#include <ECS/Component.h>
#include <Math/Polygon.h>

struct Bounds : public ecs::Component {
    Polygon shape;
    Bounds(Polygon shape) : shape(shape) {}
};

#endif //GAME_BOUNDS_H
