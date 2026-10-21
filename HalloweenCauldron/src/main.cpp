#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define LED_LEN 15
#define LED_PIN 4

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_LEN, LED_PIN, NEO_GRB + NEO_KHZ800);
uint16_t hue[LED_LEN];
uint8_t value[LED_LEN];

uint8_t state = 0;

void setup() {
	strip.begin();
}



void loop() {
	for (uint8_t led = 0; led < LED_LEN; led++) {
		if (value[led] == 0) {
			if (rand() % 100 < 1) {
				hue[led] = (rand()%32)*256*8;
				value[led] = 255;
			}
		} else {
			value[led]--;
		}
		strip.setPixelColor(led, strip.ColorHSV(hue[led], 255, value[led]));
	}
	strip.show();
	delay(10);
}
