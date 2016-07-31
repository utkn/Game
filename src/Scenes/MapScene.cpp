#include <iostream>
#include <Components/Renderable.h>
#include <Components/Position.h>
#include <Components/Scale.h>
#include <Components/Rotation.h>
#include <Components/Flip.h>
#include <Components/Center.h>
#include <Math/Polygon.h>
#include <Components/Bounds.h>
#include <Components/Collideable.h>
#include <Misc/TextureAtlas.h>
#include <Misc/Factory.h>
#include "Scenes/MapScene.h"

MapScene::MapScene(RenderWindow& window, std::string const& level) : window(window), renderSystem(window),
                                                                     factory(window), map(level, window) {
    loadTiles();
    loadColliders();
    loadPlayer();
    entityManager_.attach(renderSystem);
}

bool MapScene::update(double dt) {
    entityManager_.update(dt);
    return true;
}

void MapScene::loadTiles() {
    for(auto& tile : map.tiles) {
        ecs::EntityHandle handle = entityManager_.newEntity();
        factory.createSprite(handle, tile.src);
        handle.get<Position>().x = tile.x;
        handle.get<Position>().y = tile.y;
    }
}

void MapScene::loadPlayer() {

}

void MapScene::loadColliders() {

}
