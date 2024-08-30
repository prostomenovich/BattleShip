#include "ShipBase.h"

#ifndef SHIPBASE_C
#define SHIPBASE_C

ShipBase* initShipBase(int mapSize)
{	
	int MaxShipsPlates = 4;

	ShipBase* shipBase = NULL;
	ShipBase* sb;
	
	sb = (ShipBase*)malloc(sizeof(ShipBase));
	for (int i = 1; i <= MaxShipsPlates; i++) {
		if (sb == NULL) {
			printf("Memmory Allocation for ShipBase ERROR!\n");
			return NULL;
		}
		if (i == 1) shipBase = sb;
		sb->shipType = i;
		sb->shipsCount = MaxShipsPlates - i + 1;
		sb->shipsInMap = 0;
		sb->ships = (Ship**)malloc(sizeof(Ship*) * sb->shipsCount);
		if (sb->ships == NULL) return NULL;

		for (int j = 0; j < sb->shipsCount; j++) {
			sb->ships[j] = (Ship*)malloc(sizeof(Ship));
			sb->ships[j]->lives = i;
			sb->ships[j]->coords = (Coordinates**)malloc(sizeof(Coordinates*) * sb->shipType);
			for (int k = 0; k < sb->shipType; k++) {
				sb->ships[j]->coords[k] = (Coordinates*)malloc(sizeof(Coordinates));
			}
		}

		if (i != MaxShipsPlates) {
			sb->nextShip = (ShipBase*)malloc(sizeof(ShipBase));
			sb = sb->nextShip;
		}
		else {
	        sb->nextShip = NULL;
        }
	}

    if (mapSize == MAP_SIZE_15_X_15){

        sb->nextShip = (ShipBase*)malloc(sizeof(ShipBase));

        sb = sb->nextShip;

        if (sb == NULL) {
			printf("Memmory Allocation for ShipBase ERROR!\n");
			return NULL;
		}
		sb->shipType = FIVE_BLOCKS_SHIP;
		sb->shipsCount = FIVE_BLOCKS_SHIPS_COUNT;
		sb->shipsInMap = 0;
		sb->ships = (Ship**)malloc(sizeof(Ship*) * sb->shipsCount);
		if (sb->ships == NULL) return NULL;

		for (int j = 0; j < sb->shipsCount; j++) {
			sb->ships[j] = (Ship*)malloc(sizeof(Ship));
			sb->shipsInMap = NOT_IN_MAP;
            sb->ships[j]->lives = FIVE_BLOCKS_SHIP;
			sb->ships[j]->coords = (Coordinates**)malloc(sizeof(Coordinates*) * sb->shipType);
			for (int k = 0; k < sb->shipType; k++) {
				sb->ships[j]->coords[k] = (Coordinates*)malloc(sizeof(Coordinates));
			}
		}

        sb->nextShip = NULL;
    }

	return shipBase;
}

int putShipInBase(ShipBase* shipBase, Coordinates* coords[5], int ShipType)
{
	ShipBase* sb = shipBase;
	while (sb != NULL) {
		if (sb->shipType == ShipType) {
            if (sb->shipsCount == sb->shipsInMap){
                printf("MAX_SHIPS_THIS_TYPE!\n");
                return MAX_SHIPS_THIS_TYPE;
            } 

			for (int j = 0; j < sb->shipType; j++) {
				sb->ships[sb->shipsInMap]->coords[j]->x = coords[j]->x;
				sb->ships[sb->shipsInMap]->coords[j]->y = coords[j]->y;
			}
			sb->ships[sb->shipsInMap]->inMap = IN_MAP;
			sb->shipsInMap += 1;
            printf("ADD_SUCCESS!\n");
			return ADD_SUCCESS;
		}
		sb = sb->nextShip;
	}
    printf("ADD_ERROR!\n");
	return ADD_ERROR;
}

int maxPlatesShip(ShipBase* shipBase)
{
	ShipBase* sb = shipBase;
	int maxPlates = 0;
	while (sb != NULL) {
		if (sb->shipsCount != sb->shipsInMap) {
			maxPlates = sb->shipType;
		}
		sb = sb->nextShip;
	}
	//printf("MaxPlates: %d\n", maxPlates);
	return maxPlates;
}

void selectSortY(Coordinates* coords[5], int shipType)
{
    int min;
    int minInd;

    for (int i = 0; i < shipType; i++){
        min = coords[i]->y;
        minInd = i;
        for (int j = i; j < shipType; j++){
            if (coords[j]->y < min){
                min = coords[j]->y;
                minInd = j;
            }
        }
        coords[minInd]->y = coords[i]->y;
        coords[i]->y = min;
    }
}

