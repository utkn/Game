#ifndef GAME_MAPSCENE_H
#define GAME_MAPSCENE_H


#include <tmxparser/Tmx.h>
#include <Graphics/RenderWindow.h>
#include <Graphics/Texture.h>
#include <Systems/RenderSystem.h>
#include <Misc/Tileset.h>
#include <Misc/Factory.h>
#include "Scene.h"


class MapScene : public Scene {
    Tmx::Map map_;
    std::unordered_map<std::string, std::unique_ptr<Tileset>> textureMap_;
    Factory factory;
    std::map<int, std::string> globalIDMap_;
    RenderWindow& window;

    RenderSystem renderSystem;

    Tileset* getTileset(int gid);
    void populateTiles();
    void populateObjects();
    void processTileLayer(Tmx::TileLayer* tileLayer);
    void processCollisionGroup(Tmx::ObjectGroup* objectGroup);
    void processSpawn(Tmx::Object const* spawn);
public:
    MapScene(RenderWindow& window, std::string const& level);
    bool update(double dt) override;
};


#endif //GAME_MAPSCENE_H
