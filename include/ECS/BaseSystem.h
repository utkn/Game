#ifndef GAME_BASESYSTEM_H
#define GAME_BASESYSTEM_H

#include <vector>
#include "Misc.h"

namespace ecs {
    class EntityHandle;
    class Manager;

    class BaseSystem {
    protected:
        friend class Manager;
        Mask filter_;
        std::vector<EntityHandle> entities_;
        Manager* managerRef_;

        void entityAdded(EntityID entityID);
        void entityRemoved(EntityID entityID);
        void entityModified(EntityID entityID);
        bool satisfies(EntityID entityID);
        std::vector<EntityHandle>::iterator findEntity(EntityID entityID);
    public:
        virtual void update(double dt) = 0;
    };
}

#endif //GAME_BASESYSTEM_H
