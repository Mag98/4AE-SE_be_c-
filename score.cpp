#include "score.h"
//score : keeps in memory the best score (most number of moves)


Score::Score(){

}


void Score::CompareScore(Partie game) { 
	if(game.getNombre_Tours() > this->nombre_tours){
		this->nombre_tours = game.getNombre_Tours()  ; 
		this->gagnant = game.getWinner()  ; 
	}

}
