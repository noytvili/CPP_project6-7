#include "Board.h"
#include <iostream>
#include <fstream>
#include <string>
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
  ofstream imageFile("pic"+to_string(num_pic)+".ppm", ios::out | ios::binary); // filename-pic1.ppm,pic2.ppm...
  num_pic++;
  
  imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;
  RGB image[16];
  for (int j = 0; j < dimy; ++j)  {  // row
    for (int i = 0; i < dimx; ++i) { // column
      image[dimx*j+i].red = (i % 256);
      image[dimx*j+i].green = (j % 256);
      image[dimx*j+i].blue = ( (i*i+j*j) % 256);
    }
  }
  image[0].red = 255;
  image[0].blue = 0;
  image[0].green = 0;
  ///
  ///image processing
  ///
  imageFile.write(reinterpret_cast<char*>(&image), 3*dimx*dimy);
  imageFile.close();
    
    
}
