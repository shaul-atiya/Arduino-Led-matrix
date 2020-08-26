#include "LedAnimation.h"


void LedAnimation::setupLedStrip(char numberOfLeds,  CRGB* leds)
{
    m_numberOfLeds = numberOfLeds;
    m_leds = leds;
	FastLED.addLeds<WS2812, LED_PIN , GRB >(m_leds, numberOfLeds);
}

void LedAnimation::ShowImage()
{
    FastLED.show();
}

void LedAnimation::snakeAnimation()
{
    Serial.println("animating... 0");
    for (char i = 1; i < m_numberOfLeds-1; i++)
    {
        m_leds[i - 1] = 0;
        m_leds[i] = CRGB(0, 0, 255);
        m_leds[i + 1] = 0;
        FastLED.show();
        delay(100);
    }

}

void LedAnimation::ledOff()
{
    Serial.println("animating... 1");
    for (char i = 0; i < m_numberOfLeds; i++)
    {
       m_leds[i] = CRGB(0, 0, 0);
        
        FastLED.show();
        delay(100);
    }
}

void LedAnimation::RunRandomAnimation()
{
    switch (random(0,2))
    {
    case 0:
        snakeAnimation();
        break;
    case 1:
        ledOff();
        break;
    default:
        break;
    }
    snakeAnimation();
}