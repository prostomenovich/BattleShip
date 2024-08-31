#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include "../render/text.h"
#include "../render/sprite.h"
#include "../render/AnimSprite.h"
#include "scenesInitial.h"

#ifndef FREESCENES_H
#define FREESCENES_H

void freeMainMenu(void);

void freeAbout(void);

void freeGameSettingsMenu(void);

void freeRaftPlacement10x10(void);

void freeRaftPlacement15x15(void);

void freeRaftPlacement10x10BF(void);

void freeRaftPlacement15x15BF(void);

void freeMainGameBase10x10(void);

void freePiratesSprites(void);

void freeMainGameBase15x15(void);

void freeMainGameBotFight10x10(void);

void freeMainGameBotFight15x15(void);

void freeAddingNickName(void);

void freeLeaders(void);

void freeGetSaveName(void);

void freeLoadingMenu(void);

void freeNewLoadMenu(void);

#endif