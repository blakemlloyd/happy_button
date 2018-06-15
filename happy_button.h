#ifndef happy_button_h
#define happy_button_h

#include "Arduino.h"
#include <PubSubClient.h>

class happy_button
{
    public:
        happy_button(int pin, PubSubClient client);
        void setId(char* id);
        bool checkState();
    private:
        int _pin;
        int _state;
        char *topic;
        PubSubClient _client;
};

#endif