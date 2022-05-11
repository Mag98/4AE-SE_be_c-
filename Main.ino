#include <grove_two_rgb_led_matrix.h>
#include "score.h"
#include "potentio.h"
#include "ecran.h"
//#include "grove_two_rgb_led_matrix.h"
#include "LEDs.h"

GroveTwoRGBLedMatrixClass matrice;

U8X8_SH1107_SEEED_128X128_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);
void waitForMatrixReady() {
  delay(1000);
}


void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Test ARDUINO");
  waitForMatrixReady();
  uint16_t VID = 0;
  VID = matrice.getDeviceVID();
}
int timer = 0;
int tour = 0;
int joueur = 0;
Potentio potentio(A0);
LEDs led(matrice);
Backend back;
Partie partie;
Score score;
Ecran ecran(u8x8);
int fin = 0;
Jeton jeton(0, 0);
int colonne , ligne ;


void loop() {

  ecran.afficherDebut();
  ecran.choisirJoueur();
  tour = 0;
  uint64_t grille[] = {
    0xffffffffffffffff,
    0xffffffffffffffff,
    0xffffffffffffffff,
    0xffffffffffffffff,
    0xffffffffffffffff,
    0xffffffffffffffff,
    0xffffffffffffffff,
    0xffffffffffffffff,
  };

  while (fin == 0) {
    tour++;
    if ((tour % 2) != 0) joueur = 1;
    else joueur = 2;
    ecran.Joueur(joueur);

    while (timer < 30) {
      led.allumerColonne(potentio.determinerColonne(potentio.getEtat()));
      Serial.println(timer);
      delay(5);
      timer = timer + 1;
    }
    timer = 0;
    colonne = potentio.determinerColonne(potentio.getEtat());
    jeton = back.DeterminerPositionXJeton(colonne);
    ligne = back.DeterminerPositionYJeton(colonne);
    jeton.setY(ligne);
    Serial.print(jeton.getX());
    Serial.print("***********");
    Serial.println(jeton.getY());
    back.PlacerJetonGrille(jeton, joueur);
    led.affichageJeton(grille, colonne, ligne, joueur);
    fin = back.TestVictory(joueur);
    Serial.println(tour);
    delay(5000);
  }
  ecran.win(joueur);
  partie.setGagnant(joueur);
  partie.CalculNombreTours(back);
  score.CompareScore(partie);
  delay(3000);
  ecran.nouvellePartie();
  delay(3000);

}
