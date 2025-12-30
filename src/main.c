#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


#include "raylib.h"
#include "textures.h"





int main() {
    srand(time(NULL));
    double startTime  = 0;
    bool spinning = false;

    int hasil [NUMBER_of_INNERBOARD];
    for(int i = 0; i<NUMBER_of_INNERBOARD;i++){
        hasil[i] = 0;
    }
    int score = 0;
    
    InitWindow(1200, 600, "Zeus");
    SetTargetFPS(60);
    LoadAllTextures();
    LoadInnerBoard();

    while(!WindowShouldClose()){
        double currentTime = GetTime();

        BeginDrawing();
        
       ClearBackground(BLACK);
       DrawBackground();
       DrawText(TextFormat("Score: %d", score), 20, 20, 30, YELLOW);

       //rect
       DrawRectangleRounded(board,0.3f,16,BLACK);
       DrawInnerBoard();
       //DrawIcons();

       DrawRectangleRounded(spin,0.2f,16,WHITE);
       DrawSpinText();

       if(spinning){
        if(currentTime - startTime <= 2.0){
            UpdateHasil(hasil);
        }
        else{
            if(hasil[0] == hasil[1] && hasil[1] == hasil[2] ) score++;
            spinning = false;
        }
       }
      
        DrawIcons(hasil);

        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            Vector2 mouse = GetMousePosition();
            if(CheckCollisionPointRec(mouse,spin)){
               spinning  = true;
               startTime = GetTime();
            }
        }
       
        EndDrawing();
    }
    
    
    UnloadAllTextures();
    CloseWindow();
    return 0;
}