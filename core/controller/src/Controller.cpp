#include "Controller.h"

#include <memory>
#include <utility>

#include "ProtocolParser.h"
#include "CollationParser.h"

Controller& Controller::instance()
{
    static Controller instance;
    return instance;
}

void Controller::execute()
{
    mProtocolParser = std::make_unique<ProtocolParser>();
    mCollationParser = std::make_unique<CollationParser>();

    mProtocolParser->parse(mProtocolPath);
    mCollationParser->parse(mCollationPath);
}

void Controller::setPaths(std::string _protocolPath, std::string _collationPath)
{
    mProtocolPath = std::move(_protocolPath);
    mCollationPath = std::move(_collationPath);
}

void Controller::setParsingType()
{

}

void Controller::setSettings()
{

}
