#include "RgbLed.h"


template <>
struct RgbLedSignal<PowerPin>
{
    using SignalType = decltype(LOW);
    static constexpr SignalType On  = LOW;
    static constexpr SignalType Off = HIGH;
};
template <>
struct RgbLedSignal<GroundPin>
{
    using SignalType = decltype(LOW);
    static constexpr SignalType On  = HIGH;
    static constexpr SignalType Off = LOW;
};


template <typename CommonPinType>
RgbLed<CommonPinType>::RgbLed(const OutputPin& r, const CommonPinType& p,
    const OutputPin& g, const OutputPin& b)
    : Component(), m_r(r), m_p(p), m_g(g), m_b(b) {}

template <typename CommonPinType>
void RgbLed<CommonPinType>::red() const
{
    set(On, Off, Off);
}
template <typename CommonPinType>
void RgbLed<CommonPinType>::green() const
{
    set(Off, On, Off);
}
template <typename CommonPinType>
void RgbLed<CommonPinType>::blue() const
{
    set(Off, Off, On);
}
template <typename CommonPinType>
void RgbLed<CommonPinType>::yellow() const
{
    set(On, On, Off);
}
template <typename CommonPinType>
void RgbLed<CommonPinType>::cyan() const
{
    set(Off, On, On);
}
template <typename CommonPinType>
void RgbLed<CommonPinType>::magenta() const
{
    set(On, Off, On);
}
template <typename CommonPinType>
void RgbLed<CommonPinType>::white() const
{
    set(On, On, On);
}
template <typename CommonPinType>
void RgbLed<CommonPinType>::off() const
{
    set(Off, Off, Off);
}

template <typename CommonPinType>
void RgbLed<CommonPinType>::setup() const
{
    Component::setup();
    m_r.setup();
    m_g.setup();
    m_b.setup();
    m_p.setup();
    off();
}

template <typename CommonPinType>
void RgbLed<CommonPinType>::set(SignalType rs, SignalType gs, SignalType bs) const
{
    digitalWrite(m_r.pin, rs);
    digitalWrite(m_g.pin, gs);
    digitalWrite(m_b.pin, bs);
}

template class RgbLed<PowerPin>;
template class RgbLed<GroundPin>;
