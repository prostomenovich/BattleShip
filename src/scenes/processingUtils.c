#include "processingUtils.h"

#ifndef PROCESSINGUTILS_C
#define PROCESSINGUTILS_C

double correctXcoords(double currentXcoords, int windowSizeX)
{
    return currentXcoords * (double)windowSizeX / BASE_SCREEN_SIZE_X;
}

double correctYcoords(double currentYcoords, int windowSizeY)
{
    return currentYcoords * (double)windowSizeY / BASE_SCREEN_SIZE_Y;
}

double correctTextSize(double currentSize, int windowSizeX, int windowSizeY)
{
    return ((currentSize * windowSizeX * windowSizeY) / ( BASE_SCREEN_SIZE_X * BASE_SCREEN_SIZE_Y)); 
}

int cursorInArea(int mousePosX, int mousePosY, int lowerLeftX, int lowerLeftY, int higherRightX, int higherRightY, int windowSizeX, int windowSizeY)
{
    return mousePosX >= correctXcoords(lowerLeftX, windowSizeX) && mousePosY <= correctYcoords(lowerLeftY, windowSizeY) && mousePosX <= correctXcoords(higherRightX, windowSizeX) && mousePosY >= correctYcoords(higherRightY, windowSizeY);
}

#endif