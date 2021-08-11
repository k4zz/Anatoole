#pragma once

#include <string>
#include "Logger.h"

#include "ProtocolModel.h"

class Parser
{
public:
    Parser(std::string _path);

private:
    std::string path{};
    ProtocolModel protocolModel;
    bool withHeader;
};