#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include <SDL3/SDL.h>

class Player {

    public:
    Player();

    void init(SDL_Renderer* r);
    void ikuyo();
    void update();
    void handleInput();

    private:
    Entity p;

    SDL_Renderer* renderer;
};

#endif