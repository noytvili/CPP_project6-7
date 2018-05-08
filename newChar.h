#include <iostream>
//#include "IllegalCoordinateException.cpp"
//#include "IllegalCharException.cpp"


using namespace std;

class newChar{
  
    private :
        char c;
    
    public :
        friend ostream& operator<< (ostream& os, const newChar& nc);
        newChar();
        newChar(char c1);
        newChar& operator= (const char c1);
        operator char() ;
        
};

    inline ostream& operator<< (ostream& os, const newChar& nc){ //cout
    return os << nc.c;
}
