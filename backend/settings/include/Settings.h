#pragma once

#include <string>

class Settings
{
public:
    std::string protocolPath{};
    std::string collationPath{};
    std::string protocolNameColumn{};
    std::string protocolNumColumn{};
    std::string collationNameColumn{};
    std::string collationNumColumn{};
};