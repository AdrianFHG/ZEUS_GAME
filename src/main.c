#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "raylib.h"


Rectangle rect[3] = {{250,200,100,100},
                    {350,200,100,100},
                    {450,200,100,100}};

Rectangle spin = {350,300,160,60};

const char num[2][10] = {{"true"},{"false"}};

int main() {

    srand(time(NULL));
    

    
    InitWindow(800, 600, "Zeus");
    SetTargetFPS(60);

    

    while(!WindowShouldClose()){
        BeginDrawing();
        
       ClearBackground(RAYWHITE);
        
       for(int i = 0; i<3;i++){ 
        DrawRectangleRec(rect[i],RAYWHITE);
        DrawRectangleLines(rect[i].x,rect[i].y,rect[i].width,rect[i].height,BLACK);

        char *text;
        strcpy(text,num[rand() %2]);
        float textWidth = MeasureText(text, 20);
        float textHeight = 20; // biasanya tinggi = fontSize

        float textX = rect[i].x + (rect[i].width - textWidth) / 2;
        float textY = rect[i].y + (rect[i].height - textHeight) / 2;
        DrawText(text,textX ,textY, 20,BLACK);
       }

       DrawRectangleRec(spin,BLUE);
       DrawText("SPIN",spin.x+20,spin.y+20,20,YELLOW);
       
       
       if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        Vector2 mouse = GetMousePosition();

        if(CheckCollisionPointRec(mouse,spin)){
            DrawText("KLIK",400,400,20,YELLOW);
        }

    }

        EndDrawing();
    }
    
   
    CloseWindow();
    return 0;
}