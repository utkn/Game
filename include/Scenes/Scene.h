#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <ECS/Manager.h>

class SceneManager;

class Scene {
protected:
    ecs::Manager entityManager_;
    SceneManager* sceneManagerRef = nullptr;
    friend class SceneManager;
public:
    virtual bool update(double dt) = 0;
};

#endif //GAME_SCENE_H
