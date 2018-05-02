
#include "Board.h"
#include <iostream>
using namespace std;

Board:: Board(int n){ //constructor
    size = n;
    board = new char*[size];  //allocBoard
	for (int i = 0; i < size; i++){
		board[i] = new char[size];
        for (int j = 0; j < size; j++) {
            board[i][j] = '.';
        }
    }
}

// Board:: ~Board(){  //distructor
//     for (int i = 0; i < size; i++) //free
// 	    delete[] board[i];
// 	delete[] board;
// }

int Board:: getSize(){
    return size;
}

 char Board::operator[](Pair &p) const {  //לקריאה בלבד
    //cout << "c";
    return board[p.get_i()][p.get_j()];
}

 char& Board::operator[](Pair &p) { //לשנות את הערך
    if ((p.get_i() > size || p.get_i() < size) || (p.get_j() > size || p.get_j() < size)){
        throw string("Illegal coordinate: "+to_string(p.get_i()) + to_string(p.get_j()));
    }
    return board[p.get_i()][p.get_j()];
}

Board& Board::operator= (char c){
    if(c!='X' || c!='O' || C!='.'){
        throw IllegalCharException();
    }
    else{
        board[p.get_i()][p.get_j()]=c;
    }
}
