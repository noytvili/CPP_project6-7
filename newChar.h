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
        bool operator==(char c) const;
        bool operator!=(char c) const;
        bool operator==(const newChar &c1) const;
        bool operator!=(const newChar &c1) const;




        
};

    inline ostream& operator<< (ostream& os, const newChar& nc){ //cout
    return os << nc.c;
}
