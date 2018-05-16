#include <iostream>
#include "Coordinate.h"
using namespace std;

    
    //  pair :: pair(){ //constuctor
    //     i=0;
    //     j=0;
    // }
    
Coordinate :: Coordinate(int x, int y){ //constuctor
    i=x;
    j=y;
}
    
int Coordinate :: get_i() const{
    return i;
}    
    
int Coordinate :: get_j() const{
    return j;
}      



Coordinate& Coordinate:: operator= (const Pair& p){
    this->i = p.get_i();
    this->j = p.get_j();
    return *this;
}
