#include <cstdint>

#include "SDL3/SDL.h"
#include "ikuyodesu.h"
#include "utils/config.h"
#include <iostream>

#include "alg/vec.hpp"
#include "tilemap.hpp"

int main() {
    Config config;
    Ikuyodesu ikuyodesu;
    
    Logger::print(Logger::DEBUG, "ikuyodesu version: ", config.get<std::string>("info", "version"));
    config.init();

    int width = config.get<int>("info", "width");
    int height = config.get<int>("info", "height");

    ikuyodesu.init("Ikuyodesu", width, height, false);
    while(ikuyodesu.isRunning()){
        ikuyodesu.eventHandler();
        ikuyodesu.update();
        ikuyodesu.render();
    }
    
    std::cout << "konichiwa, world!" << std::endl;
    TilemapLayer<int> layer;
    layer.for_each([](auto _1, auto _2) {});
    
}
