#include "ecran.h"
#include <string>
//constructeur
Ecran::Ecran(U8X8_SH1107_SEEED_128X128_HW_I2C u8x8) {
  this->ecran = u8x8;
  ecran.begin();
  ecran.setPowerSave(0);
}
//Gestion de l'affichage de début de partie
void Ecran::afficherDebut() {
  ecran.begin();
  ecran.setPowerSave(0);
  ecran.setFont(u8x8_font_chroma48medium8_r);
  ecran.drawString(0, 8, "Debut partie!");
  delay(3000);
}

//gestion d'affichage des explications joueur
void Ecran::choisirJoueur() {
  ecran.begin();
  ecran.setPowerSave(0);
  ecran.setFont(u8x8_font_chroma48medium8_r);
  ecran.drawString(0, 5, "  Le joueur 1 ");
  ecran.drawString(0, 6, "sera en rouge ");
  ecran.drawString(0, 7, "l'autre en jaune");
  ecran.drawString(0, 8, "    Prets ?!");
  delay(4000);
  ecran.begin();
  ecran.setFont(u8x8_font_px437wyse700b_2x2_r);
  ecran.drawString(0, 10, "   5");
  delay(1000);
  ecran.drawString(0, 10, "   4");
  delay(1000);
  ecran.drawString(0, 10, "   3");
  delay(1000);
  ecran.drawString(0, 10, "   2");
  delay(1000);
  ecran.drawString(0, 10, "   1");
  delay(1000);
  ecran.begin();
  ecran.setFont(u8x8_font_chroma48medium8_r);
  ecran.drawString(0, 8, "Debut Partie!");
  delay(5000);
  ecran.begin();
  ecran.setPowerSave(0);
}

// gestion d'affichage du joueur en train de jouer
void Ecran::Joueur(int num) {
  ecran.setFont(u8x8_font_chroma48medium8_r);

  if (num == 1) {
    ecran.drawString(0, 8, "JOUEUR 1");
  }
  if (num == 2) {
    ecran.drawString(0, 8, "JOUEUR 2 ");
  }
}

//gestion d'affichage lors d'une victoire
void Ecran::win(int num) {
  ecran.begin();
  ecran.setPowerSave(0);
  ecran.setFont(u8x8_font_chroma48medium8_r);

  if (num == 1) {
    ecran.drawString(0, 8, "JOUEUR 1 GAGNE!");
  }
  if (num == 2) {
    ecran.drawString(0, 8, "JOUEUR 2 GAGNE!");
  }
}

//gestion d'affichage pour commencer une nouvelle partie
void Ecran::nouvellePartie() {
  ecran.begin();
  ecran.setPowerSave(0);
  ecran.setFont(u8x8_font_chroma48medium8_r);
  ecran.drawString(0, 8, "NOUVELLE PARTIE!");
}
