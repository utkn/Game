#ifndef GAME_TEXTUREREGION_H
#define GAME_TEXTUREREGION_H

#include "SDL2/SDL.h"

class Texture;

class TextureRegion {
    Texture& textureRef_;
public:
    int x;
    int y;
    int width;
    int height;
    TextureRegion(Texture& texture, int x = 0, int y = 0,
                  int width = -1, int height = -1);

    SDL_Rect rect() const;
    Texture& texture() const;
};

#endif //GAME_TEXTUREREGION_H