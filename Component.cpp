#include "Component.h"


int Component::TotalInstantiated = 0;
int Component::TotalSetup = 0;

Component::Component()
{
    ++TotalInstantiated;
}

void Component::CheckSetup()
{
    assert(TotalInstantiated == TotalSetup);
}

void Component::setup() const
{
    ++TotalSetup;
}