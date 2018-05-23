#include <iostream>
//#include "IllegalCoordinateException.cpp"
//#include "IllegalCharException.cpp"

using namespace std;

class newChar{
    private :
        
    
    public :
    char c;
        friend ostream& operator<< (ostream& os, const newChar& nc);
        newChar();
        newChar& operator= (const char c1);
        char& operator= (const newChar& c1);
         bool operator== (   char c2);
         bool operator!= (  char c2);
        bool operator== (  newChar c2);
        bool operator!= ( newChar c2);
};
  
    inline ostream& operator<< (ostream& os, const newChar& nc){
    return os << nc.c;
    }
