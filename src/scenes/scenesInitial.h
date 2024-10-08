#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "../render/sprite.h"
#include "../render/textures.h"
#include "../render/AnimSprite.h"
#include "../render/text.h"
#include "processingUtils.h"
#include "../game/ShipBase.h"
#include "../game/leaderBoard.h"
#include "defines.h"


#ifndef SCENESINITIAL_H
#define SCENESINITIAL_H


typedef struct Player
{
    GLuint scene;
    GLuint GameMode;
    GLuint MapSize;
    GLuint BotLevel;

} Player;

typedef struct MainMenu
{
    AnimatedSprite* Background;
    Sprite* ButtonPlates;
    Text* TextParams;
    GLuint state;

} MainMenu;

typedef struct About
{
    AnimatedSprite* Background;
    Sprite* MainPlace;
    Sprite* paginationPlates;
    Sprite* pagUp;
    Sprite* pagDown;
    Text* TextParams1;
    Text* TextParams2;
    Sprite* ExitButton;
    GLuint state;

} About;

typedef struct NewLoadMenu
{
    AnimatedSprite* Background;
    Sprite* ButtonPlates;
    Text* TextParams;
    GLuint state;

} NewLoadMenu;

typedef struct GameSettingsMenu
{
    AnimatedSprite* Background;
    Sprite* ButtonPlatesChooseGM;
    Sprite* ButtonPlatesChooseBFS;
    Sprite* ButtonPlatesChooseBL;
    Sprite* PirateWMGM;
    Sprite* PirateWMBFS;
    Sprite* PirateWMBL;
    Text* TextParams;
    GLuint state;

} GameSettingsMenu;

typedef struct RaftPlacement10x10
{
    Sprite* Background;
    Sprite* ButtonPlates;
    Sprite* Map10x10;
    Sprite* QuestionMarkBtn;
    Sprite* FAQPlate;
    MapSprite MapArray[10][10];
    Text* TextParams;
    Sprite* ExitBtn;
    GLuint state;

} RaftPlacement10x10;

typedef struct RaftPlacement15x15
{
    Sprite* Background;
    Sprite* ButtonPlates;
    Sprite* Map15x15;
    Sprite* QuestionMarkBtn;
    MapSprite MapArray[15][15];
    Text* TextParams;
    Sprite* FAQPlate;
    Sprite* ExitBtn;
    GLuint state;

} RaftPlacement15x15;

typedef struct RaftPlacement10x10BF
{
    Sprite* Background;
    Sprite* ButtonPlates;
    Sprite* Map10x10;
    Sprite* QuestionMarkBtn;
    Sprite* FAQPlate;
    MapSprite MapArrayBot1[10][10];
    MapSprite MapArrayBot2[10][10];
    Text* TextParams;
    Sprite* ExitBtn;
    GLuint state;

} RaftPlacement10x10BF;

typedef struct RaftPlacement15x15BF
{
    Sprite* Background;
    Sprite* ButtonPlates;
    Sprite* Map15x15;
    Sprite* QuestionMarkBtn;
    Sprite* FAQPlate;
    MapSprite MapArrayBot1[15][15];
    MapSprite MapArrayBot2[15][15];
    Text* TextParams;
    Sprite* ExitBtn;
    GLuint state;

} RaftPlacement15x15BF;

typedef struct MainGameBase10x10
{
    Sprite* Background;
    Sprite* ButtonPlates;
    Sprite* MainMap10x10;
    Sprite* QuestionMarkBtn;
    MapSprite PlayerMapArray[10][10];
    MapSprite BotMapArray[10][10];
    Text* TextParams;
    Sprite* ExitBtn;
    Sprite* FAQPlate;
    Sprite* lostPlate;
    Sprite* wonPlate;
    Sprite* exitQuestion;
    GLuint state;

} MainGameBase10x10;

typedef struct MainGameBase15x15
{
    Sprite* Background;
    Sprite* ButtonPlates;
    Sprite* MainMap15x15;
    Sprite* QuestionMarkBtn;
    MapSprite PlayerMapArray[15][15];
    MapSprite BotMapArray[15][15];
    Text* TextParams;
    Sprite* ExitBtn;
    Sprite* FAQPlate;
    Sprite* lostPlate;
    Sprite* wonPlate;
    Sprite* exitQuestion;
    GLuint state;

} MainGameBase15x15;

