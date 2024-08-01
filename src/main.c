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
    
    //Setting an OpenGL context
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //Creating a Window
    window = glfwCreateWindow(windowSizeX, windowSizeY, "BattleShip", NULL, NULL);

    //Callbacks
    glfwSetWindowSizeCallback(window, glfwWindowSizeCallback);
    glfwSetKeyCallback(window, glfwKeyCallback);

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

    //Text* textParams = makeNewText(&ft, "../resources/fonts/UnformitalRegula.ttf", 48);


    SpriteShaderProgram = MakeShaderProgram("../resources/shaders/SpriteVertex.glsl",
                                            "../resources/shaders/SpriteFragment.glsl");
    TextShaderProgram = MakeShaderProgram("../resources/shaders/textVertex.glsl",
                                            "../resources/shaders/textFragment.glsl");

    initMainMenu();
    initAbout();
    initNewLoadMenu();

	glClearColor(0, 1, 0, 1);
    
    Sprite* sp = initSprite();
    setSpriteTexture(sp, "../resources/textures/3.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setStartSpriteParams(sp, 800, 708, 10, 10, 0);
    Sprite* sp1 = initSprite();
    setSpriteTexture(sp1, "../resources/textures/2.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setStartSpriteParams(sp1, 600, 600, 600, 100, 0);

    /*AnimatedSprite* mainMenuBackground = initAnimatedSprite();
    setStartAnimSpriteParams(mainMenuBackground, 1280, 720, 0, 0, 0);
    setAnimSpriteFrames(mainMenuBackground, 4, REPEAT_TRUE, GL_NEAREST, GL_CLAMP_TO_EDGE,
                        "../resources/textures/mainMenu/background/mainMenuBackgroundFrame1.png",
                        "../resources/textures/mainMenu/background/mainMenuBackgroundFrame2.png",
                        "../resources/textures/mainMenu/background/mainMenuBackgroundFrame3.png",
                        "../resources/textures/mainMenu/background/mainMenuBackgroundFrame4.png");
    */
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
        
        if (playerInfo.state == MAIN_MENU_SCENES){
            renderMainMenu(window);
        }
        if (playerInfo.state == ABOUT_AUTHORS_SCENES || playerInfo.state == ABOUT_LORE_SCENES || playerInfo.state == ABOUT_RULES_SCENES){
            renderAbout(window);
        }
        if(playerInfo.state == NEW_LOAD_MENU_SCENES){
            renderNewLoadMenu(window);
        }
        
        
        //renderSprite(sp1, shaderProg, FIRST_TEXTURE);
        //renderSprite(sp, shaderProg, FIRST_TEXTURE);
        //renderAnimSprite(mainMenuBackground, shaderProg, time(NULL), 1.0);
        //renderText(textParams, TextShaderProg, "Hello izyan", 200.f, 250.f, 4.0f, 1.0f, 0.0f, 0.0f);
        //renderText(textParams, TextShaderProg, "Penis", 1000.f, 100.f, 1.0f, 0.0f, 0.0f, 1.0f);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    //freeAnimSprite(mainMenuBackground);
    freeSprite(sp1);
    freeSprite(sp);
    //freeText(textParams);

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

void changeSpriteRotation(Sprite* sprite, GLfloat newRotate)
{
    sprite->rotate = newRotate;
}