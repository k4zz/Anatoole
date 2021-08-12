#pragma once

#include "Logger.h"

#include "ParserBase.h"

class ProtocolParser : public ParserBase
{
public:
    ProtocolParser() : ParserBase(0,2) {}
    void parse(std::string _path) override;
};