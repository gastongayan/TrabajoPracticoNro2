
#include "nexo.h"
#define VACIO 0
#define OCUPADO 1



int InicializarEmpleados(eEmpleados lista[], int tam){
	int i;
	int rtn;
	rtn=0;
	for(i=0; i<tam; i++){
		lista[i].isEmpty=VACIO;
		rtn=1;
	}
	return rtn;
}

int BuscarLibreEmpleados(eEmpleados lista[], int tam){
	int i;
	int index;
	index=-1;
	for(i=0; i<tam; i++){
		if(lista[i].isEmpty==VACIO){
			index=i;
			break;
		}
	}
	return index;
}

int AltaEmpleados(eEmpleados lista[], int tam, int* id){
	int index;
	int rtn;
	index=BuscarLibreEmpleados(lista, tam);
	if(index!=-1){

		(*id)++;
		lista[index].idEmpleado=(*id);
		CargarUnaCadena("Ingrese nombre", lista[index].nombre);
		CargarUnaCadena("Ingrese apellido", lista[index].apellido);
		lista[index].salario=CargarUnFloat("Ingrese salario");
		lista[index].sector=CargarUnEntero("Ingrese numero de sector (0-10)", 0, 10);
		lista[index].isEmpty=OCUPADO;
		rtn = 1;
	}else{
		printf("Usted no dispone de lugar para añadir un nuevo empleado");
		rtn = 0;
	}
	return rtn;


}
int ModificacionEmpleados(eEmpleados lista[], int tam){
	eEmpleados auxiliar;
	int index;
	int opcion;
	int bandera=0;
	ListarEmpleados(lista, tam);
	index=BuscarEmpleado(lista, tam);
	if(index!=-1){
		do{
			auxiliar=lista[index];
			opcion=CargarUnEntero("Que desea modificar? \n1-Nombre\n2-Apellido\n3-Salario \n4-Sector \n0- Salir",0,4);
			switch(opcion){
			case 1:
				CargarUnaCadena("Ingrese nombre:\n", auxiliar.nombre);
				bandera=1;
				break;
			case 2:
				CargarUnaCadena("Ingrese apellido:\n", auxiliar.apellido);
				bandera=1;
				break;

			case 3:
				auxiliar.salario=CargarUnFloat("Ingrese salario:");
				bandera=1;
				break;

			case 4:
				auxiliar.sector=CargarUnEntero("Ingrese numero de sector (1-10):", 1, 10);
				bandera=1;
				break;

			case 0:
				if(bandera==1){
					if(CargarUnEntero("Desea guardar los cambios? 1 = SI   0 = NO", 0, 1)){
						lista[index]=auxiliar;
						printf("Datos guardados con exito");

					}
				}else{
					printf("Datos no guardados");

				}

				break;
			}
		}while(opcion!=0);
	}
	return bandera;


}
int BajaEmpleados(eEmpleados lista[], int tam){
	int rtn;
	rtn=0;
	int index;
	int mensaje=0;

	if(ListarEmpleados(lista,tam)){
		index = BuscarEmpleado(lista, tam);
		if(index!=-1){
			mensaje=CargarUnEntero("Desea eliminar el dato? (1 = SI  0 = NO)", 0, 1);
		}
		if(mensaje==1){
			lista[index].isEmpty=VACIO;
			printf("Dato eliminado con exito! \n");
			rtn=1;
		}else{
				printf("Baja cancelada! \n");

		}
	}else{
		printf("No hay empleados cargados");
	}

	return rtn;
}
int ListarEmpleados(eEmpleados lista[], int tam){
	int i;
	int rtn=0;
	for(i=0;i<tam;i++){
		if(lista[i].isEmpty==OCUPADO){
			MostrarEmpleado(lista[i]);
			rtn=1;
		}

	}
	return rtn;
}

void MostrarEmpleado(eEmpleados lista){

	printf("%d  ",lista.idEmpleado);
	printf("%s  ",lista.nombre);
	printf("%s  ",lista.apellido);
	printf("%.2f  ",lista.salario);
	printf("%d \n",lista.sector);

}

int OrdenarEmpleados(eEmpleados lista[], int tam){
	int i;
	int j;
	eEmpleados auxiliar;

	for (i=0; i<tam-1; i++){
		for(j=i+1; j<tam; j++){
			if(lista[i].sector>lista[j].sector){
				auxiliar=lista[i];
				lista[i]=lista[j];
				lista[j]=auxiliar;
			}
			if(strcmp(lista[i].apellido, lista[j].apellido)>0){
				auxiliar=lista[i];
				lista[i]=lista[j];
				lista[j]=auxiliar;

			}
		}
	}


}
int BuscarEmpleado(eEmpleados lista[], int tam){
	int i;
	int rtn=-1;
	int idAuxiliar;
	do{
		printf("Ingrese ID: (0-Para cancelar)\n");
		scanf("%d",&idAuxiliar);
		if(idAuxiliar!=0){
			for(i=0; i<tam; i++){
				if(lista[i].idEmpleado==idAuxiliar){
					printf("Dato encontrado! \n");
					MostrarEmpleado(lista[i]);
					system("pause");
					return i;
					break;
				}
			}
			printf("Dato no encontrado!!! \n");
			system("pause");
		}

	}while(idAuxiliar!=0);
	printf("Busqueda cancelada\n");
	return rtn;
}
int PromedioEmpleados(eEmpleados lista[], int tam){
	int i;
	float promedio;
	int contador=0;
	float acumulador=0;
	for(i=0; i<tam; i++){
		contador++;
		acumulador+=lista[i].salario;
	}
	promedio=acumulador/contador;
	printf("Total de empleados: %d",contador);
	printf("Suma total de salarios: %.2f",acumulador);
	printf("Promedio de salarios de empleados: %.2f",promedio);
	return 1;
}

