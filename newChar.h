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
        bool operator== ( newChar c1,  char c2);
        bool operator!= ( newChar c1,  char c2);
        bool operator== ( newChar c1,  newChar c2);
        bool operator!= ( newChar c1,  newChar c2);
};


    inline bool operator== ( newChar c1,  char c2){
        return c1.c==c2;
    } 
    
    inline bool operator!= ( newChar c1,  char c2){
        return c1.c!=c2;
    }
    
    inline bool operator== ( newChar c1,  newChar c2){
        return c1.c==c2.c;
    } 
    
    inline bool operator!= ( newChar c1,  newChar c2){
        return c1.c!=c2.c;
    }
    
    inline ostream& operator<< (ostream& os, const newChar& nc){
    return os << nc.c;
    }
