#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "../render/sprite.h"
#include "../render/AnimSprite.h"
#include "../render/text.h"
#include "processingUtils.h"
#include "../game/ShipBase.h"


#ifndef SCENESINITIAL_H
#define SCENESINITIAL_H

//Scenes defines
#define MAIN_MENU_SCENES 1
#define ABOUT_LORE_SCENES 2
#define ABOUT_RULES_SCENES 3
#define ABOUT_AUTHORS_SCENES 4
#define NEW_LOAD_MENU_SCENES 5
#define GAME_SETTING_MENU 6
#define RAFT_PLACEMENT_10_X_10_BASE 7
#define RAFT_PLACEMENT_15_X_15_BASE 8
#define RAFT_PLACEMENT_10_X_10_BOTS_FIGHT_BOT_1 9
#define RAFT_PLACEMENT_10_X_10_BOTS_FIGHT_BOT_2 10
#define RAFT_PLACEMENT_15_X_15_BOTS_FIGHT 11
#define RAFT_PLACEMENT_15_X_15_BOTS_FIGHT_BOT_1 12
#define RAFT_PLACEMENT_15_X_15_BOTS_FIGHT_BOT_2 13

//Before filling
#define NOT_FILLED_IN 0

//Game mode defines
#define BOTS_FIGHT_MODE 11
#define BASIC_MODE 12

//Bot level
#define EASY_BOT_LEVEL 41
#define NORMAL_BOT_LEVEL 42
#define HARD_BOT_LEVEL 43

//states
#define IN_EDIT_MODE 51
#define NOT_IN_EDIT_MODE 52
#define PLATE_SUCCES 53
#define PLATE_ERROR 54

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


void initMainMenu();

void initAbout();

void initNewLoadMenu();

void initGameSettingsMenu();

void initRaftPlacement10x10();

void initRaftPlacement15x15();

void initRaftPlacement10x10BF();

void initRaftPlacement15x15BF();


#endif