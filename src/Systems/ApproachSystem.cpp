#include "Systems/ApproachSystem.h"
#include <ECS/EntityHandle.h>

void ApproachSystem::update(double dt) {
    for(auto& entity : entities_) {
        Velocity& velocity = entity.get<Velocity>();
        VelApproach& approach = entity.get<VelApproach>();

        double delta = approach.intensity * dt;

        if(velocity.x - delta > approach.x) {
            velocity.x -= delta;
        } else if(velocity.x + delta < approach.x) {
            velocity.x += delta;
        } else {
            velocity.x = approach.x;
        }

        if(velocity.y - delta > approach.y) {
            velocity.y -= delta;
        } else if(velocity.y + delta < approach.y) {
            velocity.y += delta;
        } else {
            velocity.y = approach.y;
        }
    }
}
