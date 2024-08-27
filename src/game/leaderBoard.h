#include <stdio.h>
#include <stdlib.h>
#include "../scenes/defines.h"
#include "../scenes/processingUtils.h"

#ifndef LEADERBOARD_H
#define LEADERBOARD_H

typedef struct LeaderBoardNode 
{
    char* Nickname;
    GLuint nickSize;
    GLuint MapSize;
    GLuint BotLevel;
    GLuint Score;

} LeaderBoardNode;

typedef struct LeaderBoard 
{
    LeaderBoardNode** nodes;
    GLuint count;

} LeaderBoard;

#define SCORE_UPDATED 1
#define SCORE_NOT_UPDATED 2

void pushDataInLeaderBoard(char* nickname,int score, int MapSize, int BotLevel, char* LeaderBoardName);

LeaderBoard* getDataFromLeaderBoard(char* LeaderBoardName);

void updateLeaderBoard(char* LeaderBoardName, LeaderBoard* lb);

void sortLeaderBoard(LeaderBoard* leaderboard);

void freeLeaderBoard(LeaderBoard* leaderBoard);

int checkNickname(LeaderBoard* lb, char* nickname,int score, int mapSize, int botLevel);



#endif