#ifndef GAME_FACTORY_H
#define GAME_FACTORY_H


#include <ECS/EntityHandle.h>
#include <Graphics/TextureRegion.h>
#include <Misc/TextureAtlas.h>

class Factory {
    std::unordered_map<std::string, TextureAtlas> atlasMap_;
public:
    Factory(RenderWindow& window);
    void createSprite(ecs::EntityHandle &handle, TextureRegion &region);
    void createPlayer(ecs::EntityHandle &handle, int spawnX, int spawnY);
};


#endif //GAME_FACTORY_H
