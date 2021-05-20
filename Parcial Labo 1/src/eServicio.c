/*
 * eServicio.c
 *
 *  Created on: 13 may. 2021
 *      Author: F2019
 */

#include "eServicio.h"

void MostrarTodosLosServicios(eServicio listaServicio[], int tamServ)
{
	int i;

	printf("     SERVICIO\t PRECIO    ID\n");

	for(i=0; i<tamServ; i++)
	{
		if(listaServicio[i].isEmpty == 1)
		{
		printf("%d. %10s %9.2f %8d\n", i+1, listaServicio[i].descripcion,
										listaServicio[i].precio, listaServicio[i].id);
		}
	}
}


int ObtenerIdServicioDelIndex(eServicio listaServicio[], int tamServ, int* idServ)
{
	int index;
	int retorno = -1;

	if(utn_getEnteroSinReintentos(&index, "Ingrese una opción para elegir el servicio: ", "Opción inválida. ", 1, tamServ)==0)
	{
		while(listaServicio[index-1].isEmpty != 1)
		{
			printf("Este servicio no existe\n");

			utn_getEnteroSinReintentos(&index, "Ingrese una opción (Solo de la lista): ", "Opción inválida. ", 1, tamServ);
		}
		*idServ = listaServicio[index-1].id;
		retorno = 1;
	}
	return retorno;
}

int BuscarIdServicio(eServicio listaServicio[], int tamSev, int buscarId)
{
	int i;
	int retorno = -1;

	for(i=0; i<tamSev; i++)
	{
		if(listaServicio[i].id == buscarId)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}

void harcodearServicios(eServicio listaServicio[], int tamServ)
{
	int i;
	int id[4] = {20000, 20001, 20002, 20003};
	char descripcion[4][50] = {"Limpieza", "Parche", "Centrado", "Cadena"};
	float precio[4] = {250, 300, 400, 350};

	for(i=0; i<tamServ; i++)
	{
		listaServicio[i].id = id[i];
		strcpy(listaServicio[i].descripcion, descripcion[i]);
		listaServicio[i].precio = precio[i];
		listaServicio[i].isEmpty = 1;

	}



}
