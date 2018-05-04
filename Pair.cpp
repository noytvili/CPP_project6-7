#include <iostream>
#include "Pair.h"
using namespace std;

    
    //  pair :: pair(){ //constuctor
    //     i=0;
    //     j=0;
    // }
    
Pair :: Pair(int x, int y){ //constuctor
    i=x;
    j=y;
}
    
int Pair :: get_i() const{
    return i;
}    
    
int Pair :: get_j() const{
    return j;
}      



Pair& Pair:: operator= (const Pair& p){
    this->i = p.get_i();
    this->j = p.get_j();
    return *this;
}
