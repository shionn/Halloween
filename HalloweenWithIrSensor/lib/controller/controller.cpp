#include <controller.h>

Controller::Controller() {

}

void Controller::init() {
    mp3.init();
    lights.init();
}

void Controller::update() {
    lights.update();
    if (human && millis() > last) {
        human = false;
        if (random( 0, 2 )) {
            lights.setMode( LED_MODE_THEATRE );
        } else {
            lights.setMode( LED_MODE_RAINBOW );
        }
    }
}

void Controller::playSound( uint8_t track ) {
    mp3.play( track );
}

void Controller::humanDetect() {
    if (!human) {
        Serial.write( "human detect \n" );
        last = millis() + 10000;
        human = true;
        uint8_t tracks[] = { SOUND_FANTOM_HOUHOU, SOUND_HELLO_AND_WELCOME, SOUND_THUNDERS,  SOUND_BOUH_RIRE,
                SOUND_RIRE_1, SOUND_RIRE_2, SOUND_RIRE_3, SOUND_RIRE_4, SOUND_RIRE_5, SOUND_RIRE_6, SOUND_RIRE_7 };
        mp3.play( tracks[random( 11 )] );
        lights.setMode( LED_MODE_FLASH );
    }
}

void Controller::toggleLight() {
    lights.setEnable( !lights.isEnable() );
}

bool Controller::isLightOn() {
    return lights.isEnable();
}

void Controller::toggleSound() {
    mp3.setEnable( !mp3.isEnable() );
}

bool Controller::isSoundOn() {
    return mp3.isEnable();
}

