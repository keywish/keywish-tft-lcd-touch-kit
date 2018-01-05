/***********************************************************************
 * When using the BREAKOUT BOARD only, use these 8 data lines to the LCD:
 * For the Arduino Uno, Duemilanove, Diecimila, etc.:
 * D0 connects to digital pin 8  (Notice these are
 * D1 connects to digital pin 9   NOT in order!)
 * D2 connects to digital pin 2
 * D3 connects to digital pin 3
 * D4 connects to digital pin 4
 * D5 connects to digital pin 5
 * D6 connects to digital pin 6
 * D7 connects to digital pin 7
 * For the Arduino Mega, use digital pins 22 through 29
 * (on the 2-row header at the end of the board).
 ***********************************************************************/

#include "Adafruit_GFX.h" // Hardware-specific library
#include "MCUFRIEND_kbv.h"
MCUFRIEND_kbv tft;

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

// work in line numbers.  Font height in ht
int16_t ht = 16, top = 3, line, lines = 15, scroll;

void setup()
{
    tft.reset();
    uint16_t id = tft.readID();
    tft.begin(id);
    tft.setRotation(0);     //Portrait
    tft.fillScreen(BLACK);
    tft.setTextColor(WHITE, BLACK);
    tft.setTextSize(2);     // System font is 8 pixels.  ht = 8*2=16
    tft.setCursor(100, 0);
    tft.print("ID = 0x");
    tft.println(id, HEX);
    if (id == 0x9320 || id == 0x9325 || id == 0xB509) {
        top = 0;                      // these controllers scroll full screen
        lines = tft.height() / ht;    // we are in portrait mode
    }
    if (id == 0x7783) {
        tft.println("can NOT scroll");
        while (1);                    // die.
    }
    tft.setCursor(0, 0);
    for (line = 1; line < 21; line++) tft.println(String(line) + ": ");
}

void loop()
{
    tft.setCursor(0, (scroll + top) * ht);
    if (++scroll >= lines) scroll = 0;
    tft.vertScroll(top * ht, lines * ht, (scroll) * ht);
    tft.println(String(line) + ": [" + String(scroll) + "]  ");
    delay(100);
    line++;
}
