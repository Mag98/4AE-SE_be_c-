
#include <Arduino.h>
#include <iostream>
#include <string>
using namespace std;

#ifndef _POTENTIO_
#define _POTENTIO_

class Potentio {


  public :
    //constructeur
    Potentio(int numPin);
    //Getter
    int getEtat();
    int determinerColonne(int etat);
  private :
    int numPin;
    int etat;


};

#endif
