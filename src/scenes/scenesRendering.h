#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "../render/sprite.h"
#include "../render/AnimSprite.h"
#include "../render/text.h"
#include "scenesInitial.h"
#include "processingUtils.h"
#include "../game/ShipBase.h"


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

#endif