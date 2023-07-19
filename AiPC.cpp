//
// Created by Alin on 15/04/2023.
//

#include "AiPC.h"

int AiPC::minimax(std::vector<std::vector<int>> &board, int depth, bool isMax, int n, int alpha, int beta) {
    int score;
    if(checkWinner(board, n) != 2){
        score = checkWinner(board, n);
    }
    if(depth<=0){
        return score;
    }
    // If Maximizer has won the game return his/her
    // evaluated score
    if (score == Xwon)
        return score;

    // If Minimizer has won the game return his/her
    // evaluated score
    if (score == Owon)
        return score;

    // If there are no more moves and no winner then
    // it is a tie
    if (score==Tie)
        return 0;

    // If this maximizer's move
    if (isMax)
    {
        int best = -10000;

        // Traverse all cells
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<n; j++)
            {
                // Check if cell is empty
                if (board[i][j]==EMPTY)
                {
                    // Make the move
                    board[i][j] = X;

                    // Call minimax recursively and choose
                    // the maximum value
                    best = std::max(best,
                                        minimax(board, depth, !isMax, n, alpha, beta));

                    alpha = std::max(alpha, best);
                    board[i][j] = EMPTY;
                    if(beta<=alpha)
                        break;

                    // Undo the move
                }
            }
        }
        return best;
    }

        // If this minimizer's move
    else
    {
        int best = 10000;

        // Traverse all cells
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<n; j++)
            {
                // Check if cell is empty
                if (board[i][j]==EMPTY)
                {
                    // Make the move
                    board[i][j] = O;

                    // Call minimax recursively and choose
                    // the minimum value
                        best = std::min(best,
                                        minimax(board, depth, !isMax, n, alpha, beta));
                    // Undo the move
                    beta = std::min(beta, best);
                    board[i][j] = EMPTY;
                    if(beta<=alpha)
                        break;
                }
            }
        }
        return best;
    }
}

Move AiPC::findBestMove(std::vector<std::vector<int>> board, int n, int depth){
        int bestVal = -10000;
        Move bestMove;
        bestMove.row = -1;
        bestMove.col = -1;

        // Traverse all cells, evaluate minimax function for
        // all empty cells. And return the cell with optimal
        // value.
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<n; j++)
            {
                // Check if cell is empty
                if (board[i][j]==EMPTY)
                {
                    // Make the move
                    board[i][j] = X;

                    // compute evaluation function for this
                    // move.
                    int moveVal = AiPC::minimax(board, depth, false, n, -10000, 10000);

                    // Undo the move
                    board[i][j] = EMPTY;

                    // If the value of the current move is
                    // more than the best value, then update
                    // best/
                    if (moveVal > bestVal)
                    {
                        bestMove.row = i;
                        bestMove.col = j;
                        bestVal = moveVal;
                    }
                }
            }
        }

        printf("The value of the best Move is : %d\n\n",
               bestVal);

        return bestMove;
}

