/*
 * eBicicleta.c
 *
 *  Created on: 20 may. 2021
 *      Author: F2019
 */

#include "eBicicleta.h"


void HarcodearBicicletas(eBicicleta listaBicicleta[], int tamBici)
{
	int i;
	int idBici[5] = {25, 26, 27, 28, 29};
	char marcaBici[5][26] = {"BMX", "ABUS", "ALTRA", "ASISATA", "BRUNOX"};
	int rodadoBici[5] = {20, 24, 12, 26, 20};
	char colorBici[5][20] = {"ROJO", "AMARILLO", "VERDE", "AZUL", "VERDE"};


	for(i=0; i<tamBici; i++)
	{
		listaBicicleta[i].id = idBici[i];
		strcpy(listaBicicleta[i].marca, marcaBici[i]);
		listaBicicleta[i].rodado = rodadoBici[i];
		strcpy(listaBicicleta[i].color, colorBici[i]);
		listaBicicleta[i].isEmpty = 1;
	}
}

int BuscarIdBicicleta(eBicicleta listaBici[], int tamBici, int buscarId)
{
	int retorno = -1;
	int i;

	if (listaBici != NULL && tamBici > 0 && buscarId >= 0)
	{
		for (i = 0; i < tamBici; i++)
		{
			if (listaBici[i].id == buscarId)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int MostrarTodasLasBicicletas(eBicicleta listaBici[], int tamBici)
{
	int i;
	int retorno = -1;

	printf("\t\t  MARCA      COLOR     RODADO \tID\n");
	for(i=0; i<tamBici; i++)
	{
		if(listaBici[i].isEmpty == 1)
		{
			printf("%2d. %20s %10s %10d %4d\n", i+1, listaBici[i].marca,
					listaBici[i].color, listaBici[i].rodado, listaBici[i].id);
			retorno = 1;
		}
	}
	return retorno;
}

int ObtenerIdBicicletaDelIndex(eBicicleta listaBici[], int tamBici, int* idServ)
{
	int index;
	int retorno = -1;

	if(utn_getEnteroSinReintentos(&index, "Ingrese una opción para elegir la bicicleta: ", "Opción inválida. ", 1, tamBici)==0)
	{
		while(listaBici[index-1].isEmpty != 1)
		{
			printf("Este servicio no existe\n");

			utn_getEnteroSinReintentos(&index, "Ingrese una opción (Solo de la lista): ", "Opción inválida. ", 1, tamBici);
		}
		*idServ = listaBici[index-1].id;
		retorno = 1;
	}
	return retorno;
}
