/*
 * eServicio.h
 *
 *  Created on: 13 may. 2021
 *      Author: F2019
 */

#ifndef ESERVICIO_H_
#define ESERVICIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN.h"


typedef struct
{
	int id;
	char descripcion[50];
	float precio;
	int isEmpty;
}eServicio;



/**
 * @fn int MostrarTodosLosServicios(eServicio[], int)
 * @brief Muestra la lista de servicios disponible
 *
 * @param listaServicio Array de servicios
 * @param tamServ tamaño del array
 */
void MostrarTodosLosServicios(eServicio listaServicio[], int tamServ);

/**
 * @fn int ObtenerIdTipoDelIndex(eServicio[], int, int*)
 * @brief Obtiene el id a partir de la opcion que elija el usuario
 *
 * @param listaServicio  Array de servicios
 * @param tamServ tamaño del array
 * @param idServ puntero a dirteccion de memoria donde se va a copiar el id
 * @return -1 si no pudo obtener el id, 1 si si
 */
int ObtenerIdServicioDelIndex(eServicio listaServicio[], int tamServ, int* idServ);

/**
 * @fn int BuscarIdServicio(eServicio[], int, int)
 * @brief pregunta si el id de lista servicio en pocision i es igual a un id que se le pase. Si es así, devuelve el indice
 *
 * @param listaServicio array de servicio
 * @param tamServ tamaño del array
 * @param buscarId id que se le pasa para buscar
 * @return -1 si el id de servicio no coincide con el id que le pasaron, la posicion del servicio si pudo encontrar el id
 */
int BuscarIdServicio(eServicio listaServicio[], int tamServ, int buscarId);

/**
 * @fn void harcodearServicios(eServicio[], int)
 * @brief harcodea el aray de servicios
 *
 * @param listaServicio array de servicios
 * @param tamServ tamaño del array
 */
void harcodearServicios(eServicio listaServicio[], int tamServ);

#endif /* ESERVICIO_H_ */
