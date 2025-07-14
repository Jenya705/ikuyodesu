#ifndef LOGGER_H
#define LOGGER_H

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define PURPLE  "\033[35m"
#define RESET   "\033[0m"

#include <iostream>
#include <sstream>

class Logger {
    
    public:
    Logger();

    enum type {
        INFO, DEBUG, WARNING, ERROR, SUCCESS
    };

    template<typename... TArgs>
    static void print(type logType, const TArgs&... args){
        std::string prefix;
        std::ostringstream st;
        (st << ... << args);

        switch(logType){
            case INFO:
                prefix = std::string(BLUE) + "[INFO] " + RESET;
                break;
            case DEBUG:
                prefix = std::string(PURPLE) + "[DEBUG] " + RESET;
                break;
            case WARNING:
                prefix = std::string(YELLOW) + "[WARNING] " + RESET;
                break;
            case ERROR:
                prefix = std::string(RED) + "[ERROR] " + RESET;
                break;
            case SUCCESS:
                prefix = std::string(GREEN) + "[SUCCESS] " + RESET;
        }

        std::cout << prefix << st.str() << std::endl;
    }
};

#endif