#include "Champion.h"

const Coordinate Champion:: play(const Board& board){
     newChar c;
     c.c= '.';
   uint b_size= board.size();
     if(board[{0,0}] == c)  //left up
          return Coordinate{0,0};
          
     if(board[{b_size-1, b_size-1}] == c) //right down
          return Coordinate{b_size-1, b_size-1};
     
     if(board[{0, b_size-1}] == c) // right up
          return Coordinate{0, b_size-1};
          
     if(board[{b_size-1, 0}] == c) //left down
          return Coordinate{b_size-1, 0};
     
     for (uint i = 1; i < b_size; i++) { //left diagonal
          if(board[{i,i}] == c)
               return Coordinate{i,i};
     }
     
     for (uint i = 1; i < b_size; i++) { //right diagonal
          if(board[{i,b_size-1-i}] == c)
               return Coordinate{i,b_size-1-i};
     }
     
     for (uint i = 0; i < b_size; i++) {
          for (uint j = 0; j < b_size; j++) {
               if(board[{i,j}] == c)
                    return Coordinate{i,j};
          }
     }
}

const string Champion:: name() const {
     return "♥ Doriya and Noy ♥";
 }
   
