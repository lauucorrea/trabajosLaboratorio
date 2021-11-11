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
    int optionConfirmOperation = 1;
    int validationControl;
    int pValidation;

    int flagFirstRoll = 1;
    int flagFileLoaded = -1;
    int flagFileSaved = -1;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	option = DeployMainMenu();
    	if(option != -1){
            switch(option)
            {
                case 1:
                	if(flagFileLoaded == 0 && flagFileSaved == -1){
                		puts("Hay datos sin guardar en el sistema.");
                		puts("Desea continuar sin guardar los datos?");
                		optionConfirmOperation = IngresarEntero("Ingrese la respuesta: 1. Si 2.No\n", &pValidation);

						if(pValidation != -1){
							validationControl = controller_loadFromFile(listaEmpleados, optionConfirmOperation, option, &flagFileLoaded);
						}else{
							puts("El dato ingresado es incorrecto");
							validationControl = -1;
						}
                	}else if(flagFileLoaded != 0){
                		validationControl = controller_loadFromText("data.csv", listaEmpleados);
                	}

					if(validationControl != -1){
							puts("El archivo se cargo correctamente");
							flagFileLoaded = 0;
					}else{
						puts("ERROR ! No pudo cargarse el archivo");
					}

                break;
                case 2:
                	if(flagFileLoaded == 0 && flagFileSaved == -1){
                		puts("Hay datos sin guardar en el sistema.");
                		puts("Desea continuar sin guardar los datos?");
                		optionConfirmOperation = IngresarEntero("Ingrese la respuesta: 1. Si 2.No", &pValidation);

                		if(pValidation != -1){
    						validationControl = controller_loadFromFile(listaEmpleados, optionConfirmOperation, option, &flagFileLoaded);
    					}else{
    						puts("El dato ingresado es incorrecto");
    						validationControl = -1;
    					}
                	}else if(flagFileLoaded != 0){
                		validationControl = controller_loadFromBinary("data.bin", listaEmpleados);
                	}


					if(validationControl != -1){
							puts("El archivo se cargo correctamente");
							flagFileLoaded = 0;
					}else{
						puts("ERROR ! No pudo cargarse el archivo");
					}
                break;
                case 3:
                	if(flagFirstRoll == 1 && flagFileLoaded == 0){
                		//lastId = controller_calculateId(listaEmpleados);
                    	validationControl = controller_addEmployee(listaEmpleados);
                    	flagFirstRoll = 0;
                	}else if (flagFirstRoll == 0 && flagFileLoaded == 0){
                		validationControl = controller_addEmployee(listaEmpleados);
                	}else{
                		puts("Error ! Lista Vacia");
                		puts("Deberias cargar al menos un archivo");
                	}

                    if(validationControl != -1){
                    	puts("El empleado se cargo correctamente");
                    }else{
                    	puts("ERROR ! No pudo cargarse el empleado");
                    }
                break;
                case 4:
                	if(flagFileLoaded == 0){
                		controller_ListEmployee(listaEmpleados);
                       	validationControl = controller_editEmployee(listaEmpleados);
                            if(validationControl != -1){
                            	puts("El empleado se edito correctamente");
                            }else{
                            	puts("ERROR ! No pudo editarse el empleado");
                            }
                	}else{
                		puts("Error ! Lista Vacia");
                		puts("Deberias cargar al menos un archivo");
                	}

                break;
                case 5:
                   	if(flagFileLoaded == 0){
                   		controller_ListEmployee(listaEmpleados);
                       	validationControl = controller_removeEmployee(listaEmpleados);
                            if(validationControl != -1){
                            	puts("El empleado se elimino correctamente");
                            }else if(validationControl == -2){
                            	puts("El empleado no fue eliminado");
                            }else{
                            	puts("ERROR ! No se encontro el Id especificado");
                            }
                   	}else{
                		puts("Error ! Lista Vacia");
                		puts("Deberias cargar al menos un archivo");
                   	}

                break;
                case 6:
                	if(flagFileLoaded == 0){
                    	validationControl = controller_ListEmployee(listaEmpleados);
                        if(validationControl != -1){
                        	puts("La lista se cargo correctamente");
                        }else{
                        	puts("ERROR ! No pudo cargarse la lista");
                        }
                	}else{
                		puts("Error ! Lista Vacia");
                		puts("Deberias cargar al menos un archivo");
                	}

                break;
                case 7:
                	if(flagFileLoaded == 0){
                    	validationControl = controller_sortEmployee(listaEmpleados);
                        if(validationControl != -1){
                        	puts("La lista se ordeno correctamente");
                        }else{
                        	puts("ERROR ! No pudo ordenarse la lista");
                        }
                	}else{
                		puts("Error ! Lista Vacia");
                		puts("Deberias cargar al menos un archivo");
                	}

                break;
                case 8:
                	if(flagFileLoaded == 0){
                    	validationControl = controller_saveAsText("data.csv", listaEmpleados);
                        if(validationControl != -1){
                        	puts("Se guardo el archivo con exito");
                        	flagFileSaved = 0;
                        }else{
                        	puts("ERROR ! No pudo guardarse el archivo");
                        }
                	}else{
                		puts("Error ! Lista Vacia");
                		puts("Deberias cargar al menos un archivo");
                	}

                break;
                case 9:
                	if(flagFileLoaded == 0){
                       	validationControl = controller_saveAsBinary("data.bin", listaEmpleados);
                            if(validationControl != -1){
                            	puts("Se guardo el archivo con exito");
                            	flagFileSaved = 0;
                            }else{
                            	puts("ERROR ! No pudo guardarse el archivo");
                            }
                	}else{
                		puts("Error ! Lista Vacia");
                		puts("Deberias cargar al menos un archivo");
                	}
                break;
                case 10:
                	if(flagFileLoaded == 0){
                		puts("Hay datos sin guardar en el sistema.");
                		puts("Desea continuar sin guardar los datos?");
                		optionConfirmOperation = IngresarEntero("Ingrese la respuesta: 1. Si 2.No\n", &pValidation);
                	}
                	if(pValidation != -1){
                    	puts("Saliendo del sistema");
                    	exit(0);
                	}else{
                		puts("Cancelando salida...");
                	}

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

