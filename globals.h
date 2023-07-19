//
// Created by Alin on 15/04/2023.
//

#ifndef XO_GLOBALS_H
#include <iostream>
#include "raylib.h"
#include <vector>
#define XO_GLOBALS_H


enum symbols {EMPTY = 0, X = 10, O = -10};
enum state {Running = 2, Xwon = 10, Owon = -10, Tie = 0};

struct Move
{
    int row, col;
};


inline void nextPlayer(symbols &current)
{
    if(current==X)
        current = O;
    else if(current == O)
        current = X;
}

inline int checkWinner(std::vector<std::vector<int>> board, int n)
{
    int winner;

    // any of the rows is same
    for(int i = 0; i<n; i++) {
        int flag = 0;
        for (int j = 0; j < n - 1; j++) {
            if (board[i][j] != board[i][j + 1] || board[i][j] == EMPTY) {
                flag = 1;
            }
        }
        if (!flag) {
            winner = board[i][0];
            return winner;
        }
    }


    // any of the columns is same
    for(int i=0; i<n; i++)
    {   int flag = 0;
        for(int j =0; j<n-1; j++) {
            if (board[j][i] != board[j+1][i] || board[j][i] == EMPTY) {
                flag = 1;
            }
        }
        if(!flag) {
            winner = board[0][i];
            return winner;
        }
    }

    // 1st diagonal is same
    int flag =0;
    for(int i=0; i<n-1; i++)
    {
        if(board[i][i]!=board[i+1][i+1] || board[i][i]==EMPTY)
        {
            flag =1;
        }

    }
    if(!flag){
        winner = board[0][0];
        return winner;
    }


    // 2nd diagonal is same
    flag =0;
    for(int i=0; i<n-1; i++)
    {
        if(board[i][(n-1)-i]!=board[i+1][(n-1)-(i+1)] || board[i][i]==EMPTY)
        {
            flag =1;
        }

    }
    if(!flag){
        winner = board[0][n-1];
        return winner;
    }


    // if we reached here nobody has won yet

    // if any empty box on board then play on
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(board[i][j]==EMPTY)
            {
                winner = Running;
                return winner;
            }
        }
    }

    winner = Tie; // all boxes full and nobody won so A tie has occurred
    return winner;
}

inline Vector2 CoordToGrid(Vector2 coord, int n, float width, float height){
    Vector2 poz;
    poz.x = (coord.x)/(width/n);
    poz.y = (coord.y)/(height/n);
    return poz;
}


#endif //XO_GLOBALS_H


