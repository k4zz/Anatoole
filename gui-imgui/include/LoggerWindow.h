#pragma once

#include <vector>

#include "imgui.h"

#include "Logger.h"

class LoggerWindow : private ILoggerObserver
{
public:
    LoggerWindow() {init();}

    void init();
    void show();

private:
    struct LogData
    {
        std::string msg;
        std::string level;
        std::string fileName;
        std::string line;
    };

    void log(const std::string& _msg, LogLevel _level, const std::string& _fileName, int _line) override;
    std::vector<LogData> logPool;
};



