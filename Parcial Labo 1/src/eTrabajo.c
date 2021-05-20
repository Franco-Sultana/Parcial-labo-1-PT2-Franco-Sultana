/*
 * eTrabajo.c
 *
 *  Created on: 13 may. 2021
 *      Author: F2019
 */

#include "eTrabajo.h"

int MenuOpcionesTrabajo(void)
{
	int opcion;
	printf("\n\tMENU PRINCIPAL\n -0. Salir\n -1. Alta\n -2. Modificación\n "
			"-3. Baja\n -4. Mostrar trabajos\n -5. Mostrar servicios\n "
			"-6. Calcular total por servicios prestados\n "
			"-7. Lista ordenada por marca de bicicleta\n "
			"-8. Servicios que mas trabajos realizaron\n "
			"-9. Listado de servicios con bicicletas que lo realizaron\n "
			"-10. Cantidad de bicicletas rojas\n ");
	utn_getEnteroSinReintentos(&opcion, "Ingrese una opcion: ", "Opcion inválida. ", 0, 11);
	return opcion;
}

void eTrabajo_Inicializar(eTrabajo listaTrabajo[], int tamTrab)
{
	int i;

	if (listaTrabajo != NULL && tamTrab > 0)
	{
		for (i = 0; i < tamTrab; i++)
		{
			listaTrabajo[i].isEmpty = 0;
		}
	}
}

int eTrabajo_ObtenerIndexLibre(eTrabajo listaTrabajo[], int tamTrab)
{
	int rtn = -1;
	int i;

	if (listaTrabajo != NULL && tamTrab > 0) {

		for (i = 0; i < tamTrab; i++) {

			if (listaTrabajo[i].isEmpty == 0)
			{
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}


int eTrabajo_BuscarPorID(eTrabajo listaTrabajo[], int tamTrab, int ID)
{
	int retorno = -1;
	int i;

	if (listaTrabajo != NULL && tamTrab > 0 && ID >= 0)
	{
		for (i = 0; i < tamTrab; i++)
		{
			if (listaTrabajo[i].id == ID && listaTrabajo[i].isEmpty == OCUPADO)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

void OrdenarLista(eTrabajo listaTrabajo[], int tamTrab)
{
	int i;
	int j;
	eTrabajo aux;

	for (i = 0; i < tamTrab - 1; i++)
	{
		for (j = i + 1; j < tamTrab; j++)
		{

			if (listaTrabajo[i].isEmpty == OCUPADO
					&& listaTrabajo[j].isEmpty == OCUPADO)
			{

				if (listaTrabajo[i].fecha.anio > listaTrabajo[j].fecha.anio)
				{

					aux = listaTrabajo[i];
					listaTrabajo[i] = listaTrabajo[j];
					listaTrabajo[j] = aux;
				}
				/*else
				{
					if (strcmp(listaTrabajo[i].marcaBicicleta, listaTrabajo[j].marcaBicicleta) > 0)
					{

						aux = listaTrabajo[i];
						listaTrabajo[i] = listaTrabajo[j];
						listaTrabajo[j] = aux;
					}
				}*/
			}
		}
	}
}


