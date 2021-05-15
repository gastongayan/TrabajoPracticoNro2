/*
 * input.c
 *
 *  Created on: 8 may. 2021
 *      Author: gasto
 */



//Funcion que recibe el valor como parametro devolviendolo incrmentado en 1
#include "nexo.h"


int incrementarId(int* id){
	(*id)++;
	return id;
}

int MenuABM(){
	int opcion;
	puts("Empleados\n\n");
	puts("1. Alta\n");
	puts("2. Baja\n");
	puts("3. Modificar\n");
	puts("4. Listar\n");
	puts("0. Salir");
	opcion=CargarUnEntero("Ingrese una opcion:", 0, 4);
	return opcion;
}
float CargarUnFloat(char mensaje[]){
	float numero;
	do{
		printf("%s: ",mensaje);
		scanf("%f",&numero);
	}while(numero<0);

	return numero;
}
int CargarUnEntero(char mensaje[], int menor, int mayor){
	int numero;
	printf("%s: ",mensaje);
	scanf("%d",&numero);
	numero=ValidarRango(numero, menor, mayor);
	return numero;
}

/*int BuscarIdMayor(eServicios servicio[], int tamServicio){
	int i;
	int mayor;
	mayor=0;
	for(i=0; i<tamServicio; i++){
		if(servicio[i].idServicio>mayor){
			mayor=servicio[i].idServicio;
		}
	}
	return mayor;
}
int BuscarIdMenor(eServicios servicio[], int tamServicio){
	int i;
	int menor;
	menor=0;
	for(i=0; i<tamServicio; i++){
		if(servicio[i].idServicio<menor || menor==0){
			menor=servicio[i].idServicio;
		}
	}
	return menor;
}*/
int ValidarRango(int numero, int menor, int mayor){
	int contador;
	contador=0;
	while(numero<menor || numero>mayor){
		printf("Error, ingrese datos entre %d y %d\n",menor, mayor);
		scanf("%d",&numero);
		contador++;
		if(contador==3){
			printf("Demasiados intentos realizados\nEl dato no fue cargado\n");
			return 0;
			break;
		}
	}
	return numero;
}


void CargarUnaCadena(char mensaje[], char* datoIngresado){

	char auxString[500];

	do{
		printf("%s:", mensaje);
		fflush(stdin);
		scanf("%s",auxString);
	}while(strlen(auxString)>50 || strlen(auxString)==0);
	strcpy(datoIngresado, auxString);

}

