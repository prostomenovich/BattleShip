#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <cglm/call.h>
#include <cglm/mat4.h>
#include "textures.h"
#include "renderUtils.h"
#include <stdarg.h>


#ifndef SPRITE_H
#define SPRITE_H

#define DATA_ARRAY_SIZE 12
#define FIRST_TEXTURE 1
#define SECOND_TEXTURE 2
#define THIRD_TEXTURE 3
#define FOURTH_TEXTURE 4

typedef struct Sprite
{
    GLuint VAO;
    GLuint vertCoordsVBO;
    GLuint texCoordsVBO;
    GLfloat sizeX;
    GLfloat sizeY;
    GLfloat positionX;
    GLfloat positionY;
    GLfloat rotate;
    GLuint Texture1;
    GLuint Texture2;
    GLuint Texture3;
    GLuint Texture4;

}Sprite;

Sprite* initSprite();

void setStartSpriteParams(Sprite* sprite, GLfloat spriteSizeX,
                                          GLfloat spriteSizeY,
                                          GLfloat spritePosX,
                                          GLfloat spritePosY,
                                          GLfloat spriteRotate);

void setSpriteTexture(Sprite* sprite, char* pathToTexture, GLenum filter, GLenum wrapMode, GLint textureNumber);

void renderSprite(Sprite* sprite, GLuint shaderProgram, GLint textureNumber);

void changeSpritePosX(Sprite* sprite, GLfloat newPosX);

void changeSpritePosY(Sprite* sprite, GLfloat newPosY);

void changeSpriteSize(Sprite* sprite, GLfloat newSizeX, GLfloat newSizeY);

void changeSpriteRotation(Sprite* sprite, GLfloat newRotate);

void fillTextureFieldsWithZeros(Sprite* sprite);

void freeSprite(Sprite* sprite);

#endif