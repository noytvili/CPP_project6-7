#include "Board.h"
#include <iostream>
using namespace std;

Board:: Board(int n){ //constructor
    Size = n;
    board = new newChar*[Size];  //allocBoard
	for (int i = 0; i < Size; i++){
		board[i] = new newChar[Size];
    }
}

Board:: Board(const Board& b1){ //copy constructor
int i,j;
    Size = b1.Size;
    board = new newChar*[Size];  //allocBoard
	for (i = 0; i < Size; i++){
		board[i] = new newChar[Size];
        for (j = 0; j < Size; j++) 
           // board[i][j] = b1.board[i][j];
           board[i][j] = newChar(b1.board[i][j]);
	}

}

int Board:: size() const{
    return Size;
}

 newChar Board::operator[](const Coordinate &p) const {  //לקריאה בלבד
    return board[p.get_i()][p.get_j()];
}

 newChar& Board::operator[](const Coordinate &p) { //לשנות את הערך
    if ((p.get_i() >= Size || p.get_i() < 0) || (p.get_j() >= Size || p.get_j() < 0)){
        throw IllegalCoordinateException(p);
    }
        return board[p.get_i()][p.get_j()];
}

Board& Board::operator= (char c){
    if(c!='X' && c!='O' && c!='.'){
        throw IllegalCharException(c);
    }
    else{
        for(int i = 0; i < Size; i++)
            for(int j = 0; j < Size; j++)
                board[i][j] = c;
    }
    return *this;
}

Board& Board::operator=(const Board& b1){
    
     if (this==&b1){
            return *this;
     }

    clear();
    Size = b1.Size;
    board = new newChar*[Size];  //allocBoard
	for (int i = 0; i < Size; i++){
		board[i] = new newChar[Size];
        for (int j = 0; j < Size; j++) 
            board[i][j] = b1.board[i][j];
        
    }
    return *this;
        }
    
bool Board::operator==(const Board &b1) const {
    if (Size != b1.Size)
        return false;
    for (int i = 0; i < Size; ++i) {
        for (int j = 0; j < Size; ++j) {
            if (board[i][j] != b1.board[i][j])
                return false;
        }
    }
    return true;
}


void Board:: clear(){  //distructor
    for (int i = 0; i < Size; i++) //free
	    delete[] board[i];
	delete[] board;
}

Board:: ~Board(){  //distructor
    clear();
}
