#include "stdlib.h"
#include "../game/ShipBase.h"
#include "../scenes/scenesInitial.h"

#ifndef OTHERSCENESUTILS_H
#define OTHERSCENESUTILS_H

void fillShipsTextures10x10(MapSprite SpriteArray[10][10], ShipBase* shipBase, int map[18][18], int turn);

void fillShipsTextures15x15(MapSprite SpriteArray[15][15], ShipBase* shipBase, int map[18][18], int turn);

#endif