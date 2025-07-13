#include "SDL3/SDL.h"
#include "utils/config.h"
#include <iostream>

int main() {
    Config config;

    config.init();
    
    Logger::print(Logger::DEBUG, "ikuyodesu version: ", config.get<std::string>("info", "version"));
    std::cout << "konichiwa, world!" << std::endl;
    
}