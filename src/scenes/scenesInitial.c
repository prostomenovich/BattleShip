#include "scenesInitial.h"

#ifndef SCENESINITIAL_C
#define SCENESINITIAL_C


Player playerInfo;

//map
int map[18][18] = {0, };
int mapBot[18][18] = {0, };
int mapBot1[18][18] = {0, };
int mapBot2[18][18] = {0, };

//Scenes
MainMenu sMainMenu;
About sAbout;
NewLoadMenu sNewLoadMenu;
GameSettingsMenu sGameSettingsMenu;
RaftPlacement10x10 sRaftPlacement10X10;
RaftPlacement15x15 sRaftPlacement15X15;
RaftPlacement10x10BF sRaftPlacement10X10BF;
RaftPlacement15x15BF sRaftPlacement15X15BF;
MainGameBase10x10 sMainGameBase10x10;
MainGameBase15x15 sMainGameBase15x15;


//ShipBase
ShipBase* shipBase = NULL;
ShipBase* botShipBase = NULL;
ShipBase* shipBaseBFBot1 = NULL;
ShipBase* shipBaseBFBot2 = NULL;
Coordinates* coords[5] = {NULL, };

//Other veriables
PiratesSprites PiratesSpritesBase;
double lastClickTime = 0;

//FAQ Text
char FAQMainGame10x10Basic [7][MAX_STRING_SIZE] = 
{
    "In the basic mode you have to fight against a bot.",
    "The number of your living rafts is displayed above",
    "your field and the number of his living rafts",
    "is displayed above the opponents field. The winner",
    "is the one who first eliminates all the enemys",
    "rafts. To fire a shot left click on the desired",
    "cell on the enemys field."
};

const int FAQMainGame10x10BasicStringCount = 7;

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

void initRaftPlacement10x10BF()
{
    extern MainMenu sMainMenu;
    extern RaftPlacement10x10 sRaftPlacement10X10;
    extern RaftPlacement10x10BF sRaftPlacement10X10BF;
    extern ShipBase* shipBaseBFBot1;
    extern ShipBase* shipBaseBFBot2;
    extern Coordinates* coords[5];

    Sprite* buttonsPlate = initSprite();
    setStartSpriteParams(buttonsPlate, 1280, 720, 0, 0, 0);
    setSpriteTexture(buttonsPlate, "../resources/textures/raftPuttingMenu/10x10/buttonsPlateForBF.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

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
                mapPlate->Texture1 = sRaftPlacement10X10BF.MapArrayBot1[0][0].sprite->Texture1;
                mapPlate->Texture2 = sRaftPlacement10X10BF.MapArrayBot1[0][0].sprite->Texture2;
                mapPlate->Texture3 = sRaftPlacement10X10BF.MapArrayBot1[0][0].sprite->Texture3;
            }
            xPos += 60;

            sRaftPlacement10X10BF.MapArrayBot1[i][j].sprite = mapPlate;
            sRaftPlacement10X10BF.MapArrayBot1[i][j].spriteState = PLATE_NOT_PRESSED;
        }
        xPos = 558.0;
        yPos -= 60.8;
    }

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
                mapPlate->Texture1 = sRaftPlacement10X10BF.MapArrayBot2[0][0].sprite->Texture1;
                mapPlate->Texture2 = sRaftPlacement10X10BF.MapArrayBot2[0][0].sprite->Texture2;
                mapPlate->Texture3 = sRaftPlacement10X10BF.MapArrayBot2[0][0].sprite->Texture3;
            }
            xPos += 60;

            sRaftPlacement10X10BF.MapArrayBot2[i][j].sprite = mapPlate;
            sRaftPlacement10X10BF.MapArrayBot2[i][j].spriteState = PLATE_NOT_PRESSED;
        }
        xPos = 558.0;
        yPos -= 60.8;
    }
    
    if (coords[0] == NULL){

        for (int i = 0; i < 5; i++){
            coords[i] = (Coordinates*)malloc(sizeof(Coordinates));
        }

    }

    sRaftPlacement10X10BF.TextParams = sMainMenu.TextParams;
    sRaftPlacement10X10BF.Background = sRaftPlacement10X10.Background;
    sRaftPlacement10X10BF.ButtonPlates = buttonsPlate;
    sRaftPlacement10X10BF.Map10x10 = sRaftPlacement10X10.Map10x10;
    sRaftPlacement10X10BF.QuestionMarkBtn = sRaftPlacement10X10.QuestionMarkBtn;
    sRaftPlacement10X10BF.state = NOT_IN_EDIT_MODE;
    sRaftPlacement10X10BF.ExitBtn = sRaftPlacement10X10.ExitBtn;
}

