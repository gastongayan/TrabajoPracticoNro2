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
	eEmpleados lista[T];
	int opc;
	int id=0;
	int pId;
	pId=&id;
	int altas;
	int  bajas;
	int modif;

	altas=0;
	bajas=0;
	modif=0;
	setbuf(stdout,NULL);
	if(InicializarEmpleados(lista, T)){
		do{
			opc=MenuABM();
			switch(opc){

			case 1:
				printf("Alta\n");
				if(AltaEmpleados(lista, T, pId)){
					altas++;
				}
				break;

			case 2:
				printf("Baja\n");
				if(altas!=0){
					if(BajaEmpleados(lista, T)){
						bajas++;
					}
				}else{
					printf("Debe ingresar un alta para poder dar de baja\n");
				}
				break;

			case 3:
				printf("Modificacion\n");
				if(altas!=0){
					if(ModificacionEmpleados(lista, T)){
						modif++;
					}
				}else{
					printf("Debe ingresar un alta para poder dar de baja\n");
				}
				break;

			case 4:
				printf("Listados\n");
				if(OrdenarEmpleados(lista, T)){
					ListarEmpleados(lista, T);
					PromedioEmpleados(lista, T);
				}
				break;

			case 5:
				printf("Ordenar\n");
				break;

			}
		}while(opc!=5);
	}
}
