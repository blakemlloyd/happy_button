#ifndef happy_button_h
#define happy_button_h

#include "Arduino.h"

class happy_button
{
    public:
        happy_button(int pin);
        bool isStateUpdated();
    private:
        int _pin;
        int _state = -1;
};

#endif