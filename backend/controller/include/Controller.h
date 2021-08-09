#pragma once

#include <string>

#include "Mediator.h"
#include <Settings.h>

class BaseComponent;
class ProtocolParser;

class Controller : public Mediator
{
public:
    static Controller& instance();
    Controller(Controller&) = delete;
    Controller& operator=(const Controller&) = delete;
    void setGUIComponent(BaseComponent* _component);
    void setAnalyzerComponent(BaseComponent* _component);
    void setParserProtocolComponent(BaseComponent* _component);
    void setParserCollationComponent(BaseComponent* _component);

    void notify(BaseComponent* sender, Event event) const;

    Settings settings;
private:

    Controller() = default;
private:
    BaseComponent* gui;
    BaseComponent* analyzer;
    BaseComponent* parserProtocol;
    BaseComponent* parserCollation;
};