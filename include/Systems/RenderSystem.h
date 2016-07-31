#ifndef GAME_RENDERSYSTEM_H
#define GAME_RENDERSYSTEM_H

#include <Graphics/RenderWindow.h>
#include <Components/Renderable.h>
#include <Components/Position.h>
#include <ECS/EntityHandle.h>
#include <ECS/System.h>
#include <Components/Rotation.h>
#include <Components/Scale.h>
#include <Components/Flip.h>
#include <Components/Center.h>

class RenderSystem : public ecs::System<Renderable, Position, Scale, Rotation, Flip, Center> {
    RenderWindow& window;
public:
    explicit RenderSystem(RenderWindow& window) : window(window) {}
    void update(double dt) override;
};

#endif //GAME_RENDERSYSTEM_H
