#include "Champion.h"

const Coordinate Champion:: play(const Board& board){
     newChar c = '.';
     if(game_board[{0,0}] == c)  //left up
          return Coordinate{0,0};
          
     if(game_board[{game_board.size-1, game_board.size-1}] == c) //right down
          return Coordinate{game_board.size-1, game_board.size-1};
     
     if(game_board[{0, game_board.size-1}] == c) // right up
          return Coordinate{0, game_board.size-1};
          
     if(game_board[{game_board.size-1, 0}] == c) //left down
          return Coordinate{game_board.size-1, 0};
     
     for (int i = 1; i < game_board.size; i++) { //left diagonal
          if(game_board[{i,i}] == c)
               return Coordinate{i,i};
     }
     
     for (int i = 1; i < game_board.size; i++) { //right diagonal
          if(game_board[{i,game_board.size-1-i}] == c)
               return Coordinate{i,game_board.size-1-i};
     }
     
     for (int i = 0; i < game_board.size; i++) {
          for (int i = 0; i < game_board.size; i++) {
               if(game_board[{i,j}] == c)
                    return Coordinate{i,j};
          }
     }
}

const string Champion:: name() const {
     return "♥ Doriya and Noy ♥";
 }
   
