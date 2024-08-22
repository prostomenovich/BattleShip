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
    changeCorrectSpriteParams(sAbout.ExitButton, windowSizeX, windowSizeY);
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

    static int elemCount = 0;
    int maxElemCount = maxPlatesShip(shipBase);
    
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

    //Подгон под размер окна каждой клетки на поле
    for (int i = 0 ; i < 10; i++){
        for (int j = 0; j < 10; j++){
            Sprite* sp = sRaftPlacement10X10.MapArray[i][j].sprite;
            changeCorrectSpriteParams(sp, windowSizeX, windowSizeY);
        }
    }
    
    
    renderSprite(sRaftPlacement10X10.Background, SpriteShaderProgram, FIRST_TEXTURE);
    
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
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


    if (sRaftPlacement10X10.state == IN_EDIT_MODE){

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
    if (cursorInArea(xMousePos, yMousePos, 1200, 139, 1264, 89, windowSizeX, windowSizeY)){
        renderSprite(sRaftPlacement10X10.QuestionMarkBtn, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            
            lastClickTime = glfwGetTime();
        }
    }
    else {
        renderSprite(sRaftPlacement10X10.QuestionMarkBtn, SpriteShaderProgram, FIRST_TEXTURE);
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

    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
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


    if (sRaftPlacement15X15.state == IN_EDIT_MODE){

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
    if (cursorInArea(xMousePos, yMousePos, 42, 464, 359, 385, windowSizeX, windowSizeY)){
        if (AllShipsInMap(shipBase) == NOT_ALL_SHIPS_IN_MAP){
            renderText(sRaftPlacement15X15.TextParams, TextShaderProgram, "Play", correctXcoords(126.0, windowSizeX) , correctYcoords(274, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 1.0f, 0.0f, 0.0f);
        }
        else {
            renderText(sRaftPlacement15X15.TextParams, TextShaderProgram, "Play", correctXcoords(126.0, windowSizeX) , correctYcoords(274, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 0.0f, 1.0f, 0.0f);
        }

        if (AllShipsInMap(shipBase) == ALL_SHIPS_IN_MAP && glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            playerInfo.scene = MAIN_GAME_BASE_15_X_15;
           
           /* for (int i = 0; i < 15; i++){
                for (int j = 0; j < 15; j++){
                    if (map[i + 1][j + 1] == 2){
                        sMainGameBase15x15.PlayerMapArray[i][j].spriteState = THIS_IS_SHIP_PLATE_LIVE;
                    }
                }
            }*/

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
    if (cursorInArea(xMousePos, yMousePos, 36, 682, 361, 599, windowSizeX, windowSizeY)){
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
    if (cursorInArea(xMousePos, yMousePos, 37, 572, 362, 492, windowSizeX, windowSizeY)){
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
    if (cursorInArea(xMousePos, yMousePos, 1202, 64, 1262, 17, windowSizeX, windowSizeY)){
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
    if (cursorInArea(xMousePos, yMousePos, 1200, 139, 1264, 89, windowSizeX, windowSizeY)){
        renderSprite(sRaftPlacement15X15.QuestionMarkBtn, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            
            lastClickTime = glfwGetTime();
        }
    }
    else {
        renderSprite(sRaftPlacement15X15.QuestionMarkBtn, SpriteShaderProgram, FIRST_TEXTURE);
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
        
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
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


        if (sRaftPlacement10X10BF.state == IN_EDIT_MODE){

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
        if (cursorInArea(xMousePos, yMousePos, 36, 682, 361, 599, windowSizeX, windowSizeY)){
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
        if (cursorInArea(xMousePos, yMousePos, 37, 572, 362, 492, windowSizeX, windowSizeY)){
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
        
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
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


        if (sRaftPlacement10X10BF.state == IN_EDIT_MODE){

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
        if (cursorInArea(xMousePos, yMousePos, 36, 682, 361, 599, windowSizeX, windowSizeY)){
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
        if (cursorInArea(xMousePos, yMousePos, 37, 572, 362, 492, windowSizeX, windowSizeY)){
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
    if (cursorInArea(xMousePos, yMousePos, 1202, 64, 1262, 17, windowSizeX, windowSizeY)){
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
    if (cursorInArea(xMousePos, yMousePos, 1200, 139, 1264, 89, windowSizeX, windowSizeY)){
        renderSprite(sRaftPlacement10X10BF.QuestionMarkBtn, SpriteShaderProgram, SECOND_TEXTURE);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
            
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
        if (cursorInArea(xMousePos, yMousePos, 42, 464, 359, 385, windowSizeX, windowSizeY)){
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

                if (rand() % 2 == 0) sMainGameBotFight10x10.state = BOT_2_SHOT;
                else sMainGameBotFight10x10.state = BOT_1_SHOT;

                lastClickTime = glfwGetTime();
            }  
        }
        else {
            renderText(sRaftPlacement10X10BF.TextParams, TextShaderProgram, "Play", correctXcoords(120.0, windowSizeX) , correctYcoords(274, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
        }
        
}

void renderRaftPlacement15x15BF(GLFWwindow* window)
{
    extern GLuint SpriteShaderProgram;
    extern GLuint TextShaderProgram;
    extern RaftPlacement15x15BF sRaftPlacement15X15BF;
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
        
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
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


        if (sRaftPlacement15X15BF.state == IN_EDIT_MODE){

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
        if (cursorInArea(xMousePos, yMousePos, 36, 682, 361, 599, windowSizeX, windowSizeY)){
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
        if (cursorInArea(xMousePos, yMousePos, 37, 572, 362, 492, windowSizeX, windowSizeY)){
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
        
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
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


        if (sRaftPlacement15X15BF.state == IN_EDIT_MODE){
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
        if (cursorInArea(xMousePos, yMousePos, 36, 682, 361, 599, windowSizeX, windowSizeY)){
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
        if (cursorInArea(xMousePos, yMousePos, 37, 572, 362, 492, windowSizeX, windowSizeY)){
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
    if (cursorInArea(xMousePos, yMousePos, 1202, 64, 1262, 17, windowSizeX, windowSizeY)){
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
    if (cursorInArea(xMousePos, yMousePos, 42, 464, 359, 385, windowSizeX, windowSizeY)){
        if (AllShipsInMap(shipBaseBFBot2) == NOT_ALL_SHIPS_IN_MAP || AllShipsInMap(shipBaseBFBot1) == NOT_ALL_SHIPS_IN_MAP){
            renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, "Play", correctXcoords(124.0, windowSizeX) , correctYcoords(274, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 1.0f, 0.0f, 0.0f);
        }
        else {
            renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, "Play", correctXcoords(124.0, windowSizeX) , correctYcoords(274, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 0.0f, 1.0f, 0.0f);
        }

        if (AllShipsInMap(shipBaseBFBot2) == ALL_SHIPS_IN_MAP && AllShipsInMap(shipBaseBFBot1) == ALL_SHIPS_IN_MAP && glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                
            lastClickTime = glfwGetTime();
        }  
    }
    else {
        renderText(sRaftPlacement15X15BF.TextParams, TextShaderProgram, "Play", correctXcoords(124.0, windowSizeX) , correctYcoords(274, windowSizeY), correctTextSize(1.8, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
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

    static int botMode = ATTACK_MODE;

    char shipsLeftStr[3] = {'\0',};

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

    if (sMainGameBase10x10.state == PLAYER_SHOT){
        //Обработка выстрела игрока
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && cursorInArea(xMousePos, yMousePos, sMainGameBase10x10.BotMapArray[i][j].sprite->positionX, windowSizeY - sMainGameBase10x10.BotMapArray[i][j].sprite->positionY, sMainGameBase10x10.BotMapArray[i][j].sprite->positionX + sMainGameBase10x10.BotMapArray[i][j].sprite->sizeX, windowSizeY - sMainGameBase10x10.BotMapArray[i][j].sprite->positionY - sMainGameBase10x10.BotMapArray[i][j].sprite->sizeY, windowSizeX, windowSizeY) && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                    if (mapBot[i + 1][j + 1] == SHIP_PLATE){
                        mapBot[i + 1][j + 1] = HIT_PLATE;
                        if (killShipInShipBase(botShipBase, j, i) == SHIP_KILLED){
                            putMisses(mapBot, botShipBase, j, i, 1);
                        }

                    }
                    else if (mapBot[i + 1][j + 1] == EMPTY_PLATE){
                        mapBot[i + 1][j + 1] = MISS_PLATE;
                        sMainGameBase10x10.state = BOT_SHOT;
                    }
                }
            }
        }


    }
    else if (sMainGameBase10x10.state == BOT_SHOT) {
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
            if (botMode == ATTACK_MODE){
                printf("\n");
                if ((botAttackResult = mediumLevelBot(&x, &y, map, MAP_SIZE_10_X_10, GAME_PROCESS)) == HIT_PLATE){
                    //Если корабль убит, то продолжаем базовый подбор клетки для атаки, в противном случае активируем режим добивания
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
        sleep(BOT_SHOT_DELAY);
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


    PlayerShipsLeft = getShipsLeft(botShipBase);
    snprintf(shipsLeftStr, 3, "%d", PlayerShipsLeft);
    renderText(sMainGameBase10x10.TextParams, TextShaderProgram, shipsLeftStr, correctXcoords(907.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    
    memset(shipsLeftStr, '\0', 3);

    BotShipsLeft = getShipsLeft(shipBase);
    snprintf(shipsLeftStr, 3, "%d", BotShipsLeft);
    renderText(sMainGameBase10x10.TextParams, TextShaderProgram, shipsLeftStr, correctXcoords(274.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);

    //Если у кого-то из игроков не осталось кораблей, значит игра закончилась

    //Отображение того, чей выстрел ожидается в данный момент
    if (sMainGameBase10x10.state == PLAYER_SHOT || (sMainGameBase10x10.state == FAQ && lastSceneState == PLAYER_SHOT)){
        renderText(sMainGameBase10x10.TextParams, TextShaderProgram, "YOUR SHOT" , correctXcoords(442.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }
    else if (sMainGameBase10x10.state == BOT_SHOT || (sMainGameBase10x10.state == FAQ && lastSceneState == BOT_SHOT)){
        renderText(sMainGameBase10x10.TextParams, TextShaderProgram, "ENEMY SHOT" , correctXcoords(430.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }

    //Обработка FAQ
    if (cursorInArea(xMousePos, yMousePos, 1108, 70, 1169, 24, windowSizeX, windowSizeY) && sMainGameBase10x10.state != FAQ){
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

    double xMousePos,
           yMousePos;

    int PlayerShipsLeft,
        BotShipsLeft;

    static int x, y;
    static int lastSceneState = 0;
    
    int botAttackResult;

    static int botMode = ATTACK_MODE;

    char shipsLeftStr[3] = {'\0',};

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

    if (sMainGameBase15x15.state == PLAYER_SHOT){
        //Обработка выстрела игрока
        for (int i = 0; i < 15; i++){
            for (int j = 0; j < 15; j++){
                if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && cursorInArea(xMousePos, yMousePos, sMainGameBase15x15.BotMapArray[i][j].sprite->positionX, windowSizeY - sMainGameBase15x15.BotMapArray[i][j].sprite->positionY, sMainGameBase15x15.BotMapArray[i][j].sprite->positionX + sMainGameBase15x15.BotMapArray[i][j].sprite->sizeX, windowSizeY - sMainGameBase15x15.BotMapArray[i][j].sprite->positionY - sMainGameBase15x15.BotMapArray[i][j].sprite->sizeY, windowSizeX, windowSizeY) && glfwGetTime() - lastClickTime >= KEY_PRESSED_DELAY){
                    if (mapBot[i + 1][j + 1] == SHIP_PLATE){
                        mapBot[i + 1][j + 1] = HIT_PLATE;
                        if (killShipInShipBase(botShipBase, j, i) == SHIP_KILLED){
                            putMisses(mapBot, botShipBase, j, i, 1);
                        }

                    }
                    else if (mapBot[i + 1][j + 1] == EMPTY_PLATE){
                        mapBot[i + 1][j + 1] = MISS_PLATE;
                        sMainGameBase15x15.state = BOT_SHOT;
                    }
                }
            }
        }


    }
    else if (sMainGameBase15x15.state == BOT_SHOT) {
        //Обработка выстрела бота
        for (int i = 0; i < 10000000; i++);

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
        sleep(BOT_SHOT_DELAY);
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

    
    PlayerShipsLeft = getShipsLeft(botShipBase);
    snprintf(shipsLeftStr, 3, "%d", PlayerShipsLeft);
    renderText(sMainGameBase15x15.TextParams, TextShaderProgram, shipsLeftStr, correctXcoords(907.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    
    memset(shipsLeftStr, '\0', 3);

    BotShipsLeft = getShipsLeft(shipBase);
    snprintf(shipsLeftStr, 3, "%d", BotShipsLeft);
    renderText(sMainGameBase15x15.TextParams, TextShaderProgram, shipsLeftStr, correctXcoords(274.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);

    //Если у кого-то из игроков не осталось кораблей, значит игра закончилась

    //Отображение того, чей выстрел ожидается в данный момент
    if (sMainGameBase15x15.state == PLAYER_SHOT || (sMainGameBase15x15.state == FAQ && lastSceneState == PLAYER_SHOT)){
        renderText(sMainGameBase15x15.TextParams, TextShaderProgram, "YOUR SHOT" , correctXcoords(442.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }
    else if (sMainGameBase15x15.state == BOT_SHOT || (sMainGameBase15x15.state == FAQ && lastSceneState == BOT_SHOT)){
        renderText(sMainGameBase15x15.TextParams, TextShaderProgram, "ENEMY SHOT" , correctXcoords(430.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
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

    extern char FAQMainGame10x10Basic [5][MAX_STRING_SIZE];
    extern const int FAQMainGame10x10BasicStringCount;

    double xMousePos,
           yMousePos;

    int Bot1ShipsLeft,
        Bot2ShipsLeft;

    static int xb1, yb1, xb2, yb2;
    static int lastSceneStateBot1 = 0,
               lastSceneStateBot2 = 0;
    
    int botAttackResult;

    static int lastSceneState = 0;

    static int botMode1 = ATTACK_MODE,
               botMode2 = ATTACK_MODE;

    char shipsLeftStr[3] = {'\0',};

    glfwGetCursorPos(window, &xMousePos, &yMousePos);
    //printf("%.2lf  %.2lf    ", xMousePos, yMousePos);
    //printf("Window size: %dx%d\n", windowSizeX, windowSizeY);

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
    
    if (sMainGameBotFight10x10.state == BOT_1_SHOT){
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
                    putMisses(mapBot2, shipBaseBFBot2, xb1 - 1, yb1 - 1, 4);
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
        sleep(BOT_SHOT_DELAY);
    }
    else if (sMainGameBotFight10x10.state == BOT_2_SHOT) {
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
                    putMisses(mapBot1, shipBaseBFBot1, xb2 - 1, yb2 - 1, 4);
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
        sleep(BOT_SHOT_DELAY);
    }
    else if (sMainGameBotFight10x10.state == FAQ){
        renderSprite(sMainGameBotFight10x10.FAQPlate, SpriteShaderProgram, FIRST_TEXTURE);
        for (int i = 0, startY = 530; i < FAQMainGame10x10BasicStringCount; i++, startY -= 30){
            renderText(sMainGameBotFight10x10.TextParams, TextShaderProgram, FAQMainGame10x10Basic[i], correctXcoords(320.0, windowSizeX) , correctYcoords(startY, windowSizeY), correctTextSize(0.6, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
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
    }


    //Отображение того, чей выстрел ожидается в данный момент
    if (sMainGameBotFight10x10.state == BOT_1_SHOT || (sMainGameBotFight10x10.state == FAQ && lastSceneState == BOT_1_SHOT)){
        renderText(sMainGameBotFight10x10.TextParams, TextShaderProgram, "BOT 1 SHOT" , correctXcoords(442.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }
    else if (sMainGameBotFight10x10.state == BOT_2_SHOT || (sMainGameBotFight10x10.state == FAQ && lastSceneState == BOT_2_SHOT)){
        renderText(sMainGameBotFight10x10.TextParams, TextShaderProgram, "BOT 2 SHOT" , correctXcoords(442.0, windowSizeX) , correctYcoords(659.5, windowSizeY), correctTextSize(0.75, windowSizeX, windowSizeY), 0.0f, 0.0f, 0.0f);
    }
    else if (sMainGameBotFight10x10.state == GAME_END){
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
    
}

#endif