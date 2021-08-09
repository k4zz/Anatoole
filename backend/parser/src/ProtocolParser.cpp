#include "ProtocolParser.h"

void ProtocolParser::parse()
{
    if(filePath.empty())
    {
        LOG_WARNING("No protocol file to be parsed");
        return;
    }
    LOG_WARNING(filePath);
}
