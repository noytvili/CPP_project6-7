#include <exception>
#include <string>
#include "Pair.h"

using namespace std;



class IllegalCoordinateException{
    private:
        const Pair &p;
    public:
        IllegalCoordinateException(const  Pair &p) : p(p){}


string theCoordinate() const{
    return string(to_string(p.get_i()) + "," + to_string(p.get_j()));
    
}
};
