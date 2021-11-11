#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Employee* employee_new(){
	Employee* nuevoEmpleado;

	nuevoEmpleado = (Employee*)malloc(sizeof(Employee));

	if(nuevoEmpleado != NULL){
		nuevoEmpleado -> id = 0;
		nuevoEmpleado -> sueldo = 0;
		nuevoEmpleado->horasTrabajadas = 0;
		strcpy(nuevoEmpleado -> nombre, "");
	}

	return nuevoEmpleado;
}

void employee_delete(Employee* this){
	if(this != NULL){
		free(this);
	}
}

int employee_setId(Employee* this,int id){
	int retorno = -1;

	if(this != NULL){
		if(id >= 0){
			this -> id = id;
			retorno = 0;
		}
	}

	return retorno;
}

int employee_getId(Employee* this, int* id){
	int retorno = -1;

	if(this != NULL && id != NULL){
		*id = this -> id;
		retorno = 0;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre){
	int retorno = -1;

	if(this != NULL && nombre != NULL){
		strcpy(this -> nombre, nombre);
		retorno = 0;
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre){
	int retorno = -1;

	if(this != NULL && nombre != NULL){
		strcpy(nombre, this -> nombre);
		retorno = 0;
	}

	return retorno;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int retorno = -1;

	if(this != NULL){
		if(horasTrabajadas >= 0){
			this -> horasTrabajadas = horasTrabajadas;
			retorno = 0;
		}
	}

	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int retorno = -1;

	if(this != NULL){
		if(horasTrabajadas >= 0){
			*horasTrabajadas = this -> horasTrabajadas;
			retorno = 0;
		}
	}

	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo){
	int retorno = -1;

	if(this != NULL){
			this -> sueldo = sueldo;
			retorno = 0;
	}

	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo){
	int retorno =-1;

	if(this != NULL && sueldo != NULL){
			*sueldo = this -> sueldo;
			retorno = 0;
	}

	return retorno;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){
	Employee* nuevoEmpleado;
	nuevoEmpleado = employee_new();

	int id;
	int cantHoras;
	int sueldo;

	id = atoi(idStr);
	cantHoras = atoi(horasTrabajadasStr);
	sueldo = atoi(sueldoStr);

	if(nuevoEmpleado != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL){
		employee_setNombre(nuevoEmpleado, nombreStr);
		employee_setId(nuevoEmpleado, id);
		employee_setHorasTrabajadas(nuevoEmpleado, cantHoras);
		employee_setSueldo(nuevoEmpleado, sueldo);
	}

	return nuevoEmpleado;
}

int employee_sortList(LinkedList* pArrayEmployee){
	int retorno = -1;

	int opcion;

	if(pArrayEmployee != NULL){
        puts("OPCIONES:");
        puts("1. Ordernar lista de empleados por nombre.");
        puts("2. Ordenar lista de empleados por sueldo.");
        puts("3. Ordenar lista de empleados por Id.");
        puts("4. Cancelar.");
        scanf("%d", &opcion);

        switch(opcion){

			case 1:
				retorno = ll_sort(pArrayEmployee, employee_sortByName, 1);
				puts("Lista Ordenada con exito por NOMBRE");
			break;
			case 2:
				retorno = ll_sort(pArrayEmployee, employee_sortBySalary, 1);
				puts("Lista Ordenada con exito por SUELDO");
			break;
			case 3:
				retorno = ll_sort(pArrayEmployee, employee_sortById,1);
				puts("Lista ordenada con exito por ID");
			break;
			case 4:
				puts("Cancelando Operacion ...");
				 retorno = 0;
			break;
			default:
				puts("Error. opcion invalida");
				 retorno = 0;
			break;
        }
	}
	return retorno;
}



int employee_sortByName(void* firstEmployee, void* secondEmployee){
	int retorno = 0;

	char nameFirst[50];
	char nameSecond[50];

	employee_getNombre(firstEmployee, nameFirst);
	employee_getNombre(secondEmployee, nameSecond);

	if(strcmp(nameFirst,nameSecond) > 0){
		//El primer nombre es mayor al segundo (va primero)
		retorno = 1;
	}
	if(strcmp(nameFirst,nameSecond) < 0){
		retorno = -1;
	}

	return retorno;
}

int employee_sortBySalary(void* firstEmployee, void* secondEmployee){
	int retorno = 0;

	int firstSalary;
	int secondSalary;

	employee_getSueldo(firstEmployee, &firstSalary);
	employee_getSueldo(secondEmployee, &secondSalary);

	if(firstSalary > secondSalary){
		retorno = 1;
	}
	if(firstSalary < secondSalary){
		retorno = -1;
	}
	return retorno;
}

int employee_sortById(void* firstEmployee, void* secondEmployee){
	int retorno = 0;

	int firstId;
	int secondId;

	employee_getId(firstEmployee, &firstId);
	employee_getId(secondEmployee, &secondId);

	if(firstId > secondId){
		retorno = 1;
	}
	if(firstId < secondId){
		retorno = -1;
	}

	return retorno;

}
