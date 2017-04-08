#pragma once

#include "Arduino.h"

#include "Component.h"
#include "Pin.h"


template <typename CommonPinType>
struct RgbLedSignal
{
    using SignalType = decltype(LOW);
    static constexpr SignalType On = LOW;
    static constexpr SignalType Off = HIGH;
};

template <typename CommonPinType>
class RgbLed : public Component
{
    using SignalType = decltype(LOW);
    static constexpr SignalType On  = RgbLedSignal<CommonPinType>::On;
    static constexpr SignalType Off = RgbLedSignal<CommonPinType>::Off;
public:
    RgbLed(const OutputPin& r, const CommonPinType& p,
        const OutputPin& g, const OutputPin& b);
    void setup() const;
    void set(SignalType r, SignalType g, SignalType b) const;
    void red() const;
    void green() const;
    void blue() const;
    void yellow() const;
    void cyan() const;
    void magenta() const;
    void white() const;
    void off() const;
private:
    const OutputPin& m_r;
    const CommonPinType& m_p;
    const OutputPin& m_g;
    const OutputPin& m_b;
};
