#include "scenesRendering.h"

#ifndef SCENESRENDERING_C
#define SCENESRENDERING_C

void renderMainMenu(GLFWwindow* window)
{
    extern GLuint SpriteShaderProgram;
    extern GLuint TextShaderProgram;
    extern MainMenu sMainMenu;
    extern Player playerInfo;

    extern int windowSizeX;
    extern int windowSizeY;

    double xMousePos,
           yMousePos;
    
    changeSpriteSize(sMainMenu.ButtonPlates, windowSizeX, windowSizeY);
    changeAnimSpriteSize(sMainMenu.Background, windowSizeX, windowSizeY);


    glfwGetCursorPos(window, &xMousePos, &yMousePos);
    printf("%.2lf  %.2lf    ", xMousePos, yMousePos);
    printf("Window size: %dx%d\n", windowSizeX, windowSizeY);

    renderAnimSprite(sMainMenu.Background, SpriteShaderProgram, time(NULL), 1.0);


    renderSprite(sMainMenu.ButtonPlates, SpriteShaderProgram, FIRST_TEXTURE);

    //glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && 
    
    if (cursorInArea(xMousePos, yMousePos, 495.0f, 617.0f, 794.0f, 512.0f, windowSizeX, windowSizeY)){
        renderText(sMainMenu.TextParams, TextShaderProgram, "Play", correctXcoords(560.0, windowSizeX) , correctYcoords(135, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
            playerInfo.state = NEW_LOAD_MENU_SCENES;
        }
    }
    else {
        renderText(sMainMenu.TextParams, TextShaderProgram, "Play", correctXcoords(560.0, windowSizeX) , correctYcoords(135, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    if (cursorInArea(xMousePos, yMousePos, 144.0f, 608.0f, 392.0f, 523.0f, windowSizeX, windowSizeY)){
        renderText(sMainMenu.TextParams, TextShaderProgram, "About", correctXcoords(167.0, windowSizeX) , correctYcoords(128, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
            playerInfo.state = ABOUT_LORE_SCENES;
        }
    }
    else {
        renderText(sMainMenu.TextParams, TextShaderProgram, "About", correctXcoords(167.0, windowSizeX) , correctYcoords(128, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    if (cursorInArea(xMousePos, yMousePos, 906.0f, 606.0f, 1142.0f, 526.0f, windowSizeX, windowSizeY)){
        renderText(sMainMenu.TextParams, TextShaderProgram, "Leaders", correctXcoords(905.0, windowSizeX) , correctYcoords(135, windowSizeY), correctTextSize(1.4, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
    }
    else {
        renderText(sMainMenu.TextParams, TextShaderProgram, "Leaders", correctXcoords(905.0, windowSizeX) , correctYcoords(135, windowSizeY), correctTextSize(1.4, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }
}

void renderAbout(GLFWwindow* window)
{
    extern GLuint SpriteShaderProgram;
    extern GLuint TextShaderProgram;
    extern About sAbout;
    extern Player playerInfo;

    extern int windowSizeX;
    extern int windowSizeY;

    double xMousePos,
           yMousePos;
    
    changeSpriteSize(sAbout.MainPlace, windowSizeX, windowSizeY);
    changeAnimSpriteSize(sAbout.Background, windowSizeX, windowSizeY);

    glfwGetCursorPos(window, &xMousePos, &yMousePos);
    printf("%.2lf  %.2lf    ", xMousePos, yMousePos);
    printf("Window size: %dx%d\n", windowSizeX, windowSizeY);

    renderAnimSprite(sAbout.Background, SpriteShaderProgram, time(NULL), 1.0);
    renderSprite(sAbout.MainPlace, SpriteShaderProgram, FIRST_TEXTURE);

    if (cursorInArea(xMousePos, yMousePos, 277, 116, 461, 58, windowSizeX, windowSizeY) || playerInfo.state == ABOUT_LORE_SCENES){
        renderText(sAbout.TextParams, TextShaderProgram, "Lore", correctXcoords(300.0, windowSizeX) , correctYcoords(612.0, windowSizeY), correctTextSize(1.5, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
            playerInfo.state = ABOUT_LORE_SCENES;
        }
    }
    else{
        renderText(sAbout.TextParams, TextShaderProgram, "Lore", correctXcoords(300.0, windowSizeX) , correctYcoords(612.0, windowSizeY), correctTextSize(1.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    if (cursorInArea(xMousePos, yMousePos, 499, 116, 680, 60, windowSizeX, windowSizeY) || playerInfo.state == ABOUT_RULES_SCENES){
        renderText(sAbout.TextParams, TextShaderProgram, "Rules", correctXcoords(510.0, windowSizeX) , correctYcoords(612.0, windowSizeY), correctTextSize(1.5, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
            playerInfo.state = ABOUT_RULES_SCENES;
        }
    }
    else{
        renderText(sAbout.TextParams, TextShaderProgram, "Rules", correctXcoords(510.0, windowSizeX) , correctYcoords(612.0, windowSizeY), correctTextSize(1.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    if (cursorInArea(xMousePos, yMousePos, 720, 116, 901, 60, windowSizeX, windowSizeY) || playerInfo.state == ABOUT_AUTHORS_SCENES){
        renderText(sAbout.TextParams, TextShaderProgram, "Authors", correctXcoords(733.0, windowSizeX) , correctYcoords(618.0, windowSizeY), correctTextSize(1.0, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
            playerInfo.state = ABOUT_AUTHORS_SCENES;
        }
    }
    else{
        renderText(sAbout.TextParams, TextShaderProgram, "Authors", correctXcoords(733.0, windowSizeX) , correctYcoords(618.0, windowSizeY), correctTextSize(1.0, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    if (cursorInArea(xMousePos, yMousePos, 934, 116, 1013, 60, windowSizeX, windowSizeY)){
        renderSprite(sAbout.ExitButton, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
            playerInfo.state = MAIN_MENU_SCENES;
        }
    }
    else{
        renderSprite(sAbout.ExitButton, SpriteShaderProgram, FIRST_TEXTURE);
    }

    

    if (playerInfo.state == ABOUT_LORE_SCENES){


    }
    else if (playerInfo.state == ABOUT_RULES_SCENES){


    }
    else if (playerInfo.state == ABOUT_AUTHORS_SCENES){


    }

}

void renderNewLoadMenu(GLFWwindow* window)
{
    extern GLuint SpriteShaderProgram;
    extern GLuint TextShaderProgram;
    extern NewLoadMenu sNewLoadMenu;
    extern Player playerInfo;

    extern int windowSizeX;
    extern int windowSizeY;

    double xMousePos,
           yMousePos;
    
    changeSpriteSize(sNewLoadMenu.ButtonPlates, windowSizeX, windowSizeY);
    changeAnimSpriteSize(sNewLoadMenu.Background, windowSizeX, windowSizeY);

    glfwGetCursorPos(window, &xMousePos, &yMousePos);
    printf("%.2lf  %.2lf    ", xMousePos, yMousePos);
    printf("Window size: %dx%d\n", windowSizeX, windowSizeY);

    renderAnimSprite(sNewLoadMenu.Background, SpriteShaderProgram, time(NULL), 1.0);
    renderSprite(sNewLoadMenu.ButtonPlates, SpriteShaderProgram, FIRST_TEXTURE);

    
    
    if (cursorInArea(xMousePos, yMousePos, 441, 372, 838, 265, windowSizeX, windowSizeY)){
            renderText(sNewLoadMenu.TextParams, TextShaderProgram, "NEW GAME", correctXcoords(465.0, windowSizeX) , correctYcoords(375, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);        
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
                
            }
    }
    else{
        renderText(sNewLoadMenu.TextParams, TextShaderProgram, "NEW GAME", correctXcoords(465.0, windowSizeX) , correctYcoords(375, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }


    if (cursorInArea(xMousePos, yMousePos, 434, 534, 841, 421, windowSizeX, windowSizeY)){
            renderText(sNewLoadMenu.TextParams, TextShaderProgram, "LOAD GAME", correctXcoords(458.0, windowSizeX) , correctYcoords(222, windowSizeY), correctTextSize(1.65, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
                
            }
    }
    else{
        renderText(sNewLoadMenu.TextParams, TextShaderProgram, "LOAD GAME", correctXcoords(458.0, windowSizeX) , correctYcoords(222, windowSizeY), correctTextSize(1.65, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }


    if (cursorInArea(xMousePos, yMousePos, 45, 96, 239, 33, windowSizeX, windowSizeY)){
        renderText(sNewLoadMenu.TextParams, TextShaderProgram, "BACK", correctXcoords(55.0, windowSizeX) , correctYcoords(632, windowSizeY), correctTextSize(1.65, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
            playerInfo.state = MAIN_MENU_SCENES;
        }
    }
    else{
        renderText(sNewLoadMenu.TextParams, TextShaderProgram, "BACK", correctXcoords(55.0, windowSizeX) , correctYcoords(632, windowSizeY), correctTextSize(1.65, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }
}
#endif