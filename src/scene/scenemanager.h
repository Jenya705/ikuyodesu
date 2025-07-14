#ifndef SCENE_H
#define SCENE_H

#include "../tilemap.hpp"
#include <list>
#include <set>

struct Scene {
    const char *name;
    int id;
    std::list<TilemapLayer<int>> layers;
};

class SceneManager {

    public:
    SceneManager();

    void init();
    void ikuyo();

    void setActive(Scene *scene);
    Scene *getActive();

    const Scene& findById(int id);

    Scene test;

    private:
    std::set<Scene> scenesHolder;
    Scene *activeScene = nullptr;
};

extern SceneManager sceneManager;

#endif