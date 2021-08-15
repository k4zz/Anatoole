#include "Controller.h"

#include <memory>
#include <utility>

#include "ProtocolParser.h"
#include "CollationParser.h"
#include "Analyzer.h"
#include "Utils.h"

void Controller::execute()
{
    resetComponents();

    if(not validatePaths())
        return;

    //TODO: make it return bool
    createParsers();

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

    mAnalyzer =  std::make_unique<Analyzer>(mProtocolParser->getEntries(), mCollationParser->getEntries());

    handleProblems();

    if (not mAnalyzer->problemCount())
        LOG_INFO("Analysis done, no problems found");
    else
        LOG_WARNING("Analysis done, found " + std::to_string(mAnalyzer->problemCount()) + " problems. Check your files.");
}

void Controller::setPaths(std::string _protocolPath, std::string _collationPath)
{
    mProtocolPath = std::move(_protocolPath);
    mCollationPath = std::move(_collationPath);

}

void Controller::createParsers()
{

    if (Utils::ends_with(mProtocolPath, ".csv"))
    {
        mProtocolParser = std::make_unique<ProtocolParser>();
    }

    if (Utils::ends_with(mCollationPath, ".csv"))
    {
        mCollationParser = std::make_unique<CollationParser>();
    }
}

//TODO: settings should be separate class
bool Controller::setSettings(int _protocolKeyColumn, int _protocolValueColumn, int _collationKeyColumn,
                             int _collationValueColumn)
{
    if (not isParsersCreated())
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
    if (not isProtocolParsed)
    {
        LOG_ERROR("Problem with parsing protocol");
    }
    else
        LOG_DEBUG("Protocol parsed correctly");

    auto isCollationParsed = mCollationParser->parse(mCollationPath);
    if (not isCollationParsed)
    {
        LOG_ERROR("Problem with parsing collation");
    }
    else
        LOG_DEBUG("Collation parsed correctly");

    return isProtocolParsed && isCollationParsed;
}

void Controller::handleProblems()
{
    for(auto problem : mAnalyzer->getProblems())
    {
        switch (problem.type)
        {
            case ProblemType::MissingPosition:
                LOG_WARNING("Missing position " + problem.protocolPosition + " from protocol for name " + problem.name + " in collation");
                break;
            case ProblemType::MissingName:
                LOG_WARNING("Missing name " + problem.name + " in collation");
                break;
            case ProblemType::RedundantPosition:
                LOG_WARNING("Non-existing position " + problem.protocolPosition + " of protocol in collation");
                break;
            case ProblemType::RedundantName:
                LOG_WARNING("Name " + problem.name + " is not existing in protocol for position " + problem.protocolPosition + " in collation");
                break;
        }
    }
}

void Controller::resetComponents()
{
    mProtocolParser.reset();
    mCollationParser.reset();
    mAnalyzer.reset();
}

bool Controller::validatePaths()
{
    auto allow = true;
    if (mProtocolPath.empty())
    {
        LOG_ERROR("Cannot create protocol parser, path is empty");
        allow = false;
    }
    if (mCollationPath.empty())
    {
        LOG_ERROR("Cannot create collation parser, path is empty");
        allow = false;
    }
    return allow;
}
