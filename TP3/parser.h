/*
 * parser.h
 *
 *  Created on: 9 Nov 2021
 *      Author: Lauta
 */

#ifndef PARSER_H_
#define PARSER_H_

//Obtiene la informacion del archivo linea por linea, y asigna los datos al linked list
//retorna 0 y -1
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

//Obtiene la informacion del archivo linea por linea, y asigna los datos al linked list
//retorna 0 y -1
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

//Obtieneel id del archivo linea por linea, y asigna los datos al linked list
//retorna 0 y -1
int parser_OneEmployeeFromText(FILE* pFile);
#endif /* PARSER_H_ */
