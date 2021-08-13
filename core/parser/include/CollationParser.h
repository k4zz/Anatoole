#pragma once

#include "Logger.h"

#include "CSVParser.h"

class CollationParser : public CSVParser
{
public:
    CollationParser() : CSVParser(1,2) {}
    void parse(std::string _path) override;
};