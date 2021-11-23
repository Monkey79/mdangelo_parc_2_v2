/*
 * AracadeRepo.h
 *
 *  Created on: 20 nov. 2021
 *      Author: Mariano DAngelo
 */

#ifndef REPOSITORIES_ARACADEREPO_H_
#define REPOSITORIES_ARACADEREPO_H_

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#include "../dto/ArcadeDto.h"
#include "../entities/ArcadeEnt.h"

#include "../utils/StringUtil.h"
#include "../utils/IntUtil.h"
#include "../utils/LinkedList.h"
#include "../utils/FileUtil.h"

ArcadeEnt* ar_createNewArcade();

void ar_saveArcade(LinkedList* arcLList,char* fileName);
int ar_getAllArcades(LinkedList* arcLList,char* fileName);

#endif /* REPOSITORIES_ARACADEREPO_H_ */
