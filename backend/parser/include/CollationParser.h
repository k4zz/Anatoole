#pragma once

#include "Logger.h"

#include "ParserBase.h"

class CollationParser : public ParserBase
{
public:
    CollationParser() : ParserBase(1,2) {}
    void parse(std::string _path) override;
};