#include <iostream>
#include "Systems/ControlSystem.h"
#include "ECS/EntityHandle.h"

void ControlSystem::update(double dt) {
    for(auto& entity : entities_) {
        Control& control = entity.get<Control>();
        VelApproach& approach = entity.get<VelApproach>();
        if(control.left) {
            approach.x = -approach.maxSpeed;
            entity.get<Flip>().x = true;
        } else if(control.right) {
            approach.x = approach.maxSpeed;
            entity.get<Flip>().x = false;
        } else {
            approach.x = 0.f;
        }
    }
}
