//
// Created by Alin on 15/04/2023.
//

#include "Draw.h"

Draw::Draw(int n, float width, float height, std::vector<std::vector<int>> &arr) {
_n = n;
_width = width;
_height = height;
_arr = arr;
}

void Draw::DrawGrid() {
    for(int i = 1; i<_n; i++) {
        DrawLineEx({0, i*_height / _n}, {_width, i*_height / _n}, 5, BLACK);
        DrawLineEx({i*_width / _n, 0}, {i*_width / _n, _height}, 5, BLACK);
    }
}

void Draw::DrawX(int x, int y) {
    float NewWidth = _width/_n;
    float NewHeight = _height/_n;
    DrawLineEx({NewWidth*x, NewHeight*y}, {NewWidth*(x+1),NewHeight*(y+1)}, 5, RED);
    DrawLineEx({NewWidth*(x+1), NewHeight*y}, {NewWidth*x,NewHeight*(y+1)}, 5, RED);
}

void Draw::DrawO(int x, int y) {
    float NewWidth = _width / _n;
    float NewHeight = _height / _n;
    DrawLineEx({NewWidth * x, NewHeight * y}, {NewWidth * (x + 1), NewHeight * y}, 5, BLUE);
    DrawLineEx({NewWidth * (x + 1), NewHeight * y}, {NewWidth * (x + 1), NewHeight * (y+1)}, 5, BLUE);
    DrawLineEx({NewWidth * (x + 1), NewHeight * (y+1)}, {NewWidth * x, NewHeight * (y+1)}, 5, BLUE);
    DrawLineEx({NewWidth * x, NewHeight * (y+1)}, {NewWidth * x, NewHeight * y}, 5, BLUE);

}

void Draw::DrawSymbols(){
    for(int i =0 ; i< _n; i++)
        for(int j =0; j<_n; j++) {
            if (_arr[i][j] == X) {
                DrawX(i, j);
            }
            else if (_arr[i][j] == O){
                DrawO(i, j);
            }
        }

}

void Draw::RefreshTable(std::vector<std::vector<int>> &arr) {
    _arr = arr;
}

