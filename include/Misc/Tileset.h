#ifndef GAME_TILESET_H
#define GAME_TILESET_H

#include <Graphics/TextureRegion.h>
#include <Graphics/RenderWindow.h>
#include <Graphics/Texture.h>
#include <tmxparser/Tmx.h>

struct Tileset {
    int tilewidth;
    int tileheight;
    int tilesPerRow;
    Tmx::Tileset const* source;
    Texture texture;

    explicit Tileset(Tmx::Tileset const* tileset, std::string const& filePath, RenderWindow& window);
    TextureRegion getRegion(int id);
};

#endif //GAME_TILESET_H
