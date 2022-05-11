#include <Arduino.h>
#include <iostream>
#include <string>
#include <U8x8lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
using namespace std;

class Ecran {


  public :
    //constructeur
    Ecran(U8X8_SH1107_SEEED_128X128_HW_I2C u8x8);
    void afficherDebut();
    void choisirJoueur();
    void nouvellePartie();
    void win(int num);
    void Joueur(int num);
    //Getter
    // Setter
    // void setEtat();
  private :
    int numPin;
    U8X8_SH1107_SEEED_128X128_HW_I2C ecran;
};
