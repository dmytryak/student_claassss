#pragma once
#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>

class Logger {
private:
    std::ofstream logfile;

public:
    Logger(const std::string& filename);
    void log(const std::string& message);
    ~Logger();
};
#endif