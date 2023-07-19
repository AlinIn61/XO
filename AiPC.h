//
// Created by Alin on 15/04/2023.
//

#ifndef XO_AIPC_H
#include "globals.h"
#define XO_AIPC_H

class AiPC{
public:
    static int minimax(std::vector<std::vector<int>> &board, int depth, bool isMax, int n, int alpha, int beta);
    static Move findBestMove(std::vector<std::vector<int>> board, int n, int depth);
};

#endif //XO_AIPC_H
