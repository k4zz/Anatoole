#pragma once

#include <string>
#include <map>
#include <vector>
#include "Logger.h"

class Parser
{
public:
    Parser(std::string _path);

private:
    std::string path{};
    std::map<std::string, std::vector<std::string>> protocolEntries;
    bool withHeader;
};