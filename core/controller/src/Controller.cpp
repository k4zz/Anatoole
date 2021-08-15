#include "Controller.h"

#include <memory>
#include <utility>

#include "ProtocolParser.h"
#include "CollationParser.h"
#include "Analyzer.h"
#include "Utils.h"

void Controller::execute()
{
    if (not isParsersCreated())
    {
        LOG_ERROR("Cannot execute parsing; parsers not created");
        return;
    }

    if (not parseFiles())
    {
        LOG_ERROR("Failed to parse one of the files");
        return;
    }

    Analyzer analyzer(mProtocolParser->getEntries(), mCollationParser->getEntries());
    //TODO: call of analysis
}

void Controller::setPaths(std::string _protocolPath, std::string _collationPath)
{
    mProtocolPath = std::move(_protocolPath);
    mCollationPath = std::move(_collationPath);

    createParsers();
}

void Controller::createParsers()
{
    if(mProtocolPath.empty())
    {
        LOG_DEBUG("Cannot create protocol parser, path is empty");
    }
    else if (Utils::ends_with(mProtocolPath, ".csv"))
    {
        mProtocolParser = std::make_unique<ProtocolParser>();
    }

    if(mCollationPath.empty())
    {
        LOG_DEBUG("Cannot create collation parser, path is empty");
    }
    else if (Utils::ends_with(mCollationPath, ".csv"))
    {
        mCollationParser = std::make_unique<CollationParser>();
    }
}

bool Controller::setSettings(int _protocolKeyColumn, int _protocolValueColumn, int _collationKeyColumn, int _collationValueColumn)
{
    if(not isParsersCreated())
    {
        LOG_ERROR("Cannot set settings; Parser/s not created");
        return false;
    }

    mProtocolParser->setSettings(_protocolKeyColumn, _protocolValueColumn);
    mCollationParser->setSettings(_collationKeyColumn, _collationValueColumn);
    return true;
}

bool Controller::isParsersCreated()
{
    return mProtocolParser && mCollationParser;
}

bool Controller::parseFiles()
{
    //TODO: should be done parallel
    auto isProtocolParsed = mProtocolParser->parse(mProtocolPath);
    if (not isProtocolParsed) {
        LOG_ERROR("Problem with parsing protocol");
    } else
        LOG_INFO("Protocol parsed correctly");

    auto isCollationParsed = mCollationParser->parse(mCollationPath);
    if (not isCollationParsed) {
        LOG_ERROR("Problem with parsing collation");
    } else
        LOG_INFO("Collation parsed correctly");

    return isProtocolParsed && isCollationParsed;
}
