#include "backend.h"
#include <iostream>
#include <string>
//constructeur
Backend::Backend() {

};

//determine avec le potentiometre la colonne (alors X) ou le jeton sera place
Jeton Backend::DeterminerPositionXJeton(int colonne) {

  Jeton jeton(0, 0);


  jeton.setX(colonne);

  return jeton ;
}

int Backend::nombre_element_liste(int joueur) {
  if (joueur == 1) return jetonPlaced_joueur1.size() ;
  else return jetonPlaced_joueur2.size() ;
}
//determine la ligne sur laquelle le jeton sera placee selon la disponibilite sur la colonne selectionee avec le potentiometre
int Backend::DeterminerPositionYJeton(int x) {
  int Y_max = 0 ;
  //iterateur de liste et on cherche le max Y de chaque liste
  if (!jetonPlaced_joueur1.empty()) {
    for (list<Jeton>::iterator it = this->jetonPlaced_joueur1.begin() ; it != this->jetonPlaced_joueur1.end(); it++) {
      if (it->getX() == x) {
        if (it->getY() > Y_max) Y_max = it->getY();
      }
    }
  }
  else {
    Y_max = 0;
  }

  //on cherche le max dans la liste 2
  if (!jetonPlaced_joueur2.empty()) {
    for (list<Jeton>::iterator it = jetonPlaced_joueur2.begin() ; it != jetonPlaced_joueur2.end(); it++) {
      if (it->getX() == x) {
        if (it->getY() > Y_max) Y_max = it->getY() ;
      }
    }
  }
  else {
    Y_max = 0;
  }
  return Y_max + 1;
}


//fonction gardant en memoire le placement du jeton de la part d'un joueur
void Backend::PlacerJetonGrille (Jeton jeton , int joueur) {
  if (joueur == 1) {
    (this->jetonPlaced_joueur1).push_back(jeton);
  }
  else //joueur=2
  {
    (this->jetonPlaced_joueur2).push_back(jeton);
  }
}



