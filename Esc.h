#pragma once

#include "Arduino.h"
#include "Pin.h"
#include <Servo.h> // ESC uses same signals as Servo

template<int Levels>
class Esc : public Component
{
public:
    Esc(const OutputPin&, const PowerPin&, const GroundPin&, int minWidth = 1000, int maxWidth = 2000);
    void setup();
    int throttle(int level);
    void off();
    int width(int level) const { return widths[level]; }
    void printLevels() const;
private:
    const OutputPin& out;
    const PowerPin& vcc;
    const GroundPin& gnd;
    Servo pwmDevice;
    int widths[Levels] = {};
    int minWidth = 0; // microseconds
    int maxWidth = 0; // microseconds
};

template<int Levels>
Esc<Levels>::Esc(const OutputPin& out, const PowerPin& vcc, const GroundPin& gnd, 
  int minWidth, int maxWidth)
  : Component(), out(out), vcc(vcc), gnd(gnd), minWidth(minWidth), maxWidth(maxWidth)
{
    // Initialize pulse width discretization.
    int increment = static_cast<float>(maxWidth - minWidth) / (Levels - 1);
    for(int i = 0; i < Levels; ++i)
    {
        widths[i] = minWidth + i * increment;
    }
    widths[0] = minWidth;
    widths[Levels-1] = maxWidth;
}

template<int Levels>
void Esc<Levels>::setup()
{
    Component::setup();
    pwmDevice.attach(out.pin);
    Component::setup(); // for out pin
    gnd.setup();
    vcc.setup();
    off();
}

template<int Levels>
int Esc<Levels>::throttle(int level)
{
    level = constrain(level, 0, Levels-1);
    pwmDevice.writeMicroseconds(widths[level]);
    // Serial.println(widths[level]);
    return level;
}

template<int Levels>
void Esc<Levels>::off()
{
    pwmDevice.writeMicroseconds(minWidth);
}

template<int Levels>
void Esc<Levels>::printLevels() const
{
    for(int i = 0; i < Levels; ++i)
    {
        Serial.print("Level ");
        Serial.print(i);
        Serial.print(": ");
        Serial.println(widths[i]);
    }
}
