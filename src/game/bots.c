#include "bots.h"

#ifndef BOTS_C
#define BOTS_C

int lastAttackCoordX = -1;
int lastAttackCoordY = -1;
int AttackDirection = -1;


int easyLevelBot(int* x, int* y, int map[18][18], int mapSize)
{
    int xTmp = rand() % MAP_SIZE_10_X_10 + 1,
        yTmp = rand() % MAP_SIZE_10_X_10 + 1,
        endGameFlag = 0;


    //Проверка, что игра не закончилась
    for (int i = 1; i <= mapSize; i++){
        for (int j = 1; j <= mapSize; j++){
            if (map[i][j] == EMPTY_PLATE || map[i][j] == SHIP_PLATE){
                endGameFlag = 1;
            }
        }
    }

    if (!endGameFlag) return GAME_END;

    while (map[yTmp][xTmp] == HIT_PLATE || map[yTmp][xTmp] == MISS_PLATE){
        xTmp = rand() % MAP_SIZE_10_X_10 + 1,
        yTmp = rand() % MAP_SIZE_10_X_10 + 1;
    }

    if (map[yTmp][xTmp] == EMPTY_PLATE){
        map[yTmp][xTmp] = MISS_PLATE;
        *x = xTmp;
        *y = yTmp;
        return MISS_PLATE;
    }
    else if (map[yTmp][xTmp] == SHIP_PLATE){
        map[yTmp][xTmp] = HIT_PLATE;
        *x = xTmp;
        *y = yTmp;
        return HIT_PLATE;
    }
}

int mediumLevelBot(int* x, int* y, int map[18][18], int mapSize, int gameStatus)
{
    static int step = 0;
    static int direction = -1;
    static int lastX = -1;
    static int lastY = -1;

    int endGameFlag = 0;


    if (gameStatus != GAME_END){
        //Проверка, что игра не закончилась
        for (int i = 1; i <= mapSize; i++){
            for (int j = 1; j <= mapSize; j++){
                if (map[i][j] == EMPTY_PLATE || map[i][j] == SHIP_PLATE){
                    endGameFlag = 1;
                }
            }
        }

        if (!endGameFlag) return GAME_END;

        if (step == 0) step = rand() % 10 + 1;
        if (direction == -1) direction = rand() % 2;
        if (lastX == -1 && lastY == -1){
            if (direction == TOP_DOWN){
                lastX = 1;
                lastY = 1;
            }
            else {
                lastX = 1;
                lastY = mapSize;
            }
        }
        else {
            while (map[lastY][lastX] != EMPTY_PLATE && map[lastY][lastX] != SHIP_PLATE){

                if (direction == TOP_DOWN){
                    lastY += step;
                    if (lastY > mapSize){
                        lastX += 1;
                        lastY = lastY - mapSize;
                    }
                }
                else {
                    lastY -= step;
                    if (lastY < 1){
                        lastX += 1;
                        lastY = mapSize - abs(lastY);
                    }
                }

                if (lastX > mapSize){
                    direction = rand() % 2;
                    if (direction == TOP_DOWN){
                        lastX = 1;
                        lastY = 1;
                    }
                    else {
                        lastX = 1;
                        lastY = mapSize;
                    }
                    step = rand() % 10 + 1;   
                }
            }
        }
        printf("%d, %d ", lastX, lastY);
        printf("%d\n", step);
        if (map[lastY][lastX] == EMPTY_PLATE){
            map[lastY][lastX] = MISS_PLATE;
            *x = lastX;
            *y = lastY;
            return MISS_PLATE;
        }
        else if (map[lastY][lastX] == SHIP_PLATE){
            map[lastY][lastX] = HIT_PLATE;
            *x = lastX;
            *y = lastY;
            return HIT_PLATE;
        }
    }
    else {
        step = 0;
        direction = -1;
        lastX = -1;
        lastY = -1;
    }
    
}

