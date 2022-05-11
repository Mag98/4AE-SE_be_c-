#include "partie.h"


//constructeur
Partie::Partie() {

};

//setter
void Partie::setGagnant(int joueur) {
  this->gagnant = joueur ;
}

//getter
int Partie::getWinner(void) {
  return this->gagnant  ;
}

int Partie::getNombre_Tours(void) {
  return this->nombre_tours ;
}




//fonction calculant le nombre de tours dans la partie (c'est la longeur de la liste du joueur gagnant)
void Partie::CalculNombreTours(Backend back) {
  if (!this->gagnant) {
    if (this->gagnant == 1) {
      this->nombre_tours = back.nombre_element_liste(1) ;
    }
    else {//joueur 2
      this->nombre_tours = back.nombre_element_liste(2) ;
    }
  }
}
