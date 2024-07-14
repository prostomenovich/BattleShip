#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../external/stb_image.h"
#include <cglm/mat4.h>
#include <cglm/types.h>
#include "renderUtils.h"


#ifndef TEXTURES_H
#define TEXTURES_H

#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PNG

#define MAKE_TEXTURE_ERROR 5555

void printTextureInfo(GLuint* width, GLuint* height, GLuint* channels);

unsigned char* loadTextureFromFile(char* PathToTexture, GLuint* width, GLuint* height, GLuint* channels);

GLuint NewTexture(GLuint width, 
                      GLuint height, 
                      unsigned char* texturePixels, 
                      GLuint channels, 
                      GLenum filter, 
                      GLenum wrapMode);


GLuint MakeNewTexture(char* pathToTexture, GLenum filter, GLenum wrapMode);

void BindTexture(GLuint TextureID);

#endif