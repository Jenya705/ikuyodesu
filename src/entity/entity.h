#ifndef ENTITY_H
#define ENTITY_H

#include "holder.h"
#include "../alg/vec.hpp"
#include <SDL3/SDL.h>

class Entity {

    public:
    Entity(const Vec2<float>& pos, int w, int h, const char *pathToTexture, const char *name, bool visible, bool collisible, Holder::relationship r);

    void update();
    void render();
    void kill();

    const char *getName();
    const int getId();
    const bool getVisible();
    const bool getCollisible();
    const Holder::relationship getRel();

    void setName(const char *n);
    void setVisible(bool b);
    void setCollisible(bool b);
    void setRel(Holder::relationship r);

    Vec2<float> position;
    Vec2<float> velocity;

    SDL_Rect srcRect, destRect; 

    private:
    SDL_Texture *texture;

    const char *file;
    const char *name;
    int width;
    int height;
    int id;
    bool isVisible;
    bool isCollisible;
    Holder::relationship rel;

    const int getUniqueId();
    void setTexture();
};

#endif