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

//Reserva y asigna un espacio en memoria para el nuevo empleado generado
Employee* employee_new();

//Carga los datos en el espacio asignado por employee_new
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

//Libera la memoria reservada para el empleado
void employee_delete(Employee* this);

//Guarda el id del empleado en su atributo Id
int employee_setId(Employee* this,int id);

//Obtiene el id del empleado desde su atributo ID
int employee_getId(Employee* this,int* id);

//Guarda el nombre del empleado en su atributo Nombre
int employee_setNombre(Employee* this,char* nombre);

//Obtiene el nombre del empleado desde su atributo Nombre
int employee_getNombre(Employee* this,char* nombre);

//Guarda las horas del empleado en su atributo horasTrabajadas
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

//Obtiene las horas del empleado desde su atributo horasTrabajadas
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

//Guarda el sueldo del empleado en su atributo sueldo
int employee_setSueldo(Employee* this,int sueldo);

//Obtiene el sueldo del empleado desde su atributo sueldo
int employee_getSueldo(Employee* this,int* sueldo);

//Ordena la lista de empleados segun el critero del cliente
int employee_sortList(LinkedList* pArrayEmployee);

//Ordena la lista de empleados por NOMBRE
int employee_sortByName(void* firstEmployee, void* secondEmployee);

//Ordena la lista de empleados por SUELDO
int employee_sortBySalary(void* firstEmployee, void* secondEmployee);

//Ordena la lista de empleados por ID
int employee_sortById(void* firstEmployee, void* secondEmployee);

//Ordena la lista de empleados por HORAS
int employee_sortByHours(void* firstEmployee, void* secondEmployee);

#endif // employee_H_INCLUDED
