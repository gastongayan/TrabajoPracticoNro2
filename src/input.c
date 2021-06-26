/*
 * input.c
 *
 *  Created on: 8 may. 2021
 *      Author: gasto
 */



//Funcion que recibe el valor como parametro devolviendolo incrmentado en 1
#include "nexo.h"
#include <ctype.h>
int idAutonumerico = 0;

int get_Id(void){

	return idAutonumerico += 1;
}

int MenuABM(char* mensaje){
	int opcion;
	printf("----%s-----\n\n", mensaje);
	puts("1. Alta\n");
	puts("2. Baja\n");
	puts("3. Modificar\n");
	puts("4. Listar\n");
	puts("5. Ordenar\n");
	puts("6. Informe\n");
	puts("0. Salir\n");
	CargarUnEntero("Ingrese una opcion:",&opcion, 0, 6);

	return opcion;
}
int CargarUnFloat(char mensaje[], float* numFloat, int menor, int mayor){

	int rtn=-1;
	char numero[51];

	printf("%s",mensaje);
	scanf("%s", numero);
	*numFloat = atof(numero);
	rtn=0;




	return rtn;
}
int validar_numero(char numero[51]){
	int len;
	int i;
	int rtn=0;
	len=strlen(numero);
	for(i=0; i<len; i++)
	{
		if(!isdigit(numero[i]))
		{
			rtn=1;
			break;
		}
	}
	return rtn;
}
int CargarUnEntero(char mensaje[51], int* entero, int menor, int mayor)
{

	char numeroChar[51];
	int rtn=-1;
	int numeroInt;
	printf("%s: ",mensaje);
	fflush(stdin);
	scanf("%s",numeroChar);
	if(strlen(numeroChar)!=0)
	{
		if(!validar_numero(numeroChar))
		{
			numeroInt = atoi(numeroChar);
			if(!ValidarRango(&numeroInt, menor, mayor)==0)
			{
				*entero=numeroInt;
				rtn=0;
			}


		}
	}


	return rtn;
}


int ValidarRango(int* numero, int menor, int mayor){
	int contador;
	int rtn=1;
	contador=0;

	while(*numero<menor || *numero>mayor){
		printf("Error, ingrese datos entre %d y %d\n",menor, mayor);
		scanf("%d", numero);
		contador++;
		if(contador==3){

			printf("Demasiados intentos realizados\nEl dato no fue cargado\n");
			rtn=0;
			break;

		}



	}
	return rtn;
}
int validar_cadena(char cadena[51]){
	int rtn = 0;
	int i;
	int len;
	len = strlen(cadena);
	for(i=0; i<len; i++)
	{
		if(isalpha(cadena[i])==0)
		{
			rtn=1;
		}
	}
	return rtn;
}

int CargarUnaCadena(char mensaje[51], char* datoIngresado){
	int rtn = 0;
	char auxString[500];

	do{
		printf("%s:", mensaje);
		fflush(stdin);
		scanf("%s",auxString);
		mensaje = "Error, el mensaje supera los 50 caracteres";
	}while(strlen(auxString)>50 || strlen(auxString)==0);
	if(!validar_cadena(auxString)){
		strcpy(datoIngresado, auxString);
		rtn = 1;
	}

	return rtn;
}

