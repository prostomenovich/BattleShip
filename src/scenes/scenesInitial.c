#include "scenesInitial.h"

#ifndef SCENESINITIAL_C
#define SCENESINITIAL_C


Player playerInfo;

//map
int map[18][18] = {0, };

//Scenes
MainMenu sMainMenu;
About sAbout;
NewLoadMenu sNewLoadMenu;
GameSettingsMenu sGameSettingsMenu;
RaftPlacement10x10 sRaftPlacement10X10;
RaftPlacement15x15 sRaftPlacement15X15;

//ShipBase
ShipBase* shipBase;
Coordinates* coords[5] = {NULL, };

//Other veriables
double lastClickTime = 0;

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

    playerInfo.scene = MAIN_MENU_SCENES;
    playerInfo.GameMode = NOT_FILLED_IN;
    playerInfo.MapSize = NOT_FILLED_IN;

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

void initGameSettingsMenu()
{
    extern MainMenu sMainMenu;
    extern GameSettingsMenu sGameSettingsMenu;

    AnimatedSprite* GameSettingsMenuBackground = initAnimatedSprite();
    setStartAnimSpriteParams(GameSettingsMenuBackground, 1280, 720, 0, 0, 0);
    setAnimSpriteFrames(GameSettingsMenuBackground, 3, REPEAT_TRUE, GL_NEAREST, GL_CLAMP_TO_EDGE,
                        "../resources/textures/gameSettingsMenu/background/gameSettingsMenuBackFrame1.png",
                        "../resources/textures/gameSettingsMenu/background/gameSettingsMenuBackFrame2.png",
                        "../resources/textures/gameSettingsMenu/background/gameSettingsMenuBackFrame3.png");

    Sprite* buttonsPlatesChooseGM = initSprite();
    setStartSpriteParams(buttonsPlatesChooseGM, 1280, 720, 0, 0, 0);
    setSpriteTexture(buttonsPlatesChooseGM, "../resources/textures/gameSettingsMenu/selectGameMode/SelectGMButtonPlates.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* buttonsPlatesChooseBFS = initSprite();
    setStartSpriteParams(buttonsPlatesChooseBFS, 1280, 720, 0, 0, 0);
    setSpriteTexture(buttonsPlatesChooseBFS, "../resources/textures/gameSettingsMenu/selectMapSize/SelectMSButtonPlates.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* buttonsPlatesChooseBL = initSprite();
    setStartSpriteParams(buttonsPlatesChooseBL, 1280, 720, 0, 0, 0);
    setSpriteTexture(buttonsPlatesChooseBL, "../resources/textures/gameSettingsMenu/selectBotLevel/SelectBLButtonPlates.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* pirateWMGM = initSprite();
    setStartSpriteParams(pirateWMGM, 1280, 720, 0, 0, 0);
    setSpriteTexture(pirateWMGM, "../resources/textures/gameSettingsMenu/selectGameMode/pirateMessage.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* pirateWMBFS = initSprite();
    setStartSpriteParams(pirateWMBFS, 1280, 720, 0, 0, 0);
    setSpriteTexture(pirateWMBFS, "../resources/textures/gameSettingsMenu/selectMapSize/pirateMessage.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* pirateWMBL = initSprite();
    setStartSpriteParams(pirateWMBL, 1280, 720, 0, 0, 0);
    setSpriteTexture(pirateWMBL, "../resources/textures/gameSettingsMenu/selectBotLevel/pirateWMBL.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);


    sGameSettingsMenu.TextParams = sMainMenu.TextParams;
    sGameSettingsMenu.Background = GameSettingsMenuBackground;
    sGameSettingsMenu.ButtonPlatesChooseBFS = buttonsPlatesChooseBFS;
    sGameSettingsMenu.ButtonPlatesChooseGM = buttonsPlatesChooseGM;
    sGameSettingsMenu.ButtonPlatesChooseBL = buttonsPlatesChooseBL;
    sGameSettingsMenu.PirateWMGM = pirateWMGM;
    sGameSettingsMenu.PirateWMBFS = pirateWMBFS;
    sGameSettingsMenu.PirateWMBL = pirateWMBL;
}

void initRaftPlacement10x10()
{
    extern MainMenu sMainMenu;
    extern RaftPlacement10x10 sRaftPlacement10X10;
    extern ShipBase* shipBase;
    extern Coordinates* coords[5];

    extern int map[18][18];
   

    Sprite* background = initSprite();
    setStartSpriteParams(background, 1280, 720, 0, 0, 0);
    setSpriteTexture(background, "../resources/textures/raftPuttingMenu/10x10/background.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* buttonsPlate = initSprite();
    setStartSpriteParams(buttonsPlate, 1280, 720, 0, 0, 0);
    setSpriteTexture(buttonsPlate, "../resources/textures/raftPuttingMenu/10x10/buttonsPlate.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* map10x10 = initSprite();
    setStartSpriteParams(map10x10, 1280, 720, 0, 0, 0);
    setSpriteTexture(map10x10, "../resources/textures/raftPuttingMenu/10x10/Map.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* exitBtn = initSprite();
    setStartSpriteParams(exitBtn,  60, 60, 1202, 650, 0);
    setSpriteTexture(exitBtn, "../resources/textures/raftPuttingMenu/10x10/exit_black1.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(exitBtn, "../resources/textures/raftPuttingMenu/10x10/exit_red1.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* questionMarkBtn = initSprite();
    setStartSpriteParams(questionMarkBtn, 60, 60, 1200 , 578, 0);
    setSpriteTexture(questionMarkBtn, "../resources/textures/raftPuttingMenu/10x10/qMark_black.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(questionMarkBtn, "../resources/textures/raftPuttingMenu/10x10/qMark_white.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);
    

    double xPos = 558.0,
        yPos = 582.0;

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            Sprite* mapPlate = initSprite();
            setStartSpriteParams(mapPlate, 57, 57, xPos, yPos, 0);
            if (i == 0 && j == 0){
                setSpriteTexture(mapPlate, "../resources/textures/raftPuttingMenu/10x10/red.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
                setSpriteTexture(mapPlate, "../resources/textures/raftPuttingMenu/10x10/green.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);
                setSpriteTexture(mapPlate, "../resources/textures/raftPuttingMenu/10x10/yellow.png", GL_NEAREST, GL_CLAMP_TO_EDGE, THIRD_TEXTURE);
            }
            else {
                mapPlate->Texture1 = sRaftPlacement10X10.MapArray[0][0].sprite->Texture1;
                mapPlate->Texture2 = sRaftPlacement10X10.MapArray[0][0].sprite->Texture2;
                mapPlate->Texture3 = sRaftPlacement10X10.MapArray[0][0].sprite->Texture3;
            }
            xPos += 60;

            sRaftPlacement10X10.MapArray[i][j].sprite = mapPlate;
            sRaftPlacement10X10.MapArray[i][j].spriteState = PLATE_NOT_PRESSED;
        }
        xPos = 558.0;
        yPos -= 60.8;
    }

    //if (shipBase == NULL) shipBase = initShipBase(MAP_SIZE_10_X_10);
    
    if (coords[0] == NULL){

        for (int i = 0; i < 5; i++){
            coords[i] = (Coordinates*)malloc(sizeof(Coordinates));
        }

    }

    sRaftPlacement10X10.TextParams = sMainMenu.TextParams;
    sRaftPlacement10X10.Background = background;
    sRaftPlacement10X10.ButtonPlates = buttonsPlate;
    sRaftPlacement10X10.Map10x10 = map10x10;
    sRaftPlacement10X10.QuestionMarkBtn = questionMarkBtn;
    sRaftPlacement10X10.state = NOT_IN_EDIT_MODE;
    sRaftPlacement10X10.ExitBtn = exitBtn;
}

void initRaftPlacement15x15()
{
    extern MainMenu sMainMenu;
    extern RaftPlacement15x15 sRaftPlacement15X15;
    extern ShipBase* shipBase;
    extern Coordinates* coords[5];

    extern int map[18][18];
    

    Sprite* background = initSprite();
    setStartSpriteParams(background, 1280, 720, 0, 0, 0);
    setSpriteTexture(background, "../resources/textures/raftPuttingMenu/15x15/background.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* buttonsPlate = initSprite();
    setStartSpriteParams(buttonsPlate, 1280, 720, 0, 0, 0);
    setSpriteTexture(buttonsPlate, "../resources/textures/raftPuttingMenu/15x15/buttonsPlate.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* map15x15 = initSprite();
    setStartSpriteParams(map15x15, 1280, 720, 0, 0, 0);
    setSpriteTexture(map15x15, "../resources/textures/raftPuttingMenu/15x15/Map.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* exitBtn = initSprite();
    setStartSpriteParams(exitBtn,  60, 60, 1207, 651, 0);
    setSpriteTexture(exitBtn, "../resources/textures/raftPuttingMenu/10x10/exit_black1.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(exitBtn, "../resources/textures/raftPuttingMenu/10x10/exit_red1.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* questionMarkBtn = initSprite();
    setStartSpriteParams(questionMarkBtn, 60, 60, 1206 , 580, 0);
    setSpriteTexture(questionMarkBtn, "../resources/textures/raftPuttingMenu/10x10/qMark_black.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(questionMarkBtn, "../resources/textures/raftPuttingMenu/10x10/qMark_white.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);
    

    double xPos = 549.8,
        yPos = 621.0;

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            Sprite* mapPlate = initSprite();
            setStartSpriteParams(mapPlate, 41, 41, xPos, yPos, 0);
            if (i == 0 && j == 0){
                setSpriteTexture(mapPlate, "../resources/textures/raftPuttingMenu/10x10/red.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
                setSpriteTexture(mapPlate, "../resources/textures/raftPuttingMenu/10x10/green.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);
                setSpriteTexture(mapPlate, "../resources/textures/raftPuttingMenu/10x10/yellow.png", GL_NEAREST, GL_CLAMP_TO_EDGE, THIRD_TEXTURE);
            }
            else {
                mapPlate->Texture1 = sRaftPlacement15X15.MapArray[0][0].sprite->Texture1;
                mapPlate->Texture2 = sRaftPlacement15X15.MapArray[0][0].sprite->Texture2;
                mapPlate->Texture3 = sRaftPlacement15X15.MapArray[0][0].sprite->Texture3;
            }
            xPos += 41.72;

            sRaftPlacement15X15.MapArray[i][j].sprite = mapPlate;
            sRaftPlacement15X15.MapArray[i][j].spriteState = PLATE_NOT_PRESSED;
        }
        xPos = 550.0;
        yPos -= 42.0;
    }

    //if (shipBase == NULL) shipBase = initShipBase(MAP_SIZE_15_X_15);
    
    if (coords[0] == NULL){
        
        for (int i = 0; i < 5; i++){
            coords[i] = (Coordinates*)malloc(sizeof(Coordinates));
        }

    }

    sRaftPlacement15X15.TextParams = sMainMenu.TextParams;
    sRaftPlacement15X15.Background = background;
    sRaftPlacement15X15.ButtonPlates = buttonsPlate;
    sRaftPlacement15X15.Map15x15 = map15x15;
    sRaftPlacement15X15.QuestionMarkBtn = questionMarkBtn;
    sRaftPlacement15X15.state = NOT_IN_EDIT_MODE;
    sRaftPlacement15X15.ExitBtn = exitBtn;
}

#endif