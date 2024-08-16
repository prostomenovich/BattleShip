#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include "../scenes/processingUtils.h"
#include "../scenes/defines.h"

#ifndef SHIPBASE_H
#define SHIPBASE_H

#define ONE_BLOCK_SHIP 1
#define TWO_BLOCKS_SHIP 2
#define THREE_BLOCKS_SHIP 3
#define FOUR_BLOCKS_SHIP 4
#define FIVE_BLOCKS_SHIP 5

#define ONE_BLOCKS_SHIPS_COUNT 4
#define TWO_BLOCKS_SHIPS_COUNT 3
#define THREE_BLOCKS_SHIPS_COUNT 2
#define FOUR_BLOCKS_SHIPS_COUNT 1
#define FIVE_BLOCKS_SHIPS_COUNT 1

#define SHIP_IS_CORRECT 1
#define SHIP_NOT_CORRECT 2

#define NOT_IN_MAP 0
#define IN_MAP 1;

#define ADD_SUCCESS 1
#define MAX_SHIPS_THIS_TYPE 2
#define ADD_ERROR -1

#define CHANGE_X 1
#define CHANGE_Y 2
#define CHANGE_BACK 1
#define CHANGE_UP 2

#define ALL_SHIPS_IN_MAP 1
#define NOT_ALL_SHIPS_IN_MAP 2

#define SHIP_WAS_HIT 1
#define SHIP_KILLED 2
#define SHIP_NOT_FOUND 3

typedef struct Coordinates
{
	int x;
	int y;

} Coordinates;

typedef struct Ship
{
	int lives;
	int inMap;
	Coordinates** coords;
} Ship;

typedef struct ShipBase
{
	int shipType;
	int shipsCount;
	int shipsInMap;
	struct ShipBase* nextShip;
	Ship** ships;
} ShipBase;

ShipBase* initShipBase(int mapSize);

int putShipInBase(ShipBase* shipBase, Coordinates* coords[5], int ShipType);

int maxPlatesShip(ShipBase* shipBase);

int shipIsCorrect(int map[18][18], ShipBase* shipBase, int shipType, int MapSize, Coordinates* coords[5]);

void selectSortX(Coordinates* coords[5], int shipType);

void selectSortY(Coordinates* coords[5], int shipType);

void putShipInMap(int map[18][18], Coordinates* coords[5], int shipType);

void getRemainedShips(ShipBase* shipBase, int shipType, char* shipsCountStr);

int AllShipsInMap(ShipBase* shipBase);

void clearMap(int map[18][18]);

void clearShipBase(ShipBase* shipBase);

static ShipBase* maxNotPutShip(ShipBase* shipBase);

static ShipBase* maxNotPutShip(ShipBase* shipBase);

static int canPutThisShip(int map[18][18], int shipType, int MapSize, Coordinates* coords[5]);

void genRandShips(int map[18][18], ShipBase* shipBase, int MapSize);

void freeShipBase(ShipBase* shipBase);

void clearTrashFromMap(int map[18][18]);

int killShipInShipBase(ShipBase* shipBase, int x, int y);

void putMisses(int map[18][18], ShipBase* shipBase, int x, int y, int digit);

int getShipsLeft(ShipBase* shipBase);

#endif