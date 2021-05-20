/*
 * eTrabajo.h
 *
 *  Created on: 13 may. 2021
 *      Author: F2019
 */

#ifndef ETRABAJO_H_
#define ETRABAJO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN.h"

#define OCUPADO 1
#define VACIO 0


typedef struct
{
	int mes;
	int dia;
	int anio;
}eFecha;

typedef struct
{
	int id;
	//char marcaBicicleta[50];
	//int rodadoBicicleta;
	int idBici;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eTrabajo;


/**
 * @fn int MenuOpcionesTrabajo(void)
 * @brief Muestra el menu de opciones al usuario y pide el ingreso de una opcion
 *
 * @return la opcion que eligió el usuario, una vez validad por la funcion de utn
 */
int MenuOpcionesTrabajo(void);

/**
 * @fn void eTrabajo_Inicializar(eTrabajo[], int)
 * @brief Inicializa el array de trabajo en vacio
 *
 * @param array array de trabajo
 * @param TAM  tamaño de array de trabajo
 */
void eTrabajo_Inicializar(eTrabajo array[], int TAM);

/**
 * @fn int eTrabajo_ObtenerIndexLibre(eTrabajo[], int)
 * @brief recorre el array de trabajo para encontrar espacio disponible
 *
 * @param array array de trabajo
 * @param TAM tamaño de array de trabajo
 * @return retorna 1 si obtuvo la posicion libre, -1 si no
 */
int eTrabajo_ObtenerIndexLibre(eTrabajo array[], int TAM);

/**
 * @fn int eTrabajo_BuscarPorID(eTrabajo[], int, int)
 * @brief realiza una busqueda por id
 *
 * @param array array de trabajo
 * @param TAM tamaño de array de trabajo
 * @param ID id a buscar
 * @return -1 si no encontro el id. La pocision del array donde está el id si lo encontró
 */
int eTrabajo_BuscarPorID(eTrabajo array[], int TAM, int ID);


/**
 * @fn int OrdenarLista(eTrabajo[], int)
 * @brief Ordena por año o descripcion
 *
 * @param listaTrabajo array de trabajo
 * @param tamTrab tamaño de array de trabajo
 */
void OrdenarLista(eTrabajo listaTrabajo[], int tamTrab);


#endif /* ETRABAJO_H_ */
