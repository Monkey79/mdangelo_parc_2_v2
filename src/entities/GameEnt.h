/*
 * GameEnt.h
 *
 *  Created on: 20 nov. 2021
 *      Author: Mariano DAngelo
 */

#ifndef ENTITIES_GAMEENT_H_
#define ENTITIES_GAMEENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../properties_file.h"

typedef struct {
	int gameId;
	char gameName[STR_200];
}GameEnt;

//--constructors---
GameEnt* ge_createGameEntity(char* gmIdSt, char* gmNameStr);

//---setters & getters
void ge_setGameId(GameEnt* gmEnt, int gmId);
void ge_setGameName(GameEnt* gmEnt, char* gmName);
int ge_getGameId(GameEnt* gmEnt);
void ge_getGameName(GameEnt* gmEnt, char* gmName);

#endif /* ENTITIES_GAMEENT_H_ */
