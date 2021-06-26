
#include "nexo.h"
#define VACIO 1
#define OCUPADO 0


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

int initEmployees(Employee* list, int len){
	int i;
	int rtn;
	rtn=0;
	if(list!=NULL && len>0)
	{
		for(i=0; i<len; i++){
			list[i].isEmpty=VACIO;
			rtn=0;
		}
	}

	return rtn;
}

int findFreeEmployee(Employee* list, int len){
	int i;
	int index;
	index=-1;
	for(i=0; i<len; i++){
		if(list[i].isEmpty==VACIO){
			index=i;
			break;
		}
	}
	return index;
}
/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],int salary,int sector){
	int index;
	int rtn;
	rtn = 0;
	if(list!=NULL && len>0){
		index=findFreeEmployee(list, len);
		if(index!=-1){
			rtn = 1;

			list[index].idEmpleado=id;
			strcpy(list[index].nombre, name);
			strcpy(list[index].apellido, lastName);
			list[index].sector=sector;
			list[index].salario=salary;
			list[index].isEmpty=OCUPADO;
		}

	}

	return rtn;


}
int dataChargeEmployee(Employee *list, int len){


	int id;
	char name[51];
	char lastName[51];
	int salary;
	int sector;
	int rtn=-1;
	if(list!= NULL && len >0)
	{
		if(CargarUnaCadena("Ingrese nombre", name) &&
			CargarUnaCadena("Ingrese apellido", lastName)&&
			!CargarUnEntero("Ingrese salario", &salary, 0, 1000000) &&
			!CargarUnEntero("Ingrese numero de sector (0-10)", &sector, 0, 10))
		{
			id = get_Id();
			rtn=0;

			if(addEmployee(list, len, id, name, lastName, salary, sector))
			{
				rtn=1;
			}
		}
	}
	return rtn;
}
/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len, int id)
{
	int i;
	int index=-1;

	if(list!=NULL && len>0 && id>0){
		index = 0;
		for(i=0; i<len; i++){

			if(list[i].idEmpleado==id && list[i].isEmpty==OCUPADO){

				index= i;
				break;
			}

		}

	}


	return index;
}
/** \brief Controller remove a Employee
*
* \param list Employee*
* \param len int
* \return int Return (-1) if Error [Invalid length or NULL pointer (0) if can't find a employee] - (1) if Ok
*
*/
int controllerRemoveEmployee(Employee* list, int len)
{
	int rtn=-1;
	int contador;
	int id;
	int opcion;
	int index;
	if(list!=NULL && len>0)
	{
		contador=contadorEmpleados(list, len);
		rtn=0;
		if(contador>0)
		{

			printEmployees(list, len);
			if(!CargarUnEntero("Ingrese id del empleado a eliminar",&id, 0, buscarIdMayor(list, len)))
			{
				index=findEmployeeById(list, len, id);
				if(!CargarUnEntero("Esta seguro de eliminar el empleado (1=SI 0=NO)",&opcion, 0, 1))
				{
					if(opcion==1)
					{
						if(!removeEmployee(list, len, index))
						{
							rtn=1;
						}
					}
				}
			}
		}
	}
	return rtn;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param index int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int index)
{
	int rtn=-1;

	if(list != NULL && len>0)
	{
		list[index].isEmpty=VACIO;
		rtn=0;
	}

	return rtn;
}

/** \brief Edit a Employee by Id
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*
*/

