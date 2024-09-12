#include "shader.h"

#ifndef SHADER_C
#define SHADER_C

//Считывает текст шейдера из указанного файла
//Возвращает строку с текстом шейдера
const GLchar* readShaderFromFile(char* fileName)
{
    FILE* SHADERFILE = fopen(fileName, "r");
    GLchar* shaderText = NULL;
    int fileSize = 0;
    GLchar symb = '\0';

    if (SHADERFILE == NULL){
        printf("Failed to open shader file!\n");
        return NULL;
    }

    fseek(SHADERFILE, 0, SEEK_END);
    fileSize = ftell(SHADERFILE);
    rewind(SHADERFILE);

    shaderText = (GLchar*)malloc((sizeof(GLchar) * fileSize) + sizeof(GLchar) * 10);
    if (shaderText == NULL){
        printf("Memory allocation error for shader text!\n");
        fclose(SHADERFILE);
        return NULL;
    }

    memset(shaderText, '\0', fileSize + 10);

    symb = getc(SHADERFILE);
    for (int i = 0; symb != EOF; i++){
        shaderText[i] = symb;
        symb = getc(SHADERFILE);
    }

    if (shaderText[strlen(shaderText) - 1] == '\n'){
        for (int i = strlen(shaderText) - 1; shaderText[i] == '\n'; i--){
            shaderText[i] = '\0';
        }
    }

    fclose(SHADERFILE);
    return (const GLchar*)shaderText;

}

//Создаёт вершинный шейдер, возвращает его идентификатор
GLuint MakeVertexShader(const GLchar* shaderText)
{
	GLint ErrorCheck;

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &shaderText, NULL);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &ErrorCheck); 
	if (ErrorCheck == 0)
	{
        char ErrorLog[MAX_LOG_SIZE + 1] = {'\0',};
		glGetShaderInfoLog(vertexShader, MAX_LOG_SIZE,NULL ,ErrorLog); 
		printf("VertexShader compile error!\n %s", ErrorLog);
		glfwTerminate();
		return COMPILE_SHADER_ERROR;
	}

    return vertexShader;
}

//Создаёт фрагментный шейдер, возвращает его идентификатор
GLuint MakeFragmentShader(const GLchar* shaderText)
{
    GLint ErrorCheck;

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &shaderText, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &ErrorCheck); 
	if (ErrorCheck == 0)
	{
        char ErrorLog[MAX_LOG_SIZE + 1] = {'\0',};
		glGetShaderInfoLog(fragmentShader, MAX_LOG_SIZE, NULL ,ErrorLog); 
		printf("FragmentShader compile error!\n %s", ErrorLog);
		glfwTerminate();
		return COMPILE_SHADER_ERROR;
	}

    return fragmentShader;
}

//Создаёт шейдерную программу, возвращает её идентификатор
//В качестве аргументов передаются пути до фрагментного и вертексного шейдеров
GLuint MakeShaderProgram(char* PathToVertex, char* PathToFragment)
{
    const GLchar* vertexShaderText = readShaderFromFile(PathToVertex);
    const GLchar* fragmentShaderText = readShaderFromFile(PathToFragment);
    
    if (vertexShaderText == NULL || fragmentShaderText == NULL){
        if (vertexShaderText != NULL) free((GLchar*)vertexShaderText);
        if (fragmentShaderText != NULL) free((GLchar*)fragmentShaderText);

        return READING_SHADER_ERROR;
    }

    GLuint vertexShader = MakeVertexShader(vertexShaderText);
    GLuint fragmentShader = MakeFragmentShader(fragmentShaderText);

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    free((GLchar*)vertexShaderText);
    free((GLchar*)fragmentShaderText);

    return shaderProgram;
}

#endif