#include "../../include/Graphics/RenderWindow.h"
#include "../../include/Graphics/Texture.h"
#include "../../include/Graphics/TextureRegion.h"
#include <iostream>

RenderWindow::RenderWindow(const std::string &title, int width, int height, Uint32 winFlags, Uint32 rndFlags) {
    window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, winFlags);
    if(window_ == nullptr) {
        std::cerr << "Error while creating window: " << SDL_GetError() << "\n";
        exit(1);
    }
    renderer_ = SDL_CreateRenderer(window_, 0, rndFlags);
    if(window_ == nullptr) {
        std::cerr << "Error while creating renderer: " << SDL_GetError() << "\n";
        exit(1);
    }
}

void RenderWindow::clear() {
    SDL_RenderClear(renderer_);
}

void RenderWindow::present() {
    SDL_RenderPresent(renderer_);
}

void RenderWindow::draw(TextureRegion& region, int posX, int posY, float scaleX, float scaleY, int centerX, int centerY, float rotation, SDL_RendererFlip flip)
{
    SDL_Rect src = region.rect();
    SDL_Point center = {centerX, centerY};
    SDL_Rect dst = {posX, posY, (int) (src.w * scaleX + 0.5), (int) (src.h * scaleY + 0.5)};
    SDL_RenderCopyEx(renderer_, region.texture().source(), &src, &dst, rotation, &center, flip);
}

SDL_Window* RenderWindow::winSource() const {
    return window_;
}

SDL_Renderer* RenderWindow::rndSource() const {
    return renderer_;
}

RenderWindow::~RenderWindow() {
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
}

