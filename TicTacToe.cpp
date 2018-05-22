#include "TicTacToe.h"
    
TicTacToe::TicTacToe(int n){  //constructor
    board.size=n;
}

const void TicTacToe:: play(Player& player_X, Player& player_O){  //loop with the game
    bool win;
    while(!Winning(player_X, player_O)){
        if(win){
            try{
                if(game_board[player_X.play(game_board)] == '.')
                    game_board[player_X.play(game_board)] = player_X.getChar();  //where X will play
                else{
                    game_winner = player_O;
                    return;
                }   
                win = false;
            }
            catch(string& ex){
                game_winner = player_O;
                return;
            }
        }
        else{
            try{
                if(){
                    game_board[player_O.play(game_board)] = player_O.getChar();  //where O will play
                }
                else{
                    game_winner = player_X;
                    return; 
                }
                win = true; 
            }
            catch(string& ex){
                game_winner = player_O;
                return;
            }
        }
    }
}

bool TicTacToe:: Winning(Player& player_X, Player& player_O){  //check winnig for the game
    newChar c = game_board[{0,0}];
    bool flag = true;
    //check row
    for (int j = 0; j < game_board.size(); j++) {
        c = game_board[{0,j}];
       if(c != '.'){
           for (int i = 0; i < game_board.size(); i++) {
               if(game_board[{i,j}] != c) break;
               if(i = game_board.size()-1){
                   if(player_X.getChar() == c){
                       game_winner = player_X;
                   }
                   else{
                       game_winner = player_O;
                   }
                   return true;
               }
           }
       }
    }
    
    //check colum
    for (int i = 0; i < game_board.size(); i++) {
        c = game_board[{i,0}];
       if(c != '.'){
           for (int j = 0; j < game_board.size(); j++) {
               if(game_board[{i,j}] != c) break;
               if(j = game_board.size()-1){
                   if(player_X.getChar() == c){
                       game_winner = player_X;
                   }
                   else{
                       game_winner = player_O;
                   }
                   return true;
               }
           }
       }
    }
    
    //check left diagonal
    c = game_board[{0,0}];
    if(c != '.'){
        for (int i = 1; i < game_board.size(); i++) {
            if(game_board[{i,i}] != c) break;
                if(i = game_board.size()-1){
                    if(player_X.getChar() == c){
                        game_winner = player_X;
                   }
                   else{
                       game_winner = player_O;
                   }
                   return true;
               }
           }
       }
    }
    
    //check right diagonal
    c = game_board[{0,game_board.size()-1}];
    if(c != '.'){
        for (int i = 1; i < game_board.size(); i++) {
            if(game_board[{i,(game_board.size()-i-1)}] != c) break;
                if(i = game_board.size()-1){
                    if(player_X.getChar() == c){
                        game_winner = player_X;
                   }
                   else{
                       game_winner = player_O;
                   }
                   return true;
               }
           }
       }
    }
    while(flag){
        for (int i = 0; i < game_board.size(); i++) {
            for (int j = 0; j < game_board.size(); j++) {
                if(game_board[{i,j}] == '.') flag = false;
            }
        }
        game_winner = player_O;
        return true;
    }
 return false;   

}
    
const Player& TicTacToe:: winner() const{
    return game_winner;
}

Board& TicTacToe:: board() const{
    return game_board;
}
