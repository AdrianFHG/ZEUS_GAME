#include <raylib.h>
#include "textures.h"

Texture2D bg;
Texture2D icon[NUMBER_of_TEXTURE];

//RECTANGLE
Rectangle board = {400,120,660,240};
Rectangle spin = {600,420,270,90};

void LoadAllTextures(){
    bg = LoadTexture("assets\\background.jpg");

    icon[0] = LoadTexture("assets\\777.png");
    icon[1] = LoadTexture("assets\\dollar-sign.png");
    icon[2] = LoadTexture("assets\\diamond.png");
    icon[3] = LoadTexture("assets\\bell.png");
    icon[4] = LoadTexture("assets\\clover.png");
    icon[5] = LoadTexture("assets\\cherries.png");
   
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