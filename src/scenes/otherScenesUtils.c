#include "otherScenesUtils.h"

#ifndef OTHERSCENESUTILS_C
#define OTHERSCENESUTILS_C

void fillShipsTextures(MapSprite SpriteArray[10][10], ShipBase* shipBase, int map[18][18], int turn)
{
    extern PiratesSprites PiratesSpritesBase;
    int currentShipsCount;
    ShipBase* sb = shipBase;
    if (turn == TEXTURES_TURN_RIGHT){
        while (sb != NULL)
        {
            currentShipsCount = sb->shipsCount;
            if (sb->shipType == ONE_BLOCK_SHIP){
                for (int i = 0; i < currentShipsCount; i++){
                    if (rand() % 2 == 0)
                        SpriteArray[sb->ships[i]->coords[0]->y][sb->ships[i]->coords[0]->x].sprite->Texture1 = PiratesSpritesBase.noCapBasePR1;
                    else 
                        SpriteArray[sb->ships[i]->coords[0]->y][sb->ships[i]->coords[0]->x].sprite->Texture1 = PiratesSpritesBase.noCapBasePR2;
                    
                    SpriteArray[sb->ships[i]->coords[0]->y][sb->ships[i]->coords[0]->x].sprite->Texture2 = PiratesSpritesBase.dead;

                    SpriteArray[sb->ships[i]->coords[0]->y][sb->ships[i]->coords[0]->x].sprite->Texture3 = PiratesSpritesBase.waterSplash;
                }
            }
            else if (sb->shipType == TWO_BLOCKS_SHIP){
                for (int i = 0; i < currentShipsCount; i++){
                    SpriteArray[sb->ships[i]->coords[0]->y][sb->ships[i]->coords[0]->x].sprite->Texture1 = PiratesSpritesBase.yellowMainPR;
                    SpriteArray[sb->ships[i]->coords[1]->y][sb->ships[i]->coords[1]->x].sprite->Texture1 = PiratesSpritesBase.yellowBasePBR;
                    
                    SpriteArray[sb->ships[i]->coords[0]->y][sb->ships[i]->coords[0]->x].sprite->Texture2 = PiratesSpritesBase.dead;
                    SpriteArray[sb->ships[i]->coords[1]->y][sb->ships[i]->coords[1]->x].sprite->Texture2 = PiratesSpritesBase.dead;

                    SpriteArray[sb->ships[i]->coords[0]->y][sb->ships[i]->coords[0]->x].sprite->Texture3 = PiratesSpritesBase.waterSplash;
                    SpriteArray[sb->ships[i]->coords[1]->y][sb->ships[i]->coords[1]->x].sprite->Texture3 = PiratesSpritesBase.waterSplash;
                }
            }
            else if (sb->shipType == THREE_BLOCKS_SHIP){
                for (int i = 0; i < currentShipsCount; i++){
                    if (rand() % 2 == 0){
                        SpriteArray[sb->ships[i]->coords[0]->y][sb->ships[i]->coords[0]->x].sprite->Texture1 = PiratesSpritesBase.blueMainPR;
                        SpriteArray[sb->ships[i]->coords[1]->y][sb->ships[i]->coords[1]->x].sprite->Texture1 = PiratesSpritesBase.blueBasePBR;
                        SpriteArray[sb->ships[i]->coords[2]->y][sb->ships[i]->coords[2]->x].sprite->Texture1 = PiratesSpritesBase.blueBasePBR;
                    }
                    else {
                        SpriteArray[sb->ships[i]->coords[0]->y][sb->ships[i]->coords[0]->x].sprite->Texture1 = PiratesSpritesBase.blueMainPR;
                        SpriteArray[sb->ships[i]->coords[1]->y][sb->ships[i]->coords[1]->x].sprite->Texture1 = PiratesSpritesBase.blueBasePPR;
                        SpriteArray[sb->ships[i]->coords[2]->y][sb->ships[i]->coords[2]->x].sprite->Texture1 = PiratesSpritesBase.blueBasePPR;
                    }
                     
                    SpriteArray[sb->ships[i]->coords[0]->y][sb->ships[i]->coords[0]->x].sprite->Texture2 = PiratesSpritesBase.dead;
                    SpriteArray[sb->ships[i]->coords[1]->y][sb->ships[i]->coords[1]->x].sprite->Texture2 = PiratesSpritesBase.dead;
                    SpriteArray[sb->ships[i]->coords[2]->y][sb->ships[i]->coords[2]->x].sprite->Texture2 = PiratesSpritesBase.dead;

                    SpriteArray[sb->ships[i]->coords[0]->y][sb->ships[i]->coords[0]->x].sprite->Texture3 = PiratesSpritesBase.waterSplash;
                    SpriteArray[sb->ships[i]->coords[1]->y][sb->ships[i]->coords[1]->x].sprite->Texture3 = PiratesSpritesBase.waterSplash;
                    SpriteArray[sb->ships[i]->coords[2]->y][sb->ships[i]->coords[2]->x].sprite->Texture3 = PiratesSpritesBase.waterSplash;
                }
            }
            else if (sb->shipType == FOUR_BLOCKS_SHIP){
                for (int i = 0; i < currentShipsCount; i++){
                    if (rand() % 2 == 0){
                        SpriteArray[sb->ships[i]->coords[0]->y][sb->ships[i]->coords[0]->x].sprite->Texture1 = PiratesSpritesBase.redMainPR;
                        SpriteArray[sb->ships[i]->coords[1]->y][sb->ships[i]->coords[1]->x].sprite->Texture1 = PiratesSpritesBase.redBasePBR;
                        SpriteArray[sb->ships[i]->coords[2]->y][sb->ships[i]->coords[2]->x].sprite->Texture1 = PiratesSpritesBase.redBasePBR;
                        SpriteArray[sb->ships[i]->coords[3]->y][sb->ships[i]->coords[3]->x].sprite->Texture1 = PiratesSpritesBase.redBasePBR;
                    }
                    else {
                        SpriteArray[sb->ships[i]->coords[0]->y][sb->ships[i]->coords[0]->x].sprite->Texture1 = PiratesSpritesBase.redMainPR;
                        SpriteArray[sb->ships[i]->coords[1]->y][sb->ships[i]->coords[1]->x].sprite->Texture1 = PiratesSpritesBase.redBasePPR;
                        SpriteArray[sb->ships[i]->coords[2]->y][sb->ships[i]->coords[2]->x].sprite->Texture1 = PiratesSpritesBase.redBasePPR;
                        SpriteArray[sb->ships[i]->coords[3]->y][sb->ships[i]->coords[3]->x].sprite->Texture1 = PiratesSpritesBase.redBasePPR;
                    }
                     
                    SpriteArray[sb->ships[i]->coords[0]->y][sb->ships[i]->coords[0]->x].sprite->Texture2 = PiratesSpritesBase.dead;
                    SpriteArray[sb->ships[i]->coords[1]->y][sb->ships[i]->coords[1]->x].sprite->Texture2 = PiratesSpritesBase.dead;
                    SpriteArray[sb->ships[i]->coords[2]->y][sb->ships[i]->coords[2]->x].sprite->Texture2 = PiratesSpritesBase.dead;
                    SpriteArray[sb->ships[i]->coords[3]->y][sb->ships[i]->coords[3]->x].sprite->Texture2 = PiratesSpritesBase.dead;

                    SpriteArray[sb->ships[i]->coords[0]->y][sb->ships[i]->coords[0]->x].sprite->Texture3 = PiratesSpritesBase.waterSplash;
                    SpriteArray[sb->ships[i]->coords[1]->y][sb->ships[i]->coords[1]->x].sprite->Texture3 = PiratesSpritesBase.waterSplash;
                    SpriteArray[sb->ships[i]->coords[2]->y][sb->ships[i]->coords[2]->x].sprite->Texture3 = PiratesSpritesBase.waterSplash;
                    SpriteArray[sb->ships[i]->coords[3]->y][sb->ships[i]->coords[3]->x].sprite->Texture3 = PiratesSpritesBase.waterSplash;
                }
            }
            else if (sb->shipType == FIVE_BLOCKS_SHIP){
                for (int i = 0; i < currentShipsCount; i++){
                    if (rand() % 2 == 0){
                        SpriteArray[sb->ships[i]->coords[0]->y][sb->ships[i]->coords[0]->x].sprite->Texture1 = PiratesSpritesBase.blueMainPR;
                        SpriteArray[sb->ships[i]->coords[1]->y][sb->ships[i]->coords[1]->x].sprite->Texture1 = PiratesSpritesBase.blueBasePBR;
                        SpriteArray[sb->ships[i]->coords[2]->y][sb->ships[i]->coords[2]->x].sprite->Texture1 = PiratesSpritesBase.blueBasePBR;
                        SpriteArray[sb->ships[i]->coords[3]->y][sb->ships[i]->coords[3]->x].sprite->Texture1 = PiratesSpritesBase.blueBasePBR;
                        SpriteArray[sb->ships[i]->coords[4]->y][sb->ships[i]->coords[4]->x].sprite->Texture1 = PiratesSpritesBase.blueBasePBR;
                    }
                    else {
                        SpriteArray[sb->ships[i]->coords[0]->y][sb->ships[i]->coords[0]->x].sprite->Texture1 = PiratesSpritesBase.blueMainPR;
                        SpriteArray[sb->ships[i]->coords[1]->y][sb->ships[i]->coords[1]->x].sprite->Texture1 = PiratesSpritesBase.blueBasePPR;
                        SpriteArray[sb->ships[i]->coords[2]->y][sb->ships[i]->coords[2]->x].sprite->Texture1 = PiratesSpritesBase.blueBasePPR;
                        SpriteArray[sb->ships[i]->coords[3]->y][sb->ships[i]->coords[3]->x].sprite->Texture1 = PiratesSpritesBase.blueBasePPR;
                        SpriteArray[sb->ships[i]->coords[4]->y][sb->ships[i]->coords[4]->x].sprite->Texture1 = PiratesSpritesBase.blueBasePBR;
                    }
                     
                    SpriteArray[sb->ships[i]->coords[0]->y][sb->ships[i]->coords[0]->x].sprite->Texture2 = PiratesSpritesBase.dead;
                    SpriteArray[sb->ships[i]->coords[1]->y][sb->ships[i]->coords[1]->x].sprite->Texture2 = PiratesSpritesBase.dead;
                    SpriteArray[sb->ships[i]->coords[2]->y][sb->ships[i]->coords[2]->x].sprite->Texture2 = PiratesSpritesBase.dead;
                    SpriteArray[sb->ships[i]->coords[3]->y][sb->ships[i]->coords[3]->x].sprite->Texture2 = PiratesSpritesBase.dead;
                    SpriteArray[sb->ships[i]->coords[4]->y][sb->ships[i]->coords[4]->x].sprite->Texture2 = PiratesSpritesBase.dead;

                    SpriteArray[sb->ships[i]->coords[0]->y][sb->ships[i]->coords[0]->x].sprite->Texture3 = PiratesSpritesBase.waterSplash;
                    SpriteArray[sb->ships[i]->coords[1]->y][sb->ships[i]->coords[1]->x].sprite->Texture3 = PiratesSpritesBase.waterSplash;
                    SpriteArray[sb->ships[i]->coords[2]->y][sb->ships[i]->coords[2]->x].sprite->Texture3 = PiratesSpritesBase.waterSplash;
                    SpriteArray[sb->ships[i]->coords[3]->y][sb->ships[i]->coords[3]->x].sprite->Texture3 = PiratesSpritesBase.waterSplash;
                    SpriteArray[sb->ships[i]->coords[4]->y][sb->ships[i]->coords[4]->x].sprite->Texture3 = PiratesSpritesBase.waterSplash;
                }
            }

            sb = sb->nextShip;
            
        }
        
    }
    else {

    }
}


#endif
