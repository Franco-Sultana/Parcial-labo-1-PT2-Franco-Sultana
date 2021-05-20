/*
 ============================================================================
 	 	 	 Franco Sultana 		Div: "B"
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//#include "eTrabajo.h"
#include "ServicioTrabajo.h"



int main(void)
{
	setbuf(stdout, NULL);
	int idIncremental = 0;
	int opcionMenu;
	float totalServicios = 0;
	char respuestaSalir;
	int contadorRojas;

	eServicio listaServicio[TAM_SERVICIO];
	eTrabajo listaTrabajos[TAM_TRABAJO];
	eBicicleta listaBicicleta[TAM_BICI];

	HarcodearBicicletas(listaBicicleta, TAM_BICI);
	harcodearServicios(listaServicio, TAM_SERVICIO);
	eTrabajo_Inicializar(listaTrabajos, TAM_TRABAJO);

	do
	{
		opcionMenu = MenuOpcionesTrabajo();
		switch(opcionMenu)
		{
		case 0:
			if(utn_getRespuestaSiNo(&respuestaSalir, "¿Está seguro de salir?", sizeof(respuestaSalir)) == 1)
			{
				printf("\n\t\tSaliendo.");
				opcionMenu = -1;
			}
		break;
		case 1:
			switch(eTrabajo_Alta(&idIncremental, listaTrabajos,  TAM_TRABAJO, listaServicio, TAM_SERVICIO, listaBicicleta, TAM_BICI))
			{
				case 1:
					printf("Trabajo ingresado con éxito\n");
				break;
				case -1:
					printf("X Alta cancelada\n");
				break;
				case 0:
					printf("No hay espacio para cargar mas trabajos\n");
				break;
			}
		break;
		case 2:
			switch(eTrabajo_Modificacion(listaTrabajos, TAM_TRABAJO, listaServicio, TAM_SERVICIO, listaBicicleta, TAM_BICI))
			{
				case 1:
					printf("Trabajo modificado  con éxito\n");
				break;
				case -1:
					printf("X Modificacion cancelada\n");
				break;
				case 0:
					printf("Aun no hay trabajos dados de alta\n");
				break;
			}
		break;
		case 3:
			switch(eTrabajo_Baja(listaTrabajos, TAM_TRABAJO, listaServicio, TAM_SERVICIO, listaBicicleta, TAM_BICI))
			{
				case 1:
					printf("Gen dado de baja con éxito\n");
				break;
				case -1:
					printf("X Baja cancelada\n");
				break;
				case 0:
					printf("Aun no hay Gen dados de alta\n");
				break;
			}
		break;
		case 4:
			OrdenarLista(listaTrabajos, TAM_TRABAJO);
			if(eTrabajo_MostrarTodos(listaTrabajos, TAM_TRABAJO, listaServicio, TAM_SERVICIO, listaBicicleta, TAM_BICI) != 1)
			{
				printf("Debe cargar al menos 1 trabajo\n");
			}
		break;
		case 5:
			MostrarTodosLosServicios(listaServicio, TAM_SERVICIO);
		break;
		case 6:
			if(CalcularTotalServicios(listaTrabajos, TAM_TRABAJO, listaServicio, TAM_SERVICIO, &totalServicios) == 1)
			{
				printf("Total: %.2f\n", totalServicios);
			}
			else
			{
				printf("Debe haber cargado al menos un trabajo para calcular el total\n");
			}

		break;
		case 7:
			OrdenarListaPorMarca(listaTrabajos, TAM_TRABAJO, listaBicicleta, TAM_BICI);
			if(eTrabajo_MostrarTodos(listaTrabajos, TAM_TRABAJO, listaServicio, TAM_SERVICIO, listaBicicleta, TAM_BICI) != 1)
			{
				printf("Debe cargar al menos 1 trabajo\n");
			}
		break;
		case 8:
			if(BuscarElServicioConMasTrabajos(listaServicio, TAM_SERVICIO, listaTrabajos, TAM_TRABAJO) != 1)
			{
				printf("No hay trabajos dados de alta");
			}

		break;
		case 9:
			if(ListarSeviciosConBicicletas(listaBicicleta, TAM_BICI, listaTrabajos, TAM_TRABAJO, listaServicio, TAM_SERVICIO) != 1)
			{
				printf("No se ingresaron trabajos.");
			}

		break;
		case 10:
			contadorRojas = CantidadBicicletasRojas(listaBicicleta, TAM_BICI, listaTrabajos, TAM_TRABAJO);
			if(contadorRojas > 0)
			{
				printf("La cantidad de bicicletas rojas es: %d", contadorRojas);
			}
			else
			{
				printf("No hay bicicletas rojas");
			}

		break;
		}


	}while(opcionMenu != -1);

	return EXIT_SUCCESS;
}
