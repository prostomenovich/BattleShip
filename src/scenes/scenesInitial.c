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
MainGameBotFight10x10 sMainGameBotFight10x10;
MainGameBotFight15x15 sMainGameBotFight15x15;
AddingNickName sAddingNickName;
Leaders sLeaders;
GetSaveName sGetSaveName;
LoadingMenu sLoadingMenu;


//ShipBase
ShipBase* shipBase = NULL;
ShipBase* botShipBase = NULL;
ShipBase* shipBaseBFBot1 = NULL;
ShipBase* shipBaseBFBot2 = NULL;
Coordinates* coords[5] = {NULL, };

//Other veriables
PiratesSprites PiratesSpritesBase;
LeaderBoard* leaderBoard = NULL;
SaveNamesList* listSaveNames = NULL;
double lastClickTime = 0;
int playerScore = 0,
    botScore = 0,
    bot1Score = 0,
    bot2Score = 0;
char nickname[MAX_NICKNAME_SIZE] = {'\0',};
char saveName[MAX_SAVENAME_SIZE] = {'\0',};
char loadName[MAX_SAVENAME_SIZE] = {'\0',};

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

char FAQMainGameBotFight [2][MAX_STRING_SIZE] = 
{
    "In this mode you dont need to do anything",
    "Just watch the battle between two bots"
};

const int FAQMainGameBotFightStringCount = 2;

char FAQLoadingGameMenu[5][MAX_STRING_SIZE] =
{
    "Enter the name of the existing save and",
    "click on the Load button. If the save is",
    "correct, you will immediately be taken",
    "to the battlefield. Enter a name for the",
    "save and press delete to delete it."
};

const int FAQLoadingGameMenuStringCount = 5; 

char FAQRaftPlacement[8][MAX_STRING_SIZE] =
{
    "To place a ship you need to go into edit mode. To do",
    "this you need to press the E button if you did",
    "everything correctly the letter E on the right will",
    "glow yellow Next on the map click on the required",
    "number of cells To complete the installation of the",
    "ship press E again The indicator will go out and if",
    "the ship is installed correctly the highlighted cells",
    "will be highlighted in green."
};

const int FAQRaftPlacementStringCount = 8; 

char FAQRaftPlacementBF[10][MAX_STRING_SIZE] =
{
    "To place a ship you need to go into edit mode. To do",
    "this you need to press the E button if you did",
    "everything correctly the letter E on the right will",
    "glow yellow Next on the map click on the required",
    "number of cells To complete the installation of the",
    "ship press E again The indicator will go out and if",
    "the ship is installed correctly the highlighted cells",
    "will be highlighted in green. Buttons B1 and B2 switch",
    "maps for different bots. Place the required number",
    " of ships on both fields to start the game."
};

const int FAQRaftPlacementBFStringCount = 10; 

char FAQAddingName[2][MAX_STRING_SIZE] =
{
    "Enter your nickname using the keyboard",
    "and click Ready."
};

const int FAQAddingNameStringCount = 2; 

char FAQAddingSaveName[2][MAX_STRING_SIZE] =
{
    "Enter a name to save using the keyboard",
    "and click Ready."
};

const int FAQAddingSaveNameStringCount = 2; 



char AboutAuthors [10][MAX_STRING_SIZE] = 
{   "University:         Saint-Pitersburg",
    "                 Politechnic University",
    " ",
    "Authors:",
    "    Tryahov Aleksandr Aleksandrovich",
    "    Volkov Arseny Sergeevich",
    " ",
    "Institute: IKNK",
    "Department: IBKS",
    "Group: 5151003/30002"
};

const int AboutAuthorsStringCount = 10;

char AboutLore [9][MAX_STRING_SIZE] = 
{   "Imagine that you and your opponent are shipwrecked",
    "during a devastated battle.",
    "All the ships sank and the only thing you have left",
    "a small rafts.",
    "Place your faitful pirates around the field and try",
    "not to miss, because this is the only one chance to",
    "win the battle",
    " ",
    "Good luck, brave pirate!",
};