int editEmployee(Employee* list, int len, int id){
	Employee auxiliar;

	int rtn=-1;
	int index;
	int opcion;
	int guardar=0;
	int bandera=0;
	if(list!=NULL && len>0)
	{

		index=findEmployeeById(list, len, id);
		showOneEmployee(list, index);
		if(index!=-1){
			auxiliar=list[index];
			do{

				if(!CargarUnEntero("Que desea modificar? \n1-Nombre\n2-Apellido\n3-Salario \n4-Sector \n0- Salir",&opcion,0,4))
				{
					switch(opcion){
						case 1:
							if(!CargarUnaCadena("Ingrese nombre:\n", auxiliar.nombre))
							{
								bandera=1;
							}

							break;
						case 2:
							if(!CargarUnaCadena("Ingrese apellido:\n", auxiliar.apellido))
							{
								bandera=1;
							}

							break;

						case 3:
							if(!CargarUnEntero("Ingrese salario:",&(auxiliar.salario), 0, 1000000))
							{
								bandera=1;
							}

							break;

						case 4:

							if(!CargarUnEntero("Ingrese numero de sector (1-10):",&(auxiliar.sector), 1, 10))
							{
								bandera=1;
							}

							break;

						case 0:
							if(bandera==1){
								if(!CargarUnEntero("Desea guardar los cambios? 1 = SI   0 = NO",&guardar, 0, 1)){
									if(guardar==1)
									{
										*(list+index)=auxiliar;
										rtn=1;
									}
								}
							}
							break;
						}
				}

			}while(opcion!=0);
		}

	}
	return rtn;


}
/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int length)
{
	int rtn=-1;
	int i;
	if(list!=NULL && length>0)
	{
		rtn=0;
		for(i=0; i<length; i++)
		{
			if(list[i].isEmpty==OCUPADO)
			{
				rtn=1;
				showOneEmployee(list, i);
			}

		}

	}
	return rtn;
}

void showOneEmployee(Employee* list, int index)
{
	if(list!= NULL && list[index].isEmpty==OCUPADO){
		printf("| %4d | %10s | %15s | %15d | %10d |\n",list[index].idEmpleado, list[index].nombre, list[index].apellido, list[index].sector, list[index].salario);
	}
}



/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order)
{
    Employee pEmpleado;
    int rtn = -1;

     if(order==1){
        for(int i=0; i<len-1; i++){
            for(int j=i+1; j<len; j++){

            	if(strcmp(list[j].nombre,list[i].nombre)<0){

            		pEmpleado = list[i];
                    list[i] = list[j];
                    list[j] = pEmpleado;

            	}
                else
                {
                	if(strcmp(list[j].nombre, list[i].nombre) == 0 && list[i].sector>list[j].sector){

                		pEmpleado = list[i];
						list[i] = list[j];
						list[j] = pEmpleado;
                	}

                }
            }
        }
        rtn = 1;
    }

    if(order==0){
        for(int i=0; i<len-1; i++){
            for(int j=i+1; j<len; j++) {

                if(strcmp(list[j].nombre,list[i].nombre)>0){
                    pEmpleado = list[i];
                    list[i] = list[j];
                    list[j] = pEmpleado;
                }
                else
                {

                	if(strcmp(list[j].nombre, list[i].nombre) == 0 && list[i].sector<list[j].sector){
						pEmpleado = list[i];
						list[i] = list[j];
						list[j] = pEmpleado;
                	}
                }
            }
        }
        rtn = 1;
    }

    printEmployees(list,len);
    return rtn;
}


int sumaSueldosEmpleados(Employee* list, int len)
{
	int i;
	int acumulador=-1;
	if(list!=NULL && len>0)
	{
		acumulador=0;
		for(i=0; i<len; i++){
			if(list[i].isEmpty==OCUPADO)
			{
				acumulador+=list[i].salario;
			}
		}
	}
	return acumulador;
}

int contadorEmpleados(Employee* list, int len)
{
	int contador=-1;
	int i;
	if(list!=NULL && len>0)
	{
		contador=0;
		for(i=0; i<len; i++){
			if(list[i].isEmpty==OCUPADO)
			{
				contador++;

			}



		}
	}
	return contador;
}

float promedioSueldoEmpleados(Employee* list, int len)
{
	int contador;
	int sumador;
	float promedio=-1;

	contador=contadorEmpleados(list, len);
	sumador=sumaSueldosEmpleados(list, len);

	if(contador!=-1 && sumador!=-1)
	{
		promedio=sumador/contador;
	}

	return promedio;
}

int salarioMayorPromedio(Employee* list, int len)
{
	int i;
	int contador=0;
	for(i=0; i<len; i++)
	{
		if(list[i].salario>=promedioSueldoEmpleados(list, len) && list[i].isEmpty==OCUPADO)
		{
			contador++;
		}
	}
	return contador;
}
int buscarIdMayor(Employee* list, int len)
{
	int idMayor=-1;
	if(list!=NULL && len>0)
	{
		idMayor=0;
		for(int i=0; i<len; i++)
		{
			if(i==0 || list[i].idEmpleado>idMayor)
			{
				idMayor = list[i].idEmpleado;
			}
		}
	}
	return idMayor;
}
