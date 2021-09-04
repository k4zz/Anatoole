#include <algorithm>
#include "Analyzer.h"
#include "Logger.h"

Analyzer::Analyzer(const Entries& _protocolEntries, const Entries& _collationEntries)
{
    LOG_DEBUG("Analysis of protocol against collation");
    for(const auto& [num, names] : _protocolEntries)
    {
        for(const auto& name : names)
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

    LOG_DEBUG("Analysis of collation against protocol");
    for(auto [name, numbers] : _collationEntries)
    {
        for(const auto& num : numbers)
        {
            auto protocolEntry = _protocolEntries.find(num);
            if(protocolEntry == _protocolEntries.end())
            {
                problems.emplace_back(Problem{ProblemType::NonExistingPosition, num, name});
                continue;
            }

            auto temp = std::find(protocolEntry->second.begin(), protocolEntry->second.end(), name);
            if(temp == protocolEntry->second.end())
            {
                problems.emplace_back(Problem{ProblemType::RedundantPosition, num, name});
                continue;
            }
        }
    }
    LOG_DEBUG("End of analysis");
}

int Analyzer::problemsCount() const
{
    return problems.size();
}

const std::vector<Problem>& Analyzer::getProblems() const
{
    return problems;
}
