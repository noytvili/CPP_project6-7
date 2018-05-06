#include "Board.h"
#include <iostream>
using namespace std;

Board:: Board(int n){ //constructor
    size = n;
    board = new newChar*[size];  //allocBoard
	for (int i = 0; i < size; i++){
		board[i] = new newChar[size];
    }
}

Board:: Board(const Board& b1){ //copy constructor
    size = b1.size;
    board = new newChar*[size];  //allocBoard
	for (int i = 0; i < size; i++){
		board[i] = new newChar[size];
        for (int j = 0; j < size; j++) {
            board[i][j] = b1.board[i][j];
        }
    }
}


int Board:: getSize(){
    return size;
}

 newChar Board::operator[](const Pair &p) const {  //לקריאה בלבד
    //cout << "c";
    return board[p.get_i()][p.get_j()];
}

 newChar& Board::operator[](const Pair &p) { //לשנות את הערך
    if ((p.get_i() >= size || p.get_i() < 0) || (p.get_j() >= size || p.get_j() < 0)){
        throw IllegalCoordinateException(p);
    }
        return board[p.get_i()][p.get_j()];
}

Board& Board::operator= (char c){
     Board boradNew(*this);
    if(c!='X' && c!='O' && c!='.'){
        throw IllegalCharException(c);
    }
    else{
	   delete[] board;
        for(int i = 0; i < size; i++)
            for(int j = 0; j < size; j++)
                boradNew.board[i][j] = c;
    }
    this->board=boradNew.board;
    return *this;
}

Board& Board::operator=(const Board& b1){
     if (this==&b1){
            return *this;
     }
        Board boradNew(b1);
            this->board=boradNew.board;

            return *this;
        }
    

Board:: ~Board(){  //distructor
    for (int i = 0; i < size; i++) //free
	    delete[] board[i];
	delete[] board;
}
