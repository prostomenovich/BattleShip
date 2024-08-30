#include "saveLoad.h"


#ifndef SAVELOAD_C
#define SAVELOAD_C

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
             ShipBase* shipBase2)
{
    extern int botMode;
    extern int botMode1;
    extern int botMode2;

    extern int lastAttackCoordX;
    extern int lastAttackCoordY;
    extern int AttackDirection;

    extern int lastX;
    extern int lastY;
    extern int direction;
    extern int step;

    extern int stepBot1;
    extern int directionBot1;
    extern int lastXBot1;
    extern int lastYBot1;

    extern int stepBot2;
    extern int directionBot2;
    extern int lastXBot2;
    extern int lastYBot2;

    char* pathToSave = (char*)malloc(sizeof(char) * (strlen(pathToFolder) + strlen(saveName) + 3));
    if (pathToSave == NULL){
        printf("Mem alloc for path to save ERROR!\n");
        return SAVE_ERROR;
    }
    memset(pathToSave, '\0', strlen(pathToFolder) + strlen(saveName) + 3);
    strcat(pathToSave, pathToFolder);
    strcat(pathToSave, saveName);

    FILE* SAVEFILE = NULL;
    SAVEFILE = fopen(pathToSave, "w");
    if (SAVEFILE == NULL){
        printf("Save file open ERROR!\n");
        free(pathToSave);
        return SAVE_ERROR;
    }

    fprintf(SAVEFILE,"m:%d\nms:%d\nbl:%d\ns1:%d\ns2:%d\nstate:%d\n", mode, mapSize, botLevel, score1, score2, sceneState);
    if (botLevel == HARD_BOT_LEVEL){
        if(mode == BASIC_MODE)
            fprintf(SAVEFILE,"bm:%d\n", botMode);
        else if (mode == BOTS_FIGHT_MODE)
            fprintf(SAVEFILE,"bm1:%d\nbm2:%d\n", botMode1, botMode2);
    }
    if (botLevel == HARD_BOT_LEVEL || botLevel == NORMAL_BOT_LEVEL){
        if (mode == BASIC_MODE){
            fprintf(SAVEFILE, "lx:%d\nly:%d\nd:%d\ns:%d\n", lastX, lastY, direction, step);
        }
        else if (mode == BOTS_FIGHT_MODE){
            fprintf(SAVEFILE, "lx1:%d\nlx2:%d\nly1:%d\nly2:%d\nd1:%d\nd2:%d\ns1:%d\ns2:%d\n", lastXBot1, lastXBot2, lastYBot1, lastYBot2, directionBot1, directionBot2, stepBot1, stepBot2);
        }
    }
    fprintf(SAVEFILE, "m1:\n");
    for (int i = 0; i < 18; i++){
        for (int j = 0; j < 18; j++){
            fprintf(SAVEFILE, "%d ", map1[i][j]);
        }
        fprintf(SAVEFILE, "\n");
    }

    fprintf(SAVEFILE, "sb1:\n");
    ShipBase* sb = shipBase1;
    while (sb != NULL){
        fprintf(SAVEFILE, "t:%d\n", sb->shipType);
        for (int i = 0; i < sb->shipsCount; i++){
            fprintf(SAVEFILE, "l:%d\n", sb->ships[i]->lives);
            for (int j = 0; j < sb->shipType; j++){
                fprintf(SAVEFILE, "%d %d\n", sb->ships[i]->coords[j]->x, sb->ships[i]->coords[j]->y);
            }
        }
        sb = sb->nextShip;
    }

    fprintf(SAVEFILE, "m2:\n");
    for (int i = 0; i < 18; i++){
        for (int j = 0; j < 18; j++){
            fprintf(SAVEFILE, "%d ", map2[i][j]);
        }
        fprintf(SAVEFILE, "\n");
    }
    
    sb = shipBase2;
    fprintf(SAVEFILE, "sb2:\n");
    while (sb != NULL){
        fprintf(SAVEFILE, "t:%d\n", sb->shipType);
        for (int i = 0; i < sb->shipsCount; i++){
            fprintf(SAVEFILE, "l:%d\n", sb->ships[i]->lives);
            for (int j = 0; j < sb->shipType; j++){
                fprintf(SAVEFILE, "%d %d\n", sb->ships[i]->coords[j]->x, sb->ships[i]->coords[j]->y);
            }
        }
        sb = sb->nextShip;
    }


    free(pathToSave);
    fclose(SAVEFILE);
    
    return SAVE_SUCCESS;
}

