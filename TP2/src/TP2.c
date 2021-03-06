/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "ArrayEmployees.h"
#include "functions.h"
#define TAM 1000
#define EMPTY 0
#define FILLED 1
#define MODIFIED -1

int main(void) {
	setbuf(stdout,NULL);

	int pValidation = 0;
	int flagInit = 0;
	int isLoadedEmployee;
	int employeeId = 1000;

	int nameValidation;
	int lastNameValidation;
	int salaryValidation;
	int sectorValidation;

	int optionMenu;
	int idBusqueda;
	int indexId;
	char employeeName [50];
	char employeeLastName[50];
	int employeeSalary;
	int employeeSector;





	do{
		optionMenu = MostrarMenu();

		while(isLoadedEmployee != 1 && optionMenu != 1){
			puts("---------------------------------");
			puts("Primero deberias cargar al menos un empleado");
			optionMenu = MostrarMenu();
		}
		//setea la lista de empleados con el isEmpty en 1 solo en la primer vuelta
		if(flagInit == 0){
			pValidation = initEmployees(EmployeesList, TAM);
			if(pValidation != 0){
				puts("No se puede inicializar la lista");
				break;
			}
			flagInit = 1;
		}


		if(optionMenu != -1){

			switch(optionMenu){
				case 1:
					puts("---------------------------------");
					getString(employeeName, "Ingrese el nombre del empleado\n",51, &nameValidation);
					getString(employeeLastName, "Ingrese el apellido del empleado\n",51, &lastNameValidation);
					employeeSalary = IngresarEntero("Ingrese el salario del empleado\n", &salaryValidation);
					employeeSector = IngresarEntero("Ingrese el sector del empleado\n", &sectorValidation);

					if(nameValidation != 0 || lastNameValidation != 0 || salaryValidation != 0 || sectorValidation != 0){
						continue;
					}
					employeeId++;

					pValidation = addEmployee(EmployeesList, TAM, employeeId, employeeName, employeeLastName, employeeSalary, employeeSector);
					if(pValidation != 0){
						continue;
					}
					isLoadedEmployee = 1;
					puts("---------------------------------");
					puts("Empleado cargado");
				break;
				case 2:
					pValidation = printEmployees(EmployeesList, TAM);
					if(pValidation != 0){
						puts("---------------------------------");
						puts("La lista de empleados esta vacia.");
					}
					puts("---------------------------------");
					idBusqueda = IngresarEntero("Ingrese el id del empleado que desea modificar\n", &pValidation);
					if(pValidation != 0){
						puts("---------------------------------");
						puts("El id ingresado no es un numero o excede nuestra capacidad");
						continue;
					}
					indexId = findEmployeeById(EmployeesList, TAM, idBusqueda);
					if(indexId != -1){
						pValidation = printOneEmployee(EmployeesList, indexId);
						if(pValidation != 0){
							puts("---------------------------------");
							puts("El empleado se encuentra dado de baja o no existe");
							continue;
						}
						optionMenu = MostrarSubMenuABM(&pValidation);
						if(pValidation != 0 || optionMenu == -1){
							puts("---------------------------------");
							puts("El dato ingresado no es un caracter");
							continue;
						}
						pValidation = EjecutarAccionABM(EmployeesList, indexId, optionMenu);
						if(pValidation == -1 && pValidation != -2){
							puts("---------------------------------");
							puts("El dato ingresado no es el correcto");
							continue;
						}else if(pValidation == -2){
							continue;
						}
					}else{
						puts("---------------------------------");
						puts("El empleado se encuentra dado de baja o no existe");
					}

				break;
				case 3:
					pValidation = printEmployees(EmployeesList, TAM);
					if(pValidation != 0){
						puts("Listado de empleados vacia");
						continue;
					}
					idBusqueda = IngresarEntero("Ingrese el id del empleado que desea eliminar", &pValidation);
					if(pValidation != 0){
						puts("---------------------------------");
						puts("El numero ingresado no es el correcto");
						continue;
					}
					indexId = findEmployeeById(EmployeesList, TAM, idBusqueda);
					if(indexId == -1){
						puts("---------------------------------");
						puts("No se encontro el empleado ingresado");
						continue;
					}
					printOneEmployee(EmployeesList, indexId);
					if(pValidation != 0){
						puts("---------------------------------");
						puts("El empleado no existe en nuestro registro");
						continue;
					}
					pValidation = removeEmployee(EmployeesList, TAM, EmployeesList[indexId].id);
					if(pValidation != 0){
						puts("---------------------------------");
						puts("La lista de empleados esta vacia.");
						continue;
					}else{
						puts("---------------------------------");
						puts("Empleado exitosamente eliminado");
					}
					pValidation = printEmployees(EmployeesList, TAM);
					if(pValidation != 0){
						puts("---------------------------------");
						puts("La lista de empleados esta vacia.");
					}

				break;
				case 4:
					optionMenu = MostrarSubMenuInformes(&pValidation);

					if(pValidation == -1 && pValidation != -2){
						puts("---------------------------------");
						puts("El dato ingresado no es el correcto");
						continue;
					}else if(pValidation == -2){
						continue;
					}
					pValidation = EjecutarAccionInformes(EmployeesList, optionMenu);
					if(pValidation == -1 && pValidation != -2){
						puts("---------------------------------");
						puts("El dato ingresado no es el correcto");
						continue;
					}else if(pValidation == -2){
						continue;
					}
			}
		}
		if(pValidation != 0){
			puts("--------------------------");
			puts("Gracias por usar nuestro sistema");
			break;
		}

	}while(optionMenu != -1);
}
