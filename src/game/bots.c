#include "bots.h"

#ifndef BOTS_C
#define BOTS_C

int lastAttackCoordX = -1;
int lastAttackCoordY = -1;
int AttackDirection = -1;

//Переменные для ботов уровня Normal и Hard в ражиме Basic
int lastX = -1;
int lastY = -1;
int direction = -1;
int step = -1;

//Переменные для ботов уровня Normal и Hard в режиме Bots Fight
int stepBot1 = -1;
int directionBot1 = -1;
int lastXBot1 = -1;
int lastYBot1 = -1;

int stepBot2 = -1;
int directionBot2 = -1;
int lastXBot2 = -1;
int lastYBot2 = -1;

//Генерирует выстрел для бота лёгкого уровня сложности
int easyLevelBot(int* x, int* y, int map[18][18], int mapSize)
{
    int xTmp = rand() % mapSize + 1,
        yTmp = rand() % mapSize + 1,
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
        xTmp = rand() % mapSize + 1,
        yTmp = rand() % mapSize + 1;
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

//Генерирует выстрел для бота среднего уровня сложности
int mediumLevelBot(int* x, int* y, int map[18][18], int mapSize, int gameStatus)
{
    extern int step;
    extern int direction;
    extern int lastX;
    extern int lastY;

    int endGameFlag = 0;

    int MapChecker = 0;

    if (gameStatus != GAME_END){
        //Проверка, что игра не закончилась
        for (int i = 1; i <= mapSize; i++){
            for (int j = 1; j <= mapSize; j++){
                if (map[i][j] == EMPTY_PLATE || map[i][j] == SHIP_PLATE){
                    endGameFlag = 1;
                }
                if (map[i][j] == HIT_PLATE || map[i][j] == MISS_PLATE || map[i][j] == AROUND_SHIP_PLATE) MapChecker++;
            }
        }

        if (!endGameFlag) return GAME_END;

        if (step == -1 && MapChecker < ((mapSize * mapSize) / 2)) step= rand() % 8 + 2;
        else if (step == -1 && MapChecker >= ((mapSize * mapSize) / 2))  step = rand() % 10 + 1;

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
                    if (MapChecker < ((mapSize * mapSize) / 2)) step = rand() % 8 + 2;
                    else if (MapChecker >= ((mapSize * mapSize) / 2))  step = rand() % 10 + 1; 
                }
            }
        }

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
        step = -1;
        direction = -1;
        lastX = -1;
        lastY = -1;
    }
    
}

