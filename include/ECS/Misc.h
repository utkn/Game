#ifndef GAME_MISC_H
#define GAME_MISC_H

#include <unordered_map>
#include <array>
#include <bitset>
#include "Component.h"

namespace ecs {
    constexpr int MAX_COMPONENTS = 256;
    typedef int CompID;
    typedef int EntityID;
    typedef std::array<std::unique_ptr<Component>, MAX_COMPONENTS> ComponentArray;
    typedef std::unordered_map<EntityID, ComponentArray> EntityCompMap;
    typedef std::bitset<MAX_COMPONENTS> Mask;
    typedef std::unordered_map<EntityID, Mask> EntityMaskMap;

    struct CompIDGenerator {
    private:
        static CompID next;
    public:
        template <typename T>
        static CompID get() {
            static CompID id = next++;
            return id;
        }
    };

    template <typename... Args>
    void expand(Args&&... args) {}
}

#endif //GAME_MISC_H
