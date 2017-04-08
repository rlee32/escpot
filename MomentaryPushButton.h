#pragma once

#include "Arduino.h"
#include "Pin.h"

class MomentaryPushButton : public Component
{
public:
  MomentaryPushButton(const InputPin&, const PowerPin&, const GroundPin&);
  void setup() const;
  bool high() const;
  bool low() const;
private:
  const InputPin& m_input;
  const PowerPin& m_power;
  const GroundPin& m_ground;
};
