#ifndef HOLDER_H
#define HOLDER_H

#include "entity.h"
#include <set>

class Holder {
    public:
    enum relationship {
        FRIEND,
        ENEMY,
        NEUTRAL
    };

    void init(SDL_Renderer *renderer);
    SDL_Renderer *getRenderer();

    std::set<Entity*> keeper;

    private:
    SDL_Renderer *rend;
};

extern Holder holder;

#endif