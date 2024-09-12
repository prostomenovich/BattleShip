#include "processingUtils.h"

#ifndef PROCESSINGUTILS_C
#define PROCESSINGUTILS_C

//Восстанавливает корректное положение по X в случае ихменения размер окна (не используется в большинстве сцен)
double correctXcoords(double currentXcoords, int windowSizeX)
{
    return currentXcoords * (double)windowSizeX / BASE_SCREEN_SIZE_X;
}

//Восстанавливает корректное положение по Y в случае ихменения размер окна (не используется в большинстве сцен)
double correctYcoords(double currentYcoords, int windowSizeY)
{
    return currentYcoords * (double)windowSizeY / BASE_SCREEN_SIZE_Y;
}

//Восстанавливает корректный размер текста в соответствии с разрешением экрана (не применяется в больштнстве сцен)
double correctTextSize(double currentSize, int windowSizeX, int windowSizeY)
{
    return ((currentSize * windowSizeX * windowSizeY) / ( BASE_SCREEN_SIZE_X * BASE_SCREEN_SIZE_Y)); 
}

//Проверяет находится ли курсор в заданной области
int cursorInArea(int mousePosX, int mousePosY, int lowerLeftX, int lowerLeftY, int higherRightX, int higherRightY, int windowSizeX, int windowSizeY)
{
    return mousePosX >= correctXcoords(lowerLeftX, windowSizeX) && mousePosY <= correctYcoords(lowerLeftY, windowSizeY) && mousePosX <= correctXcoords(higherRightX, windowSizeX) && mousePosY >= correctYcoords(higherRightY, windowSizeY);
}

//Пересчитывает параметры справйта в соответствии с рамером экрана (не применяется в большинстве сцен)
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

//Переводит число в строку
void intToString(char* str, int digit)
{
    char tmp[3] = {'\0', };
    for (int i = 0; i < 2 && digit != 0; i++){
        tmp[i] = '0' + (digit % 10);
        digit /= 10;
    }

    for (int i = 1, j = 0; i >= 0; i--){
        str[j++] = tmp[i];
    }

}

//Обработка ввода с клавиатуры
int getWord(char* string, int maxStringSize, GLFWwindow* window)
{
    static int index = 0;
    static int lastPressedButton = -100;
    static double lastPressTime = 0.0;

    if (string != NULL){
        if (index == maxStringSize && glfwGetKey(window, GLFW_KEY_BACKSPACE) != GLFW_PRESS){
            string[index - 1] = '\0';
            return 0;
        }

        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){
            string[index++] = 'A';
            lastPressTime = glfwGetTime();
        } 
        else if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){
            string[index++] = 'B';
            lastPressTime = glfwGetTime();
        } 
        else if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){
            string[index++] = 'C';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY) {
            string[index++] = 'D';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){
            string[index++] = 'E';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){
             string[index++] = 'F';
             lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){
             string[index++] = 'G';
             lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){
            string[index++] = 'H';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){
            string[index++] = 'I';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){
            string[index++] = 'J';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){
            string[index++] = 'K';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){
            string[index++] = 'L';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'M';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'N';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'O';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'P';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'Q';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'R';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'S';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'T';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'U';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'V';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'W';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'X';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'Y';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'Z';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = '!';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){
            string[index++] = '@';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){
            string[index++] = '#';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = '$';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = '%';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = '*';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = '(';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = ')';
            lastPressTime = glfwGetTime();
        }



        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS &&  glfwGetTime() - lastPressTime >= BTN_DELAY){
            string[index++] = 'a';
            lastPressTime = glfwGetTime();
        } 
        else if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS &&  glfwGetTime() - lastPressTime >= BTN_DELAY){
            string[index++] = 'b';
            lastPressTime = glfwGetTime();
        } 
        else if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS &&  glfwGetTime() - lastPressTime >= BTN_DELAY){
            string[index++] = 'c';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY) {
            string[index++] = 'd';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){
            string[index++] = 'e';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){
             string[index++] = 'f';
             lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){
             string[index++] = 'g';
             lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){
            string[index++] = 'h';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){
            string[index++] = 'i';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){
            string[index++] = 'j';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){
            string[index++] = 'k';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){
            string[index++] = 'l';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'm';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'n';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'o';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'p';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'q';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'r';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 's';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 't';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'u';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'v';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'w';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'x';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'y';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = 'z';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = '1';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){
            string[index++] = '2';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){
            string[index++] = '3';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = '4';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = '5';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = '6';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = '7';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = '8';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = '9';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = '0';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){ 
            string[index++] = ' ';
            lastPressTime = glfwGetTime();
        }
        else if (glfwGetKey(window, GLFW_KEY_BACKSPACE) == GLFW_PRESS && glfwGetTime() - lastPressTime >= BTN_DELAY){
            if (index > 0){
                string[index - 1] = '\0';
                index --;
            }
            else string[index] = '\0'; 
            lastPressTime = glfwGetTime();
        } 
        return maxStringSize - index;
    }
    else {
        index = 0;
        return -1;
    }
}
#endif