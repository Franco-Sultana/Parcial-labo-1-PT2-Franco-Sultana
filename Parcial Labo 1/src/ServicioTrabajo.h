/*
 * ServicioTrabajo.h
 *
 *  Created on: 13 may. 2021
 *      Author: F2019
 */

#ifndef SERVICIOTRABAJO_H_
#define SERVICIOTRABAJO_H_
#define TAM_TRABAJO 1000
#define TAM_BICI 5
#define TAM_SERVICIO 4
#include "eServicio.h"
#include "eTrabajo.h"
#include "eBicicleta.h"


#include "UTN.h"

typedef struct
{
	int id;
	int contador;
	int isEmpty;
}eAux;

/**
 * @fn eTrabajo eTrabajo_CargarDatos(eServicio, int)
 * @brief Pide datos al usuario
 *
 * @param listaServicio array de servicios
 * @param tamServ tamaño del array
 * @return el auxiliar con los datos cargados
 */
eTrabajo eTrabajo_CargarDatos(eServicio listaServicio[], int tamServ, eBicicleta listaBici[], int tamBici);

/**
 * @fn int eTrabajo_Alta(int*, eTrabajo[], int)
 * @brief da de alta el auxiliar cargado en la funcion eTrabajo_CargarDatos(eServicio, int)
 *
 * @param idTrabajo id  autoincremental
 * @param array array de trabajo
 * @param TAM tamaño del array trabajo
 * @return
 */
int eTrabajo_Alta(int* idTrabajo, eTrabajo listaTrabajo[], int TAM, eServicio listaSevicio[],
					int tamServ, eBicicleta listaBici[], int tamBici);



/**
 * @fn eTrabajo eGen_ModificarUno(eTrabajo)
 * @brief Carga el auxiliar con datos que ingresa el usuario
 *
 * @param Gen auxilair de tipo eTrabajo
 * @return el auxiliar cargado
 */
eTrabajo eTrabajo_ModificarUno(eTrabajo Trabajo, eServicio listaServicio[], int tamServ);

/**
 * @fn int eTrabajo_Baja(eTrabajo[], int)
 * @brief Pide un id al usuario para dar de baja
 *
 * @param array array de trabajo
 * @param TAM tamaño de array de trabajo
 * @return 0 si no se dieron  de alta trabajos / 1 si pudo dar de alta / -1 si el usuario se arrepiente
 */
int eTrabajo_Baja(eTrabajo listaTrabajo[], int tamTrab, eServicio listaServicio[], int tamServ, eBicicleta listaBici[], int tamBici);

/**
 * @fn int eTrabajo_Modificacion(eTrabajo[], int)
 * @brief aplica los cambios, si el usuario acepta, al array de trabajos, con el auxiliar que se obtieene en
 * 			la funcion eTrabajo eGen_ModificarUno(eTrabajo Gen);
 *
 * @param array array de trabajo
 * @param TAM tamaño del array de trabajo
 * @return
 */
int eTrabajo_Modificacion(eTrabajo array[], int TAM, eServicio listaServicio[], int tamServ, eBicicleta listaBici[], int tamBici);

/**
 * @fn void eTrabajo_MostrarUno(eTrabajo, eServicio)
 * @brief Muestra un trabajo
 *
 * @param Trabajo trabajo que se va a mostrar
 * @param miServicio servicio que se va a mostrar
 */
void eTrabajo_MostrarUno(eTrabajo Trabajo, eServicio miServicio, eBicicleta miBici);

/**
 * @fn int eTrabajo_MostrarTodos(eTrabajo[], int, eServicio[], int)
 * @brief Muestra la lista de los trabajos
 *
 * @param array array de trabajos
 * @param TAM tamaño del array de trabajos
 * @param listaServicio array de servicios
 * @param tamServicio tamaño array de servicios
 * @return 1 si pudo mostrar / 0 si no
 */
int eTrabajo_MostrarTodos(eTrabajo listaTrabajo[], int TAM, eServicio listaServicio[], int tamServicio, eBicicleta listaBici[],  int tamBici);

/**
 * @fn int CalcularTotalServicios(eTrabajo[], int, eServicio[], int, float*)
 * @brief calcula el total por sevicios prestados
 *
 * @param listaTrabajo array de trabajos
 * @param tamTrab tamaño del array de trabajos
 * @param listaServicio array de servicios
 * @param tamServ tamaño array de servicios
 * @param acumulador puntero a espacio de memoria donde se va a copiar el acumulador
 * @return
 */
int CalcularTotalServicios(eTrabajo listaTrabajo[], int tamTrab, eServicio listaServicio[], int tamServ, float* acumulador);

/**
 * @fn int MenuOpcionesModificar(void)
 * @brief Muestra el menu de modificacion y pide al usuario que ingrese una opcion
 *
 * @return retorna la opció que ingreso el usuario
 */
