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

void changeCorrectSpriteParams(Sprite* sprite, int windowSizeX, int windowSizeY)
{   
    static int lastSizeX = 1280;
    static int lastSizeY = 720;
    static Sprite* sp = 0;

    if (windowSizeX != lastSizeX || sp != sprite){
        changeSpritePosX(sprite, sprite->positionX * (double)windowSizeX / lastSizeX);
        changeSpriteSize(sprite, sprite->sizeX * (double)windowSizeX / lastSizeX, sprite->sizeY * (double)windowSizeY / lastSizeY);
        lastSizeX = windowSizeX;
        sp = sprite;
    }
    if (windowSizeY != lastSizeY || sp != sprite){
        changeSpritePosY(sprite, sprite->positionY * (double)windowSizeY / lastSizeY);
        changeSpriteSize(sprite, sprite->sizeX * (double)windowSizeX / lastSizeX, sprite->sizeY * (double)windowSizeY / lastSizeY);
        lastSizeY = windowSizeY;
        sp = sprite;
    }
}

int plateIsPressed10x10(int i, int j, int xMousePos, int yMousePos)
{
    extern int windowSizeX;
    extern int windowSizeY;
    //extern RaftPlacement10x10 sRaftPlacement10X10;

    if (i == 0){
        if (j == 0){
            return cursorInArea(xMousePos, yMousePos, 561, 136, 611, 88, windowSizeX, windowSizeY);
        }
        else if (j == 1){
            return cursorInArea(xMousePos, yMousePos, 620, 136, 672, 88, windowSizeX, windowSizeY);
        }
        else if (j == 2){
            return cursorInArea(xMousePos, yMousePos, 683, 136, 734, 88, windowSizeX, windowSizeY);
        }
        else if (j == 3){
            return cursorInArea(xMousePos, yMousePos, 742, 136, 794, 88, windowSizeX, windowSizeY);
        }
        else if (j == 4){
            return cursorInArea(xMousePos, yMousePos, 802, 136, 853, 88, windowSizeX, windowSizeY);
        }
        else if (j == 5){
            return cursorInArea(xMousePos, yMousePos, 862, 136, 913, 88, windowSizeX, windowSizeY);
        }
        else if (j == 6){
            return cursorInArea(xMousePos, yMousePos, 922, 136, 973, 88, windowSizeX, windowSizeY);
        }
        else if (j == 7){
            return cursorInArea(xMousePos, yMousePos, 983, 136, 1034, 88, windowSizeX, windowSizeY);
        }
        else if (j == 8){
            return cursorInArea(xMousePos, yMousePos, 1043, 136, 1094, 88, windowSizeX, windowSizeY);
        }
        else if (j == 9){
            return cursorInArea(xMousePos, yMousePos, 1103, 136, 1155, 88, windowSizeX, windowSizeY);
        }

    }
    
    return 0;     
                    
            
}


#endif