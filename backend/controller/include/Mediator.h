#pragma once

#include "EventType.h"

class BaseComponent;
class Mediator
{
public:
    virtual void notify(BaseComponent* sender, Event event) const = 0;
};