int MenuOpcionesModificar(void);

/**
 * @fn void OrdenarListaPorMarca(eTrabajo[], int, eBicicleta[], int)
 * @brief Ordena la lista por marca de bicicletas
 *
 * @param listaTrabajo array de trabajos
 * @param tamTrab tamaño del array de trabajos
 * @param listaBici array de bicicletas
 * @param tamBici tamaño del array de bicicletas
 */
void OrdenarListaPorMarca(eTrabajo listaTrabajo[], int tamTrab, eBicicleta listaBici[], int tamBici);

/**
 * @fn int BuscarElServicioConMasTrabajos(eServicio[], int, eTrabajo[], int)
 * @brief Busca el servicio que más trabajos realizó
 *
 * @param listaServ array de servicios
 * @param tamServ tamaño del array de servicios
 * @param listaTrabajo array del array de trabajos
 * @param tamTrab tamaño del array e trabajos
 * @return 1 si pudo encontrarlo, -1 si no
 */
int BuscarElServicioConMasTrabajos(eServicio listaServ[], int tamServ, eTrabajo listaTrabajo[], int tamTrab);

/**
 * @fn void aux_inicializar(eAux[], eServicio[], int)
 * @brief Inicializa la estructura de auxiliar
 *
 * @param aux array de auxiliar
 * @param listaServ array de servicios
 * @param tamAux tamaño de servicios, que es el mismo que el de aux
 */
void aux_inicializar(eAux aux[], eServicio listaServ[],int tamAux);

/**
 * @fn int aux_contar(eAux[], eServicio[], int, eTrabajo[], int)
 * @brief Cuenta la cantidad de trabajos por servicios
 *
 * @param aux array de auxiliar
 * @param listaServ array de servicios
 * @param tamAux tamaño de servicios, que es el mismo que el de aux
 * @param listaTrabajo array de trabajos
 * @param tamTrab tamaño del array de trabajos
 * @return 1 si pudo contar, -1 si no
 */
int aux_contar(eAux aux[], eServicio listaServ[], int tamAux, eTrabajo listaTrabajo[], int tamTrab);

/**
 * @fn int buscarElMayor(eAux[], eServicio[], int, int*)
 * @brief Busca el mayor
 *
 * @param aux array de auxiliar
 * @param listaServ array de servicios
 * @param tamAux tamaño de servicios, que es el mismo que el de aux
 * @param max puntero a direeccion de memoria donde se va a copiar el maximo
 * @return 1 si pudo encontrar el maximo, -1 si no
 */
int buscarElMayor(eAux aux[], eServicio listaServ[], int tamAux, int* max);

/**
 * @fn int inf_MostrarMaximo(int, eAux[], eServicio[], int, eTrabajo[], int)
 * @brief Busca si hay otros servicios con el mismo num de trabajos que el maximo, y los muestra
 *
 * @param maximo el numero maximo
 * @param aux array de auxilair
 * @param listaServ array de servicios
 * @param tamAux tamaño de servicios, que es el mismo que el de aux
 * @param listaTrab array de trabajos
 * @param tamTrab tamaño del array de trabajos
 * @return 1 si pudo mostrar, -1 si no
 */int inf_MostrarMaximo(int maximo, eAux aux[], eServicio listaServ[],int tamAux, eTrabajo listaTrab[], int tamTrab);

/**
 * @fn int CantidadBicicletasRojas(eBicicleta[], int, eTrabajo[], int)
 * @brief cuenta cuantas bicicletas rojas hay
 *
 * @param listaBici array de bicicletas
 * @param tamBici tamaño del array de bicicletas
 * @param listaTrabajo array de trabajo
 * @param tamTrab tamaño del array de trabajo
 * @return 1 si pudo contar, -1 si no
 */
int CantidadBicicletasRojas(eBicicleta listaBici[], int tamBici, eTrabajo listaTrabajo[], int tamTrab);

/**
 * @fn int ListarSeviciosConBicicletas(eBicicleta[], int, eTrabajo[], int, eServicio[], int)
 * @brief lista los servicios con los trabajos que se realizaron con ellos
 *
 * @param listaBici array de bicicletas
 * @param tamBici tamaño de array de bicicletas
 * @param listaTrabajo array de trabajo
 * @param tamTrab tamaño de array de trabajo
 * @param listaServ array de servicios
 * @param tamServ tamaño del array de sevicios
 * @return 1 si pudo mostrar, -1 si no
 */
int ListarSeviciosConBicicletas(eBicicleta listaBici[], int tamBici, eTrabajo listaTrabajo[],
									int tamTrab, eServicio listaServ[],int tamServ);

#endif /* SERVICIOTRABAJO_H_ */
