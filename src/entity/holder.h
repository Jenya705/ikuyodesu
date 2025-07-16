#ifndef HOLDER_H
#define HOLDER_H

#include <SDL3/SDL.h>
#include <set>

class Entity;

class Holder {
    public:
    enum class relationship {
        FRIEND,
        ENEMY,
        NEUTRAL,
        PLAYER
    };

    void init(SDL_Renderer *renderer);
    SDL_Renderer *getRenderer();

    std::set<Entity*> keeper;

    private:
    SDL_Renderer *rend;
};

extern Holder holder;

#endif