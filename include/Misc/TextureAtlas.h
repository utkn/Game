#ifndef GAME_TEXTUREATLAS_H
#define GAME_TEXTUREATLAS_H

#include <unordered_map>
#include "Graphics/Texture.h"
#include "Graphics/TextureRegion.h"

class TextureAtlas {
    std::unique_ptr<Texture> texture_;
    std::unordered_map<std::string, TextureRegion> regions_;
    std::string defaultRegion_;
public:
    TextureAtlas(std::string const& path, RenderWindow& window);
    TextureRegion& getRegion(std::string const& name);
    TextureRegion& getDefault();
};

#endif //GAME_TEXTUREATLAS_H
