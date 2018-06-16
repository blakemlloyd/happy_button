#include "Arduino.h"
#include "happy_button.h"

happy_button::happy_button(int pin, PubSubClient client)
{
    pinMode(pin, INPUT);
    _pin = pin;
    _client = client;
}

void happy_button::setId(char* id)
{
    topic = (char*)malloc(strlen(id) + 22 + 1);
    snprintf(topic, strlen(id) + 22, "homeassistant/%s/button", id);
}

bool happy_button::checkState()
{
    int tmpButtonState = digitalRead(_pin);
    if(tmpButtonState != _state)
    {
        _state = tmpButtonState;
        if(_state == LOW)
        {
            _client.publish(topic, "pressed");
            return true;
        }
    }
    return false;
}