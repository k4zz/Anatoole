#include <algorithm>
#include "Analyzer.h"

#include "Logger.h"

Analyzer::Analyzer(const Entries& _protocolEntries, const Entries& _collationEntries)
{
    for(auto [num, names] : _protocolEntries)
    {
        for(auto name : names)
        {
            auto collationEntry = _collationEntries.find(name);
            if(collationEntry == _collationEntries.end())
            {
                problems.emplace_back(Problem{ProblemType::MissingName, num, name});
                continue;
            }

            auto temp = std::find(collationEntry->second.begin(), collationEntry->second.end(), num);
            if(temp == collationEntry->second.end())
            {
                problems.emplace_back(Problem{ProblemType::MissingPosition, num, name});
                continue;
            }
        }
    }

    for(auto [name, numbers] : _collationEntries)
    {
        for(auto num : numbers)
        {
            auto protocolEntry = _protocolEntries.find(num);
            if(protocolEntry == _protocolEntries.end())
            {
                problems.emplace_back(Problem{ProblemType::RedundantPosition, num, name});
                continue;
            }

            auto temp = std::find(protocolEntry->second.begin(), protocolEntry->second.end(), name);
            if(temp == protocolEntry->second.end())
            {
                problems.emplace_back(Problem{ProblemType::RedundantName, num, name});
                continue;
            }
        }
    }
}

int Analyzer::problemCount() const
{
    return problems.size();
}

const std::vector<Problem>& Analyzer::getProblems() const
{
    return problems;
}
