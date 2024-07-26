#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "render/shader.h"
#include "render/renderUtils.h"
#include "render/sprite.h"
#include "render/AnimSprite.h"
#include "render/text.h"
#include <cglm/mat4.h>
#include <cglm/call.h>
#include <ft2build.h>
#include FT_FREETYPE_H

int windowSizeX = 1280;
int windowSizeY = 720;

void glfwWindowSizeCallback(GLFWwindow* window, int width, int height);
void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);

int main(void)
{
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

    FT_Library ft;
    if (FT_Init_FreeType(&ft)){
        printf("ERROR::FREETYPE: Could not init FreeType Library\n");
    }

    Text* textParams = makeNewText(&ft, "../resources/fonts/UnformitalRegula.ttf", 48);



	glClearColor(0, 1, 0, 1);

    GLuint shaderProg = MakeShaderProgram("../resources/shaders/SpriteVertex.glsl", "../resources/shaders/SpriteFragment.glsl");
    //glUseProgram(shaderProg);
    GLuint TextShaderProg = MakeShaderProgram("../resources/shaders/textVertex.glsl", "../resources/shaders/textFragment.glsl");
    
    Sprite* sp = initSprite();
    setSpriteTexture(sp, "../resources/textures/3.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setStartSpriteParams(sp, 800, 708, 10, 10, 0);
    Sprite* sp1 = initSprite();
    setSpriteTexture(sp1, "../resources/textures/2.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setStartSpriteParams(sp1, 600, 600, 600, 100, 0);

    AnimatedSprite* monks = initAnimatedSprite();
    setStartAnimSpriteParams(monks, 200, 200, 560, 560, 0);
    setAnimSpriteFrames(monks, 3, REPEAT_TRUE, GL_NEAREST, GL_CLAMP_TO_EDGE,
                        "../resources/textures/krest_1.png", 
                        "../resources/textures/krest_2.png",
                        "../resources/textures/krest_3.png");




    mat4 projectionMatrix;
    glm_ortho(0.f, windowSizeX, 0.f, windowSizeY, -100.f, 100.f, projectionMatrix);
    glUseProgram(shaderProg);
    sendMatrix4ToShader("projectionMat", &projectionMatrix, shaderProg);
    glUseProgram(TextShaderProg);
    sendMatrix4ToShader("projection", &projectionMatrix, TextShaderProg);

    glUseProgram(shaderProg);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS){
            sp->rotate += 1.;
            sp1->rotate -= 1.;
        }
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS){
            sp->rotate -= 1.;
            sp1->rotate += 1.;
        }
        
        renderSprite(sp1, shaderProg, FIRST_TEXTURE);
        renderSprite(sp, shaderProg, FIRST_TEXTURE);
        renderAnimSprite(monks, shaderProg, time(NULL), 1.0);
        renderText(textParams, TextShaderProg, "Hello izyan", 200.f, 250.f, 4.0f, 1.0f, 0.0f, 0.0f);
        renderText(textParams, TextShaderProg, "Penis", 1000.f, 100.f, 1.0f, 0.0f, 0.0f, 1.0f);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    freeAnimSprite(monks);
    freeSprite(sp1);
    freeSprite(sp);
    freeText(textParams);

    glfwTerminate();
    return EXIT_SUCCESS;
}

void glfwWindowSizeCallback(GLFWwindow* window, int width, int height)
{
    windowSizeX = width;
    windowSizeY = height;
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