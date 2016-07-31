#include <SDL2/SDL_system.h>
#include <ECS/EntityHandle.h>
#include "Systems/InputSystem.h"

void InputSystem::update(double dt) {
    Uint8 const* state = SDL_GetKeyboardState(nullptr);
    for(auto& entity : entities_) {
        Control& control = entity.get<Control>();
        control.right = state[SDL_SCANCODE_RIGHT];
        control.left = state[SDL_SCANCODE_LEFT];
        control.attack = state[SDL_SCANCODE_SPACE];
        control.activate = state[SDL_SCANCODE_E];
        control.jump = state[SDL_SCANCODE_UP];
    }
}
