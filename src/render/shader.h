#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SHADER_H
#define SHADER_H

#define READING_SHADER_ERROR 111111
#define MAX_LOG_SIZE 1024

const GLchar* readShaderFromFile(char* fileName);

GLuint MakeVertexShader(const GLchar* shaderText);

GLuint MakeFragmentShader(const GLchar* shaderText);

GLuint MakeShaderProgram(char* PathToVertex, char* PathToFragment);

#endif