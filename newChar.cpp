#include <iostream>
#include "newChar.h"
//#include "IllegalCoordinateException.cpp"
#include "IllegalCharException.cpp"


using namespace std;


    newChar::newChar(){
     c='.';   
    }
    
    newChar& newChar::operator= (const char c1){
        if(c1!='X' && c1!='O' && c1!='.'){
            throw IllegalCharException(c1);
        }
        else{
            c=c1;
        }
        return *this;
    }
    
    newChar& newChar::operator= (const newChar& c1){
        c = c1.c;
        return *this;
    }

