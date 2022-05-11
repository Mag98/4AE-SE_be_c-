#include "jeton.h"

//constructeur
Jeton::Jeton(int x , int y) {

  this->X = x ;
  this->Y = y ;

}

//setter
void Jeton::setX(int x) {
  this->X = x ;
}

void Jeton::setY(int y) {
  this->Y = y ;
}

//getter
int Jeton::getX(void) {
  return this->X;
}

int Jeton::getY(void) {
  return this->Y;
}

int Jeton::getIDplayer(void) {
  return this->idJoueur ;
}
