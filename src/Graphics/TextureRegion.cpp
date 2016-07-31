#include "../../include/Graphics/TextureRegion.h"
#include "../../include/Graphics/Texture.h"

TextureRegion::TextureRegion(Texture &texture, int x, int y, int width, int height)
        : textureRef_(texture), x(x), y(y),
          width((width < 0) ? texture.width() : width),
          height((height < 0) ? texture.height() : height) {}

SDL_Rect TextureRegion::rect() const {
    return SDL_Rect{x, y, width, height};
}

Texture& TextureRegion::texture() const {
    return textureRef_;
}