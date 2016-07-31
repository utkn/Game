#ifndef GAME_MAPSCENE_H
#define GAME_MAPSCENE_H

#include <Graphics/RenderWindow.h>
#include <Graphics/Texture.h>
#include <Systems/RenderSystem.h>
#include <Misc/Factory.h>
#include <Misc/TiledMap.h>
#include "Scene.h"

class MapScene : public Scene {
    TiledMap map;
    Factory factory;
    RenderWindow& window;
    RenderSystem renderSystem;
public:
    MapScene(RenderWindow& window, std::string const& level);
    bool update(double dt) override;
private:
    void loadTiles();
    void loadColliders();
    void loadPlayer();
};


#endif //GAME_MAPSCENE_H
