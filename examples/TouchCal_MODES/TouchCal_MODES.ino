/*
  Ejemplo para la librería de calibración de pantallas táctiles "TouchCal.h".
  Este ejemplo se ha probado en una board "DOIT ESP32 DevKIT v1" y una TFT-3.2-240x340-SPI.  
  Habría que conectar la estructura de pines definida más abajo.  

  El ejemplo permite probar la librería en tres modos distintos: 
  GRAPHICS-MODE, DARK-MODE, PIN-MODE
  símplemente comentar/descomentar los defines correspondientes.

  "Es muy cool y visual" 

  by GuerraTron24 - <dinertron@gmail.com>
*/

#include <Arduino.h>

/* ACTIVAR / DESACTIVAR los distintos modos: GRAPHICS-MODE, DARK-MODE, PIN-MODE */
/* ====================== */
#define WITH_SERIAL
#define WITH_TFT
/* ====================== */

#ifdef WITH_TFT
/*Change to your screen resolution*/
#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320

#define DISP_HOR_RES SCREEN_WIDTH
#define DISP_VER_RES SCREEN_HEIGHT

//#include "adjust_card.h"

#define USE_HSPI_PORT
#include <TFT_eSPI.h>
  /*
  EN User_Setup.h se han definido algunos pines, de TFT y de Touch:
  #define TFT_MISO 12
  #define TFT_MOSI 13
  #define TFT_SCLK 14
  #define TFT_CS   15  // Chip select control pin
  #define TFT_DC    2  // Data Command control pin
  #define TFT_RST  -1  // Set TFT_RST to -1 if display RESET is connected to ESP32 board RST

  #define TOUCH_CS 33     // Chip select pin (T_CS) of touch screen
  */
  //TFT_eSPI tft = TFT_eSPI(DISP_HOR_RES, DISP_VER_RES); /* TFT instance */
  /* El constructor se rellena sólo con el alto y ancho: TFT_WIDTH, TFT_HEIGHT */
  TFT_eSPI tft = TFT_eSPI(); /* TFT instance */

/*
#ifndef TFT_eSPI
#define TFT_eSPI
#endif TFT_eSPI */
  
  //void drawCard();
#endif /* TFT */

/* Touch-Calibration: utilizar anteponiendo el namespace "tc::" */
#include "TouchCal.h"
/* Install the "XPT2046_Touchscreen" library by Paul Stoffregen to use the Touchscreen - https://github.com/PaulStoffregen/XPT2046_Touchscreen - */
/*#include <XPT2046_Touchscreen.h> //si se desea se puede obviar, ya se encuentra importada en "TouchCal.h" */
// Touchscreen pins
#define XPT2046_IRQ 36  // T_IRQ
#define XPT2046_MOSI 32 // T_DIN
#define XPT2046_MISO 39 // T_OUT
#define XPT2046_CLK 25  // T_CLK
#define XPT2046_CS 33   // T_CS

SPIClass tsSPI = SPIClass(VSPI);
// SPIClass (uint8_t uc_pinMISO, uint8_t uc_pinSCK, uint8_t uc_pinMOSI, uint8_t uc_pinSS, uint8_t uc_mux)
// SPIClass tsSPI = SPIClass(XPT2046_MISO, XPT2046_CLK, XPT2046_MOSI, XPT2046_CS, XPT2046_IRQ);
XPT2046_Touchscreen ts(XPT2046_CS, XPT2046_IRQ);

void setup() {
#ifdef WITH_SERIAL
    Serial.begin(38400);
    while (!Serial){ delay(50); }
#endif /* WITH_SERIAL */
    Serial.println("Serial.OK");

    tc::TC_ROTATION = 3; //antes de la screen y del touch

    delay(10);
    Serial.println("To touch..");
    //TS
    // Start the SPI for the touchscreen and init the touchscreen
    tsSPI.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS);
    ts.begin(tsSPI);
    //ts.begin();
    ts.setRotation(tc::TC_ROTATION);/**/

#ifdef WITH_TFT
    //TFT
    delay(100);
    Serial.println("To TFT..");
    //tft.begin(TFT_CS);       /* TFT init */
    tft.begin();         // Initialise the display
    tft.setRotation(tc::TC_ROTATION); /* Landscape orientation, flipped */
#endif /* WITH_TFT */

    /*TouchCal. See the Serial Monitor for the array TC_PARS[5] */
    //tc::setRotation(tc::TC_ROTATION);
#ifdef WITH_TFT
    tc::calibration(&ts, &tft);
#else
    tc::calibration(&ts);
#endif /* WITH_TFT */

    //----------------------------
    Serial.println("To Loop..");
}

bool oneOnly = true;
int count, countMax = 50000, count2, ultraMax = 25;
uint16_t x = 0, y = 0, z = 0; // To store the touch coordinates
bool pressed;
TS_Point p = TS_Point();

void loop() {
    pressed = tc::isTouch(&ts, &p);
    // Draw a white spot at the detected coordinates
    if (pressed) {
#ifdef WITH_TFT
        //tft.fillCircle(x, y, 4, TFT_WHITE);
        tft.fillCircle(p.x, p.y, p.z / 100, TFT_WHITE);
#endif /* WITH_TFT */
        //Serial.print("touched! x: "); Serial.print(x); Serial.print(", y: "); Serial.println(y);
        Serial.print("touched! x: "); Serial.print(p.x); Serial.print(", y: "); Serial.println(p.y);
        return;
    }
    count++;
    //New Char
    if(count > countMax){
#ifdef WITH_TFT
      tc::drawLissajous(&ts, &tft);
#endif /* WITH_TFT */
      Serial.print("*");
      count = 0;
      count2++;
    }
    //New Line
    if(count2 > ultraMax){
      tc::printToPin(2);
      Serial.println("#");
      count2 = 0;
    }
    //Only One
    if(oneOnly){
      //drawCard();
      oneOnly = false;
    }
}
