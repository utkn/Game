#ifndef GAME_ANIMATION_H
#define GAME_ANIMATION_H

#include <ECS/Component.h>
#include <Misc/TextureAtlas.h>

struct Animation : public ecs::Component {
    TextureAtlas& atlas;

    Animation(TextureAtlas& atlas) : atlas(atlas) {}
};

#endif //GAME_ANIMATION_H
