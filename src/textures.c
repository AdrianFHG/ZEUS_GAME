#include <raylib.h>
#include <time.h>
#include <math.h>
#include "textures.h"

Texture2D bg;
Texture2D icon[NUMBER_of_TEXTURE];

//RECTANGLE
Rectangle board = {400,120,600,240};
int innerBoard_side = 130;
Rectangle innerBoard[NUMBER_of_INNERBOARD];
Rectangle spin = {600,420,240,90};

void LoadAllTextures(){
    bg = LoadTexture("assets\\background.jpg");

    icon[0] = LoadTexture("assets\\777.png");
    icon[1] = LoadTexture("assets\\dollar-sign.png");
    icon[2] = LoadTexture("assets\\diamond.png");
    icon[3] = LoadTexture("assets\\bell.png");
    icon[4] = LoadTexture("assets\\clover.png");
    icon[5] = LoadTexture("assets\\cherries.png");

    for(int i = 0; i<NUMBER_of_TEXTURE;i++) SetTextureFilter(icon[i],0);
}
void LoadInnerBoard(){
    for(int i = 0; i < NUMBER_of_INNERBOARD;i++){
        innerBoard[i] = (Rectangle){board.x+50*(i+1)+innerBoard_side*i, board.y+55, innerBoard_side, innerBoard_side};
    }
}
void UnloadAllTextures(){
    UnloadTexture(bg);

    for(int i = 0;i<NUMBER_of_TEXTURE;i++){
        UnloadTexture(icon[i]);
    }
}

void DrawBackground(){
    DrawTexturePro(
        bg,
        (Rectangle) {0,0,bg.width,bg.height},
        (Rectangle){0,0,GetScreenWidth(),GetScreenHeight()},
        (Vector2){0,0},
        0.0f,
        WHITE
    );
}
void DrawInnerBoard(){
    for(int i = 0;i<NUMBER_of_INNERBOARD;i++){
        DrawRectangleRoundedLines(innerBoard[i],0.3f,16,RAYWHITE);
       }
}

void UpdateHasil(int hasil[]){
    for(int i = 0; i<NUMBER_of_INNERBOARD;i++){
        hasil[i] = GetRandomValue(0,5);
    }
}
void DrawIcons(int isi[]){
    for(int i = 0 ; i < NUMBER_of_INNERBOARD;i++){
        DrawTexturePro(
            icon[isi[i]],
            (Rectangle){0,0,icon[0].width,icon[0].height},
            (Rectangle){innerBoard[i].x,innerBoard[i].y,innerBoard[i].width-2,innerBoard[i].height-2},
            (Vector2){0,0},
            0.0f,
            WHITE
        );
    }
}
void DrawIconRandom(){
    for(int i = 0 ; i < NUMBER_of_INNERBOARD;i++){
        int randIndex = GetRandomValue(0,5);
        DrawTexturePro(
            icon[randIndex],
            (Rectangle){0,0,icon[0].width,icon[0].height},
            (Rectangle){innerBoard[i].x,innerBoard[i].y,innerBoard[i].width-2,innerBoard[i].height-2},
            (Vector2){0,0},
            0.0f,
            WHITE
        );
    }
}
void DrawSpinText(){
    char text[10] = "SPIN"; 
    int font = 60;

    float textX =(float)spin.x + spin.width/2 - MeasureText(text,font)/2;
    float textY = (float)spin.y +spin.height/2 - font/2;

    DrawText(text,textX,textY,font,YELLOW);
}