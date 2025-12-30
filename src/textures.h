#ifndef TEXTURE_H
#define TEXTURE_H

#include <raylib.h>

#define NUMBER_of_TEXTURE 6

extern Texture2D bg;
extern Texture2D icon[NUMBER_of_TEXTURE];

void LoadAllTextures();
void UnloadAllTextures();

void DrawBackground();

#endif