#ifndef _WEB_H__
#define _WEB_H__

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include <controller.h>

class Web {

private:
    AsyncWebServer server;
    Controller* controller;

public:
    Web( Controller* controller );
    void init();

private:
    void render( AsyncWebServerRequest* request );
    void playSound( AsyncWebServerRequest* request, uint8_t sound );
    void toggleLight( AsyncWebServerRequest* request );
    void toggleSound( AsyncWebServerRequest* request );

};

#endif
