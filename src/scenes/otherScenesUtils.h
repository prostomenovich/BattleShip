#include "stdlib.h"
#include "../game/ShipBase.h"
#include "../scenes/scenesInitial.h"

#ifndef OTHERSCENESUTILS_H
#define OTHERSCENESUTILS_H

void fillShipsTextures(MapSprite SpriteArray[10][10], ShipBase* shipBase, int map[18][18], int turn);

#endif