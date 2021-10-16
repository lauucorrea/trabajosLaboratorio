/*
 ============================================================================
 Name        : proyectCalculadora.c
 Author      : Correa Lautaro
 Version     : 1.2
 Consigna    :
 Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
	a) Calcular la suma (A+B)
	b) Calcular la resta (A-B)
	c) Calcular la division (A/B)
	d) Calcular la multiplicacion (A*B)
	e) Calcular el factorial (A!)
4. Informar resultados
	a) “El resultado de A+B es: r”
	b) “El resultado de A-B es: r”
	c) “El resultado de A/B es: r” o “No es posible dividir por cero”
	d) “El resultado de A*B es: r”
	e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculos.h"


int main(void) {
	setbuf(stdout, NULL);
	int operacion;
	float primerNumero;
	float segundoNumero;
	int signoNumero1;
	int signoNumero2;

	float resultadoSuma = 0;
	float resultadoResta = 0;
	float resultadoMultiplicacion = 0;
	float resultadoDivision = 0;
	float resultadoFactorealNumero1 = 0;
	float resultadoFactorealNumero2 = 0;

	int cantidadNumerosIngresados = 0;
	int flagCalculosRealizados = 0;

do{
	operacion =  SelectorOperaciones(1, 5, "Seleccione la operacion: \n 1.Ingresar primer operando\n 2.Ingresar segundo operando\n 3.Calcular operaciones\n 4.Informar resultados\n5.Salir\n");

	// si el valor elegido no corresponde al ingreso de numeros en el switch, y la cantidad de numeros ingresados es menor a 2
	//continue vuelve a repetir el bucle do while().

	if(cantidadNumerosIngresados <2 && (operacion !=1 && operacion !=2) ){
		puts("No podemos calcular operaciones hasta obtener ambos operandos\n");
		continue;
	}

	if(flagCalculosRealizados == 0 && operacion == 4){
		puts("No podemos mostrar resultados. Los calculos aun no se hicieron");
		continue;
	}
	switch(operacion){
	case 1:
		cantidadNumerosIngresados++;
		primerNumero = PedirNumero();
		signoNumero1 = ValidarSigno(primerNumero);
		break;
	case 2:
		cantidadNumerosIngresados++;
		segundoNumero = PedirNumero();
		signoNumero2 = ValidarSigno(segundoNumero);
		break;
	case 3:
		CalcularOperaciones(signoNumero1,signoNumero2, primerNumero,segundoNumero, &resultadoSuma, &resultadoResta, &resultadoDivision, &resultadoMultiplicacion, &resultadoFactorealNumero1, &resultadoFactorealNumero2);
		flagCalculosRealizados = 1;
		break;
	case 4:
		MostrarResultados(primerNumero, segundoNumero, resultadoSuma, resultadoResta, resultadoDivision, resultadoMultiplicacion, resultadoFactorealNumero1, resultadoFactorealNumero2, signoNumero1, signoNumero2);
		ResetearValores(&primerNumero, &segundoNumero, &resultadoSuma, &resultadoResta, &resultadoDivision, &resultadoMultiplicacion, &resultadoFactorealNumero1, &resultadoFactorealNumero2, &signoNumero1, &signoNumero2, &cantidadNumerosIngresados, &flagCalculosRealizados);
		break;
	}

}while(operacion !=5);

puts("Gracias por usar nuestra calculadora\n");

}
