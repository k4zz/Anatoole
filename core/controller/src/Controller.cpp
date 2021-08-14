#include "Controller.h"

#include <memory>
#include <utility>

#include "ProtocolParser.h"
#include "CollationParser.h"
#include "Analyzer.h"

Controller& Controller::instance()
{
    static Controller instance;
    return instance;
}

void Controller::execute()
{
    if (not isParsersCreated())
        return;

    if (not parseFiles())
        return;

    Analyzer analyzer(mProtocolParser->getEntries(), mCollationParser->getEntries());
    //TODO: call of analysis
}

void Controller::setPaths(std::string _protocolPath, std::string _collationPath)
{
    mProtocolPath = std::move(_protocolPath);
    mCollationPath = std::move(_collationPath);
}

void Controller::setParsingType()
{
    mProtocolParser = std::make_unique<ProtocolParser>();
    mCollationParser = std::make_unique<CollationParser>();
}

void Controller::setSettings()
{

}

bool Controller::isParsersCreated()
{
    bool valid = true;
    if (not mProtocolParser) {
        LOG_ERROR("Protocol parser not created");
        valid = false;
    }
    if (not mCollationParser) {
        LOG_ERROR("Collation parser not created");
        valid = false;
    }
    return valid;
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
