#include "Scenes/SceneManager.h"

void SceneManager::update(double dt) {
    for(auto& scene : scenes) {
        if(!scene->update(dt)) break;
    }
}

void SceneManager::put(Scene& scene) {
    scene.sceneManagerRef = this;
    scenes.push_front(&scene);
}

void SceneManager::remove(Scene &scene) {
    scene.sceneManagerRef = nullptr;
    scenes.erase(std::find(scenes.begin(), scenes.end(), &scene));
}

void SceneManager::pop() {
    scenes.pop_front();
}
