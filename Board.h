#include <iostream>
#include "newChar.h"
#include "IllegalCoordinateException.cpp"
#include "IllegalCharException.cpp"

using namespace std;

class Board{
    private :
        int Size;
    public :
        newChar**board;
        Board(int n); //constructor
        Board(const Board& b1); // copyConstructor
       // ~Board(); //destructor
        int size();
    
         newChar operator[](const Coordinate &p) const;
         newChar& operator[](const Coordinate &p);
         Board& operator= (char c);
         Board& operator=(const Board& b1);
         //char operator= (const Board& b1);
    //----------------------------------

    // friend global IO operators

    //----------------------------------

    //  friend istream& operator>> (istream& input,  Board& b);  // (cin)
};

    inline ostream &operator<<(ostream &os, Board b) {  //toString (cout)
        for (int i = 0; i < b.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                os << b.board[i][j];
            }
                        os<<endl;
        }
        return os;
    }
