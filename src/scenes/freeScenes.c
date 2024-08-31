#include "freeScenes.h"

#ifndef FREESCENES_C
#define FREESCENES_C

void freeMainMenu(void)
{
    extern MainMenu sMainMenu;

    freeAnimSprite(sMainMenu.Background);
    freeSprite(sMainMenu.ButtonPlates);
    freeText(sMainMenu.TextParams);
}

void freeAbout(void)
{
    extern About sAbout;

    freeText(sAbout.TextParams2);
    freeAnimSprite(sAbout.Background);
    freeSprite(sAbout.paginationPlates);
    freeSprite(sAbout.pagUp);
    freeSprite(sAbout.pagDown);
    freeSprite(sAbout.MainPlace);
    freeSprite(sAbout.ExitButton);
}

void freeGameSettingsMenu(void)
{
    extern GameSettingsMenu sGameSettingsMenu;

    freeAnimSprite(sGameSettingsMenu.Background);
    freeSprite(sGameSettingsMenu.ButtonPlatesChooseBFS);
    freeSprite(sGameSettingsMenu.ButtonPlatesChooseBL);
    freeSprite(sGameSettingsMenu.ButtonPlatesChooseGM);
    freeSprite(sGameSettingsMenu.PirateWMBFS);
    freeSprite(sGameSettingsMenu.PirateWMBL);
    freeSprite(sGameSettingsMenu.PirateWMGM);
}

void freeRaftPlacement10x10(void)
{
    extern RaftPlacement10x10 sRaftPlacement10X10;
    freeSprite(sRaftPlacement10X10.Background);
    freeSprite(sRaftPlacement10X10.ButtonPlates);
    freeSprite(sRaftPlacement10X10.Map10x10);
    freeSprite(sRaftPlacement10X10.QuestionMarkBtn);
    freeSprite(sRaftPlacement10X10.FAQPlate);
    freeSprite(sRaftPlacement10X10.ExitBtn);

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            freeSprite(sRaftPlacement10X10.MapArray[i][j].sprite);
        }
    }
}

void freeRaftPlacement15x15(void)
{
    extern RaftPlacement15x15 sRaftPlacement15X15;
    freeSprite(sRaftPlacement15X15.Background);
    freeSprite(sRaftPlacement15X15.ButtonPlates);
    freeSprite(sRaftPlacement15X15.Map15x15);
    freeSprite(sRaftPlacement15X15.QuestionMarkBtn);
    freeSprite(sRaftPlacement15X15.FAQPlate);
    freeSprite(sRaftPlacement15X15.ExitBtn);

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            freeSprite(sRaftPlacement15X15.MapArray[i][j].sprite);
        }
    }
}

void freeRaftPlacement10x10BF(void)
{
    extern RaftPlacement10x10BF sRaftPlacement10X10BF;

    freeSprite(sRaftPlacement10X10BF.ButtonPlates);
    freeSprite(sRaftPlacement10X10BF.FAQPlate);

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            freeSprite(sRaftPlacement10X10BF.MapArrayBot1[i][j].sprite);
            freeSprite(sRaftPlacement10X10BF.MapArrayBot2[i][j].sprite);
        }
    }
}

void freeRaftPlacement15x15BF(void)
{
    extern RaftPlacement15x15BF sRaftPlacement15X15BF;

    freeSprite(sRaftPlacement15X15BF.ButtonPlates);
    freeSprite(sRaftPlacement15X15BF.FAQPlate);

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            freeSprite(sRaftPlacement15X15BF.MapArrayBot1[i][j].sprite);
            freeSprite(sRaftPlacement15X15BF.MapArrayBot2[i][j].sprite);
        }
    }
}

void freeMainGameBase10x10(void)
{
    extern MainGameBase10x10 sMainGameBase10x10;

    freeSprite(sMainGameBase10x10.Background);
    freeSprite(sMainGameBase10x10.ButtonPlates);
    freeSprite(sMainGameBase10x10.MainMap10x10);
    freeSprite(sMainGameBase10x10.ExitBtn);
    freeSprite(sMainGameBase10x10.QuestionMarkBtn);
    freeSprite(sMainGameBase10x10.FAQPlate);
    freeSprite(sMainGameBase10x10.lostPlate);
    freeSprite(sMainGameBase10x10.wonPlate);
    freeSprite(sMainGameBase10x10.exitQuestion);

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            freeSprite( sMainGameBase10x10.PlayerMapArray[i][j].sprite);
            freeSprite(sMainGameBase10x10.BotMapArray[i][j].sprite);
        }
    }
}