void selectSortX(Coordinates* coords[5], int shipType)
{
    int min;
    int minInd;

    for (int i = 0; i < shipType; i++){
        min = coords[i]->x;
        minInd = i;
        for (int j = i; j < shipType; j++){
            if (coords[j]->x < min){
                min = coords[j]->x;
                minInd = j;
            }
        }
        coords[minInd]->x = coords[i]->x;
        coords[i]->x = min;
    }
}

int shipIsCorrect(int map[18][18], ShipBase* shipBase, int shipType, int MapSize, Coordinates* coords[5])
{
    ShipBase* sb = shipBase; 

    if (shipType == 0) return SHIP_NOT_CORRECT;

    while (sb->shipType != shipType) sb = sb->nextShip;
    if (sb->shipsCount == sb->shipsInMap){
        printf("Ships of this type are already deployed!\n");
        return SHIP_NOT_CORRECT;
    }

    int flag;
    if (coords[0]->x == coords[1]->x){
        selectSortY(coords, shipType);
        flag = CHANGE_Y;
    }
    else {
        selectSortX(coords, shipType);
        flag = CHANGE_X; 
    }
    
    int correctCoordsX = 0,
        correctCoordsY = 0;

    for (int i = 0; i < shipType - 1; i++){
        if (coords[i]->x != coords[i + 1]->x){
            printf("141\n");
            correctCoordsX = SHIP_NOT_CORRECT;
        }
        if (coords[i]->y != coords[i + 1]->y){
            correctCoordsY = SHIP_NOT_CORRECT;
        }
    }

    if (correctCoordsX == SHIP_NOT_CORRECT && correctCoordsY == SHIP_NOT_CORRECT) return SHIP_NOT_CORRECT;

    for (int i = 0; i < shipType - 1; i++){
        if (abs(coords[i]->x - coords[i + 1]->x) > 1 || abs(coords[i]->y - coords[i + 1]->y) > 1 ){
            printf("145\n");
            return SHIP_NOT_CORRECT;
        }
    }

    //2 - стоит корабль
    //1 - нельзя ставить (корабль на соседней клетке)
    //0 - клетка свободна

    for (int i = 0; i < shipType; i++){
        printf("(%d, %d)\n", coords[i]->x, coords[i]->y);
    }

    if (coords[0]->x + 1 > MapSize || coords[0]->x + 1 < 1 || coords[0]->y + 1 < 1 || coords[0]->y + 1 > MapSize) return SHIP_NOT_CORRECT;
    if (coords[shipType - 1]->x + 1 > MapSize || coords[shipType - 1]->x + 1 < 1 || coords[shipType - 1]->y + 1 > MapSize || coords[shipType - 1]->y + 1 < 1) return SHIP_NOT_CORRECT;

    if (flag == CHANGE_X){
        if (map[coords[0]->y + 1][coords[0]->x + 1 - 1] == 2 || map[coords[0]->y + 1 + 1][coords[0]->x + 1 - 1] == 2 || map[coords[0]->y + 1 - 1][coords[0]->x + 1 - 1] == 2 ){
            printf("165\n");
            return SHIP_NOT_CORRECT;
        }
        if (map[coords[shipType - 1]->y + 1][coords[shipType - 1]->x + 1 + 1] == 2 || map[coords[shipType - 1]->y + 1 + 1][coords[shipType - 1]->x + 1 + 1] == 2 || map[coords[shipType - 1]->y + 1 - 1][coords[shipType - 1]->x + 1 + 1] == 2 ){
            printf("169\n");
            return SHIP_NOT_CORRECT;
        }
        for (int i = 0; i < shipType; i++){
            if (map[coords[i]->y + 1][coords[i]->x + 1] != 0 || map[coords[i]->y + 1 + 1][coords[i]->x + 1] == 2 || map[coords[i]->y + 1 - 1][coords[i]->x + 1] == 2){
                printf("174\n");
                return SHIP_NOT_CORRECT;
            }
        }

        return SHIP_IS_CORRECT;
    }
    else {
        if (map[coords[0]->y + 1 - 1][coords[0]->x + 1] == 2 || map[coords[0]->y + 1 - 1][coords[0]->x + 1 + 1] == 2 || map[coords[0]->y + 1 - 1][coords[0]->x + 1 - 1] == 2 ){
            printf("183\n");
            return SHIP_NOT_CORRECT;
        }
        if (map[coords[shipType - 1]->y + 1 + 1][coords[shipType - 1]->x + 1] == 2 || map[coords[shipType - 1]->y + 1 + 1][coords[shipType - 1]->x + 1 + 1] == 2 || map[coords[shipType - 1]->y + 1 + 1][coords[shipType - 1]->x + 1 - 1] == 2 ){
            printf("187\n");
            return SHIP_NOT_CORRECT;
        }
        for (int i = 0; i < shipType; i++){
            if (map[coords[i]->y + 1][coords[i]->x + 1] != 0 || map[coords[i]->y + 1][coords[i]->x + 1 + 1] == 2  || map[coords[i]->y + 1][coords[i]->x + 1 - 1] == 2){
                printf("192\n");
                return SHIP_NOT_CORRECT;
            }
        }

        return SHIP_IS_CORRECT;
    }

}

