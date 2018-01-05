/***********************************************************************
 *       __                                                          _
 *      / /        _____  __    __  _          _   (_)   ________   | |
 *     / /____   / _____) \ \  / / | |   __   | |  | |  (  ______)  | |_____
 *    / / ___/  | |_____   \ \/ /  | |  /  \  | |  | |  | |______   |  ___  |
 *   / /\ \     | |_____|   \  /   | | / /\ \ | |  | |  (_______ )  | |   | |
 *  / /  \ \__  | |_____    / /    | |/ /  \ \| |  | |   ______| |  | |   | |
 * /_/    \___\  \______)  /_/      \__/    \__/   |_|  (________)  |_|   |_|
 *
 *
 * KeyWay Tech firmware
 
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

// wiring with UNO or Mega2560:
//--------------POWER Pins--------------------------------
//   5V  connects to DC 5V
//   GND connects to Ground
//   3V3 do not need to connect(NC)
//--------------LCD Display Pins--------------------------
//   LCD_RD   connects to Analog pin A0  
//   LCD_WR   connects to Analog pin A1  
//   LCD_RS   connects to Analog pin A2  
//   LCD_CS   connects to Analog pin A3  
//   LCD_RST  connects to Analog pin A4  
//   LCD_D0   connects to digital pin 8  
//   LCD_D1   connects to digital pin 9  
//   LCD_D2   connects to digital pin 2
//   LCD_D3   connects to digital pin 3
//   LCD_D4   connects to digital pin 4
//   LCD_D5   connects to digital pin 5
//   LCD_D6   connects to digital pin 6
//   LCD_D7   connects to digital pin 7
//--------------SD-card fuction Pins ----------------------
//This Connection Only for UNO, Do not support Mega2560
//because they use different Hardware-SPI Pins
//SD_SS    connects to digital pin 10
//SD_DI    connects to digital pin 11
//SD_DO    connects to digital pin 12
//SD_SCK   connects to digital pin 13


#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin
#define LCD_CS A3   // Chip Select goes to Analog 3
#define LCD_CD A2  // Command/Data goes to Analog 2
#define LCD_WR A1  // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0

// Assign human-readable names to some common 16-bit color values:
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF


MCUFRIEND_kbv tft;

static const unsigned char PROGMEM logo1[] =  
{
   #include "logo1.h"
};  
static const unsigned char PROGMEM logo2[] =
{
   #include "logo2.h"
};


void setup(void) {
   Serial.begin(9600);
  Serial.println(F("TFT LCD test"));

  tft.reset();

  uint16_t identifier = tft.readID();
  if(identifier == 0x9325) {
    Serial.println(F("Found ILI9325 LCD driver"));
  } else if(identifier == 0x9328) {
    Serial.println(F("Found ILI9328 LCD driver"));
  } else if(identifier == 0x4535) {
    Serial.println(F("Found LGDP4535 LCD driver"));
  }else if(identifier == 0x7575) {
    Serial.println(F("Found HX8347G LCD driver"));
  } else if(identifier == 0x9595) {
    Serial.println(F("Found HX8347-I LCD driver"));
  } else if(identifier == 0x4747) {
    Serial.println(F("Found HX8347-D LCD driver"));
  } else if(identifier == 0x8347) {
    Serial.println(F("Found HX8347-A LCD driver"));
  }else if(identifier == 0x9341) {
    Serial.println(F("Found ILI9341 LCD driver"));
  }else if(identifier == 0x7783) {
    Serial.println(F("Found ST7781 LCD driver"));
  }else if(identifier == 0x8230) {
    Serial.println(F("Found UC8230 LCD driver"));  
  }else if(identifier == 0x8357) {
    Serial.println(F("Found HX8357D LCD driver"));
  } else if(identifier==0x0101){     
      identifier=0x9341;
      Serial.println(F("Found 0x9341 LCD driver"));
  }else if(identifier==0x7793){     
       Serial.println(F("Found ST7793 LCD driver"));
  }else if(identifier==0xB509){     
       Serial.println(F("Found R61509 LCD driver"));
  }else if(identifier==0x9486){     
       Serial.println(F("Found ILI9486 LCD driver"));
  }else if(identifier==0x9488){     
       Serial.println(F("Found ILI9488 LCD driver"));
  }else {
    Serial.print(F("Unknown LCD driver chip: "));
    Serial.println(identifier, HEX);
    Serial.println(F("If using the Adafruit 2.8\" TFT Arduino shield, the line:"));
    Serial.println(F("  #define USE_ADAFRUIT_SHIELD_PINOUT"));
    Serial.println(F("should appear in the library header (Adafruit_TFT.h)."));
    Serial.println(F("If using the breakout board, it should NOT be #defined!"));
    Serial.println(F("Also if using the breakout, double-check that all wiring"));
    Serial.println(F("matches the tutorial."));
    identifier=0x9341; 
  }
  tft.begin(identifier); 

}

void loop(void) {
  tft.setRotation(1);
    tft.fillScreen(WHITE);
    tft.drawBitmap(40,20,logo1,240,120,1500);                               
    tft.setCursor(70, 170);
    tft.setTextColor(RED); 
    tft.setTextSize(4);
    tft.println("keywish");

    delay(2000);
    tft.setRotation(4);
    tft.fillScreen(BLUE);
    tft.drawBitmap(0,0,logo2,240,320,1500);
    delay(2000);
}
