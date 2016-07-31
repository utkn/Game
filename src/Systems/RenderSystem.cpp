#include <Components/Center.h>
#include "Systems/RenderSystem.h"

void RenderSystem::update(double dt) {
    window.clear();
    for(auto& entity : entities_) {
        Position& pos = entity.get<Position>();
        Rotation& rot = entity.get<Rotation>();
        Scale& scale = entity.get<Scale>();
        SDL_RendererFlip flip = (entity.get<Flip>().x) ? SDL_FLIP_HORIZONTAL
                                                       : (entity.get<Flip>().y) ? SDL_FLIP_VERTICAL
                                                                                : SDL_FLIP_NONE ;
        Center center = entity.get<Center>();
        window.draw(entity.get<Renderable>().region, (int) pos.x, (int) pos.y,
                    (float) scale.x, (float) scale.y, center.x, center.y, (float) rot.angle, flip);
    }
    window.present();
}