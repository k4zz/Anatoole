#pragma once

#include <map>
#include <vector>

using Entries = std::map<std::string, std::vector<std::string>>;

class Analyzer
{
public:
    explicit Analyzer(const Entries& _protocolEntries, const Entries& _collationEntries);
};