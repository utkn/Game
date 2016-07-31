#ifndef GAME_TEXTURE_H
#define GAME_TEXTURE_H

#include <string>

class RenderWindow;
struct SDL_Texture;

class Texture {
    SDL_Texture* texture_ = nullptr;
    int width_ = 0;
    int height_ = 0;
public:
    Texture(RenderWindow& renderer, std::string const& path);

    SDL_Texture* source() const;
    int width() const;
    int height() const;

    ~Texture();
};

#endif //GAME_TEXTURE_H
