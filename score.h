#include <list>
using namespace std ; 
#include "partie.h"


#ifndef _SCORE_
#define _SCORE_



class Score : public Partie {
	private : 
		int meilleur_score  () ;   
	public : 
		//constructeur 
		Score() ; 
		void CompareScore(Partie game) ; 

  	// operateur d'affectation 
  	/*Score & operator = (const Score & autre ) {
      	meilleur_score=autre.meilleur_score; 
    	return (*this);
 	 }*/
	
} ; 

#endif
