#include <Arduino.h>
#include <iostream>
#include <string>
#include "grove_two_rgb_led_matrix.h"
using namespace std;

#define DISPLAY_COLOR 0x33

#ifdef ARDUINO_SAMD_VARIANT_COMPLIANCE
#define SERIAL SerialUSB
#else
#define SERIAL Serial
#endif

#ifndef LEDS_H
#define LEDS_H


class LEDs {


  public :
    GroveTwoRGBLedMatrixClass matrix;
    //constructeur
    LEDs(GroveTwoRGBLedMatrixClass matrix);
    void allumerColonne(int colonne);
    void affichageJeton(uint64_t* grille, int x, int y, int couleur);
  private :
    int numPin;

};

#endif
