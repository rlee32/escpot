#include "Component.h"
#include "Esc.h"
#include "MomentaryPushButton.h"
#include "Pin.h"
#include "Potentiometer.h"
#include "RgbLed.h"

OutputPin escout(10);
PowerPin escpower(9);
GroundPin escground(8);

constexpr int EscLevels = 25;
Esc<EscLevels> esc(escout, escpower, escground);

OutputPin red(4);
PowerPin power(5);
OutputPin green(6);
OutputPin blue(7);

RgbLed<PowerPin> led(red, power, green, blue);

PowerPin potpower(A0);
InputPin potinput(A1);
GroundPin potground(A2);

Potentiometer pot(potpower, potinput, potground, 23, 1000, 0, EscLevels - 1);

InputPin buttoninput(A3);
PowerPin buttonpower(A4);
GroundPin buttonground(A5);

MomentaryPushButton button(buttoninput, buttonpower, buttonground);

void setup()
{
    led.setup();
    button.setup();
    esc.setup();
    pot.setup();
    Component::CheckSetup();
    Pin::ValidateSingleUsage();
    Serial.begin(9600);
    esc.printLevels();
}

void loop()
{
    if (button.high())
    {
        int level = pot.readScaled();
        level = esc.throttle(level);
        if (level == EscLevels - 1)
        {
            led.blue();
        }
        else if (level > EscLevels / 2)
        {
            led.magenta();
        }
        else if (level > 0)
        {
            led.cyan();
        }
        else if (level == 0)
        {
            led.yellow();
        }
    }
    else
    {
        led.red();
        esc.off();
    }
}
