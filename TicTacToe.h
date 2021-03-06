#include "Player.h"
#pragma once

class TicTacToe {
    private:
       Board game_board;
       Player *game_winner;
       bool Winning(Player& player_X, Player& player_O);
    
    public:
    int b_size;
        TicTacToe(int n);
        const void play(Player& player_X, Player& player_O);
        const Player& winner() const;
       Board board() const;
};
