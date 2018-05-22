#pragma once
#include "Board.h"
#include <string>

class Player {
    public:
    newChar player_char;
	virtual const string name() const =0;
	virtual const Coordinate play(const Board& board)=0;

	newChar getChar(){
	    return player_char;
	}
};
