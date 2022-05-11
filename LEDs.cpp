#include "LEDs.h"


// exceptions
enum err {masque_err};

//constructeur
LEDs::LEDs(GroveTwoRGBLedMatrixClass matrice) {
  this->matrix = matrice;
  (this->matrix).resetDevice();
}
//Cette fonction permet de visionner le placement du jeton: en fonctoin de la colonne une image différente est renvoyée
void LEDs::allumerColonne(int colonne) {
  uint64_t point[] = {
    0xffffffffffffffff,
    0xffffffffffffffff,
    0xffffffffffffffff,
    0xffffffffffffffff,
    0xffffffffffffffff,
    0xffffffffffffffff,
    0xffffffffffffffff,
    0xffffffffffffffff,
  };
  (this->matrix).resetDevice();

  if (colonne == 1)
  {
    uint64_t point[] = {
      0xfffffffffffffffe,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
    };
    (this->matrix).deleteFrames();
    (this->matrix).displayFrames(point, 100, false, 1);
  }
  if (colonne == 2)
  {
    uint64_t point[] = {
      0xfffffffffffffeff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
    };
    (this->matrix).deleteFrames();
    (this->matrix).displayFrames(point, 100, false, 1);
  }

  if (colonne == 3)
  {
    uint64_t point[] = {
      0xfffffffffffeffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
    };
    (this->matrix).deleteFrames();
    (this->matrix).displayFrames(point, 100, false, 1);
  }

  if (colonne == 4)
  {
    uint64_t point[] = {
      0xfffffffffeffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
    };
    (this->matrix).deleteFrames();
    (this->matrix).displayFrames(point, 100, false, 1);
  }

  if (colonne == 5)
  {
    uint64_t point[] = {
      0xfffffffeffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
    };
    (this->matrix).deleteFrames();
    (this->matrix).displayFrames(point, 100, false, 1);
  }

  if (colonne == 6)
  {
    uint64_t point[] = {
      0xfffffeffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
    };
    (this->matrix).deleteFrames();
    (this->matrix).displayFrames(point, 100, false, 1);
  }

  if (colonne == 7)
  {
    uint64_t point[] = {
      0xfffeffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
    };
    (this->matrix).deleteFrames();
    (this->matrix).displayFrames(point, 100, false, 1);
  }

  if (colonne == 8)
  {
    uint64_t point[] = {
      0xfeffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
      0xffffffffffffffff,
    };
    (this->matrix).displayFrames(point, 100, false, 1);
  }


}
// Cette fonction gère l'affichage global de la grille : a chaque ajout d'un jeton,
// un masque est appliqué sur l'image de la grille
// C'est aussi ici ou se trouve notre gestion d'exception : si le jeton est hors de
//la grille cela affiche un message dans le serial
void LEDs::affichageJeton(uint64_t* grille, int x, int y, int couleur) {
  uint64_t masque [1] ;
  if ((couleur > 2) || (x < 0) || (y > 8)) {
    throw masque_err;
  }
  try {
    if (couleur == 1) {
      if (x == 1) {
        masque[0] = 0xffffffffffffff00 ;
      }
      if (x == 2) {
        masque[0] = 0xffffffffffff00ff ;
      }
      if (x == 3) {
        masque[0] = 0xffffffffff00ffff ;
      }
      if (x == 4) {
        masque[0] = 0xffffffff00ffffff ;
      }
      if (x == 5) {
        masque[0] = 0xffffff00ffffffff ;
      }
      if (x == 6) {
        masque[0] = 0xffff00ffffffffff ;
      }
      if (x == 7) {
        masque[0] = 0xff00ffffffffffff ;
      }
      if (x == 8) {
        masque[0] = 0x00ffffffffffffff ;
      }


    }
    else if (couleur == 2) {
      if (x == 1) {
        masque[0] = 0xffffffffffffff18 ;
      }
      if (x == 2) {
        masque[0] = 0xffffffffffff18ff ;
      }
      if (x == 3) {
        masque[0] = 0xffffffffff18ffff ;
      }
      if (x == 4) {
        masque[0] = 0xffffffff18ffffff ;
      }
      if (x == 5) {
        masque[0] = 0xffffff18ffffffff ;
      }
      if (x == 6) {
        masque[0] = 0xffff18ffffffffff ;
      }
      if (x == 7) {
        masque[0] = 0xff18ffffffffffff ;
      }
      if (x == 8) {
        masque[0] = 0x18ffffffffffffff ;
      }
    }
  }
  catch (err er) {
    switch (er) {
      case masque_err:
        Serial.println("Exception données du masquage");
        break;
    }
  }
  grille[8 - y] &= masque[0];
  (this->matrix).displayFrames(grille, 100000, true, 1);
}
