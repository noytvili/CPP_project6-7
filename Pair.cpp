#include <iostream>
#include "Pair.h"
using namespace std;

Pair :: Pair(int x, int y){ //constuctor
    i = x;
    j = y;
}

Pair :: 

int Pair :: get_i(){
    return i;
}    


int Pair :: get_j(){
    return j;
}      

void pair :: operator =(pair &p){
    i=p.get_i();
    j=p.get_j();

}

Pair& Pair:: operator= (const Pair& p){
    this->i = p.get_i();
    this->j = p.get_j();
    return *this;
}
