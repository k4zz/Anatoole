#pragma once

#include "CSVParser.h"

class ProtocolParser : public CSVParser
{
public:
    ProtocolParser() : CSVParser(0,2) {}
    void parse(std::string _path) override;
};