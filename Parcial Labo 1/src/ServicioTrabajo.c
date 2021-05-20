/*
 * ServicioTrabajo.c
 *
 *  Created on: 13 may. 2021
 *      Author: F2019
 */



#include "ServicioTrabajo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

eTrabajo eTrabajo_CargarDatos(eServicio listaServicio[], int tamServ, eBicicleta listaBici[], int tamBici)
{
	eTrabajo auxiliar;

	//utn_getTexto(auxiliar.marcaBicicleta, "Ingrese la marca de la bicicleta: ", "Error. ", sizeof(auxiliar.marcaBicicleta));
	//utn_getEnteroSinRango(&auxiliar.rodadoBicicleta, "Ingrese el rodado de la bicicleta: ", "Rodado inválido. ");
	utn_getFecha(&auxiliar.fecha.mes, &auxiliar.fecha.dia, &auxiliar.fecha.anio, 1900, 2021);
	MostrarTodosLosServicios(listaServicio, tamServ);
	ObtenerIdServicioDelIndex(listaServicio, tamServ, &auxiliar.idServicio);

	MostrarTodasLasBicicletas(listaBici, tamBici);
	ObtenerIdBicicletaDelIndex(listaBici, tamBici, &auxiliar.idBici);

	return auxiliar;
}


int eTrabajo_Alta(int* idTrabajo, eTrabajo listaTrabajo[], int TAM, eServicio listaSevicio[], int tamServ, eBicicleta listaBici[], int tamBici)
{
	int retorno = 0;
	char respuesta;
	eTrabajo auxTrabajo;
	int i;

	i = eTrabajo_ObtenerIndexLibre(listaTrabajo, TAM);
	if (i != -1)
	{
		auxTrabajo = eTrabajo_CargarDatos(listaSevicio, tamServ, listaBici, tamBici);
		auxTrabajo.id = *idTrabajo;
		*idTrabajo = *idTrabajo + 1;

		if(utn_getRespuestaSiNo(&respuesta, "¿Está seguro de dar de alta?", sizeof(respuesta)) == 1)
		{
			listaTrabajo[i] = auxTrabajo;
			listaTrabajo[i].isEmpty = OCUPADO;
			retorno = 1;
		}
		else
		{
			retorno = -1;
		}
	}

	return retorno;
}

eTrabajo eTrabajo_ModificarUno(eTrabajo Trabajo, eServicio listaServicio[], int tamServ)
{
	eTrabajo auxiliar = Trabajo;
	int opcionModif;

	do
	{
		opcionModif = MenuOpcionesModificar();
		switch(opcionModif)
		{
		case 0:
			printf("Saliendo");
		break;
		case 1:
			//utn_getTexto(auxiliar.marcaBicicleta, "Ingrese la marca de la bicicleta modificada: ",
			//		 	 "Error. ", sizeof(auxiliar.marcaBicicleta));
		break;
		case 2:
			MostrarTodosLosServicios(listaServicio, tamServ);
			ObtenerIdServicioDelIndex(listaServicio, tamServ, &auxiliar.idServicio);
		break;
		}
	}while(opcionModif != 0);

	return auxiliar;
}

