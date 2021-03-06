#include "ArrayEmployees.h"
#include "functions.h"
#define TAM 1000
#define EMPTY 1
#define FILLED 0
#define MODIFIED -1

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *\isEmpty =  1--> empty
 *\isEmpty =  0 --> loaded
 *\isEmpty  = -1 --> deleted
 */
int initEmployees(Employee* list, int len)
{

	if(len > 1000){
		return -1;
	}else{
		for(int i=0; i<TAM;i++){
			list[i].isEmpty = 1;
		}
		 return 0;
	}
}
//returns 0 = found empty position
//returns -1 = there's any free space in the list
int searchFirstEmptyPosition (Employee* list, int tam, int* validation)
{
  int i;
  int index = 0;
  int foundSpace = -1;
  index = -1;
  for (i = 0; i < tam; i++)
  {

	  if (list[i].isEmpty == EMPTY)
	{
		if(foundSpace != 0){
			*validation = 0;
			foundSpace = 0;
			index = i;
			break;
		}
	}
  }
  if(foundSpace == -1 || tam != TAM){
	  *validation = -1;
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

/*
 * typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int freeSlot;
	int validation;
	freeSlot = searchFirstEmptyPosition(EmployeesList, TAM, &validation);

	if( freeSlot != -1 && validation == 0 && list != NULL){
		list[freeSlot].id = id;
		strcpy(list[freeSlot].name, name);
		strcpy(list[freeSlot].lastName, lastName);
		list[freeSlot].salary = salary;
		list[freeSlot].sector = sector;
		list[freeSlot].isEmpty = 0;
		return 0;
	}else{
		return -1;
	}

}


int findEmployeeById(Employee* list, int len,int id)
{
	for(int i = 0; i < len; i++){
		if(list[i].id == id){
			return i;
			break;
		}
	}
 return -1;
}

int removeEmployee(Employee* list, int len, int id)
{
	for(int i = 0; i < len; i++){
			if(list[i].id == id){
				list[i].isEmpty = -1;
				return 0;
			}
		}
 return -1;
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

int sortEmployees(Employee* list, int len, int order){
	Employee auxiliar;
	int ret;
	int comparation;
	if(len <= TAM){
		//Menor a mayor
		if(order==1 && list != NULL){
			for(int i=0; i<len-1; i++){
				for(int j = i+1; j<len; j++){

					if(list[i].sector > list[j].sector){
						auxiliar = list[i];
						list[i] = list[j];
						list[j] = auxiliar;
					}
					else if(list[i].sector == list[j].sector){
						comparation = strcmp(list[i].lastName, list[j].lastName);
						if(comparation > 0){
							auxiliar = list[i];
							list[i] = list[j];
							list[j] = auxiliar;
						}
					}
				}
			}
			ret =  0;

		}else if(order == 0 && list != NULL){//Mayor a menor
			for(int i=0; i<len-1; i++){
				for(int j = i+1; j<len; j++){
					if(list[i].sector > list[j].sector){
						auxiliar = list[j];
						list[j] = list[i];
						list[j] = auxiliar;
					}else if(list[i].sector == list[j].sector){
						comparation = strcmp(list[i].lastName, list[j].lastName);
						if(comparation > 0){
							auxiliar = list[j];
							list[j] = list[i];
							list[j] = auxiliar;
						}
					}
				}
			}
		ret =  0;
		}else{
			ret = -1;
		}
	}else{
		ret = -1;
	}
	return ret;
}

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int 0 if list is NOT empty / -1 if list is empty
 *
 */
int printEmployees(Employee* list, int length)
{
	int flagFirstLoop = 1;
	int flagEmpty = 1;

	for(int i=0; i < length; i++){
		if(flagFirstLoop == 1){
			puts("-------------------------------------");
			puts("|ID\tNOMBRE\tAPELLIDO\tSALARIO\tSECTOR|");
			flagFirstLoop = 0;
		}
		if(list[i].isEmpty == 0){
			puts("-------------------------------------");
			printf("| %4d | %15s | %10s | %4.2f | %4d |\n", list[i].id,list[i].name, list[i].lastName, list[i].salary, list[i].sector);
			puts("-------------------------------------");
			flagEmpty = 0;
		}
	}
	if(flagEmpty == 1){
		 return -1;
	}else{
		return 0;
	}
}

int printOneEmployee(Employee* list, int indexEmployee){
	int ret;
	if(list[indexEmployee].isEmpty == 0 ){
			puts("-------------------------------------");
			puts("|ID\tNOMBRE\tAPELLIDO\tSALARIO\tSECTOR|");
			puts("-------------------------------------");
			printf("| %4d | %15s | %10s | %4.2f | %4d |\n", list[indexEmployee].id,list[indexEmployee].name, list[indexEmployee].lastName, list[indexEmployee].salary, list[indexEmployee].sector);
			puts("-------------------------------------");
			ret = 0;
	}else{
		ret = -1;
	}
	return ret;

}
int EjecutarAccionInformes(Employee* list, int option){
	int retorno = -1;
	int validation;
	float promedio;
	int contadorEmpleadosSuperan;
	int cantidadEmpleadosHabilitados;
	switch(option){
		case 1:
			puts("*LISTA DE EMPLEADOS SIN ORDENAR*");
			validation = printEmployees(EmployeesList, TAM);
			if(validation != 0){
				puts("---------------------------------");
				puts("La lista de empleados esta vacia.");
			}else{
				validation = sortEmployees(EmployeesList, TAM, 1);
				if(validation != 0){
					puts("---------------------------------");
					puts("[Invalid length or NULL pointer]");
					break;
				}
				retorno = 0;
				puts("*LISTA DE EMPLEADOS ORDENADA*");
				validation = printEmployees(EmployeesList, TAM);
				if(validation != 0){
					puts("---------------------------------");
					puts("La lista de empleados esta vacia.");
				}
			}

		break;
		case 2:
			validation = CalculatePromActiveEmployees(EmployeesList, TAM, &validation, &promedio, &cantidadEmpleadosHabilitados);
			if(validation != 0){
				puts("---------------------------------");
				puts("No se encontraron empleados activos");
				break;
			}
			puts("---------------------------------");
			printf("La cantidad de empleados es de: %d\n", cantidadEmpleadosHabilitados);
			printf("El promedio es de: %.2f\n", promedio);
			contadorEmpleadosSuperan = EmpleadosSuperanPromedio(EmployeesList, TAM, &validation, promedio);
			if(validation != 0){
				puts("---------------------------------");
				puts("No se encontraron empleados que superen el promedio");
				break;
			}
			puts("---------------------------------");
			printf("La cantidad de empleados que superan el promedio es de: %d\n", contadorEmpleadosSuperan);
			retorno = 0;

		break;
	}

	return retorno;
}
int EjecutarAccionABM(Employee* list, int index, int option){
	int validation;
	int retorno = -1;
	char string[51];
	float auxSalario;
	int auxSector;

	switch(option){
	case 1:
		getString(string, "Ingrese el nuevo nombre",51, &validation);
		if(validation !=-1){
			strcpy(list[index].name, string);
			retorno = 0;
		}

	break;

	case 2:
		getString(string, "Ingrese el nuevo apellido",51, &validation);
		if(validation !=-1){
			strcpy(list[index].lastName, string);
			retorno = 0;
		}
	break;

	case 3:
		auxSalario = IngresarFlotante("Ingrese el nuevo salario",&validation);
		if(validation !=-1){
			list[index].salary = auxSalario;
			retorno = 0;
		}
	break;

	case 4:
		auxSector = IngresarEntero("Ingrese el nuevo sector", &validation);
		if(validation !=-1){
			list[index].sector = auxSector;
			retorno = 0;
		}
	break;

	}
	return retorno;
}

int CalculatePromActiveEmployees(Employee* list, int len, int* validation, float* promedio, int* totalEmployees){
	float prom = -1;
	int counterActiveEmployees = 0;
	float totalSalary = 0;

	  int foundSpace = -1;
	  for (int i = 0; i < len; i++)
	  {
		  if (list[i].isEmpty == FILLED)
		{
			counterActiveEmployees++;
			totalSalary += list[i].salary;
			foundSpace =0;
		}
	  }
	  if(foundSpace == -1 || len != TAM){
		  return -1;
	  }else{
		  prom = totalSalary / counterActiveEmployees;
		  *totalEmployees = counterActiveEmployees;
		  *promedio = prom;
		  return 0;
	  }

}

int EmpleadosSuperanPromedio(Employee* list, int len, int* validation, float prom){
int contadorEmpleados = 0;

	for (int i = 0; i < len; i++)
	{
		if(list[i].salary >= prom){
			contadorEmpleados++;
		}
	}

	if(contadorEmpleados == 0){
		return contadorEmpleados;
		*validation = -1;
	}else{
		return contadorEmpleados;
		*validation = 0;
	}
}
