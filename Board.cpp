#include "Board.h"
#include <iostream>
#include <cmath>
//#include <list>
using namespace std;

Board:: Board(){
    Size =0;
    board = new newChar*[Size];  //allocBoard
	for (int i = 0; i < Size; i++){
		board[i] = new newChar[Size];
	}  
}
    
Board:: Board(int n){ //constructor
    Size = n;
    board = new newChar*[Size];  //allocBoard
	for (int i = 0; i < Size; i++){
		board[i] = new newChar[Size];
    }
}

Board:: Board(const Board& b1){ //copy constructor
int i,j;
    Size = b1.Size;
    board = new newChar*[Size];  //allocBoard
	for (i = 0; i < Size; i++){
		board[i] = new newChar[Size];
        for (j = 0; j < Size; j++) 
           // board[i][j] = b1.board[i][j];
           board[i][j] = newChar(b1.board[i][j]);
	}
}

int Board:: size() const{
    return Size;
}

 newChar Board::operator[](const Coordinate &p) const {  //לקריאה בלבד
    return board[p.get_i()][p.get_j()];
}

 newChar& Board::operator[](const Coordinate &p) { //לשנות את הערך
    if ((p.get_i() >= Size || p.get_i() < 0) || (p.get_j() >= Size || p.get_j() < 0)){
        throw IllegalCoordinateException(p);
    }
        return board[p.get_i()][p.get_j()];
}

Board& Board::operator= (char c){
    if(c!='X' && c!='O' && c!='.'){
        throw IllegalCharException(c);
    }
    else{
        for(int i = 0; i < Size; i++)
            for(int j = 0; j < Size; j++)
                board[i][j] = c;
    }
    return *this;
}

Board& Board::operator=(const Board& b1){
     if (this==&b1){
        return *this;
     }

    clear();
    Size = b1.Size;
    board = new newChar*[Size];  //allocBoard
	for (int i = 0; i < Size; i++){
		board[i] = new newChar[Size];
        for (int j = 0; j < Size; j++) 
            board[i][j] = b1.board[i][j];
    }
    return *this;
        }
    
bool Board::operator==(const Board &b1) const {
    if (Size != b1.Size)
        return false;
    for (int i = 0; i < Size; ++i) {
        for (int j = 0; j < Size; ++j) {
            if (board[i][j] != b1.board[i][j])
                return false;
        }
    }
    return true;
}

void Board:: clear(){  //distructor
    for (int i = 0; i < Size; i++) //free
	    delete[] board[i];
	delete[] board;
}

Board:: ~Board(){  //distructor
    clear();
}

bool Board::isExists(string fileName) {
    ifstream infile(fileName);
    return infile.good();
}

 const string Board :: draw(int n){  
    int num_pic = 1;
    const int dimx = n, dimy = n;
    int cell = n / Size; 
    int width = cell / 5;
    int red_board, green_board, blue_board;
    string filename = "pic"+to_string(num_pic)+".ppm";
    RGB image[dimx*dimy];
    
    //backGround of the board
    for (int j = 0; j < dimy; ++j)  {  // row
        for (int i = 0; i < dimx; ++i) { // column
            image[dimx*j+i].red = (246);
            image[dimx*j+i].green = (233);
            image[dimx*j+i].blue = (197);
        }
    }
    //bounds
    for (int i = 0; i <dimx; ++i) {//row
        for (int j = 0; j < dimx; ++j) {//column
            if(i%(dimx /Size) == 0 || j%(dimx /Size) == 0  || i%(dimx-5/Size) == 0|| j%(dimx-5/Size) == 0) {
                image[dimx*i + j].red = 0;
                image[dimx*i + j].blue = 0;
                image[dimx*i + j].green = 0;
            }
        }
    }
    
    //paint X / O / . :
    for (int i = 0; i < Size; ++i) {
        for (int j = 0; j < Size; ++j) {
            char cur = board[i][j].getChar();

            for (int k = i*cell+width; k < i*cell+cell-width; ++k) {
                for (int y = j*cell+width; y < j*cell+cell-width; ++y) {
                    image[dimx*j+i].red = red_board;
                    image[dimx*j+i].blue = blue_board;
                    image[dimx*j+i].green = green_board; 
                }
            }
            //for "X"
            if(cur == 'X'){    
                int Right = j*cell+cell-width-1;
                int Left = j*cell+width;
                int q = 0;
                for (int p = i*cell+width; p < i*cell+cell-width; ++p) {
                    //left diagonal
                    image[dimx*p+Left+q].red = (120);
                    image[dimx*p+Left+q].green = (140);
                    image[dimx*p+Left+q].blue = (200);
                    //right diagonal
                    image[dimx*p+Right-q].red = (120);
                    image[dimx*p+Right-q].green = (140);
                    image[dimx*p+Right-q].blue = (200);
                    q++;
                }
            }
            // for 'O'
            if (cur == 'O'){
                double r = cell/2-2*width;
                double xMid = (j*cell+width)/2 + (j*cell+cell-width)/2;
                double yMid = (i*cell+width)/2 + (i*cell+cell-width)/2;
                for (int p = i*cell+width; p < i*cell+cell-width; ++p) {
                    for (int l = j*cell+width; l < j*cell+cell-width; ++l) {
                        double d = pow(xMid-l,2) + pow(yMid-p,2);
                        d = sqrt(d);
                        d = abs(d-r);
                        if(d < 10){
                            image[dimx*p+l].red = (210);
                            image[dimx*p+l].green = (11);
                            image[dimx*p+l].blue = (141);
                        }
                    }
                }
            }
        
        }   
    }
    
  ///image processing///
    while(isExists(filename)) {
        ++num_pic;
        filename = "pic" + to_string(num_pic) + ".ppm";
    }
    ofstream imageFile(filename, ios::out | ios::binary);
    imageFile << "P6" << endl << dimx << " " << dimy << endl << 255 << endl;
  
    imageFile.write(reinterpret_cast<char*>(&image), 3*dimx*dimy);
    imageFile.close();
    return filename;
}
