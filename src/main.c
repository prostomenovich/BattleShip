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

int windowSizeX = 1280;
int windowSizeY = 720;


GLuint SpriteShaderProgram;
GLuint TextShaderProgram;

FT_Library ft;


void glfwWindowSizeCallback(GLFWwindow* window, int width, int height);
void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
void character_callback( GLFWwindow * window, unsigned  int codepoint);

int main(void)
{   
    extern GLuint SpriteShaderProgram;
    extern GLuint TextShaderProgram;

    extern Player playerInfo;

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()){
        printf("Error initializing GLFW!\n");
        return EXIT_FAILURE;
    }
    
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    //Setting an OpenGL context
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //Creating a Window
    window = glfwCreateWindow(windowSizeX, windowSizeY, "BattleShip", NULL, NULL);

    glfwSetWindowAttrib(window, GLFW_RESIZABLE, GLFW_FALSE);
    glfwSetWindowSizeLimits(window, 1280, 720, 1280, 720);

    //Callbacks
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

    if (FT_Init_FreeType(&ft)){
        printf("ERROR::FREETYPE: Could not init FreeType Library\n");
    }



    SpriteShaderProgram = MakeShaderProgram("../resources/shaders/SpriteVertex.glsl",
                                            "../resources/shaders/SpriteFragment.glsl");
    TextShaderProgram = MakeShaderProgram("../resources/shaders/textVertex.glsl",
                                            "../resources/shaders/textFragment.glsl");

    initMainMenu();
    initAbout();
    initNewLoadMenu();
    initGameSettingsMenu();
    initRaftPlacement10x10();
    initRaftPlacement15x15();

	glClearColor(0, 1, 0, 1);
    
    mat4 projectionMatrix;
    glm_ortho(0.f, windowSizeX, 0.f, windowSizeY, -100.f, 100.f, projectionMatrix);
    glUseProgram(SpriteShaderProgram);
    sendMatrix4ToShader("projectionMat", &projectionMatrix, SpriteShaderProgram);
    glUseProgram(TextShaderProgram);
    sendMatrix4ToShader("projection", &projectionMatrix, TextShaderProgram);

    /* Loop until the user closes the window */
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
        if (playerInfo.scene == RAFT_PLACEMENT_10_X_10){
            renderRaftPlacement10x10(window);
        }
        if (playerInfo.scene == RAFT_PLACEMENT_15_X_15){
            renderRaftPlacement15x15(window);
        }
        
    
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

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
    printf("%c", codepoint);
}

void changeSpriteRotation(Sprite* sprite, GLfloat newRotate)
{
    sprite->rotate = newRotate;
}