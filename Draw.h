//
// Created by Alin on 15/04/2023.
//

#ifndef XO_DRAW_H
#include "globals.h"
#define XO_DRAW_H


class Draw {
private:
    int _n;
    float _width;
    float _height;
    std::vector<std::vector<int>> _arr;
public:
    Draw(int n, float width, float height, std::vector<std::vector<int>> &arr);
    void DrawGrid();
    void DrawX(int x, int y);
    void DrawO(int x, int y);
    void DrawSymbols();
    void RefreshTable(std::vector<std::vector<int>> &arr);

};


#endif //XO_DRAW_H
