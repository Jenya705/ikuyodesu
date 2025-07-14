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
    

    config.init();
    ikuyodesu.init("Ikuyodesu", config.get<int>("game_info", "width"), config.get<int>("game_info", "height"), false);
    Logger::print(Logger::DEBUG, "ikuyodesu version: ", config.get<std::string>("info", "version"));
    std::cout << "konichiwa, world!" << std::endl;
    TilemapLayer<int> layer;
    layer.for_each([](auto _1, auto _2) {});
    
}
