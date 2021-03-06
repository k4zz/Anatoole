#pragma once

#include <string>
#include <vector>
#include <map>

#include "ParserBase.h"

class CSVParser : public ParserBase
{
protected:
    CSVParser() = default;
    CSVParser(int _keyColumn, int _valueColumn) : mKeyColumn(_keyColumn), mValueColumn(_valueColumn){}

public:
    void setSettings(int _keyColumn, int _valueColumn) override { mKeyColumn = _keyColumn; mValueColumn = _valueColumn; }

protected:
    bool mWithHeader{};
    int mKeyColumn{};
    int mValueColumn{};
};




