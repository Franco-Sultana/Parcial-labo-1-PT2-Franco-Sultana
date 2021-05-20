/*
 * eBicicleta.h
 *
 *  Created on: 20 may. 2021
 *      Author: F2019
 */

#ifndef EBICICLETA_H_
#define EBICICLETA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN.h"


typedef struct
{
	int id;
	char marca[26];
	int rodado;
	char color[20];
	int isEmpty;
}eBicicleta;

void HarcodearBicicletas(eBicicleta listaBicicleta[], int tamBici);

int BuscarIdBicicleta(eBicicleta listaBici[], int tamBici, int buscarId);

int MostrarTodasLasBicicletas(eBicicleta listaBici[], int tamBici);

int ObtenerIdBicicletaDelIndex(eBicicleta listaBici[], int tamBici, int* idServ);


#endif /* EBICICLETA_H_ */
