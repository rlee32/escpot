#include "MomentaryPushButton.h"


MomentaryPushButton::MomentaryPushButton(
  const InputPin& i, const PowerPin& p, const GroundPin& g)
  : Component(), m_input(i), m_power(p), m_ground(g) {}

void MomentaryPushButton::setup() const
{
    Component::setup();
    m_input.setup();
    m_ground.setup();
    m_power.setup();
}

bool MomentaryPushButton::high() const
{
    return digitalRead(m_input.pin) == HIGH;
}

bool MomentaryPushButton::low() const
{
    return digitalRead(m_input.pin) == LOW;
}