typedef struct MainGameBotFight10x10
{
    Sprite* Background;
    Sprite* ButtonPlates;
    Sprite* MainMap10x10;
    Sprite* QuestionMarkBtn;
    Sprite* botWinPlate;
    MapSprite Bot1MapArray[10][10];
    MapSprite Bot2MapArray[10][10];
    Text* TextParams;
    Sprite* ExitBtn;
    Sprite* FAQPlate;
    Sprite* exitQuestion;
    GLuint state;

} MainGameBotFight10x10;

typedef struct MainGameBotFight15x15
{
    Sprite* Background;
    Sprite* ButtonPlates;
    Sprite* MainMap15x15;
    Sprite* QuestionMarkBtn;
    Sprite* botWinPlate;
    MapSprite Bot1MapArray[15][15];
    MapSprite Bot2MapArray[15][15];
    Text* TextParams;
    Sprite* ExitBtn;
    Sprite* FAQPlate;
    Sprite* exitQuestion;
    GLuint state;

} MainGameBotFight15x15;

typedef struct AddingNickName
{
    AnimatedSprite* Background;
    Sprite* buttonPlates;
    Text* TextParams1;
    Text* TextParams2;
    Sprite* ExitBtn;
    Sprite* QuestionMarkBtn;
    Sprite* FAQPlate;
    GLuint state;

} AddingNickName;

typedef struct Leaders
{
    AnimatedSprite* Background;
    Sprite* buttonPlates;
    Text* TextParams1;
    Text* TextParams2;
    Sprite* ExitBtn;
    Sprite* QuestionMarkBtn;
    Sprite* FAQPlate;
    Sprite* pagUp;
    Sprite* pagDown;
    GLuint state;

} Leaders;

typedef struct GetSaveName
{
    AnimatedSprite* Background;
    Sprite* buttonPlates;
    Text* TextParams1;
    Text* TextParams2;
    Sprite* ExitBtn;
    Sprite* QuestionMarkBtn;
    Sprite* FAQPlate;
    GLuint state;

} GetSaveName;

typedef struct LoadingMenu
{
    AnimatedSprite* Background;
    Sprite* buttonPlates;
    Text* TextParams1;
    Text* TextParams2;
    Sprite* ExitBtn;
    Sprite* QuestionMarkBtn;
    Sprite* FAQPlate;
    Sprite* pagUp;
    Sprite* pagDown;
    GLuint state;

} LoadingMenu;

typedef struct PiratesSprites 
{
    GLuint blueBasePBL;
    GLuint blueBasePBR;
    GLuint blueBasePPL;
    GLuint blueBasePPR;
    GLuint blueMainPL;
    GLuint blueMainPR;

    GLuint greenBasePBL;
    GLuint greenBasePBR;
    GLuint greenBasePPL;
    GLuint greenBasePPR;
    GLuint greenMainPL;
    GLuint greenMainPR;

    GLuint redBasePBL;
    GLuint redBasePBR;
    GLuint redBasePPL;
    GLuint redBasePPR;
    GLuint redMainPL;
    GLuint redMainPR;

    GLuint yellowBasePBL;
    GLuint yellowBasePBR;
    GLuint yellowMainPL;
    GLuint yellowMainPR;

    GLuint noCapBasePL1;
    GLuint noCapBasePR1;
    GLuint noCapBasePL2;
    GLuint noCapBasePR2;

    GLuint dead;
    GLuint waterSplash;
    GLuint redCross;

} PiratesSprites;

typedef struct SaveNamesList
{
    char** names;
    GLuint count;
    
} SaveNamesList;

//scenes Initial
void initMainMenu();

void initAbout();

void initNewLoadMenu();

void initGameSettingsMenu();

void initRaftPlacement10x10();

void initRaftPlacement15x15();

void initRaftPlacement10x10BF();

void initRaftPlacement15x15BF();

void initMainGameBase10x10();

void initMainGameBase15x15();

void initMainGameBotFight10x10();

void initMainGameBotFight15x15();

void initAddingNickName();

void initLeaders();

void initGetSaveName();

void initLoadingMenu();

//Other
void initPiratesSprites();

#endif