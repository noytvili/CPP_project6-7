#include <iostream>
#include "Pair.h"

using namespace std;


class Board{
    private :
        int size;

    public :
        char **board;
        Board(int n); //constructor
        //~Board(); //destructor
        int getSize();
         char operator[](Pair &p) const;
         char& operator[](Pair &p);
          Board& operator= (Pair &p,char c);
    
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

 
