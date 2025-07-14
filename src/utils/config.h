#ifndef CONFIG_H
#define CONFIG_H

#include "logger.h"
#include <string>
#include <fstream>
#include <sstream>

class Config {

    public:
    Config();
    void init();

    template<typename T>
    T get(const char *keyTitle, const char *keyMessage){
        std::ifstream config("resources/config.ini");
        std::string title = "[" + std::string(keyTitle) + "]";
        std::string message = std::string(keyMessage) + "=";
        std::string line;
        bool b = false;
        while(std::getline(config, line)){
            if(line[0] == '['){
                b = (line == title);
            } else if(b && line.rfind(message, 0) == 0){
                std::istringstream str (line.substr(message.length()));
                T res;
                str >> res;
                return res;
            }
        }
        Logger::print(Logger::ERROR, "Failed to find message from config file");
        return T{};
    }

    private:
    
};

#endif
