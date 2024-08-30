#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "ShipBase.h"
#include "../scenes/scenesInitial.h"

#ifndef SAVELOAD_H
#define SAVELOAD_H

#define SAVE_SUCCESS 52
#define SAVE_ERROR 55

#define LOAD_SUCCESS 61
#define LOAD_ERROR 62

#define MAX_SAVE_NAMES 100

#define DELETE_SUCCESS 222
#define DELETE_ERROR 223


int saveGame(char* pathToFolder, 
             char* saveName, 
             int mode, 
             int mapSize, 
             int botLevel, 
             int sceneState, 
             int score1,
             int score2,
             int map1[18][18], 
             int map2[18][18], 
             ShipBase* shipBase1, 
             ShipBase* shipBase2);

int loadGame(char* pathToFolder, char* saveName);

SaveNamesList* getSaveNames(char* pathToFolder);

void freeSaveNames(SaveNamesList* list);

int delSave(char* pathToFolder, char* saveName);

#endif