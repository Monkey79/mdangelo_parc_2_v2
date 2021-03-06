/*
 * GameSrvc.h
 *
 *  Created on: 20 nov. 2021
 *      Author: Mariano DAngelo
 */

#ifndef SERVICES_GAMESRVC_H_
#define SERVICES_GAMESRVC_H_

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

#include "../properties_file.h"
#include "../utils/LinkedList.h"
#include "../utils/FileUtil.h"
#include "../entities/GameEnt.h"
#include "../repositories/GameRepo.h"

GameEnt* gs_createNewGameEnt(char* gmId, char* gmName);

int gs_chargeGamesFromFile(LinkedList** gamesLList);
void gs_printAllGames(LinkedList* gameLList);
void gs_checkGameIfNotExistCreate(LinkedList** gmLList, char* gameStr);
int gs_writeGames(LinkedList* gmLList);
int gs_gameAlreadyExist(LinkedList* gmLList,char* gameName);

int gs_getGameNameById(LinkedList* gmLList,int gameId,char* gameName);
int gs_getGameIdByName(LinkedList* gmLList,char* gameName);

#endif /* SERVICES_GAMESRVC_H_ */
