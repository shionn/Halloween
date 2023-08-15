#include <Arduino.h>

#include <controller.h>
#include <web.h>

#define SENSOR_PIN D4


Controller controller;
Web web = Web( &controller );


void setup() {
    controller.init();
    pinMode( SENSOR_PIN, INPUT );
    Serial.begin( 9600 );

    // pinMode( LED_BUILTIN, OUTPUT );

    WiFi.disconnect();
    WiFi.mode( WIFI_STA );
    WiFi.hostname( "HalloweenD1" );
    WiFi.begin( "Livebox-AF32", "EFE356954211D29CFDE6ECAD64" );
    while (WiFi.status() != WL_CONNECTED) {
        digitalWrite( LED_BUILTIN, HIGH );
        delay( 300 );
        digitalWrite( LED_BUILTIN, LOW );
        delay( 200 );
    }

    web.init();
}

void loop() {
    controller.update();
    if (digitalRead( SENSOR_PIN ) == HIGH) {
        controller.humanDetect();
        // digitalWrite( LED_BUILTIN, HIGH );
    } else {
        // digitalWrite( LED_BUILTIN, LOW );
    }
}