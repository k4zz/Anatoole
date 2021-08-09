#pragma once

#include "Logger.h"

#include "ParserBase.h"
#include "BaseComponent.h"

class ProtocolParser : public ParserBase, public BaseComponent
{
public:
    void parse() override;
};