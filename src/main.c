#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "render/shader.h"
#include "render/textures.h"
#include "../external/stb_image.h"

GLfloat points[] = {
    -0.5f, -0.5f, 0.0f,
    -0.5f, 0.5f, 0.0f,
    0.5f,  0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.5f, 0.5f, 0.0f,
};

GLfloat colors[] = {
    0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    1.0f, 1.0f, 1.0f,
    0.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 0.0f,
    1.0f, 1.0f, 1.0f
};

GLfloat textureCoords[] = {
    0.0f, 0.0f,
    0.0f, 1.0f,
    1.0f, 1.0f,
    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f,
};

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

    //const GLchar* text = readShaderFromFile("../src/render/baseVertex.glsl");
    //printf("%s\n", text);
    //free((GLchar*)text);
    

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

    GLuint pointsVBO = 0;

    glGenBuffers(1, &pointsVBO);
    glBindBuffer(GL_ARRAY_BUFFER, pointsVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 3, points, GL_STATIC_DRAW);

    GLuint colorsVBO = 0;

    glGenBuffers(1, &colorsVBO);
    glBindBuffer(GL_ARRAY_BUFFER, colorsVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 3, colors, GL_STATIC_DRAW);

    GLuint texCoordsVBO = 0;

    glGenBuffers(1, &texCoordsVBO);
    glBindBuffer(GL_ARRAY_BUFFER, texCoordsVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 2 * 6, textureCoords, GL_STATIC_DRAW);

    GLuint VAO = 0;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    
    glBindBuffer(GL_ARRAY_BUFFER, pointsVBO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    glBindBuffer(GL_ARRAY_BUFFER, colorsVBO);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, texCoordsVBO);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(2);

    GLuint shaderProg = MakeShaderProgram("../resources/shaders/TextureVertex.glsl", "../resources/shaders/TextureFragment.glsl");
    glUseProgram(shaderProg); 

    GLuint TexID1 = MakeNewTexture("../resources/textures/1.png", GL_NEAREST, GL_CLAMP_TO_EDGE);
    GLuint TexID2 = MakeNewTexture("../resources/textures/2.png", GL_NEAREST, GL_CLAMP_TO_EDGE);

    setInt("tex", 0, TexID1);  
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        

        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS){
            BindTexture(TexID1);
        }
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS){
            BindTexture(TexID2);
        }

        glDrawArrays(GL_TRIANGLES, 0, 6);

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
    glViewport(0, 0, windowSizeX, windowSizeY); 
}

void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}