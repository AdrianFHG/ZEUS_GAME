#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "raylib.h"
#include "textures.h"


int main() {

    srand(time(NULL));
    
    InitWindow(1200, 600, "Zeus");
    SetTargetFPS(60);
    LoadAllTextures();

    while(!WindowShouldClose()){
        BeginDrawing();
        
       ClearBackground(BLACK);
       DrawBackground();

       //DrawRectangleRec(board,BLACK);
       DrawRectangleRoundedLines(board,0.3f,16,BLACK);
       DrawRectangleRec(spin,WHITE);

       


       
    //    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
    //     Vector2 mouse = GetMousePosition();

    //     if(CheckCollisionPointRec(mouse,spin)){
    //         DrawText("KLIK",400,400,20,YELLOW);
    //     }

    // }

        EndDrawing();
    }
    
    UnloadAllTextures();
    CloseWindow();
    return 0;
}