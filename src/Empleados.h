/*
 * Empleados.h
 *
 *  Created on: 14 may. 2021
 *      Author: gasto
 */

#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_

typedef struct{
	int idEmpleado;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int isEmpty;
}eEmpleados;
#include "input.h"


int InicializarEmpleados(eEmpleados[], int);
int BuscarLibreEmpleados(eEmpleados[], int);
int AltaEmpleados(eEmpleados[], int, int*);
int BajaEmpleados(eEmpleados[], int);
int ListarEmpleados(eEmpleados[], int);
int OrdenarEmpleados(eEmpleados[], int);
int BuscarEmpleado(eEmpleados[], int);
int ListarEmpleados(eEmpleados[], int);
void MostrarEmpleado(eEmpleados);
int ModificacionEmpleados(eEmpleados[], int);
int PromedioEmpleados(eEmpleados[], int);
#endif /* EMPLEADOS_H_ */
