#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <cglm/call.h>
#include <cglm/mat4.h>
#include <stdarg.h>
#include <time.h>
#include <math.h>
#include "textures.h"
#include "renderUtils.h"

#ifndef ANIMSPRITE_H
#define ANIMSPRITE_H

#define ANIM_SPRITE_NOT_USED 1
#define ANIM_SPRITE_IS_NOW_BEING_DISPLAYED 2
#define ANIM_SPRITE_DRAWN 3

#define REPEAT_TRUE 4
#define REPEAT_FALSE 5

#define DATA_ARRAY_SIZE 12

typedef struct AnimatedSprite
{
    GLuint VAO;
    GLuint vertCoordsVBO;
    GLuint texCoordsVBO;
    GLfloat sizeX;
    GLfloat sizeY;
    GLfloat positionX;
    GLfloat positionY;
    GLfloat rotate;
    GLuint state;
    GLuint texturesCount;
    GLuint repeat;
    GLint currentFrameIndex;
    GLuint* frameBuffer;
    GLuint lastRenderTime;

}AnimatedSprite;

AnimatedSprite* initAnimatedSprite();

void setStartAnimSpriteParams(AnimatedSprite* animSprite, 
                              GLfloat animSpriteSizeX,
                              GLfloat animSpriteSizeY,
                              GLfloat animSpritePosX,
                              GLfloat animSpritePosY,
                              GLfloat animSpriteRotate);


void setAnimSpriteFrames(AnimatedSprite* animSprite, 
                         GLuint texturesCount, 
                         GLuint repeat, 
                         GLenum filter, 
                         GLenum wrapMode, ...);  

void renderAnimSprite(AnimatedSprite* sprite, GLuint shaderProgram, time_t currentTime, double delay);

void freeAnimSprite(AnimatedSprite* animSprite);

void changeAnimSpriteSize(AnimatedSprite* sprite, GLfloat newSizeX, GLfloat newSizeY);

#endif
