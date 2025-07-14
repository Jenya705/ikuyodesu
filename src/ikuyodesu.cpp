#include "ikuyodesu.h"
#include "entity/holder.h"
#include "scene/scenemanager.h"
#include "utils/logger.h"
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

Ikuyodesu::Ikuyodesu(){

}

void Ikuyodesu::init(const char *title, int width, int height, bool fullscreen){
    int flags = 0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        title,
        width,
        height,
        flags
    );

    renderer = SDL_CreateRenderer(window, NULL);
    if(renderer){
        r = true;
    } else {
        r = false;
    }

    holder.init(renderer);
    sceneManager.init();
    sceneManager.setActive(&sceneManager.test);
}

void Ikuyodesu::update(){
    // _input/update shit
}

void Ikuyodesu::render(){
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void Ikuyodesu::eventHandler(){
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_EVENT_QUIT:
                r = false;
                break;
            default:
                break;
        }
    }
}

void Ikuyodesu::exit(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

const bool Ikuyodesu::isRunning(){
    return r;
}

void Ikuyodesu::setRunning(bool b){
    r = b;
}