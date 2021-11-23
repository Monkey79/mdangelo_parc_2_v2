/*
 * AracadeRepo.c
 *
 *  Created on: 20 nov. 2021
 *      Author: Mariano DAngelo
 */

#include "AracadeRepo.h"

ArcadeEnt* ar_createNewArcade(){
	ArcadeDto arcDto;

	printf("---------------------------------------------------------------------------------\n");
	su_getAlphabeticStringValue("-ingrese nacionalidad del arcade-\n", arcDto.arcCtzshpStr);
	su_getStringValueConditional("-ingrese tipo de sonido [MONO-STEREO]-\n",arcDto.arcSndTypeStr,"MONO","STEREO");
	su_getStringValue("-ingrese cantidad de jugadores-\n",arcDto.arcPlyAmntStr);
	su_getStringValue("-ingrese capacidad max de fichas-\n",arcDto.arcCoinsCapStr);
	su_getAlphabeticStringValue("-ingrese nombre del salon que pertenece-\n",arcDto.arcSaloonName);
	printf("---------------------------------------------------------------------------------\n");


	return ae_createArcadeEntityDto(arcDto);
}

int ar_getAllArcades(LinkedList* arcLList,char* fileName){
	int sucess = TRUE;
	ArcadeDto arcDto;
	FILE* arcFile = NULL;
	int cnt;
	ArcadeEnt* arcEnt=NULL;

	if(arcLList != NULL){
		arcFile = fu_openFileByMode(ARCADE_FILE, "r");
		 //avoid header
		cnt = fscanf(arcFile, ARCADE_REGEX, arcDto.arcIdStr, arcDto.arcCtzshpStr, arcDto.arcSndTypeStr,arcDto.arcPlyAmntStr,arcDto.arcCoinsCapStr,arcDto.arcSaloonName,arcDto.arcGameName);
		do {
			cnt = fscanf(arcFile, ARCADE_REGEX, arcDto.arcIdStr, arcDto.arcCtzshpStr, arcDto.arcSndTypeStr,arcDto.arcPlyAmntStr,arcDto.arcCoinsCapStr,arcDto.arcSaloonName,arcDto.arcGameName);
			if(cnt == ARCADE_REG_CANT){
				arcEnt = ae_createArcadeEntityDto(arcDto); //creo arcade a partir de su dto
				arcEnt->arcId = atoi(arcDto.arcIdStr);
				if(arcEnt!=NULL){
					sucess = ll_add(arcLList,arcEnt);
				}
			}
		} while (!feof(arcFile) && !sucess);
		//TODO remove all arcEnt created
		fclose(arcFile);
	}
	return sucess;
}

void ar_saveArcade(LinkedList* arcLList,char* fileName){
	FILE* arcFile = NULL;
	arcFile = fu_openFileByMode(fileName, "w");

	ArcadeEnt* arcEnt=NULL;
	int arcadeLen;
	char arcSndTypeStr[STR_6];

	if(arcFile!=NULL){
		fprintf(arcFile,"%s,%s,%s,%s,%s,%s,%s\n","id","nacionalidad","tipo_sonido","cant_jug","fichas_max","salon","game"); //HEADER
		arcadeLen = ll_len(arcLList);

		for(int i=0; i<arcadeLen; i++){
			arcEnt = ll_get(arcLList, i);

			strcpy(arcSndTypeStr,(arcEnt->arcSoundType)==1?"MONO":(arcEnt->arcSoundType)==2?"STEREO":"UNDEFINED");

			if(i == arcadeLen-1){ //si es la ultima linea NO ingreso salto de linea
				fprintf(arcFile,"%d,%s,%s,%d,%d,%s,%s",arcEnt->arcId,
											arcEnt->arcCitizenship,arcSndTypeStr,
											arcEnt->arcPlyAmount,arcEnt->arcCoinsCap,
											arcEnt->arcSaloonName,arcEnt->arcGameName);
			}else{
				fprintf(arcFile,"%d,%s,%s,%d,%d,%s,%s\n",arcEnt->arcId,
							arcEnt->arcCitizenship,arcSndTypeStr,
							arcEnt->arcPlyAmount,arcEnt->arcCoinsCap,
							arcEnt->arcSaloonName,arcEnt->arcGameName);
			}
		}
		fclose(arcFile);
	}
}

