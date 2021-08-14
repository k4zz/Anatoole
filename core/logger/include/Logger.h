#pragma once

#include <string>
#include <list>
#include <cstring>

enum class LogLevel
{
    NONE,
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

inline std::string toString(LogLevel _level)
{
    switch (_level)
    {
        case LogLevel::NONE:        return "NONE";
        case LogLevel::DEBUG:       return "DEBUG";
        case LogLevel::INFO:        return "INFO";
        case LogLevel::WARNING:     return "WARNING";
        case LogLevel::ERROR:       return "ERROR";
        default:                    break;
    }
    return "INVALID";
}

class ILoggerObserver
{
public:
    virtual ~ILoggerObserver() = default;
    virtual void log(const std::string& _msg, LogLevel _level, const std::string& _fileName, int _line) = 0;
};

class Logger
{
public:
    static Logger& instance();
    Logger(Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    void subscribe(ILoggerObserver* _observer);
    void unsubscribe(ILoggerObserver* _observer);
    void log(const std::string& _msg, LogLevel _level, const std::string& _fileName, int _line);

private:
    Logger() = default;
    void notifySubscribers(const std::string& _msg, LogLevel _level, const std::string& _fileName, int _line);
    std::list<ILoggerObserver*> subscribers;
};

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define LOG(_level, _msg) Logger::instance().log(_msg, _level, __FILENAME__, __LINE__)
#define LOG_DEBUG(_msg) LOG(LogLevel::DEBUG, _msg)
#define LOG_INFO(_msg) LOG(LogLevel::INFO, _msg)
#define LOG_WARNING(_msg) LOG(LogLevel::WARNING, _msg)
#define LOG_ERROR(_msg) LOG(LogLevel::ERROR, _msg)
