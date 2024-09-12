#include "renderUtils.h"

#ifndef RENDERUTILS_C
#define RENDERUTILS_C

//Передаёт в шейдер идентификатор текстуры
void sendTextureToShader(char* name, GLint value, GLuint textureID)
{
    glUniform1i(glGetUniformLocation(textureID, name), value);
}

//Передаёт в шейдер матрицу
void sendMatrix4ToShader(char* name, mat4* matrix, GLuint textureID)
{
    glUniformMatrix4fv(glGetUniformLocation(textureID, name), 1, GL_FALSE, (const float*)matrix);
}

#endif