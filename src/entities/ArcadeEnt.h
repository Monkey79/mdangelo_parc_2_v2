/*
 * ArcadeEnt.h
 *
 *  Created on: 20 nov. 2021
 *      Author: Mariano DAngelo
 */

#ifndef ENTITIES_ARCADEENT_H_
#define ENTITIES_ARCADEENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../properties_file.h"
#include "../dto/ArcadeDto.h"

typedef struct{
	int arcId; //ai

	char arcCitizenship[STR_100];
	int arcSoundType;
	int arcPlyAmount;
	int arcCoinsCap;
	char arcSaloonName[STR_200];

	int arcGameId; //deprecated
	char arcGameName[STR_63];
}ArcadeEnt;

//--constructors---
ArcadeEnt* ae_createArcadeEntityDto(ArcadeDto arcDto);
ArcadeEnt* ae_createArcadeEntityStr(char* arcIdStr, char* arcCtzShipStr, char* arcSndTpStr, char* arcPlyAmStr, char* arcCnsCapStr, char* arcSlnNmStr, char* arcGmNmStr);

//---setters & getters
void ae_setArcEntId(ArcadeEnt* arcEnt, int arcId);
void ae_setArcCitizenship(ArcadeEnt* arcEnt,char* ctzShipStr);
void ae_setArcSoundType(ArcadeEnt* arcEnt,int arcSndType);
void ae_setArcPlyAmount(ArcadeEnt* arcEnt, int arcPlyAmnt);
void ae_setArcCoinsCpty(ArcadeEnt* arcEnt, int arcCnsCpty);
void ae_setArcSaloonName(ArcadeEnt* arcEnt, char* arcSaloonNameStr);
void ae_setArcGameName(ArcadeEnt* arcEnt, char* arcGameNameStr);

int ae_getArcId(ArcadeEnt* arcEnt);
void ae_getArcCitizenship(ArcadeEnt* arcEnt,char* ctzShipStr);
int ae_getArcSoundType(ArcadeEnt* arcEnt);
int ae_getArcPlyAmount(ArcadeEnt* arcEnt);
int ae_getArcCoinsCpty(ArcadeEnt* arcEnt);
void ae_getArcSaloonName(ArcadeEnt* arcEnt, char* arcSaloonNameStr);
void ae_getArcGameName(ArcadeEnt* arcEnt, char* arcGameNameStr);

#endif /* ENTITIES_ARCADEENT_H_ */
