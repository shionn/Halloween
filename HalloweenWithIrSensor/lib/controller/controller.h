#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <Arduino.h>

#include <light.h>
#include <mp3.h>

class Controller {

private:
    MP3 mp3;
    Lights lights;
    unsigned long last = 0;
    boolean human = false;

public:
    Controller();
    void init();

    void update();
    void humanDetect();

    void playSound( uint8_t track );
    void playRandSound();

    boolean isLightOn();
    boolean isSoundOn();
    void toggleLight();
    void toggleSound();
};

#endif