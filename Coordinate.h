#include <iostream>
#include <string>
using namespace std;

class Coordinate{
    private:
        uint i;
        uint j;
        
    public:
       // pair();
        Coordinate(uint x, uint y);
        uint get_i() const;
        uint get_j() const;
        Coordinate& operator= (const Coordinate& p);
        friend ostream& operator<< (ostream& os, const Coordinate& c);
    
};

    inline ostream& operator<< (ostream& os, const Coordinate& c){
    return os << string(" ( " + to_string(c.get_i()) + "," + to_string(c.get_j()) + " ) " );
    }

    
    
