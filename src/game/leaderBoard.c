#include "leaderBoard.h"


#ifndef LEADERBOARD_C
#define LEADERBOARD_C

void pushDataInLeaderBoard(char* nickname,int score, int MapSize, int BotLevel, char* LeaderBoardName)
{
    FILE* LEADERBOARD = NULL;

    LEADERBOARD = fopen(LeaderBoardName, "a+");
    if (LEADERBOARD == NULL){
        printf("LEADERBOARD OPEN ERROR (PUSH)!\n");
        return;
    }

    fprintf(LEADERBOARD, "%s|%d|%d|%d\n", nickname, MapSize, BotLevel, score);

    fclose(LEADERBOARD);
}

LeaderBoard* getDataFromLeaderBoard(char* LeaderBoardName)
{
    FILE* LEADERBOARD = NULL;
    LeaderBoard* leaderBoard = NULL;
    LeaderBoardNode** leaderBoardNodesArray = NULL;
    int nodeCount = 0;
    char symbol;

    LEADERBOARD = fopen(LeaderBoardName, "r");
    if (LEADERBOARD == NULL){
        printf("LEADERBOARD OPEN ERROR (GET)!\n");
        return NULL;
    }

    while ((symbol = fgetc(LEADERBOARD)) != EOF){
        if (symbol == '\n') nodeCount++;
    }
    rewind(LEADERBOARD);

    leaderBoardNodesArray = (LeaderBoardNode**)malloc(sizeof(LeaderBoardNode*) * nodeCount);
    if (leaderBoardNodesArray == NULL){
        printf("Mem alloc for leadderBoardArray ERROR!\n");
        fclose(LEADERBOARD);
        return NULL;
    }

    for (int i = 0; i < nodeCount; i++){
        leaderBoardNodesArray[i] = (LeaderBoardNode*)malloc(sizeof(LeaderBoardNode));
        if (leaderBoardNodesArray[i] == NULL){
            printf("Mem alloc for LeaderBoard Node ERROR!\n");
            return NULL;
        }


        char* nickname = malloc(sizeof(char) * MAX_NICKNAME_SIZE);
        if (nickname == NULL){
            printf("Mem alloc for nick buffer ERROR!\n");
        }
        memset(nickname, '\0', MAX_NICKNAME_SIZE);
        int nickSize = 0;
        for (int i = 0; (symbol = fgetc(LEADERBOARD)) != '|'; i++){
            if (i > MAX_NICKNAME_SIZE) break;
            nickname[i] = symbol;
            nickSize++;
        }

        int res = fscanf(LEADERBOARD, "%d|%d|%d\n", &leaderBoardNodesArray[i]->MapSize, &leaderBoardNodesArray[i]->BotLevel, &leaderBoardNodesArray[i]->Score);
        if (res != 3){{}
            for (int j = 0; j <= i; j++){
                free(leaderBoardNodesArray[j]->Nickname);
                free(leaderBoardNodesArray[j]);
                free(leaderBoardNodesArray);
                fclose(LEADERBOARD);

                leaderBoard = (LeaderBoard*)malloc(sizeof(leaderBoard));
                leaderBoard->count = 0;
                leaderBoard->nodes = NULL;

                LEADERBOARD = fopen(LeaderBoardName, "w");
                if (LEADERBOARD == NULL){
                    printf("LEADERBOARD OPEN ERROR (GET)!\n");
                    return NULL;
                }
                fclose(LEADERBOARD);

                return leaderBoard;
            }
        }
        
        leaderBoardNodesArray[i]->Nickname = nickname;
        leaderBoardNodesArray[i]->nickSize = nickSize;
    }

    leaderBoard = (LeaderBoard*)malloc(sizeof(leaderBoard));
    leaderBoard->count = nodeCount;
    leaderBoard->nodes = leaderBoardNodesArray;

    fclose(LEADERBOARD);
    return leaderBoard;
}

void updateLeaderBoard(char* LeaderBoardName, LeaderBoard* lb)
{
    FILE* LEADERBOARD = NULL;
    LEADERBOARD = fopen(LeaderBoardName, "w");
    if (LEADERBOARD == NULL){
        printf("LEADERBOARD OPEN ERROR (GET)!\n");
        return;
    }

    for (int i = 0; i < lb->count; i++){
        for (int j = 0; j < lb->nodes[i]->nickSize; j++) fputc(lb->nodes[i]->Nickname[j], LEADERBOARD);
        fprintf(LEADERBOARD, "|%d|%d|%d\n", lb->nodes[i]->MapSize, lb->nodes[i]->BotLevel, lb->nodes[i]->Score);
    }
    fclose(LEADERBOARD);
}

void sortLeaderBoard(LeaderBoard* leaderboard)
{
    LeaderBoardNode* min;
    int minInd;

    for (int i = 0; i < leaderboard->count; i++){
        min = leaderboard->nodes[i];
        minInd = i;
        for (int j = i; j < leaderboard->count; j++){
            if (leaderboard->nodes[j]->Score < min->Score){
                min = leaderboard->nodes[j];
                minInd = j;
            }
        }
        leaderboard->nodes[minInd] = leaderboard->nodes[i];
        leaderboard->nodes[i] = min;
    }
}

void freeLeaderBoard(LeaderBoard* leaderBoard)
{
    
    for (int i = 0; i < leaderBoard->count; i++){
        if (leaderBoard->nodes[i]->Nickname != NULL)free(leaderBoard->nodes[i]->Nickname);
        if (leaderBoard->nodes[i] != NULL)free(leaderBoard->nodes[i]);
    }

    if (leaderBoard->nodes != NULL) free(leaderBoard->nodes);
    if (leaderBoard != NULL) free(leaderBoard);

    leaderBoard = NULL;
}


int checkNickname(LeaderBoard* lb, char* nickname,int score, int mapSize, int botLevel)
{
    for (int i = 0; i < lb->count; i++){
        if (strcmp(lb->nodes[i]->Nickname, nickname) == 0 && lb->nodes[i]->MapSize == mapSize && lb->nodes[i]->BotLevel == botLevel){
            if (lb->nodes[i]->Score > score)
                lb->nodes[i]->Score = score;

            return SCORE_UPDATED;
        }
    }
    return SCORE_NOT_UPDATED;
}

#endif