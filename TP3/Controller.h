#include "Employee.h"

//Carga los datos guardados desde la ruta del archivo especificada
//retorna 0 y -1
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

//Carga en memoria los datos guardados desde la ruta del archivo de tipo binario
//retorna 0 y -1
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

//Agrega un empleado al nodo, asi como tambien asigna el id correspondiente
// retorna 0 y -1
//contiene a controller_calculateId para calcular el id proximo
int controller_addEmployee(LinkedList* pArrayListEmployee);

//Permite la modificacion de los empleados existentes segun su id
// retorna 0 y -1
int controller_editEmployee(LinkedList* pArrayListEmployee);

//Elimina un empleado de un nodo  (FREE)
//retorna 0 y -1
int controller_removeEmployee(LinkedList* pArrayListEmployee);

//Enlista los empleados existentes en el linked list
//retorna 0 y -1
int controller_ListEmployee(LinkedList* pArrayListEmployee);

//ordena el array de empleados segun el criterio elegido
//retorna 0 y -1
int controller_sortEmployee(LinkedList* pArrayListEmployee);

//Guarda todos los empleados existentes en memoria dentro del path del archivo especificado
//en formato texto
//retorna 0 y -1
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

//Guarda todos los empleados existentes en memoria dentro del path del archivo especificado
// en formato binario
//retorna 0 y -1
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

//Guarda el Id del empelado que se genero en un archivo de texto para un mejor control de identificadores
//retorna 0 y -1
int controller_saveLastEmployeeAsText(char* path, int id);

//Carga el id existente generado previamente en el archivo de texto
//retorna 0 y -1
int controller_loadLastIdFromText(char* path);

//Calcula el id que le corresponde el proximo empleado
//Evalua cual es el mayor encontrado en la lista de empleados actualmente
//Si el valor de la lista es menor al leido en el archivo, entonces se utiliza el mayor
//retorna el id calculado y -1 en caso de error
int controller_calculateId(LinkedList* pArrayListEmployee);

//Carga los archivos segun que opcion del menu principal se eligio
//a demas controla la confirmacion del usuario en caso de no querer perder la informacion en memoria
//devuelve 0 y -1
int controller_loadFromFile(LinkedList* listaEmpleados,int option, int operation, int* pFlagFileLoaded);

