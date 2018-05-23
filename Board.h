#include <iostream>
#include "newChar.h"
//include "Coordinate.h"
#include "IllegalCoordinateException.cpp"
//#include "IllegalCharException.cpp"
#pragma once
using namespace std;

class Board{
    private :
        int Size;

    public :
        newChar**board;
        Board(int n); //constructor
        Board(const Board& b1); // copyConstructor
        int size() const;
    friend ostream &operator<<(ostream &os, const Board& b);
         newChar operator[](const Coordinate &p) const;
         newChar& operator[](const Coordinate &p);
         Board& operator= (char c);
         Board& operator=(const Board& b1);
         bool operator==(const Board &b1) const;
         void clear();
         ~Board(); //destructor
    
    //----------------------------------
    // friend global IO operators
    //----------------------------------
    //  friend istream& operator>> (istream& input,  Board& b);  // (cin)
};

    inline ostream &operator<<(ostream &os, const Board& b) {  //toString (cout)
        for (int i = 0; i < b.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                os << b.board[i][j];
            }
                        os<<endl;

        }
        return os;
    }

 
