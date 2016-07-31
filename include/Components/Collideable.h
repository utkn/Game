#ifndef GAME_COLLIDEABLE_H
#define GAME_COLLIDEABLE_H

#include <ECS/Component.h>
#include <Math/Vector.h>
#include <vector>
#include <ECS/EntityHandle.h>

struct Collideable : public ecs::Component {
    bool solid;
    bool fixed;
    bool checked = false;
    std::vector<std::pair<ecs::EntityHandle*, Vector>> contacts;

    Collideable(bool solid = false, bool fixed = false) : solid(solid), fixed(fixed) {}
};

#endif //GAME_COLLIDEABLE_H
