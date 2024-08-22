#include "bots.h"

#ifndef BOTS_C
#define BOTS_C

int lastAttackCoordX = -1;
int lastAttackCoordY = -1;
int AttackDirection = -1;


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

        if (step == 0) step = rand() % 8 + 2;
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
                    step = rand() % 8 + 2;  
                }
            }
        }
        printf("x: %d, y: %d ", lastX, lastY);
        printf("step %d\n", step);
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

        /*
            Выбор корректного направления для атаки
            Проверяется:
                1. Не стреляли ли уже в клетку, в которуб планируется сделать атаку
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

int hardLevelBot(int* x, int* y, int map[18][18], int MapSize, ShipBase* shipBase, int gameStatus)
{
    static int lastX = -1,
               lastY = -1,
               direction = -1,
               step = -1;
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
        direction = -1;
        lastX = -1;
        lastY = -1;
    }
    
}

int mediumLevelBotBF(int* x, int* y, int map[18][18], int mapSize, int botCount, int gameStatus)
{   
    static int stepBot1 = 0;
    static int directionBot1 = -1;
    static int lastXBot1 = -1;
    static int lastYBot1 = -1;

    static int stepBot2 = 0;
    static int directionBot2 = -1;
    static int lastXBot2 = -1;
    static int lastYBot2 = -1;

    int endGameFlag = 0;


    if (botCount == BOT_1_SHOT){
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

            if (stepBot1 == 0) stepBot1 = rand() % 8 + 2;
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
                        stepBot1 = rand() % 8 + 2;  
                    }
                }
            }
            printf("x: %d, y: %d ", lastXBot1, lastYBot1);
            printf("step %d\n", stepBot1);
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
            stepBot1 = 0;
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
                }
            }

            if (!endGameFlag) return GAME_END;

            if (stepBot2 == 0) stepBot2 = rand() % 8 + 2;
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
                        stepBot2 = rand() % 8 + 2;  
                    }
                }
            }
            printf("x: %d, y: %d ", lastXBot2, lastYBot2);
            printf("step %d\n", stepBot2);
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
            stepBot2 = 0;
            directionBot2 = -1;
            lastXBot2 = -1;
            lastYBot2 = -1;
        }
    }
}

int hardLevelBotBF(int* x, int* y, int map[18][18], int MapSize, ShipBase* shipBase, int botCount, int gameStatus)
{
    static int lastXBot1 = -1,
               lastYBot1 = -1,
               directionBot1 = -1,
               stepBot1 = -1;

    static int lastXBot2 = -1,
               lastYBot2 = -1,
               directionBot2 = -1,
               stepBot2 = -1;

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
            printf("%d, %d ", lastXBot1, lastYBot1);
            printf("%d\n", stepBot1);
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
            printf("%d, %d ", lastXBot2, lastYBot2);
            printf("%d\n", stepBot2);
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
           printf("BEFORE\n");
           printf("%d %d\n", lastAttackCoordXBot1, lastAttackCoordYBot1);
           if (AttackDirectionBot1 == UP) printf("BOT 1 UP\n");
           if (AttackDirectionBot1 == DOWN) printf("BOT 1 DOWN\n");
           if (AttackDirectionBot1 == RIGHT) printf("BOT 1 RIGHT\n");
           if (AttackDirectionBot1 == LEFT) printf("BOT 1 LEFT\n");

           for (int i = 1 ; i <= 10; i++){
            for (int j = 1; j <= 10; j++){
                printf("%d ", map[i][j]);
            }
            printf("\n");
           }
            if (AttackDirectionBot1 == UP && (map[lastAttackCoordYBot1 - 1][lastAttackCoordXBot1] == HIT_PLATE || map[lastAttackCoordYBot1 - 1][lastAttackCoordXBot1] == MISS_PLATE || map[lastAttackCoordYBot1 - 1][lastAttackCoordXBot1] == AROUND_SHIP_PLATE || lastAttackCoordYBot1 - 1 < 1)){
                AttackDirectionBot1 = DOWN;
                printf("XUI1\n");
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
                printf("XUI2\n");
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
                printf("XUI3\n");
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
                printf("XUI4\n");
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

            printf("AFTER\n");
           if (AttackDirectionBot1 == UP) printf("BOT 1 UP\n");
           else if (AttackDirectionBot1 == DOWN) printf("BOT 1 DOWN\n");
           else if (AttackDirectionBot1 == RIGHT) printf("BOT 1 RIGHT\n");
           else if (AttackDirectionBot1 == LEFT) printf("BOT 1 LEFT\n");
           else printf("ZALUPA BOT 1\n");

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
                        printf("KILL DOWN\n");
                        return SHIP_KILLED;
                    }
                    else {
                        printf("DOWN HIT\n");
                        return HIT_PLATE;
                    }
                }
                else {
                    printf("DOWN MISS\n");
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

            printf("BEFORE\n");
            if (AttackDirectionBot2 == UP) printf("BOT 2 UP\n");
           else if (AttackDirectionBot2 == DOWN) printf("BOT 2 DOWN\n");
           else if (AttackDirectionBot2 == RIGHT) printf("BOT 2 RIGHT\n");
           else if (AttackDirectionBot2 == LEFT) printf("BOT 2 LEFT\n");
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
            printf("AFTER\n");
            if (AttackDirectionBot2 == UP) printf("BOT 2 UP\n");
           else if (AttackDirectionBot2 == DOWN) printf("BOT 2 DOWN\n");
           else if (AttackDirectionBot2 == RIGHT) printf("BOT 2 RIGHT\n");
           else if (AttackDirectionBot2 == LEFT) printf("BOT 2 LEFT\n");
           else printf("ZALUPA BOT 2\n");

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