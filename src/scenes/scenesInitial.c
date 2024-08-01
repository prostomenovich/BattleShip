#include "scenesInitial.h"

#ifndef SCENESINITIAL_C
#define SCENESINITIAL_C


Player playerInfo;
//Scenes
MainMenu sMainMenu;
About sAbout;
NewLoadMenu sNewLoadMenu;

void initMainMenu()
{
    extern MainMenu sMainMenu;
    extern FT_Library ft;
    extern Player playerInfo;


    AnimatedSprite* mainMenuBackground = initAnimatedSprite();
    setStartAnimSpriteParams(mainMenuBackground, 1280, 720, 0, 0, 0);
    setAnimSpriteFrames(mainMenuBackground, 4, REPEAT_TRUE, GL_NEAREST, GL_CLAMP_TO_EDGE,
                        "../resources/textures/mainMenu/background/mainMenuBackgroundFrame1.png",
                        "../resources/textures/mainMenu/background/mainMenuBackgroundFrame2.png",
                        "../resources/textures/mainMenu/background/mainMenuBackgroundFrame3.png",
                        "../resources/textures/mainMenu/background/mainMenuBackgroundFrame4.png");


    Sprite* buttonPlates = initSprite();
    setStartSpriteParams(buttonPlates, 1280, 720, 0, 0, 0);
    setSpriteTexture(buttonPlates, "../resources/textures/mainMenu/buttonPlates.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Text* textParams = makeNewText(&ft, "../resources/fonts/Unformital.ttf", 48);

    playerInfo.state = MAIN_MENU_SCENES;

    sMainMenu.Background = mainMenuBackground;
    sMainMenu.ButtonPlates = buttonPlates;
    sMainMenu.TextParams = textParams;
}

void initAbout()
{
    extern MainMenu sMainMenu;
    extern About sAbout;

    AnimatedSprite* aboutBackground = initAnimatedSprite();
    setStartAnimSpriteParams(aboutBackground, 1280, 720, 0, 0, 0);
    setAnimSpriteFrames(aboutBackground, 3, REPEAT_TRUE, GL_NEAREST, GL_CLAMP_TO_EDGE,
                        "../resources/textures/about/background/aboutBackgroundFrame1.png",
                        "../resources/textures/about/background/aboutBackgroundFrame2.png",
                        "../resources/textures/about/background/aboutBackgroundFrame3.png");

    Sprite* MainPlace = initSprite();
    setStartSpriteParams(MainPlace, 1280, 720, 0, 0, 0);
    setSpriteTexture(MainPlace, "../resources/textures/about/buttons.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* ExitBTN = initSprite();
    setStartSpriteParams(ExitBTN, 72, 72, 937, 595, 0);
    setSpriteTexture(ExitBTN, "../resources/textures/about/exit_black.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(ExitBTN, "../resources/textures/about/exit_red.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);


    sAbout.TextParams = sMainMenu.TextParams;
    sAbout.Background = aboutBackground;
    sAbout.MainPlace = MainPlace;
    sAbout.ExitButton = ExitBTN;
}

void initNewLoadMenu()
{
    extern MainMenu sMainMenu;
    extern NewLoadMenu sNewLoadMenu;
    
    AnimatedSprite* newLoadMenuBackground = initAnimatedSprite();
    setStartAnimSpriteParams(newLoadMenuBackground, 1280, 720, 0, 0, 0);
    setAnimSpriteFrames(newLoadMenuBackground, 3, REPEAT_TRUE, GL_NEAREST, GL_CLAMP_TO_EDGE,
                        "../resources/textures/newLoadMenu/NewLoadBackgroundFrame1.png",
                        "../resources/textures/newLoadMenu/NewLoadBackgroundFrame2.png",
                        "../resources/textures/newLoadMenu/NewLoadBackgroundFrame3.png");

    Sprite* ButtonsPlate = initSprite();
    setStartSpriteParams(ButtonsPlate, 1280, 720, 0, 0, 0);
    setSpriteTexture(ButtonsPlate, "../resources/textures/newLoadMenu/NewLoadButtonPlates.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    sNewLoadMenu.TextParams = sMainMenu.TextParams;
    sNewLoadMenu.Background = newLoadMenuBackground;
    sNewLoadMenu.ButtonPlates = ButtonsPlate;
}

#endif