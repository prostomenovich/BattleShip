#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../render/sprite.h"


#ifndef PROCESSINGUTILS_H
#define PROCESSINGUTILS_H

#define BASE_SCREEN_SIZE_X 1280
#define BASE_SCREEN_SIZE_Y 720

#define KEY_PRESSED_DELAY 0.4f

//map sprite state
#define PLATE_NOT_PRESSED 1
#define PLATE_PRESSED 2

//Map size
#define MAP_SIZE_10_X_10 10
#define MAP_SIZE_15_X_15 15

typedef struct MapSprite
{
    Sprite* sprite;
    GLuint spriteState;

} MapSprite;

double correctXcoords(double currentXcoords, int windowSizeX);

double correctYcoords(double currentYcoords, int windowSizeY);

double correctTextSize(double currentSize, int windowSizeX, int windowSizeY);

void changeCorrectSpriteParams(Sprite* sprite, int windowSizeX, int windowSizeY);

int cursorInArea(int mousePosX, int mousePosY, int lowerLeftX, int lowerLeftY, int higherRightX, int higherRightY, int windowSizeX, int windowSizeY);

int plateIsPressed10x10(int i, int j, int xMousePos, int yMousePos);

#endif