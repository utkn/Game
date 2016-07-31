#ifndef GAME_SCENEMANAGER_H
#define GAME_SCENEMANAGER_H

#include <deque>
#include "Scene.h"

class SceneManager {
    std::deque<Scene*> scenes;
public:
    void update(double dt);
    void put(Scene& scene);
    void pop();
    void remove(Scene& scene);
};

#endif //GAME_SCENEMANAGER_H