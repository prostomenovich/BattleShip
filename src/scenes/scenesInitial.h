#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "../render/sprite.h"
#include "../render/AnimSprite.h"
#include "../render/text.h"


#ifndef SCENESINITIAL_H
#define SCENESINITIAL_H

//Scenes defines
#define MAIN_MENU_SCENES 1
#define ABOUT_LORE_SCENES 2
#define ABOUT_RULES_SCENES 3
#define ABOUT_AUTHORS_SCENES 4
#define NEW_LOAD_MENU_SCENES 5
#define GAME_SETTING_MENU 6

//Before filling
#define NOT_FILLED_IN 0

//Game mode defines
#define BOTS_FIGHT_MODE 11
#define BASIC_MODE 12

//Map size
#define MAP_SIZE_10_X_10 31
#define MAP_SIZE_15_X_15 32

typedef struct Player
{
    GLuint scene;
    GLuint GameMode;
    GLuint MapSize;

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
    Sprite* PirateWMGM;
    Sprite* PirateWMBFS;
    Text* TextParams;
    GLuint state;

} GameSettingsMenu;

void initMainMenu();

void initAbout();

void initNewLoadMenu();

void initGameSettingsMenu();


#endif