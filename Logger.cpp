#include "Logger.h"
#include <iostream>

Logger::Logger(const std::string& filename) 
{
    logfile.open(filename, std::ios::out | std::ios::app);
    if (!logfile.is_open()) {
        std::cout << "Could not open the log file: " << filename;
    }
}


void Logger::log(const std::string& message) 
{
    if (logfile.is_open()) {
        logfile << message << std::endl;
    }
}

Logger::~Logger() 
{
    if (logfile.is_open()) {
        logfile.close();
    }
}