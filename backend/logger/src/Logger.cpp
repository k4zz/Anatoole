#include "Logger.h"

#include <iostream>

Logger& Logger::instance()
{
    static Logger instance;
    return instance;
}

void Logger::log(const std::string& _msg, LogLevel _level)
{
    std::cout << toString(_level) << "\t" << _msg << "\n";
    notifySubscribers(_msg, _level);
}

void Logger::subscribe(ILoggerObserver* _observer)
{
    subscribers.emplace_back(_observer);
}

void Logger::unsubscribe(ILoggerObserver* _observer)
{
    subscribers.remove(_observer);
}

void Logger::notifySubscribers(const std::string& _msg, LogLevel _level)
{
    for(auto subscriber : subscribers)
    {
        subscriber->log(_msg, _level);
    }
}
