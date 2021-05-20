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

/**
 * @fn void HarcodearBicicletas(eBicicleta[], int)
 * @brief harcodea el array de bicicletas
 *
 * @param listaBicicleta array de bicicletas
 * @param tamBici tamaño del array de bicicletas
 */
void HarcodearBicicletas(eBicicleta listaBicicleta[], int tamBici);

/**
 * @fn int BuscarIdBicicleta(eBicicleta[], int, int)
 * @brief busca y compara el id de bicicleta con el id que se le pase por "buscarId"
 *
 * @param listaBici array de bicicletas
 * @param tamBici tamaño del array de bicicletas
 * @param buscarId id que se le pasa par abuscar
 * @return la posicion de bicicleta si el id coincide, -1 si no
 */
int BuscarIdBicicleta(eBicicleta listaBici[], int tamBici, int buscarId);

/**
 * @fn int MostrarTodasLasBicicletas(eBicicleta[], int)
 * @brief muestra el array de bicicletas
 *
 * @param listaBici array de bicicletas
 * @param tamBici tamaño de bicicletas
 * @return 1 si pudo miostrar, -1 si no
 */
int MostrarTodasLasBicicletas(eBicicleta listaBici[], int tamBici);

/**
 * @fn int ObtenerIdBicicletaDelIndex(eBicicleta[], int, int*)
 * @brief obtiene el indice a traves de la opcion que eligio el usuario
 *
 * @param listaBici array de bicicletas
 * @param tamBici tamaño de biccletas
 * @param idServ id a buscar en la pocisio
 * @return 1 si lo encontró, -1 si no
 */
int ObtenerIdBicicletaDelIndex(eBicicleta listaBici[], int tamBici, int* idServ);


#endif /* EBICICLETA_H_ */
