#ifndef GAME_VELAPPROACH_H
#define GAME_VELAPPROACH_H

#include <ECS/Component.h>

struct VelApproach : ecs::Component {
    double x = 0;
    double y = 0;
    double maxSpeed;
    double intensity;
    VelApproach(double maxSpeed, double intensity) : maxSpeed(maxSpeed), intensity(intensity) {}
};

#endif //GAME_VELAPPROACH_H