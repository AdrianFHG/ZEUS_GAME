#ifndef TEXTURE_H
#define TEXTURE_H

#include <raylib.h>

#define NUMBER_of_TEXTURE 6

extern Texture2D bg;
extern Texture2D icon[NUMBER_of_TEXTURE];

extern Rectangle board;
extern Rectangle spin;

void LoadAllTextures();
void UnloadAllTextures();

void DrawBackground();

#endif