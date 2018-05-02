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
