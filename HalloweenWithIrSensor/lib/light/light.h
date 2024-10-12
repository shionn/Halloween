#ifndef __LIGHT_H__
#define __LIGHT_H__

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Adafruit_NeoPixel.h>

// D0 semble KO pour cet usage
#define LED_PIN_PALETTE D5
#define LED_LEN_PALETTE 1

#define LED_PIN_ROOF D6
#define LED_LEN_ROOF 169

#define LED_PIN_OTHER D7
#define LED_LEN_OTHER 1

#define LED_MODE_THEATRE 0
#define LED_MODE_RAINBOW 1
#define LED_MODE_FLASH 3

#define NB_STRIP 3

#define SPEED_THEATRE 2560
#define SPEED_RAINBOW 2560
#define SPEED_FLASH 128

class Lights {

private:
    uint16_t step = 0;
    uint8_t mode = LED_MODE_THEATRE;
    bool enable = true;
    Adafruit_NeoPixel strips[NB_STRIP] = {
            Adafruit_NeoPixel( LED_LEN_PALETTE, LED_PIN_PALETTE, NEO_GRB + NEO_KHZ800 ),
            Adafruit_NeoPixel( LED_LEN_ROOF, LED_PIN_ROOF, NEO_GRB + NEO_KHZ800 ),
            Adafruit_NeoPixel( LED_LEN_OTHER, LED_PIN_OTHER, NEO_GRB + NEO_KHZ800 ) };

public:
    Lights();
    void init();
    void update();
    void setMode( uint8_t mode );
    boolean isMode( uint8_t mode );
    void setEnable( bool enable );
    boolean isEnable();

private:
    void displayTheatre();
    void displayRainbow();
    void displayFlash();
};


#endif