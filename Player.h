#pragma once
#include "Board.h"
#include <string>

class Player {
    public:
    char player_char;
	virtual const string name() const =0;
	virtual const Coordinate play(const Board& board)=0;

	char getChar(){
	    return player_char;
	}
};
