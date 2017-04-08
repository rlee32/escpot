#pragma once

#include <assert.h>

#include "Arduino.h"

#include "Component.h"


struct Pin : public Component
{
public:
    Pin(int pin);
    const int pin = -1;
    static void ValidateSingleUsage();
private:
    static constexpr int MaxPin = 40; // This may depend on your Arduino model.
    static int Usage[MaxPin + 1]; // zero-initialize.
};

struct PowerPin : public Pin
{
    PowerPin(int pin);
    void setup() const;
};

struct GroundPin : public Pin
{
    GroundPin(int pin);
    void setup() const;
};

struct InputPin : public Pin
{
    InputPin(int pin);
    void setup() const;
};

struct OutputPin : public Pin
{
    OutputPin(int pin);
    void setup() const;
};
