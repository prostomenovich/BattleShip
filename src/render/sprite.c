#include "sprite.h"

#ifndef SPRITE_C
#define SPRITE_C

void fillTextureFieldsWithZeros(Sprite* sprite)
{
    sprite->Texture1 = 0;
    sprite->Texture2 = 0;
    sprite->Texture3 = 0;
    sprite->Texture4 = 0;
}

Sprite* initSprite()
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

    GLuint spriteVAO,
           spriteVertexCoordsVBO,
           spriteTextureCoordsVBO;
   
    Sprite* newSprite = (Sprite*)malloc(sizeof(Sprite));
    if (newSprite == NULL){
        printf("Error allocating memory for new sprite");
        return NULL;
    }
    fillTextureFieldsWithZeros(newSprite);

    glGenVertexArrays(1, &spriteVAO);
    glBindVertexArray(spriteVAO);


    glGenBuffers(1, &spriteVertexCoordsVBO);
    glBindBuffer(GL_ARRAY_BUFFER, spriteVertexCoordsVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * DATA_ARRAY_SIZE, initVertexCoords, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);

    glGenBuffers(1, &spriteTextureCoordsVBO);
    glBindBuffer(GL_ARRAY_BUFFER, spriteTextureCoordsVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * DATA_ARRAY_SIZE, initTextureCoords, GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);


    glBindBuffer(GL_ARRAY_BUFFER, 0);;
    glBindVertexArray(0);

    newSprite->VAO = spriteVAO;
    newSprite->vertCoordsVBO = spriteVertexCoordsVBO;
    newSprite->texCoordsVBO = spriteTextureCoordsVBO;

    return newSprite;
}

void setStartSpriteParams(Sprite* sprite, GLfloat spriteSizeX,
                                          GLfloat spriteSizeY,
                                          GLfloat spritePosX,
                                          GLfloat spritePosY,
                                          GLfloat spriteRotate)
{
    sprite->sizeX = spriteSizeX;
    sprite->sizeY = spriteSizeY;
    sprite->positionX = spritePosX;
    sprite->positionY = spritePosY;
    sprite->rotate = spriteRotate;
}

void setSpriteTexture(Sprite* sprite, char* pathToTexture, GLenum filter, GLenum wrapMode,GLint textureNumber)
{
    GLuint spriteTexture;

    spriteTexture = MakeNewTexture(pathToTexture, filter, wrapMode);

    switch (textureNumber)
    {
    case FIRST_TEXTURE:
        sprite->Texture1 = spriteTexture;
        break;
    case SECOND_TEXTURE:
        sprite->Texture2 = spriteTexture;
        break;
    case THIRD_TEXTURE:
        sprite->Texture3 = spriteTexture;
        break;
    case FOURTH_TEXTURE:
        sprite->Texture4 = spriteTexture;
        break;    
    default:
        sprite->Texture1 = spriteTexture;
        break;
    } 
}

void renderSprite(Sprite* sprite, GLuint shaderProgram, GLint textureNumber)
{
    glUseProgram(shaderProgram);
    
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
    switch (textureNumber)
    {
    case FIRST_TEXTURE:
        BindTexture(sprite->Texture1);
        break;
    case SECOND_TEXTURE:
        BindTexture(sprite->Texture2);
        break;
    case THIRD_TEXTURE:
        BindTexture(sprite->Texture3);
        break;
    case FOURTH_TEXTURE:
        BindTexture(sprite->Texture4);
        break;    
    default:
        BindTexture(sprite->Texture1);
        break;
    } 

    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
    glUseProgram(0);
}

void changeSpritePosX(Sprite* sprite, GLfloat newPosX)
{
    sprite->positionX = newPosX;
}

void changeSpritePosY(Sprite* sprite, GLfloat newPosY)
{
    sprite->positionX = newPosY;
}

void changeSpriteSize(Sprite* sprite, GLfloat newSizeX, GLfloat newSizeY)
{
    sprite->sizeX = newSizeX;
    sprite->sizeY = newSizeY;
}

void freeSprite(Sprite* sprite)
{
    if (sprite->Texture1 != 0){
        glDeleteTextures(1, &sprite->Texture1);
    }
    if (sprite->Texture2 != 0){
        glDeleteTextures(1, &sprite->Texture2);
    }
    if (sprite->Texture3 != 0){
        glDeleteTextures(1, &sprite->Texture3);
    }
    if (sprite->Texture4 != 0){
        glDeleteTextures(1, &sprite->Texture4);
    }

    glDeleteBuffers(1, &sprite->vertCoordsVBO);
    glDeleteBuffers(1, &sprite->texCoordsVBO);
    glDeleteVertexArrays(1, &sprite->VAO);

    free(sprite);
}
#endif
