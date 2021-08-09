#include "Controller.h"

#include "Logger.h"
#include "BaseComponent.h"
#include "ProtocolParser.h"

Controller& Controller::instance()
{
    static Controller instance;
    return instance;
}

void Controller::setGUIComponent(BaseComponent* _component)
{
    gui = _component;
    gui->setMediator(this);
}

void Controller::setAnalyzerComponent(BaseComponent* _component)
{
    analyzer = _component;
    analyzer->setMediator(this);
}

void Controller::setParserProtocolComponent(BaseComponent* _component)
{
    parserProtocol = _component;
    parserProtocol->setMediator(this);
}

void Controller::setParserCollationComponent(BaseComponent* _component)
{
    parserCollation = _component;
    parserCollation->setMediator(this);
}

void Controller::notify(BaseComponent* sender, Event event) const
{
    switch (event)
    {
        case Event::ANALYZE:
            if (parserProtocol == nullptr)
            {
                LOG_ERROR("Controller has no connection to component: ProtocolParser");
                break;
            }
            static_cast<ProtocolParser*>(parserProtocol)->setFile(settings.protocolPath);
            static_cast<ProtocolParser*>(parserProtocol)->parse();
            static_cast<ProtocolParser*>(parserCollation)->setFile(settings.collationPath);
            static_cast<ProtocolParser*>(parserCollation)->parse();
            break;
        default:
            break;
    }
}
