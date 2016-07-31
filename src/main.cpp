#include <iostream>
#include <Graphics/Graphics.h>
#include <ECS/ECS.h>
#include <Components/Position.h>
#include <Components/Renderable.h>
#include <Systems/RenderSystem.h>
#include <Scenes/SceneManager.h>
#include <Scenes/MapScene.h>
#include <Misc/Factory.h>

ecs::EntityHandle createSprite(ecs::Manager& manager, TextureRegion& region, int posX, int posY) {
    ecs::EntityHandle handle = manager.newEntity();
    handle.add<Center>(region.width/2, region.height/2);
    handle.add<Renderable>(region);
    handle.add<Position>(posX, posY);
    handle.add<Scale>();
    handle.add<Rotation>();
    handle.add<Flip>();
    return handle;
}

int main() {
    RenderWindow window("hello", 640, 480);
    SceneManager manager;
    MapScene map(window, "level1");
    manager.put(map);

    bool quit = false;
    SDL_Event e;
    while(!quit) {
        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT) {
                quit = true;
            }
        }
        manager.update(1.0/60);
    }

    return 0;
}