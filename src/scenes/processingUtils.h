#ifndef PROCESSINGUTILS_H
#define PROCESSINGUTILS_H

#define BASE_SCREEN_SIZE_X 1280
#define BASE_SCREEN_SIZE_Y 720

#define KEY_PRESSED_DELAY 0.2f

double correctXcoords(double currentXcoords, int windowSizeX);

double correctYcoords(double currentYcoords, int windowSizeY);

double correctTextSize(double currentSize, int windowSizeX, int windowSizeY);

int cursorInArea(int mousePosX, int mousePosY, int lowerLeftX, int lowerLeftY, int higherRightX, int higherRightY, int windowSizeX, int windowSizeY);

#endif