//Режим добивания для бота уровня Hard
int finishingOff(int x, int y, int map[18][18], ShipBase* shipBase, int AttackStatus, int MapSize)
{
    extern int lastAttackCoordX;
    extern int lastAttackCoordY;
    extern int AttackDirection;

    if (AttackStatus == ATTACK_PROCESS){

        if (AttackDirection == -1) AttackDirection = rand() % 4;
        if (lastAttackCoordX == -1) lastAttackCoordX = x;
        if (lastAttackCoordY == -1) lastAttackCoordY = y;

        /*
            Выбор корректного направления для атаки
            Проверяется:
                1. Не стреляли ли уже в клетку, в которую планируется сделать атаку
                2. Не выходит ли атака за границы поля
        
        */

        if (AttackDirection == UP && (map[lastAttackCoordY - 1][lastAttackCoordX] == HIT_PLATE || map[lastAttackCoordY - 1][lastAttackCoordX] == MISS_PLATE || map[lastAttackCoordY - 1][lastAttackCoordX] == AROUND_SHIP_PLATE || lastAttackCoordY - 1 < 1)){
            AttackDirection = DOWN;
            if (AttackDirection == DOWN && (map[lastAttackCoordY + 1][lastAttackCoordX] == HIT_PLATE || map[lastAttackCoordY + 1][lastAttackCoordX] == MISS_PLATE || map[lastAttackCoordY + 1][lastAttackCoordX] == AROUND_SHIP_PLATE || lastAttackCoordY + 1 > MapSize)){
                AttackDirection = rand() % 2 + 2;
                if (AttackDirection == RIGHT && (map[lastAttackCoordY][lastAttackCoordX + 1] == HIT_PLATE || map[lastAttackCoordY][lastAttackCoordX + 1] == MISS_PLATE || map[lastAttackCoordY][lastAttackCoordX + 1] == AROUND_SHIP_PLATE || lastAttackCoordX + 1 > MapSize)){
                    AttackDirection = LEFT;
                }
                if (AttackDirection == LEFT && (map[lastAttackCoordY][lastAttackCoordX - 1] == HIT_PLATE || map[lastAttackCoordY][lastAttackCoordX - 1] == MISS_PLATE || map[lastAttackCoordY][lastAttackCoordX - 1] == AROUND_SHIP_PLATE || lastAttackCoordX - 1 < 1)){
                    AttackDirection = RIGHT;
                }
            }
            
        }
        else if (AttackDirection == DOWN && (map[lastAttackCoordY + 1][lastAttackCoordX] == HIT_PLATE || map[lastAttackCoordY + 1][lastAttackCoordX] == MISS_PLATE || map[lastAttackCoordY + 1][lastAttackCoordX] == AROUND_SHIP_PLATE || lastAttackCoordY + 1 > MapSize)){
            AttackDirection = UP;
            if (AttackDirection == UP && (map[lastAttackCoordY - 1][lastAttackCoordX] == HIT_PLATE || map[lastAttackCoordY - 1][lastAttackCoordX] == MISS_PLATE || map[lastAttackCoordY - 1][lastAttackCoordX] == AROUND_SHIP_PLATE || lastAttackCoordY - 1 < 1)){
                AttackDirection = rand() % 2 + 2;
                if (AttackDirection == RIGHT && (map[lastAttackCoordY][lastAttackCoordX + 1] == HIT_PLATE || map[lastAttackCoordY][lastAttackCoordX + 1] == MISS_PLATE || map[lastAttackCoordY][lastAttackCoordX + 1] == AROUND_SHIP_PLATE || lastAttackCoordX + 1 > MapSize)){
                    AttackDirection = LEFT;
                }
                if (AttackDirection == LEFT && (map[lastAttackCoordY][lastAttackCoordX - 1] == HIT_PLATE || map[lastAttackCoordY][lastAttackCoordX - 1] == MISS_PLATE || map[lastAttackCoordY][lastAttackCoordX - 1] == AROUND_SHIP_PLATE || lastAttackCoordX - 1 < 1)){
                    AttackDirection = RIGHT;
                }
            }
        }
        else if (AttackDirection == RIGHT && (map[lastAttackCoordY][lastAttackCoordX + 1] == HIT_PLATE || map[lastAttackCoordY][lastAttackCoordX + 1] == MISS_PLATE || map[lastAttackCoordY][lastAttackCoordX + 1] == AROUND_SHIP_PLATE || lastAttackCoordX + 1 > MapSize)){
            AttackDirection = LEFT;
            if (AttackDirection == LEFT && (map[lastAttackCoordY][lastAttackCoordX - 1] == HIT_PLATE || map[lastAttackCoordY][lastAttackCoordX - 1] == MISS_PLATE || map[lastAttackCoordY][lastAttackCoordX - 1] == AROUND_SHIP_PLATE || lastAttackCoordX - 1 < 1)){
                AttackDirection = rand() % 2;
                if (AttackDirection == DOWN && (map[lastAttackCoordY + 1][lastAttackCoordX] == HIT_PLATE || map[lastAttackCoordY + 1][lastAttackCoordX] == MISS_PLATE || map[lastAttackCoordY + 1][lastAttackCoordX] == AROUND_SHIP_PLATE || lastAttackCoordY + 1 > MapSize)){
                    AttackDirection = UP;
                }
                if (AttackDirection == UP && (map[lastAttackCoordY - 1][lastAttackCoordX] == HIT_PLATE || map[lastAttackCoordY - 1][lastAttackCoordX] == MISS_PLATE || map[lastAttackCoordY - 1][lastAttackCoordX] == AROUND_SHIP_PLATE || lastAttackCoordY - 1 < 1)){
                    AttackDirection = DOWN;
                }
            }
        }
        else if (AttackDirection == LEFT && (map[lastAttackCoordY][lastAttackCoordX - 1] == HIT_PLATE || map[lastAttackCoordY][lastAttackCoordX - 1] == MISS_PLATE || map[lastAttackCoordY][lastAttackCoordX - 1] == AROUND_SHIP_PLATE || lastAttackCoordX - 1 < 1)){
            AttackDirection = RIGHT;
            if (AttackDirection == RIGHT && (map[lastAttackCoordY][lastAttackCoordX + 1] == HIT_PLATE || map[lastAttackCoordY][lastAttackCoordX + 1] == MISS_PLATE || map[lastAttackCoordY][lastAttackCoordX + 1] == AROUND_SHIP_PLATE || lastAttackCoordX + 1 > MapSize)){
                AttackDirection = rand() % 2;
                if (AttackDirection == DOWN && (map[lastAttackCoordY + 1][lastAttackCoordX] == HIT_PLATE || map[lastAttackCoordY + 1][lastAttackCoordX] == MISS_PLATE || map[lastAttackCoordY + 1][lastAttackCoordX] == AROUND_SHIP_PLATE || lastAttackCoordY + 1 > MapSize)){
                    AttackDirection = UP;
                }
                if (AttackDirection == UP && (map[lastAttackCoordY - 1][lastAttackCoordX] == HIT_PLATE || map[lastAttackCoordY - 1][lastAttackCoordX] == MISS_PLATE || map[lastAttackCoordY - 1][lastAttackCoordX] == AROUND_SHIP_PLATE || lastAttackCoordY - 1 < 1)){
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
                else{
                    return HIT_PLATE;
                }
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
                else {
                    return HIT_PLATE;
                }
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
                else {
                    return HIT_PLATE;
                }
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
                else {
                    return HIT_PLATE;
                }
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

//Генерирует выстрел для бота уровня сложности hard
int hardLevelBot(int* x, int* y, int map[18][18], int MapSize, ShipBase* shipBase, int gameStatus)
{
    extern int lastX;
    extern int lastY;
    extern int direction;
    extern int step;
    int endGameFlag = 0;
            

    if (gameStatus != GAME_END){
        //Проверка, что игра не закончилась
        for (int i = 1; i <= MapSize; i++){
            for (int j = 1; j <= MapSize; j++){
                if (map[i][j] == EMPTY_PLATE || map[i][j] == SHIP_PLATE){
                    endGameFlag = 1;
                }
            }
        }
        if (!endGameFlag) return GAME_END;

        if (direction == -1){
            direction = rand() % 2;
            if (direction == TOP_DOWN){
                lastX = MapSize;
                lastY = 1;
            }
            else {
                lastX = 1;
                lastY = MapSize;
            }
        }

        while (map[lastY][lastX] != EMPTY_PLATE && map[lastY][lastX] != SHIP_PLATE){
            if (direction == TOP_DOWN){
                lastX--;
                lastY++;
            }
            if (direction == DOWN_TOP){
                lastX++;
                lastY--;
            }

            if (direction == TOP_DOWN && (lastX < 1 || lastY > MapSize)){
                direction = rand() % 2;
                if (direction == TOP_DOWN){
                    lastX = MapSize - (rand() % MapSize);
                    lastY = 1;
                }
                else {
                    lastX = 1 + (rand() % MapSize);
                    lastY = MapSize; 
                }
            }
            if (direction == DOWN_TOP && (lastX > MapSize || lastY < 1)){
                direction = rand() % 2;
                if (direction == TOP_DOWN){
                    lastX = MapSize - (rand() % MapSize);
                    lastY = 1;
                }
                else {
                    lastX = 1 + (rand() % MapSize);
                    lastY = MapSize; 
                }
            }
        }

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
        direction = -1;
        lastX = -1;
        lastY = -1;
    }
    
}

//Генерирует выстрел для ботов среднего уровня сложности в режиме bots fight
int mediumLevelBotBF(int* x, int* y, int map[18][18], int mapSize, int botCount, int gameStatus)
{   
    extern int stepBot1;
    extern int directionBot1;
    extern int lastXBot1;
    extern int lastYBot1;

    extern int stepBot2;
    extern int directionBot2;
    extern int lastXBot2;
    extern int lastYBot2;

    int endGameFlag = 0;
    int MapChecker = 0;

    if (botCount == BOT_1_SHOT){
        if (gameStatus != GAME_END){
            //Проверка, что игра не закончилась
            for (int i = 1; i <= mapSize; i++){
                for (int j = 1; j <= mapSize; j++){
                    if (map[i][j] == EMPTY_PLATE || map[i][j] == SHIP_PLATE){
                        endGameFlag = 1;
                    }
                    if (map[i][j] == MISS_PLATE || map[i][j] == HIT_PLATE) MapChecker++;
                }
            }

            if (!endGameFlag) return GAME_END;

            if (stepBot1 == -1 && MapChecker < ((mapSize * mapSize) / 2)) stepBot1 = rand() % 8 + 2;
            else if (stepBot1 == -1 && MapChecker >= ((mapSize * mapSize) / 2))  stepBot1 = rand() % 10 + 1;
            
            if (directionBot1 == -1) directionBot1 = rand() % 2;
            if (lastXBot1 == -1 && lastYBot1 == -1){
                if (directionBot1 == TOP_DOWN){
                    lastXBot1 = 1;
                    lastYBot1 = 1;
                }
                else {
                    lastXBot1 = 1;
                    lastYBot1 = mapSize;
                }
            }
            else {
                while (map[lastYBot1][lastXBot1] != EMPTY_PLATE && map[lastYBot1][lastXBot1] != SHIP_PLATE){

                    if (directionBot1 == TOP_DOWN){
                        lastYBot1 += stepBot1;
                        if (lastYBot1 > mapSize){
                            lastXBot1 += 1;
                            lastYBot1 = lastYBot1 - mapSize;
                        }
                    }
                    else {
                        lastYBot1 -= stepBot1;
                        if (lastYBot1 < 1){
                            lastXBot1 += 1;
                            lastYBot1 = mapSize - abs(lastYBot1);
                        }
                    }

                    if (lastXBot1 > mapSize){
                        directionBot1 = rand() % 2;
                        if (directionBot1 == TOP_DOWN){
                            lastXBot1 = 1;
                            lastYBot1 = 1;
                        }
                        else {
                            lastXBot1 = 1;
                            lastYBot1 = mapSize;
                        }
                        if (MapChecker < ((mapSize * mapSize) / 2)) stepBot1 = rand() % 8 + 2;
                        else if (MapChecker >= ((mapSize * mapSize) / 2))  stepBot1 = rand() % 10 + 1;  
                    }
                }
            }

            if (map[lastYBot1][lastXBot1] == EMPTY_PLATE){
                map[lastYBot1][lastXBot1] = MISS_PLATE;
                *x = lastXBot1;
                *y = lastYBot1;
                return MISS_PLATE;
            }
            else if (map[lastYBot1][lastXBot1] == SHIP_PLATE){
                map[lastYBot1][lastXBot1] = HIT_PLATE;
                *x = lastXBot1;
                *y = lastYBot1;
                return HIT_PLATE;
            }
        }
        else {
            stepBot1 = -1;
            directionBot1 = -1;
            lastXBot1 = -1;
            lastYBot1 = -1;
        }
    }
    else if (botCount == BOT_2_SHOT){
        if (gameStatus != GAME_END){
            //Проверка, что игра не закончилась
            for (int i = 1; i <= mapSize; i++){
                for (int j = 1; j <= mapSize; j++){
                    if (map[i][j] == EMPTY_PLATE || map[i][j] == SHIP_PLATE){
                        endGameFlag = 1;
                    }
                    if (map[i][j] == MISS_PLATE || map[i][j] == HIT_PLATE) MapChecker++;
                }
            }

            if (!endGameFlag) return GAME_END;

            if (stepBot2 == -1 && MapChecker < ((mapSize * mapSize) / 2)) stepBot2 = rand() % 8 + 2;
            else if (stepBot2 == -1 && MapChecker >= ((mapSize * mapSize) / 2)) stepBot2 =  rand() % 10 + 1;
            //if (stepBot2 == 0) rand() % 10 + 1;

            if (directionBot2 == -1) directionBot2 = rand() % 2;
            if (lastXBot2 == -1 && lastYBot2 == -1){
                if (directionBot2 == TOP_DOWN){
                    lastXBot2 = 1;
                    lastYBot2 = 1;
                }
                else {
                    lastXBot2 = 1;
                    lastYBot2 = mapSize;
                }
            }
            else {
                while (map[lastYBot2][lastXBot2] != EMPTY_PLATE && map[lastYBot2][lastXBot2] != SHIP_PLATE){

                    if (directionBot2 == TOP_DOWN){
                        lastYBot2 += stepBot2;
                        if (lastYBot2 > mapSize){
                            lastXBot2 += 1;
                            lastYBot2 = lastYBot2 - mapSize;
                        }
                    }
                    else {
                        lastYBot2 -= stepBot2;
                        if (lastYBot2 < 1){
                            lastXBot2 += 1;
                            lastYBot2 = mapSize - abs(lastYBot2);
                        }
                    }

                    if (lastXBot2 > mapSize){
                        directionBot2 = rand() % 2;
                        if (directionBot2 == TOP_DOWN){
                            lastXBot2 = 1;
                            lastYBot2 = 1;
                        }
                        else {
                            lastXBot2 = 1;
                            lastYBot2 = mapSize;
                        }
                        if (MapChecker < ((mapSize * mapSize) / 2)) stepBot2 = rand() % 8 + 2;
                        else if (MapChecker >= ((mapSize * mapSize) / 2))  stepBot2 = rand() % 10 + 1;    
                    }
                }
            }

            if (map[lastYBot2][lastXBot2] == EMPTY_PLATE){
                map[lastYBot2][lastXBot2] = MISS_PLATE;
                *x = lastXBot2;
                *y = lastYBot2;
                return MISS_PLATE;
            }
            else if (map[lastYBot2][lastXBot2] == SHIP_PLATE){
                map[lastYBot2][lastXBot2] = HIT_PLATE;
                *x = lastXBot2;
                *y = lastYBot2;
                return HIT_PLATE;
            }
        }
        else {
            stepBot2 = -1;
            directionBot2 = -1;
            lastXBot2 = -1;
            lastYBot2 = -1;
        }
    }
}

//Генерирует выстрел для бота уровня сложности hard в режиме bots fight
int hardLevelBotBF(int* x, int* y, int map[18][18], int MapSize, ShipBase* shipBase, int botCount, int gameStatus)
{
    extern int lastXBot1;
    extern int lastYBot1;
    extern int directionBot1;
    extern int stepBot1;

    extern int lastXBot2;
    extern int lastYBot2;
    extern int directionBot2;
    extern int stepBot2;

    int endGameFlag = 0;
            
    if (botCount == BOT_1_SHOT){
        if (gameStatus != GAME_END){
            //Проверка, что игра не закончилась
            for (int i = 1; i <= MapSize; i++){
                for (int j = 1; j <= MapSize; j++){
                    if (map[i][j] == EMPTY_PLATE || map[i][j] == SHIP_PLATE){
                        endGameFlag = 1;
                    }
                }
            }
            if (!endGameFlag) return GAME_END;

            if (directionBot1 == -1){
                directionBot1 = rand() % 2;
                if (directionBot1 == TOP_DOWN){
                    lastXBot1 = MapSize;
                    lastYBot1 = 1;
                }
                else {
                    lastXBot1 = 1;
                    lastYBot1 = MapSize;
                }
            }

            while (map[lastYBot1][lastXBot1] != EMPTY_PLATE && map[lastYBot1][lastXBot1] != SHIP_PLATE){
                if (directionBot1 == TOP_DOWN){
                    lastXBot1--;
                    lastYBot1++;
                }
                if (directionBot1 == DOWN_TOP){
                    lastXBot1++;
                    lastYBot1--;
                }

                if (directionBot1 == TOP_DOWN && (lastXBot1 < 1 || lastYBot1 > MapSize)){
                    directionBot1 = rand() % 2;
                    if (directionBot1 == TOP_DOWN){
                        lastXBot1 = MapSize - (rand() % MapSize);
                        lastYBot1 = 1;
                    }
                    else {
                        lastXBot1 = 1 + (rand() % MapSize);
                        lastYBot1 = MapSize; 
                    }
                }
                if (directionBot1 == DOWN_TOP && (lastXBot1 > MapSize || lastYBot1 < 1)){
                    directionBot1 = rand() % 2;
                    if (directionBot1 == TOP_DOWN){
                        lastXBot1 = MapSize - (rand() % MapSize);
                        lastYBot1 = 1;
                    }
                    else {
                        lastXBot1 = 1 + (rand() % MapSize);
                        lastYBot1 = MapSize; 
                    }
                }
            }

            if (map[lastYBot1][lastXBot1] == EMPTY_PLATE){
                map[lastYBot1][lastXBot1] = MISS_PLATE;
                *x = lastXBot1;
                *y = lastYBot1;
                return MISS_PLATE;
            }
            else if (map[lastYBot1][lastXBot1] == SHIP_PLATE){
                map[lastYBot1][lastXBot1] = HIT_PLATE;
                *x = lastXBot1;
                *y = lastYBot1;
                return HIT_PLATE;
            } 
            
        }
        else {
            directionBot1 = -1;
            lastXBot1 = -1;
            lastYBot1 = -1;
        }
    }
    else if (botCount == BOT_2_SHOT){
        if (gameStatus != GAME_END){
            //Проверка, что игра не закончилась
            for (int i = 1; i <= MapSize; i++){
                for (int j = 1; j <= MapSize; j++){
                    if (map[i][j] == EMPTY_PLATE || map[i][j] == SHIP_PLATE){
                        endGameFlag = 1;
                    }
                }
            }
            if (!endGameFlag) return GAME_END;

            if (directionBot2 == -1){
                directionBot2 = rand() % 2;
                if (directionBot2 == TOP_DOWN){
                    lastXBot2 = MapSize;
                    lastYBot2 = 1;
                }
                else {
                    lastXBot2 = 1;
                    lastYBot2 = MapSize;
                }
            }

            while (map[lastYBot2][lastXBot2] != EMPTY_PLATE && map[lastYBot2][lastXBot2] != SHIP_PLATE){
                if (directionBot2 == TOP_DOWN){
                    lastXBot2--;
                    lastYBot2++;
                }
                if (directionBot2 == DOWN_TOP){
                    lastXBot2++;
                    lastYBot2--;
                }

                if (directionBot2 == TOP_DOWN && (lastXBot2 < 1 || lastYBot2 > MapSize)){
                    directionBot2 = rand() % 2;
                    if (directionBot2 == TOP_DOWN){
                        lastXBot2 = MapSize - (rand() % MapSize);
                        lastYBot2 = 1;
                    }
                    else {
                        lastXBot2 = 1 + (rand() % MapSize);
                        lastYBot2 = MapSize; 
                    }
                }
                if (directionBot2 == DOWN_TOP && (lastXBot2 > MapSize || lastYBot2 < 1)){
                    directionBot2 = rand() % 2;
                    if (directionBot2 == TOP_DOWN){
                        lastXBot2 = MapSize - (rand() % MapSize);
                        lastYBot2 = 1;
                    }
                    else {
                        lastXBot2 = 1 + (rand() % MapSize);
                        lastYBot2 = MapSize; 
                    }
                }
            }

            if (map[lastYBot2][lastXBot2] == EMPTY_PLATE){
                map[lastYBot2][lastXBot2] = MISS_PLATE;
                *x = lastXBot2;
                *y = lastYBot2;
                return MISS_PLATE;
            }
            else if (map[lastYBot2][lastXBot2] == SHIP_PLATE){
                map[lastYBot2][lastXBot2] = HIT_PLATE;
                *x = lastXBot2;
                *y = lastYBot2;
                return HIT_PLATE;
            } 
            
        }
        else {
            directionBot2 = -1;
            lastXBot2 = -1;
            lastYBot2 = -1;
        }
    }
}

//Режим добивания для ботов уровня сложности Hard в режиме bots fight
int finishingOffBF(int x, int y, int map[18][18], ShipBase* shipBase, int AttackStatus, int MapSize, int botCount)
{
    static int lastAttackCoordXBot1 = -1;
    static int lastAttackCoordYBot1 = -1;
    static int AttackDirectionBot1 = -1;
    static int directionsArrayBot1[4] = {0, 0, 0, 0};

    static int lastAttackCoordXBot2 = -1;
    static int lastAttackCoordYBot2 = -1;
    static int AttackDirectionBot2 = -1;
    static int directionsArrayBot2[4] = {0, 0, 0, 0};

    if (botCount == BOT_1_SHOT){
        if (AttackStatus == ATTACK_PROCESS){

            if (AttackDirectionBot1 == -1){
                AttackDirectionBot1 = rand() % 4;
                while (AttackDirectionBot1 != 0) AttackDirectionBot1 = rand() % 4;
            }
            if (lastAttackCoordXBot1 == -1) lastAttackCoordXBot1 = x;
            if (lastAttackCoordYBot1 == -1) lastAttackCoordYBot1 = y;

            /*
                Выбор корректного направления для атаки
                Проверяется:
                    1. Не стреляли ли уже в клетку, в которуб планируется сделать атаку
                    2. Не выходит ли атака за границы поля
            
            */

            if (AttackDirectionBot1 == UP && (map[lastAttackCoordYBot1 - 1][lastAttackCoordXBot1] == HIT_PLATE || map[lastAttackCoordYBot1 - 1][lastAttackCoordXBot1] == MISS_PLATE || map[lastAttackCoordYBot1 - 1][lastAttackCoordXBot1] == AROUND_SHIP_PLATE || lastAttackCoordYBot1 - 1 < 1)){
                AttackDirectionBot1 = DOWN;
                if (AttackDirectionBot1 == DOWN && (map[y + 1][x] == HIT_PLATE || map[y + 1][x] == MISS_PLATE || map[y + 1][x] == AROUND_SHIP_PLATE || y + 1 > MapSize)){
                    AttackDirectionBot1 = rand() % 2 + 2;
                    if (AttackDirectionBot1 == RIGHT && (map[y][x + 1] == HIT_PLATE || map[y][x + 1] == MISS_PLATE || map[y][x + 1] == AROUND_SHIP_PLATE || x + 1 > MapSize)){
                        AttackDirectionBot1 = LEFT;
                    }
                    if (AttackDirectionBot1 == LEFT && (map[y][x - 1] == HIT_PLATE || map[y][x - 1] == MISS_PLATE || map[y][x - 1] == AROUND_SHIP_PLATE || x - 1 < 1)){
                        AttackDirectionBot1 = RIGHT;
                    }
                }
                directionsArrayBot1[AttackDirectionBot1] = 1;
                lastAttackCoordXBot1 = x;
                lastAttackCoordYBot1 = y;
            }
            else if (AttackDirectionBot1 == DOWN && (map[lastAttackCoordYBot1 + 1][lastAttackCoordXBot1] == HIT_PLATE || map[lastAttackCoordYBot1 + 1][lastAttackCoordXBot1] == MISS_PLATE || map[lastAttackCoordYBot1 + 1][lastAttackCoordXBot1] == AROUND_SHIP_PLATE || lastAttackCoordYBot1 + 1 > MapSize)){
                AttackDirectionBot1 = UP;
                if (AttackDirectionBot1 == UP && (map[y - 1][x] == HIT_PLATE || map[y - 1][x] == MISS_PLATE || map[y - 1][x] == AROUND_SHIP_PLATE || y - 1 < 1)){
                    AttackDirectionBot1 = rand() % 2 + 2;
                    if (AttackDirectionBot1 == RIGHT && (map[y][x + 1] == HIT_PLATE || map[y][x + 1] == MISS_PLATE || map[y][x + 1] == AROUND_SHIP_PLATE || x + 1 > MapSize)){
                        AttackDirectionBot1 = LEFT;
                    }
                    if (AttackDirectionBot1 == LEFT && (map[y][x - 1] == HIT_PLATE || map[y][x - 1] == MISS_PLATE || map[x][y - 1] == AROUND_SHIP_PLATE || x - 1 < 1)){
                        AttackDirectionBot1 = RIGHT;
                    }
                }
                directionsArrayBot1[AttackDirectionBot1] = 1;
                lastAttackCoordXBot1 = x;
                lastAttackCoordYBot1 = y;
            }
            else if (AttackDirectionBot1 == RIGHT && (map[lastAttackCoordYBot1][lastAttackCoordXBot1 + 1] == HIT_PLATE || map[lastAttackCoordYBot1][lastAttackCoordXBot1 + 1] == MISS_PLATE || map[lastAttackCoordYBot1][lastAttackCoordXBot1 + 1] == AROUND_SHIP_PLATE || lastAttackCoordXBot1 + 1 > MapSize)){
                AttackDirectionBot1 = LEFT;
                if (AttackDirectionBot1 == LEFT && (map[y][x - 1] == HIT_PLATE || map[y][x - 1] == MISS_PLATE || map[y][x - 1] == AROUND_SHIP_PLATE || x - 1 < 1)){
                    AttackDirectionBot1 = rand() % 2;
                    if (AttackDirectionBot1 == DOWN && (map[y + 1][x] == HIT_PLATE || map[y + 1][x] == MISS_PLATE || map[y + 1][x] == AROUND_SHIP_PLATE || y + 1 > MapSize)){
                        AttackDirectionBot1 = UP;
                    }
                    if (AttackDirectionBot1 == UP && (map[y - 1][x] == HIT_PLATE || map[y - 1][x] == MISS_PLATE || map[y - 1][x] == AROUND_SHIP_PLATE || y - 1 < 1)){
                        AttackDirectionBot1 = DOWN;
                    }
                }
                directionsArrayBot1[AttackDirectionBot1] = 1;
                lastAttackCoordXBot1 = x;
                lastAttackCoordYBot1 = y;
            }
            else if (AttackDirectionBot1 == LEFT && (map[lastAttackCoordYBot1][lastAttackCoordXBot1 - 1] == HIT_PLATE || map[lastAttackCoordYBot1][lastAttackCoordXBot1 - 1] == MISS_PLATE || map[lastAttackCoordYBot1][lastAttackCoordXBot1 - 1] == AROUND_SHIP_PLATE || lastAttackCoordXBot1 - 1 < 1)){
                AttackDirectionBot1 = RIGHT;
                if (AttackDirectionBot1 == RIGHT && (map[y][x + 1] == HIT_PLATE || map[y][x + 1] == MISS_PLATE || map[y][x + 1] == AROUND_SHIP_PLATE || x + 1 > MapSize)){
                    AttackDirectionBot1 = rand() % 2;
                    if (AttackDirectionBot1 == DOWN && (map[y + 1][x] == HIT_PLATE || map[y + 1][x] == MISS_PLATE || map[y + 1][x] == AROUND_SHIP_PLATE || y + 1 > MapSize)){
                        AttackDirectionBot1 = UP;
                    }
                    if (AttackDirectionBot1 == UP && (map[y - 1][x] == HIT_PLATE || map[y - 1][x] == MISS_PLATE || map[y - 1][x] == AROUND_SHIP_PLATE || y - 1 < 1)){
                        AttackDirectionBot1 = DOWN;
                    }
                }
                directionsArrayBot1[AttackDirectionBot1] = 1;
                lastAttackCoordXBot1 = x;
                lastAttackCoordYBot1 = y;
            }

            if (AttackDirectionBot1 == UP){
                lastAttackCoordYBot1--;
                if (map[lastAttackCoordYBot1][lastAttackCoordXBot1] == SHIP_PLATE){
                    map[lastAttackCoordYBot1][lastAttackCoordXBot1] = HIT_PLATE;
                    if (killShipInShipBase(shipBase, lastAttackCoordXBot1 - 1, lastAttackCoordYBot1 - 1) == SHIP_KILLED){
                        return SHIP_KILLED;
                    }
                    else{
                        return HIT_PLATE;
                    }
                }
                else {
                    map[lastAttackCoordYBot1][lastAttackCoordXBot1] = MISS_PLATE;
                    AttackDirectionBot1 = -1;
                    lastAttackCoordXBot1 = x;
                    lastAttackCoordYBot1 = y;
                    return MISS_PLATE;
                }
            }

            if (AttackDirectionBot1 == DOWN){
                lastAttackCoordYBot1++;
                if (map[lastAttackCoordYBot1][lastAttackCoordXBot1] == SHIP_PLATE){
                    map[lastAttackCoordYBot1][lastAttackCoordXBot1] = HIT_PLATE;
                    if (killShipInShipBase(shipBase, lastAttackCoordXBot1 - 1, lastAttackCoordYBot1 - 1) == SHIP_KILLED){
                        return SHIP_KILLED;
                    }
                    else {
                        return HIT_PLATE;
                    }
                }
                else {
                    map[lastAttackCoordYBot1][lastAttackCoordXBot1] = MISS_PLATE;
                    AttackDirectionBot1 = -1;
                    lastAttackCoordXBot1 = x;
                    lastAttackCoordYBot1 = y;
                    return MISS_PLATE;
                }
            }

            if (AttackDirectionBot1 == RIGHT){
                lastAttackCoordXBot1++;
                if (map[lastAttackCoordYBot1][lastAttackCoordXBot1] == SHIP_PLATE){
                    map[lastAttackCoordYBot1][lastAttackCoordXBot1] = HIT_PLATE;
                    if (killShipInShipBase(shipBase, lastAttackCoordXBot1 - 1, lastAttackCoordYBot1 - 1) == SHIP_KILLED){
                        return SHIP_KILLED;
                    }
                    else {
                        return HIT_PLATE;
                    }
                }
                else {
                    map[lastAttackCoordYBot1][lastAttackCoordXBot1] = MISS_PLATE;
                    AttackDirectionBot1 = -1;
                    lastAttackCoordXBot1 = x;
                    lastAttackCoordYBot1 = y;
                    return MISS_PLATE;
                }
            }

            if (AttackDirectionBot1 == LEFT){
                lastAttackCoordXBot1--;
                if (map[lastAttackCoordYBot1][lastAttackCoordXBot1] == SHIP_PLATE){
                    map[lastAttackCoordYBot1][lastAttackCoordXBot1] = HIT_PLATE;
                    if (killShipInShipBase(shipBase, lastAttackCoordXBot1 - 1, lastAttackCoordYBot1 - 1) == SHIP_KILLED){
                        return SHIP_KILLED;
                    }
                    else {
                        return HIT_PLATE;
                    }
                }
                else {
                    map[lastAttackCoordYBot1][lastAttackCoordXBot1] = MISS_PLATE;
                    AttackDirectionBot1 = -1;
                    lastAttackCoordXBot1 = x;
                    lastAttackCoordYBot1 = y;
                    return MISS_PLATE;
                }
            }
        }
        else {
            lastAttackCoordXBot1 = -1;
            lastAttackCoordYBot1 = -1;
            AttackDirectionBot1 = -1;
            directionsArrayBot1[0] = 0;
            directionsArrayBot1[1] = 0;
            directionsArrayBot1[2] = 0;
            directionsArrayBot1[3] = 0;
            return ATTACK_END;
        }

    }    
    else if (botCount == BOT_2_SHOT){
        if (AttackStatus == ATTACK_PROCESS){

            if (AttackDirectionBot2 == -1){
                AttackDirectionBot2 = rand() % 4;
                while (AttackDirectionBot2 != 0) AttackDirectionBot2 = rand() % 4;
            }
            if (lastAttackCoordXBot2 == -1) lastAttackCoordXBot2 = x;
            if (lastAttackCoordYBot2 == -1) lastAttackCoordYBot2 = y;

            /*
                Выбор корректного направления для атаки
                Проверяется:
                    1. Не стреляли ли уже в клетку, в которуб планируется сделать атаку
                    2. Не выходит ли атака за границы поля
            
            */

            if (AttackDirectionBot2 == UP && (map[lastAttackCoordYBot2 - 1][lastAttackCoordXBot2] == HIT_PLATE || map[lastAttackCoordYBot2 - 1][lastAttackCoordXBot2] == MISS_PLATE || map[lastAttackCoordYBot2 - 1][lastAttackCoordXBot2] == AROUND_SHIP_PLATE || lastAttackCoordYBot2 - 1 < 1)){
                AttackDirectionBot2 = DOWN;
                if (AttackDirectionBot2 == DOWN && (map[y + 1][x] == HIT_PLATE || map[y + 1][x] == MISS_PLATE || map[y + 1][x] == AROUND_SHIP_PLATE || y + 1 > MapSize)){
                    AttackDirectionBot2 = rand() % 2 + 2;
                    if (AttackDirectionBot2 == RIGHT && (map[y][x + 1] == HIT_PLATE || map[y][x + 1] == MISS_PLATE || map[y][x + 1] == AROUND_SHIP_PLATE || x + 1 > MapSize)){
                        AttackDirectionBot2 = LEFT;
                    }
                    if (AttackDirectionBot2 == LEFT && (map[y][x - 1] == HIT_PLATE || map[y][x - 1] == MISS_PLATE || map[y][x - 1] == AROUND_SHIP_PLATE || x - 1 < 1)){
                        AttackDirectionBot2 = RIGHT;
                    }
                }
                directionsArrayBot2[AttackDirectionBot2] = 1;
                lastAttackCoordXBot2 = x;
                lastAttackCoordYBot2 = y;
            }
            else if (AttackDirectionBot2 == DOWN && (map[lastAttackCoordYBot2 + 1][lastAttackCoordXBot2] == HIT_PLATE || map[lastAttackCoordYBot2 + 1][lastAttackCoordXBot2] == MISS_PLATE || map[lastAttackCoordYBot2 + 1][lastAttackCoordXBot2] == AROUND_SHIP_PLATE || lastAttackCoordYBot2 + 1 > MapSize)){
                AttackDirectionBot2 = UP;
                if (AttackDirectionBot2 == UP && (map[y - 1][x] == HIT_PLATE || map[y - 1][x] == MISS_PLATE || map[y - 1][x] == AROUND_SHIP_PLATE || y - 1 < 1)){
                    AttackDirectionBot2 = rand() % 2 + 2;
                    if (AttackDirectionBot2 == RIGHT && (map[y][x + 1] == HIT_PLATE || map[y][x + 1] == MISS_PLATE || map[y][x + 1] == AROUND_SHIP_PLATE || x + 1 > MapSize)){
                        AttackDirectionBot2 = LEFT;
                    }
                    if (AttackDirectionBot2 == LEFT && (map[y][x - 1] == HIT_PLATE || map[y][x - 1] == MISS_PLATE || map[y][x - 1] == AROUND_SHIP_PLATE || x - 1 < 1)){
                        AttackDirectionBot2 = RIGHT;
                    }
                }
                directionsArrayBot2[AttackDirectionBot2] = 1;
                lastAttackCoordXBot2 = x;
                lastAttackCoordYBot2 = y;
            }
            else if (AttackDirectionBot2 == RIGHT && (map[lastAttackCoordYBot2][lastAttackCoordXBot2 + 1] == HIT_PLATE || map[lastAttackCoordYBot2][lastAttackCoordXBot2 + 1] == MISS_PLATE || map[lastAttackCoordYBot2][lastAttackCoordXBot2 + 1] == AROUND_SHIP_PLATE || lastAttackCoordXBot2 + 1 > MapSize)){
                AttackDirectionBot2 = LEFT;
                if (AttackDirectionBot2 == LEFT && (map[y][x - 1] == HIT_PLATE || map[y][x - 1] == MISS_PLATE || map[y][x - 1] == AROUND_SHIP_PLATE || x - 1 < 1)){
                    AttackDirectionBot2 = rand() % 2;
                    if (AttackDirectionBot2 == DOWN && (map[y + 1][x] == HIT_PLATE || map[y + 1][x] == MISS_PLATE || map[y + 1][x] == AROUND_SHIP_PLATE || y + 1 > MapSize)){
                        AttackDirectionBot2 = UP;
                    }
                    if (AttackDirectionBot2 == UP && (map[y - 1][x] == HIT_PLATE || map[y - 1][x] == MISS_PLATE || map[y - 1][x] == AROUND_SHIP_PLATE || y - 1 < 1)){
                        AttackDirectionBot2 = DOWN;
                    }
                }
                directionsArrayBot2[AttackDirectionBot2] = 1;
                lastAttackCoordXBot2 = x;
                lastAttackCoordYBot2 = y;
            }
            else if (AttackDirectionBot2 == LEFT && (map[lastAttackCoordYBot2][lastAttackCoordXBot2 - 1] == HIT_PLATE || map[lastAttackCoordYBot2][lastAttackCoordXBot2 - 1] == MISS_PLATE || map[lastAttackCoordYBot2][lastAttackCoordXBot2 - 1] == AROUND_SHIP_PLATE || lastAttackCoordXBot2 - 1 < 1)){
                AttackDirectionBot2 = RIGHT;
                if (AttackDirectionBot2 == RIGHT && (map[y][x + 1] == HIT_PLATE || map[y][x + 1] == MISS_PLATE || map[y][x + 1] == AROUND_SHIP_PLATE || x + 1 > MapSize)){
                    AttackDirectionBot2 = rand() % 2;
                    if (AttackDirectionBot2 == DOWN && (map[y + 1][x] == HIT_PLATE || map[y + 1][x] == MISS_PLATE || map[y + 1][x] == AROUND_SHIP_PLATE || y + 1 > MapSize)){
                        AttackDirectionBot2 = UP;
                    }
                    if (AttackDirectionBot2 == UP && (map[y - 1][x] == HIT_PLATE || map[y - 1][x] == MISS_PLATE || map[y - 1][x] == AROUND_SHIP_PLATE || y - 1 < 1)){
                        AttackDirectionBot2 = DOWN;
                    }
                }
                directionsArrayBot2[AttackDirectionBot2] = 1;
                lastAttackCoordXBot2 = x;
                lastAttackCoordYBot2 = y;
            }

            if (AttackDirectionBot2 == UP){
                lastAttackCoordYBot2--;
                if (map[lastAttackCoordYBot2][lastAttackCoordXBot2] == SHIP_PLATE){
                    map[lastAttackCoordYBot2][lastAttackCoordXBot2] = HIT_PLATE;
                    if (killShipInShipBase(shipBase, lastAttackCoordXBot2 - 1, lastAttackCoordYBot2 - 1) == SHIP_KILLED){
                        return SHIP_KILLED;
                    }
                    else{
                        return HIT_PLATE;
                    }
                }
                else {
                    map[lastAttackCoordYBot2][lastAttackCoordXBot2] = MISS_PLATE;
                    AttackDirectionBot2 = -1;
                    lastAttackCoordXBot2 = x;
                    lastAttackCoordYBot2 = y;
                    return MISS_PLATE;
                }
            }

            if (AttackDirectionBot2 == DOWN){
                lastAttackCoordYBot2++;
                if (map[lastAttackCoordYBot2][lastAttackCoordXBot2] == SHIP_PLATE){
                    map[lastAttackCoordYBot2][lastAttackCoordXBot2] = HIT_PLATE;
                    if (killShipInShipBase(shipBase, lastAttackCoordXBot2 - 1, lastAttackCoordYBot2 - 1) == SHIP_KILLED){
                        return SHIP_KILLED;
                    }
                    else {
                        return HIT_PLATE;
                    }
                }
                else {
                    map[lastAttackCoordYBot2][lastAttackCoordXBot2] = MISS_PLATE;
                    AttackDirectionBot2 = -1;
                    lastAttackCoordXBot2 = x;
                    lastAttackCoordYBot2 = y;
                    return MISS_PLATE;
                }
            }

            if (AttackDirectionBot2 == RIGHT){
                lastAttackCoordXBot2++;
                if (map[lastAttackCoordYBot2][lastAttackCoordXBot2] == SHIP_PLATE){
                    map[lastAttackCoordYBot2][lastAttackCoordXBot2] = HIT_PLATE;
                    if (killShipInShipBase(shipBase, lastAttackCoordXBot2 - 1, lastAttackCoordYBot2 - 1) == SHIP_KILLED){
                        return SHIP_KILLED;
                    }
                    else {
                        return HIT_PLATE;
                    }
                }
                else {
                    map[lastAttackCoordYBot2][lastAttackCoordXBot2] = MISS_PLATE;
                    AttackDirectionBot2 = -1;
                    lastAttackCoordXBot2 = x;
                    lastAttackCoordYBot2 = y;
                    return MISS_PLATE;
                }
            }

            if (AttackDirectionBot2 == LEFT){
                lastAttackCoordXBot2--;
                if (map[lastAttackCoordYBot2][lastAttackCoordXBot2] == SHIP_PLATE){
                    map[lastAttackCoordYBot2][lastAttackCoordXBot2] = HIT_PLATE;
                    if (killShipInShipBase(shipBase, lastAttackCoordXBot2 - 1, lastAttackCoordYBot2 - 1) == SHIP_KILLED){
                        return SHIP_KILLED;
                    }
                    else {
                        return HIT_PLATE;
                    }
                }
                else {
                    map[lastAttackCoordYBot2][lastAttackCoordXBot2] = MISS_PLATE;
                    AttackDirectionBot2 = -1;
                    lastAttackCoordXBot2 = x;
                    lastAttackCoordYBot2 = y;
                    return MISS_PLATE;
                }
            }
        }
        else {
            lastAttackCoordXBot2 = -1;
            lastAttackCoordYBot2 = -1;
            AttackDirectionBot2 = -1;
            directionsArrayBot2[0] = 0;
            directionsArrayBot2[1] = 0;
            directionsArrayBot2[2] = 0;
            directionsArrayBot2[3] = 0;
            return ATTACK_END;
        }

    }
}



#endif