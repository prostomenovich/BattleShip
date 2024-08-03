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

    extern double lastClickTime;

    double xMousePos,
           yMousePos;
    
    changeSpriteSize(sMainMenu.ButtonPlates, windowSizeX, windowSizeY);
    changeAnimSpriteSize(sMainMenu.Background, windowSizeX, windowSizeY);

    glfwGetCursorPos(window, &xMousePos, &yMousePos);
    printf("%.2lf  %.2lf    ", xMousePos, yMousePos);
    printf("Window size: %dx%d\n", windowSizeX, windowSizeY);

    renderAnimSprite(sMainMenu.Background, SpriteShaderProgram, time(NULL), 1.0);
    renderSprite(sMainMenu.ButtonPlates, SpriteShaderProgram, FIRST_TEXTURE);
    
    if (cursorInArea(xMousePos, yMousePos, 495.0f, 617.0f, 794.0f, 512.0f, windowSizeX, windowSizeY)){
        renderText(sMainMenu.TextParams, TextShaderProgram, "Play", correctXcoords(560.0, windowSizeX) , correctYcoords(135, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
            playerInfo.scene = NEW_LOAD_MENU_SCENES;
        }
    }
    else {
        renderText(sMainMenu.TextParams, TextShaderProgram, "Play", correctXcoords(560.0, windowSizeX) , correctYcoords(135, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    if (cursorInArea(xMousePos, yMousePos, 144.0f, 608.0f, 392.0f, 523.0f, windowSizeX, windowSizeY)){
        renderText(sMainMenu.TextParams, TextShaderProgram, "About", correctXcoords(167.0, windowSizeX) , correctYcoords(128, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
            playerInfo.scene = ABOUT_LORE_SCENES;
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

    extern double lastClickTime;

    double xMousePos,
           yMousePos;
    
    changeSpriteSize(sAbout.MainPlace, windowSizeX, windowSizeY);
    changeAnimSpriteSize(sAbout.Background, windowSizeX, windowSizeY);

    glfwGetCursorPos(window, &xMousePos, &yMousePos);
    printf("%.2lf  %.2lf    ", xMousePos, yMousePos);
    printf("Window size: %dx%d\n", windowSizeX, windowSizeY);

    renderAnimSprite(sAbout.Background, SpriteShaderProgram, time(NULL), 1.0);
    renderSprite(sAbout.MainPlace, SpriteShaderProgram, FIRST_TEXTURE);

    if (cursorInArea(xMousePos, yMousePos, 277, 116, 461, 58, windowSizeX, windowSizeY) || playerInfo.scene == ABOUT_LORE_SCENES){
        renderText(sAbout.TextParams, TextShaderProgram, "Lore", correctXcoords(300.0, windowSizeX) , correctYcoords(612.0, windowSizeY), correctTextSize(1.5, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
            playerInfo.scene = ABOUT_LORE_SCENES;
        }
    }
    else{
        renderText(sAbout.TextParams, TextShaderProgram, "Lore", correctXcoords(300.0, windowSizeX) , correctYcoords(612.0, windowSizeY), correctTextSize(1.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    if (cursorInArea(xMousePos, yMousePos, 499, 116, 680, 60, windowSizeX, windowSizeY) || playerInfo.scene == ABOUT_RULES_SCENES){
        renderText(sAbout.TextParams, TextShaderProgram, "Rules", correctXcoords(510.0, windowSizeX) , correctYcoords(612.0, windowSizeY), correctTextSize(1.5, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
            playerInfo.scene = ABOUT_RULES_SCENES;
        }
    }
    else{
        renderText(sAbout.TextParams, TextShaderProgram, "Rules", correctXcoords(510.0, windowSizeX) , correctYcoords(612.0, windowSizeY), correctTextSize(1.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    if (cursorInArea(xMousePos, yMousePos, 720, 116, 901, 60, windowSizeX, windowSizeY) || playerInfo.scene == ABOUT_AUTHORS_SCENES){
        renderText(sAbout.TextParams, TextShaderProgram, "Authors", correctXcoords(733.0, windowSizeX) , correctYcoords(618.0, windowSizeY), correctTextSize(1.0, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
            playerInfo.scene = ABOUT_AUTHORS_SCENES;
        }
    }
    else{
        renderText(sAbout.TextParams, TextShaderProgram, "Authors", correctXcoords(733.0, windowSizeX) , correctYcoords(618.0, windowSizeY), correctTextSize(1.0, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    if (cursorInArea(xMousePos, yMousePos, 934, 116, 1013, 60, windowSizeX, windowSizeY)){
        renderSprite(sAbout.ExitButton, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
            playerInfo.scene = MAIN_MENU_SCENES;
        }
    }
    else{
        renderSprite(sAbout.ExitButton, SpriteShaderProgram, FIRST_TEXTURE);
    }

    

    if (playerInfo.scene == ABOUT_LORE_SCENES){


    }
    else if (playerInfo.scene == ABOUT_RULES_SCENES){


    }
    else if (playerInfo.scene == ABOUT_AUTHORS_SCENES){


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

    extern double lastClickTime;

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
                playerInfo.scene = GAME_SETTING_MENU;
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
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            playerInfo.scene = MAIN_MENU_SCENES;
            lastClickTime = glfwGetTime();
        }
    }
    else{
        renderText(sNewLoadMenu.TextParams, TextShaderProgram, "BACK", correctXcoords(55.0, windowSizeX) , correctYcoords(632, windowSizeY), correctTextSize(1.65, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }
}

void renderGameSettingsMenu(GLFWwindow* window)
{
    extern GLuint SpriteShaderProgram;
    extern GLuint TextShaderProgram;
    extern GameSettingsMenu sGameSettingsMenu;
    extern Player playerInfo;

    extern int windowSizeX;
    extern int windowSizeY;

    extern double lastClickTime;

    double xMousePos,
           yMousePos;
    
    changeAnimSpriteSize(sGameSettingsMenu.Background, windowSizeX, windowSizeY);

    glfwGetCursorPos(window, &xMousePos, &yMousePos);
    printf("%.2lf  %.2lf    ", xMousePos, yMousePos);
    printf("Window size: %dx%d\n", windowSizeX, windowSizeY);

    renderAnimSprite(sGameSettingsMenu.Background, SpriteShaderProgram, time(NULL), 1.0);

    if (playerInfo.GameMode == NOT_FILLED_IN){
        changeSpriteSize(sGameSettingsMenu.ButtonPlatesChooseGM, windowSizeX, windowSizeY);
        changeSpriteSize(sGameSettingsMenu.PirateWMGM, windowSizeX, windowSizeY);

        renderSprite(sGameSettingsMenu.PirateWMGM, SpriteShaderProgram, FIRST_TEXTURE);
        renderSprite(sGameSettingsMenu.ButtonPlatesChooseGM, SpriteShaderProgram, FIRST_TEXTURE);
        
        if (cursorInArea(xMousePos, yMousePos, 45, 96, 239, 33, windowSizeX, windowSizeY)){
            renderText(sGameSettingsMenu.TextParams, TextShaderProgram, "BACK", correctXcoords(55.0, windowSizeX) , correctYcoords(632, windowSizeY), correctTextSize(1.65, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                playerInfo.scene = NEW_LOAD_MENU_SCENES;
                playerInfo.GameMode = NOT_FILLED_IN;
                lastClickTime = glfwGetTime();
            }
        }
        else{
            renderText(sGameSettingsMenu.TextParams, TextShaderProgram, "BACK", correctXcoords(55.0, windowSizeX) , correctYcoords(632, windowSizeY), correctTextSize(1.65, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

        if (cursorInArea(xMousePos, yMousePos, 688, 479, 1095, 363, windowSizeX, windowSizeY)){
            renderText(sGameSettingsMenu.TextParams, TextShaderProgram, "BASIC", correctXcoords(755.0, windowSizeX) , correctYcoords(262, windowSizeY), correctTextSize(2.5, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
                playerInfo.GameMode = BASIC_MODE;
            }
        }
        else{
            renderText(sGameSettingsMenu.TextParams, TextShaderProgram, "BASIC", correctXcoords(755.0, windowSizeX) , correctYcoords(262, windowSizeY), correctTextSize(2.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

        if (cursorInArea(xMousePos, yMousePos, 690, 636, 1095, 520, windowSizeX, windowSizeY)){
            renderText(sGameSettingsMenu.TextParams, TextShaderProgram, "BOTS FIGHT", correctXcoords(722.0, windowSizeX) , correctYcoords(122, windowSizeY), correctTextSize(1.6, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
                playerInfo.GameMode = BOTS_FIGHT_MODE;
            }
        }
        else{
            renderText(sGameSettingsMenu.TextParams, TextShaderProgram, "BOTS FIGHT", correctXcoords(722.0, windowSizeX) , correctYcoords(122, windowSizeY), correctTextSize(1.6, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

    }
    else if(playerInfo.MapSize == NOT_FILLED_IN){
        changeSpriteSize(sGameSettingsMenu.ButtonPlatesChooseBFS, windowSizeX, windowSizeY);
        changeSpriteSize(sGameSettingsMenu.PirateWMBFS, windowSizeX, windowSizeY);

        renderSprite(sGameSettingsMenu.PirateWMBFS, SpriteShaderProgram, FIRST_TEXTURE);
        renderSprite(sGameSettingsMenu.ButtonPlatesChooseBFS, SpriteShaderProgram, FIRST_TEXTURE);

        if (cursorInArea(xMousePos, yMousePos, 45, 96, 239, 33, windowSizeX, windowSizeY)){
            renderText(sGameSettingsMenu.TextParams, TextShaderProgram, "BACK", correctXcoords(55.0, windowSizeX) , correctYcoords(632, windowSizeY), correctTextSize(1.65, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                playerInfo.GameMode = NOT_FILLED_IN;
                lastClickTime = glfwGetTime();
            }
        }
        else{
            renderText(sGameSettingsMenu.TextParams, TextShaderProgram, "BACK", correctXcoords(55.0, windowSizeX) , correctYcoords(632, windowSizeY), correctTextSize(1.65, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

        if (cursorInArea(xMousePos, yMousePos, 173, 459, 520, 331, windowSizeX, windowSizeY)){
            renderText(sGameSettingsMenu.TextParams, TextShaderProgram, "10x10", correctXcoords(205.0, windowSizeX) , correctYcoords(292, windowSizeY), correctTextSize(2.5, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
                playerInfo.MapSize = MAP_SIZE_10_X_10;
            }
        }
        else{
            renderText(sGameSettingsMenu.TextParams, TextShaderProgram, "10x10", correctXcoords(205.0, windowSizeX) , correctYcoords(292, windowSizeY), correctTextSize(2.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

        if (cursorInArea(xMousePos, yMousePos, 173, 622, 520, 499, windowSizeX, windowSizeY)){
            renderText(sGameSettingsMenu.TextParams, TextShaderProgram, "15x15", correctXcoords(205.0, windowSizeX) , correctYcoords(127, windowSizeY), correctTextSize(2.5, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
                playerInfo.MapSize = MAP_SIZE_15_X_15;
            }
        }
        else{
            renderText(sGameSettingsMenu.TextParams, TextShaderProgram, "15x15", correctXcoords(205.0, windowSizeX) , correctYcoords(127, windowSizeY), correctTextSize(2.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

    }
}
#endif