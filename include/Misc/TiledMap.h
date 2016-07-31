#ifndef GAME_TILEDMAP_H
#define GAME_TILEDMAP_H

#include <string>
#include <Graphics/RenderWindow.h>
#include <Graphics/Texture.h>
#include <Graphics/TextureRegion.h>
#include <vector>
#include <map>
#include <Math/Polygon.h>

struct Tile {
    TextureRegion src;
    int x;
    int y;
    Tile(TextureRegion src, int x, int y) : src(src), x(x), y(y) {}
};

struct Collider {
    Polygon shape;
    int x;
    int y;
    Collider(Polygon shape, int x, int y) : shape(shape), x(x), y(y) {}
};

class TiledMap {
    std::map<int, std::unique_ptr<Texture>> tilesets;
public:
    std::vector<Tile> tiles;
    std::vector<Collider> colliders;
    Point spawn;
    int tileWidth;
    int tileHeight;
    int cols;

    TiledMap(std::string const& name, RenderWindow& window);
private:
    std::pair<int, Texture*> getTileset(int gid);
};

#endif //GAME_TILEDMAP_H
