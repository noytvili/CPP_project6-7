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
        newChar& operator= (const char c1);
        newChar& operator= (const newChar& c1);

};

    inline ostream& operator<< (ostream& os, const newChar& nc){
    return os << nc.c;
}