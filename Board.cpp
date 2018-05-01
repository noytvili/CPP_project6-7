
#include "Board.h"
#include <iostream>
using namespace std;

Board:: Board(int n){ //constructor
    size = n-1;
    board b = new char*[size];  //allocBoard
	for (int i = 0; i < size; i++)
		board[i] = new char[size];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = '.';
        }
    }
}

~Board:: Board(int n){  //distructor
    for (int i = 0; i < size; i++) //free
	    delete [] board[i];
	delete [] board;
}

int Board::operator[](int index) const {  //לקריאה בלבד
    //cout << "c";
    return Board[index];
}

int& Board::operator[](int index) { //לשנות את הערך
    //cout << "r";
    return Board[index];
}
