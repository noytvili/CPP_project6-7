#include "TicTacToe.h"
    
TicTacToe::TicTacToe(int n){  //constructor
    board.size=n;
}

const void TicTacToe:: play(Player& player_X, Player& player_O){  //loop with the game
    bool win;
    
    while(!Winning(player_X, player_O)){
        if(win){
            game_board[player_X.play()] = player_X.getChar();  //where X will play   ???
            win = false;
        }
        else{
            game_board[player_O.play()] = player_O.getChar();  //where O will play  ???
            win = true;
        }
    }
}

bool TicTacToe:: Winning(Player& player_X, Player& player_O){  //check winnig for the game

}
    
const Player& TicTacToe:: winner() const{
    return *game_winner;
}

Board& TicTacToe:: board() const{
    return *game_board;
}
    
