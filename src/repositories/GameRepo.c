/*
 * GameRepo.c
 *
 *  Created on: 20 nov. 2021
 *      Author: Mariano DAngelo
 */


#include "GameRepo.h"

GameEnt* gr_createGame(char* gmIdStr,char* gmName){
	GameEnt* gmEnt = (GameEnt*) malloc(sizeof(GameEnt));
	if(gmEnt != NULL){
		gmEnt->gameId = atoi(gmIdStr);
		strcpy(gmEnt->gameName, gmName);
	}else
		printf(ERROR_NO_MEMORY);

	return gmEnt;
}

GameEnt* gr_getGameEntByIdx(LinkedList* gmLList,int idx){
	GameEnt* gmEnt = NULL;
	if(gmLList != NULL) gmEnt = ll_get(gmLList, idx);
	return gmEnt;
}

void gr_saveAllGames(LinkedList* gmLList){
	FILE* gmFile = NULL;
	GameEnt* gmEnt = NULL;
	int len;

	gmFile = fu_openFileByMode(GAME_FILE, "w");

	if(gmFile!=NULL){
		len = ll_len(gmLList);
		fprintf(gmFile,"%s,%s\n","id","game"); //-write header-
		for(int i=0;i<len;i++){
			gmEnt = ll_get(gmLList, i);
			//-si es ultimo registro no ingreso 'salto de linea'
			if(i==(len-1))
				fprintf(gmFile,"%d,%s",gmEnt->gameId,gmEnt->gameName);
			else
				fprintf(gmFile,"%d,%s\n",gmEnt->gameId,gmEnt->gameName);
		}
	}
	fclose(gmFile);
}




int gr_getGameIdByName(LinkedList* gmLList,char* gameName){
	int match = FALSE;
	int id = -1;
	GameEnt* gmEnt;

	if(gmLList != NULL){
		for (int i = 0; i<gmLList->size && !match; i++) {
			gmEnt = ll_get(gmLList, i);
			match = (strcmp(gmEnt->gameName,gameName)==0)?TRUE:FALSE;
			if(match) id = gmEnt->gameId;
		}
	}
	return id;
}

int gr_getGameNameById(LinkedList* gmLList,int gameId,char* gameName){
	int success = TRUE;
	int match = FALSE;
	GameEnt* gmEnt;

	if(gmLList != NULL){
		for (int i = 0; i<gmLList->size && !match; i++) {
			gmEnt = ll_get(gmLList, i);
			match = gmEnt->gameId == gameId;
			if(match) strcpy(gameName,gmEnt->gameName);
		}
	}else
		success = FALSE;

	return success;
}

