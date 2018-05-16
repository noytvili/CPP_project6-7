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
 int i,j;
    size = b1.size;
    board = new newChar*[size];  //allocBoard
	for (i = 0; i < size; i++){
		board[i] = new newChar[size];
        for (j = 0; j < size; j++) 
           // board[i][j] = b1.board[i][j];
           board[i][j] = newChar(b1.board[i][j]);
	}

}

int Board:: getSize() const{
    return size;
}

 newChar Board::operator[](const Coordinate &p) const {  //לקריאה בלבד
    return board[p.get_i()][p.get_j()];
}

 newChar& Board::operator[](const Coordinate &p) { //לשנות את הערך
    if ((p.get_i() >= size || p.get_i() < 0) || (p.get_j() >= size || p.get_j() < 0)){
        throw IllegalCoordinateException(p);
    }
        return board[p.get_i()][p.get_j()];
}

Board& Board::operator= (char c){
    if(c!='X' && c!='O' && c!='.'){
        throw IllegalCharException(c);
    }
    else{
        for(int i = 0; i < size; i++)
            for(int j = 0; j < size; j++)
                board[i][j] = c;
    }
    return *this;
}

Board& Board::operator=(const Board& b1){
    
     if (this==&b1){
            return *this;
     }

    clear();
    size = b1.size;
    board = new newChar*[size];  //allocBoard
	for (int i = 0; i < size; i++){
		board[i] = new newChar[size];
        for (int j = 0; j < size; j++) 
            board[i][j] = b1.board[i][j];
        
    }
    return *this;
        }
    
bool Board::operator==(const Board &b1) const {
    if (size != b1.size)
        return false;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (board[i][j] != b1.board[i][j])
                return false;
        }
    }
    return true;
}


void Board:: clear(){  //distructor
    for (int i = 0; i < size; i++) //free
	    delete[] board[i];
	delete[] board;
}

Board:: ~Board(){  //distructor
    clear();
}
