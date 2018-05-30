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


 string Board :: draw(int n){  
    int num_pic=1;
    const int dimx = n, dimy = n;
    string filename = "pic"+to_string(num_pic)+".ppm";
    num_pic++;
    ofstream imageFile(filename, ios::out | ios::binary); // filename-pic1.ppm,pic2.ppm...
    int cell = n / Size; 
    int width = cell / 5;
    int red_board, green_board, blue_board;
    char cur;
    imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;
    RGB image[dimx*dimy];
    //backGround of the board
    for (int j = 0; j < dimy; ++j)  {  // row
        for (int i = 0; i < dimx; ++i) { // column
            image[dimx*j+i].red = (246);
            image[dimx*j+i].green = (233);
            image[dimx*j+i].blue = (197);
        }
  }
    //paint X / O / . :
    for (int i = 0; i < Size; i++) 
        for (int j = 0; j < Size; j++) {
            cur = board[i][j].getChar();
            if(cur = 'O'){  //תכלת
                red_board = 97;
                green_board = 208;
                blue_board = 214;
            }
            else if (cur = 'X'){  //סגול
                red_board = 120;
                green_board = 140;
                blue_board = 200;
            }
            else{  //ורוד
                red_board = 210;
                green_board = 11;
                blue_board = 141;
            }
            for (int k = i*cell+width; k < i*cell+cell-width; ++k) {
                for (int y = j*cell+width; y < j*cell+cell-width; ++y) {
                    image[dimx*j+i].red = red_board;
                    image[dimx*j+i].blue = blue_board;
                    image[dimx*j+i].green = green_board; 
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
                            image[dimx*p+l].red = (101);
                            image[dimx*p+l].green = (63);
                            image[dimx*p+l].blue = (63);
                        }
                    }
                }
            }
            else if(cur == 'X'){
                int Right = j*cell+cell-width-1;
                int Left = j*cell+width;
                int q = 0;
                for (int p = i*cell+width; p < i*cell+cell-width; ++p) {
                    //left diagonal
                    image[dimx*p+Left+q].red = (101);
                    image[dimx*p+Left+q].green = (63);
                    image[dimx*p+Left+q].blue = (63);
                    //right diagonal
                    image[dimx*p+Right-q].red = (101);
                    image[dimx*p+Right-q].green = (63);
                    image[dimx*p+Right-q].blue = (63);
                    q++;
                }
            }
        
        }   //end second big for
 
  ///image processing///
  imageFile.write(reinterpret_cast<char*>(&image), 3*dimx*dimy);
  imageFile.close();
  return filename;
}
