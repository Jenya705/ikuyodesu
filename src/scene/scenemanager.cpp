#include "scenemanager.h"
#include "../utils/logger.h"
#include <iostream>
 
SceneManager sceneManager;

SceneManager::SceneManager(){

}

void SceneManager::init(){
    //_scenes initialization_

    //test scene
    test.name = "test";
    test.id = 0;
    //
    Logger::print(Logger::SUCCESS, "Scene manager successfully initialized");
}

void SceneManager::ikuyo(){
    for (auto& obj: activeScene->objects) {
        obj->render();
    }
}

void SceneManager::setActive(Scene *scene){
    activeScene = scene;
    Logger::print(Logger::INFO, "New scene is ", activeScene->name, activeScene->id);
}

Scene *SceneManager::getActive(){
    Logger::print(Logger::INFO, "Active scene is ", activeScene->name, activeScene->id);
    return activeScene;
}

const Scene& SceneManager::findById(int id){
    for(const auto& scene : scenesHolder){
        if(scene.id == id){
            return scene;
        }
    }
    Logger::print(Logger::ERROR, "Failed to find scene by id: ", id);
}
