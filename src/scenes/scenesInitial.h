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
    Text* TextParams;
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
    Sprite* ExitBtn;
    GLuint state;

} RaftPlacement15x15;

typedef struct RaftPlacement10x10BF
{
    Sprite* Background;
    Sprite* ButtonPlates;
    Sprite* Map10x10;
    Sprite* QuestionMarkBtn;
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
    GLuint state;

} MainGameBase15x15;

typedef struct MainGameBotFight10x10
{
    Sprite* Background;
    Sprite* ButtonPlates;
    Sprite* MainMap10x10;
    Sprite* QuestionMarkBtn;
    MapSprite Bot1MapArray[10][10];
    MapSprite Bot2MapArray[10][10];
    Text* TextParams;
    Sprite* ExitBtn;
    Sprite* FAQPlate;
    GLuint state;

} MainGameBotFight10x10;

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

//Other
void initPiratesSprites();

#endif