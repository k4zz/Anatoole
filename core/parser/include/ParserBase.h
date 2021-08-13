#pragma once

using Entries = std::map<std::string, std::vector<std::string>>;

class ParserBase
{
public:
    virtual void parse(std::string _path) = 0;
    virtual const Entries& getEntries() { return entries; }

protected:
    Entries entries{};
};