int loadGame(char* pathToFolder, char* saveName)
{
    extern int playerScore;
    extern int botScore;
    extern int bot1Score;
    extern int bot2Score;
 
    extern int map[18][18];
    extern int mapBot[18][18];
    extern int mapBot1[18][18];
    extern int mapBot2[18][18];

    extern Player playerInfo;

    extern MainGameBase10x10 sMainGameBase10x10;
    extern MainGameBase15x15 sMainGameBase15x15;
    extern MainGameBotFight10x10 sMainGameBotFight10x10;
    extern MainGameBotFight15x15 sMainGameBotFight15x15;

    extern ShipBase* shipBase;
    extern ShipBase* botShipBase;
    extern ShipBase* shipBaseBFBot1;
    extern ShipBase* shipBaseBFBot2;

    extern int botMode;
    extern int botMode1;
    extern int botMode2;

    extern int lastAttackCoordX;
    extern int lastAttackCoordY;
    extern int AttackDirection;

    extern int lastX;
    extern int lastY;
    extern int direction;
    extern int step;

    extern int stepBot1;
    extern int directionBot1;
    extern int lastXBot1;
    extern int lastYBot1;

    extern int stepBot2;
    extern int directionBot2;
    extern int lastXBot2;
    extern int lastYBot2;

    char symb;
    int sCounter = 0;
    int state = 0;
    printf("load started!\n");
    char* pathToSave = (char*)malloc(sizeof(char) * (strlen(pathToFolder) + strlen(saveName) + 3));
    if (pathToSave == NULL){
        printf("Mem alloc for path to save ERROR!\n");
        return SAVE_ERROR;
    }
    memset(pathToSave, '\0', strlen(pathToFolder) + strlen(saveName) + 3);
    strcat(pathToSave, pathToFolder);
    strcat(pathToSave, saveName);
    printf("string made!\n");

    FILE* SAVEFILE = NULL;
    SAVEFILE = fopen(pathToSave, "r");
    if (SAVEFILE == NULL){
        printf("Save file open ERROR!\n");
        free(pathToSave);
        return SAVE_ERROR;
    }
    printf("file was open!\n");
    if (fscanf(SAVEFILE,"m:%d\nms:%d\nbl:%d\n", &playerInfo.GameMode, &playerInfo.MapSize, &playerInfo.BotLevel) != 3){
        playerInfo.BotLevel = NOT_FILLED_IN;
        playerInfo.GameMode = NOT_FILLED_IN;
        playerInfo.MapSize = NOT_FILLED_IN;
        free(pathToSave);
        fclose(SAVEFILE);
        return LOAD_ERROR;
    }

    if ((playerInfo.GameMode == BASIC_MODE && playerInfo.MapSize == MAP_SIZE_10_X_10) || (playerInfo.GameMode == BASIC_MODE && playerInfo.MapSize == MAP_SIZE_15_X_15)){
        if (fscanf(SAVEFILE,"s1:%d\ns2:%d\n", &playerScore, &botScore) != 2){
            playerInfo.BotLevel = NOT_FILLED_IN;
            playerInfo.GameMode = NOT_FILLED_IN;
            playerInfo.MapSize = NOT_FILLED_IN;
            playerScore = 0;
            botScore = 0;
            free(pathToSave);
            fclose(SAVEFILE);
            return LOAD_ERROR;
        }
        if ((fscanf(SAVEFILE, "state:%d\n", &state) == 1)){
            if ((state != BOT_SHOT && state != PLAYER_SHOT)){
                playerInfo.BotLevel = NOT_FILLED_IN;
                playerInfo.GameMode = NOT_FILLED_IN;
                playerInfo.MapSize = NOT_FILLED_IN;
                playerScore = 0;
                botScore = 0;
                free(pathToSave);
                fclose(SAVEFILE);
                return LOAD_ERROR;
            }
        }

        if(playerInfo.GameMode == BASIC_MODE && playerInfo.MapSize == MAP_SIZE_10_X_10){
            sMainGameBase10x10.state = state;
        }
        else if(playerInfo.GameMode == BASIC_MODE && playerInfo.MapSize == MAP_SIZE_15_X_15){
            sMainGameBase15x15.state = state;
        }
        
    }
    else if ((playerInfo.GameMode == BOTS_FIGHT_MODE && playerInfo.MapSize == MAP_SIZE_10_X_10) || (playerInfo.GameMode == BOTS_FIGHT_MODE && playerInfo.MapSize == MAP_SIZE_15_X_15)){
        if (fscanf(SAVEFILE,"s1:%d\ns2:%d\n", &bot1Score, &bot2Score) != 2){
            playerInfo.BotLevel = NOT_FILLED_IN;
            playerInfo.GameMode = NOT_FILLED_IN;
            playerInfo.MapSize = NOT_FILLED_IN;
            bot1Score = 0;
            bot2Score = 0;
            free(pathToSave);
            fclose(SAVEFILE);
            return LOAD_ERROR;
        }
        if ((fscanf(SAVEFILE, "state:%d\n", &state) == 1)){
            if ((state != BOT_1_SHOT && state != BOT_2_SHOT)){
                playerInfo.BotLevel = NOT_FILLED_IN;
                playerInfo.GameMode = NOT_FILLED_IN;
                playerInfo.MapSize = NOT_FILLED_IN;
                bot1Score = 0;
                bot2Score = 0;
                free(pathToSave);
                fclose(SAVEFILE);
                return LOAD_ERROR;
            }
        }

        if(playerInfo.GameMode == BOTS_FIGHT_MODE && playerInfo.MapSize == MAP_SIZE_10_X_10){
            sMainGameBotFight10x10.state = state;
        }
        else if(playerInfo.GameMode == BOTS_FIGHT_MODE && playerInfo.MapSize == MAP_SIZE_15_X_15){
            sMainGameBotFight15x15.state = state;
        }
        
    }
    else{
        playerInfo.BotLevel = NOT_FILLED_IN;
        playerInfo.GameMode = NOT_FILLED_IN;
        playerInfo.MapSize = NOT_FILLED_IN;
        bot1Score = 0;
        bot2Score = 0;
        playerScore = 0;
        botScore = 0;
        free(pathToSave);
        fclose(SAVEFILE);
            
        return LOAD_ERROR;
    }

    if (playerInfo.BotLevel != EASY_BOT_LEVEL && playerInfo.BotLevel != NORMAL_BOT_LEVEL && playerInfo.BotLevel != HARD_BOT_LEVEL){
        playerInfo.BotLevel = NOT_FILLED_IN;
        playerInfo.GameMode = NOT_FILLED_IN;
        playerInfo.MapSize = NOT_FILLED_IN;
        bot1Score = 0;
        bot2Score = 0;
        playerScore = 0;
        botScore = 0;
        free(pathToSave);
        fclose(SAVEFILE);
            
        return LOAD_ERROR;
    }

    if (playerInfo.BotLevel == HARD_BOT_LEVEL){
        if(playerInfo.GameMode == BASIC_MODE)
            fscanf(SAVEFILE,"bm:%d\n", &botMode);
        else if (playerInfo.GameMode == BOTS_FIGHT_MODE)
            fscanf(SAVEFILE,"bm1:%d\nbm2:%d\n", &botMode1, &botMode2);
    }
    if (playerInfo.BotLevel == HARD_BOT_LEVEL || playerInfo.BotLevel == NORMAL_BOT_LEVEL){
        if (playerInfo.GameMode == BASIC_MODE){
            fscanf(SAVEFILE, "lx:%d\nly:%d\nd:%d\ns:%d\n", &lastX, &lastY, &direction, &step);
        }
        else if (playerInfo.GameMode == BOTS_FIGHT_MODE){
            fscanf(SAVEFILE, "lx1:%d\nlx2:%d\nly1:%d\nly2:%d\nd1:%d\nd2:%d\ns1:%d\ns2:%d\n", &lastXBot1, &lastXBot2, &lastYBot1, &lastYBot2, &directionBot1, &directionBot2, &stepBot1, &stepBot2);
        }
    }

    

    printf("m:%d\nms:%d\nbl:%d\ns1:%d\ns2:%d\nstate:%d", playerInfo.GameMode, playerInfo.MapSize, playerInfo.BotLevel, playerScore, botScore, state);
    printf("base info was getting\n");
    fseek(SAVEFILE, 4, SEEK_CUR);

    int counter = 0,
        data = 0,
        x = 0,
        y = 0;

    if (playerInfo.GameMode == BASIC_MODE){
        for (int i = 0; i < 18; i++){
            for (int j = 0; j < 18; j++){
                if (fscanf(SAVEFILE, "%d", &data) != 1){
                    playerInfo.BotLevel = NOT_FILLED_IN;
                    playerInfo.GameMode = NOT_FILLED_IN;
                    playerInfo.MapSize = NOT_FILLED_IN;
                    playerScore = 0;
                    botScore = 0;
                    clearMap(map);
                    free(pathToSave);
                    fclose(SAVEFILE);
                    return LOAD_ERROR;
                }
                fgetc(SAVEFILE);
                map[i][j] = data;  
            }
            fgetc(SAVEFILE);
        }
    }
    else if (playerInfo.GameMode == BOTS_FIGHT_MODE){
        for (int i = 0; i < 18; i++){
            for (int j = 0; j < 18; j++){
                if (fscanf(SAVEFILE, "%d", &data) != 1){
                    playerInfo.BotLevel = NOT_FILLED_IN;
                    playerInfo.GameMode = NOT_FILLED_IN;
                    playerInfo.MapSize = NOT_FILLED_IN;
                    playerScore = 0;
                    botScore = 0;
                    clearMap(map);
                    free(pathToSave);
                    fclose(SAVEFILE);
                    return LOAD_ERROR;
                }
                fgetc(SAVEFILE);
                mapBot1[i][j] = data;  
            }
            fgetc(SAVEFILE);
        }
    }
    else {
        playerInfo.BotLevel = NOT_FILLED_IN;
        playerInfo.GameMode = NOT_FILLED_IN;
        playerInfo.MapSize = NOT_FILLED_IN;
        bot1Score = 0;
        bot2Score = 0;
        playerScore = 0;
        botScore = 0;
        clearMap(mapBot1);
        clearMap(map);
        free(pathToSave);
        fclose(SAVEFILE);
        return LOAD_ERROR;
    }
    printf("First map was getting!\n");
    fseek(SAVEFILE, 5, SEEK_CUR);
    
    if (playerInfo.GameMode == BASIC_MODE){
        //if (shipBase != NULL) freeShipBase(shipBase);

        if (playerInfo.MapSize == MAP_SIZE_10_X_10) shipBase = initShipBase(MAP_SIZE_10_X_10);
        else if (playerInfo.MapSize == MAP_SIZE_15_X_15) shipBase = initShipBase(MAP_SIZE_15_X_15);
        else {
            playerInfo.BotLevel = NOT_FILLED_IN;
            playerInfo.GameMode = NOT_FILLED_IN;
            playerInfo.MapSize = NOT_FILLED_IN;
            playerScore = 0;
            botScore = 0;
            clearMap(map);
            free(pathToSave);
            fclose(SAVEFILE);
            return LOAD_ERROR;
        }
        
        ShipBase* sb = shipBase;
        while(sb != NULL){
            if (fscanf(SAVEFILE, "t:%d\n", &data) != 1){
                playerInfo.BotLevel = NOT_FILLED_IN;
                playerInfo.GameMode = NOT_FILLED_IN;
                playerInfo.MapSize = NOT_FILLED_IN;
                playerScore = 0;
                botScore = 0;
                clearMap(map);
                free(shipBase);
                free(pathToSave);
                fclose(SAVEFILE);
                return LOAD_ERROR;
            }

            for (int i = 0; i < sb->shipsCount; i++){
                if (fscanf(SAVEFILE, "l:%d\n", &data) != 1){
                    playerInfo.BotLevel = NOT_FILLED_IN;
                    playerInfo.GameMode = NOT_FILLED_IN;
                    playerInfo.MapSize = NOT_FILLED_IN;
                    playerScore = 0;
                    botScore = 0;
                    clearMap(map);
                    freeShipBase(shipBase);
                    free(pathToSave);
                    fclose(SAVEFILE);
                    return LOAD_ERROR;
                }
                
                sb->ships[i]->lives = data;
                for(int j = 0; j < sb->shipType; j++){
                    if (fscanf(SAVEFILE, "%d %d\n", &x, &y) != 2){
                        playerInfo.BotLevel = NOT_FILLED_IN;
                        playerInfo.GameMode = NOT_FILLED_IN;
                        playerInfo.MapSize = NOT_FILLED_IN;
                        playerScore = 0;
                        botScore = 0;
                        clearMap(map);
                        freeShipBase(shipBase);
                        free(pathToSave);
                        fclose(SAVEFILE);
                        return LOAD_ERROR;
                    }
                    sb->ships[i]->coords[j]->x = x;
                    sb->ships[i]->coords[j]->y = y;
                }
            }
            sb = sb->nextShip;
        }
    }
    else if (playerInfo.GameMode == BOTS_FIGHT_MODE){
        //if (shipBaseBFBot1 != NULL) freeShipBase(shipBaseBFBot1);

        if (playerInfo.MapSize == MAP_SIZE_10_X_10) shipBaseBFBot1 = initShipBase(MAP_SIZE_10_X_10);
        else if (playerInfo.MapSize == MAP_SIZE_15_X_15) shipBaseBFBot1 = initShipBase(MAP_SIZE_15_X_15);
        else {
            playerInfo.BotLevel = NOT_FILLED_IN;
            playerInfo.GameMode = NOT_FILLED_IN;
            playerInfo.MapSize = NOT_FILLED_IN;
            playerScore = 0;
            botScore = 0;
            clearMap(mapBot1);
            free(pathToSave);
            fclose(SAVEFILE);
            return LOAD_ERROR;
        }

        ShipBase* sb = shipBaseBFBot1;
        while(sb != NULL){
            if (fscanf(SAVEFILE, "t:%d\n", & data) != 1){
                playerInfo.BotLevel = NOT_FILLED_IN;
                playerInfo.GameMode = NOT_FILLED_IN;
                playerInfo.MapSize = NOT_FILLED_IN;
                playerScore = 0;
                botScore = 0;
                clearMap(mapBot1);
                freeShipBase(shipBaseBFBot1);
                free(pathToSave);
                fclose(SAVEFILE);
                return LOAD_ERROR;
            }

            for (int i = 0; i < sb->shipsCount; i++){
                if (fscanf(SAVEFILE, "l:%d\n", &data) != 1){
                    playerInfo.BotLevel = NOT_FILLED_IN;
                    playerInfo.GameMode = NOT_FILLED_IN;
                    playerInfo.MapSize = NOT_FILLED_IN;
                    playerScore = 0;
                    botScore = 0;
                    clearMap(mapBot1);
                    freeShipBase(shipBaseBFBot1);
                    free(pathToSave);
                    fclose(SAVEFILE);
                    return LOAD_ERROR;
                }
                
                sb->ships[i]->lives = data;
                for(int j = 0; j < sb->shipType; j++){
                    if (fscanf(SAVEFILE, "%d %d\n", &x, &y) != 2){
                        playerInfo.BotLevel = NOT_FILLED_IN;
                        playerInfo.GameMode = NOT_FILLED_IN;
                        playerInfo.MapSize = NOT_FILLED_IN;
                        playerScore = 0;
                        botScore = 0;
                        clearMap(mapBot1);
                        freeShipBase(shipBaseBFBot1);
                        free(pathToSave);
                        fclose(SAVEFILE);
                        return LOAD_ERROR;
                    }
                    sb->ships[i]->coords[j]->x = x;
                    sb->ships[i]->coords[j]->y = y;
                }
            }
            sb = sb->nextShip;
        }
    }
    else {
        playerInfo.BotLevel = NOT_FILLED_IN;
        playerInfo.GameMode = NOT_FILLED_IN;
        playerInfo.MapSize = NOT_FILLED_IN;
        bot1Score = 0;
        bot2Score = 0;
        playerScore = 0;
        botScore = 0;
        clearMap(mapBot1);
        clearMap(mapBot2);
        clearMap(mapBot);
        clearMap(map);
        free(pathToSave);
        fclose(SAVEFILE);
        return LOAD_ERROR;
    }
    printf("first shipBase was getting\n");

    /*ShipBase* sb = shipBase;
    while (sb != NULL){
        for (int i = 0; i < sb->shipsCount; i++){
            printf("l: %d\n", sb->ships[i]->lives);
            for (int j = 0; j < sb->shipType; j++){
                printf("%d %d\n", sb->ships[i]->coords[j]->x, sb->ships[i]->coords[j]->y);
            }
        }

        sb = sb->nextShip;
    }*/

    fseek(SAVEFILE, 4, SEEK_CUR);

    if (playerInfo.GameMode == BASIC_MODE){
        for (int i = 0; i < 18; i++){
            for (int j = 0; j < 18; j++){
                if (fscanf(SAVEFILE, "%d", &data) != 1){
                    playerInfo.BotLevel = NOT_FILLED_IN;
                    playerInfo.GameMode = NOT_FILLED_IN;
                    playerInfo.MapSize = NOT_FILLED_IN;
                    playerScore = 0;
                    botScore = 0;
                    clearMap(map);
                    clearMap(mapBot);
                    free(pathToSave);
                    freeShipBase(shipBase);
                    fclose(SAVEFILE);
                    return LOAD_ERROR;
                }
                fgetc(SAVEFILE);
                mapBot[i][j] = data;  
            }
            fgetc(SAVEFILE);
        }
    }
    else if (playerInfo.GameMode == BOTS_FIGHT_MODE){
        for (int i = 0; i < 18; i++){
            for (int j = 0; j < 18; j++){
                if (fscanf(SAVEFILE, "%d", &data) != 1){
                    playerInfo.BotLevel = NOT_FILLED_IN;
                    playerInfo.GameMode = NOT_FILLED_IN;
                    playerInfo.MapSize = NOT_FILLED_IN;
                    playerScore = 0;
                    botScore = 0;
                    clearMap(mapBot1);
                    clearMap(mapBot2);
                    free(pathToSave);
                    freeShipBase(shipBaseBFBot1);
                    fclose(SAVEFILE);
                    return LOAD_ERROR;
                }
                fgetc(SAVEFILE);
                mapBot2[i][j] = data;  
            }
            fgetc(SAVEFILE);
        }
    }
    else {
        playerInfo.BotLevel = NOT_FILLED_IN;
        playerInfo.GameMode = NOT_FILLED_IN;
        playerInfo.MapSize = NOT_FILLED_IN;
        bot1Score = 0;
        bot2Score = 0;
        playerScore = 0;
        botScore = 0;
        clearMap(mapBot1);
        clearMap(mapBot2);
        clearMap(mapBot);
        if (shipBase != NULL) freeShipBase(shipBase);
        if (shipBaseBFBot1 != NULL) freeShipBase(shipBaseBFBot1);
        clearMap(map);
        free(pathToSave);
        fclose(SAVEFILE);
        return LOAD_ERROR;
    }
    printf("second map was getting\n");
    fseek(SAVEFILE, 5, SEEK_CUR);

    if (playerInfo.GameMode == BASIC_MODE){
        //if (botShipBase != NULL) freeShipBase(botShipBase);

        if (playerInfo.MapSize == MAP_SIZE_10_X_10) botShipBase = initShipBase(MAP_SIZE_10_X_10);
        else if (playerInfo.MapSize == MAP_SIZE_15_X_15) botShipBase = initShipBase(MAP_SIZE_15_X_15);
        else {
            playerInfo.BotLevel = NOT_FILLED_IN;
            playerInfo.GameMode = NOT_FILLED_IN;
            playerInfo.MapSize = NOT_FILLED_IN;
            playerScore = 0;
            botScore = 0;
            clearMap(map);
            clearMap(mapBot);
            freeShipBase(shipBase);
            free(pathToSave);
            fclose(SAVEFILE);
            return LOAD_ERROR;
        }

        ShipBase* sb = botShipBase;
        while(sb != NULL){
            if (fscanf(SAVEFILE, "t:%d\n", & data) != 1){
                playerInfo.BotLevel = NOT_FILLED_IN;
                playerInfo.GameMode = NOT_FILLED_IN;
                playerInfo.MapSize = NOT_FILLED_IN;
                playerScore = 0;
                botScore = 0;
                clearMap(mapBot);
                clearMap(map);
                freeShipBase(shipBase);
                freeShipBase(botShipBase);
                free(pathToSave);
                fclose(SAVEFILE);
                return LOAD_ERROR;
            }

            for (int i = 0; i < sb->shipsCount; i++){
                if (fscanf(SAVEFILE, "l:%d\n", &data) != 1){
                    playerInfo.BotLevel = NOT_FILLED_IN;
                    playerInfo.GameMode = NOT_FILLED_IN;
                    playerInfo.MapSize = NOT_FILLED_IN;
                    playerScore = 0;
                    botScore = 0;
                    clearMap(mapBot);
                    clearMap(map);
                    freeShipBase(shipBase);
                    freeShipBase(botShipBase);
                    free(pathToSave);
                    fclose(SAVEFILE);
                    return LOAD_ERROR;
                }
                
                sb->ships[i]->lives = data;
                for(int j = 0; j < sb->shipType; j++){
                    if (fscanf(SAVEFILE, "%d %d\n", &x, &y) != 2){
                        playerInfo.BotLevel = NOT_FILLED_IN;
                        playerInfo.GameMode = NOT_FILLED_IN;
                        playerInfo.MapSize = NOT_FILLED_IN;
                        playerScore = 0;
                        botScore = 0;
                        clearMap(mapBot);
                        clearMap(map);
                        freeShipBase(shipBase);
                        freeShipBase(botShipBase);
                        free(pathToSave);
                        fclose(SAVEFILE);
                        return LOAD_ERROR;
                    }
                    sb->ships[i]->coords[j]->x = x;
                    sb->ships[i]->coords[j]->y = y;
                }
            }
            sb = sb->nextShip;
        }
    }
    else if (playerInfo.GameMode == BOTS_FIGHT_MODE){
        //if (shipBaseBFBot2 != NULL) freeShipBase(shipBaseBFBot2);

        if (playerInfo.MapSize == MAP_SIZE_10_X_10) shipBaseBFBot2  = initShipBase(MAP_SIZE_10_X_10);
        else if (playerInfo.MapSize == MAP_SIZE_15_X_15) shipBaseBFBot2  = initShipBase(MAP_SIZE_15_X_15);
        else {
            playerInfo.BotLevel = NOT_FILLED_IN;
            playerInfo.GameMode = NOT_FILLED_IN;
            playerInfo.MapSize = NOT_FILLED_IN;
            playerScore = 0;
            botScore = 0;
            clearMap(mapBot1);
            clearMap(mapBot2);
            freeShipBase(shipBaseBFBot1);
            free(pathToSave);
            fclose(SAVEFILE);
            return LOAD_ERROR;
        }

        ShipBase* sb = shipBaseBFBot2;
        while(sb != NULL){
            if (fscanf(SAVEFILE, "t:%d\n", & data) != 1){
                playerInfo.BotLevel = NOT_FILLED_IN;
                playerInfo.GameMode = NOT_FILLED_IN;
                playerInfo.MapSize = NOT_FILLED_IN;
                bot1Score = 0;
                bot2Score = 0;
                clearMap(mapBot1);
                clearMap(mapBot2);
                freeShipBase(shipBaseBFBot1);
                freeShipBase(shipBaseBFBot2);
                free(pathToSave);
                fclose(SAVEFILE);
                return LOAD_ERROR;
            }

            for (int i = 0; i < sb->shipsCount; i++){
                if (fscanf(SAVEFILE, "l:%d\n", &data) != 1){
                    playerInfo.BotLevel = NOT_FILLED_IN;
                    playerInfo.GameMode = NOT_FILLED_IN;
                    playerInfo.MapSize = NOT_FILLED_IN;
                    bot1Score = 0;
                    bot2Score = 0;
                    clearMap(mapBot1);
                    clearMap(mapBot2);
                    freeShipBase(shipBaseBFBot1);
                    freeShipBase(shipBaseBFBot2);
                    free(pathToSave);
                    fclose(SAVEFILE);
                    return LOAD_ERROR;
                }
                
                sb->ships[i]->lives = data;
                for(int j = 0; j < sb->shipType; j++){
                    if (fscanf(SAVEFILE, "%d %d\n", &x, &y) != 2){
                        playerInfo.BotLevel = NOT_FILLED_IN;
                        playerInfo.GameMode = NOT_FILLED_IN;
                        playerInfo.MapSize = NOT_FILLED_IN;
                        bot1Score = 0;
                        bot2Score = 0;
                        clearMap(mapBot1);
                        clearMap(mapBot2);
                        freeShipBase(shipBaseBFBot1);
                        freeShipBase(shipBaseBFBot2);
                        free(pathToSave);
                        fclose(SAVEFILE);
                        return LOAD_ERROR;
                    }
                    sb->ships[i]->coords[j]->x = x;
                    sb->ships[i]->coords[j]->y = y;
                }
            }
            sb = sb->nextShip;
        }
    }
    else {
        playerInfo.BotLevel = NOT_FILLED_IN;
        playerInfo.GameMode = NOT_FILLED_IN;
        playerInfo.MapSize = NOT_FILLED_IN;
        bot1Score = 0;
        bot2Score = 0;
        playerScore = 0;
        botScore = 0;
        clearMap(mapBot1);
        clearMap(mapBot2);
        clearMap(mapBot);
        clearMap(map);
        if (shipBase != NULL) freeShipBase(shipBase);
        if (shipBaseBFBot1 != NULL) freeShipBase(shipBaseBFBot1);
        free(pathToSave);
        fclose(SAVEFILE);
        return LOAD_ERROR;
    }
    printf("second shipBase was getting\n");
    free(pathToSave);
    fclose(SAVEFILE);

    return LOAD_SUCCESS;
}

