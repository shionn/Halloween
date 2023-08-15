
#include <mp3.h>

MP3::MP3() :comm( MP3_RX, MP3_TX ) {
    comm.begin( 9600 );
}


void MP3::sendToMp3( uint8_t command[], int len ) {
    for (int i = 0;i < len;i++) {
        comm.write( command[i] );
    }
}

void MP3::init() {
    // starting byte, number of byte, command = select SD Card, value, fin
    uint8_t data[] = { 0x7e, 0x03, 0X35, 0x01, 0xef }; // select SD Card
    this->sendToMp3( data, 5 );
    delay( 1000 );
}

void MP3::play( uint8_t track ) {
    if (enable) {
        // starting byte, number of byte, command, value, value, fin
        uint8_t data[] = { 0x7e, 0x04, 0x41, 0x00, track, 0xef };
        this->sendToMp3( data, 6 );
    }
}

void MP3::setEnable( boolean enable ) {
    this->enable = enable;
}

boolean MP3::isEnable() {
    return enable;
}

