#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>

class Ikuyodesu {
    
    public:
    Ikuyodesu();

    void init(const char *title, int width, int height, bool fullscreen);

    void update();
    void render();
    void eventHandler();
    void exit();

    const bool isRunning();
    void setRunning(bool b);

    private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    bool r;
};

#endif