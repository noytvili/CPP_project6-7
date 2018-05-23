#include <exception>
#pragma once
using namespace std;


class IllegalCharException{
    private:
      const  char c;
    public:
     IllegalCharException(const char c) : c(c){}
    


// Throw an object:
char theChar() const {
        return c;
    }

};
