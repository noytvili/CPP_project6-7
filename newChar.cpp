#include <iostream>
#include "newChar.h"
//#include "IllegalCoordinateException.cpp"
#include "IllegalCharException.cpp"


using namespace std;


    newChar::newChar(){ //constructor
     c='.';   
    }
    
    newChar::newChar(char c1){
        c=c1;
    }
    
  
    newChar& newChar::operator= (const char c1){ // newChar = char
        if(c1!='X' && c1!='O' && c1!='.'){
            throw IllegalCharException(c1);
        }
        else{
            c=c1;
        }
        return *this;
    }

    newChar::operator char() { //casting operator from nweChar to char
    return c;
    }
    
    bool newChar::operator==(char c1) const {
        return c==c1;
    }
    
    bool newChar::operator!=(char c1) const {
        return c!=c1;

    }
    
    bool Piece::operator==(const newChar &c1) const {
        return c==c1.c;

        
    }
    
    bool Piece::operator!=(const newChar &c1) const {
        return c!=c1.c;
        
    }
