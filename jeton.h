#ifndef JETON
#define JETON

class Jeton {
  private :
    int X ;
    int Y ;
    int idJoueur ; //prend valeur 1 ou 2
  public :
    //constructeur
    Jeton(int x , int y) ;
    //setter
    void setX(int x);
    void setY(int y);
    //getter
    int getX(void) ;
    int getY(void) ;
    int getIDplayer(void) ;

};

#endif
