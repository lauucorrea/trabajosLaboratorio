/*
 * parser.h
 *
 *  Created on: 9 Nov 2021
 *      Author: Lauta
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_OneEmployeeFromText(FILE* pFile);

#endif /* PARSER_H_ */
