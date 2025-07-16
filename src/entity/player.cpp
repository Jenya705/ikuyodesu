#include "player.h"
#include "../alg/vec.hpp"
#include "../utils/config.h"
#include <iostream>
#include <SDL3/SDL.h>

Player::Player(){

}

void Player::init(SDL_Renderer* r){
    renderer = r;
    p.create(Vec2<float>(0, 0), 32, 32, "assets/playertest.png", "Player", true, true, Holder::relationship::PLAYER);
}

void Player::ikuyo(){
    p.render();
}

void Player::update(){
    p.update();
}

void Player::handleInput(){
    float speed = Config::get<float>("info", "player-speed");
    const bool *keys = SDL_GetKeyboardState(NULL);
    p.velocity = {0, 0};
    if(keys[SDL_SCANCODE_W]){
        p.velocity.y -= speed;
    }

    if(keys[SDL_SCANCODE_A]){
        p.velocity.x -= speed;
    }
    if(keys[SDL_SCANCODE_S]){
        p.velocity.y += speed;
    }
    if(keys[SDL_SCANCODE_D]){
        p.velocity.x += speed;
    }
}