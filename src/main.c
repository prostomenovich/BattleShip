#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "render/renderUtils.h"
#include "render/text.h"
#include "render/shader.h"
#include <cglm/mat4.h>
#include <cglm/call.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include "scenes/scenesInitial.h"
#include "scenes/scenesRendering.h"
#include "game/leaderBoard.h"
#include "game/ShipBase.h"
#include "scenes/freeScenes.h"

int windowSizeX = 1280;
int windowSizeY = 720;


GLuint SpriteShaderProgram;
GLuint TextShaderProgram;

FT_Library ft1;
FT_Library ft2;

void glfwWindowSizeCallback(GLFWwindow* window, int width, int height);
void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
void character_callback( GLFWwindow * window, unsigned  int codepoint);

int main(void)
{   
    extern GLuint SpriteShaderProgram;
    extern GLuint TextShaderProgram;

    extern Player playerInfo;
    extern LeaderBoard* leaderBoard;

    extern ShipBase* shipBase;
    extern ShipBase* botShipBase;
    extern ShipBase* shipBaseBFBot1;
    extern ShipBase* shipBaseBFBot2;

    GLFWwindow* window;

    /*Инициализация библиотеки GLFW*/
    if (!glfwInit()){
        printf("Error initializing GLFW!\n");
        return EXIT_FAILURE;
    }
    
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    //Создание OpenGL контекста
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //Создание окна
    window = glfwCreateWindow(windowSizeX, windowSizeY, "BattleShip", NULL, NULL);

    glfwSetWindowAttrib(window, GLFW_RESIZABLE, GLFW_FALSE);
    glfwSetWindowSizeLimits(window, 1280, 720, 1280, 720);

    //Обработка коллбэков
    glfwSetWindowSizeCallback(window, glfwWindowSizeCallback);
    glfwSetKeyCallback(window, glfwKeyCallback);
    glfwSetCharCallback (window, character_callback);

    if (!window)
    {
        printf("GLFW_CREATE_WINDOW_FAILED!\n");
        glfwTerminate();
        return EXIT_FAILURE;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

	if (!gladLoadGL()){
		printf("Can't load GLAD!\n");
        glfwTerminate();
		return EXIT_FAILURE;
	}

    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("OpenGL Version: %s\n", glGetString(GL_VERSION));

    if (FT_Init_FreeType(&ft1)){
        printf("ERROR::FREETYPE: Could not init FreeType Library\n");
    }
    if (FT_Init_FreeType(&ft2)){
        printf("ERROR::FREETYPE: Could not init FreeType Library\n");
    }



    SpriteShaderProgram = MakeShaderProgram("../resources/shaders/SpriteVertex.glsl",
                                            "../resources/shaders/SpriteFragment.glsl");
    TextShaderProgram = MakeShaderProgram("../resources/shaders/textVertex.glsl",
                                            "../resources/shaders/textFragment.glsl");

    printf("Wait...We're equipping the team\n");

    initPiratesSprites();
    initMainMenu();
    initAbout();
    initNewLoadMenu();
    initGameSettingsMenu();
    initRaftPlacement10x10();
    initRaftPlacement15x15();
    initRaftPlacement10x10BF();
    initRaftPlacement15x15BF();

    printf("Wait...we're inspecting the guns\n");

    initMainGameBase10x10();
    initMainGameBase15x15();
    initMainGameBotFight10x10();
    initMainGameBotFight15x15();
    initAddingNickName();

    printf("Wait...We're swimming out of the bay\n");

    initLeaders();
    initGetSaveName();
    initLoadingMenu();

	glClearColor(0, 1, 0, 1);
    
    mat4 projectionMatrix;
    glm_ortho(0.f, windowSizeX, 0.f, windowSizeY, -100.f, 100.f, projectionMatrix);
    glUseProgram(SpriteShaderProgram);
    sendMatrix4ToShader("projectionMat", &projectionMatrix, SpriteShaderProgram);
    glUseProgram(TextShaderProgram);
    sendMatrix4ToShader("projection", &projectionMatrix, TextShaderProgram);

    printf("Press ESC to close window\n");

    /* Основной цикл */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        if (playerInfo.scene == MAIN_MENU_SCENES){
            renderMainMenu(window);
        }
        if (playerInfo.scene == ABOUT_AUTHORS_SCENES || playerInfo.scene == ABOUT_LORE_SCENES || playerInfo.scene == ABOUT_RULES_SCENES){
            renderAbout(window);
        }
        if(playerInfo.scene == NEW_LOAD_MENU_SCENES){
            renderNewLoadMenu(window);
        }
        if(playerInfo.scene == GAME_SETTING_MENU){
            renderGameSettingsMenu(window);
        }
        if (playerInfo.scene == RAFT_PLACEMENT_10_X_10_BASE){
            renderRaftPlacement10x10(window);
        }
        if (playerInfo.scene == RAFT_PLACEMENT_15_X_15_BASE){
            renderRaftPlacement15x15(window);
        }
        if (playerInfo.scene == RAFT_PLACEMENT_10_X_10_BOTS_FIGHT_BOT_1 || playerInfo.scene == RAFT_PLACEMENT_10_X_10_BOTS_FIGHT_BOT_2){
            renderRaftPlacement10x10BF(window);
        }
        if (playerInfo.scene == RAFT_PLACEMENT_15_X_15_BOTS_FIGHT_BOT_1 || playerInfo.scene == RAFT_PLACEMENT_15_X_15_BOTS_FIGHT_BOT_2){
            renderRaftPlacement15x15BF(window);
        }
        if (playerInfo.scene == MAIN_GAME_BASE_10_X_10){
            renderMainGameBase10x10(window);
        }
        if (playerInfo.scene == MAIN_GAME_BASE_15_X_15){
            renderMainGameBase15x15(window);
        }
        if (playerInfo.scene == MAIN_GAME_BOT_FIGHT_10_X_10){
            renderMainGameBotFight10x10(window);
        }
        if (playerInfo.scene == MAIN_GAME_BOT_FIGHT_15_X_15){
            renderMainGameBotFight15x15(window);
        }
        if (playerInfo.scene == ADDING_TO_THE_LEADERBOARD_SCENES){
            renderAddingNickName(window);
        }
        if (playerInfo.scene == LEADERS_SCENES){
            renderLeaders(window);
        }
        if (playerInfo.scene == SAVING_GAME_SCENES){
            renderGetSaveName(window);
        }
        if (playerInfo.scene == LOAD_GAME_SCENES){
            renderLoadingMenu(window);
        }
        
    
        /*Смен буферов*/
        glfwSwapBuffers(window);

        /*Проверка на события*/
        glfwPollEvents();
    }

    printf("Bye)\n");

    //Сохраняем текущую таблицу лидеров
    if (leaderBoard != NULL) updateLeaderBoard(PATH_TO_LEADERBOARD_DATA, leaderBoard);
    if (leaderBoard != NULL) freeLeaderBoard(leaderBoard);

    //Освобождаем память, выделенную под shipBase
    if (shipBase != NULL) freeShipBase(shipBase);
    if (botShipBase != NULL) freeShipBase(botShipBase);
    if (shipBaseBFBot1 != NULL) freeShipBase(shipBaseBFBot1);
    if (shipBaseBFBot2 != NULL) freeShipBase(shipBaseBFBot2);

    //Освобождаем память, выделенную под объекты на сценах
    freePiratesSprites();
    freeMainMenu();
    freeAbout();
    freeNewLoadMenu();
    freeGameSettingsMenu();
    freeRaftPlacement10x10();
    freeRaftPlacement15x15();
    freeRaftPlacement10x10BF();
    freeRaftPlacement15x15BF();
    freeMainGameBase10x10();
    freeMainGameBase15x15();
    freeMainGameBotFight10x10();
    freeMainGameBotFight15x15();
    freeAddingNickName();
    freeLeaders();
    freeGetSaveName();
    freeLoadingMenu();

    glfwTerminate();
    return EXIT_SUCCESS;
}

void glfwWindowSizeCallback(GLFWwindow* window, int width, int height)
{
    windowSizeX = width;
    windowSizeY = height;
    mat4 projectionMatrix;
    glm_ortho(0.f, windowSizeX, 0.f, windowSizeY, -100.f, 100.f, projectionMatrix);
    glUseProgram(SpriteShaderProgram);
    sendMatrix4ToShader("projectionMat", &projectionMatrix, SpriteShaderProgram);
    glUseProgram(TextShaderProgram);
    sendMatrix4ToShader("projection", &projectionMatrix, TextShaderProgram);
    glViewport(0, 0, windowSizeX, windowSizeY);
}

void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

void character_callback( GLFWwindow * window, unsigned  int codepoint)
{
    //printf("%c", codepoint);
}

void changeSpriteRotation(Sprite* sprite, GLfloat newRotate)
{
    sprite->rotate = newRotate;
}