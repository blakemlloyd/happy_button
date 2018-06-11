#include "Arduino.h"
#include "happy_button.h"

class happy_button
{
    happy_button::happy_button(int pin)
    {
        pinMode(pin, INPUT);
        _pin = pin;
    }

    bool happy_button::isStateUpdated()
    {
        int tmpButtonState = digitalRead(_pin);
        if(tmpButtonState != _state)
        {
            _state = tmpButtonState;
            if(_state = LOW)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}