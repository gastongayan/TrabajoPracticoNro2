/*
 ============================================================================
 Name        : TrabajoPracticoNro2.c
 Author      : Gaston A. Gayan
 Version     :
 Copyright   : 1 F
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "nexo.h"

#define T 1000

int main(void) {
	Employee list[T];

	int opc;
	int orden;
	int id;

	setbuf(stdout,NULL);
	initEmployees(list, T);
	do{
		opc=MenuABM("EMPLEADOS");
		if(opc!=-1)
		{
			switch(opc){

			case 1:
				printf("Alta\n");

				if(dataChargeEmployee(list, T)==1){

					printf("Dato guardado con exito\n");

				}else{

					printf("Error en carga de datos\n");
				}

				break;

			case 2:
				printf("Baja\n");

				if(contadorEmpleados(list, T)>0){

					if(controllerRemoveEmployee(list, T)){

						printf("Dato eliminado con exito\n");

					}else{

						printf("Error en borrado de datos\n");

					}

				}else{
					printf("No hay datos cargados\n");
				}

				break;

			case 3:
				printf("Modificacion\n");

				if(contadorEmpleados(list, T)!=0){

					if(!CargarUnEntero("Ingrese id del emplado a modificar",&id, 0, buscarIdMayor(list, T)))
					{
						if(editEmployee(list, T, id)){
							printf("Datos guardados con exito");
						}
					}

				}else{
					printf("Debe ingresar un empleado para poder modificar\n");
				}
				break;

			case 4:
				if(contadorEmpleados(list, T)>0){
					printf("Listados\n");

					if(!printEmployees(list, T))
					{
						printf("Error al imprimir datos\n");
					}
				}else{

					printf("No hay datos cargados\n");
				}


				break;

			case 5:
				printf("Ordenar\n");

				if(contadorEmpleados(list, T)>0){

					if(!CargarUnEntero("Ingrese criterio de ordenacion ((1 = Ascendente) (0 = Descendente))",&orden,0,1))
					{
						if(sortEmployees(list, T, orden))
						{
							printf("Error al ordenar datos\n");
						}

					}
				}else{
					printf("No hay datos cargados\n");
				}
				break;

			case 6:
				printf("Informe\n");

				if(contadorEmpleados(list, T)>0){

					printf("Suma total de salarios: %d\n",sumaSueldosEmpleados(list, T));
					printf("Promedio total de salarios: %.2f\n",promedioSueldoEmpleados(list, T));
					printf("Cantidad total de empleados que superan el salario promedio: %d\n",salarioMayorPromedio(list, T));

				}else{
					printf("No hay datos cargados\n");
				}
				break;

			case 0:

				printf("---SALIDA---\nPROGRAMA TERMINADO");
				break;
			}
		}

	}while(opc!=0);

}
