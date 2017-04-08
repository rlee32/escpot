#include "Potentiometer.h"

Potentiometer::Potentiometer(const PowerPin& p, const InputPin& i, const GroundPin& g,
    int rawMin, int rawMax, int scaledMin, int scaledMax)
    : m_p(p), m_i(i), m_g(g),
        m_rawMin(rawMin), m_rawMax(rawMax), 
        m_scaledMin(scaledMin), m_scaledMax(scaledMax) {}

void Potentiometer::setup() const
{
    Component::setup();
    m_g.setup();
    m_i.setup();
    m_p.setup();
}

int Potentiometer::readRaw() const
{
    return analogRead(m_i.pin);
}

int Potentiometer::readScaled() const
{
    int scaled = map(readRaw(),
        m_rawMin, m_rawMax,
        m_scaledMin, m_scaledMax);
    return constrain(scaled, m_scaledMin, m_scaledMax);
}

bool Potentiometer::scaledMin() const
{
    return readScaled() == m_scaledMin;
}

bool Potentiometer::scaledMax() const
{
    return readScaled() == m_scaledMax;
}
