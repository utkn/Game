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

MapScene::MapScene(RenderWindow& window, std::string const& level) : window(window), renderSystem(window), factory(window) {
    std::string levelPath = "assets/maps/" + level + "/";
    map_.ParseFile(levelPath + "map.tmx");
    for(auto& tileSet : map_.GetTilesets()) {
        textureMap_[tileSet->GetName()].reset(new Tileset(tileSet, levelPath + tileSet->GetImage()->GetSource(), window));
        globalIDMap_[tileSet->GetFirstGid()] = tileSet->GetName();
    }
    populateTiles();
    populateObjects();
    entityManager_.attach(renderSystem);
}

bool MapScene::update(double dt) {
    entityManager_.update(dt);
    return true;
}

Tileset* MapScene::getTileset(int gid) {
    if(gid == 0) return nullptr;
    std::string last = "";
    for(auto& pair : globalIDMap_) {
        if(pair.first <= gid) last = pair.second;
        else break;
    }
    return textureMap_[last].get();
}

void MapScene::populateTiles() {
    for(auto& tileLayer : map_.GetTileLayers()) {
        processTileLayer(tileLayer);
    }
}

void MapScene::populateObjects() {
    for(auto& objGroup : map_.GetObjectGroups()) {
        if(objGroup->GetName() == "Collision") {
            processCollisionGroup(objGroup);
        } else if(objGroup->GetName() == "Spawn") {
            processSpawn(objGroup->GetObject(0));
        }
    }
}

void MapScene::processTileLayer(Tmx::TileLayer* tileLayer) {
    for(int y = 0; y < tileLayer->GetHeight(); y++) {
        for(int x = 0; x < tileLayer->GetWidth(); x++) {
            Tmx::MapTile const& tile = tileLayer->GetTile(x, y);
            Tileset* tileset = getTileset(tile.gid);
            if(tileset == nullptr) continue; // Empty tile
            TextureRegion region = tileset->getRegion(tile.id);
            ecs::EntityHandle entity = entityManager_.newEntity();
            entity.add<Renderable>(region);
            entity.add<Position>(x * region.width, y * region.width);
            entity.add<Scale>();
            entity.add<Rotation>();
            entity.add<Flip>();
            entity.add<Center>();
        }
    }
}

void MapScene::processCollisionGroup(Tmx::ObjectGroup *objectGroup) {
    for(auto& obj : objectGroup->GetObjects()) {
        Polygon shape;
        Tmx::Polygon const* poly = obj->GetPolygon();
        if(poly != nullptr) {
            for (int i = 0; i < poly->GetNumPoints(); i++) {
                Tmx::Point const &point = poly->GetPoint(i);
            }
        } else {
            int w = obj->GetWidth();
            int h = obj->GetHeight();
            shape.points.emplace_back(0, 0);
            shape.points.emplace_back(w, 0);
            shape.points.emplace_back(w, h);
            shape.points.emplace_back(0, h);
        }
        ecs::EntityHandle entity = entityManager_.newEntity();
        entity.add<Bounds>(shape);
        entity.add<Collideable>(true, true);
        entity.add<Position>(obj->GetX(), obj->GetY());
    }
}

void MapScene::processSpawn(Tmx::Object const* spawn) {
    ecs::EntityHandle handle = entityManager_.newEntity();
    factory.createPlayer(handle, 0, 0);
}