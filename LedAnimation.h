#pragma once
#include <FastLED.h>
#define LED_PIN 5
class LedAnimation {

public :
	void LedAnimation::setupLedStrip(char numberOfLeds, CRGB leds[]);
	void RunRandomAnimation();
	void ShowImage();
	void ledOff();
private:
	void snakeAnimation();
private:
	char m_numberOfLeds;
	CRGB* m_leds;

};
