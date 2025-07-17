#ifndef ENTITY_H
#define ENTITY_H

#include "holder.h"
#include "../alg/vec.hpp"
#include <SDL3/SDL.h>
#include "../scene/base.hpp"

class Entity: public Base {

    public:
    Entity();

    void create(const Vec2<float>& pos, int w, int h, const char *pathToTexture, const char *n, bool visible, bool collisible, Holder::relationship r);
    void update() override;
    void render(float angle) override;
    void kill();

    const char *getName() const;
    const int getId() const;
    const bool getVisible() const;
    const bool getCollisible() const;
    const Holder::relationship getRel() const;

    void setName(const char *n);
    void setVisible(bool b);
    void setCollisible(bool b);
    void setRel(Holder::relationship r);

    Vec2<float> position;
    Vec2<float> velocity;

    SDL_FRect srcRect, destRect;

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
