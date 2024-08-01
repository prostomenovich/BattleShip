#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "../render/sprite.h"
#include "../render/AnimSprite.h"
#include "../render/text.h"


#ifndef SCENESINITIAL_H
#define SCENESINITIAL_H

#define MAIN_MENU_SCENES 1
#define ABOUT_LORE_SCENES 2
#define ABOUT_RULES_SCENES 3
#define ABOUT_AUTHORS_SCENES 4
#define NEW_LOAD_MENU_SCENES 5

typedef struct Player
{
    GLuint state;

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

void initMainMenu();

void initAbout();

void initNewLoadMenu();


#endif