#include <exception>
#include <string>
#include "Coordinate.h"
#pragma once

using namespace std;

class IllegalCoordinateException{
    private:
        const Coordinate &c;
    public:
        IllegalCoordinateException(const  Coordinate &c) : c(c){}

string theCoordinate() const{
    return string(to_string(c.get_i()) + "," + to_string(c.get_j()));
    
}
};
