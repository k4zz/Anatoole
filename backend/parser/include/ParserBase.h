#pragma once

#include <string>
#include <vector>
#include <map>

class ParserBase
{
public:
    virtual void parse(std::string _path) = 0;
    const std::map<std::string, std::vector<std::string>>& getEntries() const { return entries; }
    void setSettings(int _keyColumn, int _valueColumn) { keyColumn = _keyColumn; valueColumn = _valueColumn; }

protected:
    ParserBase() = default;
    ParserBase(int _keyColumn, int _valueColumn) : keyColumn(_keyColumn), valueColumn(_valueColumn){}
    void clear() { entries.clear(); }

    std::map<std::string, std::vector<std::string>> entries{};
    bool withHeader{};
    int keyColumn{};
    int valueColumn{};
};