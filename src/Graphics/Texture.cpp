#include "../../include/Graphics/Texture.h"

#include "../../include/Graphics/RenderWindow.h"
#include "SDL2_image/SDL_image.h"
#include <iostream>

Texture::Texture(RenderWindow& renderer, std::string const& path) {
    texture_ = IMG_LoadTexture(renderer.rndSource(), path.c_str());
    if(texture_ == nullptr) {
        std::cerr << "Error loading texture: " << SDL_GetError() << "\n";
        exit(1);
    }
    SDL_QueryTexture(texture_, nullptr, nullptr, &width_, &height_);
}

SDL_Texture* Texture::source() const {
    return texture_;
}

int Texture::width() const {
    return width_;
}

int Texture::height() const {
    return height_;
}

Texture::~Texture() {
    SDL_DestroyTexture(texture_);
}