int eTrabajo_Baja(eTrabajo listaTrabajo[], int tamTrab, eServicio listaServicio[], int tamServ, eBicicleta listaBici[], int tamBici)
{
	int retorno = 0;
	int idTrabajo;
	int i;
	char respuesta;

	eTrabajo_MostrarTodos(listaTrabajo, tamTrab, listaServicio, tamServ, listaBici, tamBici);

	for(i=0; i<tamTrab; i++)
	{
		if (listaTrabajo[i].isEmpty == OCUPADO)
		{
			printf("\nElija el trabajo a dar de baja.\n");

			utn_getEnteroPrositivo(&idTrabajo, "Ingrese el id del trabajo a dar de baja: ", "Error, ingrese un id válido. ");

			while (eTrabajo_BuscarPorID(listaTrabajo, tamTrab, idTrabajo) == -1)
			{
				printf("Ese id no existe.");
				utn_getEnteroPrositivo(&idTrabajo, "Ingrese el id a dar de baja: ", "Error, ingrese un id válido. ");
			}
			i = eTrabajo_BuscarPorID(listaTrabajo, tamTrab, idTrabajo);

			printf("Id ingresado: %d\n", idTrabajo);
			if(utn_getRespuestaSiNo(&respuesta, "¿Está seguro de dar de baja?", sizeof(respuesta)) == 1)
			{
				listaTrabajo[i].isEmpty = -1;
				retorno = 1;
				break;
			}
			else
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}

int eTrabajo_Modificacion(eTrabajo listaTrabajo[], int TAM, eServicio listaServicio[], int tamServ, eBicicleta listaBici[], int tamBici)
{
	int retorno = 0;
	int idTrabajo;
	char respuesta;
	eTrabajo auxiliar;
	int i;

	eTrabajo_MostrarTodos(listaTrabajo, TAM, listaServicio, tamServ, listaBici, tamBici);

	for(i=0; i<TAM; i++)
	{
		if (listaTrabajo[i].isEmpty == OCUPADO)
		{
			utn_getEnteroPrositivo(&idTrabajo, "Ingrese el id para modificar: ", "Id inválido. ");
			while (eTrabajo_BuscarPorID(listaTrabajo, TAM, idTrabajo) == -1)
			{
				printf("Ese id no existe.");
				utn_getEnteroPrositivo(&idTrabajo, "Ingrese el id para modificar: ", "Id inválido. ");
			}
			i = eTrabajo_BuscarPorID(listaTrabajo, TAM, idTrabajo);

			auxiliar = eTrabajo_ModificarUno(listaTrabajo[i], listaServicio, tamServ);

			if(utn_getRespuestaSiNo(&respuesta, "¿Está seguro de dar de baja?", sizeof(respuesta)) == 1)
			{
			listaTrabajo[i] = auxiliar;
			retorno = 1;
			break;
			}
			else
			{
				retorno = -1;
			}

		}
	}
	return retorno;
}

void eTrabajo_MostrarUno(eTrabajo Trabajo, eServicio miServicio, eBicicleta miBici)
{
	printf("%4d %15s %10d %9d/%d/%d %15s\n",
			Trabajo.id, miBici.marca,
			miBici.rodado,
			Trabajo.fecha.mes, Trabajo.fecha.dia, Trabajo.fecha.anio,
			miServicio.descripcion);
}

int eTrabajo_MostrarTodos(eTrabajo listaTrabajo[], int TAM, eServicio listaServicio[], int tamServicio, eBicicleta listaBici[],  int tamBici)
{
	int i;
	int j;
	int z;
	int retorno = 0;
	int cantidad = 0;

	if (listaTrabajo != NULL && TAM > 0)
	{
		printf("  ID\t       MARCA \t RODADO\t    FECHA(M/D/A)\tSERVICIO\n");
		for (i = 0; i < TAM; i++)
		{
			if (listaTrabajo[i].isEmpty == OCUPADO)
			{
				j = BuscarIdServicio(listaServicio, tamServicio, listaTrabajo[i].idServicio);
				z = BuscarIdBicicleta(listaBici, tamBici, listaTrabajo[i].idBici);
				if(j != -1 && z != -1)
				{
					eTrabajo_MostrarUno(listaTrabajo[i], listaServicio[j], listaBici[z]);
					cantidad++;
				}

			}
		}
	}
	if (cantidad > 0)
	{
		retorno = 1;
	}
	return retorno;
}


int CalcularTotalServicios(eTrabajo listaTrabajo[], int tamTrab, eServicio listaServicio[], int tamServ, float* acumulador)
{
	int retorno = -1;
	int i;
	int j;

	for(i=0; i<tamTrab; i++)
	{
		if(listaTrabajo[i].isEmpty == OCUPADO)
		{
			j = BuscarIdServicio(listaServicio, tamServ, listaTrabajo[i].idServicio);
			if(j != -1)
			{
				*acumulador = *acumulador + listaServicio[j].precio;
				retorno =  1;
			}
		}
	}
	return retorno;
}

int MenuOpcionesModificar(void)
{
	int opcion;
	printf("\n\tMENÚ MODIFICAR\n0. Salir\n 1. Marca\n 2. Servicio\n");
	utn_getEnteroSinReintentos(&opcion, "Ingrese una opcion: ", "Opción inválida. ", 0, 2);
	return opcion;
}

void OrdenarListaPorMarca(eTrabajo listaTrabajo[], int tamTrab, eBicicleta listaBici[], int tamBici)
{
	int i;
	int j;
	int z;
	eBicicleta aux;

	for (i =0; i < tamBici; i++)
	{
		for(j=i +1 ; j<tamBici; j++)
		{
			for(z=0; z<tamTrab; z++)
			{

				if (listaTrabajo[i].isEmpty == OCUPADO)
				{

					if (listaBici[i].id == listaTrabajo[z].idBici &&
						strcmp(listaBici[i].marca, listaBici[j].marca) > 0)
					{
						aux = listaBici[i];
						listaBici[i] = listaBici[j];
						listaBici[j] = aux;
					}
				}
			}
		}
	}
}

int BuscarElServicioConMasTrabajos(eServicio listaServ[], int tamServ, eTrabajo listaTrabajo[], int tamTrab)
{
	eAux auxiliar[tamServ];
	int trabajoMaximo = 0;
	int retorno = -1;

	aux_inicializar(auxiliar, listaServ, tamServ);

	if(aux_contar(auxiliar, listaServ, tamServ, listaTrabajo, tamTrab) == 1 &&
			buscarElMayor(auxiliar, listaServ, tamServ, &trabajoMaximo) == 1)

		{
			retorno = 1;
			inf_MostrarMaximo(trabajoMaximo, auxiliar, listaServ,tamServ , listaTrabajo, tamTrab);
		}



	return retorno;
}

void aux_inicializar(eAux aux[], eServicio listaServ[],int tamAux)
{
	int i;
	for(i=0; i<tamAux; i++)
	{
		aux[i].id = listaServ[i].id;
		aux[i].contador = 0;
		aux[i].isEmpty = 0;
	}
}

int aux_contar(eAux aux[], eServicio listaServ[], int tamAux, eTrabajo listaTrabajo[], int tamTrab)
{
	int i;
	int j;
	int retorno = -1;

	for(i=0; i<tamAux; i++)
	{
		for(j=0; j<tamTrab; j++)
		{
			if(aux[i].id ==  listaTrabajo[j].idServicio && listaTrabajo[j].isEmpty == 1)
			{
				aux[i].contador++;
				retorno = 1;
			}

		}
	}
	return retorno;
}

int buscarElMayor(eAux aux[], eServicio listaServ[], int tamAux, int* max)
{
	int i;
	int retorno = -1;

	for(i=0; i<tamAux; i++)
	{
		if((i == 0 || aux[i].contador > *max))
		{
			*max = aux[i].contador;
			retorno = 1;
		}
	}
	return retorno;
}

int inf_MostrarMaximo(int maximo, eAux aux[], eServicio listaServ[],int tamAux, eTrabajo listaTrab[], int tamTrab)
{
	int i;
	int j;
	for(i=0; i<tamAux; i++)
	{
		if(aux[i].contador == maximo)
		{
			for(j=0; j<tamTrab; j++)
			{
				if(aux[i].id == listaServ[j].id && listaTrab[j].isEmpty == 1)
				{
					printf("El servicio que más trabajos realizó es: %s con %d trabajo(s)\n", listaServ[j].descripcion, aux[i].contador);
					break;
				}
			}
		}
	}
	return 0;
}

int CantidadBicicletasRojas(eBicicleta listaBici[], int tamBici, eTrabajo listaTrabajo[], int tamTrab)
{
	int i;
	int j;
	int retorno = -1;
	int contar = 0;

	for(i=0; i<tamBici; i++)
	{
		for(j=0; j<tamTrab; j++)
		{
			if(listaTrabajo[i].isEmpty == 1)
			{
				if(listaBici[i].id == listaTrabajo[j].idBici && strcmp(listaBici[i].color, "ROJO") == 0)
				{
					contar++;
					retorno = contar;
				}
			}
		}
	}
	return retorno;
}

int ListarSeviciosConBicicletas(eBicicleta listaBici[], int tamBici, eTrabajo listaTrabajo[], int tamTrab, eServicio listaServ[],int tamServ)
{
	int i;
	int j;
	int z;
	int retorno = -1;

	for(i=0; i<tamServ; i++)
	{
		if(listaServ[i].isEmpty == 1)
		{
			printf("%s\n", listaServ[i].descripcion);
		}

		for(j=0; j<tamTrab; j++)
		{
			if(listaTrabajo[j].isEmpty == 1)
			{
				for(z=0; z<tamBici; z++)
				{
					if(listaTrabajo[j].idBici == listaBici[z].id && listaServ[i].id == listaTrabajo[j].idServicio)
					{
						printf(" -%s\n", listaBici[z].marca);
						retorno = 1;
					}
				}
			}
		}
	}

	return retorno;
}
