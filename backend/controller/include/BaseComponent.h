#pragma once

#include "Mediator.h"
#include "Logger.h"

class BaseComponent
{
protected:
    Mediator* mediator;
public:
    explicit BaseComponent(Mediator* _mediator = nullptr) : mediator(_mediator){ }
    void setMediator(Mediator* _mediator)
    {
        this->mediator = _mediator;
    }
};