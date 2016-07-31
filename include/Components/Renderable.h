#ifndef GAME_RENDERABLE_H
#define GAME_RENDERABLE_H

#include <Graphics/TextureRegion.h>
#include <ECS/Component.h>

struct Renderable : public ecs::Component {
    TextureRegion region;
    Renderable(TextureRegion& region) : region(region) {}
};

#endif //GAME_RENDERABLE_H
