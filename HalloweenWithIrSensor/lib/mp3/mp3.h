#ifndef _MP3_H__
#define _MP3_H__

#include <Arduino.h>
#include <SoftwareSerial.h>

// pour le D1 mini
#define MP3_RX D2 // to TX
#define MP3_TX D1 // To RX

#define SOUND_FANTOM_HOUHOU 1
#define SOUND_RIRE_1 3
#define SOUND_RIRE_2 4
#define SOUND_RIRE_3 5
#define SOUND_RIRE_4 6
#define SOUND_PIKA 7
#define SOUND_RIRE_5 8
#define SOUND_RIRE_6 9
#define SOUND_HELLO_AND_WELCOME 10
#define SOUND_THUNDERS 11
#define SOUND_RIRE_7 12
#define MUSIC_GHOSTBUSTER 13
#define SOUND_BOUH_RIRE 14

class MP3 {
private:
    SoftwareSerial comm;
    boolean enable = true;
public:
    MP3();
    void init();
    void play( uint8_t track );
    void setEnable( bool enable );
    boolean isEnable();

private:
    void sendToMp3( uint8_t command[], int len );

};


#endif
