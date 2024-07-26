#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#include <ft2build.h>
#include FT_FREETYPE_H

#ifndef TEXT_H
#define TEXT_H

#define CHARACTERS_COUNT 128
#define COORDS_COUNT 24

typedef struct Character
{
    GLuint TextureID; //ID текстуры глифа
    GLuint width; //Размер глифа по Х
    GLuint rows; //Размер глифа по Y
    GLuint left; //смещение верхней левой точки глифа по X
    GLuint top; //смещение верхней левой точки глифа по Y
    GLuint advance; //горизонтальное смещение до начала следующего глифа

} Character;

typedef struct Text
{
    FT_Face* face;
    GLuint VBO;
    GLuint VAO;
    Character** charsArray;
    
} Text;


FT_Face* loadNewFace(FT_Library* ft_lib, const char* pathToFont);

void setFaceSize(FT_Face face, GLuint height);

Character** genCharactersArray(FT_Face face, FT_Library ft);

Text* makeNewText(FT_Library* ft_lib, const char* pathToFont, GLuint height);

void renderText(Text* textParams,GLuint shaderProgram, const char* text, GLfloat x, GLfloat y, GLfloat scale, GLfloat red, GLfloat green, GLfloat blue);

void freeText(Text* textParams);

#endif