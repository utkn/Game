#ifndef GAME_CONTROL_H
#define GAME_CONTROL_H

#include <ECS/Component.h>

struct Control : ecs::Component {
    bool left = false;
    bool right = false;
    bool jump = false;
    bool attack = false;
    bool activate = false;
};

#endif //GAME_CONTROL_H
