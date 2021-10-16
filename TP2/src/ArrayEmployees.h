/*
 * employee.h
 *
 *  Created on: 15 Oct 2021
 *      Author: Lauta
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAM 1000

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;

Employee EmployeesList[TAM];
//Inicializa isEmpty en 1 para todas las posiciónes
int initEmployees(Employee* list, int len);
//returns 0 = found empty position
//returns -1 = there's any free space in the list
int searchFirstEmptyPosition (Employee* list, int tam, int* validation);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id);
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int sortEmployees(Employee* list, int len, int order);
/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int length);

/** \brief print the content of the list[indexEmployee] array
 * where indexEmployee is the position where the employee should be to be
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printOneEmployee(Employee* list, int indexEmployee);

//Ejecuta una accion, segun la opcion elegida en el sub menu ABM
//Option recibe la opcion ingresada por el usuario
// Index es la posicion de la lista que estamos recorriendo
// Retorna 0 si no hay error, -1 si encuentra un error
int EjecutarAccionABM(Employee* list, int index, int option);

//Ejecuta una accion, segun la opcion elegida en el sub menu de informes
//Option recibe la opcion ingresada por el usuario
// Retorna 0 si no hay error, -1 si encuentra un error
int EjecutarAccionInformes(Employee* list, int option);

//Encuentra las posiciones que tienen isEmpty en 0
//Suma todos los salarios de las coincidencias
//Divide la suma entre el total de coincidencias encontradas
//Devuelve los resultados por parametro
//Por punteros, validation devuelve 0 si esta ok y -1 si hay error
int CalculatePromActiveEmployees(Employee* list, int len, int* validation, float* promedio, int* totalEmployees);

//Recibe el promedio por parámetros y recorre la lista
//Las coincidencias de los salarios que superen el promedio, son sumados en un contador
//Devuelve 0 si esta ok y -1 si hay error
int EmpleadosSuperanPromedio(Employee* list, int len, int* validation, float prom);
#endif /* ARRAYEMPLOYEES_H_ */