void putShipInMap(int map[18][18], Coordinates* coords[5], int shipType)
{
    int flag;
    
    if (coords[0]->x == coords[1]->x){
        selectSortY(coords, shipType);
        flag = CHANGE_Y;
    }
    else {
        selectSortX(coords, shipType);
        flag = CHANGE_X;
    }

    if (flag == CHANGE_X){
        map[coords[0]->y + 1 + 1][coords[0]->x + 1 - 1] = 1;
        map[coords[0]->y + 1 ][coords[0]->x + 1 - 1] = 1;
        map[coords[0]->y + 1 - 1][coords[0]->x + 1 - 1] = 1;
        map[coords[shipType - 1]->y + 1 + 1][coords[shipType - 1]->x + 1 + 1] = 1;
        map[coords[shipType - 1]->y + 1][coords[shipType - 1]->x + 1 + 1] = 1;
        map[coords[shipType - 1]->y + 1 - 1][coords[shipType - 1]->x + 1 + 1] = 1;

        for (int i = 0; i < shipType; i++){
            map[coords[i]->y + 1 + 1][coords[i]->x + 1] = 1;
            map[coords[i]->y + 1 - 1][coords[i]->x + 1] = 1;
            map[coords[i]->y + 1][coords[i]->x + 1] = 2;
        }
    }
    else {
        map[coords[0]->y + 1 - 1][coords[0]->x + 1 - 1] = 1;
        map[coords[0]->y + 1 - 1][coords[0]->x + 1] = 1;
        map[coords[0]->y + 1 - 1][coords[0]->x + 1 + 1] = 1;
        map[coords[shipType - 1]->y + 1 + 1][coords[shipType - 1]->x + 1 - 1] =1;
        map[coords[shipType - 1]->y + 1 + 1][coords[shipType - 1]->x + 1] = 1;
        map[coords[shipType - 1]->y + 1 + 1][coords[shipType - 1]->x + 1 + 1] = 1;

        for (int i = 0; i < shipType; i++){
            map[coords[i]->y + 1][coords[i]->x + 1] = 2;
            map[coords[i]->y + 1][coords[i]->x + 1 - 1] = 1;
            map[coords[i]->y + 1 ][coords[i]->x + 1 + 1] = 1;
        }
    }

    for (int i = 1; i <= 10; i++){
        for (int j = 1; j <= 10; j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}

void getRemainedShips(ShipBase* shipBase, int shipType, char* shipsCountStr)
{
    ShipBase* sb = shipBase;
    
    int remained = 0;

    while(sb != NULL){
        if (sb->shipType == shipType){
            remained = sb->shipsCount - sb->shipsInMap;
            break;
        }
        sb = sb->nextShip;
    }

    shipsCountStr[0] = remained + '0';
}

int AllShipsInMap(ShipBase* shipBase)
{
    ShipBase* sb = shipBase;
    if (sb == NULL) return NOT_ALL_SHIPS_IN_MAP;
    while(sb != NULL){
        if (sb->shipsCount != sb->shipsInMap) return NOT_ALL_SHIPS_IN_MAP;
        sb = sb->nextShip;
    }
    return ALL_SHIPS_IN_MAP;
}

void clearMap(int map[18][18])
{
    for (int i = 0; i < 18; i++){
        for (int j = 0; j < 18; j++){
            map[i][j] = 0;
        }
    }
}

void clearShipBase(ShipBase* shipBase)
{
    ShipBase* sb = shipBase;
    while(sb != NULL){
        sb->shipsInMap = 0;
        sb = sb->nextShip;
    }
}

static ShipBase* maxNotPutShip(ShipBase* shipBase)
{
    ShipBase* sb = shipBase;
    ShipBase* tmpsb = NULL;
    while(sb != NULL){
        if (sb->shipsCount != sb->shipsInMap){
            tmpsb = sb;
        }
        sb = sb->nextShip;
    }
    return tmpsb;
}

static int canPutThisShip(int map[18][18], int shipType, int MapSize, Coordinates* coords[5])
{
    
    int flag;
    if (coords[0]->x == coords[1]->x){
        flag = CHANGE_Y;
    }
    else {
        flag = CHANGE_X;
    }

    if (coords[0]->x + 1 > MapSize || coords[0]->x + 1 < 1 || coords[0]->y + 1 < 1 || coords[0]->y + 1 > MapSize) return SHIP_NOT_CORRECT;
    if (coords[shipType - 1]->x + 1 > MapSize || coords[shipType - 1]->x + 1 < 1 || coords[shipType - 1]->y + 1 > MapSize || coords[shipType - 1]->y + 1 < 1) return SHIP_NOT_CORRECT;

    if (flag == CHANGE_X){
        if (map[coords[0]->y + 1][coords[0]->x + 1 - 1] == 2 || map[coords[0]->y + 1 + 1][coords[0]->x + 1 - 1] == 2 || map[coords[0]->y + 1 - 1][coords[0]->x + 1 - 1] == 2 ){
            printf("165\n");
            return SHIP_NOT_CORRECT;
        }
        if (map[coords[shipType - 1]->y + 1][coords[shipType - 1]->x + 1 + 1] == 2 || map[coords[shipType - 1]->y + 1 + 1][coords[shipType - 1]->x + 1 + 1] == 2 || map[coords[shipType - 1]->y + 1 - 1][coords[shipType - 1]->x + 1 + 1] == 2 ){
            printf("169\n");
            return SHIP_NOT_CORRECT;
        }
        for (int i = 0; i < shipType; i++){
            if (map[coords[i]->y + 1][coords[i]->x + 1] != 0 || map[coords[i]->y + 1 + 1][coords[i]->x + 1] == 2 || map[coords[i]->y + 1 - 1][coords[i]->x + 1] == 2){
                printf("174\n");
                return SHIP_NOT_CORRECT;
            }
        }

        return SHIP_IS_CORRECT;
    }
    else {
        if (map[coords[0]->y + 1 - 1][coords[0]->x + 1] == 2 || map[coords[0]->y + 1 - 1][coords[0]->x + 1 + 1] == 2 || map[coords[0]->y + 1 - 1][coords[0]->x + 1 - 1] == 2 ){
            printf("183\n");
            return SHIP_NOT_CORRECT;
        }
        if (map[coords[shipType - 1]->y + 1 + 1][coords[shipType - 1]->x + 1] == 2 || map[coords[shipType - 1]->y + 1 + 1][coords[shipType - 1]->x + 1 + 1] == 2 || map[coords[shipType - 1]->y + 1 + 1][coords[shipType - 1]->x + 1 - 1] == 2 ){
            printf("187\n");
            return SHIP_NOT_CORRECT;
        }
        for (int i = 0; i < shipType; i++){
            if (map[coords[i]->y + 1][coords[i]->x + 1] != 0 || map[coords[i]->y + 1][coords[i]->x + 1 + 1] == 2  || map[coords[i]->y + 1][coords[i]->x + 1 - 1] == 2){
                printf("192\n");
                return SHIP_NOT_CORRECT;
            }
        }
        return SHIP_IS_CORRECT;
    }
}


void genRandShips(int map[18][18], ShipBase* shipBase, int MapSize)
{
    srand(time(NULL));

    ShipBase* sb;
    Coordinates* coords[5];

    for (int i = 0; i < 5; i++){
        coords[i] = (Coordinates*)malloc(sizeof(Coordinates));
    }

    int typesOfShip,
        firstCoordX,
        firstCoordY,
        direction;

    bool flag = false;

    if (MapSize == MAP_SIZE_10_X_10) typesOfShip = 4;
    else typesOfShip = 5;

    for (int currShipType = typesOfShip; currShipType > 0; currShipType--){
        sb = maxNotPutShip(shipBase);
        for (; sb->shipsInMap != sb->shipsCount;){
            while (flag == false)
            {   
                firstCoordX = rand() % MapSize;
                firstCoordY = rand() % MapSize;
                direction = rand() % 2 + 1;
                if (direction == CHANGE_X){
                    direction = rand() % 2 + 1;
                    if (direction == CHANGE_UP){
                        for (int i = 0; i < currShipType; i++){
                            coords[i]->x = firstCoordX + i;
                            coords[i]->y = firstCoordY;
                        }
                    }
                    else{
                        for (int i = 0; i < currShipType; i++){
                            coords[i]->x = firstCoordX - i;
                            coords[i]->y = firstCoordY;
                        }
                    }
                }
                else {
                    if (direction == CHANGE_UP){
                        for (int i = 0; i < currShipType; i++){
                            coords[i]->x = firstCoordX;
                            coords[i]->y = firstCoordY + i;
                        }
                    }
                    else {
                        for (int i = 0; i < currShipType; i++){
                            coords[i]->x = firstCoordX;
                            coords[i]->y = firstCoordY - i;
                        }
                    }
                }
                if (canPutThisShip(map, currShipType, MapSize, coords) == SHIP_IS_CORRECT){
                    flag = true;
                    putShipInBase(shipBase, coords, currShipType);
                    putShipInMap(map, coords, currShipType);
                }
            }
            flag = false;
            
        }

        
    }


    for (int i = 0; i < 5; i++){
        free(coords[i]);
    }
}


void freeShipBase(ShipBase* shipBase)
{
    ShipBase* tmp = NULL;
    if (shipBase == NULL) return;
    while(shipBase != NULL){
        for (int i = 0; i < shipBase->shipsCount; i++){
            for (int j = 0; j < shipBase->shipType; j++){
                if (shipBase->ships[i]->coords[j] != NULL){
                    free(shipBase->ships[i]->coords[j]);
                    shipBase->ships[i]->coords[j] = NULL;
                }
                else {
                    return;
                }
            }
            if (shipBase->ships[i]->coords != NULL){
                free(shipBase->ships[i]->coords);
                shipBase->ships[i]->coords = NULL;
            }
            else {
                return;
            }
        }
        if (shipBase != NULL){
            free(shipBase->ships);
        }else {
            return;
        }
        tmp = shipBase;
        if (shipBase != NULL)
            shipBase = shipBase->nextShip;
        if (tmp != NULL) free(tmp);
    }

    shipBase = NULL;
}

void clearTrashFromMap(int map[18][18])
{
    for (int i = 0; i < 18; i++){
        for (int j = 0; j < 18; j++){
            if (map[i][j] != 2) map[i][j] = 0;
        }
    }
}

//Проверка убит корабль, подбит или промах
int killShipInShipBase(ShipBase* shipBase, int x, int y)
{
    ShipBase* sb = shipBase;
    while(sb != NULL){
        for (int i = 0; i < sb->shipsCount; i++){
            if (sb->ships[i]->lives == 0) continue;
            for (int j = 0; j < sb->shipType; j++){
                if (sb->ships[i]->coords[j]->x == x && sb->ships[i]->coords[j]->y == y){
                    sb->ships[i]->lives -= 1;
                    if (sb->ships[i]->lives > 0){
                        return HIT_PLATE;
                    }
                    else{
                        return SHIP_KILLED;
                    } 
                }
            }
        }

        sb = sb->nextShip;
    }

    return SHIP_NOT_FOUND;
}

//Расставляет промахи вокруг корабля, если он убит
void putMisses(int map[18][18], ShipBase* shipBase, int x, int y, int digit)
{
    ShipBase* sb = shipBase;
    while(sb != NULL){
        if (sb->ships)
        for (int i = 0; i < sb->shipsCount; i++){
            if (sb->ships[i]->lives == 0){
                for (int j = 0; j < sb->shipType; j++){
                    if (sb->ships[i]->coords[j]->x == x && sb->ships[i]->coords[j]->y == y){
                        for (int k = 0; k < sb->shipType; k++){
                            printf("1\n");
                            if (map[sb->ships[i]->coords[k]->y + 1][sb->ships[i]->coords[k]->x + 1 - 1] != 3 && map[sb->ships[i]->coords[k]->y + 1][sb->ships[i]->coords[k]->x + 1 - 1] != 1 && map[sb->ships[i]->coords[k]->y + 1][sb->ships[i]->coords[k]->x + 1 - 1] != 2){
                                map[sb->ships[i]->coords[k]->y + 1][sb->ships[i]->coords[k]->x + 1 - 1] = digit;
                            }
                            printf("2\n");
                            if (map[sb->ships[i]->coords[k]->y + 1][sb->ships[i]->coords[k]->x + 1 + 1] != 3 && map[sb->ships[i]->coords[k]->y + 1][sb->ships[i]->coords[k]->x + 1 + 1] != 1 && map[sb->ships[i]->coords[k]->y + 1][sb->ships[i]->coords[k]->x + 1 + 1] != 2){
                                map[sb->ships[i]->coords[k]->y + 1][sb->ships[i]->coords[k]->x + 1 + 1] = digit;
                            }
                            printf("3\n");
                            if (map[sb->ships[i]->coords[k]->y + 1 + 1][sb->ships[i]->coords[k]->x + 1] != 3 && map[sb->ships[i]->coords[k]->y + 1 + 1][sb->ships[i]->coords[k]->x + 1] != 1 && map[sb->ships[i]->coords[k]->y + 1 + 1][sb->ships[i]->coords[k]->x + 1] != 2){
                                map[sb->ships[i]->coords[k]->y + 1 + 1][sb->ships[i]->coords[k]->x + 1] = digit;
                            }
                            printf("4\n");
                            if (map[sb->ships[i]->coords[k]->y + 1 + 1][sb->ships[i]->coords[k]->x + 1 + 1] != 3 && map[sb->ships[i]->coords[k]->y + 1 + 1][sb->ships[i]->coords[k]->x + 1 + 1] != 1 && map[sb->ships[i]->coords[k]->y + 1 + 1][sb->ships[i]->coords[k]->x + 1 + 1] != 2){
                                map[sb->ships[i]->coords[k]->y + 1 + 1][sb->ships[i]->coords[k]->x + 1 + 1] = digit;
                            }
                            printf("5\n");
                            if (map[sb->ships[i]->coords[k]->y + 1 + 1][sb->ships[i]->coords[k]->x + 1 - 1] != 3 && map[sb->ships[i]->coords[k]->y + 1 + 1][sb->ships[i]->coords[k]->x + 1 - 1] != 1 && map[sb->ships[i]->coords[k]->y + 1 + 1][sb->ships[i]->coords[k]->x + 1 - 1] != 2){
                                map[sb->ships[i]->coords[k]->y + 1 + 1][sb->ships[i]->coords[k]->x + 1 - 1] = digit;
                            }
                            printf("6\n");
                            if (map[sb->ships[i]->coords[k]->y + 1 - 1][sb->ships[i]->coords[k]->x + 1] != 3 && map[sb->ships[i]->coords[k]->y + 1 - 1][sb->ships[i]->coords[k]->x + 1] != 1 && map[sb->ships[i]->coords[k]->y + 1 - 1][sb->ships[i]->coords[k]->x + 1] != 2){
                                map[sb->ships[i]->coords[k]->y + 1 - 1][sb->ships[i]->coords[k]->x + 1] = digit;
                            }
                            printf("7\n");
                            if (map[sb->ships[i]->coords[k]->y + 1 - 1][sb->ships[i]->coords[k]->x + 1 + 1] != 3 && map[sb->ships[i]->coords[k]->y + 1 - 1][sb->ships[i]->coords[k]->x + 1 + 1] != 1 && map[sb->ships[i]->coords[k]->y + 1 - 1][sb->ships[i]->coords[k]->x + 1 + 1] != 2){
                                map[sb->ships[i]->coords[k]->y + 1 - 1][sb->ships[i]->coords[k]->x + 1 + 1] = digit;
                            }
                            printf("8\n");
                            if (map[sb->ships[i]->coords[k]->y + 1 - 1][sb->ships[i]->coords[k]->x + 1 - 1] != 3 && map[sb->ships[i]->coords[k]->y + 1 - 1][sb->ships[i]->coords[k]->x + 1 - 1] != 1 && map[sb->ships[i]->coords[k]->y + 1 - 1][sb->ships[i]->coords[k]->x + 1 - 1] != 2){
                                map[sb->ships[i]->coords[k]->y + 1 - 1][sb->ships[i]->coords[k]->x + 1 - 1] = digit;
                            } 
                        }
                        return;
                    }
                }
            }  
        }

        sb = sb->nextShip;
    }
}

int getShipsLeft(ShipBase* shipBase)
{
    ShipBase* sb = shipBase;
    int shipsLeft = 0;

    while(sb != NULL){
        for (int i = 0; i < sb->shipsCount; i++){
            if (sb->ships[i]->lives != 0)
                shipsLeft += 1;
        }
        sb = sb->nextShip;
    }
    return shipsLeft;
}

#endif
