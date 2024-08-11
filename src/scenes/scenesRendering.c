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
            if (playerInfo.MapSize == MAP_SIZE_10_X_10)
                playerInfo.scene = RAFT_PLACEMENT_10_X_10;
            else 
                playerInfo.scene = RAFT_PLACEMENT_15_X_15; 
        }
    }
    
}


void renderRaftPlacement10x10(GLFWwindow* window)
{
    extern GLuint SpriteShaderProgram;
    extern GLuint TextShaderProgram;
    extern RaftPlacement10x10 sRaftPlacement10X10;
    extern Player playerInfo;
    extern ShipBase* shipBase;
    extern Coordinates* coords[5];

    extern int map[18][18];

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
    extern Player playerInfo;
    extern ShipBase* shipBase;
    extern Coordinates* coords[5];

    extern int map[18][18];

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

#endif