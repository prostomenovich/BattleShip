#include "text.h"

#ifndef TEXT_C
#define TEXT_C

FT_Face* loadNewFace(FT_Library* ft_lib, const char* pathToFont)
{
    FT_Face* newFace = (FT_Face*)malloc(sizeof(FT_Face));
    if (newFace == NULL){
        printf("Error allocating memory for new font!\n");
        return NULL;
    }

    if (FT_New_Face(*ft_lib, pathToFont, 0, newFace)){
        printf("Failed to load font!\n");
        return NULL;
    }

    return newFace;
}

void setFaceSize(FT_Face face, GLuint height)
{
    FT_Set_Pixel_Sizes(face, 0, height);
}

Character** genCharactersArray(FT_Face face, FT_Library ft)
{
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    Character** charArray = (Character**) malloc(sizeof(Character*) * CHARACTERS_COUNT);
    for (int i = 0; i < CHARACTERS_COUNT; i++){
        charArray[i] = (Character*)malloc(sizeof(Character));
    }

    if (charArray == NULL){
        printf("Memory allocation error for character set!\n");
        return NULL;
    }

    for (int i = 0; i < CHARACTERS_COUNT; i++){
        if (FT_Load_Char(face, i, FT_LOAD_RENDER)){
            printf("FREETYPE: Failed to load Glyph!\n");
            continue;
        }

        GLuint textureID;
        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D,
                     0,
                     GL_RED,
                     face->glyph->bitmap.width,
                     face->glyph->bitmap.rows,
                     0,
                     GL_RED,
                     GL_UNSIGNED_BYTE,
                     face->glyph->bitmap.buffer);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        charArray[i]->TextureID = textureID;
        charArray[i]->width = face->glyph->bitmap.width;
        charArray[i]->rows = face->glyph->bitmap.rows;
        charArray[i]->left = face->glyph->bitmap_left;
        charArray[i]->top = face->glyph->bitmap_top;
        charArray[i]->advance = face->glyph->advance.x;
    }

    FT_Done_Face(face);
    FT_Done_FreeType(ft);

    return charArray;
}

Text* makeNewText(FT_Library* ft_lib, const char* pathToFont, GLuint height)
{
    FT_Face* newFace = loadNewFace(ft_lib, pathToFont);
    if (newFace == NULL) return NULL; 

    setFaceSize(*newFace, height);

    Character** charsArray = genCharactersArray(*newFace, *ft_lib);
    if (charsArray == NULL){
        free(newFace);
        return NULL;
    }

    Text* newText = (Text*)malloc(sizeof(Text));
    if (newText == NULL){
        printf("Error allocating memory for new text!\n");
        free(newFace);
        
        for (int i = 0; i < CHARACTERS_COUNT; i++){
            if (charsArray[i] != NULL) free(charsArray[i]);
        }
        free(charsArray);
        return NULL;
    }

    GLuint VBO, VAO;
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * COORDS_COUNT, NULL, GL_DYNAMIC_DRAW);

    glad_glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), NULL);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    newText->face = newFace;
    newText->VAO = VAO;
    newText->VBO = VBO;
    newText->charsArray = charsArray;

    return newText;
}

void renderText(Text* textParams,GLuint shaderProgram, const char* text, GLfloat x, GLfloat y, GLfloat scale, GLfloat red, GLfloat green, GLfloat blue)
{
    glUseProgram(shaderProgram);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glUniform3f(glGetUniformLocation(shaderProgram, "textColor"), red, green, blue);
    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(textParams->VAO);

    for (int i = 0; text[i] != '\0'; i++){
        Character* ch = textParams->charsArray[text[i]];

        GLfloat xpos = x + ch->left * scale;
        GLfloat ypos = y - (ch->rows - ch->top) * scale;

        GLfloat w = ch->width * scale;
        GLfloat h = ch->rows * scale;

        GLfloat vertices[6][4] = {
            {xpos, ypos + h, 0.0f, 0.0f},
            {xpos, ypos, 0.0f, 1.0f},
            {xpos + w, ypos, 1.0f, 1.0f},
            {xpos, ypos + h, 0.0f, 0.0f},
            {xpos + w, ypos, 1.0f, 1.0f},
            {xpos + w, ypos + h, 1.0f, 0.0f}
        };

        glBindTexture(GL_TEXTURE_2D, ch->TextureID);
        glBindBuffer(GL_ARRAY_BUFFER, textParams->VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * COORDS_COUNT, vertices);
        glBindBuffer(GL_ARRAY_BUFFER,0);

        glDrawArrays(GL_TRIANGLES, 0, 6);

        x += (ch->advance >> 6) * scale;
    }

    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
    glUseProgram(0);
}

void freeText(Text* textParams)
{
    glDeleteBuffers(1, &textParams->VAO);
    glDeleteVertexArrays(1, &textParams->VAO);

    for (int i = CHARACTERS_COUNT - 1; i >= 0; i--){
        glDeleteTextures(1, &textParams->charsArray[i]->TextureID);
        free(textParams->charsArray[i]);
    }

    free(textParams->charsArray);
    free(textParams->face);
}

#endif