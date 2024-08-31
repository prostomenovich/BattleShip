#include "scenesRendering.h"

#ifndef SCENESRENDERING_C
#define SCENESRENDERING_C

int botMode = ATTACK_MODE;
int botMode1 = ATTACK_MODE,
    botMode2 = ATTACK_MODE;

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
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            playerInfo.scene = NEW_LOAD_MENU_SCENES;
            lastClickTime = glfwGetTime();
        }
    }
    else {
        renderText(sMainMenu.TextParams, TextShaderProgram, "Play", correctXcoords(560.0, windowSizeX) , correctYcoords(135, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    if (cursorInArea(xMousePos, yMousePos, 144.0f, 608.0f, 392.0f, 523.0f, windowSizeX, windowSizeY)){
        renderText(sMainMenu.TextParams, TextShaderProgram, "About", correctXcoords(167.0, windowSizeX) , correctYcoords(128, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            playerInfo.scene = ABOUT_LORE_SCENES;
            lastClickTime = glfwGetTime();
        }
    }
    else {
        renderText(sMainMenu.TextParams, TextShaderProgram, "About", correctXcoords(167.0, windowSizeX) , correctYcoords(128, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    if (cursorInArea(xMousePos, yMousePos, 906.0f, 606.0f, 1142.0f, 526.0f, windowSizeX, windowSizeY)){
        renderText(sMainMenu.TextParams, TextShaderProgram, "Leaders", correctXcoords(905.0, windowSizeX) , correctYcoords(135, windowSizeY), correctTextSize(1.4, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            playerInfo.scene = LEADERS_SCENES;
            lastClickTime = glfwGetTime();
        }
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

    extern char AboutAuthors [][MAX_STRING_SIZE];
    extern const int AboutAuthorsStringCount;

    extern char AboutLore [][MAX_STRING_SIZE];
    extern const int AboutLoreStringCount;

    extern char AboutRules [][MAX_STRING_SIZE];
    extern const int AboutRulesStringCount;

    extern int windowSizeX;
    extern int windowSizeY;

    extern double lastClickTime;

    static int paginationStringStart = 0;

    double xMousePos,
           yMousePos;
    
    changeSpriteSize(sAbout.MainPlace, windowSizeX, windowSizeY);
    changeCorrectSpriteParams(sAbout.ExitButton, windowSizeX, windowSizeY);
    changeAnimSpriteSize(sAbout.Background, windowSizeX, windowSizeY);

    glfwGetCursorPos(window, &xMousePos, &yMousePos);
    printf("%.2lf  %.2lf    ", xMousePos, yMousePos);
    printf("Window size: %dx%d\n", windowSizeX, windowSizeY);

    renderAnimSprite(sAbout.Background, SpriteShaderProgram, time(NULL), 1.0);
    renderSprite(sAbout.MainPlace, SpriteShaderProgram, FIRST_TEXTURE);

    if (cursorInArea(xMousePos, yMousePos, 277, 116, 461, 58, windowSizeX, windowSizeY) || playerInfo.scene == ABOUT_LORE_SCENES){
        renderText(sAbout.TextParams1, TextShaderProgram, "Lore", correctXcoords(300.0, windowSizeX) , correctYcoords(612.0, windowSizeY), correctTextSize(1.5, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
            playerInfo.scene = ABOUT_LORE_SCENES;
        }
    }
    else{
        renderText(sAbout.TextParams1, TextShaderProgram, "Lore", correctXcoords(300.0, windowSizeX) , correctYcoords(612.0, windowSizeY), correctTextSize(1.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    if (cursorInArea(xMousePos, yMousePos, 499, 116, 680, 60, windowSizeX, windowSizeY) || playerInfo.scene == ABOUT_RULES_SCENES){
        renderText(sAbout.TextParams1, TextShaderProgram, "Rules", correctXcoords(510.0, windowSizeX) , correctYcoords(612.0, windowSizeY), correctTextSize(1.5, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
            playerInfo.scene = ABOUT_RULES_SCENES;
        }
    }
    else{
        renderText(sAbout.TextParams1, TextShaderProgram, "Rules", correctXcoords(510.0, windowSizeX) , correctYcoords(612.0, windowSizeY), correctTextSize(1.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    if (cursorInArea(xMousePos, yMousePos, 720, 116, 901, 60, windowSizeX, windowSizeY) || playerInfo.scene == ABOUT_AUTHORS_SCENES){
        renderText(sAbout.TextParams1, TextShaderProgram, "Authors", correctXcoords(733.0, windowSizeX) , correctYcoords(618.0, windowSizeY), correctTextSize(1.0, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
            playerInfo.scene = ABOUT_AUTHORS_SCENES;
        }
    }
    else{
        renderText(sAbout.TextParams1, TextShaderProgram, "Authors", correctXcoords(733.0, windowSizeX) , correctYcoords(618.0, windowSizeY), correctTextSize(1.0, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }


    if (cursorInArea(xMousePos, yMousePos, 934, 116, 1013, 60, windowSizeX, windowSizeY)){
        renderSprite(sAbout.ExitButton, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
            paginationStringStart = 0;
            playerInfo.scene = MAIN_MENU_SCENES;
        }
    }
    else{
        renderSprite(sAbout.ExitButton, SpriteShaderProgram, FIRST_TEXTURE);
    }


    if (playerInfo.scene == ABOUT_LORE_SCENES){
        for (int i = 0, startY = 530; i < AboutLoreStringCount; i++, startY -= 25){
            renderText(sAbout.TextParams2, TextShaderProgram, AboutLore[i], correctXcoords(340.0, windowSizeX) , correctYcoords(startY, windowSizeY), correctTextSize(0.41, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

    }
    else if (playerInfo.scene == ABOUT_RULES_SCENES){
        renderSprite(sAbout.paginationPlates, SpriteShaderProgram, FIRST_TEXTURE);
        //Обработка пагинации вверх
        if (cursorInArea(xMousePos, yMousePos, 1068, 345, 1155, 277, windowSizeX, windowSizeY)){
            renderSprite(sAbout.pagUp, SpriteShaderProgram, SECOND_TEXTURE);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                if (paginationStringStart - 18 >= 0) paginationStringStart -= 18;
                lastClickTime = glfwGetTime();
            }
        }
        else{
            renderSprite(sAbout.pagUp, SpriteShaderProgram, FIRST_TEXTURE);
        }

        //Обработка пагинации вниз
        if (cursorInArea(xMousePos, yMousePos, 1068, 463, 1155, 375, windowSizeX, windowSizeY)){
            renderSprite(sAbout.pagDown, SpriteShaderProgram, SECOND_TEXTURE);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                if (paginationStringStart + 18 < AboutRulesStringCount) paginationStringStart += 18;
                lastClickTime = glfwGetTime();
            }
        }
        else{
            renderSprite(sAbout.pagDown, SpriteShaderProgram, FIRST_TEXTURE);
        }
        int paginEnd = (paginationStringStart + 18 > AboutRulesStringCount) ? (AboutRulesStringCount) : (paginationStringStart + 18);

        for (int i = paginationStringStart, startY = 530; i < paginEnd; i++, startY -= 25){
            renderText(sAbout.TextParams2, TextShaderProgram, AboutRules[i], correctXcoords(340.0, windowSizeX) , correctYcoords(startY, windowSizeY), correctTextSize(0.41, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }
    }
    else if (playerInfo.scene == ABOUT_AUTHORS_SCENES){
        for (int i = 0, startY = 530; i < AboutAuthorsStringCount; i++, startY -= 25){
            renderText(sAbout.TextParams2, TextShaderProgram, AboutAuthors[i], correctXcoords(340.0, windowSizeX) , correctYcoords(startY, windowSizeY), correctTextSize(0.41, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

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
                playerInfo.scene = LOAD_GAME_SCENES;
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
    else if (playerInfo.BotLevel == NOT_FILLED_IN){
        changeSpriteSize(sGameSettingsMenu.ButtonPlatesChooseBL, windowSizeX, windowSizeY);
        changeSpriteSize(sGameSettingsMenu.PirateWMBL, windowSizeX, windowSizeY);

        renderSprite(sGameSettingsMenu.PirateWMBL, SpriteShaderProgram, FIRST_TEXTURE);
        renderSprite(sGameSettingsMenu.ButtonPlatesChooseBL, SpriteShaderProgram, FIRST_TEXTURE);

        if (cursorInArea(xMousePos, yMousePos, 45, 96, 239, 33, windowSizeX, windowSizeY)){
            renderText(sGameSettingsMenu.TextParams, TextShaderProgram, "BACK", correctXcoords(55.0, windowSizeX) , correctYcoords(632, windowSizeY), correctTextSize(1.65, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                playerInfo.MapSize = NOT_FILLED_IN;
                lastClickTime = glfwGetTime();
            }
        }
        else{
            renderText(sGameSettingsMenu.TextParams, TextShaderProgram, "BACK", correctXcoords(55.0, windowSizeX) , correctYcoords(632, windowSizeY), correctTextSize(1.65, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

        if (cursorInArea(xMousePos, yMousePos, 38, 587, 384, 469, windowSizeX, windowSizeY)){
            renderText(sGameSettingsMenu.TextParams, TextShaderProgram, "EASY", correctXcoords(97.0, windowSizeX) , correctYcoords(164, windowSizeY), correctTextSize(2.2, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                playerInfo.BotLevel = EASY_BOT_LEVEL;
                lastClickTime = glfwGetTime();
            }
        }
        else{
            renderText(sGameSettingsMenu.TextParams, TextShaderProgram, "EASY", correctXcoords(97.0, windowSizeX) , correctYcoords(164, windowSizeY), correctTextSize(2.2, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

        if (cursorInArea(xMousePos, yMousePos, 467, 588, 811, 469, windowSizeX, windowSizeY)){
            renderText(sGameSettingsMenu.TextParams, TextShaderProgram, "NORMAL", correctXcoords(498.0, windowSizeX) , correctYcoords(168, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                playerInfo.BotLevel = NORMAL_BOT_LEVEL;
                lastClickTime = glfwGetTime();
            }
        }
        else{
            renderText(sGameSettingsMenu.TextParams, TextShaderProgram, "NORMAL", correctXcoords(498.0, windowSizeX) , correctYcoords(168, windowSizeY), correctTextSize(1.8 , windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

        if (cursorInArea(xMousePos, yMousePos, 889, 590, 1235, 468, windowSizeX, windowSizeY)){
            renderText(sGameSettingsMenu.TextParams, TextShaderProgram, "HARD", correctXcoords(955.0, windowSizeX) , correctYcoords(164, windowSizeY), correctTextSize(2.2, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                playerInfo.BotLevel = HARD_BOT_LEVEL;
                lastClickTime = glfwGetTime();
            }
        }
        else{
            renderText(sGameSettingsMenu.TextParams, TextShaderProgram, "HARD", correctXcoords(955.0, windowSizeX) , correctYcoords(164, windowSizeY), correctTextSize(2.2, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }
        
        if (playerInfo.BotLevel != NOT_FILLED_IN){
            if (playerInfo.MapSize == MAP_SIZE_10_X_10 && playerInfo.GameMode == BASIC_MODE)
                playerInfo.scene = RAFT_PLACEMENT_10_X_10_BASE;
            else if (playerInfo.MapSize == MAP_SIZE_15_X_15 && playerInfo.GameMode == BASIC_MODE)
                playerInfo.scene = RAFT_PLACEMENT_15_X_15_BASE; 
            else if (playerInfo.MapSize == MAP_SIZE_10_X_10 && playerInfo.GameMode == BOTS_FIGHT_MODE)
                playerInfo.scene = RAFT_PLACEMENT_10_X_10_BOTS_FIGHT_BOT_1;
            else if (playerInfo.MapSize == MAP_SIZE_15_X_15 && playerInfo.GameMode == BOTS_FIGHT_MODE)
                playerInfo.scene = RAFT_PLACEMENT_15_X_15_BOTS_FIGHT_BOT_1;    
            else if (playerInfo.MapSize == MAP_SIZE_10_X_10 && playerInfo.GameMode == BOTS_FIGHT_MODE){
                playerInfo.scene = MAIN_GAME_BOT_FIGHT_10_X_10;
            }
        }
    }
    
}


void renderRaftPlacement10x10(GLFWwindow* window)
{
    extern GLuint SpriteShaderProgram;
    extern GLuint TextShaderProgram;
    extern RaftPlacement10x10 sRaftPlacement10X10;
    extern MainGameBase10x10 sMainGameBase10x10;
    extern Player playerInfo;
    extern ShipBase* shipBase;
    extern ShipBase* botShipBase;
    extern Coordinates* coords[5];

    extern int map[18][18];
    extern int mapBot[18][18];

    extern int windowSizeX;
    extern int windowSizeY;

    extern double lastClickTime;

    double xMousePos,
           yMousePos;

    char CanPutShips[2] = {'\0',};

    static int elemCount = 0, first = 0;
    int maxElemCount = maxPlatesShip(shipBase);

    extern char FAQRaftPlacement[8][MAX_STRING_SIZE];
    extern const int FAQRaftPlacementStringCount;

    static int lastSceneState = 0;
    
    glfwGetCursorPos(window, &xMousePos, &yMousePos);
    printf("%.2lf  %.2lf    ", xMousePos, yMousePos);
    printf("Window size: %dx%d\n", windowSizeX, windowSizeY);

    changeSpriteSize(sRaftPlacement10X10.Background, windowSizeX, windowSizeY);
    changeSpriteSize(sRaftPlacement10X10.ButtonPlates, windowSizeX, windowSizeY);
    changeSpriteSize(sRaftPlacement10X10.Map10x10, windowSizeX, windowSizeY);

    //Если сцена открывается повторно нужно снова выделить память под данные о кораблях
    if (shipBase == NULL){
        shipBase = initShipBase(MAP_SIZE_10_X_10);
    }

    if (first == 0){
        clearMap(map);
        first++;
    }

    //Подгон под размер окна каждой клетки на поле
    for (int i = 0 ; i < 10; i++){
        for (int j = 0; j < 10; j++){
            Sprite* sp = sRaftPlacement10X10.MapArray[i][j].sprite;
            changeCorrectSpriteParams(sp, windowSizeX, windowSizeY);
        }
    }
    
    
    renderSprite(sRaftPlacement10X10.Background, SpriteShaderProgram, FIRST_TEXTURE);
    
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY && sRaftPlacement10X10.state != FAQ){
        if (sRaftPlacement10X10.state == IN_EDIT_MODE){
            sRaftPlacement10X10.state = NOT_IN_EDIT_MODE;
            if (shipIsCorrect(map, shipBase, elemCount, MAP_SIZE_10_X_10, coords) == SHIP_IS_CORRECT){
                printf("IS_CORRECT!\n");
                putShipInBase(shipBase, coords, elemCount);
                putShipInMap(map, coords, elemCount);
                for (int i = 0 ; i < 10; i++){
                    for (int j = 0; j < 10; j++){
                        if (sRaftPlacement10X10.MapArray[i][j].spriteState == PLATE_PRESSED){
                            sRaftPlacement10X10.MapArray[i][j].spriteState = PLATE_SUCCES;
                                
                        }
                    }
                }
                elemCount = 0;
                //Все клетки, где нельзя ставить корабль помечаются красным
                for (int i = 1; i <= 10; i++){
                    for (int j = 1; j <= 10; j++){
                        if (map[i][j] == 1){
                            sRaftPlacement10X10.MapArray[i - 1][j - 1].spriteState = PLATE_ERROR;
                        }
                    }
                }

            }
            else {
                printf("IS_NOT_CORRECT!\n");
                for (int i = 0 ; i < 10; i++){
                    for (int j = 0; j < 10; j++){
                        if (sRaftPlacement10X10.MapArray[i][j].spriteState == PLATE_PRESSED){
                            sRaftPlacement10X10.MapArray[i][j].spriteState = PLATE_NOT_PRESSED;    
                        }
                    }
                }
            }
            elemCount = 0;
        }
        else sRaftPlacement10X10.state = IN_EDIT_MODE;
        lastClickTime = glfwGetTime();
    }


    if (sRaftPlacement10X10.state == IN_EDIT_MODE && sRaftPlacement10X10.state != FAQ){

        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && cursorInArea(xMousePos, yMousePos, sRaftPlacement10X10.MapArray[i][j].sprite->positionX, windowSizeY - sRaftPlacement10X10.MapArray[i][j].sprite->positionY, sRaftPlacement10X10.MapArray[i][j].sprite->positionX + sRaftPlacement10X10.MapArray[i][j].sprite->sizeX, windowSizeY - sRaftPlacement10X10.MapArray[i][j].sprite->positionY - sRaftPlacement10X10.MapArray[i][j].sprite->sizeY, windowSizeX, windowSizeY) && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                    if (sRaftPlacement10X10.MapArray[i][j].spriteState == PLATE_PRESSED){
                        sRaftPlacement10X10.MapArray[i][j].spriteState = PLATE_NOT_PRESSED;
                        elemCount--;
                    }
                    else {
                        if (elemCount < maxElemCount && sRaftPlacement10X10.MapArray[i][j].spriteState != PLATE_SUCCES && sRaftPlacement10X10.MapArray[i][j].spriteState != PLATE_ERROR){
                            sRaftPlacement10X10.MapArray[i][j].spriteState = PLATE_PRESSED;
                            coords[elemCount]->x = j;
                            coords[elemCount]->y = i;
                            elemCount++;
                        }
                    }

                    lastClickTime = glfwGetTime();
                }

                if (sRaftPlacement10X10.MapArray[i][j].spriteState == PLATE_PRESSED){
                    renderSprite(sRaftPlacement10X10.MapArray[i][j].sprite, SpriteShaderProgram, THIRD_TEXTURE);
                }
                else if (sRaftPlacement10X10.MapArray[i][j].spriteState == PLATE_SUCCES){
                    renderSprite(sRaftPlacement10X10.MapArray[i][j].sprite, SpriteShaderProgram, SECOND_TEXTURE);
                }
                else if (sRaftPlacement10X10.MapArray[i][j].spriteState == PLATE_ERROR){
                    renderSprite(sRaftPlacement10X10.MapArray[i][j].sprite, SpriteShaderProgram, FIRST_TEXTURE);
                }
            }
        }

    }
    else {
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                if (sRaftPlacement10X10.MapArray[i][j].spriteState == PLATE_SUCCES){
                    renderSprite(sRaftPlacement10X10.MapArray[i][j].sprite, SpriteShaderProgram, SECOND_TEXTURE);
                }
                else if (sRaftPlacement10X10.MapArray[i][j].spriteState == PLATE_ERROR){
                    renderSprite(sRaftPlacement10X10.MapArray[i][j].sprite, SpriteShaderProgram, FIRST_TEXTURE);
                }
            }
        }
    }

    changeCorrectSpriteParams(sRaftPlacement10X10.Map10x10, windowSizeX, windowSizeY);

    renderSprite(sRaftPlacement10X10.Map10x10, SpriteShaderProgram, FIRST_TEXTURE);
    renderSprite(sRaftPlacement10X10.ButtonPlates, SpriteShaderProgram, FIRST_TEXTURE);

    //Количество кораблей, которые можно установить на поле
    getRemainedShips(shipBase, ONE_BLOCK_SHIP, CanPutShips);
    renderText(sRaftPlacement10X10.TextParams, TextShaderProgram, CanPutShips, correctXcoords(185.0, windowSizeX) , correctYcoords(615, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    getRemainedShips(shipBase, TWO_BLOCKS_SHIP, CanPutShips);
    renderText(sRaftPlacement10X10.TextParams, TextShaderProgram, CanPutShips, correctXcoords(166.0, windowSizeX) , correctYcoords(588, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    getRemainedShips(shipBase, THREE_BLOCKS_SHIP, CanPutShips);
    renderText(sRaftPlacement10X10.TextParams, TextShaderProgram, CanPutShips, correctXcoords(184.0, windowSizeX) , correctYcoords(561, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    getRemainedShips(shipBase, FOUR_BLOCKS_SHIP, CanPutShips);
    renderText(sRaftPlacement10X10.TextParams, TextShaderProgram, CanPutShips, correctXcoords(172.0, windowSizeX) , correctYcoords(537, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);

    //Обработка кнопки PLAY
    if (cursorInArea(xMousePos, yMousePos, 42, 464, 359, 385, windowSizeX, windowSizeY)){
        if (AllShipsInMap(shipBase) == NOT_ALL_SHIPS_IN_MAP){
            renderText(sRaftPlacement10X10.TextParams, TextShaderProgram, "Play", correctXcoords(120.0, windowSizeX) , correctYcoords(274, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 1.0f, 0.0f, 0.0f);
        }
        else {
            renderText(sRaftPlacement10X10.TextParams, TextShaderProgram, "Play", correctXcoords(120.0, windowSizeX) , correctYcoords(274, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 0.0f, 1.0f, 0.0f);
        }

        if (AllShipsInMap(shipBase) == ALL_SHIPS_IN_MAP && glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            //ТУТ НУЖНО БУДЕТ СГЕНЕРИТЬ РАССТАНОВКУ ДЛЯ БОТА!!!
    
            playerInfo.scene = MAIN_GAME_BASE_10_X_10;

            for (int i = 0; i < 10; i++){
                for (int j = 0; j < 10; j++){
                    if (map[i + 1][j + 1] == 2){
                        sMainGameBase10x10.PlayerMapArray[i][j].spriteState = THIS_IS_SHIP_PLATE_LIVE;
                    }
                }
            }

            for (int i = 0; i < 10; i++){
                for (int j = 0; j < 10; j++){
                    sRaftPlacement10X10.MapArray[i][j].spriteState = PLATE_NOT_PRESSED;
                }
            }
            
            fillShipsTextures10x10(sMainGameBase10x10.PlayerMapArray, shipBase, map, TEXTURES_TURN_RIGHT);

            if (botShipBase == NULL) botShipBase = initShipBase(MAP_SIZE_10_X_10);
            genRandShips(mapBot, botShipBase, MAP_SIZE_10_X_10);
            clearTrashFromMap(map);
            clearTrashFromMap(mapBot);
            
            sMainGameBase10x10.state = PLAYER_SHOT;

            for (int i = 0; i < 10; i++){
                for (int j = 0; j < 10; j++){
                    printf("%d ", map[i + 1][j + 1]);
                }
                printf("\n");
            }

            lastClickTime = glfwGetTime();
        }  
    }
    else {
        renderText(sRaftPlacement10X10.TextParams, TextShaderProgram, "Play", correctXcoords(120.0, windowSizeX) , correctYcoords(274, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    //Обработка кнопки CLEAR
    if (cursorInArea(xMousePos, yMousePos, 36, 682, 361, 599, windowSizeX, windowSizeY)){
        renderText(sRaftPlacement10X10.TextParams, TextShaderProgram, "Clear", correctXcoords(108.0, windowSizeX) , correctYcoords(58.0, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            clearMap(map);
            clearShipBase(shipBase);

            for (int i = 0; i < 10; i++){
                for (int j = 0; j < 10; j++){
                    sRaftPlacement10X10.MapArray[i][j].spriteState = PLATE_NOT_PRESSED;
                }
            }
            
            lastClickTime = glfwGetTime();
        }  
    }
    else {
        renderText(sRaftPlacement10X10.TextParams, TextShaderProgram, "Clear", correctXcoords(108.0, windowSizeX) , correctYcoords(58.0, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    //Обработка кнопки AutoGen
    if (cursorInArea(xMousePos, yMousePos, 37, 572, 362, 492, windowSizeX, windowSizeY)){
        renderText(sRaftPlacement10X10.TextParams, TextShaderProgram, "AutoGen", correctXcoords(66.0, windowSizeX) , correctYcoords(168.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            clearMap(map);
            clearShipBase(shipBase);

            for (int i = 0; i < 10; i++){
                for (int j = 0; j < 10; j++){
                    sRaftPlacement10X10.MapArray[i][j].spriteState = PLATE_NOT_PRESSED;
                }
            }
            
            genRandShips(map, shipBase, MAP_SIZE_10_X_10);

            for (int i = 0; i < 10; i++){
                for (int j = 0; j < 10; j++){
                    if (map[i + 1][j + 1] == 2){
                        sRaftPlacement10X10.MapArray[i][j].spriteState = PLATE_SUCCES;
                    }
                }
            }

            lastClickTime = glfwGetTime();
        }  
    }
    else {
        renderText(sRaftPlacement10X10.TextParams, TextShaderProgram, "AutoGen", correctXcoords(66.0, windowSizeX) , correctYcoords(168.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    //Индикатор режима редактирования
    if(sRaftPlacement10X10.state == IN_EDIT_MODE){           
        renderText(sRaftPlacement10X10.TextParams, TextShaderProgram, "e", correctXcoords(1218.0, windowSizeX) , correctYcoords(521.0, windowSizeY), correctTextSize(1.5, windowSizeX, windowSizeY), 1.0f, 1.0f, 0.0f);
    }
    else{
        renderText(sRaftPlacement10X10.TextParams, TextShaderProgram, "e", correctXcoords(1218.0, windowSizeX) , correctYcoords(521.0, windowSizeY), correctTextSize(1.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        renderSprite(sRaftPlacement10X10.ExitBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }

    //Обработка кнопки Exit
    if (cursorInArea(xMousePos, yMousePos, 1202, 64, 1262, 17, windowSizeX, windowSizeY)){
        renderSprite(sRaftPlacement10X10.ExitBtn, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            
            freeShipBase(shipBase);
            shipBase = NULL;

            clearMap(map);

            for (int i = 0; i < 10; i++){
                for (int j = 0; j < 10; j++){
                    sRaftPlacement10X10.MapArray[i][j].spriteState = PLATE_NOT_PRESSED;
                }
            }

            playerInfo.scene = MAIN_MENU_SCENES;
            playerInfo.BotLevel = NOT_FILLED_IN;
            playerInfo.GameMode = NOT_FILLED_IN;
            playerInfo.MapSize = NOT_FILLED_IN;
            lastClickTime = glfwGetTime();
        }
    }
    else{
        renderSprite(sRaftPlacement10X10.ExitBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }

    //Обработка кнопки подсказки
    if (cursorInArea(xMousePos, yMousePos, 1200, 139, 1264, 89, windowSizeX, windowSizeY) && sRaftPlacement10X10.state != FAQ){
        renderSprite(sRaftPlacement10X10.QuestionMarkBtn, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            lastSceneState = sRaftPlacement10X10.state;
            sRaftPlacement10X10.state = FAQ;
            lastClickTime = glfwGetTime();
        }
    }
    else {
        renderSprite(sRaftPlacement10X10.QuestionMarkBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }

    //Обработка FAQ
    if (sRaftPlacement10X10.state == FAQ){
        renderSprite(sRaftPlacement10X10.FAQPlate, SpriteShaderProgram, FIRST_TEXTURE);
        for (int i = 0, startY = 530; i < FAQRaftPlacementStringCount; i++, startY -= 35){
            renderText(sRaftPlacement10X10.TextParams, TextShaderProgram, FAQRaftPlacement[i], correctXcoords(320.0, windowSizeX) , correctYcoords(startY, windowSizeY), correctTextSize(0.6, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

        if (cursorInArea(xMousePos, yMousePos, 490, 620, 791, 545, windowSizeX, windowSizeY)){
            renderText(sRaftPlacement10X10.TextParams, TextShaderProgram, "OK", correctXcoords(585.0, windowSizeX) , correctYcoords(112, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                sRaftPlacement10X10.state = lastSceneState;
                lastClickTime = glfwGetTime();
            }
        }
        else {
            renderText(sRaftPlacement10X10.TextParams, TextShaderProgram, "OK", correctXcoords(585.0, windowSizeX) , correctYcoords(112, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }    
        
    }
}


void renderRaftPlacement15x15(GLFWwindow* window)
{
    extern GLuint SpriteShaderProgram;
    extern GLuint TextShaderProgram;
    extern RaftPlacement15x15 sRaftPlacement15X15;
    extern MainGameBase15x15 sMainGameBase15x15;
    extern Player playerInfo;
    extern ShipBase* shipBase;
    extern ShipBase* botShipBase;
    extern Coordinates* coords[5];

    extern int map[18][18];
    extern int mapBot[18][18];

    extern int windowSizeX;
    extern int windowSizeY;

    extern double lastClickTime;

    double xMousePos,
           yMousePos;

    char CanPutShips[2] = {'\0',};

    static int elemCount = 0;
    int maxElemCount = maxPlatesShip(shipBase);

    extern char FAQRaftPlacement[8][MAX_STRING_SIZE];
    extern const int FAQRaftPlacementStringCount;

    static int lastSceneState = 0;
    
    glfwGetCursorPos(window, &xMousePos, &yMousePos);
    printf("%.2lf  %.2lf    ", xMousePos, yMousePos);
    printf("Window size: %dx%d\n", windowSizeX, windowSizeY);

    changeSpriteSize(sRaftPlacement15X15.Background, windowSizeX, windowSizeY);
    changeSpriteSize(sRaftPlacement15X15.ButtonPlates, windowSizeX, windowSizeY);
    changeSpriteSize(sRaftPlacement15X15.Map15x15, windowSizeX, windowSizeY);

    //Если сцена открывается повторно нужно снова выделить память под данные о кораблях
    if (shipBase == NULL){
        shipBase = initShipBase(MAP_SIZE_15_X_15);
        
    }

    renderSprite(sRaftPlacement15X15.Background, SpriteShaderProgram, FIRST_TEXTURE);
    renderSprite(sRaftPlacement15X15.ButtonPlates, SpriteShaderProgram, FIRST_TEXTURE);

    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY && sRaftPlacement15X15.state != FAQ){
        if (sRaftPlacement15X15.state == IN_EDIT_MODE){
            sRaftPlacement15X15.state = NOT_IN_EDIT_MODE;
            if (shipIsCorrect(map, shipBase, elemCount, MAP_SIZE_15_X_15, coords) == SHIP_IS_CORRECT){
                printf("IS_CORRECT!\n");
                putShipInBase(shipBase, coords, elemCount);
                putShipInMap(map, coords, elemCount);
                for (int i = 0 ; i < 15; i++){
                    for (int j = 0; j < 15; j++){
                        if (sRaftPlacement15X15.MapArray[i][j].spriteState == PLATE_PRESSED){
                            sRaftPlacement15X15.MapArray[i][j].spriteState = PLATE_SUCCES;
                        }
                    }
                }
                elemCount = 0;
                //Все клетки, где нельзя ставить корабль помечаются красным
                for (int i = 1; i <= 15; i++){
                    for (int j = 1; j <= 15; j++){
                        if (map[i][j] == 1){
                            sRaftPlacement15X15.MapArray[i - 1][j - 1].spriteState = PLATE_ERROR;
                        }
                    }
                }

            }
            else {
                printf("IS_NOT_CORRECT!\n");
                for (int i = 0 ; i < 15; i++){
                    for (int j = 0; j < 15; j++){
                        if (sRaftPlacement15X15.MapArray[i][j].spriteState == PLATE_PRESSED){
                            sRaftPlacement15X15.MapArray[i][j].spriteState = PLATE_NOT_PRESSED;    
                        }
                    }
                }
            }
            elemCount = 0;
        }
        else sRaftPlacement15X15.state = IN_EDIT_MODE;
        lastClickTime = glfwGetTime();
    }


    if (sRaftPlacement15X15.state == IN_EDIT_MODE && sRaftPlacement15X15.state != FAQ){

        for (int i = 0; i < 15; i++){
            for (int j = 0; j < 15; j++){
                if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && cursorInArea(xMousePos, yMousePos, sRaftPlacement15X15.MapArray[i][j].sprite->positionX, windowSizeY - sRaftPlacement15X15.MapArray[i][j].sprite->positionY, sRaftPlacement15X15.MapArray[i][j].sprite->positionX + sRaftPlacement15X15.MapArray[i][j].sprite->sizeX, windowSizeY - sRaftPlacement15X15.MapArray[i][j].sprite->positionY - sRaftPlacement15X15.MapArray[i][j].sprite->sizeY, windowSizeX, windowSizeY) && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                    if (sRaftPlacement15X15.MapArray[i][j].spriteState == PLATE_PRESSED){
                        sRaftPlacement15X15.MapArray[i][j].spriteState = PLATE_NOT_PRESSED;
                        elemCount--;
                    }
                    else {
                        if (elemCount < maxElemCount && sRaftPlacement15X15.MapArray[i][j].spriteState != PLATE_SUCCES && sRaftPlacement15X15.MapArray[i][j].spriteState != PLATE_ERROR){
                            sRaftPlacement15X15.MapArray[i][j].spriteState = PLATE_PRESSED;
                            coords[elemCount]->x = j;
                            coords[elemCount]->y = i;
                            elemCount++;
                        }
                    }

                    lastClickTime = glfwGetTime();
                }

                if (sRaftPlacement15X15.MapArray[i][j].spriteState == PLATE_PRESSED){
                    renderSprite(sRaftPlacement15X15.MapArray[i][j].sprite, SpriteShaderProgram, THIRD_TEXTURE);
                }
                else if (sRaftPlacement15X15.MapArray[i][j].spriteState == PLATE_SUCCES){
                    renderSprite(sRaftPlacement15X15.MapArray[i][j].sprite, SpriteShaderProgram, SECOND_TEXTURE);
                }
                else if (sRaftPlacement15X15.MapArray[i][j].spriteState == PLATE_ERROR){
                    renderSprite(sRaftPlacement15X15.MapArray[i][j].sprite, SpriteShaderProgram, FIRST_TEXTURE);
                }
            }
        }

    }
    else {
        for (int i = 0; i < 15; i++){
            for (int j = 0; j < 15; j++){
                if (sRaftPlacement15X15.MapArray[i][j].spriteState == PLATE_SUCCES){
                    renderSprite(sRaftPlacement15X15.MapArray[i][j].sprite, SpriteShaderProgram, SECOND_TEXTURE);
                }
                else if (sRaftPlacement15X15.MapArray[i][j].spriteState == PLATE_ERROR){
                    renderSprite(sRaftPlacement15X15.MapArray[i][j].sprite, SpriteShaderProgram, FIRST_TEXTURE);
                }
            }
        }
    }

    changeCorrectSpriteParams(sRaftPlacement15X15.Map15x15, windowSizeX, windowSizeY);

    renderSprite(sRaftPlacement15X15.Map15x15, SpriteShaderProgram, FIRST_TEXTURE);
    renderSprite(sRaftPlacement15X15.ButtonPlates, SpriteShaderProgram, FIRST_TEXTURE);

    //Количество кораблей, которые можно установить на поле
    getRemainedShips(shipBase, ONE_BLOCK_SHIP, CanPutShips);
    renderText(sRaftPlacement15X15.TextParams, TextShaderProgram, CanPutShips, correctXcoords(189.0, windowSizeX) , correctYcoords(623, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    getRemainedShips(shipBase, TWO_BLOCKS_SHIP, CanPutShips);
    renderText(sRaftPlacement15X15.TextParams, TextShaderProgram, CanPutShips, correctXcoords(170.0, windowSizeX) , correctYcoords(597, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    getRemainedShips(shipBase, THREE_BLOCKS_SHIP, CanPutShips);
    renderText(sRaftPlacement15X15.TextParams, TextShaderProgram, CanPutShips, correctXcoords(189.0, windowSizeX) , correctYcoords(571, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    getRemainedShips(shipBase, FOUR_BLOCKS_SHIP, CanPutShips);
    renderText(sRaftPlacement15X15.TextParams, TextShaderProgram, CanPutShips, correctXcoords(176.0, windowSizeX) , correctYcoords(547, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    getRemainedShips(shipBase, FIVE_BLOCKS_SHIP, CanPutShips);
    renderText(sRaftPlacement15X15.TextParams, TextShaderProgram, CanPutShips, correctXcoords(173.0, windowSizeX) , correctYcoords(521, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);

    //Обработка кнопки PLAY
    if (cursorInArea(xMousePos, yMousePos, 42, 464, 359, 385, windowSizeX, windowSizeY) && sRaftPlacement15X15.state != FAQ){
        if (AllShipsInMap(shipBase) == NOT_ALL_SHIPS_IN_MAP){
            renderText(sRaftPlacement15X15.TextParams, TextShaderProgram, "Play", correctXcoords(126.0, windowSizeX) , correctYcoords(274, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 1.0f, 0.0f, 0.0f);
        }
        else {
            renderText(sRaftPlacement15X15.TextParams, TextShaderProgram, "Play", correctXcoords(126.0, windowSizeX) , correctYcoords(274, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 0.0f, 1.0f, 0.0f);
        }

        if (AllShipsInMap(shipBase) == ALL_SHIPS_IN_MAP && glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            playerInfo.scene = MAIN_GAME_BASE_15_X_15;
           
           for (int i = 0; i < 15; i++){
                for (int j = 0; j < 15; j++){
                    sRaftPlacement15X15.MapArray[i][j].spriteState = PLATE_NOT_PRESSED;
                }
            }

            fillShipsTextures15x15(sMainGameBase15x15.PlayerMapArray, shipBase, map, TEXTURES_TURN_RIGHT);
            
            if (botShipBase == NULL) botShipBase = initShipBase(MAP_SIZE_15_X_15);
            genRandShips(mapBot, botShipBase, MAP_SIZE_15_X_15);
            clearTrashFromMap(map);
            clearTrashFromMap(mapBot);
            
            sMainGameBase15x15.state = PLAYER_SHOT;
            lastClickTime = glfwGetTime();
        }  
    }
    else {
        renderText(sRaftPlacement15X15.TextParams, TextShaderProgram, "Play", correctXcoords(126.0, windowSizeX) , correctYcoords(274, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    //Обработка кнопки CLEAR
    if (cursorInArea(xMousePos, yMousePos, 36, 682, 361, 599, windowSizeX, windowSizeY) && sRaftPlacement15X15.state != FAQ){
        renderText(sRaftPlacement15X15.TextParams, TextShaderProgram, "Clear", correctXcoords(112.0, windowSizeX) , correctYcoords(53.0, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            clearMap(map);
            clearShipBase(shipBase);

            for (int i = 0; i < 15; i++){
                for (int j = 0; j < 15; j++){
                    sRaftPlacement15X15.MapArray[i][j].spriteState = PLATE_NOT_PRESSED;
                }
            }
            
            lastClickTime = glfwGetTime();
        }  
    }
    else {
        renderText(sRaftPlacement15X15.TextParams, TextShaderProgram, "Clear", correctXcoords(112.0, windowSizeX) , correctYcoords(53.0, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    //Обработка кнопки AutoGen
    if (cursorInArea(xMousePos, yMousePos, 37, 572, 362, 492, windowSizeX, windowSizeY) && sRaftPlacement15X15.state != FAQ){
        renderText(sRaftPlacement15X15.TextParams, TextShaderProgram, "AutoGen", correctXcoords(66.0, windowSizeX) , correctYcoords(162.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            clearMap(map);
            clearShipBase(shipBase);

            for (int i = 0; i < 15; i++){
                for (int j = 0; j < 15; j++){
                    sRaftPlacement15X15.MapArray[i][j].spriteState = PLATE_NOT_PRESSED;
                }
            }
            
            genRandShips(map, shipBase, MAP_SIZE_15_X_15);

            for (int i = 0; i < 15; i++){
                for (int j = 0; j < 15; j++){
                    if (map[i + 1][j + 1] == 2){
                        sRaftPlacement15X15.MapArray[i][j].spriteState = PLATE_SUCCES;
                    }
                }
            }

            lastClickTime = glfwGetTime();
        }  
    }
    else {
        renderText(sRaftPlacement15X15.TextParams, TextShaderProgram, "AutoGen", correctXcoords(66.0, windowSizeX) , correctYcoords(162.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    //Индикатор режима редактирования
    if(sRaftPlacement15X15.state == IN_EDIT_MODE){           
        renderText(sRaftPlacement15X15.TextParams, TextShaderProgram, "e", correctXcoords(1222.0, windowSizeX) , correctYcoords(521.0, windowSizeY), correctTextSize(1.5, windowSizeX, windowSizeY), 1.0f, 1.0f, 0.0f);
    }
    else{
        renderText(sRaftPlacement15X15.TextParams, TextShaderProgram, "e", correctXcoords(1222.0, windowSizeX) , correctYcoords(521.0, windowSizeY), correctTextSize(1.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        renderSprite(sRaftPlacement15X15.ExitBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }

    //Обработка кнопки Exit
    if (cursorInArea(xMousePos, yMousePos, 1202, 64, 1262, 17, windowSizeX, windowSizeY) && sRaftPlacement15X15.state != FAQ){
        renderSprite(sRaftPlacement15X15.ExitBtn, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            
            freeShipBase(shipBase);
            shipBase = NULL;

            clearMap(map);

            for (int i = 0; i < 15; i++){
                for (int j = 0; j < 15; j++){
                    sRaftPlacement15X15.MapArray[i][j].spriteState = PLATE_NOT_PRESSED;
                }
            }

            playerInfo.scene = MAIN_MENU_SCENES;
            playerInfo.BotLevel = NOT_FILLED_IN;
            playerInfo.GameMode = NOT_FILLED_IN;
            playerInfo.MapSize = NOT_FILLED_IN;
            lastClickTime = glfwGetTime();
        }
    }
    else{
        renderSprite(sRaftPlacement15X15.ExitBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }

    //Обработка кнопки подсказки
    if (cursorInArea(xMousePos, yMousePos, 1200, 139, 1264, 89, windowSizeX, windowSizeY) && sRaftPlacement15X15.state != FAQ){
        renderSprite(sRaftPlacement15X15.QuestionMarkBtn, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            lastSceneState = sRaftPlacement15X15.state;
            sRaftPlacement15X15.state = FAQ;
            lastClickTime = glfwGetTime();
        }
    }
    else {
        renderSprite(sRaftPlacement15X15.QuestionMarkBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }

    //Обработка FAQ
    if (sRaftPlacement15X15.state == FAQ){
        renderSprite(sRaftPlacement15X15.FAQPlate, SpriteShaderProgram, FIRST_TEXTURE);
        for (int i = 0, startY = 530; i < FAQRaftPlacementStringCount; i++, startY -= 35){
            renderText(sRaftPlacement15X15.TextParams, TextShaderProgram, FAQRaftPlacement[i], correctXcoords(320.0, windowSizeX) , correctYcoords(startY, windowSizeY), correctTextSize(0.6, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

        if (cursorInArea(xMousePos, yMousePos, 490, 620, 791, 545, windowSizeX, windowSizeY)){
            renderText(sRaftPlacement15X15.TextParams, TextShaderProgram, "OK", correctXcoords(585.0, windowSizeX) , correctYcoords(112, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                sRaftPlacement15X15.state = lastSceneState;
                lastClickTime = glfwGetTime();
            }
        }
        else {
            renderText(sRaftPlacement15X15.TextParams, TextShaderProgram, "OK", correctXcoords(585.0, windowSizeX) , correctYcoords(112, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }    
        
    }

}

void renderRaftPlacement10x10BF(GLFWwindow* window)
{
    extern GLuint SpriteShaderProgram;
    extern GLuint TextShaderProgram;
    extern RaftPlacement10x10BF sRaftPlacement10X10BF;
    extern MainGameBotFight10x10 sMainGameBotFight10x10;
    extern ShipBase* shipBaseBFBot1;
    extern ShipBase* shipBaseBFBot2;
    extern ShipBase* shipBaseBFBot1;
    extern ShipBase* shipBaseBFBot2;

    extern Coordinates* coords[5];
    extern Player playerInfo;

    extern int mapBot1[18][18];
    extern int mapBot2[18][18];

    extern int windowSizeX;
    extern int windowSizeY;

    extern double lastClickTime;

    double xMousePos,
           yMousePos;

    char CanPutShips[2] = {'\0',};

    extern char FAQRaftPlacementBF[10][MAX_STRING_SIZE];
    extern const int FAQRaftPlacementBFStringCount;

    static int lastSceneState = 0;

    glfwGetCursorPos(window, &xMousePos, &yMousePos);
    printf("%.2lf  %.2lf    ", xMousePos, yMousePos);
    printf("Window size: %dx%d\n", windowSizeX, windowSizeY);

    static int elemCount = 0;
    int maxElemCount;
    
    changeSpriteSize(sRaftPlacement10X10BF.Background, windowSizeX, windowSizeY);
    changeSpriteSize(sRaftPlacement10X10BF.ButtonPlates, windowSizeX, windowSizeY);
    changeSpriteSize(sRaftPlacement10X10BF.Map10x10, windowSizeX, windowSizeY);

    if (playerInfo.scene == RAFT_PLACEMENT_10_X_10_BOTS_FIGHT_BOT_1){

        maxElemCount = maxPlatesShip(shipBaseBFBot1);

        //Если сцена открывается повторно нужно снова выделить память под данные о кораблях
        if (shipBaseBFBot1 == NULL){
            shipBaseBFBot1 = initShipBase(MAP_SIZE_10_X_10);
        }

        //Подгон под размер окна каждой клетки на поле
        for (int i = 0 ; i < 10; i++){
            for (int j = 0; j < 10; j++){
                Sprite* sp = sRaftPlacement10X10BF.MapArrayBot1[i][j].sprite;
                changeCorrectSpriteParams(sp, windowSizeX, windowSizeY);
            }
        }
        
        
        renderSprite(sRaftPlacement10X10BF.Background, SpriteShaderProgram, FIRST_TEXTURE);
        
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY && sRaftPlacement10X10BF.state != FAQ){
            if (sRaftPlacement10X10BF.state == IN_EDIT_MODE){
                sRaftPlacement10X10BF.state = NOT_IN_EDIT_MODE;
                if (shipIsCorrect(mapBot1, shipBaseBFBot1, elemCount, MAP_SIZE_10_X_10, coords) == SHIP_IS_CORRECT){
                    printf("IS_CORRECT!\n");
                    putShipInBase(shipBaseBFBot1, coords, elemCount);
                    putShipInMap(mapBot1, coords, elemCount);
                    for (int i = 0 ; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            if (sRaftPlacement10X10BF.MapArrayBot1[i][j].spriteState == PLATE_PRESSED){
                                sRaftPlacement10X10BF.MapArrayBot1[i][j].spriteState = PLATE_SUCCES;
                                    
                            }
                        }
                    }
                    elemCount = 0;
                    //Все клетки, где нельзя ставить корабль помечаются красным
                    for (int i = 1; i <= 10; i++){
                        for (int j = 1; j <= 10; j++){
                            if (mapBot1[i][j] == 1){
                                sRaftPlacement10X10BF.MapArrayBot1[i - 1][j - 1].spriteState = PLATE_ERROR;
                            }
                        }
                    }

                }
                else {
                    printf("IS_NOT_CORRECT!\n");
                    for (int i = 0 ; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            if (sRaftPlacement10X10BF.MapArrayBot1[i][j].spriteState == PLATE_PRESSED){
                                sRaftPlacement10X10BF.MapArrayBot1[i][j].spriteState = PLATE_NOT_PRESSED;    
                            }
                        }
                    }
                }
                elemCount = 0;
            }
            else sRaftPlacement10X10BF.state = IN_EDIT_MODE;
            lastClickTime = glfwGetTime();
        }


        if (sRaftPlacement10X10BF.state == IN_EDIT_MODE && sRaftPlacement10X10BF.state != FAQ){

            for (int i = 0; i < 10; i++){
                for (int j = 0; j < 10; j++){
                    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && cursorInArea(xMousePos, yMousePos, sRaftPlacement10X10BF.MapArrayBot1[i][j].sprite->positionX, windowSizeY - sRaftPlacement10X10BF.MapArrayBot1[i][j].sprite->positionY, sRaftPlacement10X10BF.MapArrayBot1[i][j].sprite->positionX + sRaftPlacement10X10BF.MapArrayBot1[i][j].sprite->sizeX, windowSizeY - sRaftPlacement10X10BF.MapArrayBot1[i][j].sprite->positionY - sRaftPlacement10X10BF.MapArrayBot1[i][j].sprite->sizeY, windowSizeX, windowSizeY) && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                        if (sRaftPlacement10X10BF.MapArrayBot1[i][j].spriteState == PLATE_PRESSED){
                            sRaftPlacement10X10BF.MapArrayBot1[i][j].spriteState = PLATE_NOT_PRESSED;
                            elemCount--;
                        }
                        else {
                            if (elemCount < maxElemCount && sRaftPlacement10X10BF.MapArrayBot1[i][j].spriteState != PLATE_SUCCES && sRaftPlacement10X10BF.MapArrayBot1[i][j].spriteState != PLATE_ERROR){
                                sRaftPlacement10X10BF.MapArrayBot1[i][j].spriteState = PLATE_PRESSED;
                                coords[elemCount]->x = j;
                                coords[elemCount]->y = i;
                                elemCount++;
                            }
                        }

                        lastClickTime = glfwGetTime();
                    }

                    if (sRaftPlacement10X10BF.MapArrayBot1[i][j].spriteState == PLATE_PRESSED){
                        renderSprite(sRaftPlacement10X10BF.MapArrayBot1[i][j].sprite, SpriteShaderProgram, THIRD_TEXTURE);
                    }
                    else if (sRaftPlacement10X10BF.MapArrayBot1[i][j].spriteState == PLATE_SUCCES){
                        renderSprite(sRaftPlacement10X10BF.MapArrayBot1[i][j].sprite, SpriteShaderProgram, SECOND_TEXTURE);
                    }
                    else if (sRaftPlacement10X10BF.MapArrayBot1[i][j].spriteState == PLATE_ERROR){
                        renderSprite(sRaftPlacement10X10BF.MapArrayBot1[i][j].sprite, SpriteShaderProgram, FIRST_TEXTURE);
                    }
                }
            }

        }
        else {
            for (int i = 0; i < 10; i++){
                for (int j = 0; j < 10; j++){
                    if (sRaftPlacement10X10BF.MapArrayBot1[i][j].spriteState == PLATE_SUCCES){
                        renderSprite(sRaftPlacement10X10BF.MapArrayBot1[i][j].sprite, SpriteShaderProgram, SECOND_TEXTURE);
                    }
                    else if (sRaftPlacement10X10BF.MapArrayBot1[i][j].spriteState == PLATE_ERROR){
                        renderSprite(sRaftPlacement10X10BF.MapArrayBot1[i][j].sprite, SpriteShaderProgram, FIRST_TEXTURE);
                    }
                }
            }
        }

        changeCorrectSpriteParams(sRaftPlacement10X10BF.Map10x10, windowSizeX, windowSizeY);

        renderSprite(sRaftPlacement10X10BF.Map10x10, SpriteShaderProgram, FIRST_TEXTURE);
        renderSprite(sRaftPlacement10X10BF.ButtonPlates, SpriteShaderProgram, FIRST_TEXTURE);

        //Количество кораблей, которые можно установить на поле
        getRemainedShips(shipBaseBFBot1, ONE_BLOCK_SHIP, CanPutShips);
        renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, CanPutShips, correctXcoords(185.0, windowSizeX) , correctYcoords(615, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        getRemainedShips(shipBaseBFBot1, TWO_BLOCKS_SHIP, CanPutShips);
        renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, CanPutShips, correctXcoords(166.0, windowSizeX) , correctYcoords(588, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        getRemainedShips(shipBaseBFBot1, THREE_BLOCKS_SHIP, CanPutShips);
        renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, CanPutShips, correctXcoords(184.0, windowSizeX) , correctYcoords(561, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        getRemainedShips(shipBaseBFBot1, FOUR_BLOCKS_SHIP, CanPutShips);
        renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, CanPutShips, correctXcoords(172.0, windowSizeX) , correctYcoords(537, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);

        //Обработка кнопки CLEAR
        if (cursorInArea(xMousePos, yMousePos, 36, 682, 361, 599, windowSizeX, windowSizeY) && sRaftPlacement10X10BF.state != FAQ){
            renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, "Clear", correctXcoords(108.0, windowSizeX) , correctYcoords(58.0, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                clearMap(mapBot1);
                clearShipBase(shipBaseBFBot1);

                for (int i = 0; i < 10; i++){
                    for (int j = 0; j < 10; j++){
                        sRaftPlacement10X10BF.MapArrayBot1[i][j].spriteState = PLATE_NOT_PRESSED;
                    }
                }
                
                lastClickTime = glfwGetTime();
            }  
        }
        else {
            renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, "Clear", correctXcoords(108.0, windowSizeX) , correctYcoords(58.0, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

        //Обработка кнопки AutoGen
        if (cursorInArea(xMousePos, yMousePos, 37, 572, 362, 492, windowSizeX, windowSizeY) && sRaftPlacement10X10BF.state != FAQ){
            renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, "AutoGen", correctXcoords(66.0, windowSizeX) , correctYcoords(168.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                clearMap(mapBot1);
                clearShipBase(shipBaseBFBot1);

                for (int i = 0; i < 10; i++){
                    for (int j = 0; j < 10; j++){
                        sRaftPlacement10X10BF.MapArrayBot1[i][j].spriteState = PLATE_NOT_PRESSED;
                    }
                }
                
                genRandShips(mapBot1, shipBaseBFBot1, MAP_SIZE_10_X_10);

                for (int i = 0; i < 10; i++){
                    for (int j = 0; j < 10; j++){
                        if (mapBot1[i + 1][j + 1] == 2){
                            sRaftPlacement10X10BF.MapArrayBot1[i][j].spriteState = PLATE_SUCCES;
                        }
                    }
                }

                lastClickTime = glfwGetTime();
            }  
        }
        else {
            renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, "AutoGen", correctXcoords(66.0, windowSizeX) , correctYcoords(168.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }
    }
    else if (playerInfo.scene == RAFT_PLACEMENT_10_X_10_BOTS_FIGHT_BOT_2){

        maxElemCount = maxPlatesShip(shipBaseBFBot2);

        //Если сцена открывается повторно нужно снова выделить память под данные о кораблях
        if (shipBaseBFBot2 == NULL){
            shipBaseBFBot2 = initShipBase(MAP_SIZE_10_X_10);
        }

        //Подгон под размер окна каждой клетки на поле
        for (int i = 0 ; i < 10; i++){
            for (int j = 0; j < 10; j++){
                Sprite* sp = sRaftPlacement10X10BF.MapArrayBot2[i][j].sprite;
                changeCorrectSpriteParams(sp, windowSizeX, windowSizeY);
            }
        }
        
        
        renderSprite(sRaftPlacement10X10BF.Background, SpriteShaderProgram, FIRST_TEXTURE);
        
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY && sRaftPlacement10X10BF.state != FAQ){
            if (sRaftPlacement10X10BF.state == IN_EDIT_MODE){
                sRaftPlacement10X10BF.state = NOT_IN_EDIT_MODE;
                if (shipIsCorrect(mapBot2, shipBaseBFBot2, elemCount, MAP_SIZE_10_X_10, coords) == SHIP_IS_CORRECT){
                    printf("IS_CORRECT!\n");
                    putShipInBase(shipBaseBFBot2, coords, elemCount);
                    putShipInMap(mapBot2, coords, elemCount);
                    for (int i = 0 ; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            if (sRaftPlacement10X10BF.MapArrayBot2[i][j].spriteState == PLATE_PRESSED){
                                sRaftPlacement10X10BF.MapArrayBot2[i][j].spriteState = PLATE_SUCCES;  
                            }
                        }
                    }
                    elemCount = 0;
                    //Все клетки, где нельзя ставить корабль помечаются красным
                    for (int i = 1; i <= 10; i++){
                        for (int j = 1; j <= 10; j++){
                            if (mapBot2[i][j] == 1){
                                sRaftPlacement10X10BF.MapArrayBot2[i - 1][j - 1].spriteState = PLATE_ERROR;
                            }
                        }
                    }

                }
                else {
                    printf("IS_NOT_CORRECT!\n");
                    for (int i = 0 ; i < 10; i++){
                        for (int j = 0; j < 10; j++){
                            if (sRaftPlacement10X10BF.MapArrayBot2[i][j].spriteState == PLATE_PRESSED){
                                sRaftPlacement10X10BF.MapArrayBot2[i][j].spriteState = PLATE_NOT_PRESSED;    
                            }
                        }
                    }
                }
                elemCount = 0;
            }
            else sRaftPlacement10X10BF.state = IN_EDIT_MODE;
            lastClickTime = glfwGetTime();
        }


        if (sRaftPlacement10X10BF.state == IN_EDIT_MODE && sRaftPlacement10X10BF.state != FAQ){

            for (int i = 0; i < 10; i++){
                for (int j = 0; j < 10; j++){
                    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && cursorInArea(xMousePos, yMousePos, sRaftPlacement10X10BF.MapArrayBot2[i][j].sprite->positionX, windowSizeY - sRaftPlacement10X10BF.MapArrayBot2[i][j].sprite->positionY, sRaftPlacement10X10BF.MapArrayBot2[i][j].sprite->positionX + sRaftPlacement10X10BF.MapArrayBot2[i][j].sprite->sizeX, windowSizeY - sRaftPlacement10X10BF.MapArrayBot2[i][j].sprite->positionY - sRaftPlacement10X10BF.MapArrayBot2[i][j].sprite->sizeY, windowSizeX, windowSizeY) && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                        if (sRaftPlacement10X10BF.MapArrayBot2[i][j].spriteState == PLATE_PRESSED){
                            sRaftPlacement10X10BF.MapArrayBot2[i][j].spriteState = PLATE_NOT_PRESSED;
                            elemCount--;
                        }
                        else {
                            if (elemCount < maxElemCount && sRaftPlacement10X10BF.MapArrayBot2[i][j].spriteState != PLATE_SUCCES && sRaftPlacement10X10BF.MapArrayBot2[i][j].spriteState != PLATE_ERROR){
                                sRaftPlacement10X10BF.MapArrayBot2[i][j].spriteState = PLATE_PRESSED;
                                coords[elemCount]->x = j;
                                coords[elemCount]->y = i;
                                elemCount++;
                            }
                        }

                        lastClickTime = glfwGetTime();
                    }

                    if (sRaftPlacement10X10BF.MapArrayBot2[i][j].spriteState == PLATE_PRESSED){
                        renderSprite(sRaftPlacement10X10BF.MapArrayBot2[i][j].sprite, SpriteShaderProgram, THIRD_TEXTURE);
                    }
                    else if (sRaftPlacement10X10BF.MapArrayBot2[i][j].spriteState == PLATE_SUCCES){
                        renderSprite(sRaftPlacement10X10BF.MapArrayBot2[i][j].sprite, SpriteShaderProgram, SECOND_TEXTURE);
                    }
                    else if (sRaftPlacement10X10BF.MapArrayBot2[i][j].spriteState == PLATE_ERROR){
                        renderSprite(sRaftPlacement10X10BF.MapArrayBot2[i][j].sprite, SpriteShaderProgram, FIRST_TEXTURE);
                    }
                }
            }

        }
        else {
            for (int i = 0; i < 10; i++){
                for (int j = 0; j < 10; j++){
                    if (sRaftPlacement10X10BF.MapArrayBot2[i][j].spriteState == PLATE_SUCCES){
                        renderSprite(sRaftPlacement10X10BF.MapArrayBot2[i][j].sprite, SpriteShaderProgram, SECOND_TEXTURE);
                    }
                    else if (sRaftPlacement10X10BF.MapArrayBot2[i][j].spriteState == PLATE_ERROR){
                        renderSprite(sRaftPlacement10X10BF.MapArrayBot2[i][j].sprite, SpriteShaderProgram, FIRST_TEXTURE);
                    }
                }
            }
        }

        changeCorrectSpriteParams(sRaftPlacement10X10BF.Map10x10, windowSizeX, windowSizeY);

        renderSprite(sRaftPlacement10X10BF.Map10x10, SpriteShaderProgram, FIRST_TEXTURE);
        renderSprite(sRaftPlacement10X10BF.ButtonPlates, SpriteShaderProgram, FIRST_TEXTURE);

        //Количество кораблей, которые можно установить на поле
        getRemainedShips(shipBaseBFBot2, ONE_BLOCK_SHIP, CanPutShips);
        renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, CanPutShips, correctXcoords(185.0, windowSizeX) , correctYcoords(615, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        getRemainedShips(shipBaseBFBot2, TWO_BLOCKS_SHIP, CanPutShips);
        renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, CanPutShips, correctXcoords(166.0, windowSizeX) , correctYcoords(588, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        getRemainedShips(shipBaseBFBot2, THREE_BLOCKS_SHIP, CanPutShips);
        renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, CanPutShips, correctXcoords(184.0, windowSizeX) , correctYcoords(561, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        getRemainedShips(shipBaseBFBot2, FOUR_BLOCKS_SHIP, CanPutShips);
        renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, CanPutShips, correctXcoords(172.0, windowSizeX) , correctYcoords(537, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);

        //Обработка кнопки CLEAR
        if (cursorInArea(xMousePos, yMousePos, 36, 682, 361, 599, windowSizeX, windowSizeY) && sRaftPlacement10X10BF.state != FAQ){
            renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, "Clear", correctXcoords(108.0, windowSizeX) , correctYcoords(58.0, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                clearMap(mapBot2);
                clearShipBase(shipBaseBFBot2);

                for (int i = 0; i < 10; i++){
                    for (int j = 0; j < 10; j++){
                        sRaftPlacement10X10BF.MapArrayBot2[i][j].spriteState = PLATE_NOT_PRESSED;
                    }
                }
                
                lastClickTime = glfwGetTime();
            }  
        }
        else {
            renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, "Clear", correctXcoords(108.0, windowSizeX) , correctYcoords(58.0, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

        //Обработка кнопки AutoGen
        if (cursorInArea(xMousePos, yMousePos, 37, 572, 362, 492, windowSizeX, windowSizeY) && sRaftPlacement10X10BF.state != FAQ){
            renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, "AutoGen", correctXcoords(66.0, windowSizeX) , correctYcoords(168.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                clearMap(mapBot2);
                clearShipBase(shipBaseBFBot2);

                for (int i = 0; i < 10; i++){
                    for (int j = 0; j < 10; j++){
                        sRaftPlacement10X10BF.MapArrayBot2[i][j].spriteState = PLATE_NOT_PRESSED;
                    }
                }
                
                genRandShips(mapBot2, shipBaseBFBot2, MAP_SIZE_10_X_10);

                for (int i = 0; i < 10; i++){
                    for (int j = 0; j < 10; j++){
                        if (mapBot2[i + 1][j + 1] == 2){
                            sRaftPlacement10X10BF.MapArrayBot2[i][j].spriteState = PLATE_SUCCES;
                        }
                    }
                }

                lastClickTime = glfwGetTime();
            }  
        }
        else {
            renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, "AutoGen", correctXcoords(66.0, windowSizeX) , correctYcoords(168.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }
    }

    //Индикатор режима редактирования
    if(sRaftPlacement10X10BF.state == IN_EDIT_MODE){           
        renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, "e", correctXcoords(1218.0, windowSizeX) , correctYcoords(523.0, windowSizeY), correctTextSize(1.5, windowSizeX, windowSizeY), 1.0f, 1.0f, 0.0f);
    }
    else{
        renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, "e", correctXcoords(1218.0, windowSizeX) , correctYcoords(523.0, windowSizeY), correctTextSize(1.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        renderSprite(sRaftPlacement10X10BF.ExitBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }

    //Обработка кнопки Exit
    if (cursorInArea(xMousePos, yMousePos, 1202, 64, 1262, 17, windowSizeX, windowSizeY) && sRaftPlacement10X10BF.state != FAQ){
        renderSprite(sRaftPlacement10X10BF.ExitBtn, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            
            if (shipBaseBFBot1 != NULL) freeShipBase(shipBaseBFBot1);
            if (shipBaseBFBot2 != NULL) freeShipBase(shipBaseBFBot2);

            shipBaseBFBot1 = NULL;
            shipBaseBFBot2 = NULL;

            clearMap(mapBot1);
            clearMap(mapBot2);

            for (int i = 0; i < 10; i++){
                for (int j = 0; j < 10; j++){
                    sRaftPlacement10X10BF.MapArrayBot1[i][j].spriteState = PLATE_NOT_PRESSED;
                    sRaftPlacement10X10BF.MapArrayBot2[i][j].spriteState = PLATE_NOT_PRESSED;
                }
            }

            playerInfo.scene = MAIN_MENU_SCENES;
            playerInfo.BotLevel = NOT_FILLED_IN;
            playerInfo.GameMode = NOT_FILLED_IN;
            playerInfo.MapSize = NOT_FILLED_IN;
            lastClickTime = glfwGetTime();
        }
    }
    else{
        renderSprite(sRaftPlacement10X10BF.ExitBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }

    //Обработка кнопки подсказки
    if (cursorInArea(xMousePos, yMousePos, 1200, 139, 1264, 89, windowSizeX, windowSizeY) && sRaftPlacement10X10BF.state != FAQ){
        renderSprite(sRaftPlacement10X10BF.QuestionMarkBtn, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            lastSceneState = sRaftPlacement10X10BF.state;
            sRaftPlacement10X10BF.state = FAQ;
            lastClickTime = glfwGetTime();
        }
    }
    else {
        renderSprite(sRaftPlacement10X10BF.QuestionMarkBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }

    //Обработка конпки B1
    if (cursorInArea(xMousePos, yMousePos, 1200, 277, 1264, 227, windowSizeX, windowSizeY) || playerInfo.scene == RAFT_PLACEMENT_10_X_10_BOTS_FIGHT_BOT_1){
        renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, "B1", correctXcoords(1211.0, windowSizeX) , correctYcoords(453.0, windowSizeY), correctTextSize(1.1, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY && playerInfo.scene != RAFT_PLACEMENT_10_X_10_BOTS_FIGHT_BOT_1){
            playerInfo.scene = RAFT_PLACEMENT_10_X_10_BOTS_FIGHT_BOT_1;
            lastClickTime = glfwGetTime();
            if (sRaftPlacement10X10BF.state == IN_EDIT_MODE){
                sRaftPlacement10X10BF.state = NOT_IN_EDIT_MODE;
            }
        }
    }
    else {
        renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, "B1", correctXcoords(1211.0, windowSizeX) , correctYcoords(453.0, windowSizeY), correctTextSize(1.1, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    //Обработка конпки B2
    if (cursorInArea(xMousePos, yMousePos, 1200, 349, 1264, 294, windowSizeX, windowSizeY) || playerInfo.scene == RAFT_PLACEMENT_10_X_10_BOTS_FIGHT_BOT_2){
        renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, "B2", correctXcoords(1210.0, windowSizeX) , correctYcoords(385.0, windowSizeY), correctTextSize(1.0, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY &&  playerInfo.scene != RAFT_PLACEMENT_10_X_10_BOTS_FIGHT_BOT_2){
            playerInfo.scene = RAFT_PLACEMENT_10_X_10_BOTS_FIGHT_BOT_2;
            lastClickTime = glfwGetTime();
            if (sRaftPlacement10X10BF.state == IN_EDIT_MODE){
                sRaftPlacement10X10BF.state = NOT_IN_EDIT_MODE;
            }
        }
    }
    else {
        renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, "B2", correctXcoords(1210.0, windowSizeX) , correctYcoords(385.0, windowSizeY), correctTextSize(1.0, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    //Обработка кнопки PLAY
    if (cursorInArea(xMousePos, yMousePos, 42, 464, 359, 385, windowSizeX, windowSizeY) && sRaftPlacement10X10BF.state != FAQ){
        if (AllShipsInMap(shipBaseBFBot2) == NOT_ALL_SHIPS_IN_MAP || AllShipsInMap(shipBaseBFBot1) == NOT_ALL_SHIPS_IN_MAP){
            renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, "Play", correctXcoords(120.0, windowSizeX) , correctYcoords(274, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 1.0f, 0.0f, 0.0f);
        }
        else {
            renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, "Play", correctXcoords(120.0, windowSizeX) , correctYcoords(274, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 0.0f, 1.0f, 0.0f);
        }

        if (AllShipsInMap(shipBaseBFBot2) == ALL_SHIPS_IN_MAP && AllShipsInMap(shipBaseBFBot2) == ALL_SHIPS_IN_MAP && glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            playerInfo.scene = MAIN_GAME_BOT_FIGHT_10_X_10;

            fillShipsTextures10x10(sMainGameBotFight10x10.Bot1MapArray, shipBaseBFBot1, mapBot1, TEXTURES_TURN_RIGHT);
            fillShipsTextures10x10(sMainGameBotFight10x10.Bot2MapArray, shipBaseBFBot2, mapBot2, TEXTURES_TURN_LEFT);

            clearTrashFromMap(mapBot1);
            clearTrashFromMap(mapBot2);

            for (int i = 0; i < 10; i++){
                for (int j = 0; j < 10; j++){
                    sRaftPlacement10X10BF.MapArrayBot1[i][j].spriteState = PLATE_NOT_PRESSED;
                    sRaftPlacement10X10BF.MapArrayBot2[i][j].spriteState = PLATE_NOT_PRESSED;
                }
            }

            if (rand() % 2 == 0) sMainGameBotFight10x10.state = BOT_2_SHOT;
            else sMainGameBotFight10x10.state = BOT_1_SHOT;

            lastClickTime = glfwGetTime();
        }  
    }
    else {
        renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, "Play", correctXcoords(120.0, windowSizeX) , correctYcoords(274, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    //Обработка FAQ
    if (sRaftPlacement10X10BF.state == FAQ){
        renderSprite(sRaftPlacement10X10BF.FAQPlate, SpriteShaderProgram, FIRST_TEXTURE);
        for (int i = 0, startY = 530; i < FAQRaftPlacementBFStringCount; i++, startY -= 35){
            renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, FAQRaftPlacementBF[i], correctXcoords(320.0, windowSizeX) , correctYcoords(startY, windowSizeY), correctTextSize(0.6, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

        if (cursorInArea(xMousePos, yMousePos, 490, 620, 791, 545, windowSizeX, windowSizeY)){
            renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, "OK", correctXcoords(585.0, windowSizeX) , correctYcoords(112, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                sRaftPlacement10X10BF.state = lastSceneState;
                lastClickTime = glfwGetTime();
            }
        }
        else {
            renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, "OK", correctXcoords(585.0, windowSizeX) , correctYcoords(112, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }    
        
    }
        
}

void renderRaftPlacement15x15BF(GLFWwindow* window)
{
    extern GLuint SpriteShaderProgram;
    extern GLuint TextShaderProgram;
    extern RaftPlacement15x15BF sRaftPlacement15X15BF;
    extern MainGameBotFight15x15 sMainGameBotFight15x15;
    extern Player playerInfo;
    extern ShipBase* shipBaseBFBot1;
    extern ShipBase* shipBaseBFBot2;
    extern Coordinates* coords[5];

    extern int mapBot1[18][18];
    extern int mapBot2[18][18];

    extern int windowSizeX;
    extern int windowSizeY;

    extern double lastClickTime;

    double xMousePos,
           yMousePos;

    char CanPutShips[2] = {'\0',};

    extern char FAQRaftPlacementBF[10][MAX_STRING_SIZE];
    extern const int FAQRaftPlacementBFStringCount;

    static int lastSceneState = 0;

    glfwGetCursorPos(window, &xMousePos, &yMousePos);
    printf("%.2lf  %.2lf    ", xMousePos, yMousePos);
    printf("Window size: %dx%d\n", windowSizeX, windowSizeY);

    static int elemCount = 0;
    int maxElemCount;
    
    changeSpriteSize(sRaftPlacement15X15BF.Background, windowSizeX, windowSizeY);
    changeSpriteSize(sRaftPlacement15X15BF.ButtonPlates, windowSizeX, windowSizeY);
    changeSpriteSize(sRaftPlacement15X15BF.Map15x15, windowSizeX, windowSizeY);

    if (playerInfo.scene == RAFT_PLACEMENT_15_X_15_BOTS_FIGHT_BOT_1){
    
        //Если сцена открывается повторно нужно снова выделить память под данные о кораблях
        if (shipBaseBFBot1 == NULL){
            shipBaseBFBot1 = initShipBase(MAP_SIZE_15_X_15);
        }
        
        maxElemCount = maxPlatesShip(shipBaseBFBot1);
        printf("2\n");
        //Подгон под размер окна каждой клетки на поле
        for (int i = 0 ; i < 15; i++){
            for (int j = 0; j < 15; j++){
                Sprite* sp = sRaftPlacement15X15BF.MapArrayBot1[i][j].sprite;
                changeCorrectSpriteParams(sp, windowSizeX, windowSizeY);
            }
        }
        
        
        renderSprite(sRaftPlacement15X15BF.Background, SpriteShaderProgram, FIRST_TEXTURE);
        
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY && sRaftPlacement15X15BF.state != FAQ){
            if (sRaftPlacement15X15BF.state == IN_EDIT_MODE){
                sRaftPlacement15X15BF.state = NOT_IN_EDIT_MODE;
                if (shipIsCorrect(mapBot1, shipBaseBFBot1, elemCount, MAP_SIZE_15_X_15, coords) == SHIP_IS_CORRECT){
                    printf("IS_CORRECT!\n");
                    putShipInBase(shipBaseBFBot1, coords, elemCount);
                    putShipInMap(mapBot1, coords, elemCount);
                    for (int i = 0 ; i < 15; i++){
                        for (int j = 0; j < 15; j++){
                            if (sRaftPlacement15X15BF.MapArrayBot1[i][j].spriteState == PLATE_PRESSED){
                                sRaftPlacement15X15BF.MapArrayBot1[i][j].spriteState = PLATE_SUCCES;
                            }
                        }
                    }
                    elemCount = 0;
                    //Все клетки, где нельзя ставить корабль помечаются красным
                    for (int i = 1; i <= 15; i++){
                        for (int j = 1; j <= 15; j++){
                            if (mapBot1[i][j] == 1){
                                sRaftPlacement15X15BF.MapArrayBot1[i - 1][j - 1].spriteState = PLATE_ERROR;
                            }
                        }
                    }

                }
                else {
                    printf("IS_NOT_CORRECT!\n");
                    for (int i = 0 ; i < 15; i++){
                        for (int j = 0; j < 15; j++){
                            if (sRaftPlacement15X15BF.MapArrayBot1[i][j].spriteState == PLATE_PRESSED){
                                sRaftPlacement15X15BF.MapArrayBot1[i][j].spriteState = PLATE_NOT_PRESSED;    
                            }
                        }
                    }
                }
                elemCount = 0;
            }
            else sRaftPlacement15X15BF.state = IN_EDIT_MODE;
            lastClickTime = glfwGetTime();
        }


        if (sRaftPlacement15X15BF.state == IN_EDIT_MODE && sRaftPlacement15X15BF.state != FAQ){

            for (int i = 0; i < 15; i++){
                for (int j = 0; j < 15; j++){
                    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && cursorInArea(xMousePos, yMousePos, sRaftPlacement15X15BF.MapArrayBot1[i][j].sprite->positionX, windowSizeY - sRaftPlacement15X15BF.MapArrayBot1[i][j].sprite->positionY, sRaftPlacement15X15BF.MapArrayBot1[i][j].sprite->positionX + sRaftPlacement15X15BF.MapArrayBot1[i][j].sprite->sizeX, windowSizeY - sRaftPlacement15X15BF.MapArrayBot1[i][j].sprite->positionY - sRaftPlacement15X15BF.MapArrayBot1[i][j].sprite->sizeY, windowSizeX, windowSizeY) && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                        if (sRaftPlacement15X15BF.MapArrayBot1[i][j].spriteState == PLATE_PRESSED){
                            sRaftPlacement15X15BF.MapArrayBot1[i][j].spriteState = PLATE_NOT_PRESSED;
                            elemCount--;
                        }
                        else {
                            if (elemCount < maxElemCount && sRaftPlacement15X15BF.MapArrayBot1[i][j].spriteState != PLATE_SUCCES && sRaftPlacement15X15BF.MapArrayBot1[i][j].spriteState != PLATE_ERROR){
                                sRaftPlacement15X15BF.MapArrayBot1[i][j].spriteState = PLATE_PRESSED;
                                coords[elemCount]->x = j;
                                coords[elemCount]->y = i;
                                elemCount++;
                            }
                        }

                        lastClickTime = glfwGetTime();
                    }

                    if (sRaftPlacement15X15BF.MapArrayBot1[i][j].spriteState == PLATE_PRESSED){
                        renderSprite(sRaftPlacement15X15BF.MapArrayBot1[i][j].sprite, SpriteShaderProgram, THIRD_TEXTURE);
                    }
                    else if (sRaftPlacement15X15BF.MapArrayBot1[i][j].spriteState == PLATE_SUCCES){
                        renderSprite(sRaftPlacement15X15BF.MapArrayBot1[i][j].sprite, SpriteShaderProgram, SECOND_TEXTURE);
                    }
                    else if (sRaftPlacement15X15BF.MapArrayBot1[i][j].spriteState == PLATE_ERROR){
                        renderSprite(sRaftPlacement15X15BF.MapArrayBot1[i][j].sprite, SpriteShaderProgram, FIRST_TEXTURE);
                    }
                }
            }

        }
        else {
            for (int i = 0; i < 15; i++){
                for (int j = 0; j < 15; j++){
                    if (sRaftPlacement15X15BF.MapArrayBot1[i][j].spriteState == PLATE_SUCCES){
                        renderSprite(sRaftPlacement15X15BF.MapArrayBot1[i][j].sprite, SpriteShaderProgram, SECOND_TEXTURE);
                    }
                    else if (sRaftPlacement15X15BF.MapArrayBot1[i][j].spriteState == PLATE_ERROR){
                        renderSprite(sRaftPlacement15X15BF.MapArrayBot1[i][j].sprite, SpriteShaderProgram, FIRST_TEXTURE);
                    }
                }
            }
        }

        changeCorrectSpriteParams(sRaftPlacement15X15BF.Map15x15, windowSizeX, windowSizeY);

        renderSprite(sRaftPlacement15X15BF.Map15x15, SpriteShaderProgram, FIRST_TEXTURE);
        renderSprite(sRaftPlacement15X15BF.ButtonPlates, SpriteShaderProgram, FIRST_TEXTURE);

         //Количество кораблей, которые можно установить на поле
        getRemainedShips(shipBaseBFBot1, ONE_BLOCK_SHIP, CanPutShips);
        renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, CanPutShips, correctXcoords(189.0, windowSizeX) , correctYcoords(623, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        getRemainedShips(shipBaseBFBot1, TWO_BLOCKS_SHIP, CanPutShips);
        renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, CanPutShips, correctXcoords(170.0, windowSizeX) , correctYcoords(597, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        getRemainedShips(shipBaseBFBot1, THREE_BLOCKS_SHIP, CanPutShips);
        renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, CanPutShips, correctXcoords(189.0, windowSizeX) , correctYcoords(571, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        getRemainedShips(shipBaseBFBot1, FOUR_BLOCKS_SHIP, CanPutShips);
        renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, CanPutShips, correctXcoords(176.0, windowSizeX) , correctYcoords(547, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        getRemainedShips(shipBaseBFBot1, FIVE_BLOCKS_SHIP, CanPutShips);
        renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, CanPutShips, correctXcoords(173.0, windowSizeX) , correctYcoords(521, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);

        //Обработка кнопки CLEAR
        if (cursorInArea(xMousePos, yMousePos, 36, 682, 361, 599, windowSizeX, windowSizeY) && sRaftPlacement15X15BF.state != FAQ){
            renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, "Clear", correctXcoords(111.0, windowSizeX) , correctYcoords(54.0, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                clearMap(mapBot1);
                clearShipBase(shipBaseBFBot1);

                for (int i = 0; i < 15; i++){
                    for (int j = 0; j < 15; j++){
                        sRaftPlacement15X15BF.MapArrayBot1[i][j].spriteState = PLATE_NOT_PRESSED;
                    }
                }
                
                lastClickTime = glfwGetTime();
            }  
        }
        else {
            renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, "Clear", correctXcoords(111.0, windowSizeX) , correctYcoords(54.0, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

        //Обработка кнопки AutoGen
        if (cursorInArea(xMousePos, yMousePos, 37, 572, 362, 492, windowSizeX, windowSizeY) && sRaftPlacement15X15BF.state != FAQ){
            renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, "AutoGen", correctXcoords(66.0, windowSizeX) , correctYcoords(164.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                clearMap(mapBot1);
                clearShipBase(shipBaseBFBot1);

                for (int i = 0; i < 15; i++){
                    for (int j = 0; j < 15; j++){
                        sRaftPlacement15X15BF.MapArrayBot1[i][j].spriteState = PLATE_NOT_PRESSED;
                    }
                }
                
                genRandShips(mapBot1, shipBaseBFBot1, MAP_SIZE_15_X_15);

                for (int i = 0; i < 15; i++){
                    for (int j = 0; j < 15; j++){
                        if (mapBot1[i + 1][j + 1] == 2){
                            sRaftPlacement15X15BF.MapArrayBot1[i][j].spriteState = PLATE_SUCCES;
                        }
                    }
                }

                lastClickTime = glfwGetTime();
            }  
        }
        else {
            renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, "AutoGen", correctXcoords(66.0, windowSizeX) , correctYcoords(164.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }
    }
    else if (playerInfo.scene == RAFT_PLACEMENT_15_X_15_BOTS_FIGHT_BOT_2){

        maxElemCount = maxPlatesShip(shipBaseBFBot2);

        //Если сцена открывается повторно нужно снова выделить память под данные о кораблях
        if (shipBaseBFBot2 == NULL){
            shipBaseBFBot2 = initShipBase(MAP_SIZE_15_X_15);
        }

        //Подгон под размер окна каждой клетки на поле
        for (int i = 0 ; i < 15; i++){
            for (int j = 0; j < 15; j++){
                Sprite* sp = sRaftPlacement15X15BF.MapArrayBot2[i][j].sprite;
                changeCorrectSpriteParams(sp, windowSizeX, windowSizeY);
            }
        } 
        
        renderSprite(sRaftPlacement15X15BF.Background, SpriteShaderProgram, FIRST_TEXTURE);
        
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY && sRaftPlacement15X15BF.state != FAQ){
            if (sRaftPlacement15X15BF.state == IN_EDIT_MODE){
                sRaftPlacement15X15BF.state = NOT_IN_EDIT_MODE;
                if (shipIsCorrect(mapBot2, shipBaseBFBot2, elemCount, MAP_SIZE_15_X_15, coords) == SHIP_IS_CORRECT){
                    printf("IS_CORRECT!\n");
                    putShipInBase(shipBaseBFBot2, coords, elemCount);
                    putShipInMap(mapBot2, coords, elemCount);
                    for (int i = 0 ; i < 15; i++){
                        for (int j = 0; j < 15; j++){
                            if (sRaftPlacement15X15BF.MapArrayBot2[i][j].spriteState == PLATE_PRESSED){
                                sRaftPlacement15X15BF.MapArrayBot2[i][j].spriteState = PLATE_SUCCES;  
                            }
                        }
                    }
                    elemCount = 0;
                    //Все клетки, где нельзя ставить корабль помечаются красным
                    for (int i = 1; i <= 15; i++){
                        for (int j = 1; j <= 15; j++){
                            if (mapBot2[i][j] == 1){
                                sRaftPlacement15X15BF.MapArrayBot2[i - 1][j - 1].spriteState = PLATE_ERROR;
                            }
                        }
                    }

                }
                else {
                    printf("IS_NOT_CORRECT!\n");
                    for (int i = 0 ; i < 15; i++){
                        for (int j = 0; j < 15; j++){
                            if (sRaftPlacement15X15BF.MapArrayBot2[i][j].spriteState == PLATE_PRESSED){
                                sRaftPlacement15X15BF.MapArrayBot2[i][j].spriteState = PLATE_NOT_PRESSED;    
                            }
                        }
                    }
                }
                elemCount = 0;
            }
            else sRaftPlacement15X15BF.state = IN_EDIT_MODE;
            lastClickTime = glfwGetTime();
        }


        if (sRaftPlacement15X15BF.state == IN_EDIT_MODE && sRaftPlacement15X15BF.state != FAQ){
            for (int i = 0; i < 15; i++){
                for (int j = 0; j < 15; j++){
                    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && cursorInArea(xMousePos, yMousePos, sRaftPlacement15X15BF.MapArrayBot2[i][j].sprite->positionX, windowSizeY - sRaftPlacement15X15BF.MapArrayBot2[i][j].sprite->positionY, sRaftPlacement15X15BF.MapArrayBot2[i][j].sprite->positionX + sRaftPlacement15X15BF.MapArrayBot2[i][j].sprite->sizeX, windowSizeY - sRaftPlacement15X15BF.MapArrayBot2[i][j].sprite->positionY - sRaftPlacement15X15BF.MapArrayBot2[i][j].sprite->sizeY, windowSizeX, windowSizeY) && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                        if (sRaftPlacement15X15BF.MapArrayBot2[i][j].spriteState == PLATE_PRESSED){
                            sRaftPlacement15X15BF.MapArrayBot2[i][j].spriteState = PLATE_NOT_PRESSED;
                            elemCount--;
                        }
                        else {
                            if (elemCount < maxElemCount && sRaftPlacement15X15BF.MapArrayBot2[i][j].spriteState != PLATE_SUCCES && sRaftPlacement15X15BF.MapArrayBot2[i][j].spriteState != PLATE_ERROR){
                                sRaftPlacement15X15BF.MapArrayBot2[i][j].spriteState = PLATE_PRESSED;
                                coords[elemCount]->x = j;
                                coords[elemCount]->y = i;
                                elemCount++;
                            }
                        }

                        lastClickTime = glfwGetTime();
                    }

                    if (sRaftPlacement15X15BF.MapArrayBot2[i][j].spriteState == PLATE_PRESSED){
                        renderSprite(sRaftPlacement15X15BF.MapArrayBot2[i][j].sprite, SpriteShaderProgram, THIRD_TEXTURE);
                    }
                    else if (sRaftPlacement15X15BF.MapArrayBot2[i][j].spriteState == PLATE_SUCCES){
                        renderSprite(sRaftPlacement15X15BF.MapArrayBot2[i][j].sprite, SpriteShaderProgram, SECOND_TEXTURE);
                    }
                    else if (sRaftPlacement15X15BF.MapArrayBot2[i][j].spriteState == PLATE_ERROR){
                        renderSprite(sRaftPlacement15X15BF.MapArrayBot2[i][j].sprite, SpriteShaderProgram, FIRST_TEXTURE);
                    }
                }
            }

        }
        else {
            for (int i = 0; i < 15; i++){
                for (int j = 0; j < 15; j++){
                    if (sRaftPlacement15X15BF.MapArrayBot2[i][j].spriteState == PLATE_SUCCES){
                        renderSprite(sRaftPlacement15X15BF.MapArrayBot2[i][j].sprite, SpriteShaderProgram, SECOND_TEXTURE);
                    }
                    else if (sRaftPlacement15X15BF.MapArrayBot2[i][j].spriteState == PLATE_ERROR){
                        renderSprite(sRaftPlacement15X15BF.MapArrayBot2[i][j].sprite, SpriteShaderProgram, FIRST_TEXTURE);
                    }
                }
            }
        }

        changeCorrectSpriteParams(sRaftPlacement15X15BF.Map15x15, windowSizeX, windowSizeY);

        renderSprite(sRaftPlacement15X15BF.Map15x15, SpriteShaderProgram, FIRST_TEXTURE);
        renderSprite(sRaftPlacement15X15BF.ButtonPlates, SpriteShaderProgram, FIRST_TEXTURE);

         //Количество кораблей, которые можно установить на поле
        getRemainedShips(shipBaseBFBot2, ONE_BLOCK_SHIP, CanPutShips);
        renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, CanPutShips, correctXcoords(189.0, windowSizeX) , correctYcoords(623, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        getRemainedShips(shipBaseBFBot2, TWO_BLOCKS_SHIP, CanPutShips);
        renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, CanPutShips, correctXcoords(170.0, windowSizeX) , correctYcoords(597, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        getRemainedShips(shipBaseBFBot2, THREE_BLOCKS_SHIP, CanPutShips);
        renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, CanPutShips, correctXcoords(189.0, windowSizeX) , correctYcoords(571, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        getRemainedShips(shipBaseBFBot2, FOUR_BLOCKS_SHIP, CanPutShips);
        renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, CanPutShips, correctXcoords(176.0, windowSizeX) , correctYcoords(547, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        getRemainedShips(shipBaseBFBot2, FIVE_BLOCKS_SHIP, CanPutShips);
        renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, CanPutShips, correctXcoords(173.0, windowSizeX) , correctYcoords(521, windowSizeY), correctTextSize(0.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);

        //Обработка кнопки CLEAR
        if (cursorInArea(xMousePos, yMousePos, 36, 682, 361, 599, windowSizeX, windowSizeY) && sRaftPlacement15X15BF.state != FAQ){
            renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, "Clear", correctXcoords(111.0, windowSizeX) , correctYcoords(54.0, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                clearMap(mapBot2);
                clearShipBase(shipBaseBFBot2);

                for (int i = 0; i < 15; i++){
                    for (int j = 0; j < 15; j++){
                        sRaftPlacement15X15BF.MapArrayBot2[i][j].spriteState = PLATE_NOT_PRESSED;
                    }
                }
                
                lastClickTime = glfwGetTime();
            }  
        }
        else {
            renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, "Clear", correctXcoords(111.0, windowSizeX) , correctYcoords(54.0, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

        //Обработка кнопки AutoGen
        if (cursorInArea(xMousePos, yMousePos, 37, 572, 362, 492, windowSizeX, windowSizeY) && sRaftPlacement15X15BF.state != FAQ){
            renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, "AutoGen", correctXcoords(66.0, windowSizeX) , correctYcoords(164.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                clearMap(mapBot2);
                clearShipBase(shipBaseBFBot2);

                for (int i = 0; i < 15; i++){
                    for (int j = 0; j < 15; j++){
                        sRaftPlacement15X15BF.MapArrayBot2[i][j].spriteState = PLATE_NOT_PRESSED;
                    }
                }
                
                genRandShips(mapBot2, shipBaseBFBot2, MAP_SIZE_15_X_15);

                for (int i = 0; i < 15; i++){
                    for (int j = 0; j < 15; j++){
                        if (mapBot2[i + 1][j + 1] == 2){
                            sRaftPlacement15X15BF.MapArrayBot2[i][j].spriteState = PLATE_SUCCES;
                        }
                    }
                }

                lastClickTime = glfwGetTime();
            }  
        }
        else {
            renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, "AutoGen", correctXcoords(66.0, windowSizeX) , correctYcoords(164.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }
    }

    //Индикатор режима редактирования
    if(sRaftPlacement15X15BF.state == IN_EDIT_MODE){           
        renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, "e", correctXcoords(1222.0, windowSizeX) , correctYcoords(521.0, windowSizeY), correctTextSize(1.5, windowSizeX, windowSizeY), 1.0f, 1.0f, 0.0f);
    }
    else{
        renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, "e", correctXcoords(1222.0, windowSizeX) , correctYcoords(521.0, windowSizeY), correctTextSize(1.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        renderSprite(sRaftPlacement15X15BF.ExitBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }

    //Обработка кнопки Exit
    if (cursorInArea(xMousePos, yMousePos, 1202, 64, 1262, 17, windowSizeX, windowSizeY) && sRaftPlacement15X15BF.state != FAQ){
        renderSprite(sRaftPlacement15X15BF.ExitBtn, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            
            if (shipBaseBFBot1 != NULL) freeShipBase(shipBaseBFBot1);
            if (shipBaseBFBot2 != NULL) freeShipBase(shipBaseBFBot2);

            shipBaseBFBot1 = NULL;
            shipBaseBFBot2 = NULL;

            clearMap(mapBot1);
            clearMap(mapBot2);

            for (int i = 0; i < 15; i++){
                for (int j = 0; j < 15; j++){
                    sRaftPlacement15X15BF.MapArrayBot1[i][j].spriteState = PLATE_NOT_PRESSED;
                    sRaftPlacement15X15BF.MapArrayBot2[i][j].spriteState = PLATE_NOT_PRESSED;
                }
            }

            playerInfo.scene = MAIN_MENU_SCENES;
            playerInfo.BotLevel = NOT_FILLED_IN;
            playerInfo.GameMode = NOT_FILLED_IN;
            playerInfo.MapSize = NOT_FILLED_IN;
            lastClickTime = glfwGetTime();
        }
    }
    else{
        renderSprite(sRaftPlacement15X15BF.ExitBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }

    //Обработка кнопки подсказки
    if (cursorInArea(xMousePos, yMousePos, 1200, 139, 1264, 89, windowSizeX, windowSizeY)){
        renderSprite(sRaftPlacement15X15BF.QuestionMarkBtn, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            lastSceneState = sRaftPlacement15X15BF.state;
            sRaftPlacement15X15BF.state = FAQ;
            lastClickTime = glfwGetTime();
        }
    }
    else {
        renderSprite(sRaftPlacement15X15BF.QuestionMarkBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }

    //Обработка конпки B1
    if (cursorInArea(xMousePos, yMousePos, 1200, 277, 1264, 227, windowSizeX, windowSizeY) || playerInfo.scene == RAFT_PLACEMENT_15_X_15_BOTS_FIGHT_BOT_1){
        renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, "B1", correctXcoords(1215.0, windowSizeX) , correctYcoords(452.0, windowSizeY), correctTextSize(1.1, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY && playerInfo.scene != RAFT_PLACEMENT_15_X_15_BOTS_FIGHT_BOT_1){
            playerInfo.scene = RAFT_PLACEMENT_15_X_15_BOTS_FIGHT_BOT_1;
            lastClickTime = glfwGetTime();
            if (sRaftPlacement15X15BF.state == IN_EDIT_MODE){
                sRaftPlacement15X15BF.state = NOT_IN_EDIT_MODE;
            }
        }
    }
    else {
        renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, "B1", correctXcoords(1215.0, windowSizeX) , correctYcoords(452.0, windowSizeY), correctTextSize(1.1, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    //Обработка конпки B2
    if (cursorInArea(xMousePos, yMousePos, 1200, 349, 1264, 294, windowSizeX, windowSizeY) || playerInfo.scene == RAFT_PLACEMENT_15_X_15_BOTS_FIGHT_BOT_2){
        renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, "B2", correctXcoords(1212.0, windowSizeX) , correctYcoords(382.0, windowSizeY), correctTextSize(1.0, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY &&  playerInfo.scene != RAFT_PLACEMENT_15_X_15_BOTS_FIGHT_BOT_2){
            playerInfo.scene = RAFT_PLACEMENT_15_X_15_BOTS_FIGHT_BOT_2;
            lastClickTime = glfwGetTime();
            if (sRaftPlacement15X15BF.state == IN_EDIT_MODE){
                sRaftPlacement15X15BF.state = NOT_IN_EDIT_MODE;
            }
        }
    }
    else {
        renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, "B2", correctXcoords(1212.0, windowSizeX) , correctYcoords(382.0, windowSizeY), correctTextSize(1.0, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    //Обработка кнопки PLAY
    if (cursorInArea(xMousePos, yMousePos, 42, 464, 359, 385, windowSizeX, windowSizeY) && sRaftPlacement15X15BF.state != FAQ){
        if (AllShipsInMap(shipBaseBFBot2) == NOT_ALL_SHIPS_IN_MAP || AllShipsInMap(shipBaseBFBot1) == NOT_ALL_SHIPS_IN_MAP){
            renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, "Play", correctXcoords(124.0, windowSizeX) , correctYcoords(274, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 1.0f, 0.0f, 0.0f);
        }
        else {
            renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, "Play", correctXcoords(124.0, windowSizeX) , correctYcoords(274, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 0.0f, 1.0f, 0.0f);
        }

        if (AllShipsInMap(shipBaseBFBot2) == ALL_SHIPS_IN_MAP && AllShipsInMap(shipBaseBFBot1) == ALL_SHIPS_IN_MAP && glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            playerInfo.scene = MAIN_GAME_BOT_FIGHT_15_X_15;

            fillShipsTextures15x15(sMainGameBotFight15x15.Bot1MapArray, shipBaseBFBot1, mapBot1, TEXTURES_TURN_RIGHT);
            fillShipsTextures15x15(sMainGameBotFight15x15.Bot2MapArray, shipBaseBFBot2, mapBot2, TEXTURES_TURN_LEFT);

            clearTrashFromMap(mapBot1);
            clearTrashFromMap(mapBot2);

            if (rand() % 2 == 0) sMainGameBotFight15x15.state = BOT_2_SHOT;
            else sMainGameBotFight15x15.state = BOT_1_SHOT;

            for (int i = 0; i < 15; i++){
                for (int j = 0; j < 15; j++){
                    sRaftPlacement15X15BF.MapArrayBot1[i][j].spriteState = PLATE_NOT_PRESSED;
                    sRaftPlacement15X15BF.MapArrayBot2[i][j].spriteState = PLATE_NOT_PRESSED;
                }
            }

            lastClickTime = glfwGetTime();
        }  
    }
    else {
        renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, "Play", correctXcoords(124.0, windowSizeX) , correctYcoords(274, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    //Обработка FAQ
    if (sRaftPlacement15X15BF.state == FAQ){
        renderSprite(sRaftPlacement15X15BF.FAQPlate, SpriteShaderProgram, FIRST_TEXTURE);
        for (int i = 0, startY = 530; i < FAQRaftPlacementBFStringCount; i++, startY -= 35){
            renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, FAQRaftPlacementBF[i], correctXcoords(320.0, windowSizeX) , correctYcoords(startY, windowSizeY), correctTextSize(0.6, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

        if (cursorInArea(xMousePos, yMousePos, 490, 620, 791, 545, windowSizeX, windowSizeY)){
            renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, "OK", correctXcoords(585.0, windowSizeX) , correctYcoords(112, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                sRaftPlacement15X15BF.state = lastSceneState;
                lastClickTime = glfwGetTime();
            }
        }
        else {
            renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, "OK", correctXcoords(585.0, windowSizeX) , correctYcoords(112, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }    
        
    }
        
}

void renderMainGameBase10x10(GLFWwindow* window)
{
    extern GLuint SpriteShaderProgram;
    extern GLuint TextShaderProgram;
    extern MainGameBase10x10 sMainGameBase10x10;
    extern Player playerInfo;
    extern ShipBase* shipBase;
    extern ShipBase* botShipBase;

    extern int map[18][18];
    extern int mapBot[18][18];

    extern int windowSizeX;
    extern int windowSizeY;

    extern int playerScore;
    extern int botScore;

    extern double lastClickTime;

    extern char FAQMainGame10x10Basic [5][MAX_STRING_SIZE];
    extern const int FAQMainGame10x10BasicStringCount;

    double xMousePos,
           yMousePos;

    int PlayerShipsLeft,
        BotShipsLeft;

    static int x, y;
    static int lastSceneState = 0;
    
    int botAttackResult;

    static int whoWin = 0;

    extern int botMode;

    char shipsLeftStr[3] = {'\0',};
    char botScoreStr[5] = {'\0',};

    static double lastPlayerShotTime = 0,
                  lastBotShotTime = 0;

    glfwGetCursorPos(window, &xMousePos, &yMousePos);
    printf("%.2lf  %.2lf    ", xMousePos, yMousePos);
    printf("Window size: %dx%d\n", windowSizeX, windowSizeY);

    renderSprite(sMainGameBase10x10.Background, SpriteShaderProgram, FIRST_TEXTURE);
    renderSprite(sMainGameBase10x10.ButtonPlates, SpriteShaderProgram, FIRST_TEXTURE);

    //Отображение поля
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (map[i + 1][j + 1] == SHIP_PLATE)
                renderSprite(sMainGameBase10x10.PlayerMapArray[i][j].sprite, SpriteShaderProgram, FIRST_TEXTURE);
            else if (map[i + 1][j + 1] == HIT_PLATE){
                renderSprite(sMainGameBase10x10.PlayerMapArray[i][j].sprite, SpriteShaderProgram, SECOND_TEXTURE);
            }
            else if (map[i + 1][j + 1] == MISS_PLATE){
                renderSprite(sMainGameBase10x10.PlayerMapArray[i][j].sprite, SpriteShaderProgram, THIRD_TEXTURE);
            }

            if (mapBot[i + 1][j + 1] == HIT_PLATE)
                renderSprite(sMainGameBase10x10.BotMapArray[i][j].sprite, SpriteShaderProgram, FIRST_TEXTURE);
            else if (mapBot[i + 1][j + 1] == MISS_PLATE)
                renderSprite(sMainGameBase10x10.BotMapArray[i][j].sprite, SpriteShaderProgram, SECOND_TEXTURE);
        }
    }

    renderSprite(sMainGameBase10x10.MainMap10x10, SpriteShaderProgram, FIRST_TEXTURE);

    //0 - пустая клетка
    //1 - промах
    //2 - корабль
    //3 - подбитый корабль

    if (sMainGameBase10x10.state == PLAYER_SHOT && glfwGetTime() - lastPlayerShotTime >= PLAYER_DELAY){
        //Обработка выстрела игрока
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && cursorInArea(xMousePos, yMousePos, sMainGameBase10x10.BotMapArray[i][j].sprite->positionX, windowSizeY - sMainGameBase10x10.BotMapArray[i][j].sprite->positionY, sMainGameBase10x10.BotMapArray[i][j].sprite->positionX + sMainGameBase10x10.BotMapArray[i][j].sprite->sizeX, windowSizeY - sMainGameBase10x10.BotMapArray[i][j].sprite->positionY - sMainGameBase10x10.BotMapArray[i][j].sprite->sizeY, windowSizeX, windowSizeY) && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                    if (mapBot[i + 1][j + 1] == SHIP_PLATE){
                        mapBot[i + 1][j + 1] = HIT_PLATE;
                        if (killShipInShipBase(botShipBase, j, i) == SHIP_KILLED){
                            putMisses(mapBot, botShipBase, j, i, 1);
                        }
                        playerScore++;

                    }
                    else if (mapBot[i + 1][j + 1] == EMPTY_PLATE){
                        mapBot[i + 1][j + 1] = MISS_PLATE;
                        sMainGameBase10x10.state = BOT_SHOT;
                        playerScore++;
                    }
                    lastPlayerShotTime = glfwGetTime();
                }
            }
        }
    }
    else if (sMainGameBase10x10.state == BOT_SHOT && glfwGetTime() - lastBotShotTime >= BOT_DELAY) {
        //Обработка выстрела бота
        for (int i = 0; i < 10000000; i++);

        if (playerInfo.BotLevel == EASY_BOT_LEVEL){
            if ((botAttackResult = easyLevelBot(&x, &y, map, MAP_SIZE_10_X_10)) == HIT_PLATE){
                killShipInShipBase(shipBase, x - 1, y - 1);
            }
            else if (botAttackResult == MISS_PLATE){
                sMainGameBase10x10.state = PLAYER_SHOT;
            }
        }
        else if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
            if ((botAttackResult = mediumLevelBot(&x, &y, map, MAP_SIZE_10_X_10, GAME_PROCESS)) == HIT_PLATE){
                if (killShipInShipBase(shipBase, x - 1, y - 1) == SHIP_KILLED){
                    putMisses(map, shipBase, x - 1, y - 1, 4);
                }
            }
            else if (botAttackResult == MISS_PLATE){
                sMainGameBase10x10.state = PLAYER_SHOT;
            }
        }
        else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
            if (botMode == ATTACK_MODE){
                if ((botAttackResult = hardLevelBot(&x, &y, map, MAP_SIZE_10_X_10, shipBase, GAME_PROCESS)) == HIT_PLATE){
                    if (killShipInShipBase(shipBase, x - 1, y - 1) == SHIP_KILLED){
                        putMisses(map, shipBase, x - 1, y - 1, 4);
                    }
                    else {
                        botMode = FINISHING_OFF_MODE;
                    }

                }
                else if (botAttackResult == MISS_PLATE){
                    sMainGameBase10x10.state = PLAYER_SHOT;
                }
                else if (botAttackResult == GAME_END){
                    sMainGameBase10x10.state = PLAYER_SHOT;
                }
            }
            else {
                if ((botAttackResult = finishingOff(x , y, map, shipBase, ATTACK_PROCESS, MAP_SIZE_10_X_10)) == MISS_PLATE){
                    sMainGameBase10x10.state = PLAYER_SHOT;
                }
                else if (botAttackResult == SHIP_KILLED){
                    finishingOff(x , y, map, shipBase, ATTACK_END, MAP_SIZE_10_X_10);
                    putMisses(map, shipBase, x - 1, y - 1, 4);
                    botMode = ATTACK_MODE;
                }
            }
        }
        botScore++;
        lastBotShotTime = glfwGetTime();
    }
    else if (sMainGameBase10x10.state == FAQ){
        renderSprite(sMainGameBase10x10.FAQPlate, SpriteShaderProgram, FIRST_TEXTURE);
        for (int i = 0, startY = 530; i < FAQMainGame10x10BasicStringCount; i++, startY -= 30){
            renderText(sMainGameBase10x10.TextParams, TextShaderProgram, FAQMainGame10x10Basic[i], correctXcoords(320.0, windowSizeX) , correctYcoords(startY, windowSizeY), correctTextSize(0.6, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

        if (cursorInArea(xMousePos, yMousePos, 490, 620, 791, 545, windowSizeX, windowSizeY)){
            renderText(sMainGameBase10x10.TextParams, TextShaderProgram, "OK", correctXcoords(585.0, windowSizeX) , correctYcoords(112, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                sMainGameBase10x10.state = lastSceneState;
                lastClickTime = glfwGetTime();
            }
        }
        else {
            renderText(sMainGameBase10x10.TextParams, TextShaderProgram, "OK", correctXcoords(585.0, windowSizeX) , correctYcoords(112, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }    
        
    }
    else if (sMainGameBase10x10.state == GAME_END){
        //Обработка победы бота
        if (whoWin == BOT_WIN){
            renderSprite(sMainGameBase10x10.lostPlate, SpriteShaderProgram, FIRST_TEXTURE);
            snprintf(botScoreStr, 4, "%d", botScore);
            renderText(sMainGameBase10x10.TextParams, TextShaderProgram, botScoreStr, correctXcoords(705.0, windowSizeX) , correctYcoords(348, windowSizeY), correctTextSize(0.7, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);

            if (cursorInArea(xMousePos, yMousePos, 442, 491, 831, 408, windowSizeX, windowSizeY)){
                renderText(sMainGameBase10x10.TextParams, TextShaderProgram, "Back To Menu", correctXcoords(475.0, windowSizeX) , correctYcoords(256, windowSizeY), correctTextSize(1.2, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
                if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                    if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
                        mediumLevelBot(&x, &y, mapBot, MAP_SIZE_10_X_10, GAME_END);
                    }
                    else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
                        hardLevelBot(&x, &y, mapBot, MAP_SIZE_10_X_10, botShipBase, GAME_END);
                    }

                    playerInfo.BotLevel = NOT_FILLED_IN;
                    playerInfo.GameMode = NOT_FILLED_IN;
                    playerInfo.MapSize = NOT_FILLED_IN;
                    playerInfo.scene = MAIN_MENU_SCENES;
                    botMode = ATTACK_MODE;

                    if (shipBase != NULL){
                        freeShipBase(shipBase);
                        shipBase = NULL;
                    }
                    if (botShipBase != NULL){
                        freeShipBase(botShipBase);
                        botShipBase = NULL;
                    }
                    
                    playerScore = 0;
                    botScore = 0;

                    clearMap(map);
                    clearMap(mapBot);

                    lastClickTime = glfwGetTime();
                }
            }
            else {
                renderText(sMainGameBase10x10.TextParams, TextShaderProgram, "Back To Menu", correctXcoords(475.0, windowSizeX) , correctYcoords(256, windowSizeY), correctTextSize(1.2, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);       
            }  
        }  
        else if (whoWin == PLAYER_WIN){
            //Обработка победы Игрока
            renderSprite(sMainGameBase10x10.wonPlate, SpriteShaderProgram, FIRST_TEXTURE);
            snprintf(botScoreStr, 4, "%d", playerScore);
            renderText(sMainGameBase10x10.TextParams, TextShaderProgram, botScoreStr, correctXcoords(665.0, windowSizeX) , correctYcoords(411, windowSizeY), correctTextSize(0.7, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);

            //Если игрок не захотел добавлять имя на доску лидеров, то просто выход в главное меню
            if (cursorInArea(xMousePos, yMousePos, 428, 536, 859, 452, windowSizeX, windowSizeY)){
                renderText(sMainGameBase10x10.TextParams, TextShaderProgram, "Back To Menu", correctXcoords(478.0, windowSizeX) , correctYcoords(213, windowSizeY), correctTextSize(1.2, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
                if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                    if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
                        mediumLevelBot(&x, &y, mapBot, MAP_SIZE_10_X_10, GAME_END);
                    }
                    else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
                        hardLevelBot(&x, &y, mapBot, MAP_SIZE_10_X_10, botShipBase, GAME_END);
                    }

                    playerInfo.BotLevel = NOT_FILLED_IN;
                    playerInfo.GameMode = NOT_FILLED_IN;
                    playerInfo.MapSize = NOT_FILLED_IN;
                    playerInfo.scene = MAIN_MENU_SCENES;
                    botMode = ATTACK_MODE;

                    if (shipBase != NULL){
                        freeShipBase(shipBase);
                        shipBase = NULL;
                    }
                    if (botShipBase != NULL){
                        freeShipBase(botShipBase);
                        botShipBase = NULL;
                    }
                    
                    playerScore = 0;
                    botScore = 0;

                    clearMap(map);
                    clearMap(mapBot);

                    lastClickTime = glfwGetTime();
                }
            }
            else {
                renderText(sMainGameBase10x10.TextParams, TextShaderProgram, "Back To Menu", correctXcoords(478.0, windowSizeX) , correctYcoords(213, windowSizeY), correctTextSize(1.2, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);       
            } 

            //Обработка кнопки добавления на доску лидеров
            if (cursorInArea(xMousePos, yMousePos, 431, 429, 856, 342, windowSizeX, windowSizeY)){
                renderText(sMainGameBase10x10.TextParams, TextShaderProgram, "Add To LeaderBoard", correctXcoords(468.0, windowSizeX) , correctYcoords(325, windowSizeY), correctTextSize(0.9, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
                if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                    if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
                        mediumLevelBot(&x, &y, mapBot, MAP_SIZE_10_X_10, GAME_END);
                    }
                    else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
                        hardLevelBot(&x, &y, mapBot, MAP_SIZE_10_X_10, botShipBase, GAME_END);
                    }
                    
                    playerInfo.scene = ADDING_TO_THE_LEADERBOARD_SCENES;

                    if (shipBase != NULL){
                        freeShipBase(shipBase);
                        shipBase = NULL;
                    }
                    if (botShipBase != NULL){
                        freeShipBase(botShipBase);
                        botShipBase = NULL;
                    }

                    botScore = 0;

                    clearMap(map);
                    clearMap(mapBot);

                    lastClickTime = glfwGetTime();
                }
            }
            else {
                renderText(sMainGameBase10x10.TextParams, TextShaderProgram, "Add To LeaderBoard", correctXcoords(468.0, windowSizeX) , correctYcoords(325, windowSizeY), correctTextSize(0.9, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);       
            } 
        }
    }
    else if (sMainGameBase10x10.state == EXIT_QUESTION){
        renderSprite(sMainGameBase10x10.exitQuestion, SpriteShaderProgram, FIRST_TEXTURE);

        //Обработка кнопки YES
        if (cursorInArea(xMousePos, yMousePos, 325, 458, 589, 362, windowSizeX, windowSizeY)){
            renderText(sMainGameBase10x10.TextParams, TextShaderProgram, "YES" , correctXcoords(389.0, windowSizeX) , correctYcoords(290.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                playerInfo.scene = SAVING_GAME_SCENES;
                sMainGameBase10x10.state = lastSceneState;
                lastClickTime = glfwGetTime();
            }
        }
        else {
            renderText(sMainGameBase10x10.TextParams, TextShaderProgram, "YES" , correctXcoords(389.0, windowSizeX) , correctYcoords(290.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        } 

        //Обработка кнопки NO
        if (cursorInArea(xMousePos, yMousePos, 685, 458, 952, 362, windowSizeX, windowSizeY)){
            renderText(sMainGameBase10x10.TextParams, TextShaderProgram, "NO" , correctXcoords(775.0, windowSizeX) , correctYcoords(290.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
                    mediumLevelBot(&x, &y, mapBot, MAP_SIZE_10_X_10, GAME_END);
                }
                else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
                    hardLevelBot(&x, &y, mapBot, MAP_SIZE_10_X_10, botShipBase, GAME_END);
                }

                playerInfo.BotLevel = NOT_FILLED_IN;
                playerInfo.GameMode = NOT_FILLED_IN;
                playerInfo.MapSize = NOT_FILLED_IN;
                playerInfo.scene = MAIN_MENU_SCENES;
                botMode = ATTACK_MODE;

                if (shipBase != NULL){
                    freeShipBase(shipBase);
                    shipBase = NULL;
                }
                if (botShipBase != NULL){
                    freeShipBase(botShipBase);
                    botShipBase = NULL;
                }
                
                playerScore = 0;
                botScore = 0;

                clearMap(map);
                clearMap(mapBot);

                lastClickTime = glfwGetTime();
            }
        }
        else {
            renderText(sMainGameBase10x10.TextParams, TextShaderProgram, "NO" , correctXcoords(775.0, windowSizeX) , correctYcoords(290.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }
        
    }


    BotShipsLeft = getShipsLeft(botShipBase);
    snprintf(shipsLeftStr, 3, "%d", BotShipsLeft);
    renderText(sMainGameBase10x10.TextParams, TextShaderProgram, shipsLeftStr, correctXcoords(907.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    
    memset(shipsLeftStr, '\0', 3);

    PlayerShipsLeft = getShipsLeft(shipBase);
    snprintf(shipsLeftStr, 3, "%d", PlayerShipsLeft);
    renderText(sMainGameBase10x10.TextParams, TextShaderProgram, shipsLeftStr, correctXcoords(274.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);

    //Если у кого-то из игроков не осталось кораблей, значит игра закончилась
    if ((PlayerShipsLeft == 0 || BotShipsLeft == 0) && sMainGameBase10x10.state != FAQ){
        sMainGameBase10x10.state = GAME_END;
        if (PlayerShipsLeft == 0){
            whoWin = BOT_WIN;
        }
        else if (BotShipsLeft == 0){
            whoWin = PLAYER_WIN;
        }
    }


    //Отображение того, чей выстрел ожидается в данный момент
    if (sMainGameBase10x10.state == PLAYER_SHOT || (sMainGameBase10x10.state == FAQ && lastSceneState == PLAYER_SHOT) || (sMainGameBase10x10.state == EXIT_QUESTION && lastSceneState == PLAYER_SHOT)){
        renderText(sMainGameBase10x10.TextParams, TextShaderProgram, "YOUR SHOT" , correctXcoords(442.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }
    else if (sMainGameBase10x10.state == BOT_SHOT || (sMainGameBase10x10.state == FAQ && lastSceneState == BOT_SHOT) || (sMainGameBase10x10.state == EXIT_QUESTION && lastSceneState == BOT_SHOT)){
        renderText(sMainGameBase10x10.TextParams, TextShaderProgram, "ENEMY SHOT" , correctXcoords(430.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }
    else if (sMainGameBase10x10.state == GAME_END || (sMainGameBase10x10.state == FAQ && lastSceneState == GAME_END) || (sMainGameBase10x10.state == EXIT_QUESTION && lastSceneState == GAME_END)){
        renderText(sMainGameBase10x10.TextParams, TextShaderProgram, "GAME END" , correctXcoords(446.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    //Обработка FAQ
    if (cursorInArea(xMousePos, yMousePos, 1108, 70, 1169, 24, windowSizeX, windowSizeY) && sMainGameBase10x10.state != FAQ && sMainGameBase10x10.state != EXIT_QUESTION){
        renderSprite(sMainGameBase10x10.QuestionMarkBtn, SpriteShaderProgram, SECOND_TEXTURE);
         if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            lastSceneState = sMainGameBase10x10.state;
            sMainGameBase10x10.state = FAQ;
            lastClickTime = glfwGetTime();
        }
    }
    else {
        renderSprite(sMainGameBase10x10.QuestionMarkBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }    

    //Обработка кнопки Exit
    if (cursorInArea(xMousePos, yMousePos, 1196, 73, 1260, 20, windowSizeX, windowSizeY) && sMainGameBase10x10.state != FAQ){
        renderSprite(sMainGameBase10x10.ExitBtn, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            if (sMainGameBase10x10.state == EXIT_QUESTION){
                sMainGameBase10x10.state = lastSceneState;
            }
            else {
                lastSceneState = sMainGameBase10x10.state;
                sMainGameBase10x10.state = EXIT_QUESTION;
            }

            lastClickTime = glfwGetTime();
        }
    }
    else {
        renderSprite(sMainGameBase10x10.ExitBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }    
    
    
}

void renderMainGameBase15x15(GLFWwindow* window)
{
    extern GLuint SpriteShaderProgram;
    extern GLuint TextShaderProgram;
    extern MainGameBase15x15 sMainGameBase15x15;
    extern Player playerInfo;
    extern ShipBase* shipBase;
    extern ShipBase* botShipBase;

    extern int map[18][18];
    extern int mapBot[18][18];

    extern int windowSizeX;
    extern int windowSizeY;

    extern double lastClickTime;

    extern char FAQMainGame10x10Basic [5][MAX_STRING_SIZE];
    extern const int FAQMainGame10x10BasicStringCount;

    extern int playerScore;
    extern int botScore;

    double xMousePos,
           yMousePos;

    int PlayerShipsLeft,
        BotShipsLeft;

    static int x, y;
    static int lastSceneState = 0;

    static int whoWin = 0;
    
    int botAttackResult;

    extern int botMode;

    char shipsLeftStr[3] = {'\0',};
    char botScoreStr[5] = {'\0',};

    static double lastPlayerShotTime = 0,
                  lastBotShotTime = 0;
    

    glfwGetCursorPos(window, &xMousePos, &yMousePos);
    //printf("%.2lf  %.2lf    ", xMousePos, yMousePos);
    //printf("Window size: %dx%d\n", windowSizeX, windowSizeY);

    renderSprite(sMainGameBase15x15.Background, SpriteShaderProgram, FIRST_TEXTURE);
    renderSprite(sMainGameBase15x15.ButtonPlates, SpriteShaderProgram, FIRST_TEXTURE);

    //Отображение поля
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            if (map[i + 1][j + 1] == SHIP_PLATE)
                renderSprite(sMainGameBase15x15.PlayerMapArray[i][j].sprite, SpriteShaderProgram, FIRST_TEXTURE);
            else if (map[i + 1][j + 1] == HIT_PLATE){
                renderSprite(sMainGameBase15x15.PlayerMapArray[i][j].sprite, SpriteShaderProgram, SECOND_TEXTURE);
            }
            else if (map[i + 1][j + 1] == MISS_PLATE){
                renderSprite(sMainGameBase15x15.PlayerMapArray[i][j].sprite, SpriteShaderProgram, THIRD_TEXTURE);
            }

            if (mapBot[i + 1][j + 1] == HIT_PLATE)
                renderSprite(sMainGameBase15x15.BotMapArray[i][j].sprite, SpriteShaderProgram, FIRST_TEXTURE);
            else if (mapBot[i + 1][j + 1] == MISS_PLATE)
                renderSprite(sMainGameBase15x15.BotMapArray[i][j].sprite, SpriteShaderProgram, SECOND_TEXTURE);
        }
    }

   renderSprite(sMainGameBase15x15.MainMap15x15, SpriteShaderProgram, FIRST_TEXTURE);

    //0 - пустая клетка
    //1 - промах
    //2 - корабль
    //3 - подбитый корабль

    if (sMainGameBase15x15.state == PLAYER_SHOT && glfwGetTime() - lastPlayerShotTime >= PLAYER_DELAY){
        //Обработка выстрела игрока
        for (int i = 0; i < 15; i++){
            for (int j = 0; j < 15; j++){
                if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && cursorInArea(xMousePos, yMousePos, sMainGameBase15x15.BotMapArray[i][j].sprite->positionX, windowSizeY - sMainGameBase15x15.BotMapArray[i][j].sprite->positionY, sMainGameBase15x15.BotMapArray[i][j].sprite->positionX + sMainGameBase15x15.BotMapArray[i][j].sprite->sizeX, windowSizeY - sMainGameBase15x15.BotMapArray[i][j].sprite->positionY - sMainGameBase15x15.BotMapArray[i][j].sprite->sizeY, windowSizeX, windowSizeY) && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                    if (mapBot[i + 1][j + 1] == SHIP_PLATE){
                        mapBot[i + 1][j + 1] = HIT_PLATE;
                        if (killShipInShipBase(botShipBase, j, i) == SHIP_KILLED){
                            putMisses(mapBot, botShipBase, j, i, 1);
                        }
                        playerScore++;

                    }
                    else if (mapBot[i + 1][j + 1] == EMPTY_PLATE){
                        mapBot[i + 1][j + 1] = MISS_PLATE;
                        sMainGameBase15x15.state = BOT_SHOT;
                        playerScore++;
                    }
                    lastPlayerShotTime - glfwGetTime();
                }
            }
        }
    }
    else if (sMainGameBase15x15.state == BOT_SHOT && glfwGetTime() - lastBotShotTime >= BOT_DELAY) {
        //Обработка выстрела бота
        if (playerInfo.BotLevel == EASY_BOT_LEVEL){
            if ((botAttackResult = easyLevelBot(&x, &y, map, MAP_SIZE_15_X_15)) == HIT_PLATE){
                killShipInShipBase(shipBase, x - 1, y - 1);
            }
            else if (botAttackResult == MISS_PLATE){
                sMainGameBase15x15.state = PLAYER_SHOT;
            }
        }
        else if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
            if (botMode == ATTACK_MODE){
                printf("\n");
                if ((botAttackResult = mediumLevelBot(&x, &y, map, MAP_SIZE_15_X_15, GAME_PROCESS)) == HIT_PLATE){
                    //Если корабль убит, то продолжаем базовый подбор клетки для атаки, в противном случае активируем режим добивания
                    if (killShipInShipBase(shipBase, x - 1, y - 1) == SHIP_KILLED){
                        putMisses(map, shipBase, x - 1, y - 1, 4);
                    }
                    else {
                        botMode = FINISHING_OFF_MODE;
                    }
                }
                else if (botAttackResult == MISS_PLATE){
                    sMainGameBase15x15.state = PLAYER_SHOT;
                }
                else if (botAttackResult == GAME_END){
                    sMainGameBase15x15.state = PLAYER_SHOT;
                }
            }
            else {
                if ((botAttackResult = finishingOff(x , y, map, shipBase, ATTACK_PROCESS, MAP_SIZE_15_X_15)) == MISS_PLATE){
                    sMainGameBase15x15.state = PLAYER_SHOT;
                }
                else if (botAttackResult == SHIP_KILLED){
                    finishingOff(x , y, map, shipBase, ATTACK_END, MAP_SIZE_15_X_15);
                    putMisses(map, shipBase, x - 1, y - 1, 4);
                    botMode = ATTACK_MODE;
                }
            }
        }
        else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
            if (botMode == ATTACK_MODE){
                if ((botAttackResult = hardLevelBot(&x, &y, map, MAP_SIZE_15_X_15, shipBase, GAME_PROCESS)) == HIT_PLATE){
                    if (killShipInShipBase(shipBase, x - 1, y - 1) == SHIP_KILLED){
                        putMisses(map, shipBase, x - 1, y - 1, 4);
                    }
                    else {
                        botMode = FINISHING_OFF_MODE;
                    }

                }
                else if (botAttackResult == MISS_PLATE){
                    sMainGameBase15x15.state = PLAYER_SHOT;
                }
                else if (botAttackResult == GAME_END){
                    sMainGameBase15x15.state = PLAYER_SHOT;
                }
            }
            else {
                if ((botAttackResult = finishingOff(x , y, map, shipBase, ATTACK_PROCESS, MAP_SIZE_15_X_15)) == MISS_PLATE){
                    sMainGameBase15x15.state = PLAYER_SHOT;
                }
                else if (botAttackResult == SHIP_KILLED){
                    finishingOff(x , y, map, shipBase, ATTACK_END, MAP_SIZE_15_X_15);
                    putMisses(map, shipBase, x - 1, y - 1, 4);
                    botMode = ATTACK_MODE;
                }
            }
        }
        botScore++;
        sleep(BOT_SHOT_DELAY);
        lastBotShotTime = glfwGetTime();
    }
    else if (sMainGameBase15x15.state == FAQ){
        renderSprite(sMainGameBase15x15.FAQPlate, SpriteShaderProgram, FIRST_TEXTURE);
        for (int i = 0, startY = 530; i < FAQMainGame10x10BasicStringCount; i++, startY -= 30){
            renderText(sMainGameBase15x15.TextParams, TextShaderProgram, FAQMainGame10x10Basic[i], correctXcoords(320.0, windowSizeX) , correctYcoords(startY, windowSizeY), correctTextSize(0.6, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

        if (cursorInArea(xMousePos, yMousePos, 490, 620, 791, 545, windowSizeX, windowSizeY)){
            renderText(sMainGameBase15x15.TextParams, TextShaderProgram, "OK", correctXcoords(585.0, windowSizeX) , correctYcoords(112, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                sMainGameBase15x15.state = lastSceneState;
                lastClickTime = glfwGetTime();
            }
        }
        else {
            renderText(sMainGameBase15x15.TextParams, TextShaderProgram, "OK", correctXcoords(585.0, windowSizeX) , correctYcoords(112, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }    
        
    }
    else if (sMainGameBase15x15.state == GAME_END){
        if (whoWin == BOT_WIN){
            renderSprite(sMainGameBase15x15.lostPlate, SpriteShaderProgram, FIRST_TEXTURE);
            snprintf(botScoreStr, 4, "%d", botScore);
            renderText(sMainGameBase15x15.TextParams, TextShaderProgram, botScoreStr, correctXcoords(705.0, windowSizeX) , correctYcoords(348, windowSizeY), correctTextSize(0.7, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);

            if (cursorInArea(xMousePos, yMousePos, 442, 491, 831, 408, windowSizeX, windowSizeY)){
                renderText(sMainGameBase15x15.TextParams, TextShaderProgram, "Back To Menu", correctXcoords(475.0, windowSizeX) , correctYcoords(256, windowSizeY), correctTextSize(1.2, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
                if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                    if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
                        mediumLevelBot(&x, &y, mapBot, MAP_SIZE_15_X_15, GAME_END);
                    }
                    else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
                        hardLevelBot(&x, &y, mapBot, MAP_SIZE_15_X_15, botShipBase, GAME_END);
                    }

                    playerInfo.BotLevel = NOT_FILLED_IN;
                    playerInfo.GameMode = NOT_FILLED_IN;
                    playerInfo.MapSize = NOT_FILLED_IN;
                    playerInfo.scene = MAIN_MENU_SCENES;
                    botMode = ATTACK_MODE;

                    if (shipBase != NULL){
                        freeShipBase(shipBase);
                        shipBase = NULL;
                    }
                    if (botShipBase != NULL){
                        freeShipBase(botShipBase);
                        botShipBase = NULL;
                    }
                    
                    playerScore = 0;
                    botScore = 0;

                    clearMap(map);
                    clearMap(mapBot);

                    lastClickTime = glfwGetTime();
                }
            }
            else {
                renderText(sMainGameBase15x15.TextParams, TextShaderProgram, "Back To Menu", correctXcoords(475.0, windowSizeX) , correctYcoords(256, windowSizeY), correctTextSize(1.2, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);       
            }  
        } 
        else if (whoWin == PLAYER_WIN){
            //Обработка победы Игрока
            renderSprite(sMainGameBase15x15.wonPlate, SpriteShaderProgram, FIRST_TEXTURE);
            snprintf(botScoreStr, 4, "%d", playerScore);
            renderText(sMainGameBase15x15.TextParams, TextShaderProgram, botScoreStr, correctXcoords(665.0, windowSizeX) , correctYcoords(411, windowSizeY), correctTextSize(0.7, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);

            //Если игрок не захотел добавлять имя на доску лидеров, то просто выход в главное меню
            if (cursorInArea(xMousePos, yMousePos, 428, 536, 859, 452, windowSizeX, windowSizeY)){
                renderText(sMainGameBase15x15.TextParams, TextShaderProgram, "Back To Menu", correctXcoords(478.0, windowSizeX) , correctYcoords(213, windowSizeY), correctTextSize(1.2, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
                if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                    if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
                        mediumLevelBot(&x, &y, mapBot, MAP_SIZE_15_X_15, GAME_END);
                    }
                    else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
                        hardLevelBot(&x, &y, mapBot, MAP_SIZE_15_X_15, botShipBase, GAME_END);
                    }

                    playerInfo.BotLevel = NOT_FILLED_IN;
                    playerInfo.GameMode = NOT_FILLED_IN;
                    playerInfo.MapSize = NOT_FILLED_IN;
                    playerInfo.scene = MAIN_MENU_SCENES;
                    botMode = ATTACK_MODE;

                    if (shipBase != NULL){
                        freeShipBase(shipBase);
                        shipBase = NULL;
                    }
                    if (botShipBase != NULL){
                        freeShipBase(botShipBase);
                        botShipBase = NULL;
                    }
                    
                    playerScore = 0;
                    botScore = 0;

                    clearMap(map);
                    clearMap(mapBot);

                    lastClickTime = glfwGetTime();
                }
            }
            else {
                renderText(sMainGameBase15x15.TextParams, TextShaderProgram, "Back To Menu", correctXcoords(478.0, windowSizeX) , correctYcoords(213, windowSizeY), correctTextSize(1.2, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);       
            } 

            //Обработка кнопки добавления на доску лидеров
            if (cursorInArea(xMousePos, yMousePos, 431, 429, 856, 342, windowSizeX, windowSizeY)){
                renderText(sMainGameBase15x15.TextParams, TextShaderProgram, "Add To LeaderBoard", correctXcoords(468.0, windowSizeX) , correctYcoords(325, windowSizeY), correctTextSize(0.9, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
                if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                    if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
                        mediumLevelBot(&x, &y, mapBot, MAP_SIZE_15_X_15, GAME_END);
                    }
                    else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
                        hardLevelBot(&x, &y, mapBot, MAP_SIZE_15_X_15, botShipBase, GAME_END);
                    }
                    
                    playerInfo.scene = ADDING_TO_THE_LEADERBOARD_SCENES;

                    if (shipBase != NULL){
                        freeShipBase(shipBase);
                        shipBase = NULL;
                    }
                    if (botShipBase != NULL){
                        freeShipBase(botShipBase);
                        botShipBase = NULL;
                    }

                    botScore = 0;

                    clearMap(map);
                    clearMap(mapBot);

                    lastClickTime = glfwGetTime();
                }
            }
            else {
                renderText(sMainGameBase15x15.TextParams, TextShaderProgram, "Add To LeaderBoard", correctXcoords(468.0, windowSizeX) , correctYcoords(325, windowSizeY), correctTextSize(0.9, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);       
            } 
        }
    }
    else if (sMainGameBase15x15.state == EXIT_QUESTION){
        renderSprite(sMainGameBase15x15.exitQuestion, SpriteShaderProgram, FIRST_TEXTURE);

        //Обработка кнопки YES
        if (cursorInArea(xMousePos, yMousePos, 325, 458, 589, 362, windowSizeX, windowSizeY)){
            renderText(sMainGameBase15x15.TextParams, TextShaderProgram, "YES" , correctXcoords(389.0, windowSizeX) , correctYcoords(290.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                playerInfo.scene = SAVING_GAME_SCENES;
                sMainGameBase15x15.state = lastSceneState;
                lastClickTime = glfwGetTime();
            }
        }
        else {
            renderText(sMainGameBase15x15.TextParams, TextShaderProgram, "YES" , correctXcoords(389.0, windowSizeX) , correctYcoords(290.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        } 

        //Обработка кнопки NO
        if (cursorInArea(xMousePos, yMousePos, 685, 458, 952, 362, windowSizeX, windowSizeY)){
            renderText(sMainGameBase15x15.TextParams, TextShaderProgram, "NO" , correctXcoords(775.0, windowSizeX) , correctYcoords(290.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
                    mediumLevelBot(&x, &y, mapBot, MAP_SIZE_15_X_15, GAME_END);
                }
                else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
                    hardLevelBot(&x, &y, mapBot, MAP_SIZE_15_X_15, botShipBase, GAME_END);
                }

                playerInfo.BotLevel = NOT_FILLED_IN;
                playerInfo.GameMode = NOT_FILLED_IN;
                playerInfo.MapSize = NOT_FILLED_IN;
                playerInfo.scene = MAIN_MENU_SCENES;
                botMode = ATTACK_MODE;

                if (shipBase != NULL){
                    freeShipBase(shipBase);
                    shipBase = NULL;
                }
                if (botShipBase != NULL){
                    freeShipBase(botShipBase);
                    botShipBase = NULL;
                }
                
                playerScore = 0;
                botScore = 0;

                clearMap(map);
                clearMap(mapBot);

                lastClickTime = glfwGetTime();
            }
        }
        else {
            renderText(sMainGameBase15x15.TextParams, TextShaderProgram, "NO" , correctXcoords(775.0, windowSizeX) , correctYcoords(290.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }
        
    }

    
    BotShipsLeft = getShipsLeft(botShipBase);
    snprintf(shipsLeftStr, 3, "%d", BotShipsLeft);
    renderText(sMainGameBase15x15.TextParams, TextShaderProgram, shipsLeftStr, correctXcoords(907.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    
    memset(shipsLeftStr, '\0', 3);

    PlayerShipsLeft = getShipsLeft(shipBase);
    snprintf(shipsLeftStr, 3, "%d", PlayerShipsLeft);
    renderText(sMainGameBase15x15.TextParams, TextShaderProgram, shipsLeftStr, correctXcoords(274.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);

    //Если у кого-то из игроков не осталось кораблей, значит игра закончилась
    if ((PlayerShipsLeft == 0 || BotShipsLeft == 0) && sMainGameBase15x15.state != FAQ){
        sMainGameBase15x15.state = GAME_END;
        if (PlayerShipsLeft == 0){
            whoWin = BOT_WIN;
        }
        else if (BotShipsLeft == 0){
            whoWin = PLAYER_WIN;
        }
    }

    //Отображение того, чей выстрел ожидается в данный момент
    if (sMainGameBase15x15.state == PLAYER_SHOT || (sMainGameBase15x15.state == FAQ && lastSceneState == PLAYER_SHOT) || (sMainGameBase15x15.state == EXIT_QUESTION && lastSceneState == PLAYER_SHOT)){
        renderText(sMainGameBase15x15.TextParams, TextShaderProgram, "YOUR SHOT" , correctXcoords(442.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }
    else if (sMainGameBase15x15.state == BOT_SHOT || (sMainGameBase15x15.state == FAQ && lastSceneState == BOT_SHOT) || (sMainGameBase15x15.state == EXIT_QUESTION && lastSceneState == BOT_SHOT)){
        renderText(sMainGameBase15x15.TextParams, TextShaderProgram, "ENEMY SHOT" , correctXcoords(430.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }
    else if (sMainGameBase15x15.state == GAME_END || (sMainGameBase15x15.state == FAQ && lastSceneState == GAME_END) || (sMainGameBase15x15.state == EXIT_QUESTION && lastSceneState == GAME_END)){
        renderText(sMainGameBase15x15.TextParams, TextShaderProgram, "GAME END" , correctXcoords(446.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    //Обработка FAQ
    if (cursorInArea(xMousePos, yMousePos, 1108, 70, 1169, 24, windowSizeX, windowSizeY) && sMainGameBase15x15.state != FAQ){
        renderSprite(sMainGameBase15x15.QuestionMarkBtn, SpriteShaderProgram, SECOND_TEXTURE);
         if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            lastSceneState = sMainGameBase15x15.state;
            sMainGameBase15x15.state = FAQ;
            lastClickTime = glfwGetTime();
        }
    }
    else {
        renderSprite(sMainGameBase15x15.QuestionMarkBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }    

    //Обработка кнопки Exit
    if (cursorInArea(xMousePos, yMousePos, 1196, 73, 1260, 20, windowSizeX, windowSizeY) && sMainGameBase15x15.state != FAQ){
        renderSprite(sMainGameBase15x15.ExitBtn, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            if (sMainGameBase15x15.state == EXIT_QUESTION){
                sMainGameBase15x15.state = lastSceneState;
            }
            else {
                lastSceneState = sMainGameBase15x15.state;
                sMainGameBase15x15.state = EXIT_QUESTION;
            }

            lastClickTime = glfwGetTime();
        }
    }
    else {
        renderSprite(sMainGameBase15x15.ExitBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }
}


void renderMainGameBotFight10x10(GLFWwindow* window)
{
    extern GLuint SpriteShaderProgram;
    extern GLuint TextShaderProgram;
    extern MainGameBotFight10x10 sMainGameBotFight10x10;
    extern Player playerInfo;
    extern ShipBase* shipBaseBFBot1;
    extern ShipBase* shipBaseBFBot2;
    

    extern int mapBot1[18][18];
    extern int mapBot2[18][18];

    extern int windowSizeX;
    extern int windowSizeY;

    extern double lastClickTime;

    extern char FAQMainGameBotFight [2][MAX_STRING_SIZE];
    extern const int FAQMainGameBotFightStringCount;

    extern int bot1Score;
    extern int bot2Score; 

    double xMousePos,
           yMousePos;

    int Bot1ShipsLeft,
        Bot2ShipsLeft;

    static int xb1, yb1, xb2, yb2;
    static int lastSceneStateBot1 = 0,
               lastSceneStateBot2 = 0;
    
    int botAttackResult;

    static int lastSceneState = 0;

    extern int botMode1;
    extern int botMode2;

    char shipsLeftStr[3] = {'\0',};
    char botScoreStr[6] = {'\0',};

    static int whoWin = 0;

    static int lastBotShotTime = 0;

    glfwGetCursorPos(window, &xMousePos, &yMousePos);
    printf("%.2lf  %.2lf    ", xMousePos, yMousePos);
    printf("Window size: %dx%d\n", windowSizeX, windowSizeY);

    renderSprite(sMainGameBotFight10x10.Background, SpriteShaderProgram, FIRST_TEXTURE);
    renderSprite(sMainGameBotFight10x10.ButtonPlates, SpriteShaderProgram, FIRST_TEXTURE);

    //Отображение поля
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (mapBot1[i + 1][j + 1] == SHIP_PLATE)
                renderSprite(sMainGameBotFight10x10.Bot1MapArray[i][j].sprite, SpriteShaderProgram, FIRST_TEXTURE);
            else if (mapBot1[i + 1][j + 1] == HIT_PLATE){
                renderSprite(sMainGameBotFight10x10.Bot1MapArray[i][j].sprite, SpriteShaderProgram, SECOND_TEXTURE);
            }
            else if (mapBot1[i + 1][j + 1] == MISS_PLATE){
                renderSprite(sMainGameBotFight10x10.Bot1MapArray[i][j].sprite, SpriteShaderProgram, THIRD_TEXTURE);
            }

            if (mapBot2[i + 1][j + 1] == SHIP_PLATE)
                renderSprite(sMainGameBotFight10x10.Bot2MapArray[i][j].sprite, SpriteShaderProgram, FIRST_TEXTURE);
            else if (mapBot2[i + 1][j + 1] == HIT_PLATE){
                renderSprite(sMainGameBotFight10x10.Bot2MapArray[i][j].sprite, SpriteShaderProgram, SECOND_TEXTURE);
            }
            else if (mapBot2[i + 1][j + 1] == MISS_PLATE){
                renderSprite(sMainGameBotFight10x10.Bot2MapArray[i][j].sprite, SpriteShaderProgram, THIRD_TEXTURE);
            }
        }
    }

    renderSprite(sMainGameBotFight10x10.MainMap10x10, SpriteShaderProgram, FIRST_TEXTURE);

    //0 - пустая клетка
    //1 - промах
    //2 - корабль
    //3 - подбитый корабль
    
    if (sMainGameBotFight10x10.state == BOT_1_SHOT && glfwGetTime() - lastBotShotTime  >= BOT_BF_DELAY){
        //Обработка выстрела бота
        for (int i = 0; i < 10000000; i++);

        if (playerInfo.BotLevel == EASY_BOT_LEVEL){
            if ((botAttackResult = easyLevelBot(&xb1, &yb1, mapBot2, MAP_SIZE_10_X_10)) == HIT_PLATE){
                killShipInShipBase(shipBaseBFBot2, xb1 - 1, yb1 - 1);
            }
            else if (botAttackResult == MISS_PLATE){
                sMainGameBotFight10x10.state = BOT_2_SHOT;
            }
        }
        else if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
            if ((botAttackResult = mediumLevelBotBF(&xb1, &yb1, mapBot2, MAP_SIZE_10_X_10, BOT_1_SHOT, GAME_PROCESS)) == HIT_PLATE){
                //Если корабль убит, то продолжаем базовый подбор клетки для атаки, в противном случае активируем режим добивания
                if (killShipInShipBase(shipBaseBFBot2, xb1 - 1, yb1 - 1) == SHIP_KILLED){
                    putMisses(mapBot2, shipBaseBFBot2, xb1 - 1, yb1 - 1, 1);
                }
            }
            else if (botAttackResult == MISS_PLATE){
                sMainGameBotFight10x10.state = BOT_2_SHOT;
            } 
        }
        else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
            if (botMode1 == ATTACK_MODE){
                if ((botAttackResult = hardLevelBotBF(&xb1, &yb1, mapBot2, MAP_SIZE_10_X_10, shipBaseBFBot2, BOT_1_SHOT, GAME_PROCESS)) == HIT_PLATE){
                    if (killShipInShipBase(shipBaseBFBot2, xb1 - 1, yb1 - 1) == SHIP_KILLED){
                        putMisses(mapBot2, shipBaseBFBot2, xb1 - 1, yb1 - 1, 1);
                    }
                    else {
                        botMode1 = FINISHING_OFF_MODE;
                    }

                }
                else if (botAttackResult == MISS_PLATE){
                    sMainGameBotFight10x10.state = BOT_2_SHOT;
                }
            }
            else {
                if ((botAttackResult = finishingOffBF(xb1 , yb1, mapBot2, shipBaseBFBot2, ATTACK_PROCESS, MAP_SIZE_10_X_10, BOT_1_SHOT)) == MISS_PLATE){
                    sMainGameBotFight10x10.state = BOT_2_SHOT;
                    printf("bot1 %d %d\n", xb1, yb1);
                }
                else if (botAttackResult == SHIP_KILLED){
                    finishingOffBF(xb1 , yb1, mapBot2, shipBaseBFBot2, ATTACK_END, MAP_SIZE_10_X_10, BOT_1_SHOT);
                    putMisses(mapBot2, shipBaseBFBot2, xb1 - 1, yb1 - 1, 1);
                    botMode1 = ATTACK_MODE;
                }
            }
        }
        bot1Score++;
        lastBotShotTime = glfwGetTime();
        sleep(BOT_SHOT_DELAY);
    }
    else if (sMainGameBotFight10x10.state == BOT_2_SHOT && glfwGetTime() - lastBotShotTime >= BOT_BF_DELAY) {
        if (playerInfo.BotLevel == EASY_BOT_LEVEL){
            if ((botAttackResult = easyLevelBot(&xb2, &yb2, mapBot1, MAP_SIZE_10_X_10)) == HIT_PLATE){
                killShipInShipBase(shipBaseBFBot1, xb2 - 1, yb2 - 1);
            }
            else if (botAttackResult == MISS_PLATE){
                sMainGameBotFight10x10.state = BOT_1_SHOT;
            }
        }
        else if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
            if ((botAttackResult = mediumLevelBotBF(&xb2, &yb2, mapBot1, MAP_SIZE_10_X_10, BOT_2_SHOT, GAME_PROCESS)) == HIT_PLATE){
                //Если корабль убит, то продолжаем базовый подбор клетки для атаки, в противном случае активируем режим добивания
                if (killShipInShipBase(shipBaseBFBot1, xb2 - 1, yb2 - 1) == SHIP_KILLED){
                    putMisses(mapBot1, shipBaseBFBot1, xb2 - 1, yb2 - 1, 1);
                }
            }
            else if (botAttackResult == MISS_PLATE){
                sMainGameBotFight10x10.state = BOT_1_SHOT;
            }  
        }
        else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
            if (botMode2 == ATTACK_MODE){
                if ((botAttackResult = hardLevelBotBF(&xb2, &yb2, mapBot1, MAP_SIZE_10_X_10, shipBaseBFBot1, BOT_2_SHOT, GAME_PROCESS)) == HIT_PLATE){
                    if (killShipInShipBase(shipBaseBFBot1, xb2 - 1, yb2 - 1) == SHIP_KILLED){
                        putMisses(mapBot1, shipBaseBFBot1, xb2 - 1, yb2 - 1, 1);
                    }
                    else {
                        botMode2 = FINISHING_OFF_MODE;
                    }

                }
                else if (botAttackResult == MISS_PLATE){
                    sMainGameBotFight10x10.state = BOT_1_SHOT;
                }
            }
            else {
                if ((botAttackResult = finishingOffBF(xb2 , yb2, mapBot1, shipBaseBFBot1, ATTACK_PROCESS, MAP_SIZE_10_X_10, BOT_2_SHOT)) == MISS_PLATE){
                    sMainGameBotFight10x10.state = BOT_1_SHOT;
                }
                else if (botAttackResult == SHIP_KILLED){
                    finishingOffBF(xb2 , yb2, mapBot1, shipBaseBFBot1, ATTACK_END, MAP_SIZE_10_X_10, BOT_2_SHOT);
                    putMisses(mapBot1, shipBaseBFBot1, xb2 - 1, yb2 - 1, 1);
                    botMode2 = ATTACK_MODE;
                }
            }
        }
        bot2Score++;
        lastBotShotTime = glfwGetTime();
        sleep(BOT_SHOT_DELAY);
    }
    else if (sMainGameBotFight10x10.state == FAQ){
        renderSprite(sMainGameBotFight10x10.FAQPlate, SpriteShaderProgram, FIRST_TEXTURE);
        for (int i = 0, startY = 530; i < FAQMainGameBotFightStringCount; i++, startY -= 30){
            renderText(sMainGameBotFight10x10.TextParams, TextShaderProgram, FAQMainGameBotFight[i], correctXcoords(320.0, windowSizeX) , correctYcoords(startY, windowSizeY), correctTextSize(0.6, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

        if (cursorInArea(xMousePos, yMousePos, 490, 620, 791, 545, windowSizeX, windowSizeY)){
            renderText(sMainGameBotFight10x10.TextParams, TextShaderProgram, "OK", correctXcoords(585.0, windowSizeX) , correctYcoords(112, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                sMainGameBotFight10x10.state = lastSceneState;
                lastClickTime = glfwGetTime();
            }
        }
        else {
            renderText(sMainGameBotFight10x10.TextParams, TextShaderProgram, "OK", correctXcoords(585.0, windowSizeX) , correctYcoords(112, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }    
        
    }
    else if (sMainGameBotFight10x10.state == GAME_END){
        renderSprite(sMainGameBotFight10x10.botWinPlate, SpriteShaderProgram, FIRST_TEXTURE);
        if (whoWin == 2){
            renderText(sMainGameBotFight10x10.TextParams, TextShaderProgram, "2", correctXcoords(695.0, windowSizeX) , correctYcoords(454, windowSizeY), correctTextSize(1.65, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
            snprintf(botScoreStr, 4, "%d", bot2Score);
            renderText(sMainGameBotFight10x10.TextParams, TextShaderProgram, botScoreStr, correctXcoords(655.0, windowSizeX) , correctYcoords(349, windowSizeY), correctTextSize(0.6, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);

        }
        if (whoWin == 1){
            renderText(sMainGameBotFight10x10.TextParams, TextShaderProgram, "1", correctXcoords(695.0, windowSizeX) , correctYcoords(454, windowSizeY), correctTextSize(1.65, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
            snprintf(botScoreStr, 4, "%d", bot2Score);
            renderText(sMainGameBotFight10x10.TextParams, TextShaderProgram, botScoreStr, correctXcoords(655.0, windowSizeX) , correctYcoords(349, windowSizeY), correctTextSize(0.6, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }
        
        if (cursorInArea(xMousePos, yMousePos, 442, 491, 831, 408, windowSizeX, windowSizeY)){
            renderText(sMainGameBotFight10x10.TextParams, TextShaderProgram, "Back To Menu", correctXcoords(475.0, windowSizeX) , correctYcoords(256, windowSizeY), correctTextSize(1.2, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
                    mediumLevelBotBF(&xb1, &yb1, mapBot1, MAP_SIZE_10_X_10, BOT_1_SHOT, GAME_END);
                    mediumLevelBotBF(&xb2, &yb2, mapBot1, MAP_SIZE_10_X_10, BOT_2_SHOT, GAME_END);
                }
                else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
                    hardLevelBotBF(&xb1, &yb1, mapBot1, MAP_SIZE_10_X_10, shipBaseBFBot1, BOT_1_SHOT, GAME_END);
                    hardLevelBotBF(&xb2, &yb2, mapBot1, MAP_SIZE_10_X_10, shipBaseBFBot2, BOT_2_SHOT, GAME_END);
                }

                playerInfo.BotLevel = NOT_FILLED_IN;
                playerInfo.GameMode = NOT_FILLED_IN;
                playerInfo.MapSize = NOT_FILLED_IN;
                playerInfo.scene = MAIN_MENU_SCENES;
                botMode1 = ATTACK_MODE;
                botMode2 = ATTACK_MODE;

                if (shipBaseBFBot1 != NULL){
                    freeShipBase(shipBaseBFBot1);
                    shipBaseBFBot1 = NULL;
                }
                if (shipBaseBFBot2 != NULL){
                    freeShipBase(shipBaseBFBot2);
                    shipBaseBFBot2= NULL;
                }
                
                bot1Score = 0;
                bot2Score = 0;

                clearMap(mapBot1);
                clearMap(mapBot2);

                lastClickTime = glfwGetTime();
            }
        }
        else {
            renderText(sMainGameBotFight10x10.TextParams, TextShaderProgram, "Back To Menu", correctXcoords(475.0, windowSizeX) , correctYcoords(256, windowSizeY), correctTextSize(1.2, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);       
        }    
    }
    else if (sMainGameBotFight10x10.state == EXIT_QUESTION){
        renderSprite(sMainGameBotFight10x10.exitQuestion, SpriteShaderProgram, FIRST_TEXTURE);

        //Обработка кнопки YES
        if (cursorInArea(xMousePos, yMousePos, 325, 458, 589, 362, windowSizeX, windowSizeY)){
            renderText(sMainGameBotFight10x10.TextParams, TextShaderProgram, "YES" , correctXcoords(389.0, windowSizeX) , correctYcoords(290.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                playerInfo.scene = SAVING_GAME_SCENES;
                sMainGameBotFight10x10.state = lastSceneState;
                lastClickTime = glfwGetTime();
            }
        }
        else {
            renderText(sMainGameBotFight10x10.TextParams, TextShaderProgram, "YES" , correctXcoords(389.0, windowSizeX) , correctYcoords(290.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        } 

        //Обработка кнопки NO
        if (cursorInArea(xMousePos, yMousePos, 685, 458, 952, 362, windowSizeX, windowSizeY)){
            renderText(sMainGameBotFight10x10.TextParams, TextShaderProgram, "NO" , correctXcoords(775.0, windowSizeX) , correctYcoords(290.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
                    mediumLevelBotBF(&xb1, &yb1, mapBot1, MAP_SIZE_10_X_10, BOT_1_SHOT, GAME_END);
                    mediumLevelBotBF(&xb2, &yb2, mapBot1, MAP_SIZE_10_X_10, BOT_2_SHOT, GAME_END);
                }
                else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
                    hardLevelBotBF(&xb1, &yb1, mapBot1, MAP_SIZE_10_X_10, shipBaseBFBot1, BOT_1_SHOT, GAME_END);
                    hardLevelBotBF(&xb2, &yb2, mapBot1, MAP_SIZE_10_X_10, shipBaseBFBot2, BOT_2_SHOT, GAME_END);
                }

                playerInfo.BotLevel = NOT_FILLED_IN;
                playerInfo.GameMode = NOT_FILLED_IN;
                playerInfo.MapSize = NOT_FILLED_IN;
                playerInfo.scene = MAIN_MENU_SCENES;
                botMode1 = ATTACK_MODE;
                botMode2 = ATTACK_MODE;

                if (shipBaseBFBot1 != NULL){
                    freeShipBase(shipBaseBFBot1);
                    shipBaseBFBot1 = NULL;
                }
                if (shipBaseBFBot2 != NULL){
                    freeShipBase(shipBaseBFBot2);
                    shipBaseBFBot2= NULL;
                }
                
                bot1Score = 0;
                bot2Score = 0;

                clearMap(mapBot1);
                clearMap(mapBot2);

                lastClickTime = glfwGetTime();
            }
        }
        else {
            renderText(sMainGameBotFight10x10.TextParams, TextShaderProgram, "NO" , correctXcoords(775.0, windowSizeX) , correctYcoords(290.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }
        
    }


    Bot2ShipsLeft = getShipsLeft(shipBaseBFBot2);
    snprintf(shipsLeftStr, 3, "%d", Bot2ShipsLeft);
    renderText(sMainGameBotFight10x10.TextParams, TextShaderProgram, shipsLeftStr, correctXcoords(920.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    
    memset(shipsLeftStr, '\0', 3);

    Bot1ShipsLeft = getShipsLeft(shipBaseBFBot1);
    snprintf(shipsLeftStr, 3, "%d", Bot1ShipsLeft);
    renderText(sMainGameBotFight10x10.TextParams, TextShaderProgram, shipsLeftStr, correctXcoords(265.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);

    //Если у кого-то из игроков не осталось кораблей, значит игра закончилась
    if ((Bot1ShipsLeft == 0 || Bot2ShipsLeft == 0) && sMainGameBotFight10x10.state != FAQ){
        sMainGameBotFight10x10.state = GAME_END;
        if (Bot1ShipsLeft != 0) whoWin = 1;
        if (Bot2ShipsLeft != 0) whoWin = 2; 
    }


    //Отображение того, чей выстрел ожидается в данный момент
    if (sMainGameBotFight10x10.state == BOT_1_SHOT || (sMainGameBotFight10x10.state == FAQ && lastSceneState == BOT_1_SHOT) || (sMainGameBotFight10x10.state == EXIT_QUESTION && lastSceneState == BOT_1_SHOT)){
        renderText(sMainGameBotFight10x10.TextParams, TextShaderProgram, "BOT 1 SHOT" , correctXcoords(442.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }
    else if (sMainGameBotFight10x10.state == BOT_2_SHOT || (sMainGameBotFight10x10.state == FAQ && lastSceneState == BOT_2_SHOT) || (sMainGameBotFight10x10.state == EXIT_QUESTION && lastSceneState == BOT_2_SHOT)){
        renderText(sMainGameBotFight10x10.TextParams, TextShaderProgram, "BOT 2 SHOT" , correctXcoords(442.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }
    else if (sMainGameBotFight10x10.state == GAME_END || (sMainGameBotFight10x10.state == FAQ && lastSceneState == GAME_END) || (sMainGameBotFight10x10.state == EXIT_QUESTION && lastSceneState == GAME_END)){
        renderText(sMainGameBotFight10x10.TextParams, TextShaderProgram, "GAME END" , correctXcoords(446.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    //Обработка FAQ
    if (cursorInArea(xMousePos, yMousePos, 1108, 70, 1169, 24, windowSizeX, windowSizeY) && sMainGameBotFight10x10.state != FAQ){
        renderSprite(sMainGameBotFight10x10.QuestionMarkBtn, SpriteShaderProgram, SECOND_TEXTURE);
         if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            lastSceneState = sMainGameBotFight10x10.state;
            sMainGameBotFight10x10.state = FAQ;
            lastClickTime = glfwGetTime();
        }
    }
    else {
        renderSprite(sMainGameBotFight10x10.QuestionMarkBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }    

    //Обработка кнопки Exit
    if (cursorInArea(xMousePos, yMousePos, 1196, 73, 1260, 20, windowSizeX, windowSizeY) && sMainGameBotFight10x10.state != FAQ){
        renderSprite(sMainGameBotFight10x10.ExitBtn, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            if (sMainGameBotFight10x10.state == EXIT_QUESTION){
                sMainGameBotFight10x10.state = lastSceneState;
            }
            else {
                lastSceneState = sMainGameBotFight10x10.state;
                sMainGameBotFight10x10.state = EXIT_QUESTION;
            }

            lastClickTime = glfwGetTime();
        }
    }
    else {
        renderSprite(sMainGameBotFight10x10.ExitBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }
    
}


void renderMainGameBotFight15x15(GLFWwindow* window)
{
    extern GLuint SpriteShaderProgram;
    extern GLuint TextShaderProgram;
    extern MainGameBotFight15x15 sMainGameBotFight15x15;
    extern Player playerInfo;
    extern ShipBase* shipBaseBFBot1;
    extern ShipBase* shipBaseBFBot2;
    

    extern int mapBot1[18][18];
    extern int mapBot2[18][18];

    extern int windowSizeX;
    extern int windowSizeY;

    extern double lastClickTime;

    extern char FAQMainGameBotFight [2][MAX_STRING_SIZE];
    extern const int FAQMainGameBotFightStringCount;

    extern int bot1Score;
    extern int bot2Score;

    double xMousePos,
           yMousePos;

    int Bot1ShipsLeft,
        Bot2ShipsLeft;

    static int xb1, yb1, xb2, yb2;
    static int lastSceneStateBot1 = 0,
               lastSceneStateBot2 = 0;
    
    int botAttackResult;

    static int lastSceneState = 0;

    extern int botMode1;
    extern int botMode2;

    static int whoWin = 0;

    char shipsLeftStr[3] = {'\0',};
    char botScoreStr[5] = {'\0'};

    static double lastBotShotTime = 0;

    glfwGetCursorPos(window, &xMousePos, &yMousePos);
    //printf("%.2lf  %.2lf    ", xMousePos, yMousePos);
    //printf("Window size: %dx%d\n", windowSizeX, windowSizeY);

    renderSprite(sMainGameBotFight15x15.Background, SpriteShaderProgram, FIRST_TEXTURE);
    renderSprite(sMainGameBotFight15x15.ButtonPlates, SpriteShaderProgram, FIRST_TEXTURE);

    //Отображение поля
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            if (mapBot1[i + 1][j + 1] == SHIP_PLATE)
                renderSprite(sMainGameBotFight15x15.Bot1MapArray[i][j].sprite, SpriteShaderProgram, FIRST_TEXTURE);
            else if (mapBot1[i + 1][j + 1] == HIT_PLATE){
                renderSprite(sMainGameBotFight15x15.Bot1MapArray[i][j].sprite, SpriteShaderProgram, SECOND_TEXTURE);
            }
            else if (mapBot1[i + 1][j + 1] == MISS_PLATE){
                renderSprite(sMainGameBotFight15x15.Bot1MapArray[i][j].sprite, SpriteShaderProgram, THIRD_TEXTURE);
            }

            if (mapBot2[i + 1][j + 1] == SHIP_PLATE)
                renderSprite(sMainGameBotFight15x15.Bot2MapArray[i][j].sprite, SpriteShaderProgram, FIRST_TEXTURE);
            else if (mapBot2[i + 1][j + 1] == HIT_PLATE){
                renderSprite(sMainGameBotFight15x15.Bot2MapArray[i][j].sprite, SpriteShaderProgram, SECOND_TEXTURE);
            }
            else if (mapBot2[i + 1][j + 1] == MISS_PLATE){
                renderSprite(sMainGameBotFight15x15.Bot2MapArray[i][j].sprite, SpriteShaderProgram, THIRD_TEXTURE);
            }
        }
    }

    renderSprite(sMainGameBotFight15x15.MainMap15x15, SpriteShaderProgram, FIRST_TEXTURE);

    //0 - пустая клетка
    //1 - промах
    //2 - корабль
    //3 - подбитый корабль
    
    if (sMainGameBotFight15x15.state == BOT_1_SHOT && glfwGetTime() - lastBotShotTime >= BOT_BF_DELAY){
        //Обработка выстрела бота
        for (int i = 0; i < 10000000; i++);

        if (playerInfo.BotLevel == EASY_BOT_LEVEL){
            if ((botAttackResult = easyLevelBot(&xb1, &yb1, mapBot2, MAP_SIZE_15_X_15)) == HIT_PLATE){
                killShipInShipBase(shipBaseBFBot2, xb1 - 1, yb1 - 1);
            }
            else if (botAttackResult == MISS_PLATE){
                sMainGameBotFight15x15.state = BOT_2_SHOT;
            }
        }
        else if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
            if ((botAttackResult = mediumLevelBotBF(&xb1, &yb1, mapBot2, MAP_SIZE_15_X_15, BOT_1_SHOT, GAME_PROCESS)) == HIT_PLATE){
                //Если корабль убит, то продолжаем базовый подбор клетки для атаки, в противном случае активируем режим добивания
                if (killShipInShipBase(shipBaseBFBot2, xb1 - 1, yb1 - 1) == SHIP_KILLED){
                    putMisses(mapBot2, shipBaseBFBot2, xb1 - 1, yb1 - 1, 1);
                }
            }
            else if (botAttackResult == MISS_PLATE){
                sMainGameBotFight15x15.state = BOT_2_SHOT;
            } 
        }
        else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
            if (botMode1 == ATTACK_MODE){
                if ((botAttackResult = hardLevelBotBF(&xb1, &yb1, mapBot2, MAP_SIZE_15_X_15, shipBaseBFBot2, BOT_1_SHOT, GAME_PROCESS)) == HIT_PLATE){
                    if (killShipInShipBase(shipBaseBFBot2, xb1 - 1, yb1 - 1) == SHIP_KILLED){
                        putMisses(mapBot2, shipBaseBFBot2, xb1 - 1, yb1 - 1, 1);
                    }
                    else {
                        botMode1 = FINISHING_OFF_MODE;
                    }

                }
                else if (botAttackResult == MISS_PLATE){
                    sMainGameBotFight15x15.state = BOT_2_SHOT;
                }
            }
            else {
                if ((botAttackResult = finishingOffBF(xb1 , yb1, mapBot2, shipBaseBFBot2, ATTACK_PROCESS, MAP_SIZE_15_X_15, BOT_1_SHOT)) == MISS_PLATE){
                    sMainGameBotFight15x15.state = BOT_2_SHOT;
                    printf("bot1 %d %d\n", xb1, yb1);
                }
                else if (botAttackResult == SHIP_KILLED){
                    finishingOffBF(xb1 , yb1, mapBot2, shipBaseBFBot2, ATTACK_END, MAP_SIZE_15_X_15, BOT_1_SHOT);
                    putMisses(mapBot2, shipBaseBFBot2, xb1 - 1, yb1 - 1, 1);
                    botMode1 = ATTACK_MODE;
                }
            }
        }
        bot1Score++;
        lastBotShotTime = glfwGetTime();
        sleep(BOT_SHOT_DELAY);
    }
    else if (sMainGameBotFight15x15.state == BOT_2_SHOT && glfwGetTime() - lastBotShotTime >= BOT_BF_DELAY) {
        if (playerInfo.BotLevel == EASY_BOT_LEVEL){
            if ((botAttackResult = easyLevelBot(&xb2, &yb2, mapBot1, MAP_SIZE_15_X_15)) == HIT_PLATE){
                killShipInShipBase(shipBaseBFBot1, xb2 - 1, yb2 - 1);
            }
            else if (botAttackResult == MISS_PLATE){
                sMainGameBotFight15x15.state = BOT_1_SHOT;
            }
        }
        else if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
            if ((botAttackResult = mediumLevelBotBF(&xb2, &yb2, mapBot1, MAP_SIZE_15_X_15, BOT_2_SHOT, GAME_PROCESS)) == HIT_PLATE){
                //Если корабль убит, то продолжаем базовый подбор клетки для атаки, в противном случае активируем режим добивания
                if (killShipInShipBase(shipBaseBFBot1, xb2 - 1, yb2 - 1) == SHIP_KILLED){
                    putMisses(mapBot1, shipBaseBFBot1, xb2 - 1, yb2 - 1, 1);
                }
            }
            else if (botAttackResult == MISS_PLATE){
                sMainGameBotFight15x15.state = BOT_1_SHOT;
            }  
        }
        else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
            if (botMode2 == ATTACK_MODE){
                if ((botAttackResult = hardLevelBotBF(&xb2, &yb2, mapBot1, MAP_SIZE_15_X_15, shipBaseBFBot1, BOT_2_SHOT, GAME_PROCESS)) == HIT_PLATE){
                    if (killShipInShipBase(shipBaseBFBot1, xb2 - 1, yb2 - 1) == SHIP_KILLED){
                        putMisses(mapBot1, shipBaseBFBot1, xb2 - 1, yb2 - 1, 1);
                    }
                    else {
                        botMode2 = FINISHING_OFF_MODE;
                    }

                }
                else if (botAttackResult == MISS_PLATE){
                    sMainGameBotFight15x15.state = BOT_1_SHOT;
                }
            }
            else {
                if ((botAttackResult = finishingOffBF(xb2 , yb2, mapBot1, shipBaseBFBot1, ATTACK_PROCESS, MAP_SIZE_15_X_15, BOT_2_SHOT)) == MISS_PLATE){
                    sMainGameBotFight15x15.state = BOT_1_SHOT;
                }
                else if (botAttackResult == SHIP_KILLED){
                    finishingOffBF(xb2 , yb2, mapBot1, shipBaseBFBot1, ATTACK_END, MAP_SIZE_15_X_15, BOT_2_SHOT);
                    putMisses(mapBot1, shipBaseBFBot1, xb2 - 1, yb2 - 1, 1);
                    botMode2 = ATTACK_MODE;
                }
            }
        }
        bot2Score++;
        lastBotShotTime = glfwGetTime();
        sleep(BOT_SHOT_DELAY);
    }
    else if (sMainGameBotFight15x15.state == FAQ){
        renderSprite(sMainGameBotFight15x15.FAQPlate, SpriteShaderProgram, FIRST_TEXTURE);
        for (int i = 0, startY = 530; i < FAQMainGameBotFightStringCount; i++, startY -= 30){
            renderText(sMainGameBotFight15x15.TextParams, TextShaderProgram, FAQMainGameBotFight[i], correctXcoords(320.0, windowSizeX) , correctYcoords(startY, windowSizeY), correctTextSize(0.6, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

        if (cursorInArea(xMousePos, yMousePos, 490, 620, 791, 545, windowSizeX, windowSizeY)){
            renderText(sMainGameBotFight15x15.TextParams, TextShaderProgram, "OK", correctXcoords(585.0, windowSizeX) , correctYcoords(112, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                sMainGameBotFight15x15.state = lastSceneState;
                lastClickTime = glfwGetTime();
            }
        }
        else {
            renderText(sMainGameBotFight15x15.TextParams, TextShaderProgram, "OK", correctXcoords(585.0, windowSizeX) , correctYcoords(112, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }    
        
    }
    else if (sMainGameBotFight15x15.state == GAME_END){
        renderSprite(sMainGameBotFight15x15.botWinPlate, SpriteShaderProgram, FIRST_TEXTURE);
        if (whoWin == 2){
            renderText(sMainGameBotFight15x15.TextParams, TextShaderProgram, "2", correctXcoords(695.0, windowSizeX) , correctYcoords(454, windowSizeY), correctTextSize(1.65, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
            snprintf(botScoreStr, 4, "%d", bot2Score);
            renderText(sMainGameBotFight15x15.TextParams, TextShaderProgram, botScoreStr, correctXcoords(655.0, windowSizeX) , correctYcoords(349, windowSizeY), correctTextSize(0.6, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }
        if (whoWin == 1){
            renderText(sMainGameBotFight15x15.TextParams, TextShaderProgram, "1", correctXcoords(695.0, windowSizeX) , correctYcoords(454, windowSizeY), correctTextSize(1.65, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
            snprintf(botScoreStr, 4, "%d", bot1Score);
            renderText(sMainGameBotFight15x15.TextParams, TextShaderProgram, botScoreStr, correctXcoords(655.0, windowSizeX) , correctYcoords(349, windowSizeY), correctTextSize(0.6, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }
        
        if (cursorInArea(xMousePos, yMousePos, 442, 491, 831, 408, windowSizeX, windowSizeY)){
            renderText(sMainGameBotFight15x15.TextParams, TextShaderProgram, "Back To Menu", correctXcoords(475.0, windowSizeX) , correctYcoords(256, windowSizeY), correctTextSize(1.2, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
                    mediumLevelBotBF(&xb1, &yb1, mapBot1, MAP_SIZE_15_X_15, BOT_1_SHOT, GAME_END);
                    mediumLevelBotBF(&xb2, &yb2, mapBot1, MAP_SIZE_15_X_15, BOT_2_SHOT, GAME_END);
                }
                else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
                    hardLevelBotBF(&xb1, &yb1, mapBot1, MAP_SIZE_15_X_15, shipBaseBFBot1, BOT_1_SHOT, GAME_END);
                    hardLevelBotBF(&xb2, &yb2, mapBot1, MAP_SIZE_15_X_15, shipBaseBFBot2, BOT_2_SHOT, GAME_END);
                }

                playerInfo.BotLevel = NOT_FILLED_IN;
                playerInfo.GameMode = NOT_FILLED_IN;
                playerInfo.MapSize = NOT_FILLED_IN;
                playerInfo.scene = MAIN_MENU_SCENES;
                botMode1 = ATTACK_MODE;
                botMode2 = ATTACK_MODE;

                if (shipBaseBFBot1 != NULL){
                    freeShipBase(shipBaseBFBot1);
                    shipBaseBFBot1 = NULL;
                }
                if (shipBaseBFBot2 != NULL){
                    freeShipBase(shipBaseBFBot2);
                    shipBaseBFBot2= NULL;
                }

                bot1Score = 0;
                bot2Score = 0;

                clearMap(mapBot1);
                clearMap(mapBot2);

                lastClickTime = glfwGetTime();
            }
        }
        else {
            renderText(sMainGameBotFight15x15.TextParams, TextShaderProgram, "Back To Menu", correctXcoords(475.0, windowSizeX) , correctYcoords(256, windowSizeY), correctTextSize(1.2, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);       
        }    
    }
    else if (sMainGameBotFight15x15.state == EXIT_QUESTION){
        renderSprite(sMainGameBotFight15x15.exitQuestion, SpriteShaderProgram, FIRST_TEXTURE);

        //Обработка кнопки YES
        if (cursorInArea(xMousePos, yMousePos, 325, 458, 589, 362, windowSizeX, windowSizeY)){
            renderText(sMainGameBotFight15x15.TextParams, TextShaderProgram, "YES" , correctXcoords(389.0, windowSizeX) , correctYcoords(290.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                playerInfo.scene = SAVING_GAME_SCENES;
                sMainGameBotFight15x15.state = lastSceneState;
                lastClickTime = glfwGetTime();
            }
        }
        else {
            renderText(sMainGameBotFight15x15.TextParams, TextShaderProgram, "YES" , correctXcoords(389.0, windowSizeX) , correctYcoords(290.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        } 

        //Обработка кнопки NO
        if (cursorInArea(xMousePos, yMousePos, 685, 458, 952, 362, windowSizeX, windowSizeY)){
            renderText(sMainGameBotFight15x15.TextParams, TextShaderProgram, "NO" , correctXcoords(775.0, windowSizeX) , correctYcoords(290.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
                    mediumLevelBotBF(&xb1, &yb1, mapBot1, MAP_SIZE_15_X_15, BOT_1_SHOT, GAME_END);
                    mediumLevelBotBF(&xb2, &yb2, mapBot1, MAP_SIZE_15_X_15, BOT_2_SHOT, GAME_END);
                }
                else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
                    hardLevelBotBF(&xb1, &yb1, mapBot1, MAP_SIZE_15_X_15, shipBaseBFBot1, BOT_1_SHOT, GAME_END);
                    hardLevelBotBF(&xb2, &yb2, mapBot1, MAP_SIZE_15_X_15, shipBaseBFBot2, BOT_2_SHOT, GAME_END);
                }

                playerInfo.BotLevel = NOT_FILLED_IN;
                playerInfo.GameMode = NOT_FILLED_IN;
                playerInfo.MapSize = NOT_FILLED_IN;
                playerInfo.scene = MAIN_MENU_SCENES;
                botMode1 = ATTACK_MODE;
                botMode2 = ATTACK_MODE;

                if (shipBaseBFBot1 != NULL){
                    freeShipBase(shipBaseBFBot1);
                    shipBaseBFBot1 = NULL;
                }
                if (shipBaseBFBot2 != NULL){
                    freeShipBase(shipBaseBFBot2);
                    shipBaseBFBot2= NULL;
                }
                
                bot1Score = 0;
                bot2Score = 0;

                clearMap(mapBot1);
                clearMap(mapBot2);

                lastClickTime = glfwGetTime();
            }
        }
        else {
            renderText(sMainGameBotFight15x15.TextParams, TextShaderProgram, "NO" , correctXcoords(775.0, windowSizeX) , correctYcoords(290.0, windowSizeY), correctTextSize(1.7, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }
        
    }


    Bot2ShipsLeft = getShipsLeft(shipBaseBFBot2);
    snprintf(shipsLeftStr, 3, "%d", Bot2ShipsLeft);
    renderText(sMainGameBotFight15x15.TextParams, TextShaderProgram, shipsLeftStr, correctXcoords(920.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    
    memset(shipsLeftStr, '\0', 3);

    Bot1ShipsLeft = getShipsLeft(shipBaseBFBot1);
    snprintf(shipsLeftStr, 3, "%d", Bot1ShipsLeft);
    renderText(sMainGameBotFight15x15.TextParams, TextShaderProgram, shipsLeftStr, correctXcoords(265.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);

    //Если у кого-то из игроков не осталось кораблей, значит игра закончилась
    if ((Bot1ShipsLeft == 0 || Bot2ShipsLeft == 0) && sMainGameBotFight15x15.state != FAQ){
        sMainGameBotFight15x15.state = GAME_END;
        if (Bot1ShipsLeft != 0) whoWin = 1;
        if (Bot2ShipsLeft != 0) whoWin = 2; 
    }


    //Отображение того, чей выстрел ожидается в данный момент
    if (sMainGameBotFight15x15.state == BOT_1_SHOT || (sMainGameBotFight15x15.state == FAQ && lastSceneState == BOT_1_SHOT) || (sMainGameBotFight15x15.state == EXIT_QUESTION && lastSceneState == BOT_1_SHOT)){
        renderText(sMainGameBotFight15x15.TextParams, TextShaderProgram, "BOT 1 SHOT" , correctXcoords(442.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }
    else if (sMainGameBotFight15x15.state == BOT_2_SHOT || (sMainGameBotFight15x15.state == FAQ && lastSceneState == BOT_2_SHOT) || (sMainGameBotFight15x15.state == EXIT_QUESTION && lastSceneState == BOT_2_SHOT)){
        renderText(sMainGameBotFight15x15.TextParams, TextShaderProgram, "BOT 2 SHOT" , correctXcoords(442.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }
    else if (sMainGameBotFight15x15.state == GAME_END || (sMainGameBotFight15x15.state == FAQ && lastSceneState == GAME_END) || (sMainGameBotFight15x15.state == EXIT_QUESTION && lastSceneState == GAME_END)){
        renderText(sMainGameBotFight15x15.TextParams, TextShaderProgram, "GAME END" , correctXcoords(446.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);

    }

    //Обработка FAQ
    if (cursorInArea(xMousePos, yMousePos, 1108, 70, 1169, 24, windowSizeX, windowSizeY) && sMainGameBotFight15x15.state != FAQ){
        renderSprite(sMainGameBotFight15x15.QuestionMarkBtn, SpriteShaderProgram, SECOND_TEXTURE);
         if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            lastSceneState = sMainGameBotFight15x15.state;
            sMainGameBotFight15x15.state = FAQ;
            lastClickTime = glfwGetTime();
        }
    }
    else {
        renderSprite(sMainGameBotFight15x15.QuestionMarkBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }    

    //Обработка кнопки Exit
    if (cursorInArea(xMousePos, yMousePos, 1196, 73, 1260, 20, windowSizeX, windowSizeY) && sMainGameBotFight15x15.state != FAQ){
        renderSprite(sMainGameBotFight15x15.ExitBtn, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            if (sMainGameBotFight15x15.state == EXIT_QUESTION){
                sMainGameBotFight15x15.state = lastSceneState;
            }
            else {
                lastSceneState = sMainGameBotFight15x15.state;
                sMainGameBotFight15x15.state = EXIT_QUESTION;
            }

            lastClickTime = glfwGetTime();
        }
    }
    else {
        renderSprite(sMainGameBotFight15x15.ExitBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }
    
}

void renderAddingNickName(GLFWwindow* window)
{
    extern GLuint SpriteShaderProgram;
    extern GLuint TextShaderProgram;
    extern AddingNickName sAddingNickName;
    extern Player playerInfo;
    extern LeaderBoard* leaderBoard;
    extern int playerScore;
    extern char nickname[MAX_STRING_SIZE];

    extern int windowSizeX;
    extern int windowSizeY;

    extern double lastClickTime;

    extern char FAQAddingName[2][MAX_STRING_SIZE];
    extern const int FAQAddingNameStringCount;

    double xMousePos,
           yMousePos;

    int symbolsLeft = 0;
    char symbolsLeftStr[4] = {'\0',};

    static int lastSceneState = 0;

    glfwGetCursorPos(window, &xMousePos, &yMousePos);
    //printf("%.2lf  %.2lf    ", xMousePos, yMousePos);
    //printf("Window size: %dx%d\n", windowSizeX, windowSizeY);

    renderAnimSprite(sAddingNickName.Background, SpriteShaderProgram, time(NULL), 1.0);
    renderSprite(sAddingNickName.buttonPlates, SpriteShaderProgram, FIRST_TEXTURE);

    symbolsLeft = getWord(nickname, MAX_NICKNAME_SIZE, window);   
    snprintf(symbolsLeftStr, 3, "%d", symbolsLeft);
    renderText(sAddingNickName.TextParams2, TextShaderProgram, symbolsLeftStr , correctXcoords(733.0, windowSizeX) , correctYcoords(310.0, windowSizeY), correctTextSize(0.56, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    renderText(sAddingNickName.TextParams2, TextShaderProgram, nickname , correctXcoords(340.0, windowSizeX) , correctYcoords(371.0, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    
    if (cursorInArea(xMousePos, yMousePos, 506, 515, 774, 447, windowSizeX, windowSizeY) && sAddingNickName.state != FAQ){
        renderText(sAddingNickName.TextParams1, TextShaderProgram, "READY" , correctXcoords(553.0, windowSizeX) , correctYcoords(222.0, windowSizeY), correctTextSize(1.4, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
         if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            //Перед добавлением ника нужно записать в файл ранее отсортированную таблицу, очистить её, а потом скопировать с файла таблицу с добавленым ником и заново отсортировать её
            //Таким образом нужно будет переместить на нужное место только один элемент

            int resault = checkNickname(leaderBoard, nickname, playerScore, playerInfo.MapSize, playerInfo.BotLevel);

            if (leaderBoard != NULL) updateLeaderBoard(PATH_TO_LEADERBOARD_DATA, leaderBoard);
            if (leaderBoard != NULL) freeLeaderBoard(leaderBoard);
            
            //скидываем счётчик индексов никнейма
            getWord(NULL, MAX_NICKNAME_SIZE, window);

            if (resault == SCORE_NOT_UPDATED) pushDataInLeaderBoard(nickname, playerScore, playerInfo.MapSize, playerInfo.BotLevel, PATH_TO_LEADERBOARD_DATA);
            leaderBoard = getDataFromLeaderBoard(PATH_TO_LEADERBOARD_DATA);
            sortLeaderBoard(leaderBoard);

            memset(nickname, '\0', MAX_NICKNAME_SIZE);

            //скидываем счётчик индексов никнейма
            getWord(NULL, MAX_NICKNAME_SIZE, window);

            playerInfo.BotLevel = NOT_FILLED_IN;
            playerInfo.GameMode = NOT_FILLED_IN;
            playerInfo.MapSize = NOT_FILLED_IN;
            playerScore = 0;
            
            playerInfo.scene = MAIN_MENU_SCENES;
            lastClickTime = glfwGetTime();
        }
    }
    else {
        renderText(sAddingNickName.TextParams1, TextShaderProgram, "READY" , correctXcoords(553.0, windowSizeX) , correctYcoords(222.0, windowSizeY), correctTextSize(1.4, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }    

    //Обработка кнопки Exit
    if ((cursorInArea(xMousePos, yMousePos, 1198, 68, 1258, 18, windowSizeX, windowSizeY) && sAddingNickName.state != FAQ)){
        renderSprite(sAddingNickName.ExitBtn, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            memset(nickname, '\0', MAX_NICKNAME_SIZE);

            //скидываем счётчик индексов никнейма
            getWord(NULL, MAX_NICKNAME_SIZE, window);

            playerInfo.BotLevel = NOT_FILLED_IN;
            playerInfo.GameMode = NOT_FILLED_IN;
            playerInfo.MapSize = NOT_FILLED_IN;
            playerScore = 0;
            
            playerInfo.scene = MAIN_MENU_SCENES;
            lastClickTime = glfwGetTime();
        }
    }
    else {
        renderSprite(sAddingNickName.ExitBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }
    
    //Обработка FAQ
    if (cursorInArea(xMousePos, yMousePos, 1108, 70, 1169, 24, windowSizeX, windowSizeY) && sAddingNickName.state != FAQ){
        renderSprite(sAddingNickName.QuestionMarkBtn, SpriteShaderProgram, SECOND_TEXTURE);
         if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            lastSceneState = sAddingNickName.state;
            sAddingNickName.state = FAQ;
            lastClickTime = glfwGetTime();
        }
    }
    else {
        renderSprite(sAddingNickName.QuestionMarkBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }    

    //Вывод подсказки
    if (sAddingNickName.state == FAQ){
        renderSprite(sAddingNickName.FAQPlate, SpriteShaderProgram, FIRST_TEXTURE);
        for (int i = 0, startY = 530; i < FAQAddingNameStringCount; i++, startY -= 30){
            renderText(sAddingNickName.TextParams2, TextShaderProgram, FAQAddingName[i], correctXcoords(320.0, windowSizeX) , correctYcoords(startY, windowSizeY), correctTextSize(0.6, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

        if (cursorInArea(xMousePos, yMousePos, 490, 620, 791, 545, windowSizeX, windowSizeY)){
            renderText(sAddingNickName.TextParams1, TextShaderProgram, "OK", correctXcoords(585.0, windowSizeX) , correctYcoords(112, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                sAddingNickName.state = lastSceneState;
                lastClickTime = glfwGetTime();
            }
        }
        else {
            renderText(sAddingNickName.TextParams1, TextShaderProgram, "OK", correctXcoords(585.0, windowSizeX) , correctYcoords(112, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }    
        
    }

}

void renderLeaders(GLFWwindow* window)
{
    extern GLuint SpriteShaderProgram;
    extern GLuint TextShaderProgram;
    extern Leaders sLeaders;
    extern Player playerInfo;
    extern LeaderBoard* leaderBoard;
    extern char nickname[MAX_STRING_SIZE];

    extern int windowSizeX;
    extern int windowSizeY;

    extern double lastClickTime;

    extern char FAQMainGameBotFight [2][MAX_STRING_SIZE];
    extern const int FAQMainGameBotFightStringCount;

    double xMousePos,
           yMousePos;

    static int mapSize = 0,
               botLevel = 0,
               startNumber = 0;

    char dataStr[5] = {'\0'};

    glfwGetCursorPos(window, &xMousePos, &yMousePos);
    printf("%.2lf  %.2lf    ", xMousePos, yMousePos);
    printf("Window size: %dx%d\n", windowSizeX, windowSizeY);

    renderAnimSprite(sLeaders.Background, SpriteShaderProgram, time(NULL), 1.0);
    renderSprite(sLeaders.buttonPlates, SpriteShaderProgram, FIRST_TEXTURE);

    //if (leaderBoard == NULL) getDataFromLeaderBoard(PATH_TO_LEADERBOARD_DATA); 

    //Map Size buttons
    if ((cursorInArea(xMousePos, yMousePos, 40, 186, 312, 108, windowSizeX, windowSizeY) && sLeaders.state != FAQ) || mapSize == MAP_SIZE_10_X_10){
        renderText(sLeaders.TextParams1, TextShaderProgram, "10x10" , correctXcoords(83.0, windowSizeX) , correctYcoords(552.0, windowSizeY), correctTextSize(1.6, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            if (mapSize != MAP_SIZE_10_X_10){
                mapSize = MAP_SIZE_10_X_10;
                lastClickTime = glfwGetTime();
            }
        }
    }
    else {
        renderText(sLeaders.TextParams1, TextShaderProgram, "10x10" , correctXcoords(83.0, windowSizeX) , correctYcoords(552.0, windowSizeY), correctTextSize(1.6, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }   

    if ((cursorInArea(xMousePos, yMousePos, 40, 294, 312, 216, windowSizeX, windowSizeY) && sLeaders.state != FAQ) || mapSize == MAP_SIZE_15_X_15){
        renderText(sLeaders.TextParams1, TextShaderProgram, "15x15" , correctXcoords(83.0, windowSizeX) , correctYcoords(445.0, windowSizeY), correctTextSize(1.6, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            if (mapSize != MAP_SIZE_15_X_15){
                mapSize = MAP_SIZE_15_X_15;
                lastClickTime = glfwGetTime();
            }
        }
    }
    else {
        renderText(sLeaders.TextParams1, TextShaderProgram, "15x15" , correctXcoords(83.0, windowSizeX) , correctYcoords(445.0, windowSizeY), correctTextSize(1.6, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }


    //Bot level buttons
    if ((cursorInArea(xMousePos, yMousePos, 40, 472, 312, 391, windowSizeX, windowSizeY) && sLeaders.state != FAQ) || botLevel == EASY_BOT_LEVEL){
        renderText(sLeaders.TextParams1, TextShaderProgram, "EASY" , correctXcoords(93.0, windowSizeX) , correctYcoords(268.0, windowSizeY), correctTextSize(1.6, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            if (botLevel != EASY_BOT_LEVEL){
                botLevel = EASY_BOT_LEVEL;
                lastClickTime = glfwGetTime();
            }
        }
    }
    else {
        renderText(sLeaders.TextParams1, TextShaderProgram, "EASY" , correctXcoords(93.0, windowSizeX) , correctYcoords(268.0, windowSizeY), correctTextSize(1.6, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    if ((cursorInArea(xMousePos, yMousePos, 40, 568, 312, 491, windowSizeX, windowSizeY) && sLeaders.state != FAQ) || botLevel == NORMAL_BOT_LEVEL){
        renderText(sLeaders.TextParams1, TextShaderProgram, "NORMAL" , correctXcoords(62.0, windowSizeX) , correctYcoords(171.0, windowSizeY), correctTextSize(1.5, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            if (botLevel != NORMAL_BOT_LEVEL){
                botLevel = NORMAL_BOT_LEVEL;
                lastClickTime = glfwGetTime();
            }
        }
    }
    else {
        renderText(sLeaders.TextParams1, TextShaderProgram, "NORMAL" , correctXcoords(62.0, windowSizeX) , correctYcoords(171.0, windowSizeY), correctTextSize(1.5, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    if ((cursorInArea(xMousePos, yMousePos, 40, 668, 312, 593, windowSizeX, windowSizeY) && sLeaders.state != FAQ) || botLevel == HARD_BOT_LEVEL){
        renderText(sLeaders.TextParams1, TextShaderProgram, "HARD" , correctXcoords(93.0, windowSizeX) , correctYcoords(68.0, windowSizeY), correctTextSize(1.6, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            if (botLevel != HARD_BOT_LEVEL){
                botLevel = HARD_BOT_LEVEL;
                lastClickTime = glfwGetTime();
            }
        }
    }
    else {
        renderText(sLeaders.TextParams1, TextShaderProgram, "HARD" , correctXcoords(93.0, windowSizeX) , correctYcoords(68.0, windowSizeY), correctTextSize(1.6, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    //Обработка кнопки Exit
    if ((cursorInArea(xMousePos, yMousePos, 1199, 74, 1265, 23, windowSizeX, windowSizeY) && sLeaders.state != FAQ)){
        renderSprite(sLeaders.ExitBtn, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            mapSize = 0;
            botLevel = 0;
            startNumber = 0;
            playerInfo.scene = MAIN_MENU_SCENES;
        }
    }
    else {
        renderSprite(sLeaders.ExitBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }

    //Обработка pagUP
    if ((cursorInArea(xMousePos, yMousePos, 1197, 347, 1267, 293, windowSizeX, windowSizeY) && sLeaders.state != FAQ)){
        renderSprite(sLeaders.pagUp, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            if (startNumber - 15 >= 0) startNumber -= 15;
            lastClickTime = glfwGetTime();
        }
    }
    else {
        renderSprite(sLeaders.pagUp, SpriteShaderProgram, FIRST_TEXTURE);
    }

    //Обработка pagDOWN
    if ((cursorInArea(xMousePos, yMousePos, 1199, 426, 1265, 374, windowSizeX, windowSizeY) && sLeaders.state != FAQ)){
        renderSprite(sLeaders.pagDown, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            if (startNumber + 15 < leaderBoard->count) startNumber += 15;

            lastClickTime = glfwGetTime();
        }
    }
    else {
        renderSprite(sLeaders.pagDown, SpriteShaderProgram, FIRST_TEXTURE);
    }
    
    
    

    double y = 570;
    int place = 1;

    //Вывод выборки
    if (mapSize != 0 && botLevel != 0){
        for (int i = 0; i < leaderBoard->count; i++){
            if (mapSize == leaderBoard->nodes[i]->MapSize && botLevel == leaderBoard->nodes[i]->BotLevel){
                if ((i >= startNumber && i < startNumber + 15) || (place < 15 && i >= startNumber + 15)){
                    snprintf(dataStr, 4, "%d", place);
                    renderText(sLeaders.TextParams2, TextShaderProgram, dataStr , correctXcoords(500, windowSizeX) , correctYcoords(y, windowSizeY), correctTextSize(0.6, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
                    memset(dataStr, '\0', 5);
                    snprintf(dataStr, 4, "%d", leaderBoard->nodes[i]->Score);
                    renderText(sLeaders.TextParams2, TextShaderProgram, dataStr , correctXcoords(1013, windowSizeX) , correctYcoords(y, windowSizeY), correctTextSize(0.6, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
                    memset(dataStr, '\0', 5);
                    renderText(sLeaders.TextParams2, TextShaderProgram, leaderBoard->nodes[i]->Nickname , correctXcoords(610, windowSizeX) , correctYcoords(y, windowSizeY), correctTextSize(0.6, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
                    y -= 35;
                }
                place++;
            }
        }
    }


}

void renderGetSaveName(GLFWwindow* window)
{
    extern GLuint SpriteShaderProgram;
    extern GLuint TextShaderProgram;
    extern GetSaveName sGetSaveName;
    extern Player playerInfo;
    extern LeaderBoard* leaderBoard;
    extern MainGameBase10x10 sMainGameBase10x10;
    extern MainGameBase15x15 sMainGameBase15x15;
    extern MainGameBotFight10x10 sMainGameBotFight10x10;
    extern MainGameBotFight15x15 sMainGameBotFight15x15;
    extern int playerScore;
    extern char saveName[MAX_SAVENAME_SIZE];

    extern int windowSizeX;
    extern int windowSizeY;

    extern double lastClickTime;

    extern int playerScore;
    extern int botScore;
    extern int bot1Score;
    extern int bot2Score;

    extern int map[18][18];
    extern int mapBot[18][18];
    extern int mapBot1[18][18];
    extern int mapBot2[18][18];

    extern ShipBase* shipBase;
    extern ShipBase* botShipBase;
    extern ShipBase* shipBaseBFBot1;
    extern ShipBase* shipBaseBFBot2;

    extern SaveNamesList* listSaveNames;

    extern char FAQAddingSaveName[2][MAX_STRING_SIZE];
    extern const int FAQAddingSaveNameStringCount;

    double xMousePos,
           yMousePos;

    int symbolsLeft = 0;
    char symbolsLeftStr[4] = {'\0',};

    static int lastSceneState = 0;

    glfwGetCursorPos(window, &xMousePos, &yMousePos);
    printf("%.2lf  %.2lf    ", xMousePos, yMousePos);
    printf("Window size: %dx%d\n", windowSizeX, windowSizeY);

    renderAnimSprite(sGetSaveName.Background, SpriteShaderProgram, time(NULL), 1.0);
    renderSprite(sGetSaveName.buttonPlates, SpriteShaderProgram, FIRST_TEXTURE);

    symbolsLeft = getWord(saveName, MAX_SAVENAME_SIZE, window);   
    snprintf(symbolsLeftStr, 3, "%d", symbolsLeft);
    renderText(sGetSaveName.TextParams2, TextShaderProgram, symbolsLeftStr , correctXcoords(738.0, windowSizeX) , correctYcoords(310.0, windowSizeY), correctTextSize(0.56, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    renderText(sGetSaveName.TextParams2, TextShaderProgram, saveName , correctXcoords(355.0, windowSizeX) , correctYcoords(371.0, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    
    if (cursorInArea(xMousePos, yMousePos, 506, 515, 774, 447, windowSizeX, windowSizeY) && sGetSaveName.state != FAQ){
        renderText(sGetSaveName.TextParams1, TextShaderProgram, "READY" , correctXcoords(565.0, windowSizeX) , correctYcoords(222.0, windowSizeY), correctTextSize(1.4, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            if (playerInfo.MapSize == MAP_SIZE_10_X_10 && playerInfo.GameMode == BASIC_MODE){
                saveGame(PATH_TO_FOLDER, saveName, playerInfo.GameMode, playerInfo.MapSize, playerInfo.BotLevel, sMainGameBase10x10.state, playerScore, botScore, map, mapBot, shipBase, botShipBase); 
                if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
                    mediumLevelBot(0, 0, map, MAP_SIZE_10_X_10, GAME_END);
                }
                else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
                    hardLevelBot(0, 0, map, MAP_SIZE_10_X_10, shipBase, GAME_END);
                }

                playerInfo.BotLevel = NOT_FILLED_IN;
                playerInfo.GameMode = NOT_FILLED_IN;
                playerInfo.MapSize = NOT_FILLED_IN;

                botMode = ATTACK_MODE;

                if (shipBase != NULL){
                    freeShipBase(shipBase);
                    shipBase = NULL;
                }
                if (botShipBase != NULL){
                    freeShipBase(botShipBase);
                    botShipBase = NULL;
                }
                
                playerScore = 0;
                botScore = 0;

                clearMap(map);
                clearMap(mapBot);

                lastClickTime = glfwGetTime();

                playerInfo.scene = MAIN_MENU_SCENES;
            }
            else if (playerInfo.MapSize == MAP_SIZE_15_X_15 && playerInfo.GameMode == BASIC_MODE){
                saveGame(PATH_TO_FOLDER, saveName, playerInfo.GameMode, playerInfo.MapSize, playerInfo.BotLevel, sMainGameBase15x15.state, playerScore, botScore, map, mapBot, shipBase, botShipBase); 
                if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
                    mediumLevelBot(0, 0, map, MAP_SIZE_15_X_15, GAME_END);
                }
                else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
                    hardLevelBot(0, 0, map, MAP_SIZE_15_X_15, shipBase, GAME_END);
                }

                playerInfo.BotLevel = NOT_FILLED_IN;
                playerInfo.GameMode = NOT_FILLED_IN;
                playerInfo.MapSize = NOT_FILLED_IN;

                botMode = ATTACK_MODE;

                if (shipBase != NULL){
                    freeShipBase(shipBase);
                    shipBase = NULL;
                }
                if (botShipBase != NULL){
                    freeShipBase(botShipBase);
                    botShipBase = NULL;
                }
                
                playerScore = 0;
                botScore = 0;

                clearMap(map);
                clearMap(mapBot);

                lastClickTime = glfwGetTime();

                playerInfo.scene = MAIN_MENU_SCENES;

            }
            else if (playerInfo.MapSize == MAP_SIZE_10_X_10 && playerInfo.GameMode == BOTS_FIGHT_MODE){
                saveGame(PATH_TO_FOLDER, saveName, playerInfo.GameMode, playerInfo.MapSize, playerInfo.BotLevel, sMainGameBotFight10x10.state, bot1Score, bot2Score, mapBot1, mapBot2, shipBaseBFBot1, shipBaseBFBot2); 
                if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
                    mediumLevelBotBF(0, 0, mapBot1, MAP_SIZE_10_X_10, BOT_1_SHOT, GAME_END);
                    mediumLevelBotBF(0, 0, mapBot1, MAP_SIZE_10_X_10, BOT_2_SHOT, GAME_END);
                }
                else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
                    hardLevelBotBF(0, 0, mapBot1, MAP_SIZE_10_X_10, shipBaseBFBot1, BOT_1_SHOT, GAME_END);
                    hardLevelBotBF(0, 0, mapBot1, MAP_SIZE_10_X_10, shipBaseBFBot2, BOT_2_SHOT, GAME_END);
                }

                playerInfo.BotLevel = NOT_FILLED_IN;
                playerInfo.GameMode = NOT_FILLED_IN;
                playerInfo.MapSize = NOT_FILLED_IN;

                botMode1 = ATTACK_MODE;
                botMode2 = ATTACK_MODE;

                if (shipBaseBFBot1 != NULL){
                    freeShipBase(shipBaseBFBot1);
                    shipBaseBFBot1 = NULL;
                }
                if (shipBaseBFBot2 != NULL){
                    freeShipBase(shipBaseBFBot2);
                    shipBaseBFBot2= NULL;
                }
                
                bot1Score = 0;
                bot2Score = 0;

                clearMap(mapBot1);
                clearMap(mapBot2);

                lastClickTime = glfwGetTime();
            
                
                playerInfo.scene = MAIN_MENU_SCENES;

            }
            else if (playerInfo.MapSize == MAP_SIZE_15_X_15 && playerInfo.GameMode == BOTS_FIGHT_MODE){
                saveGame(PATH_TO_FOLDER, saveName, playerInfo.GameMode, playerInfo.MapSize, playerInfo.BotLevel, sMainGameBotFight15x15.state, bot1Score, bot2Score, mapBot1, mapBot2, shipBaseBFBot1, shipBaseBFBot2); 

                if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
                    mediumLevelBotBF(0, 0, mapBot1, MAP_SIZE_15_X_15, BOT_1_SHOT, GAME_END);
                    mediumLevelBotBF(0, 0, mapBot1, MAP_SIZE_15_X_15, BOT_2_SHOT, GAME_END);
                }
                else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
                    hardLevelBotBF(0, 0, mapBot1, MAP_SIZE_15_X_15, shipBaseBFBot1, BOT_1_SHOT, GAME_END);
                    hardLevelBotBF(0, 0, mapBot1, MAP_SIZE_15_X_15, shipBaseBFBot2, BOT_2_SHOT, GAME_END);
                }

                playerInfo.BotLevel = NOT_FILLED_IN;
                playerInfo.GameMode = NOT_FILLED_IN;
                playerInfo.MapSize = NOT_FILLED_IN;

                botMode1 = ATTACK_MODE;
                botMode2 = ATTACK_MODE;

                if (shipBaseBFBot1 != NULL){
                    freeShipBase(shipBaseBFBot1);
                    shipBaseBFBot1 = NULL;
                }
                if (shipBaseBFBot2 != NULL){
                    freeShipBase(shipBaseBFBot2);
                    shipBaseBFBot2= NULL;
                }
                
                bot1Score = 0;
                bot2Score = 0;

                clearMap(mapBot1);
                clearMap(mapBot2);

                lastClickTime = glfwGetTime();
            
                
                playerInfo.scene = MAIN_MENU_SCENES;
            }

            if (listSaveNames != NULL) freeSaveNames(listSaveNames);
            listSaveNames = getSaveNames(PATH_TO_FOLDER);
            
            getWord(NULL, MAX_SAVENAME_SIZE, window);
            memset(saveName, '\0', MAX_SAVENAME_SIZE);
        }
    }
    else {
        renderText(sGetSaveName.TextParams1, TextShaderProgram, "READY" , correctXcoords(565.0, windowSizeX) , correctYcoords(222.0, windowSizeY), correctTextSize(1.4, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }    

    //Обработка Exit
    if ((cursorInArea(xMousePos, yMousePos, 1198, 68, 1258, 18, windowSizeX, windowSizeY) && sGetSaveName.state != FAQ)){
        renderSprite(sGetSaveName.ExitBtn, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            
            if (playerInfo.GameMode == BASIC_MODE && playerInfo.MapSize == MAP_SIZE_10_X_10){
                if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
                    mediumLevelBot(0, 0, map, MAP_SIZE_10_X_10, GAME_END);
                }
                else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
                    hardLevelBot(0, 0, map, MAP_SIZE_10_X_10, shipBase, GAME_END);
                }

                playerInfo.BotLevel = NOT_FILLED_IN;
                playerInfo.GameMode = NOT_FILLED_IN;
                playerInfo.MapSize = NOT_FILLED_IN;

                botMode = ATTACK_MODE;

                if (shipBase != NULL){
                    freeShipBase(shipBase);
                    shipBase = NULL;
                }
                if (botShipBase != NULL){
                    freeShipBase(botShipBase);
                    botShipBase = NULL;
                }
                
                playerScore = 0;
                botScore = 0;

                clearMap(map);
                clearMap(mapBot);

                playerInfo.scene = MAIN_MENU_SCENES;
            }
            else if (playerInfo.GameMode == BASIC_MODE && playerInfo.MapSize == MAP_SIZE_15_X_15){
                if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
                    mediumLevelBot(0, 0, map, MAP_SIZE_15_X_15, GAME_END);
                }
                else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
                    hardLevelBot(0, 0, map, MAP_SIZE_15_X_15, shipBase, GAME_END);
                }

                playerInfo.BotLevel = NOT_FILLED_IN;
                playerInfo.GameMode = NOT_FILLED_IN;
                playerInfo.MapSize = NOT_FILLED_IN;

                botMode = ATTACK_MODE;

                if (shipBase != NULL){
                    freeShipBase(shipBase);
                    shipBase = NULL;
                }
                if (botShipBase != NULL){
                    freeShipBase(botShipBase);
                    botShipBase = NULL;
                }
                
                playerScore = 0;
                botScore = 0;

                clearMap(map);
                clearMap(mapBot);

                playerInfo.scene = MAIN_MENU_SCENES;
            

                getWord(NULL, MAX_SAVENAME_SIZE, window);
                memset(saveName, '\0', MAX_SAVENAME_SIZE);

            
                lastClickTime = glfwGetTime();
            }        
            else if (playerInfo.GameMode == BOTS_FIGHT_MODE && playerInfo.MapSize == MAP_SIZE_10_X_10){
                if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
                        mediumLevelBotBF(0, 0, mapBot1, MAP_SIZE_10_X_10, BOT_1_SHOT, GAME_END);
                        mediumLevelBotBF(0, 0, mapBot1, MAP_SIZE_10_X_10, BOT_2_SHOT, GAME_END);
                }
                else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
                    hardLevelBotBF(0, 0, mapBot1, MAP_SIZE_10_X_10, shipBaseBFBot1, BOT_1_SHOT, GAME_END);
                    hardLevelBotBF(0, 0, mapBot1, MAP_SIZE_10_X_10, shipBaseBFBot2, BOT_2_SHOT, GAME_END);
                }

                playerInfo.BotLevel = NOT_FILLED_IN;
                playerInfo.GameMode = NOT_FILLED_IN;
                playerInfo.MapSize = NOT_FILLED_IN;

                botMode1 = ATTACK_MODE;
                botMode2 = ATTACK_MODE;

                if (shipBaseBFBot1 != NULL){
                    freeShipBase(shipBaseBFBot1);
                    shipBaseBFBot1 = NULL;
                }
                if (shipBaseBFBot2 != NULL){
                    freeShipBase(shipBaseBFBot2);
                    shipBaseBFBot2= NULL;
                }
                
                bot1Score = 0;
                bot2Score = 0;

                clearMap(mapBot1);
                clearMap(mapBot2);

                playerInfo.scene = MAIN_MENU_SCENES;
            }
            else if (playerInfo.GameMode == BOTS_FIGHT_MODE && playerInfo.MapSize == MAP_SIZE_15_X_15){
                if (playerInfo.BotLevel == NORMAL_BOT_LEVEL){
                    mediumLevelBotBF(0, 0, mapBot1, MAP_SIZE_15_X_15, BOT_1_SHOT, GAME_END);
                    mediumLevelBotBF(0, 0, mapBot1, MAP_SIZE_15_X_15, BOT_2_SHOT, GAME_END);
                }
                else if (playerInfo.BotLevel == HARD_BOT_LEVEL){
                    hardLevelBotBF(0, 0, mapBot1, MAP_SIZE_15_X_15, shipBaseBFBot1, BOT_1_SHOT, GAME_END);
                    hardLevelBotBF(0, 0, mapBot1, MAP_SIZE_15_X_15, shipBaseBFBot2, BOT_2_SHOT, GAME_END);
                }

                playerInfo.BotLevel = NOT_FILLED_IN;
                playerInfo.GameMode = NOT_FILLED_IN;
                playerInfo.MapSize = NOT_FILLED_IN;

                botMode1 = ATTACK_MODE;
                botMode2 = ATTACK_MODE;

                if (shipBaseBFBot1 != NULL){
                    freeShipBase(shipBaseBFBot1);
                    shipBaseBFBot1 = NULL;
                }
                if (shipBaseBFBot2 != NULL){
                    freeShipBase(shipBaseBFBot2);
                    shipBaseBFBot2= NULL;
                }
                
                bot1Score = 0;
                bot2Score = 0;

                clearMap(mapBot1);
                clearMap(mapBot2);
                
                playerInfo.scene = MAIN_MENU_SCENES;
            }
        }
    }
    else {
        renderSprite(sGetSaveName.ExitBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }


    //Обработка FAQ
    if (cursorInArea(xMousePos, yMousePos, 1108, 70, 1169, 24, windowSizeX, windowSizeY) && sGetSaveName.state != FAQ){
        renderSprite(sGetSaveName.QuestionMarkBtn, SpriteShaderProgram, SECOND_TEXTURE);
         if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            lastSceneState = sGetSaveName.state;
            sGetSaveName.state = FAQ;
            lastClickTime = glfwGetTime();
        }
    }
    else {
        renderSprite(sGetSaveName.QuestionMarkBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }    

    //Вывод подсказки
    if (sGetSaveName.state == FAQ){
        renderSprite(sGetSaveName.FAQPlate, SpriteShaderProgram, FIRST_TEXTURE);
        for (int i = 0, startY = 530; i < FAQAddingSaveNameStringCount; i++, startY -= 30){
            renderText(sGetSaveName.TextParams2, TextShaderProgram, FAQAddingSaveName[i], correctXcoords(320.0, windowSizeX) , correctYcoords(startY, windowSizeY), correctTextSize(0.6, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

        if (cursorInArea(xMousePos, yMousePos, 490, 620, 791, 545, windowSizeX, windowSizeY)){
            renderText(sGetSaveName.TextParams1, TextShaderProgram, "OK", correctXcoords(585.0, windowSizeX) , correctYcoords(112, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                sGetSaveName.state = lastSceneState;
                lastClickTime = glfwGetTime();
            }
        }
        else {
            renderText(sGetSaveName.TextParams1, TextShaderProgram, "OK", correctXcoords(585.0, windowSizeX) , correctYcoords(112, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }    
        
    }
    
}

void renderLoadingMenu(GLFWwindow* window)
{
    extern GLuint SpriteShaderProgram;
    extern GLuint TextShaderProgram;
    extern LoadingMenu sLoadingMenu;
    extern Player playerInfo;
    extern MainGameBase10x10 sMainGameBase10x10;
    extern MainGameBase15x15 sMainGameBase15x15;
    extern MainGameBotFight10x10 sMainGameBotFight10x10;
    extern MainGameBotFight15x15 sMainGameBotFight15x15;
    extern SaveNamesList* listSaveNames;

    extern int map[18][18];
    extern int mapBot[18][18];
    extern int mapBot1[18][18];
    extern int mapBot2[18][18];

    extern ShipBase* shipBase;
    extern ShipBase* botShipBase;
    extern ShipBase* shipBaseBFBot1;
    extern ShipBase* shipBaseBFBot2;

    extern char loadName[MAX_SAVENAME_SIZE];

    extern int windowSizeX;
    extern int windowSizeY;

    extern double lastClickTime;

    extern char FAQLoadingGameMenu[5][MAX_STRING_SIZE];
    extern const int FAQLoadingGameMenuStringCount;

    double xMousePos,
           yMousePos;

    static int mapSize = 0,
               botLevel = 0,
               startNumber = 0,
               first = 0;
    
    int symbolsLeft = 0;
    char symbolsLeftStr[5] = {'\0'};

    glfwGetCursorPos(window, &xMousePos, &yMousePos);
    printf("%.2lf  %.2lf    ", xMousePos, yMousePos);
    printf("Window size: %dx%d\n", windowSizeX, windowSizeY);

    renderAnimSprite(sLoadingMenu.Background, SpriteShaderProgram, time(NULL), 1.0);
    renderSprite(sLoadingMenu.buttonPlates, SpriteShaderProgram, FIRST_TEXTURE);

    //Если сена открывается первый раз, то нужно подгрузить имена файлов
    if (first == 0){
        listSaveNames = getSaveNames(PATH_TO_FOLDER);
        first++;
    } 

    //Вывод списка сохранений
    double x = 462,
           y = 655;
    for (int i = 0; i < listSaveNames->count && i < MAX_SAVE_NAMES; i++){
        if (i >= startNumber && i < startNumber + 10){
            renderText(sLoadingMenu.TextParams2, TextShaderProgram, listSaveNames->names[i] , correctXcoords(x, windowSizeX) , correctYcoords(y, windowSizeY), correctTextSize(0.4, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
            y -= 30;
        }
    }
    
    //Вывод строки набранного текста
    symbolsLeft = getWord(loadName, MAX_SAVENAME_SIZE, window);   
    snprintf(symbolsLeftStr, 3, "%d", symbolsLeft);
    renderText(sLoadingMenu.TextParams2, TextShaderProgram, symbolsLeftStr , correctXcoords(720.0, windowSizeX) , correctYcoords(134, windowSizeY), correctTextSize(0.56, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    renderText(sLoadingMenu.TextParams2, TextShaderProgram, loadName , correctXcoords(379.0, windowSizeX) , correctYcoords(192.0, windowSizeY), correctTextSize(0.65, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    
    //Обработка pagUP
    if ((cursorInArea(xMousePos, yMousePos, 896, 193, 960, 142, windowSizeX, windowSizeY) && sLoadingMenu.state != FAQ)){
        renderSprite(sLoadingMenu.pagUp, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            if (startNumber - 10 >= 0) startNumber -= 10;
            lastClickTime = glfwGetTime();
        }
    }
    else {
        renderSprite(sLoadingMenu.pagUp, SpriteShaderProgram, FIRST_TEXTURE);
    }

    //Обработка pagDOWN
    if ((cursorInArea(xMousePos, yMousePos, 896, 267, 960, 215, windowSizeX, windowSizeY) && sLoadingMenu.state != FAQ)){
        renderSprite(sLoadingMenu.pagDown, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            if ((startNumber + 10 < listSaveNames->count) && startNumber + 10 < MAX_SAVE_NAMES) startNumber += 10;

            lastClickTime = glfwGetTime();
        }
    }
    else {
        renderSprite(sLoadingMenu.pagDown, SpriteShaderProgram, FIRST_TEXTURE);
    }


    //Обработка кнопки Load
    if (cursorInArea(xMousePos, yMousePos, 380, 677, 615, 615, windowSizeX, windowSizeY) && sLoadingMenu.state != FAQ){
        renderText(sLoadingMenu.TextParams1, TextShaderProgram, "LOAD" , correctXcoords(435.0, windowSizeX) , correctYcoords(58.0, windowSizeY), correctTextSize(1.2, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            if (loadGame(PATH_TO_FOLDER, loadName) == LOAD_SUCCESS){
                if (playerInfo.MapSize == MAP_SIZE_10_X_10 && playerInfo.GameMode == BASIC_MODE){
                    playerInfo.scene = MAIN_GAME_BASE_10_X_10;
                    
                    fillShipsTextures10x10(sMainGameBase10x10.PlayerMapArray, shipBase, map, TEXTURES_TURN_RIGHT);
                }
                else if (playerInfo.MapSize == MAP_SIZE_15_X_15 && playerInfo.GameMode == BASIC_MODE){
                    playerInfo.scene = MAIN_GAME_BASE_15_X_15;
                    fillShipsTextures15x15(sMainGameBase15x15.PlayerMapArray, shipBase, map, TEXTURES_TURN_RIGHT);
                }
                else if (playerInfo.MapSize == MAP_SIZE_10_X_10 && playerInfo.GameMode == BOTS_FIGHT_MODE){
                    playerInfo.scene = MAIN_GAME_BOT_FIGHT_10_X_10;
                    fillShipsTextures10x10(sMainGameBotFight10x10.Bot1MapArray, shipBaseBFBot1, mapBot1, TEXTURES_TURN_RIGHT);
                    fillShipsTextures10x10(sMainGameBotFight10x10.Bot2MapArray, shipBaseBFBot2, mapBot2, TEXTURES_TURN_LEFT);
                }
                else if (playerInfo.MapSize == MAP_SIZE_15_X_15 && playerInfo.GameMode == BOTS_FIGHT_MODE){
                    playerInfo.scene = MAIN_GAME_BOT_FIGHT_15_X_15;
                    fillShipsTextures15x15(sMainGameBotFight15x15.Bot1MapArray, shipBaseBFBot1, mapBot1, TEXTURES_TURN_RIGHT);
                    fillShipsTextures15x15(sMainGameBotFight15x15.Bot2MapArray, shipBaseBFBot2, mapBot2, TEXTURES_TURN_LEFT);
                }
            }
            getWord(NULL, MAX_SAVENAME_SIZE, window);
            memset(loadName, '\0', MAX_SAVENAME_SIZE);
            lastClickTime = glfwGetTime();
        }
    }
    else{
        renderText(sLoadingMenu.TextParams1, TextShaderProgram, "LOAD" , correctXcoords(435.0, windowSizeX) , correctYcoords(58.0, windowSizeY), correctTextSize(1.2, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    //Обработка кнопки Delete
    if (cursorInArea(xMousePos, yMousePos, 659, 677, 900, 615, windowSizeX, windowSizeY) && sLoadingMenu.state != FAQ){
        renderText(sLoadingMenu.TextParams1, TextShaderProgram, "DELETE" , correctXcoords(696.0, windowSizeX) , correctYcoords(58.0, windowSizeY), correctTextSize(1.2, windowSizeX, windowSizeY), 1.0f, 0.0f, 0.0f);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            if(delSave(PATH_TO_FOLDER, loadName) == DELETE_SUCCESS){
                if (listSaveNames != NULL) freeSaveNames(listSaveNames);
                listSaveNames = getSaveNames(PATH_TO_FOLDER);
                getWord(NULL, MAX_SAVENAME_SIZE, window);
                memset(loadName, '\0', MAX_SAVENAME_SIZE);

            }
            else{
                getWord(NULL, MAX_SAVENAME_SIZE, window);
                memset(loadName, '\0', MAX_SAVENAME_SIZE);
            }
            lastClickTime = glfwGetTime();
        }
    }
    else{
        renderText(sLoadingMenu.TextParams1, TextShaderProgram, "DELETE" , correctXcoords(696.0, windowSizeX) , correctYcoords(58.0, windowSizeY), correctTextSize(1.2, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }


    //Обработка кнопки Exit
    if (cursorInArea(xMousePos, yMousePos, 1202, 64, 1262, 17, windowSizeX, windowSizeY) && sLoadingMenu.state != FAQ){
        renderSprite(sLoadingMenu.ExitBtn, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            playerInfo.scene = MAIN_MENU_SCENES;
            playerInfo.BotLevel = NOT_FILLED_IN;
            playerInfo.GameMode = NOT_FILLED_IN;
            playerInfo.MapSize = NOT_FILLED_IN;
            getWord(NULL, MAX_SAVENAME_SIZE, window);
            memset(loadName, '\0', MAX_SAVENAME_SIZE);
            lastClickTime = glfwGetTime();
        }
    }
    else{
        renderSprite(sLoadingMenu.ExitBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }

    //Обработка кнопки подсказки 
    if (cursorInArea(xMousePos, yMousePos, 1203, 138, 1260, 95, windowSizeX, windowSizeY) && sLoadingMenu.state != FAQ){
        renderSprite(sLoadingMenu.QuestionMarkBtn, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            sLoadingMenu.state = FAQ;
            lastClickTime = glfwGetTime();
        }
    }
    else{
        renderSprite(sLoadingMenu.QuestionMarkBtn, SpriteShaderProgram, FIRST_TEXTURE);
    }
    
    //Обработка FAQ
    if (sLoadingMenu.state == FAQ){
        renderSprite(sLoadingMenu.FAQPlate, SpriteShaderProgram, FIRST_TEXTURE);
        for (int i = 0, startY = 530; i < FAQLoadingGameMenuStringCount; i++, startY -= 35){
            renderText(sLoadingMenu.TextParams2, TextShaderProgram, FAQLoadingGameMenu[i], correctXcoords(320.0, windowSizeX) , correctYcoords(startY, windowSizeY), correctTextSize(0.6, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }

        if (cursorInArea(xMousePos, yMousePos, 490, 620, 791, 545, windowSizeX, windowSizeY)){
            renderText(sLoadingMenu.TextParams1, TextShaderProgram, "OK", correctXcoords(585.0, windowSizeX) , correctYcoords(112, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 1.0f, 1.0f, 1.0f);
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                sLoadingMenu.state = NOT_FAQ;
                lastClickTime = glfwGetTime();
            }
        }
        else {
            renderText(sLoadingMenu.TextParams1, TextShaderProgram, "OK", correctXcoords(585.0, windowSizeX) , correctYcoords(112, windowSizeY), correctTextSize(2.0, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }    
        
    }
}
#endif