#ifndef GAME_SYSTEM_H
#define GAME_SYSTEM_H

#include "BaseSystem.h"

namespace ecs {
    template<typename... Deps>
    class System : public BaseSystem {
    protected:
        System() {
            expand((filter_[CompIDGenerator::get<Deps>()] = true)...);
        }
    };
}
#endif //GAME_SYSTEM_H
