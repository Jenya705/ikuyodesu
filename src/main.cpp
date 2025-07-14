#include <cstdint>

#include "SDL3/SDL.h"
#include "utils/config.h"
#include <iostream>

#include "alg/vec.hpp"
#include "tilemap.hpp"

int main() {
    Config config;
    
    config.init();
    
    Logger::print(Logger::DEBUG, "ikuyodesu version: ", config.get<std::string>("info", "version"));
    std::cout << "konichiwa, world!" << std::endl;
    TilemapLayer<int> layer;
    layer.for_each([](auto _1, auto _2) {});
    
}
