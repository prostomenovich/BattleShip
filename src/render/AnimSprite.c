#include "AnimSprite.h"

#ifndef ANIMSPRITE_C
#define ANIMSPRITE_C

//Создание нового анимированного спрайта, возвращает указатель
AnimatedSprite* initAnimatedSprite()
{
    const GLfloat initVertexCoords[] = {
        //First Triangle
        //x    y
        0.0f, 0.0f,
        0.0f, 1.0f,
        1.0f, 1.0f,
        //Second Triangle
        1.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f
    };

    const GLfloat initTextureCoords[] = {
        //First Triangle
        //x    y
        0.0f, 0.0f,
        0.0f, 1.0f,
        1.0f, 1.0f,
        //Second Triangle
        1.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f
    };

    GLuint animSpriteVAO,
           animSpriteVertexCoordsVBO,
           animSpriteTextureCoordsVBO;
   
    AnimatedSprite* newAnimSprite = (AnimatedSprite*)malloc(sizeof(AnimatedSprite));
    if (newAnimSprite == NULL){
        printf("Error allocating memory for new sprite");
        return NULL;
    }

    glGenVertexArrays(1, &animSpriteVAO);
    glBindVertexArray(animSpriteVAO);


    glGenBuffers(1, &animSpriteVertexCoordsVBO);
    glBindBuffer(GL_ARRAY_BUFFER, animSpriteVertexCoordsVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * DATA_ARRAY_SIZE, initVertexCoords, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);

    glGenBuffers(1, &animSpriteTextureCoordsVBO);
    glBindBuffer(GL_ARRAY_BUFFER, animSpriteTextureCoordsVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * DATA_ARRAY_SIZE, initTextureCoords, GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);


    glBindBuffer(GL_ARRAY_BUFFER, 0);;
    glBindVertexArray(0);

    newAnimSprite->VAO = animSpriteVAO;
    newAnimSprite->vertCoordsVBO = animSpriteVertexCoordsVBO;
    newAnimSprite->texCoordsVBO = animSpriteTextureCoordsVBO;
    newAnimSprite->lastRenderTime= 0;

    return newAnimSprite;
}

//Устанавливает базовые параметры для нового анимированного спрайта
void setStartAnimSpriteParams(AnimatedSprite* animSprite, 
                              GLfloat animSpriteSizeX,
                              GLfloat animSpriteSizeY,
                              GLfloat animSpritePosX,
                              GLfloat animSpritePosY,
                              GLfloat animSpriteRotate)
{
    animSprite->sizeX = animSpriteSizeX;
    animSprite->sizeY = animSpriteSizeY;
    animSprite->positionX = animSpritePosX;
    animSprite->positionY = animSpritePosY;
    animSprite->rotate = animSpriteRotate;
}

//Позволяет загрузить кадры, которые будут повторяться во время проигрывания анимированного спрайта
void setAnimSpriteFrames(AnimatedSprite* animSprite, 
                         GLuint texturesCount, 
                         GLuint repeat, 
                         GLenum filter, 
                         GLenum wrapMode, ...)
{
    char* currentPathToTexture = NULL;
    GLuint TextureID;

    GLuint* framesBuffer = (GLuint*)malloc(sizeof(GLuint) * texturesCount);
    if (framesBuffer == NULL){
        printf("Error allocating memory for animated sprite framebuffer!\n");
        return;
    }

    va_list pathsToTextures;
    va_start(pathsToTextures, wrapMode);

    for (unsigned int i = 0; i < texturesCount; i++){
        currentPathToTexture = va_arg(pathsToTextures, char*);
        TextureID = MakeNewTexture(currentPathToTexture, filter, wrapMode);
        if (TextureID == MAKE_TEXTURE_ERROR){
            printf("Make Texture Error!\nPath to texture: %s\n", currentPathToTexture);
            free(framesBuffer);
        }

        framesBuffer[i] = TextureID;
    }
    va_end(pathsToTextures);

    animSprite->texturesCount = texturesCount;
    animSprite->state = ANIM_SPRITE_NOT_USED;
    animSprite->repeat = repeat;
    animSprite->frameBuffer = framesBuffer;
    animSprite->currentFrameIndex = -1;
}

//Отрисовка анимированного спрайта
void renderAnimSprite(AnimatedSprite* sprite, GLuint shaderProgram, time_t currentTime, double delay)
{   
    glUseProgram(shaderProgram);

    if (sprite->state == ANIM_SPRITE_NOT_USED){
        sprite->state = ANIM_SPRITE_IS_NOW_BEING_DISPLAYED;
    }

    GLuint delta = currentTime - sprite->lastRenderTime;
    
    mat4 modelMatrix = {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };

    vec3 position = {sprite->positionX, sprite->positionY, 1.0f};
    vec3 сenterСoordinatesTo = {0.5f * sprite->sizeX, 0.5f * sprite->sizeY, 0.0f};
    vec3 сenterСoordinatesBack = {-0.5f * sprite->sizeX, -0.5f * sprite->sizeY, 0.0f};
    vec3 setSize = {sprite->sizeX, sprite->sizeY, 1.0f};
    float axis[] = {0.0f, 0.0f, 1.0f};

    glm_translate(modelMatrix, position);
    glm_translate(modelMatrix, сenterСoordinatesTo);
    glm_rotate(modelMatrix, glm_rad(sprite->rotate), axis);
    glm_translate(modelMatrix, сenterСoordinatesBack);
    glm_scale(modelMatrix, setSize);
        
    glBindVertexArray(sprite->VAO);
        
    sendMatrix4ToShader("modelMat", &modelMatrix, shaderProgram);

    glActiveTexture(GL_TEXTURE0);

    if (fabs(delta) >= delay && sprite->repeat != ANIM_SPRITE_DRAWN){
        if (sprite->repeat == REPEAT_TRUE && sprite->currentFrameIndex == sprite->texturesCount - 1){
            sprite->currentFrameIndex = -1;
        }
        sprite->currentFrameIndex += 1;

        sprite->lastRenderTime = currentTime;
    }

    if (sprite->state == ANIM_SPRITE_IS_NOW_BEING_DISPLAYED && sprite->currentFrameIndex == sprite->texturesCount){
        if (sprite->repeat == REPEAT_FALSE){
            sprite->state = ANIM_SPRITE_DRAWN;
        }
    }
    
    if (sprite->state == ANIM_SPRITE_DRAWN){
        BindTexture(sprite->frameBuffer[sprite->texturesCount - 1]);
    }
    else {
        BindTexture(sprite->frameBuffer[sprite->currentFrameIndex]);
    }

    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
    glUseProgram(0);
}

//Изменение размера анимированного спрайта
void changeAnimSpriteSize(AnimatedSprite* sprite, GLfloat newSizeX, GLfloat newSizeY)
{
    sprite->sizeX = newSizeX;
    sprite->sizeY = newSizeY;
}

//Освобождает память, которую выделели под анимированный спрайт
void freeAnimSprite(AnimatedSprite* animSprite)
{
    glDeleteBuffers(1, &animSprite->texCoordsVBO);
    glDeleteBuffers(1, &animSprite->vertCoordsVBO);
    glDeleteVertexArrays(1, &animSprite->VAO);

    for (int i = 0; i < animSprite->texturesCount; i++){
        glDeleteTextures(1, &animSprite->frameBuffer[i]);
    }

    free(animSprite->frameBuffer);
    free(animSprite);
}

#endif