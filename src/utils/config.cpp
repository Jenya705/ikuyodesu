#include <iostream>
#include <fstream>
#include "config.h"

Config::Config(){

}

void Config::init(){
    std::string line;
    std::ifstream file("resources/config.ini");
    if(file.is_open()){
        Logger::print(Logger::ERROR, "Config file already exist");
    } else {
        std::ofstream config("resources/config.ini");
        config << "[info]\n";
        config << "name=\n";
        config << "version=\n";
        config << "width=\n";
        config << "height=\n";
        Logger::print(Logger::INFO, "Config file created");
    }
}