#include "LinkedList.h"
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_sortList(LinkedList* pArrayEmployee);

int employee_sortByName(void* firstEmployee, void* secondEmployee);
int employee_sortBySalary(void* firstEmployee, void* secondEmployee);
int employee_sortById(void* firstEmployee, void* secondEmployee);
int employee_sortByHours(void* firstEmployee, void* secondEmployee);

#endif // employee_H_INCLUDED
