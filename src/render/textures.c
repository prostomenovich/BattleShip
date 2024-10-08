#include "textures.h"

#ifndef TEXTURES_C
#define TEXTURES_C
#include "../../external/stb_image.h"

//Выводит информацию о загруженной текстуре (вспомогательная функция)
void printTextureInfo(GLuint* width, GLuint* height, GLuint* channels)
{
    printf("---Image info---\n");
    printf("Width: %d\n", *width);
    printf("Height: %d\n", *height);
    printf("Channels: %d\n", *channels);
}

/*
    Загружает текстуру из файла
    Записывает значения ширины, высоты и количества каналов по указанным адресам
    Возвращает указатель на массив прочитанных пикселей
*/
unsigned char* loadTextureFromFile(char* PathToTexture, GLuint* width, GLuint* height, GLuint* channels)
{
    stbi_set_flip_vertically_on_load(true);
    unsigned char* texturePixels = stbi_load((const char*)PathToTexture, width, height, channels, 0);
    if (texturePixels == NULL){
        printf("Load image error!\nPath: %s\n", PathToTexture);
        return NULL; 
    }
    //printTextureInfo(width, height, channels);

    return texturePixels;
}

//Создаёт новую текстуру, возвращает её идентификатор
GLuint NewTexture(GLuint width, GLuint height, unsigned char* texturePixels, GLuint channels, GLenum filter, GLenum wrapMode)
{
    GLuint TextureID;
    GLuint channelCountMode = 0;

    glGenTextures(1, &TextureID);
    glBindTexture(GL_TEXTURE_2D, TextureID);
    
    switch (channels)
    {
    case 3:
        channelCountMode = GL_RGB;
        break;
    
    case 4:
        channelCountMode = GL_RGBA;
        break;
    default:
        channelCountMode = GL_RGB;
        break;
    }

    glTexImage2D(GL_TEXTURE_2D, 0, channelCountMode, width, height, 0, channelCountMode, GL_UNSIGNED_BYTE, texturePixels);
    glActiveTexture(GL_TEXTURE0);

    //Wrap_S и Wrap_T эквивалетны осям X и Y
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
    glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, 0);

    stbi_image_free(texturePixels);

    return TextureID;
}


//Создаёт текстуру, возвращает её идентификатор
//На ввход получает путь до текстуры, filter и wrapMode
GLuint MakeNewTexture(char* pathToTexture, GLenum filter, GLenum wrapMode)
{
    GLuint width = 0,
           height = 0,
           channels = 0,
           newTex = 0;

    unsigned char* texturePixels = loadTextureFromFile(pathToTexture, &width, &height, &channels);
    if (texturePixels == NULL){
        return MAKE_TEXTURE_ERROR;
    }

    newTex = NewTexture(width, height, texturePixels, channels, filter, wrapMode);

    return newTex;
}

//Биндит необходимую текстуру, получает на вход её идентификатор
void BindTexture(GLuint TextureID)
{
    sendTextureToShader("tex", 0, TextureID);
    glBindTexture(GL_TEXTURE_2D, TextureID);
}

#endif