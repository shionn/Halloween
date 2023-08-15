#include <light.h>

Lights::Lights() {

}

void Lights::init() {
    for (int s = 0;s < NB_STRIP;s++) {
        strips[s].begin();
        strips[s].fill( strips[s].Color( 64, 64, 64 ) );
        strips[s].show();
    }
}

void Lights::update() {
    if (enable) {
        switch (mode) {
        case LED_MODE_THEATRE: displayTheatre(); break;
        case LED_MODE_RAINBOW: displayRainbow(); break;
        case LED_MODE_FLASH: displayFlash(); break;
        default: break;
        }
    } else {
        for (int s = 0;s < NB_STRIP;s++) {
            uint32_t c = strips[s].Color( 0, 0, 0 );
            strips[s].fill( c );
        }
    }
    for (int s = 0;s < NB_STRIP;s++) {
        strips[s].show();
    }
    step++;
    if (step > 20480) {
        step = 0;
    }
}

void Lights::setMode( uint8_t mode ) {
    this->mode = mode;
}

boolean Lights::isMode( uint8_t mode ) {
    return this->mode == mode;
}

void Lights::setEnable( boolean enable ) {
    this->enable = enable;
}

boolean Lights::isEnable() {
    return enable;
}

void Lights::displayTheatre() {
    for (int s = 0;s < NB_STRIP;s++) {
        for (int8_t led = 0; led < strips[s].numPixels(); led++) {
            uint16_t state = (map( led, 0, strips[s].numPixels(), 0, SPEED_THEATRE ) + step) % SPEED_THEATRE;
            strips[s].setPixelColor( led, strips[s].ColorHSV( map( state, 0, SPEED_THEATRE, 0, 65535 ), 255, 255 ) );
        }
    }
}

void Lights::displayRainbow() {
    for (int s = 0;s < NB_STRIP;s++) {
        uint32_t c = strips[s].ColorHSV( map( step % SPEED_RAINBOW, 0, SPEED_RAINBOW, 0, 65535 ), 255, 255 );
        strips[s].fill( c );
    }
}

void Lights::displayFlash() {
    for (int s = 0;s < NB_STRIP;s++) {
        if (step % SPEED_FLASH > SPEED_FLASH / 2) {
            uint32_t c = strips[s].Color( 255, 255, 255 );
            strips[s].fill( c );
        } else {
            uint32_t c = strips[s].Color( 0, 0, 0 );
            strips[s].fill( c );
        }
    }
}
