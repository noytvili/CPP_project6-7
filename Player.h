#pragma once
#include "Board.h"
#include <string>

class Player {
    public :
    char myChar;
	virtual const string name() const=0 ;
	virtual const Coordinate play(const Board& board)=0;
    void setChar(char c) {myChar = c;}

	char getChar() const{
	    return myChar;
	}
};
