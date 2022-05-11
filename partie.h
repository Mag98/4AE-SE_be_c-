//#include <Arduino.h>
//#include <iostream>
//#include <string>
using namespace std;

#include "backend.h"


#ifndef _PARTIE_
#define _PARTIE_

class Partie {


  public :
    //constructeur
    Partie();
    //setter
    void setGagnant(int joueur) ;
    void CalculNombreTours(Backend back) ;
    //getter
    int getWinner(void);
    int getNombre_Tours(void);
  protected :
    int gagnant; //joueur1 ou joueur2
    int nombre_tours;

};

#endif
