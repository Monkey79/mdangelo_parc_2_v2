/*
 * GameRepo.h
 *
 *  Created on: 20 nov. 2021
 *      Author: Mariano DAngelo
 */

#ifndef REPOSITORIES_GAMEREPO_H_
#define REPOSITORIES_GAMEREPO_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>


#include "../entities/GameEnt.h"
#include "../utils/LinkedList.h"
#include "../utils/FileUtil.h"
#include "../properties_file.h"

GameEnt* gr_createGame(char* gmIdStr,char* gmName);
void gr_saveAllGames(LinkedList* gmLList);

int gr_getGameIdByName(LinkedList* gmLList,char* gameName);
int gr_getGameNameById(LinkedList* gmLList,int gameId,char* gameName);

#endif /* REPOSITORIES_GAMEREPO_H_ */
