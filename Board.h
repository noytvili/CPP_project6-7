#include <iostream>
using namespace std;


class Board{
    private :
        int size;

    public :
        char **board;
		void allocBoard(int size); // size x size הקצאת לוח בגודל
		void freeBoard(int size); // שחרור לוח
        Board(int n); //constructor
        ~Board(int n); //disstructor
    
    //----------------------------------
    // friend global IO operators
    //----------------------------------
    friend ostream& operator<< (ostream& os, const Board& b);  //toString (cout)
    //  friend istream& operator>> (istream& input,  Board& b);  // (cin)
        
};

    inline ostream &operator<<(ostream &os, Board const &b) {  //toString (cout)
        for (int i = 0; i < b.size; i++) {
            for (int j = 0; j < b.size; j++) {
                os << to_string(b[i][j]);
            }
        }
        return os;
    }
