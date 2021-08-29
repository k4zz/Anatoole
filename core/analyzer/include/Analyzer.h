#pragma once

#include <map>
#include <vector>

#include "Problem.h"

using Entries = std::map<std::string, std::vector<std::string>>;

class Analyzer
{
public:
    explicit Analyzer(const Entries& _protocolEntries, const Entries& _collationEntries);

    int problemsCount() const;
    const std::vector<Problem>& getProblems() const;

private:
    std::vector<Problem> problems;
};