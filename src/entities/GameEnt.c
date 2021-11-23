/*
 * GameEnt.c
 *
 *  Created on: 23 nov. 2021
 *      Author: Mariano DAngelo
 */

#include "GameEnt.h"


GameEnt* ge_createGameEntity(char* gmIdSt, char* gmNameStr){
	GameEnt* gmEnt = NULL;
	gmEnt = (GameEnt*) malloc(sizeof(GameEnt));

	if(gmEnt != NULL){
		gmEnt->gameId = atoi(gmIdSt);
		strcpy(gmEnt->gameName, gmNameStr);
	}else
		printf(ERROR_NO_MEMORY);

	return gmEnt;
}

//--setters
void ge_setGameId(GameEnt* gmEnt, int gmId){
	if(gmEnt!=NULL)gmEnt->gameId = gmId;
}
void ge_setGameName(GameEnt* gmEnt, char* gmName){
	if(gmEnt!=NULL)strcpy(gmEnt->gameName, gmName);
}
//--getters
int ge_getGameId(GameEnt* gmEnt){
	return (gmEnt!=NULL)?gmEnt->gameId:-1;
}
void ge_getGameName(GameEnt* gmEnt, char* gmName){
	if(gmEnt!=NULL)strcpy(gmName,gmEnt->gameName);
}



