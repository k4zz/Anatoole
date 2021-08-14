#pragma once

#include "Logger.h"

#include "CSVParser.h"

class ProtocolParser : public CSVParser
{
public:
    ProtocolParser() : CSVParser(0,2) {}
    bool parse(std::string _path) override;
};