#include <iostream>
using namespace std;

class Pair{
    private:
        int i;
        int j;
        
    public:
       // pair();
        Pair(int x, int y);
        int get_i() const;
        int get_j() const;
        Pair& operator= (const Pair& p);
    
};


    
    
