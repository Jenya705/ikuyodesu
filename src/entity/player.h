#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "../alg/vec.hpp"
#include <SDL3/SDL.h>

class Player {

    public:
    Player();

    void init(SDL_Renderer* r);
    void ikuyo();
    void update();
    void handleInput();

    private:
    void updateMousePos();

    Entity p;

    SDL_Renderer* renderer;
    float mouseX, mouseY, angle;
};

#endif