#include <iostream>
#include "Coordinate.h"
using namespace std;

Coordinate :: Coordinate(uint x, uint y){ //constuctor
    i=x;
    j=y;
}
    
uint Coordinate :: get_i() const{
    return i;
}    
    
uint Coordinate :: get_j() const{
    return j;
}      

Coordinate& Coordinate:: operator= (const Coordinate& p){
    this->i = p.get_i();
    this->j = p.get_j();
    return *this;
}
