#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "render/shader.h"
#include "render/textures.h"
#include "render/renderUtils.h"
#include "render/sprite.h"
#include <cglm/mat4.h>
#include <cglm/call.h>

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

	glClearColor(0, 1, 0, 1);

    GLuint shaderProg = MakeShaderProgram("../resources/shaders/SpriteVertex.glsl", "../resources/shaders/SpriteFragment.glsl");
    glUseProgram(shaderProg); 

    Sprite* sp = initSprite();
    setSpriteTexture(sp, "../resources/textures/3.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setStartSpriteParams(sp, 800, 708, 100, 10, 0);
    Sprite* sp1 = initSprite();
    setSpriteTexture(sp1, "../resources/textures/2.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setStartSpriteParams(sp1, 100, 100, 1000, 290, 0);

    mat4 projectionMatrix;
    glm_ortho(0.f, windowSizeX, 0.f, windowSizeY, -100.f, 100.f, projectionMatrix);
    sendMatrix4ToShader("projectionMat", &projectionMatrix, shaderProg);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS){
            sp->rotate = sp->rotate += 1.;
        }
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS){
            //renderSprite(sp, shaderProg, SECOND_TEXTURE);
            sp->rotate = sp->rotate -= 1.;
        }
        renderSprite(sp, shaderProg, FIRST_TEXTURE);
        renderSprite(sp1, shaderProg, FIRST_TEXTURE);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    freeSprite(sp1);
    freeSprite(sp);

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