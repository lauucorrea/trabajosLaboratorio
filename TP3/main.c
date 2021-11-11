#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "functions.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option;
    int validationControl;
    int lastId;
    int flagFirstRoll = 1;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	option = DeployMainMenu();
    	if(option != -1){
            switch(option)
            {
                case 1:
                	ll_clear(listaEmpleados);
                    validationControl = controller_loadFromText("data.csv",listaEmpleados);
                    if(validationControl != -1){
                    	if(lastId != -1){
                    		puts("El archivo se cargo correctamente");
                    	}

                    }else{
                    	puts("ERROR ! No pudo cargarse el archivo");
                    }
                break;
                case 2:
                	ll_clear(listaEmpleados);
                	validationControl = controller_loadFromBinary("data.bin", listaEmpleados);

                    if(validationControl != -1){
                    	puts("El archivo se cargo correctamente");
                    }else{
                    	puts("ERROR ! No pudo cargarse el archivo");
                    }
                break;
                case 3:
                	if(flagFirstRoll == 1){
                		lastId = controller_calculateId(listaEmpleados);
                    	validationControl = controller_addEmployee(listaEmpleados,&lastId);
                    	flagFirstRoll = 0;
                	}else{
                		validationControl = controller_addEmployee(listaEmpleados,&lastId);
                	}

                    if(validationControl != -1){
                    	puts("El empleado se cargo correctamente");
                    }else{
                    	puts("ERROR ! No pudo cargarse el empleado");
                    }
                break;
                case 4:
                	validationControl = controller_editEmployee(listaEmpleados);
                    if(validationControl != -1){
                    	puts("El empleado se edito correctamente");
                    }else{
                    	puts("ERROR ! No pudo editarse el empleado");
                    }
                break;
                case 5:
                	validationControl = controller_removeEmployee(listaEmpleados);
                    if(validationControl != -1){
                    	puts("El empleado se elimino correctamente");
                    }else if(validationControl == -2){
                    	puts("El empleado no fue eliminado");
                    }else{
                    	puts("ERROR ! No se encontro el Id especificado");
                    }
                break;
                case 6:
                	validationControl = controller_ListEmployee(listaEmpleados);
                    if(validationControl != -1){
                    	puts("La lista se cargo correctamente");
                    }else{
                    	puts("ERROR ! No pudo cargarse la lista");
                    }
                break;
                case 7:
                	validationControl = controller_sortEmployee(listaEmpleados);
                    if(validationControl != -1){
                    	puts("La lista se ordeno correctamente");
                    }else{
                    	puts("ERROR ! No pudo ordenarse la lista");
                    }
                break;
                case 8:
                	validationControl = controller_saveAsText("data.csv", listaEmpleados);
                    if(validationControl != -1){
                    	puts("Se guardo el archivo con exito");
                    }else{
                    	puts("ERROR ! No pudo guardarse el archivo");
                    }
                break;
                case 9:
                	validationControl = controller_saveAsBinary("data.bin", listaEmpleados);
                    if(validationControl != -1){
                    	puts("Se guardo el archivo con exito");
                    }else{
                    	puts("ERROR ! No pudo guardarse el archivo");
                    }
                break;
                case 10:
                	puts("Saliendo del sistema");
                	exit(0);
                break;
                default:
                	puts("ERROR ! opcion incorrecta");
                break;
            }
    	}

    }while(option != 10 && option != -1);

    puts("Gracias por utilizar nuestro sistema");
    return 0;
}

