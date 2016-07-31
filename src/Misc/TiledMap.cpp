#include <Misc/Constants.h>
#include <fstream>
#include <pugixml.hpp>
#include <iostream>
#include "Misc/TiledMap.h"

TiledMap::TiledMap(std::string const &name, RenderWindow &window) {
    std::ifstream fs(Constants::MAPS_PATH + name + "/map.tmx");
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load(fs);
    fs.close();
    pugi::xml_node mapNode = doc.child("map");
    tileWidth = mapNode.attribute("tilewidth").as_int();
    tileHeight = mapNode.attribute("tileheight").as_int();
    cols = mapNode.attribute("width").as_int();

    for(auto& tilesetNode : mapNode.children("tileset")) {
        int firstGid = tilesetNode.attribute("firstgid").as_int();
        pugi::xml_node imageNode = tilesetNode.child("image");
        std::string imgPath = Constants::MAPS_PATH + name + "/";
        imgPath += imageNode.attribute("source").as_string();
        std::unique_ptr<Texture> tx(new Texture(window, imgPath));
        tilesets.emplace(firstGid, std::move(tx));
    }

    for(auto& layerNode : mapNode.children("layer")) {
        int i = -1;
        for(auto& tileNode : layerNode.child("data").children("tile")) {
            i++;
            int gid = tileNode.attribute("gid").as_int();
            if(gid == 0) continue;

            auto tileset = getTileset(gid);
            int tilesetCols = tileset.second->width() / tileWidth;
            int id = gid - tileset.first;
            int srcX = (id % tilesetCols) * tileWidth;
            int srcY = (id / tilesetCols) * tileHeight;
            int posX = (i % cols) * tileWidth;
            int posY = (i / cols) * tileHeight;
            TextureRegion region(*tileset.second, srcX, srcY, tileWidth, tileHeight);
            tiles.emplace_back(region, posX, posY);
        }
    }

    for(auto& objGroupNode : mapNode.children("objectgroup")) {
        if(std::string(objGroupNode.attribute("name").as_string()) == "Collision") {
            for(auto& colObjNode : objGroupNode.children("object")) {
                Polygon shape;
                int posX = colObjNode.attribute("x").as_int();
                int posY = colObjNode.attribute("y").as_int();
                if(colObjNode.empty()) {
                    // Parse rectangle.
                    int w = colObjNode.attribute("width").as_int();
                    int h = colObjNode.attribute("height").as_int();
                    shape.points.emplace_back(0, 0);
                    shape.points.emplace_back(w, 0);
                    shape.points.emplace_back(w, h);
                    shape.points.emplace_back(0, h);
                } else {
                    // Parse polygon.
                    std::string points = colObjNode.child("polygon").attribute("points").as_string();
                    unsigned long pos = 0;
                    int x = -1;
                    int y = -1;
                    while((pos = points.find(" ,")) != std::string::npos) {
                        std::string number = points.substr(0, pos);
                        if(x < 0 && y < 0) x = std::stoi(number);
                        else if(y < 0) y = std::stoi(number);
                        else {
                            shape.points.emplace_back(x, y);
                            x = -1;
                            y = -1;
                        }
                        points.erase(0, pos + 2);
                    }
                }
                colliders.emplace_back(shape, posX, posY);
            }
        } else if(std::string(objGroupNode.attribute("name").as_string()) == "Spawn") {
            pugi::xml_node spawnNode = objGroupNode.first_child();
            spawn.x = spawnNode.attribute("x").as_int();
            spawn.y = spawnNode.attribute("y").as_int();
        }
    }

}

std::pair<int, Texture*> TiledMap::getTileset(int gid) {
    int id = 0;
    Texture* tx = nullptr;
    for(auto& pair : tilesets) {
        if(gid >= pair.first) {
            id = pair.first;
            tx = pair.second.get();
        } else break;
    }
    if(tx == nullptr) {
        std::cerr << "Error parsing map.";
        exit(1);
    }
    auto pair = std::make_pair(id, tx);
    return pair;
}