
#include "Draw.h"
#include "AiPC.h"


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    symbols currentPlayer = X;
    int gridSize = 3;
    std::vector<std::vector<int>> array(gridSize, std::vector<int>(gridSize, 0));
    Draw drawclass(gridSize, screenWidth, screenHeight, array);



    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    Vector2 poz = {NULL};
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            poz = CoordToGrid(GetMousePosition(), gridSize, screenWidth, screenHeight);
            if(array[(int)poz.x][(int)poz.y] ==EMPTY) {
                array[(int)poz.x][(int)poz.y] = currentPlayer;
                drawclass.RefreshTable(array);
                nextPlayer(currentPlayer);
            }
            //findBestMove(array);
            if(checkWinner(array, gridSize) == Running){
                std::cout<<"Running!";
            }
            else{
                std::cout<<"Finished";
            }
        }
        if(currentPlayer == X) {
            Move mov = AiPC::findBestMove(array ,gridSize, 4);
            array[mov.row][mov.col] = X;
            drawclass.RefreshTable(array);
            nextPlayer(currentPlayer);
        }

        //std::cout<<poz.x<<"s"<<poz.y<<"\n";
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        drawclass.DrawGrid();
        drawclass.DrawSymbols();
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}