void initRaftPlacement15x15BF()
{
    extern MainMenu sMainMenu;
    extern RaftPlacement15x15 sRaftPlacement15X15;
    extern RaftPlacement15x15BF sRaftPlacement15X15BF;
    extern ShipBase* shipBaseBFBot1;
    extern ShipBase* shipBaseBFBot2;
    extern Coordinates* coords[5];

    Sprite* buttonsPlate = initSprite();
    setStartSpriteParams(buttonsPlate, 1280, 720, 0, 0, 0);
    setSpriteTexture(buttonsPlate, "../resources/textures/raftPuttingMenu/15x15/buttonsPlateForBF.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

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
                mapPlate->Texture1 = sRaftPlacement15X15BF.MapArrayBot1[0][0].sprite->Texture1;
                mapPlate->Texture2 = sRaftPlacement15X15BF.MapArrayBot1[0][0].sprite->Texture2;
                mapPlate->Texture3 = sRaftPlacement15X15BF.MapArrayBot1[0][0].sprite->Texture3;
            }
            xPos += 41.72;

            sRaftPlacement15X15BF.MapArrayBot1[i][j].sprite = mapPlate;
            sRaftPlacement15X15BF.MapArrayBot1[i][j].spriteState = PLATE_NOT_PRESSED;
        }
        xPos = 550.0;
        yPos -= 42.0;
    }
    
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
                mapPlate->Texture1 = sRaftPlacement15X15BF.MapArrayBot2[0][0].sprite->Texture1;
                mapPlate->Texture2 = sRaftPlacement15X15BF.MapArrayBot2[0][0].sprite->Texture2;
                mapPlate->Texture3 = sRaftPlacement15X15BF.MapArrayBot2[0][0].sprite->Texture3;
            }
            xPos += 41.72;

            sRaftPlacement15X15BF.MapArrayBot2[i][j].sprite = mapPlate;
            sRaftPlacement15X15BF.MapArrayBot2[i][j].spriteState = PLATE_NOT_PRESSED;
        }
        xPos = 550.0;
        yPos -= 42.0;
    }

    if (coords[0] == NULL){

        for (int i = 0; i < 5; i++){
            coords[i] = (Coordinates*)malloc(sizeof(Coordinates));
        }

    }

    sRaftPlacement15X15BF.TextParams = sMainMenu.TextParams;
    sRaftPlacement15X15BF.Background = sRaftPlacement15X15.Background;
    sRaftPlacement15X15BF.ButtonPlates = buttonsPlate;
    sRaftPlacement15X15BF.Map15x15 = sRaftPlacement15X15.Map15x15;
    sRaftPlacement15X15BF.QuestionMarkBtn = sRaftPlacement15X15.QuestionMarkBtn;
    sRaftPlacement15X15BF.state = NOT_IN_EDIT_MODE;
    sRaftPlacement15X15BF.ExitBtn = sRaftPlacement15X15.ExitBtn;
}

