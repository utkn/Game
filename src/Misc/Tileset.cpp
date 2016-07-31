#include "Misc/Tileset.h"

Tileset::Tileset(Tmx::Tileset const* tileset, std::string const& filePath, RenderWindow& window)
        : source(tileset), tilewidth(tileset->GetTileWidth()), tileheight(tileset->GetTileHeight()),
          tilesPerRow(tileset->GetImage()->GetWidth()/tilewidth), texture(window, filePath) {
}

TextureRegion Tileset::getRegion(int id) {
    int x = id % tilesPerRow;
    int y = id / tilesPerRow;
    return TextureRegion(texture, x * tilewidth, y * tileheight, tilewidth, tileheight);
}