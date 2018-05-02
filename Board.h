#include <iostream>
#include "newChar.h"
#include "IllegalCoordinateException.cpp"
#include "IllegalCharException.cpp"


using namespace std;


class Board{
    private :
        int size;

    public :
        newChar**board;
        Board(int n); //constructor
       // ~Board(); //destructor
        int getSize();
         newChar operator[](const Pair &p) const;
         newChar& operator[](const Pair &p);
         Board& operator= (char c);
         Board& operator=(const Board& b1);

    
    //----------------------------------
    // friend global IO operators
    //----------------------------------
    //  friend istream& operator>> (istream& input,  Board& b);  // (cin)
        
};

    inline ostream &operator<<(ostream &os, Board b) {  //toString (cout)
        for (int i = 0; i < b.getSize(); i++) {
            for (int j = 0; j < b.getSize(); j++) {
                os << b.board[i][j];
            }
                        os<<endl;

        }
        return os;
    }

 
