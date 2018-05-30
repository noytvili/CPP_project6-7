#include <iostream>
#include <fstream>
#include "newChar.h"
#include "IllegalCoordinateException.cpp"
#include <string>
#pragma once
using namespace std;

struct RGB {
    uint8_t red, green, blue;
    public:
        RGB() {}
        RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};

class Board{
    private :
        int Size;

    public :
        newChar**board;
        Board(int n); //constructor
        Board();
        Board(const Board& b1); // copyConstructor
        int size() const;
        friend ostream &operator<<(ostream &os, const Board& b);  //output
        friend istream &operator>>(istream &is,  Board& b);  //input   

         newChar operator[](const Coordinate &p) const;
         newChar& operator[](const Coordinate &p);
         Board& operator= (char c);
         Board& operator=(const Board& b1);
         bool operator==(const Board &b1) const;
         void clear();
         ~Board(); //destructor
          const string draw(int n);
          bool isExists(string fileName);
};

    inline ostream &operator<<(ostream &os, const Board& b) {  //toString (cout)
        for (int i = 0; i < b.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                os << b.board[i][j];
            }
            os<<endl;
        }
        return os;
    }

    inline istream &operator>>(istream &is,  Board& b) {  //input   
        string line;
        cin>>line;
       int n = line.length();
        Board temp(n);
        for (int i = 0; i < temp.size(); i++) {
            for (int j = 0; j < temp.size(); j++){ 
                    temp.board[i][j]=line[j];
                }
                //line="";
                cin>>line;
            }
        b=temp;
        return is;
    }
