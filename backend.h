#include <list>
#include "jeton.h"
using namespace std ;
#include <iostream>
#include <string>
using namespace std;

#ifndef _BACKEND_
#define _BACKEND_



#ifdef ARDUINO_SAMD_VARIANT_COMPLIANCE
#define SERIAL SerialUSB
#else
#define SERIAL Serial
#endif

class Backend {
  private :
    list <Jeton> jetonPlaced_joueur1 ;
    list <Jeton> jetonPlaced_joueur2 ;
  public :
    //constructeur
    Backend();
    int nombre_element_liste(int joueur) ;
    Jeton DeterminerPositionXJeton(int val_potentio) ;
    int DeterminerPositionYJeton(int x) ;
    void PlacerJetonGrille (Jeton jeton , int joueur) ;
    int TestVictory(int joueur) ;

} ;


#endif
