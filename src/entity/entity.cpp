#include "holder.h"
#include "entity.h"
#include "../utils/logger.h"
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

Holder holder;

Entity::Entity()
    : position(0, 0), velocity(0, 0)
{

}

void Entity::create(const Vec2<float>& pos, int w, int h, const char *pathToTexture, const char *n, bool visible, bool collisible, Holder::relationship r){
    position = pos;
    width = w;
    height = h;
    file = pathToTexture;
    name = n;
    isVisible = visible;
    isCollisible = collisible;
    rel = r;

    id = getUniqueId();
    holder.keeper.insert(this);

    destRect.w = width;
    destRect.h = height;

    setTexture();
}

void Entity::update() {
    // _update logic?
    position = position + velocity;
}

void Entity::render(float angle){
    // _render logic?
    destRect = {
        position.x,
        position.y,
        static_cast<float>(width),
        static_cast<float>(height)
    };

    SDL_RenderTextureRotated(holder.getRenderer(), texture, NULL, &destRect, angle, NULL, SDL_FLIP_NONE);
}

void Entity::kill(){
    SDL_DestroyTexture(texture);
    holder.keeper.erase(this);
}

const char *Entity::getName() const {
    return name;
}

const int Entity::getId() const {
    return id;
}

const bool Entity::getVisible() const {
    return isVisible;
}

const bool Entity::getCollisible() const {
    return isCollisible;
}

const Holder::relationship Entity::getRel() const {
    return rel;
}

void Entity::setName(const char *n){
    name = n;
}

void Entity::setVisible(bool b){
    isVisible = b;
}

void Entity::setCollisible(bool b){
    isCollisible = b;
}

const int Entity::getUniqueId(){
    int unique = 0;
    if(holder.keeper.empty()){
        return 1;
    }
    for(Entity *e : holder.keeper){
        if(e->getId() > unique){
            unique = e->getId();
        }
    }
    return unique + 1;
}

void Entity::setTexture(){
    if(texture != nullptr){
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
    SDL_Surface *surface = IMG_Load(file);
    if(!surface){
        Logger::print(Logger::ERROR, "Failed to load entity surface: ", SDL_GetError());
        exit(-1);
    }

    texture = SDL_CreateTextureFromSurface(holder.getRenderer(), surface);
    if(!texture){
        Logger::print(Logger::ERROR, "Failed to load entity texture: ", SDL_GetError());
        exit(-1);    
    }
    SDL_DestroySurface(surface);
}

void Holder::init(SDL_Renderer *renderer){
    holder.rend = renderer;
    Logger::print(Logger::SUCCESS, "Entity holder successfully initialized");
}

SDL_Renderer *Holder::getRenderer(){
    return holder.rend;
}
