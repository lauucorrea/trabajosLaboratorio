#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* pEmpleado;

	char idEmployee[128];
	char nombreEmployee[128];
	char horasEmployee[128];
	char sueldoEmployee[128];

	int retorno = -1;

	if(pFile != NULL && pArrayListEmployee != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idEmployee, nombreEmployee, horasEmployee, sueldoEmployee);

		while(!feof(pFile)){
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idEmployee, nombreEmployee, horasEmployee, sueldoEmployee);
			pEmpleado = employee_newParametros(idEmployee, nombreEmployee, horasEmployee, sueldoEmployee);

			if(pEmpleado != NULL && !feof(pFile)){
				retorno = ll_add(pArrayListEmployee, pEmpleado);
			}
		}
	}

    return retorno;
}
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_OneEmployeeFromText(FILE* pFile)
{
	char idEmployee[128];
	int retorno = -1;

	if(pFile != NULL){
		fscanf(pFile, "%[^,],[^\n]\n", idEmployee);
		while(!feof(pFile)){
			fscanf(pFile, "%[^,],[^\n]\n", idEmployee);
			retorno = atoi(idEmployee);
		}
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* oneEmployee;
	int retorno = -1;

	if(pFile != NULL){
		while(!feof(pFile)){
			oneEmployee = employee_new();
			fread(oneEmployee, sizeof(Employee), 1, pFile);
			if(!feof(pFile)){
				ll_add(pArrayListEmployee, oneEmployee);
			}

		}
		retorno = 0;
	}
    return retorno;
}
