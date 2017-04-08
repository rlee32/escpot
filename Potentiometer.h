#pragma once

#include "Arduino.h"

#include "Component.h"
#include "Pin.h"

class Potentiometer : public Component
{
public:
    Potentiometer(const PowerPin&, const InputPin&, const GroundPin&, 
        int rawMin = 23, int rawMax = 1000, int scaledMin = 0, int scaledMax = 1023);
    void setup() const;
    int readRaw() const;
    int readScaled() const;
    bool scaledMin() const;
    bool scaledMax() const;
private:
    const PowerPin& m_p;
    const InputPin& m_i;
    const GroundPin& m_g;
    const int m_rawMin;
    const int m_rawMax;
    const int m_scaledMin;
    const int m_scaledMax;
};
