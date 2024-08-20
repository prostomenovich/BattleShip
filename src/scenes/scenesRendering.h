#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../render/sprite.h"
#include "../render/AnimSprite.h"
#include "../render/text.h"
#include "scenesInitial.h"
#include "processingUtils.h"
#include "../game/ShipBase.h"
#include "otherScenesUtils.h"
#include "defines.h"
#include "../game/bots.h"


#ifndef SCENESRENDERING_H
#define SCENESRENDERING_H

void renderMainMenu(GLFWwindow* window);

void renderAbout(GLFWwindow* window);

void renderNewLoadMenu(GLFWwindow* window);

void renderGameSettingsMenu(GLFWwindow* window);

void renderRaftPlacement10x10(GLFWwindow* window);

void renderRaftPlacement15x15(GLFWwindow* window);

void renderRaftPlacement10x10BF(GLFWwindow* window);

void renderRaftPlacement15x15BF(GLFWwindow* window);

void renderMainGameBase10x10(GLFWwindow* window);

void renderMainGameBase15x15(GLFWwindow* window);

#endif