#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <cglm/mat4.h>
#include <cglm/call.h>

#ifndef RENDERUTILS_H
#define RENDERUTILS_H

void sendTextureToShader(char* name, GLint value, GLuint textureID);

void sendMatrix4ToShader(char* name, mat4* matrix, GLuint textureID);

#endif