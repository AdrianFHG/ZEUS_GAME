#ifndef TEXTURE_H
#define TEXTURE_H

#include <raylib.h>

#define NUMBER_of_TEXTURE 6
#define NUMBER_of_INNERBOARD 3

extern Texture2D bg;
extern Texture2D icon[NUMBER_of_TEXTURE];

extern Rectangle board;
extern int innerBoard_side;
extern Rectangle innerBoard[NUMBER_of_INNERBOARD];
extern Rectangle spin;

void LoadAllTextures();
void LoadInnerBoard();
void UnloadAllTextures();

void DrawBackground();
void DrawInnerBoard();
void UpdateHasil(int hasil[]);
void DrawIcons(int isi[]);
void DrawIconRandom();
void DrawSpinText();

#endif