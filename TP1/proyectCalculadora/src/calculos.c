#include "calculos.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

float PedirNumero(){
	float operando;

	printf("Ingrese el operando numero 1\n");
	scanf("%f", &operando);

	return operando;
}

int ValidarSigno(float numero){

	int signoNumero = 0;
	if(numero > 0){
		signoNumero = 1;
	}else if(numero < 0){
		signoNumero = -1;
	}
	printf("%d", signoNumero);
	return signoNumero;

}

int SelectorOperaciones(int opcionMin, int opcionMax, char mensaje[]){
	int operacion;

	do{
		printf("%s\n",mensaje);
		scanf("%d", &operacion);

	}while(operacion < opcionMin && operacion > opcionMax);

	return operacion;
}

void CalcularOperaciones(float signoNumero1, float signoNumero2,float primerNumero, float segundoNumero, float* resultadoSuma, float* resultadoResta, float* resultadoDivision, float* resultadoMultiplicacion, float* resultadoFactorealNumero1, float* resultadoFactorealNumero2){
	*resultadoSuma = SumarNumeros(primerNumero, segundoNumero);
	*resultadoResta = RestarNumeros(primerNumero, segundoNumero);

	if(signoNumero2 != 0){
		*resultadoDivision = DividirNumeros(primerNumero, segundoNumero);
	}
	*resultadoMultiplicacion = MultiplicarNumeros(primerNumero, segundoNumero);

	if(signoNumero1 != -1){
		*resultadoFactorealNumero1 = CalcularFactorial(primerNumero);
	}
	if(signoNumero2 != -1){
		*resultadoFactorealNumero2 = CalcularFactorial(segundoNumero);
	}

}

float SumarNumeros(float primerNumero, float segundoNumero){
	float resultado;

	resultado = primerNumero + segundoNumero;

	return resultado;
}

float RestarNumeros(float primerNumero, float segundoNumero){
	float resultado;

	resultado = primerNumero - segundoNumero;

	return resultado;
}

float DividirNumeros(float primerNumero, float segundoNumero){
	float resultado;

	resultado = primerNumero / segundoNumero;

	return resultado;
}

float MultiplicarNumeros(float primerNumero, float segundoNumero){
	float resultado;

	resultado = primerNumero * segundoNumero;

	return resultado;
}

float CalcularFactorial(float numero){
	float resultado;
	if(numero >= 0 && numero < 1){
		resultado = 1;
	}else{
		resultado = numero * CalcularFactorial(numero - 1);
	}
	return resultado;
}

void MostrarResultados(float primerNumero, float segundoNumero, float resultadoSuma, float resultadoResta, float resultadoDivision, float resultadoMultiplicacion, float resultadoFactorealNumero1, float resultadoFactorealNumero2, int signoPrimerNumero, int signoSegundoNumero){

	printf("El resultado de la suma de %.2f + %.2f es: %.2f \n",primerNumero, segundoNumero, resultadoSuma);
	printf("El resultado de la resta %.2f - %.2f es: %.2f \n", primerNumero, segundoNumero, resultadoResta);

	if(signoSegundoNumero != 0){
		printf("El resultado de la division de %.2f / %.2f es: %.2f \n", primerNumero, segundoNumero, resultadoDivision);
	}else{
		puts("No es posible dividir por cero");
	}
	printf("El resultado de la multiplicacion %.2f * %.2f: %.2f \n", primerNumero, segundoNumero, resultadoMultiplicacion);

	if(signoPrimerNumero != -1){
		printf("El resultado del factoreo de %.2f es: %.2f \n", primerNumero, resultadoFactorealNumero1);
	}else{
		printf("El numero %.2f no puede factorearse. es negativo", primerNumero);
	}

	if(signoSegundoNumero != -1){
		printf("El resultado del factoreo de %.2f es: %.2f \n", segundoNumero, resultadoFactorealNumero2);
	}else{
		printf("El numero %.2f no puede factorearse. es negativo",segundoNumero);
	}
}
void ResetearValores(float* primerNumero, float* segundoNumero,float* resultadoSuma, float* resultadoResta, float* resultadoDivision, float* resultadoMultiplicacion, float* resultadoFactorealNumero1, float* resultadoFactorealNumero2, int* signoPrimerNumero, int* signoSegundoNumero, int* contadorIngresados, int* flagCalculos){
	*primerNumero = 0;
	*segundoNumero = 0;
	*resultadoSuma = 0;
	*resultadoResta = 0;
	*resultadoDivision = 0;
	*resultadoMultiplicacion = 0;
	*resultadoFactorealNumero1 = 0;
	*resultadoFactorealNumero2 = 0;
	*signoPrimerNumero = 0;
	*signoSegundoNumero = 0;
	*contadorIngresados = 0;
	*flagCalculos = 0;
}
