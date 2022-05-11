#include "potentio.h"
//constructeur
Potentio::Potentio(int numPin) {
  pinMode(this->numPin, INPUT); // BP est une broche d'entree
  this->etat = LOW;
}

//Getter
int Potentio::getEtat() {
  return analogRead(this->numPin) ;
}

// Permet de determiner sur quelle colonne le joueur souhaite poser
// son jeton en fonction de la valeur renvoyée par le potentiometre
int Potentio::determinerColonne(int etat) {
  int colonne = 0 ;
  if (etat >= 7 && etat < 134) colonne = 1 ;
  else if (etat >= 134 && etat < 260) colonne = 2 ;
  else if (etat >= 261 && etat < 387) colonne = 3 ;
  else if (etat >= 388 && etat < 514) colonne = 4 ;
  else if (etat >= 515 && etat < 641) colonne = 5 ;
  else if (etat >= 642 && etat < 768) colonne = 6 ;
  else if (etat >= 769 && etat < 895) colonne = 7 ;
  else if (etat >= 896 && etat < 1044) colonne = 8 ;
  return colonne;
}
