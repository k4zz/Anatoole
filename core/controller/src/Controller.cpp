#include "Controller.h"

#include <memory>

#include "ProtocolParser.h"
#include "CollationParser.h"
#include "Utils.h"

void Controller::execute()
{
    resetComponents();

    if(not validatePaths())
    {
        LOG_ERROR("File paths are invalid");
        return;
    }

    if(not createParsers())
    {
        LOG_ERROR("Not all parsers are created");
        return;
    }

    if(not setSettings())
    {
        return;
    }

    if (not parseFiles())
    {
        return;
    }

    mAnalyzer =  std::make_unique<Analyzer>(mProtocolParser->getEntries(), mCollationParser->getEntries());

    handleProblems();

    if (not mAnalyzer->problemsCount())
        LOG_INFO("Analysis done, no problems found");
    else
        LOG_WARNING("Analysis done, found " + std::to_string(mAnalyzer->problemsCount()) + " problems. Check your files.");
}

void Controller::resetComponents()
{
    mProtocolParser.reset();
    mCollationParser.reset();
    mAnalyzer.reset();
    LOG_DEBUG("Reset of controller components");
}

void Controller::setPaths(std::string _protocolPath, std::string _collationPath)
{
    mProtocolPath = std::move(_protocolPath);
    mCollationPath = std::move(_collationPath);
}

bool Controller::validatePaths()
{
    auto allow = true;
    if (mProtocolPath.empty())
    {
        LOG_ERROR("Protocol path is empty");
        allow = false;
    }
    if (mCollationPath.empty())
    {
        LOG_ERROR("Collation path is empty");
        allow = false;
    }
    return allow;
}

bool Controller::createParsers()
{

    if (Utils::ends_with(mProtocolPath, ".csv"))
    {
        mProtocolParser = std::make_unique<ProtocolParser>();
        LOG_DEBUG("CSVProtocolParser created");
    }

    if (Utils::ends_with(mCollationPath, ".csv"))
    {
        mCollationParser = std::make_unique<CollationParser>();
        LOG_DEBUG("CSVCollationParser created");
    }

    return mProtocolParser && mCollationParser;
}

//TODO: settings should be separate class
void Controller::setSettings(int _protocolKeyColumn, int _protocolValueColumn, int _collationKeyColumn,
                             int _collationValueColumn)
{
    mSettings = {_protocolKeyColumn, _protocolValueColumn, _collationKeyColumn, _collationValueColumn};
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
    for(const auto& problem : mAnalyzer->getProblems())
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

bool Controller::setSettings()
{
    if(not (mProtocolParser && mCollationParser))
    {
        LOG_ERROR("Cannot set settings, parsers not created");
        return false;
    }

    mProtocolParser->setSettings(mSettings.protocolKeyColumn, mSettings.protocolValueColumn);
    mCollationParser->setSettings(mSettings.collationKeyColumn, mSettings.collationValueColumn);
    return true;
}
