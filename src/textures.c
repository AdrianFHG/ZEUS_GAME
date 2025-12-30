#include <raylib.h>
#include "textures.h"

Texture2D bg;
Texture2D icon[NUMBER_of_TEXTURE];

void LoadAllTextures(){
    bg = LoadTexture("assets\\background.jpg");

    //icon[0] = LoadTexture("../");
}
void UnloadAllTextures(){
    UnloadTexture(bg);

    // for(int i = 0;i<NUMBER_of_TEXTURE;i++){
    //     UnloadTexture(icon[i]);
    // }
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