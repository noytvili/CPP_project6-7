#include <iostream>
using namespace std;

class Coordinate{
    private:
        int i;
        int j;
        
    public:
       // pair();
        Coordinate(int x, int y);
        int get_i() const;
        int get_j() const;
        Coordinate& operator= (const Coordinate& p);
    
};


    
    