//fonction testant la victoire a chaque fois qu'un jeton est placee en testant a doite a gauche et en bas (et eventuellement en diagonal si 4 jeton de meme couleur sont consecutifs)
//returns 1 if end of game 0 otherwise
int Backend::TestVictory(int joueur) {
  int win = 0 ;
  int cpt_colonne = 1;
  int cpt_ligne = 1 ;

  if (joueur == 1) {
    ;
    for (list<Jeton>::iterator it = jetonPlaced_joueur1.begin() ; it != jetonPlaced_joueur1.end(); it++) {
      //victoire par colonne
      if  (it->getY() == (((jetonPlaced_joueur1.end()->getY() - 1)) && ((it->getX() == jetonPlaced_joueur1.end()->getX()))))
      {
        //win=1;
        cpt_colonne = cpt_colonne + 1;
        for (list<Jeton>::iterator it2 = jetonPlaced_joueur1.begin() ; it2 != jetonPlaced_joueur1.end(); it2++) {
          if ((it2->getY() == (it->getY() - 1)) && (it2->getX() == it->getX()))
          {
            cpt_colonne = cpt_colonne + 1;
            for (list<Jeton>::iterator it3 = jetonPlaced_joueur1.begin() ; it3 != jetonPlaced_joueur1.end(); it3++) {
              if ((it3->getY() == (it2->getY() - 1)) && (it3->getX() == it2->getX()))
              {
                cpt_colonne = cpt_colonne + 1;
              }
            }
          }
        }
      }
    }

    for (list<Jeton>::iterator it = jetonPlaced_joueur1.begin() ; it != jetonPlaced_joueur1.end(); it++) {
      //victoire par ligne ( vers la droite )
      if ((it->getX() == (jetonPlaced_joueur1.end()->getX() + 1)) && (it->getY() == jetonPlaced_joueur1.end()->getY()))
      {
        cpt_ligne = cpt_ligne + 1 ;
        for (list<Jeton>::iterator it2 = jetonPlaced_joueur1.begin() ; it2 != jetonPlaced_joueur1.end(); it2++) {
          if ((it2->getX() == (it->getX() + 1)) && (it2->getY() == it->getY()))
          {
            cpt_ligne = cpt_ligne + 1 ;
            for (list<Jeton>::iterator it3 = jetonPlaced_joueur1.begin() ; it3 != jetonPlaced_joueur1.end(); it3++) {
              if ((it3->getX() == (it2->getX() + 1)) && (it3->getY() == it2->getY()))
              {
                cpt_ligne = cpt_ligne + 1 ;
              }
            }
          }
        }
      }
    }
    for (list<Jeton>::iterator it = jetonPlaced_joueur1.begin() ; it != jetonPlaced_joueur1.end(); it++) {
      //victoire par ligne ( vers la gauche )
      if ((it->getX() == (jetonPlaced_joueur1.end()->getX() - 1)) && (it->getY() == jetonPlaced_joueur1.end()->getY()))
      {
        cpt_ligne = cpt_ligne + 1 ;
        for (list<Jeton>::iterator it2 = jetonPlaced_joueur1.begin() ; it2 != jetonPlaced_joueur1.end(); it2++) {
          if ((it2->getX() == (it->getX() - 1)) && (it2->getY() == it->getY()))
          {
            cpt_ligne = cpt_ligne + 1 ;
            for (list<Jeton>::iterator it3 = jetonPlaced_joueur1.begin() ; it3 != jetonPlaced_joueur1.end(); it3++) {
              if ((it3->getX() == (it2->getX() - 1)) && (it3->getY() == it2->getY()))
              {
                cpt_ligne = cpt_ligne + 1 ;
              }
            }
          }
        }
      }
    }

    if (cpt_colonne >= 4 || cpt_ligne >= 4) {
      win = 1;
    }
    //}
  }

  if (joueur == 2) {
    for (list<Jeton>::iterator it = jetonPlaced_joueur2.begin() ; it != jetonPlaced_joueur2.end(); it++) {
      //victoire par colonne
      if ((it->getY() == (jetonPlaced_joueur2.end()->getY() - 1)) && (it->getX() == jetonPlaced_joueur2.end()->getX()))
      {
        cpt_colonne = cpt_colonne + 1;
        for (list<Jeton>::iterator it2 = jetonPlaced_joueur2.begin() ; it2 != jetonPlaced_joueur2.end(); it2++) {
          if ((it2->getY() == (it->getY() - 1)) && (it2->getX() == it->getX()))
          {
            cpt_colonne = cpt_colonne + 1;
            for (list<Jeton>::iterator it3 = jetonPlaced_joueur2.begin() ; it3 != jetonPlaced_joueur2.end(); it3++) {
              if ((it3->getY() == (it2->getY() - 1)) && (it3->getX() == it2->getX()))
              {
                cpt_colonne = cpt_colonne + 1;
              }
            }
          }
        }
      }
    }

    for (list<Jeton>::iterator it = jetonPlaced_joueur2.begin() ; it != jetonPlaced_joueur2.end(); it++) {
      //victoire par ligne ( vers la droite )
      if ((it->getX() == (jetonPlaced_joueur2.end()->getX() + 1)) && (it->getY() == jetonPlaced_joueur2.end()->getY()))
      {
        cpt_ligne = cpt_ligne + 1 ;
        for (list<Jeton>::iterator it2 = jetonPlaced_joueur2.begin() ; it2 != jetonPlaced_joueur2.end(); it2++) {
          if ((it2->getX() == (it->getX() + 1)) && (it2->getY() == it->getY()))
          {
            cpt_ligne = cpt_ligne + 1 ;
            for (list<Jeton>::iterator it3 = jetonPlaced_joueur2.begin() ; it3 != jetonPlaced_joueur2.end(); it3++) {
              if ((it3->getX() == (it2->getX() + 1)) && (it3->getY() == it2->getY()))
              {
                cpt_ligne = cpt_ligne + 1 ;
              }
            }
          }
        }
      }
    }
    for (list<Jeton>::iterator it = jetonPlaced_joueur2.begin() ; it != jetonPlaced_joueur2.end(); it++) {
      //victoire par ligne ( vers la gauche )
      if ((it->getX() == (jetonPlaced_joueur2.end()->getX() - 1)) && (it->getY() == jetonPlaced_joueur2.end()->getY()))
      {
        cpt_ligne = cpt_ligne + 1 ;
        for (list<Jeton>::iterator it2 = jetonPlaced_joueur2.begin() ; it2 != jetonPlaced_joueur2.end(); it2++) {
          if ((it2->getX() == (it->getX() - 1)) && (it2->getY() == it->getY()))
          {
            cpt_ligne = cpt_ligne + 1 ;
            for (list<Jeton>::iterator it3 = jetonPlaced_joueur2.begin() ; it3 != jetonPlaced_joueur2.end(); it3++) {
              if ((it3->getX() == (it2->getX() - 1)) && (it3->getY() == it2->getY()))
              {
                cpt_ligne = cpt_ligne + 1 ;
              }
            }
          }
        }
      }
    }
    if (cpt_colonne >= 4 || cpt_ligne >= 4) {
      win = 2;
    }
    //}
  }
  return win ;
}
