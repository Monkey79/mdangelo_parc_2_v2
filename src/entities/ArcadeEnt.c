/*
 * ArcadeEnt.c
 *
 *  Created on: 22 nov. 2021
 *      Author: Mariano DAngelo
 */

#include "ArcadeEnt.h"

ArcadeEnt* ae_createArcadeEntityDto(ArcadeDto arcDto){
	ArcadeEnt* arcEnt = (ArcadeEnt*) malloc(sizeof(ArcadeEnt));
	if(arcEnt!=NULL){
		arcEnt->arcId = atof(arcDto.arcIdStr);
		strcpy(arcEnt->arcCitizenship, arcDto.arcCtzshpStr);
		arcEnt->arcSoundType = ( (strcmp(arcDto.arcSndTypeStr,TYPE_1)==0)?1: (strcmp(arcDto.arcSndTypeStr,TYPE_2)==0)?2:-1);
		arcEnt->arcPlyAmount = atoi(arcDto.arcPlyAmntStr);
		arcEnt->arcCoinsCap = atoi(arcDto.arcCoinsCapStr);
		strcpy(arcEnt->arcSaloonName, arcDto.arcSaloonName);
		strcpy(arcEnt->arcGameName, arcDto.arcGameName);
	}
	printf("ArcEnt %p\n",arcEnt);
	return arcEnt;
}

ArcadeEnt* ae_createArcadeEntityStr(char* arcIdStr, char* arcCtzShipStr, char* arcSndTpStr, char* arcPlyAmStr, char* arcCnsCapStr, char* arcSlnNmStr, char* arcGmNmStr){
	ArcadeEnt* arcEnt = (ArcadeEnt*) malloc(sizeof(ArcadeEnt));
	if(arcEnt!=NULL){
		arcEnt->arcId = atoi(arcIdStr);
		strcpy(arcEnt->arcCitizenship, arcCtzShipStr);
		arcEnt->arcSoundType = ( (strcmp(arcSndTpStr,TYPE_1)==0)?1: (strcmp(arcSndTpStr,TYPE_2)==0)?2:-1);
		arcEnt->arcPlyAmount = atoi(arcPlyAmStr);
		arcEnt->arcCoinsCap = atoi(arcCnsCapStr);
		strcpy(arcEnt->arcSaloonName, arcSlnNmStr);
		strcpy(arcEnt->arcGameName, arcGmNmStr);
	}
	return arcEnt;
}

//---setters
void ae_setArcEntId(ArcadeEnt* arcEnt, int arcId){
	if(arcEnt!=NULL) arcEnt->arcId = arcId;
}
void ae_setArcCitizenship(ArcadeEnt* arcEnt,char* ctzShipStr){
	if(arcEnt!=NULL) strcpy(arcEnt->arcCitizenship, ctzShipStr);
}
void ae_setArcSoundType(ArcadeEnt* arcEnt,int arcSndType){
	if(arcEnt!=NULL) arcEnt->arcSoundType = arcSndType;
}
void ae_setArcPlyAmount(ArcadeEnt* arcEnt, int arcPlyAmnt){
	if(arcEnt!=NULL) arcEnt->arcPlyAmount = arcPlyAmnt;
}
void ae_setArcCoinsCpty(ArcadeEnt* arcEnt, int arcCnsCpty){
	if(arcEnt!=NULL) arcEnt->arcCoinsCap = arcCnsCpty;
}
void ae_setArcSaloonName(ArcadeEnt* arcEnt, char* arcSaloonNameStr){
	if(arcEnt!=NULL) strcpy(arcEnt->arcSaloonName, arcSaloonNameStr);
}
void ae_setArcGameName(ArcadeEnt* arcEnt, char* arcGameNameStr){
	if(arcEnt!=NULL) strcpy(arcEnt->arcGameName, arcGameNameStr);
}
//--getters
int ae_getArcId(ArcadeEnt* arcEnt){
	return (arcEnt!=NULL)?arcEnt->arcId:-1;
}
void ae_getArcCitizenship(ArcadeEnt* arcEnt,char* ctzShipStr){
	(arcEnt!=NULL)?strcpy(ctzShipStr, arcEnt->arcCitizenship):strcpy(ctzShipStr, "UNDEFINED");
}
int ae_getArcSoundType(ArcadeEnt* arcEnt){
	return (arcEnt!=NULL)?arcEnt->arcSoundType:-1;
}
int ae_getArcPlyAmount(ArcadeEnt* arcEnt){
	return (arcEnt!=NULL)?arcEnt->arcPlyAmount:-1;
}
int ae_getArcCoinsCpty(ArcadeEnt* arcEnt){
	return (arcEnt!=NULL)?arcEnt->arcCoinsCap:-1;
}
void ae_getArcSaloonName(ArcadeEnt* arcEnt, char* arcSaloonNameStr){
	(arcEnt!=NULL)?strcpy(arcSaloonNameStr, arcEnt->arcSaloonName):strcpy(arcSaloonNameStr, "UNDEFINED");
}
void ae_getArcGameName(ArcadeEnt* arcEnt, char* arcGameNameStr){
	(arcEnt!=NULL)?strcpy(arcGameNameStr, arcEnt->arcSaloonName):strcpy(arcGameNameStr, "UNDEFINED");
}