SaveNamesList* getSaveNames(char* pathToFolder)
{
    DIR* directory;
    struct dirent* data;

    SaveNamesList* list = (SaveNamesList*)malloc(sizeof(SaveNamesList));
    if (list == NULL){
        printf("Mem alloc for save names list error!\n");
        return NULL;
    }

    directory = opendir(pathToFolder);
    if (directory != NULL){
        while ((data = readdir(directory)) != NULL){
            if (strcmp(data->d_name, ".") != 0 && strcmp(data->d_name, "..") != 0){
                list->count += 1;
            }
        }
        closedir(directory);

        directory = opendir(pathToFolder);

        list->names = (char**)malloc(sizeof(char*) * MAX_SAVE_NAMES);
        if (list->names == NULL){
            free(list);
            closedir(directory);
            return NULL;
        }

        for (int i = 0; i < list->count && i < MAX_SAVE_NAMES;){
            data = readdir(directory);
            if (strcmp(data->d_name, ".") != 0 && strcmp(data->d_name, "..") != 0){
                list->names[i] = (char*)malloc(sizeof(char) * MAX_SAVENAME_SIZE);
                memset(list->names[i], '\0', MAX_SAVENAME_SIZE);
                strncpy(list->names[i], data->d_name, MAX_SAVENAME_SIZE - 1);
                i++;
            } 
        }
    }
    else {
        free(list);
        return NULL;
    }

    return list;
}

void freeSaveNames(SaveNamesList* list){
    for (int i = 0 ; i < list->count && i < MAX_SAVE_NAMES; i++){
        free(list->names[i]);
    }
    free(list->names);
    free(list);
    list = NULL;
}

int delSave(char* pathToFolder, char* saveName)
{
    char* string = (char*)malloc(sizeof(char) * (strlen(pathToFolder) + strlen(saveName) + 4));
    if (string == NULL){
        printf("Mem alloc for del string ERROR!\n");
        return DELETE_ERROR;
    }

    memset(string, '\0', strlen(pathToFolder) + strlen(saveName) + 4);

    strcat(string, pathToFolder);
    strcat(string, saveName);

    if (remove(string) == 0){
        free(string);
        return DELETE_SUCCESS;
    }
    else{
        free(string);
        return DELETE_ERROR;
    }
}
#endif