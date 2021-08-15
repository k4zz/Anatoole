#pragma once

#include <iostream>

#include "Logger.h"

class ConsoleLogger : public ILoggerObserver
{
public:
    ConsoleLogger()
    {
        Logger::instance().subscribe(this);
    }
    ~ConsoleLogger() override
    {
        Logger::instance().unsubscribe(this);
    }
    void log(const std::string &_msg, LogLevel _level, const std::string &_fileName, int _line) override
    {
        std::cout << _fileName << ":" << _line << "\t" << toString(_level) << "\t" << _msg << "\n";
    }
};