const int AboutLoreStringCount = 9;

char AboutRules [70][MAX_STRING_SIZE] = 
{   
    "The rules of the game in Sea Battle are quite simple.",
    "You need to select one of the proposed modes",
    "and field size.",
    " ",
    "Modes:",
    "    1. Basic",
    "    2. Bots Fight",
    " ",
    "Map Size",
    "    1. 10x10",
    "    2. 15x15",
    " ",
    "In the basic mode, you have to fight with a bot of",
    "one of three difficulty levels (Easy, Normal, Hard).",
    "The first thing you need to do is place your rafts",
    "on the field. After the game starts, you need",
    "to left-click on the opponents field.",
    "If there is a hit, a cross will appear, otherwise",
    "a dot will appear. If you hit, then make another",
    "move, otherwise the move is transferred to the enemy.",
    "The game continues until one of the players runs",
    "out of rafts.",
    " ",
    "In Bots Fight mode you need to select the difficulty",
    "level for the bots and place them on the map. ",
    "Next you just have to enjoy the battle!",
    " ",
    "About Raft Placement:",
    "To place a ship you need to go into edit mode. To do",
    "this, you need to press the E button; if you did",
    "everything correctly, the letter E on the right will",
    "glow yellow. Next, on the map, click on the required",
    "number of cells. To complete the installation of the",
    "ship, press E again. The indicator will go out and if",
    "the ship is installed correctly, the highlighted cells",
    "will be highlighted in green.",
    " ",
    "The number of rafts that need to be placed is",
    "displayed in the upper right corner of the screen.",
    "The game cannot begin until all the rafts have",
    "been placed.",
    "To clear the field from placed rafts, you can use the",
    "Clear button, and to automatically place rafts,",
    "the Autogen button.",
    " ",
    "About LeaderBoard",
    "If you win the battle, you will be asked to add your",
    "name to the leaderboard. Enter your nickname in the",
    "field and click Ready.", 
    "After this, in the main menu you can go to the",
    "LeaderBoard tab, select the required map size and bot",
    "level and see the current leaderboard for this mode.",
    " ",
    "About Saving",
    "If during the game you want to exit, you will be given",
    "the option to save the game. Enter a name in the save",
    "name field and click Ready.",
    " ",
    "About loading game",
    "In the main menu, select loading game, all saves",
    "available to you will appear in the list at the top of",
    "the screen. Enter the name of the desired song on the",
    "keyboard and press Load. If the save file does not contain",
    "errors, then you will be taken to the playing field,",
    "otherwise nothing will happen. If you enter an existing save",
    "and click on the Delete button, this save will be",
    "permanently deleted."
};

const int AboutRulesStringCount = 70;

