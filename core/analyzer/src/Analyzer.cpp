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
                LOG_WARNING("Missing name " + name + " in collation");
                continue;
            }

            auto temp = std::find(collationEntry->second.begin(), collationEntry->second.end(), num);
            if(temp == collationEntry->second.end())
            {
                LOG_WARNING("Missing position " + num + " from protocol for name " + name + " in collation");
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
                LOG_WARNING("Non-existing position " + num + " of protocol in collation");
                continue;
            }

            auto temp = std::find(protocolEntry->second.begin(), protocolEntry->second.end(), name);
            if(temp == protocolEntry->second.end())
            {
                LOG_WARNING("Name " + name + " is not existing in protocol for position " + num + " in collation");
            }

        }
    }
}
