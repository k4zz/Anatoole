#pragma once

#include <memory>
#include "ParserBase.h"

class Controller
{
public:
    static Controller& instance();
    Controller(Controller&) = delete;
    Controller& operator=(const Controller&) = delete;

    void execute();
    void setSettings();
    void setPaths(std::string _protocolPath, std::string _collationPath);
    void setParsingType();

private:
    bool isParsersCreated();
    bool parseFiles();

private:
    Controller() = default;
    std::string mProtocolPath;
    std::string mCollationPath;
    std::unique_ptr<ParserBase> mProtocolParser;
    std::unique_ptr<ParserBase> mCollationParser;
};