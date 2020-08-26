#include "MatrixSDReader.h"
#include "LedAnimation.h"
#define SD_PIN  4

const char	NUMBER_OF_PIXELS = 18;
bool animationStatus = false;
unsigned long ledMatrix[NUMBER_OF_PIXELS] = { 0 };
LedAnimation ledAnimation;
MatrixSDReader matrixSDReader;
CRGB leds[NUMBER_OF_PIXELS];

void setup() {
    Serial.begin(115200); 
    Serial.println("starting...");

    matrixSDReader.InitSDReader(SD_PIN);
    ledAnimation.setupLedStrip(NUMBER_OF_PIXELS, leds);

}

void loop() {

    animationStatus =  matrixSDReader.ReadNextAnimation(ledMatrix, NUMBER_OF_PIXELS);
    Serial.println(animationStatus);
    if (animationStatus)
    {
        for (char i = 0; i < 9; i++)
        {
            leds[i]=(ledMatrix[i]);
            Serial.print(ledMatrix[i], HEX);

        }
        Serial.println("");
        ledAnimation.ShowImage();
    }
    else
    {
        Serial.println("d");
        ledAnimation.RunRandomAnimation();
    }
    delay(500);
}