void initMainGameBase10x10()
{
    extern MainMenu sMainMenu;
    extern MainGameBase10x10 sMainGameBase10x10;
    extern ShipBase* shipBase;
    extern ShipBase* botShipBase;

    Sprite* background = initSprite();
    setStartSpriteParams(background, 1280, 720, 0, 0, 0);
    setSpriteTexture(background, "../resources/textures/raftPuttingMenu/10x10/background.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* buttonsPlates = initSprite();
    setStartSpriteParams(buttonsPlates, 1280, 720, 0, 0, 0);
    setSpriteTexture(buttonsPlates, "../resources/textures/mainGame/Base10x10/mainBtnPlates10x10.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* map = initSprite();
    setStartSpriteParams(map, 1280, 720, 0, 0, 0);
    setSpriteTexture(map, "../resources/textures/mainGame/Base10x10/MainMap10x10.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    
    Sprite* exitBtn = initSprite();
    setStartSpriteParams(exitBtn,  60, 60, 1207, 651, 0);
    setSpriteTexture(exitBtn, "../resources/textures/raftPuttingMenu/10x10/exit_black1.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(exitBtn, "../resources/textures/raftPuttingMenu/10x10/exit_red1.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* questionMarkBtn = initSprite();
    setStartSpriteParams(questionMarkBtn, 60, 60, 1109 , 644, 0);
    setSpriteTexture(questionMarkBtn, "../resources/textures/raftPuttingMenu/10x10/qMark_black.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(questionMarkBtn, "../resources/textures/raftPuttingMenu/10x10/qMark_white.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* FAQPlate = initSprite();
    setStartSpriteParams(FAQPlate, 1280, 720, 0 , 0, 0);
    setSpriteTexture(FAQPlate, "../resources/textures/mainGame/FAQPlateBasicGame10x10.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    
    double xPos = 70.0,
           yPos = 510.0;

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            Sprite* mapPlate = initSprite();
            setStartSpriteParams(mapPlate, 50, 50, xPos, yPos, 0);
            xPos += 52;

            sMainGameBase10x10.PlayerMapArray[i][j].sprite = mapPlate;
            sMainGameBase10x10.PlayerMapArray[i][j].spriteState = THIS_IS_NOT_SHIP_PLATE;
            sMainGameBase10x10.PlayerMapArray[i][j].sprite->Texture3 = PiratesSpritesBase.waterSplash;

        }
        xPos = 70.0;
        yPos -= 52.0;
    }
    
    xPos = 722.0;
    yPos = 510.0;

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            Sprite* mapPlate = initSprite();
            setStartSpriteParams(mapPlate, 50, 50, xPos, yPos, 0);
            setSpriteTexture(mapPlate, "../resources/textures/raftPuttingMenu/10x10/red.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
            setSpriteTexture(mapPlate, "../resources/textures/raftPuttingMenu/10x10/yellow.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);
            xPos += 52;
            
            sMainGameBase10x10.BotMapArray[i][j].sprite = mapPlate;
            sMainGameBase10x10.BotMapArray[i][j].spriteState = THIS_IS_NOT_SHIP_PLATE;
            sMainGameBase10x10.BotMapArray[i][j].sprite->Texture1 = PiratesSpritesBase.redCross;
            sMainGameBase10x10.BotMapArray[i][j].sprite->Texture2 = PiratesSpritesBase.waterSplash;

        }
        xPos = 722.0;
        yPos -= 52.0;
    }

    //if (botShipBase == NULL) botShipBase = initShipBase(MAP_SIZE_10_X_10);

    sMainGameBase10x10.TextParams = sMainMenu.TextParams;
    sMainGameBase10x10.Background = background;
    sMainGameBase10x10.ButtonPlates = buttonsPlates;
    sMainGameBase10x10.MainMap10x10 = map;
    sMainGameBase10x10.ExitBtn = exitBtn;
    sMainGameBase10x10.QuestionMarkBtn = questionMarkBtn;
    sMainGameBase10x10.FAQPlate = FAQPlate;
}

void initPiratesSprites()
{
    extern PiratesSprites PiratesSpritesBase;

    PiratesSpritesBase.blueBasePBL = MakeNewTexture("../resources/textures/pirates/blue_base_pirate_badana_turn_left.png", GL_NEAREST, GL_CLAMP_TO_EDGE);
    PiratesSpritesBase.blueBasePBR = MakeNewTexture("../resources/textures/pirates/blue_base_pirate_badana_turn_right.png", GL_NEAREST, GL_CLAMP_TO_EDGE);
    PiratesSpritesBase.blueBasePPL = MakeNewTexture("../resources/textures/pirates/blue_base_pirate_turn_left.png", GL_NEAREST, GL_CLAMP_TO_EDGE);
    PiratesSpritesBase.blueBasePPR = MakeNewTexture("../resources/textures/pirates/blue_base_pirate_turn_right.png", GL_NEAREST, GL_CLAMP_TO_EDGE);
    PiratesSpritesBase.blueMainPL = MakeNewTexture("../resources/textures/pirates/blue_main_pirate_turn_left.png", GL_NEAREST, GL_CLAMP_TO_EDGE);
    PiratesSpritesBase.blueMainPR = MakeNewTexture("../resources/textures/pirates/blue_main_pirate_turn_right.png", GL_NEAREST, GL_CLAMP_TO_EDGE);

    PiratesSpritesBase.greenBasePBL = MakeNewTexture("../resources/textures/pirates/green_base_pirate_badana_turn_left.png", GL_NEAREST, GL_CLAMP_TO_EDGE);
    PiratesSpritesBase.greenBasePBR = MakeNewTexture("../resources/textures/pirates/green_base_pirate_badana_turn_right.png", GL_NEAREST, GL_CLAMP_TO_EDGE);
    PiratesSpritesBase.greenBasePPL = MakeNewTexture("../resources/textures/pirates/green_base_pirate_turn_left.png", GL_NEAREST, GL_CLAMP_TO_EDGE);
    PiratesSpritesBase.greenBasePPR = MakeNewTexture("../resources/textures/pirates/green_base_pirate_turn_right.png", GL_NEAREST, GL_CLAMP_TO_EDGE);
    PiratesSpritesBase.greenMainPL = MakeNewTexture("../resources/textures/pirates/green_main_pirate_turn_left.png", GL_NEAREST, GL_CLAMP_TO_EDGE);
    PiratesSpritesBase.greenMainPR = MakeNewTexture("../resources/textures/pirates/green_main_pirate_turn_right.png", GL_NEAREST, GL_CLAMP_TO_EDGE);

    PiratesSpritesBase.redBasePBL = MakeNewTexture("../resources/textures/pirates/red_base_pirate_badana_turn_left.png", GL_NEAREST, GL_CLAMP_TO_EDGE);
    PiratesSpritesBase.redBasePBR = MakeNewTexture("../resources/textures/pirates/red_base_pirate_badana_turn_right.png", GL_NEAREST, GL_CLAMP_TO_EDGE);
    PiratesSpritesBase.redBasePPL = MakeNewTexture("../resources/textures/pirates/red_base_pirate_turn_left.png", GL_NEAREST, GL_CLAMP_TO_EDGE);
    PiratesSpritesBase.redBasePPR = MakeNewTexture("../resources/textures/pirates/red_base_pirate_turn_right.png", GL_NEAREST, GL_CLAMP_TO_EDGE);
    PiratesSpritesBase.redMainPL = MakeNewTexture("../resources/textures/pirates/red_main_pirate_turn_left.png", GL_NEAREST, GL_CLAMP_TO_EDGE);
    PiratesSpritesBase.redMainPR = MakeNewTexture("../resources/textures/pirates/red_main_pirate_turn_right.png", GL_NEAREST, GL_CLAMP_TO_EDGE);
    
    PiratesSpritesBase.yellowBasePBL = MakeNewTexture("../resources/textures/pirates/yellow_base_pirate_badana_turn_left.png", GL_NEAREST, GL_CLAMP_TO_EDGE);
    PiratesSpritesBase.yellowBasePBR = MakeNewTexture("../resources/textures/pirates/yellow_base_pirate_badana_turn_right.png", GL_NEAREST, GL_CLAMP_TO_EDGE);
    PiratesSpritesBase.yellowMainPL = MakeNewTexture("../resources/textures/pirates/yellow_main_pirate_turn_left.png", GL_NEAREST, GL_CLAMP_TO_EDGE);
    PiratesSpritesBase.yellowMainPR = MakeNewTexture("../resources/textures/pirates/yellow_main_pirate_turn_right.png", GL_NEAREST, GL_CLAMP_TO_EDGE);

    PiratesSpritesBase.noCapBasePL1 = MakeNewTexture("../resources/textures/pirates/no_cap_base_pirate_turn_left.png", GL_NEAREST, GL_CLAMP_TO_EDGE);
    PiratesSpritesBase.noCapBasePR1 = MakeNewTexture("../resources/textures/pirates/no_cap_base_pirate_turn_right.png", GL_NEAREST, GL_CLAMP_TO_EDGE);
    PiratesSpritesBase.noCapBasePL2 = MakeNewTexture("../resources/textures/pirates/no_cap_base_pirate2_turn_left.png", GL_NEAREST, GL_CLAMP_TO_EDGE);
    PiratesSpritesBase.noCapBasePR2 = MakeNewTexture("../resources/textures/pirates/no_cap_base_pirate2_turn_right.png", GL_NEAREST, GL_CLAMP_TO_EDGE);

    PiratesSpritesBase.dead = MakeNewTexture("../resources/textures/pirates/dead.png", GL_NEAREST, GL_CLAMP_TO_EDGE);
    PiratesSpritesBase.waterSplash = MakeNewTexture("../resources/textures/pirates/dot.png", GL_NEAREST, GL_CLAMP_TO_EDGE);
    PiratesSpritesBase.redCross = MakeNewTexture("../resources/textures/pirates/exit_red.png", GL_NEAREST, GL_CLAMP_TO_EDGE);

}

void initMainGameBase15x15()
{
    extern MainMenu sMainMenu;
    extern MainGameBase15x15 sMainGameBase15x15;
    extern ShipBase* shipBase;
    extern ShipBase* botShipBase;

    Sprite* background = initSprite();
    setStartSpriteParams(background, 1280, 720, 0, 0, 0);
    setSpriteTexture(background, "../resources/textures/raftPuttingMenu/10x10/background.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* buttonsPlates = initSprite();
    setStartSpriteParams(buttonsPlates, 1280, 720, 0, 0, 0);
    setSpriteTexture(buttonsPlates, "../resources/textures/mainGame/Base10x10/mainBtnPlates10x10.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* map = initSprite();
    setStartSpriteParams(map, 1280, 720, 0, 0, 0);
    setSpriteTexture(map, "../resources/textures/mainGame/Base15x15/MainMap15x15Basic.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    
    Sprite* exitBtn = initSprite();
    setStartSpriteParams(exitBtn,  60, 60, 1207, 651, 0);
    setSpriteTexture(exitBtn, "../resources/textures/raftPuttingMenu/10x10/exit_black1.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(exitBtn, "../resources/textures/raftPuttingMenu/10x10/exit_red1.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* questionMarkBtn = initSprite();
    setStartSpriteParams(questionMarkBtn, 60, 60, 1109 , 644, 0);
    setSpriteTexture(questionMarkBtn, "../resources/textures/raftPuttingMenu/10x10/qMark_black.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(questionMarkBtn, "../resources/textures/raftPuttingMenu/10x10/qMark_white.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* FAQPlate = initSprite();
    setStartSpriteParams(FAQPlate, 1280, 720, 0 , 0, 0);
    setSpriteTexture(FAQPlate, "../resources/textures/mainGame/FAQPlateBasicGame10x10.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    
    double xPos = 61.43,
           yPos = 540.0;

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            Sprite* mapPlate = initSprite();
            setStartSpriteParams(mapPlate, 34, 34, xPos, yPos, 0);
            xPos += 36.53;

            sMainGameBase15x15.PlayerMapArray[i][j].sprite = mapPlate;
            sMainGameBase15x15.PlayerMapArray[i][j].spriteState = THIS_IS_NOT_SHIP_PLATE;
            sMainGameBase15x15.PlayerMapArray[i][j].sprite->Texture3 = PiratesSpritesBase.waterSplash;

        }
        xPos = 61.43;
        yPos -= 36.52;
    }
    
    xPos = 704.0;
    yPos = 542.0;

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            Sprite* mapPlate = initSprite();
            setStartSpriteParams(mapPlate, 34, 34, xPos, yPos, 0);
            setSpriteTexture(mapPlate, "../resources/textures/raftPuttingMenu/10x10/red.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
            setSpriteTexture(mapPlate, "../resources/textures/raftPuttingMenu/10x10/yellow.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);
            xPos += 36.5;
            
            sMainGameBase15x15.BotMapArray[i][j].sprite = mapPlate;
            sMainGameBase15x15.BotMapArray[i][j].spriteState = THIS_IS_NOT_SHIP_PLATE;
            sMainGameBase15x15.BotMapArray[i][j].sprite->Texture1 = PiratesSpritesBase.redCross;
            sMainGameBase15x15.BotMapArray[i][j].sprite->Texture2 = PiratesSpritesBase.waterSplash;

        }
        xPos = 705.0;
        yPos -= 36.7;
    }


    sMainGameBase15x15.TextParams = sMainMenu.TextParams;
    sMainGameBase15x15.Background = background;
    sMainGameBase15x15.ButtonPlates = buttonsPlates;
    sMainGameBase15x15.MainMap15x15 = map;
    sMainGameBase15x15.ExitBtn = exitBtn;
    sMainGameBase15x15.QuestionMarkBtn = questionMarkBtn;
    sMainGameBase15x15.FAQPlate = FAQPlate;
}


#endif