void initMainMenu()
{
    extern MainMenu sMainMenu;
    extern FT_Library ft1;
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

    Text* textParams = makeNewText(&ft1, "../resources/fonts/Unformital.ttf", 48);

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
    extern FT_Library ft2;
    
    Text* textParams = makeNewText(&ft2, "../resources/fonts/undertale_battle_font.ttf", 48);

    AnimatedSprite* aboutBackground = initAnimatedSprite();
    setStartAnimSpriteParams(aboutBackground, 1280, 720, 0, 0, 0);
    setAnimSpriteFrames(aboutBackground, 3, REPEAT_TRUE, GL_NEAREST, GL_CLAMP_TO_EDGE,
                        "../resources/textures/about/background/aboutBackgroundFrame1.png",
                        "../resources/textures/about/background/aboutBackgroundFrame2.png",
                        "../resources/textures/about/background/aboutBackgroundFrame3.png");

    Sprite* MainPlace = initSprite();
    setStartSpriteParams(MainPlace, 1280, 720, 0, 0, 0);
    setSpriteTexture(MainPlace, "../resources/textures/about/buttons.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* paginationPlates = initSprite();
    setStartSpriteParams(paginationPlates, 1280, 720, 0, 0, 0);
    setSpriteTexture(paginationPlates, "../resources/textures/about/PaginationPlates.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* pagUP = initSprite();
    setStartSpriteParams(pagUP, 1280, 720, 0, 0, 0);
    setSpriteTexture(pagUP, "../resources/textures/about/pagUPnotPressed.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(pagUP, "../resources/textures/about/pagUPPressed.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* pagDown = initSprite();
    setStartSpriteParams(pagDown, 1280, 720, 0, 0, 0);
    setSpriteTexture(pagDown, "../resources/textures/about/pagDOWNnotPressed.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(pagDown, "../resources/textures/about/pagDOWNPressed.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* ExitBTN = initSprite();
    setStartSpriteParams(ExitBTN, 72, 72, 937, 595, 0);
    setSpriteTexture(ExitBTN, "../resources/textures/about/exit_black.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(ExitBTN, "../resources/textures/about/exit_red.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);


    sAbout.TextParams1 = sMainMenu.TextParams;
    sAbout.TextParams2 = textParams;
    sAbout.Background = aboutBackground;
    sAbout.MainPlace = MainPlace;
    sAbout.ExitButton = ExitBTN;
    sAbout.paginationPlates = paginationPlates;
    sAbout.pagUp = pagUP;
    sAbout.pagDown = pagDown;
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
    
    Sprite* FAQPlate = initSprite();
    setStartSpriteParams(FAQPlate, 1280, 720, 0 , 0, 0);
    setSpriteTexture(FAQPlate, "../resources/textures/mainGame/FAQPlateBasicGame10x10.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

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
    sRaftPlacement10X10.FAQPlate = FAQPlate;
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
    
    Sprite* FAQPlate = initSprite();
    setStartSpriteParams(FAQPlate, 1280, 720, 0 , 0, 0);
    setSpriteTexture(FAQPlate, "../resources/textures/mainGame/FAQPlateBasicGame10x10.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

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
    sRaftPlacement15X15.FAQPlate = FAQPlate;
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

    Sprite* FAQPlate = initSprite();
    setStartSpriteParams(FAQPlate, 1280, 720, 0 , 0, 0);
    setSpriteTexture(FAQPlate, "../resources/textures/mainGame/FAQPlateBasicGame10x10.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

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
    sRaftPlacement10X10BF.FAQPlate = FAQPlate;
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

    Sprite* FAQPlate = initSprite();
    setStartSpriteParams(FAQPlate, 1280, 720, 0 , 0, 0);
    setSpriteTexture(FAQPlate, "../resources/textures/mainGame/FAQPlateBasicGame10x10.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

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
    sRaftPlacement15X15BF.FAQPlate = FAQPlate;
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
    setStartSpriteParams(exitBtn,  60, 60, 1197, 644, 0);
    setSpriteTexture(exitBtn, "../resources/textures/raftPuttingMenu/10x10/exit_black1.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(exitBtn, "../resources/textures/raftPuttingMenu/10x10/exit_red1.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* questionMarkBtn = initSprite();
    setStartSpriteParams(questionMarkBtn, 60, 60, 1109 , 644, 0);
    setSpriteTexture(questionMarkBtn, "../resources/textures/raftPuttingMenu/10x10/qMark_black.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(questionMarkBtn, "../resources/textures/raftPuttingMenu/10x10/qMark_white.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* FAQPlate = initSprite();
    setStartSpriteParams(FAQPlate, 1280, 720, 0 , 0, 0);
    setSpriteTexture(FAQPlate, "../resources/textures/mainGame/FAQPlateBasicGame10x10.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* lostPlate = initSprite();
    setStartSpriteParams(lostPlate, 1280, 720, 0 , 0, 0);
    setSpriteTexture(lostPlate, "../resources/textures/mainGame/youLost.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* wonPlate = initSprite();
    setStartSpriteParams(wonPlate, 1280, 720, 0 , 0, 0);
    setSpriteTexture(wonPlate, "../resources/textures/mainGame/youWon.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* exitQuestion = initSprite();
    setStartSpriteParams(exitQuestion, 1280, 720, 0 , 0, 0);
    setSpriteTexture(exitQuestion, "../resources/textures/SaveLoad/QuestionAboutSave.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    
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
    sMainGameBase10x10.lostPlate = lostPlate;
    sMainGameBase10x10.wonPlate = wonPlate;
    sMainGameBase10x10.exitQuestion = exitQuestion;
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
    setStartSpriteParams(exitBtn,  60, 60, 1197, 644, 0);
    setSpriteTexture(exitBtn, "../resources/textures/raftPuttingMenu/10x10/exit_black1.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(exitBtn, "../resources/textures/raftPuttingMenu/10x10/exit_red1.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* questionMarkBtn = initSprite();
    setStartSpriteParams(questionMarkBtn, 60, 60, 1109 , 644, 0);
    setSpriteTexture(questionMarkBtn, "../resources/textures/raftPuttingMenu/10x10/qMark_black.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(questionMarkBtn, "../resources/textures/raftPuttingMenu/10x10/qMark_white.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* FAQPlate = initSprite();
    setStartSpriteParams(FAQPlate, 1280, 720, 0 , 0, 0);
    setSpriteTexture(FAQPlate, "../resources/textures/mainGame/FAQPlateBasicGame10x10.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* lostPlate = initSprite();
    setStartSpriteParams(lostPlate, 1280, 720, 0 , 0, 0);
    setSpriteTexture(lostPlate, "../resources/textures/mainGame/youLost.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* wonPlate = initSprite();
    setStartSpriteParams(wonPlate, 1280, 720, 0 , 0, 0);
    setSpriteTexture(wonPlate, "../resources/textures/mainGame/youWon.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* exitQuestion = initSprite();
    setStartSpriteParams(exitQuestion, 1280, 720, 0 , 0, 0);
    setSpriteTexture(exitQuestion, "../resources/textures/SaveLoad/QuestionAboutSave.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    
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
    sMainGameBase15x15.lostPlate = lostPlate;
    sMainGameBase15x15.wonPlate = wonPlate;
    sMainGameBase15x15.exitQuestion = exitQuestion;
}

void initMainGameBotFight10x10()
{
    extern MainMenu sMainMenu;
    extern MainGameBotFight10x10 sMainGameBotFight10x10;
    extern ShipBase* shipBaseBFBot1;
    extern ShipBase* shipBaseBFBot2;

    Sprite* background = initSprite();
    setStartSpriteParams(background, 1280, 720, 0, 0, 0);
    setSpriteTexture(background, "../resources/textures/raftPuttingMenu/10x10/background.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* buttonsPlates = initSprite();
    setStartSpriteParams(buttonsPlates, 1280, 720, 0, 0, 0);
    setSpriteTexture(buttonsPlates, "../resources/textures/mainGame/mainBtnPlates10x10BF.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* map = initSprite();
    setStartSpriteParams(map, 1280, 720, 0, 0, 0);
    setSpriteTexture(map, "../resources/textures/mainGame/Base10x10/MainMap10x10.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    
    Sprite* exitBtn = initSprite();
    setStartSpriteParams(exitBtn,  60, 60, 1197, 644, 0);
    setSpriteTexture(exitBtn, "../resources/textures/raftPuttingMenu/10x10/exit_black1.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(exitBtn, "../resources/textures/raftPuttingMenu/10x10/exit_red1.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* questionMarkBtn = initSprite();
    setStartSpriteParams(questionMarkBtn, 60, 60, 1109 , 644, 0);
    setSpriteTexture(questionMarkBtn, "../resources/textures/raftPuttingMenu/10x10/qMark_black.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(questionMarkBtn, "../resources/textures/raftPuttingMenu/10x10/qMark_white.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* FAQPlate = initSprite();
    setStartSpriteParams(FAQPlate, 1280, 720, 0 , 0, 0);
    setSpriteTexture(FAQPlate, "../resources/textures/mainGame/FAQPlateBasicGame10x10.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* winPlate = initSprite();
    setStartSpriteParams(winPlate, 1280, 720, 0 , 0, 0);
    setSpriteTexture(winPlate, "../resources/textures/mainGame/BotFightWin.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* exitQuestion = initSprite();
    setStartSpriteParams(exitQuestion, 1280, 720, 0 , 0, 0);
    setSpriteTexture(exitQuestion, "../resources/textures/SaveLoad/QuestionAboutSave.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    
    double xPos = 70.0,
           yPos = 510.0;

    //Клетки поля для Bot1
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            Sprite* mapPlate = initSprite();
            setStartSpriteParams(mapPlate, 50, 50, xPos, yPos, 0);
            xPos += 52;

            sMainGameBotFight10x10.Bot1MapArray[i][j].sprite = mapPlate;
            sMainGameBotFight10x10.Bot1MapArray[i][j].spriteState = THIS_IS_NOT_SHIP_PLATE;
            sMainGameBotFight10x10.Bot1MapArray[i][j].sprite->Texture3 = PiratesSpritesBase.waterSplash;

        }
        xPos = 70.0;
        yPos -= 52.0;
    }
    
    xPos = 722.0;
    yPos = 510.0;

    //Клетки поля для Bot2
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            Sprite* mapPlate = initSprite();
            setStartSpriteParams(mapPlate, 50, 50, xPos, yPos, 0);
            xPos += 52;
            
            sMainGameBotFight10x10.Bot2MapArray[i][j].sprite = mapPlate;
            sMainGameBotFight10x10.Bot2MapArray[i][j].spriteState = THIS_IS_NOT_SHIP_PLATE;
            sMainGameBotFight10x10.Bot2MapArray[i][j].sprite->Texture3 = PiratesSpritesBase.waterSplash;
        }
        xPos = 722.0;
        yPos -= 52.0;
    }

    //if (botShipBase == NULL) botShipBase = initShipBase(MAP_SIZE_10_X_10);

    sMainGameBotFight10x10.TextParams = sMainMenu.TextParams;
    sMainGameBotFight10x10.Background = background;
    sMainGameBotFight10x10.ButtonPlates = buttonsPlates;
    sMainGameBotFight10x10.MainMap10x10 = map;
    sMainGameBotFight10x10.ExitBtn = exitBtn;
    sMainGameBotFight10x10.QuestionMarkBtn = questionMarkBtn;
    sMainGameBotFight10x10.FAQPlate = FAQPlate;
    sMainGameBotFight10x10.botWinPlate = winPlate;
    sMainGameBotFight10x10.exitQuestion = exitQuestion;
}

void initMainGameBotFight15x15()
{
    extern MainMenu sMainMenu;
    extern MainGameBotFight10x10 sMainGameBotFight10x10;
    extern MainGameBotFight15x15 sMainGameBotFight15x15;
    extern ShipBase* shipBaseBFBot1;
    extern ShipBase* shipBaseBFBot2;

    Sprite* background = initSprite();
    setStartSpriteParams(background, 1280, 720, 0, 0, 0);
    setSpriteTexture(background, "../resources/textures/raftPuttingMenu/10x10/background.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* buttonsPlates = initSprite();
    setStartSpriteParams(buttonsPlates, 1280, 720, 0, 0, 0);
    setSpriteTexture(buttonsPlates, "../resources/textures/mainGame/mainBtnPlates10x10BF.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* map = initSprite();
    setStartSpriteParams(map, 1280, 720, 0, 0, 0);
    setSpriteTexture(map, "../resources/textures/mainGame/Base15x15/MainMap15x15Basic.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    
    Sprite* exitBtn = initSprite();
    setStartSpriteParams(exitBtn,  60, 60, 1197, 644, 0);
    setSpriteTexture(exitBtn, "../resources/textures/raftPuttingMenu/10x10/exit_black1.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(exitBtn, "../resources/textures/raftPuttingMenu/10x10/exit_red1.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* questionMarkBtn = initSprite();
    setStartSpriteParams(questionMarkBtn, 60, 60, 1109 , 644, 0);
    setSpriteTexture(questionMarkBtn, "../resources/textures/raftPuttingMenu/10x10/qMark_black.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(questionMarkBtn, "../resources/textures/raftPuttingMenu/10x10/qMark_white.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* FAQPlate = initSprite();
    setStartSpriteParams(FAQPlate, 1280, 720, 0 , 0, 0);
    setSpriteTexture(FAQPlate, "../resources/textures/mainGame/FAQPlateBasicGame10x10.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* winPlate = initSprite();
    setStartSpriteParams(winPlate, 1280, 720, 0 , 0, 0);
    setSpriteTexture(winPlate, "../resources/textures/mainGame/BotFightWin.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* exitQuestion = initSprite();
    setStartSpriteParams(exitQuestion, 1280, 720, 0 , 0, 0);
    setSpriteTexture(exitQuestion, "../resources/textures/SaveLoad/QuestionAboutSave.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    
    double xPos = 61.43,
           yPos = 540.0;

    //Клетки поля для Bot1
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            Sprite* mapPlate = initSprite();
            setStartSpriteParams(mapPlate, 34, 34, xPos, yPos, 0);
            xPos += 36.53;

            sMainGameBotFight15x15.Bot1MapArray[i][j].sprite = mapPlate;
            sMainGameBotFight15x15.Bot1MapArray[i][j].spriteState = THIS_IS_NOT_SHIP_PLATE;
            sMainGameBotFight15x15.Bot1MapArray[i][j].sprite->Texture3 = PiratesSpritesBase.waterSplash;

        }
        xPos = 61.43;
        yPos -= 36.52;
    }
    
    xPos = 704.0;
    yPos = 542.0;

    //Клетки поля для Bot2
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            Sprite* mapPlate = initSprite();
            setStartSpriteParams(mapPlate, 34, 34, xPos, yPos, 0);
            xPos += 36.5;
            
            sMainGameBotFight15x15.Bot2MapArray[i][j].sprite = mapPlate;
            sMainGameBotFight15x15.Bot2MapArray[i][j].spriteState = THIS_IS_NOT_SHIP_PLATE;
            sMainGameBotFight15x15.Bot2MapArray[i][j].sprite->Texture3 = PiratesSpritesBase.waterSplash;
        }
        xPos = 705.0;
        yPos -= 36.7;
    }

    //if (botShipBase == NULL) botShipBase = initShipBase(MAP_SIZE_10_X_10);

    sMainGameBotFight15x15.TextParams = sMainMenu.TextParams;
    sMainGameBotFight15x15.Background = background;
    sMainGameBotFight15x15.ButtonPlates = buttonsPlates;
    sMainGameBotFight15x15.MainMap15x15 = map;
    sMainGameBotFight15x15.ExitBtn = exitBtn;
    sMainGameBotFight15x15.QuestionMarkBtn = questionMarkBtn;
    sMainGameBotFight15x15.FAQPlate = FAQPlate;
    sMainGameBotFight15x15.botWinPlate = winPlate; 
    sMainGameBotFight15x15.exitQuestion = exitQuestion;
}

void initAddingNickName()
{
    extern MainMenu sMainMenu;
    extern About sAbout;
    extern AddingNickName sAddingNickName;
    extern char nickname[MAX_NICKNAME_SIZE];

    memset(nickname, '\0', MAX_NICKNAME_SIZE);

    Sprite* btnPlate = initSprite();
    setStartSpriteParams(btnPlate, 1280, 720, 0 , 0, 0);
    setSpriteTexture(btnPlate, "../resources/textures/AddingNickname/AddingNickPlates.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* exitBtn = initSprite();
    setStartSpriteParams(exitBtn,  60, 60, 1197, 647, 0);
    setSpriteTexture(exitBtn, "../resources/textures/raftPuttingMenu/10x10/exit_black1.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(exitBtn, "../resources/textures/raftPuttingMenu/10x10/exit_red1.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* questionMarkBtn = initSprite();
    setStartSpriteParams(questionMarkBtn, 60, 60, 1112 , 648, 0);
    setSpriteTexture(questionMarkBtn, "../resources/textures/raftPuttingMenu/10x10/qMark_black.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(questionMarkBtn, "../resources/textures/raftPuttingMenu/10x10/qMark_white.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* FAQPlate = initSprite();
    setStartSpriteParams(FAQPlate, 1280, 720, 0 , 0, 0);
    setSpriteTexture(FAQPlate, "../resources/textures/mainGame/FAQPlateBasicGame10x10.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    sAddingNickName.TextParams1 = sMainMenu.TextParams;
    sAddingNickName.TextParams2 = sAbout.TextParams2;
    sAddingNickName.Background = sAbout.Background;
    sAddingNickName.buttonPlates = btnPlate;
    sAddingNickName.ExitBtn = exitBtn;
    sAddingNickName.QuestionMarkBtn = questionMarkBtn;
    sAddingNickName.FAQPlate = FAQPlate;
}

void initLeaders()
{
    extern MainMenu sMainMenu;
    extern About sAbout;
    extern Leaders sLeaders;
    extern LeaderBoard* leaderBoard;

    leaderBoard = getDataFromLeaderBoard(PATH_TO_LEADERBOARD_DATA);

    Sprite* btnPlate = initSprite();
    setStartSpriteParams(btnPlate, 1280, 720, 0 , 0, 0);
    setSpriteTexture(btnPlate, "../resources/textures/LeaderBoard/btnplates.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* exitBtn = initSprite();
    setStartSpriteParams(exitBtn,  60, 60, 1202, 645, 0);
    setSpriteTexture(exitBtn, "../resources/textures/raftPuttingMenu/10x10/exit_black1.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(exitBtn, "../resources/textures/raftPuttingMenu/10x10/exit_red1.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* questionMarkBtn = initSprite();
    setStartSpriteParams(questionMarkBtn, 60, 60, 1109 , 644, 0);
    setSpriteTexture(questionMarkBtn, "../resources/textures/raftPuttingMenu/10x10/qMark_black.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(questionMarkBtn, "../resources/textures/raftPuttingMenu/10x10/qMark_white.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* FAQPlate = initSprite();
    setStartSpriteParams(FAQPlate, 1280, 720, 0 , 0, 0);
    setSpriteTexture(FAQPlate, "../resources/textures/mainGame/FAQPlateBasicGame10x10.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* pagUP = initSprite();
    setStartSpriteParams(pagUP, 1260, 700, 136, 2, 0);
    setSpriteTexture(pagUP, "../resources/textures/about/pagUPnotPressed.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(pagUP, "../resources/textures/about/pagUPPressed.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* pagDown = initSprite();
    setStartSpriteParams(pagDown, 1260, 700, 136, 14, 0);
    setSpriteTexture(pagDown, "../resources/textures/about/pagDOWNnotPressed.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(pagDown, "../resources/textures/about/pagDOWNPressed.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    sLeaders.TextParams1 = sMainMenu.TextParams;
    sLeaders.TextParams2 = sAbout.TextParams2;
    sLeaders.Background = sAbout.Background;
    sLeaders.buttonPlates = btnPlate;
    sLeaders.ExitBtn = exitBtn;
    sLeaders.QuestionMarkBtn = questionMarkBtn;
    sLeaders.FAQPlate = FAQPlate;
    sLeaders.pagUp = pagUP;
    sLeaders.pagDown = pagDown;
}

void initGetSaveName()
{
    extern MainMenu sMainMenu;
    extern About sAbout;
    extern GetSaveName sGetSaveName;
    extern char saveName[MAX_SAVENAME_SIZE];

    memset(saveName, '\0', MAX_SAVENAME_SIZE);

    Sprite* btnPlate = initSprite();
    setStartSpriteParams(btnPlate, 1280, 720, 0 , 0, 0);
    setSpriteTexture(btnPlate, "../resources/textures/SaveLoad/getSaveNameScene.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* exitBtn = initSprite();
    setStartSpriteParams(exitBtn,  60, 60, 1198, 649, 0);
    setSpriteTexture(exitBtn, "../resources/textures/raftPuttingMenu/10x10/exit_black1.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(exitBtn, "../resources/textures/raftPuttingMenu/10x10/exit_red1.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* questionMarkBtn = initSprite();
    setStartSpriteParams(questionMarkBtn, 60, 60, 1112 , 648, 0);
    setSpriteTexture(questionMarkBtn, "../resources/textures/raftPuttingMenu/10x10/qMark_black.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(questionMarkBtn, "../resources/textures/raftPuttingMenu/10x10/qMark_white.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* FAQPlate = initSprite();
    setStartSpriteParams(FAQPlate, 1280, 720, 0 , 0, 0);
    setSpriteTexture(FAQPlate, "../resources/textures/mainGame/FAQPlateBasicGame10x10.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    sGetSaveName.TextParams1 = sMainMenu.TextParams;
    sGetSaveName.TextParams2 = sAbout.TextParams2;
    sGetSaveName.Background = sAbout.Background;
    sGetSaveName.buttonPlates = btnPlate;
    sGetSaveName.ExitBtn = exitBtn;
    sGetSaveName.QuestionMarkBtn = questionMarkBtn;
    sGetSaveName.FAQPlate = FAQPlate;
}


void initLoadingMenu()
{
    extern MainMenu sMainMenu;
    extern About sAbout;
    extern LoadingMenu sLoadingMenu;
    extern char loadName[MAX_SAVENAME_SIZE];
    
    
    memset(loadName, '\0', MAX_SAVENAME_SIZE);

    Sprite* btnPlate = initSprite();
    setStartSpriteParams(btnPlate, 1280, 720, 0 , 0, 0);
    setSpriteTexture(btnPlate, "../resources/textures/loadingMenu/loadMenu.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* exitBtn = initSprite();
    setStartSpriteParams(exitBtn,  60, 60, 1204, 651, 0);
    setSpriteTexture(exitBtn, "../resources/textures/raftPuttingMenu/10x10/exit_black1.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(exitBtn, "../resources/textures/raftPuttingMenu/10x10/exit_red1.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* questionMarkBtn = initSprite();
    setStartSpriteParams(questionMarkBtn, 60, 60, 1203 , 579, 0);
    setSpriteTexture(questionMarkBtn, "../resources/textures/raftPuttingMenu/10x10/qMark_black.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(questionMarkBtn, "../resources/textures/raftPuttingMenu/10x10/qMark_white.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* FAQPlate = initSprite();
    setStartSpriteParams(FAQPlate, 1280, 720, 0 , 0, 0);
    setSpriteTexture(FAQPlate, "../resources/textures/mainGame/FAQPlateBasicGame10x10.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);

    Sprite* pagUP = initSprite();
    setStartSpriteParams(pagUP, 55, 55, 903, 530, 0);
    setSpriteTexture(pagUP, "../resources/textures/loadingMenu/pagUPblack.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(pagUP, "../resources/textures/loadingMenu/pagUPwhite.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);

    Sprite* pagDown = initSprite();
    setStartSpriteParams(pagDown, 55, 55, 903, 452, 0);
    setSpriteTexture(pagDown, "../resources/textures/loadingMenu/pagDOWNblack.png", GL_NEAREST, GL_CLAMP_TO_EDGE, FIRST_TEXTURE);
    setSpriteTexture(pagDown, "../resources/textures/loadingMenu/pagDOWNwhite.png", GL_NEAREST, GL_CLAMP_TO_EDGE, SECOND_TEXTURE);


    sLoadingMenu.TextParams1 = sMainMenu.TextParams;
    sLoadingMenu.TextParams2 = sAbout.TextParams2;
    sLoadingMenu.Background = sAbout.Background;
    sLoadingMenu.buttonPlates = btnPlate;
    sLoadingMenu.ExitBtn = exitBtn;
    sLoadingMenu.QuestionMarkBtn = questionMarkBtn;
    sLoadingMenu.FAQPlate = FAQPlate;
    sLoadingMenu.pagUp = pagUP;
    sLoadingMenu.pagDown = pagDown;
}
#endif