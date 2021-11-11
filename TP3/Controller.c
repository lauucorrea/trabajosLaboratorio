#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "functions.h"
#include "parser.h"
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;

	int retorno = -1;
	pFile = fopen(path, "r");

	if(pFile != NULL){
		parser_EmployeeFromText(pFile, pArrayListEmployee);
		retorno = 0;
	}
	fclose(pFile);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;

	int retorno = -1;
	pFile = fopen(path, "rb");
	if(pFile != NULL){
		parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		retorno = 0;
	}
	fclose(pFile);

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id)
{
	Employee* oneEmployee;
	int retorno = -1;
	int validacionNombre;
	int validacionSueldo;
	int validacionHoras;

	char nombre[128];
	int sueldo;
	int horas;


	oneEmployee = employee_new();

	if(pArrayListEmployee != NULL){

		getString(nombre, "Ingrese el nombre del empleado", 128, &validacionNombre);
		horas = IngresarEntero("Ingrese las horas del empleado", &validacionHoras);
		sueldo = IngresarEntero("Ingrese el sueldo del empelado", &validacionSueldo);
		printf("EL ID ES, %d\n", id);
		if(oneEmployee != NULL){
			if(validacionHoras != -1 && validacionNombre != -1 && validacionSueldo != -1){
				*id = id + 1;
				employee_setId(oneEmployee, id);
				employee_setSueldo(oneEmployee, sueldo);
				employee_setHorasTrabajadas(oneEmployee, horas);
				ll_add(pArrayListEmployee, oneEmployee);
				retorno = 0;
			}
		}
	}

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pEmpleado;
	int validacion;
	int idEmpleadoActual;
	int id;
	int opcion;
	int numero;
	char cadena[128];
    int retorno = -1;

    if(pArrayListEmployee !=  NULL){
    	id = IngresarEntero("Ingrese el Id del empleado a modificar", &validacion);
    	if(validacion != -1){
            for(int i = 0; i< ll_len(pArrayListEmployee);i++){
            	pEmpleado = ll_get(pArrayListEmployee, i);
            	employee_getId(pEmpleado, &idEmpleadoActual);

            	if(idEmpleadoActual == id){
                    puts("OPCIONES:");
                    puts("1. Modificar nombre.");
                    puts("2. Modificar sueldo.");
                    puts("3. Modificar horas trabajadas.");
                    puts("4. Cancelar.");
                    opcion = IngresarEntero("Ingrese la opcion a modificar", &validacion);

                    if(validacion  != -1){
                    	switch(opcion){
                    	case 1:
                    		getString(cadena, "Ingrese el nuevo nombre", 128, &validacion);
                    		if(validacion != -1){
                    			employee_setNombre(pEmpleado, cadena);
                    			retorno = 0;
                    		}else{
                    			puts("Nombre Ingresado incorrectamente");
                    		}
                    	break;
                    	case 2:
                    		numero = IngresarEntero("Ingresae el nuevo sueldo", &validacion);
                    		if(validacion != -1){
                    			employee_setSueldo(pEmpleado, numero);
                    			retorno = 0;
                    		}else{
                    			puts("Sueldo Ingresado incorrectamente");
                    		}
                    	break;
                    	case 3:
                    		numero = IngresarEntero("Ingrese las nuevas horas", &validacion);
                    		if(validacion != -1){
                    			employee_setHorasTrabajadas(pEmpleado, numero);
                    			retorno = 0;
                    		}else{
                    			puts("Horas Ingresadas incorrectamente");
                    		}
                    	break;
                    	case 4:
                    		puts("---------------------------");
                    		puts("Proceso cancelado");
                    	break;
                    	default:
                    		puts("No existe la opcion ingresada");
                    	break;
                    	}
                    }else{
                    	puts("Opcion incorrecta");
                    }
                    break;
            	}
            }
    	}

    }

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pEmpleado;
    int retorno = -1;
    int idIngresado;
    int idEmpleado;
    int validacion;
    int opcion;
    if(pArrayListEmployee != NULL){
    	idIngresado = IngresarEntero("Ingrese el id del empleado", &validacion);
    	if(validacion != -1){
    		for(int i = 0; i< ll_len(pArrayListEmployee); i++){
    			pEmpleado = ll_get(pArrayListEmployee, i);
    			employee_getId(pEmpleado, &idEmpleado);

    			if(idEmpleado == idIngresado && pEmpleado != NULL){
    				puts("Dar de baja el usuario?");
    	            puts("1 para confirmar");
    	            puts("2 para cancelar");
    	            opcion =IngresarEntero("Ingrese confirmacion", &validacion);
    	            if(validacion != -1){
							switch(opcion){
							case 1:
								employee_delete(pEmpleado);
								retorno = ll_remove(pArrayListEmployee, i);
							break;
							case 2:
								retorno = -2;
							break;
							default:
								puts("La opcion ingresada no es valida");
							break;
    	            	}
    	            }else{
    	            	puts("Opcion ingresada incorrectamente");
    	            	break;
    	            }
    				break;
    			}
    		}
    	}else{
    		puts("Id ingresado incorrectamente");
    	}
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pEmployee;

    int retorno = -1;
    char nombreObtenido[128];
    int idObtenido;
    int sueldoObtenido;
    int horasObtenidas;

    if(pArrayListEmployee != NULL){
        puts("ID \t\t NOMBRE \t\t SUELDO \t\t HORAS");
        retorno = 0;

        for(int i = 0; i< ll_len(pArrayListEmployee); i++){
        	pEmployee = ll_get(pArrayListEmployee, i);
        	if(pEmployee != NULL){
            	employee_getNombre(pEmployee, nombreObtenido);
            	employee_getId(pEmployee, &idObtenido);
            	employee_getSueldo(pEmployee, &sueldoObtenido);
            	employee_getHorasTrabajadas(pEmployee, &horasObtenidas);
            	printf("%5d %20s %20d %20d \n\n", idObtenido, nombreObtenido, sueldoObtenido, horasObtenidas);
        	}

        }
    }

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL){
    	retorno = employee_sortList(pArrayListEmployee);
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* oneEmployee;
    int retorno = -1;
    int id;
    int i;
    char nombre[128];
    int sueldo;
    int horas;

    if(pArrayListEmployee != NULL && path != NULL && ll_isEmpty(pArrayListEmployee) == 0){
    	retorno = 0;
        pFile = fopen(path,"w");
        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
        for(i=0; i< ll_len(pArrayListEmployee);i++){
        	oneEmployee = ll_get(pArrayListEmployee, i);
        	employee_getId(oneEmployee, &id);
        	employee_getNombre(oneEmployee, nombre);
        	employee_getSueldo(oneEmployee, &sueldo);
        	employee_getHorasTrabajadas(oneEmployee, &horas);
        	fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,sueldo,horas);
        }
    	fclose(pFile);
    	if(ll_len(pArrayListEmployee) == i ){
    	  retorno = 0;
    	}
    }
    return retorno;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	Employee* oneEmployee;
    int retorno = -1;
    int i;
    if(path != NULL && pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0){
    	retorno = 0;
    	pFile = fopen(path, "wb");
    	for(i=0; i< ll_len(pArrayListEmployee); i++){
    		oneEmployee = (Employee*) ll_get(pArrayListEmployee,i);
    		fwrite(oneEmployee, sizeof(Employee), 1, pFile);
    	}
    	fclose(pFile);
    	if(ll_len(pArrayListEmployee) == i ){
    	  retorno = 0;
    	}
    }
    return retorno;

}
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadLastIdFromText(char* path)
{
	FILE* pFile;
	int retorno = -1;
	pFile = fopen(path, "r");

	if(pFile != NULL){
		retorno = parser_OneEmployeeFromText(pFile);
		printf("EL ID ES, %d\n", retorno);
	}
	fclose(pFile);

    return retorno;
}
int controller_saveLastEmployeeAsText(char* path, Employee* oneEmployee){
	FILE* pFile;
	int retorno = -1;
	int* reservaId;

	if(path != NULL){
    	reservaId = (int*) malloc(sizeof(int));
    	if(reservaId != NULL){
    		pFile = fopen(path, "w");
    		if(pFile != NULL){
    			retorno = 0;
        		fprintf(pFile,"id\n");
        		employee_getId(oneEmployee, reservaId);
        		fprintf(pFile,"%d\n", *reservaId);
        		free(reservaId);
    		}
    		fclose(pFile);
    	}
	}
	return retorno;
}
//devuelve el id generado, o -1
int controller_calculateId(LinkedList* pArrayListEmployee){
	Employee* oneEmployee;
	int idEmpleado;
	int idMax = -1;
	int flagPrimerEmpleado = 1;

	if(pArrayListEmployee != NULL){
		if(ll_len(pArrayListEmployee) > 0){
			for(int i = 0; i < ll_len(pArrayListEmployee);i++){
				oneEmployee = (Employee*) ll_get(pArrayListEmployee, i);
				if(oneEmployee != NULL){
					employee_getId(oneEmployee, &idEmpleado);

					if(flagPrimerEmpleado == 1){
						idMax = idEmpleado;
						flagPrimerEmpleado = 0;
					}else{
						if(idEmpleado > idMax){
							idMax = idEmpleado;
						}
					}
				}
			}
			idMax++;
		}
	}
	return idMax;
}