void freePiratesSprites(void)
{
    extern PiratesSprites PiratesSpritesBase;

    glDeleteTextures(1, &PiratesSpritesBase.blueBasePBL);
    glDeleteTextures(1, &PiratesSpritesBase.blueBasePBR);
    glDeleteTextures(1, &PiratesSpritesBase.blueBasePPL);
    glDeleteTextures(1, &PiratesSpritesBase.blueBasePPR);
    glDeleteTextures(1, &PiratesSpritesBase.blueMainPL);
    glDeleteTextures(1, &PiratesSpritesBase.blueMainPR);
    glDeleteTextures(1, &PiratesSpritesBase.dead);
    glDeleteTextures(1, &PiratesSpritesBase.greenBasePBL);
    glDeleteTextures(1, &PiratesSpritesBase.greenBasePBR);
    glDeleteTextures(1, &PiratesSpritesBase.greenBasePPL);
    glDeleteTextures(1, &PiratesSpritesBase.greenBasePPR);
    glDeleteTextures(1, &PiratesSpritesBase.greenMainPL);
    glDeleteTextures(1, &PiratesSpritesBase.greenMainPR);
    glDeleteTextures(1, &PiratesSpritesBase.noCapBasePL1);
    glDeleteTextures(1, &PiratesSpritesBase.noCapBasePL2);
    glDeleteTextures(1, &PiratesSpritesBase.noCapBasePR1);
    glDeleteTextures(1, &PiratesSpritesBase.noCapBasePR2);
    glDeleteTextures(1, &PiratesSpritesBase.redBasePBL);
    glDeleteTextures(1, &PiratesSpritesBase.redBasePBR);
    glDeleteTextures(1, &PiratesSpritesBase.redBasePPL);
    glDeleteTextures(1, &PiratesSpritesBase.redBasePPR);
    glDeleteTextures(1, &PiratesSpritesBase.redCross);
    glDeleteTextures(1, &PiratesSpritesBase.redMainPL);
    glDeleteTextures(1, &PiratesSpritesBase.redMainPR);
    glDeleteTextures(1, &PiratesSpritesBase.waterSplash);
    glDeleteTextures(1, &PiratesSpritesBase.yellowBasePBL);
    glDeleteTextures(1, &PiratesSpritesBase.yellowBasePBR);
    glDeleteTextures(1, &PiratesSpritesBase.yellowMainPL);
    glDeleteTextures(1, &PiratesSpritesBase.yellowMainPR);
}

void freeMainGameBase15x15(void)
{
    extern MainGameBase15x15 sMainGameBase15x15;

    freeSprite(sMainGameBase15x15.Background);
    freeSprite(sMainGameBase15x15.ButtonPlates);
    freeSprite(sMainGameBase15x15.MainMap15x15);
    freeSprite(sMainGameBase15x15.ExitBtn);
    freeSprite(sMainGameBase15x15.QuestionMarkBtn);
    freeSprite(sMainGameBase15x15.FAQPlate);
    freeSprite(sMainGameBase15x15.lostPlate);
    freeSprite(sMainGameBase15x15.wonPlate);
    freeSprite(sMainGameBase15x15.exitQuestion);

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            freeSprite( sMainGameBase15x15.PlayerMapArray[i][j].sprite);
            freeSprite(sMainGameBase15x15.BotMapArray[i][j].sprite);
        }
    }
}

void freeMainGameBotFight10x10(void)
{
    extern MainGameBotFight10x10 sMainGameBotFight10x10;

    freeSprite(sMainGameBotFight10x10.Background);
    freeSprite(sMainGameBotFight10x10.ButtonPlates);
    freeSprite(sMainGameBotFight10x10.MainMap10x10);
    freeSprite(sMainGameBotFight10x10.ExitBtn);
    freeSprite(sMainGameBotFight10x10.QuestionMarkBtn);
    freeSprite(sMainGameBotFight10x10.FAQPlate);
    freeSprite(sMainGameBotFight10x10.botWinPlate);
    freeSprite(sMainGameBotFight10x10.exitQuestion);

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            freeSprite(sMainGameBotFight10x10.Bot1MapArray[i][j].sprite);
            freeSprite(sMainGameBotFight10x10.Bot2MapArray[i][j].sprite);
        }
    }
}

void freeMainGameBotFight15x15(void)
{
    extern MainGameBotFight15x15 sMainGameBotFight15x15;

    freeSprite(sMainGameBotFight15x15.Background);
    freeSprite(sMainGameBotFight15x15.ButtonPlates);
    freeSprite(sMainGameBotFight15x15.MainMap15x15);
    freeSprite(sMainGameBotFight15x15.ExitBtn);
    freeSprite(sMainGameBotFight15x15.QuestionMarkBtn);
    freeSprite(sMainGameBotFight15x15.FAQPlate);
    freeSprite(sMainGameBotFight15x15.botWinPlate);
    freeSprite(sMainGameBotFight15x15.exitQuestion);

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            freeSprite(sMainGameBotFight15x15.Bot1MapArray[i][j].sprite);
            freeSprite(sMainGameBotFight15x15.Bot2MapArray[i][j].sprite);
        }
    }
}

void freeAddingNickName(void)
{
    extern AddingNickName sAddingNickName;

    freeSprite(sAddingNickName.buttonPlates);
    freeSprite(sAddingNickName.ExitBtn);
    freeSprite(sAddingNickName.QuestionMarkBtn);
    freeSprite(sAddingNickName.FAQPlate);
}

void freeLeaders(void)
{
    extern Leaders sLeaders;
    freeSprite(sLeaders.buttonPlates);
    freeSprite(sLeaders.ExitBtn);
    freeSprite(sLeaders.QuestionMarkBtn);
    freeSprite(sLeaders.FAQPlate);
    freeSprite(sLeaders.pagUp);
    freeSprite(sLeaders.pagDown);
}

void freeGetSaveName(void)
{
    extern GetSaveName sGetSaveName;

    freeSprite(sGetSaveName.buttonPlates);
    freeSprite(sGetSaveName.ExitBtn);
    freeSprite(sGetSaveName.QuestionMarkBtn);
    freeSprite(sGetSaveName.FAQPlate);
}

void freeLoadingMenu(void)
{
    extern LoadingMenu sLoadingMenu;

    freeSprite(sLoadingMenu.buttonPlates);
    freeSprite(sLoadingMenu.ExitBtn);
    freeSprite(sLoadingMenu.QuestionMarkBtn);
    freeSprite(sLoadingMenu.FAQPlate);
    freeSprite(sLoadingMenu.pagUp);
    freeSprite(sLoadingMenu.pagDown);
}

void freeNewLoadMenu(void)
{
    extern NewLoadMenu sNewLoadMenu;
    freeAnimSprite(sNewLoadMenu.Background);
    freeSprite(sNewLoadMenu.ButtonPlates);
}

#endif