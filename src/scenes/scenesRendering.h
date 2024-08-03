#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "../render/sprite.h"
#include "../render/AnimSprite.h"
#include "../render/text.h"
#include "scenesInitial.h"
#include "processingUtils.h"


#ifndef SCENESRENDERING_H
#define SCENESRENDERING_H

void renderMainMenu(GLFWwindow* window);

void renderAbout(GLFWwindow* window);

void renderNewLoadMenu(GLFWwindow* window);

void renderGameSettingsMenu(GLFWwindow* window);

#endif