int finishingOff(int x, int y, int map[18][18], ShipBase* shipBase, int AttackStatus, int MapSize)
{
    extern int lastAttackCoordX;
    extern int lastAttackCoordY;
    extern int AttackDirection;

    if (AttackStatus == ATTACK_PROCESS){

        if (AttackDirection == -1) AttackDirection = rand() % 4;
        if (lastAttackCoordX == -1) lastAttackCoordX = x;
        if (lastAttackCoordY == -1) lastAttackCoordY = y;

        if (AttackDirection == UP && (map[lastAttackCoordY - 1][lastAttackCoordX] == MISS_PLATE || map[lastAttackCoordY - 1][lastAttackCoordX] == AROUND_SHIP_PLATE || lastAttackCoordY - 1 < 1)){
            AttackDirection = DOWN;
            if (AttackDirection == DOWN && (map[lastAttackCoordY + 1][lastAttackCoordX] == MISS_PLATE || map[lastAttackCoordY + 1][lastAttackCoordX] == AROUND_SHIP_PLATE || lastAttackCoordY + 1 > MapSize)){
                AttackDirection = rand() % 2 + 2;
                if (AttackDirection == RIGHT && (map[lastAttackCoordY][lastAttackCoordX + 1] == MISS_PLATE || map[lastAttackCoordY][lastAttackCoordX + 1] == AROUND_SHIP_PLATE || lastAttackCoordX + 1 > MapSize)){
                    AttackDirection = LEFT;
                }
                if (AttackDirection == LEFT && (map[lastAttackCoordY][lastAttackCoordX - 1] == MISS_PLATE || map[lastAttackCoordY][lastAttackCoordX - 1] == AROUND_SHIP_PLATE || lastAttackCoordX - 1 < 1)){
                    AttackDirection = RIGHT;
                }
            }
            
        }
        else if (AttackDirection == DOWN && (map[lastAttackCoordY + 1][lastAttackCoordX] == MISS_PLATE || map[lastAttackCoordY + 1][lastAttackCoordX] == AROUND_SHIP_PLATE || lastAttackCoordY + 1 > MapSize)){
            AttackDirection = UP;
            if (AttackDirection == UP && (map[lastAttackCoordY - 1][lastAttackCoordX] == MISS_PLATE || map[lastAttackCoordY - 1][lastAttackCoordX] == AROUND_SHIP_PLATE || lastAttackCoordY - 1 < 1)){
                AttackDirection = rand() % 2 + 2;
                if (AttackDirection == RIGHT && (map[lastAttackCoordY][lastAttackCoordX + 1] == MISS_PLATE || map[lastAttackCoordY][lastAttackCoordX + 1] == AROUND_SHIP_PLATE || lastAttackCoordX + 1 > MapSize)){
                    AttackDirection = LEFT;
                }
                if (AttackDirection == LEFT && (map[lastAttackCoordY][lastAttackCoordX - 1] == MISS_PLATE || map[lastAttackCoordY][lastAttackCoordX - 1] == AROUND_SHIP_PLATE || lastAttackCoordX - 1 < 1)){
                    AttackDirection = RIGHT;
                }
            }
        }
        else if (AttackDirection == RIGHT && (map[lastAttackCoordY][lastAttackCoordX + 1] == MISS_PLATE || map[lastAttackCoordY][lastAttackCoordX + 1] == AROUND_SHIP_PLATE) || lastAttackCoordX + 1 > MapSize){
            AttackDirection = LEFT;
            if (AttackDirection == LEFT && (map[lastAttackCoordY][lastAttackCoordX - 1] == MISS_PLATE || map[lastAttackCoordY][lastAttackCoordX - 1] == AROUND_SHIP_PLATE || lastAttackCoordX - 1 < 1)){
                AttackDirection = rand() % 2;
                if (AttackDirection == DOWN && (map[lastAttackCoordY + 1][lastAttackCoordX] == MISS_PLATE || map[lastAttackCoordY + 1][lastAttackCoordX] == AROUND_SHIP_PLATE || lastAttackCoordY + 1 > MapSize)){
                    AttackDirection = UP;
                }
                if (AttackDirection == UP && (map[lastAttackCoordY - 1][lastAttackCoordX] == MISS_PLATE || map[lastAttackCoordY - 1][lastAttackCoordX] == AROUND_SHIP_PLATE || lastAttackCoordY - 1 < 1)){
                    AttackDirection = DOWN;
                }
            }
        }
        else if (AttackDirection == LEFT && (map[lastAttackCoordY][lastAttackCoordX - 1] == MISS_PLATE || map[lastAttackCoordY][lastAttackCoordX - 1] == AROUND_SHIP_PLATE || lastAttackCoordX - 1 < 1)){
            AttackDirection = RIGHT;
            if (AttackDirection == RIGHT && (map[lastAttackCoordY][lastAttackCoordX + 1] == MISS_PLATE || map[lastAttackCoordY][lastAttackCoordX + 1] == AROUND_SHIP_PLATE || lastAttackCoordX + 1 > MapSize)){
                AttackDirection = rand() % 2;
                if (AttackDirection == DOWN && (map[lastAttackCoordY + 1][lastAttackCoordX] == MISS_PLATE || map[lastAttackCoordY + 1][lastAttackCoordX] == AROUND_SHIP_PLATE || lastAttackCoordY + 1 > MapSize)){
                    AttackDirection = UP;
                }
                if (AttackDirection == UP && (map[lastAttackCoordY - 1][lastAttackCoordX] == MISS_PLATE || map[lastAttackCoordY - 1][lastAttackCoordX] == AROUND_SHIP_PLATE || lastAttackCoordY - 1 < 1)){
                    AttackDirection = DOWN;
                }
            }
        }
        if (AttackDirection == UP){
            lastAttackCoordY--;
            if (map[lastAttackCoordY][lastAttackCoordX] == SHIP_PLATE){
                map[lastAttackCoordY][lastAttackCoordX] = HIT_PLATE;
                if (killShipInShipBase(shipBase, lastAttackCoordX - 1, lastAttackCoordY - 1) == SHIP_KILLED){
                    return SHIP_KILLED;
                }
                else return HIT_PLATE;
            }
            else {
                map[lastAttackCoordY][lastAttackCoordX] = MISS_PLATE;
                if (lastAttackCoordY != y - 1){
                    AttackDirection = DOWN;
                }
                else{
                    AttackDirection = rand() % 2 + 2;
                }
                lastAttackCoordX = x;
                lastAttackCoordY = y;
                return MISS_PLATE;
            }
        }

        if (AttackDirection == DOWN){
            lastAttackCoordY++;
            if (map[lastAttackCoordY][lastAttackCoordX] == SHIP_PLATE){
                map[lastAttackCoordY][lastAttackCoordX] = HIT_PLATE;
                if (killShipInShipBase(shipBase, lastAttackCoordX - 1, lastAttackCoordY - 1) == SHIP_KILLED){
                    return SHIP_KILLED;
                }
                else return HIT_PLATE;
            }
            else {
                map[lastAttackCoordY][lastAttackCoordX] = MISS_PLATE;
                if (lastAttackCoordY != y + 1){
                    AttackDirection = UP;
                }
                else{
                    AttackDirection = rand() % 2 + 2;
                }
                lastAttackCoordX = x;
                lastAttackCoordY = y;
                return MISS_PLATE;
            }
        }

        if (AttackDirection == RIGHT){
            lastAttackCoordX++;
            if (map[lastAttackCoordY][lastAttackCoordX] == SHIP_PLATE){
                map[lastAttackCoordY][lastAttackCoordX] = HIT_PLATE;
                if (killShipInShipBase(shipBase, lastAttackCoordX - 1, lastAttackCoordY - 1) == SHIP_KILLED){
                    return SHIP_KILLED;
                }
                else return HIT_PLATE;
            }
            else {
                map[lastAttackCoordY][lastAttackCoordX] = MISS_PLATE;
                if (lastAttackCoordX != x + 1){
                    AttackDirection = LEFT;
                }
                else{
                    AttackDirection = rand() % 2;
                }
                lastAttackCoordX = x;
                lastAttackCoordY = y;
                return MISS_PLATE;
            }
        }

        if (AttackDirection == LEFT){
            lastAttackCoordX--;
            if (map[lastAttackCoordY][lastAttackCoordX] == SHIP_PLATE){
                map[lastAttackCoordY][lastAttackCoordX] = HIT_PLATE;
                if (killShipInShipBase(shipBase, lastAttackCoordX - 1, lastAttackCoordY - 1) == SHIP_KILLED){
                    return SHIP_KILLED;
                }
                else return HIT_PLATE;
            }
            else {
                map[lastAttackCoordY][lastAttackCoordX] = MISS_PLATE;
                if (lastAttackCoordX != x - 1){
                    AttackDirection = RIGHT;
                }
                else{
                    AttackDirection = rand() % 2;
                }
                lastAttackCoordX = x;
                lastAttackCoordY = y;
                return MISS_PLATE;
            }
        }
    }
    else {
        lastAttackCoordX = -1;
        lastAttackCoordY = -1;
        AttackDirection = -1;
        return ATTACK_END;
    }

}
#endif