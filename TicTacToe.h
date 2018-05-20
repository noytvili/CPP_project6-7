#include "Board.h"
#include "Player.h"
#pragma once

class TicTacToe {
    private:
       Board* game_board;
       Player* game_winner;
       bool Winning(Player& player_X, Player& player_O);
    
    public:
        TicTacToe(int n);
        const void TicTacToe:: play(Player& player_X, Player& player_O);
        const Player& winner() const;
        Board& TicTacToe:: board() const;
};
