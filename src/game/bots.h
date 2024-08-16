#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ShipBase.h"
#include "../scenes/defines.h"

#ifndef BOTS_H
#define BOTS_H

//for menium level bot
#define TOP_DOWN 0
#define DOWN_TOP 1

//Attack division
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

//Attack Status
#define ATTACK_PROCESS 1
#define ATTACK_END 2

typedef struct MediumLevelBotDataBase 
{



} MediumLevelBotDataBase;

int easyLevelBot(int* x, int* y, int map[18][18], int mapSize);

int mediumLevelBot(int* x, int* y, int map[18][18], int mapSize, int gameStatus);

int finishingOff(int x, int y, int map[18][18], ShipBase* shipBase, int AttackStatus, int MapSize);




#endif