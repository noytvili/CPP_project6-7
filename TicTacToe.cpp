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
    player_X.setChar('X');
    player_O.setChar('O');
    
   game_board='.';
    while(!Winning(player_X, player_O)){
        //cout << game_board << endl;

        if(win){
  //  cout << "******if****" << endl;

            try{
                Coordinate p = player_X.play(game_board);
                if(game_board[p] == '.'){
                    game_board[p] = player_X.getChar();  //where X will play
                   // cout << "******x****" << p << player_X.getChar() << endl;
                }
                else{
                    game_winner = &player_O;
                    break;
                }   
            }
            catch(string& ex){
                game_winner = &player_O;
                break;
            }
        win = false;

        }
        else{
            try{
                Coordinate p = player_O.play(game_board);
                if(game_board[p] == '.'){
                    game_board[p] = player_O.getChar();  //where O will play
                 //   cout << "******o****" << p << player_O.getChar() << endl;
                }
                else{
                    game_winner = &player_X;
                    break; 
                }
            }
            catch(string& ex){
                game_winner = &player_X;
                break;
            }
        win = true; 

        }
    }
}

bool TicTacToe:: Winning(Player& player_X, Player& player_O){  //check winnig for the game
    newChar c2;
    c2 = game_board[{0,0}];
    //check row

    for (uint j = 0; j < b_size; j++) {
        c2 = game_board[{0,j}];
       if(c2 != '.'){
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
       if(c2 != '.'){
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

    if(c2 != '.'){
                                  //cout << "----------for 3----------" << endl;

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
    if(c2 != '.'){
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
    

    for (uint i = 0; i < b_size; i++) {
        for (uint j = 0; j < b_size; j++) {
            if(game_board[{i,j}] == '.') return false;
        }
    }
    game_winner = &player_O;
    return true;   

}
    
const Player& TicTacToe:: winner() const{
    return *game_winner;
}


