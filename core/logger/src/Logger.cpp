#include "Logger.h"

#include <iostream>

Logger& Logger::instance()
{
    static Logger instance;
    return instance;
}

void Logger::log(const std::string& _msg, LogLevel _level, const std::string& _fileName, int _line)
{
    std::cout << _fileName << ":" << _line << "\t" << toString(_level) << "\t" << _msg << "\n";
    notifySubscribers(_msg, _level, _fileName, _line);
}

void Logger::subscribe(ILoggerObserver* _observer)
{
    subscribers.emplace_back(_observer);
}

void Logger::unsubscribe(ILoggerObserver* _observer)
{
    subscribers.remove(_observer);
}

void Logger::notifySubscribers(const std::string& _msg, LogLevel _level, const std::string& _fileName, int _line)
{
    for(auto subscriber : subscribers)
    {
        subscriber->log(_msg, _level, _fileName, _line);
    }
}
