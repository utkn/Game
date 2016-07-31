#ifndef GAME_RENDERWINDOW_H
#define GAME_RENDERWINDOW_H

#include "SDL2/SDL.h"
#include <string>

class TextureRegion;

class RenderWindow {
    SDL_Window* window_ = nullptr;
    SDL_Renderer* renderer_ = nullptr;
public:
    RenderWindow(std::string const& title, int width, int height,
                 Uint32 winFlags = SDL_WINDOW_SHOWN,
                 Uint32 rndFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    void clear();
    void present();
    void draw(TextureRegion& region, int posX, int posY, float scaleX = 1.f, float scaleY = 1.f,
              int centerX = 0, int centerY = 0, float rotation = 0.f, SDL_RendererFlip flip = SDL_FLIP_NONE);

    SDL_Window* winSource() const;
    SDL_Renderer* rndSource() const;

    ~RenderWindow();
};

#endif //GAME_RENDERWINDOW_H
