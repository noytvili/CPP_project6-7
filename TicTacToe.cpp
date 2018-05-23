#include "TicTacToe.h"
#include <string>
using namespace std;


    
TicTacToe::TicTacToe(int n) : game_board(n){  //constructor
    b_size=n;
}

Board TicTacToe::board() const
{
    return game_board;
}

const void TicTacToe:: play(Player& player_X, Player& player_O){  //loop with the game
    bool win=true;
 //   cout << "******play***" << endl;
    player_X.myChar='X';
    player_O.myChar='O';

    while(!Winning(player_X, player_O)){
  //  cout << "******while****" << endl;

        if(win){
  //  cout << "******if****" << endl;

            try{
                if(game_board[player_X.play(game_board)] == '.'){
                    game_board[player_X.play(game_board)] = player_X.getChar();  //where X will play
  //  cout << "******x****" << endl;
                }
                else{
                    game_winner = &player_O;
                    return;
                }   
            }
            catch(string& ex){
                game_winner = &player_O;
                return;
            }
        win = false;

        }
        else{
            try{
                if(game_board[player_O.play(game_board)] == '.'){
                    game_board[player_O.play(game_board)] = player_O.getChar();  //where O will play
   // cout << "******o****" << endl;

                }
                else{
                    game_winner = &player_X;
                    return; 
                }
            }
            catch(string& ex){
                game_winner = &player_O;
                return;
            }
        win = true; 

        }
    }
}

bool TicTacToe:: Winning(Player& player_X, Player& player_O){  //check winnig for the game
    newChar c2;
    c2 = game_board[{0,0}];
    bool flag = true;
    //check row

    for (uint j = 0; j < b_size; j++) {
        c2 = game_board[{0,j}];
       if(c2.c != '.'){
           for (uint i = 1; i < b_size; i++) {
               if(game_board[{i,j}] != c2) break;
               if(i == b_size-1){
                   if(player_X.getChar() == c2.c){
                       game_winner = &player_X;
                   }
                   else{
                       game_winner = &player_O;
                   }
         //          cout << "----------for 1----------" << endl;
                   return true;
                }
            }
        }
    }

    
    //check colum
    for (uint i = 0; i < b_size; i++) {
        c2 = game_board[{i,0}];
       if(c2.c != '.'){
           for (uint j = 1; j < b_size; j++) {
               if(game_board[{i,j}] != c2) break;
               if(j == b_size-1){
                   if(player_X.getChar() == c2.c){
                       game_winner = &player_X;
                   }
                   else{
                       game_winner = &player_O;
                   }
        //    cout << "----------for 2----------" << endl;

                   return true;
               }
           }
       }
    }
    
    //check left diagonal
    c2 = game_board[{0,0}];
    if(c2.c != '.'){
        for (uint i = 1; i < b_size; i++) {
            if(game_board[{i,i}] != c2) break;
                if(i == b_size-1){
                    if(player_X.getChar() == c2.c){
                        game_winner = &player_X;
                   }
                   else{
                       game_winner = &player_O;
                   }
       //     cout << "----------for 3----------" << endl;
                   return true;
               
               }
           }
       }
    
    
    //check right diagonal
    uint size_uint = b_size;
    c2 = game_board[{0,size_uint-1}];
    if(c2.c != '.'){
        for (uint i = 1; i < b_size; i++) {
            if(game_board[{i,(b_size-i-1)}] != c2) break;
                if(i == b_size-1){
                    if(player_X.getChar() == c2.c){
                        game_winner = &player_X;
                   }
                   else{
                       game_winner = &player_O;
                   }
       // cout << "----------for 4----------" << endl;
                   return true;

               }
           }
       }
    
    // while(flag){
    //     for (uint i = 0; i < b_size; i++) {
    //         for (uint j = 0; j < b_size; j++) {
    //             if(game_board[{i,j}] == '.') flag = false;
    //         }
    //     }
    //     game_winner = &player_O;
    // //   cout << "----------while full board----------" << endl;

    //     return false;
    // }
 return false;   

}
    
const Player& TicTacToe:: winner() const{
    return *game_winner;
}


