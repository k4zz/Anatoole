#pragma once

#include <memory>
#include "ParserBase.h"
#include "Analyzer.h"

class Controller;
class UIInterface
{
public:
    UIInterface() = default;
    UIInterface(std::shared_ptr<Controller> _controller)
        : mController(_controller)
        {}

protected:
    std::shared_ptr<Controller> mController;
};

class Controller
{
public:
    Controller() = default;
    Controller(Controller&) = delete;
    Controller& operator=(const Controller&) = delete;

    void execute();
    bool setSettings(int _protocolKeyColumn, int _protocolValueColumn, int _collationKeyColumn, int _collationValueColumn);
    void setPaths(std::string _protocolPath, std::string _collationPath);

private:
    bool createParsers();
    bool parseFiles();
    void handleProblems();
    void resetComponents();
    bool validatePaths();

private:
    std::string mProtocolPath;
    std::string mCollationPath;
    std::unique_ptr<ParserBase> mProtocolParser;
    std::unique_ptr<ParserBase> mCollationParser;

    std::unique_ptr<Analyzer> mAnalyzer;
};