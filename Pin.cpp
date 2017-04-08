#include "Pin.h"


int Pin::Usage[MaxPin + 1] = {}; // initialize to 0
Pin::Pin(int pin) : Component(), pin(pin)
{
    assert(pin >= 0 and pin <= MaxPin);
    ++Usage[pin];
}
void Pin::ValidateSingleUsage()
{
    for(int i = 0; i <= MaxPin; ++i)
    {
        assert(Usage[i] == 1 or Usage[i] == 0);
    }
}


PowerPin::PowerPin(int pin) : Pin(pin) {}
void PowerPin::setup() const
{
    Component::setup();
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
}


GroundPin::GroundPin(int pin) : Pin(pin) {}
void GroundPin::setup() const
{
    Component::setup();
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}


InputPin::InputPin(int pin) : Pin(pin) {}
void InputPin::setup() const
{
    Component::setup();
    pinMode(pin, INPUT);
}


OutputPin::OutputPin(int pin) : Pin(pin) {}
void OutputPin::setup() const
{
    Component::setup();
    pinMode(pin, OUTPUT);
}