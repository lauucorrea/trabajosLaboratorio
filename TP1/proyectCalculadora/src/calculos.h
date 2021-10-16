#ifndef CALCULOS_H_
#define CALCULOS_H_
/// @fn float PedirNumero()
/// @brief Funcion que devuelve el numero ingresados por el usuario
///
/// @pre
/// @post
float PedirNumero();


/// @fn int ValidarSigno(float)
/// @brief retorna el valor respectivo al signo del numero ingresado
/// -1 --> positivo
/// 0 --> cero
/// 1 --> positivo
///
/// @pre
/// @post
/// @param numero
/// @return signo del numero ingresado
int ValidarSigno(float numero);


/// @fn int SelectorOperaciones(void)
/// @brief La operacion elegida por el usuario se guarda en una variable del main
///
/// @param opcionMin --> primer dato valido del menu
/// @param opcionMax --> ultimo dato valido del menu
/// @param mensaje --> mensaje a mostrar para que el usuario elija correctamente
/// @return operacion elegida por el usuario
int SelectorOperaciones(int opcionMin, int opcionMax, char mensaje[]);


/// @fn void CalcularOperaciones(float, float, float, float, float*, float*, float*, float*, float*, float*)
/// @brief
///Recibe como paramentro los numeros ingresados, y los signos evaluados para calcular cada uno de los calculos pedidos por la consigna
/// a su vez, pasa con referencias los resultados para que no se pierdan datos
/// @pre
/// @post
/// @param signoNumero1 --> signo evaluado (negativo, cero , positivo)
/// @param signoNumero2 --> signo evaluado (negativo, cero , positivo)
/// @param primerNumero --> primer numero ingresado por el usuario
/// @param segundoNumero--> segundo numero ingresado por el usuario
/// @param resultadoSuma --> suma de dos numeros
/// @param resultadoResta --> resta de dos numeros
/// @param resultadoDivision --> division de dos numeros
/// @param resultadoMultiplicacion --> multiplicacion de dos numeros
/// @param resultadoFactorealNumero1 --> factoreo numero 1
/// @param resultadoFactorealNumero2 --> factoreo numero 2
void CalcularOperaciones(float signoNumero1, float signoNumero2,float primerNumero, float segundoNumero, float* resultadoSuma, float* resultadoResta, float* resultadoDivision, float* resultadoMultiplicacion, float* resultadoFactorealNumero1, float* resultadoFactorealNumero2);


/// @fn float SumarNumeros(int, int)
/// @brief suma los dos numeros ingresados por el usuario
///
/// @pre
/// @post
/// @param primerNumero --> numero ingresado por el usuario en PedirNumeros()
/// @param segundoNumero --> numero ingresado por el usuario en PedirNumeros()
/// @return --> devuelve el resultado de la suma
float SumarNumeros(float primerNumero, float segundoNumero);


/// @fn float RestarNumeros(float, float)
/// @brief resta los dos numeros ingresados por el usuario
///
/// @pre
/// @post
/// @param primerNumero --> numero ingresado por el usuario en PedirNumeros()
/// @param segundoNumero --> numero ingresado por el usuario en PedirNumeros()
/// @return --> devuelve el resultado de la resta
float RestarNumeros(float primerNumero, float segundoNumero);


/// @fn float DividirNumeros(flaot, float)
/// @brief divide los dos numeros ingresados por el usuario
///
/// @pre
/// @post
/// @param primerNumero  --> numero ingresado por el usuario en PedirNumeros()
/// @param segundoNumero --> numero ingresado por el usuario en PedirNumeros()
/// @return --> devuelve el resultado de la division
float DividirNumeros(float primerNumero, float segundoNumero);


/// @fn float MultiplicarNumeros(float, float)
/// @brief multiplica los dos numeros ingresados por el usuario
///
/// @pre
/// @post
/// @param primerNumero --> numero ingresado por el usuario en PedirNumeros()
/// @param segundoNumero --> numero ingresado por el usuario en PedirNumeros()
/// @return --> devuelve el resultado de la multiplicacion
float MultiplicarNumeros(float primerNumero, float segundoNumero);


/// @fn float CalcularFactorial(float)
/// @brief factorea el numero ingresado
/// @pre
/// @post
/// @param numero --> numero pasado por parametros en CalcularOperaciones()
/// @return --> devuelve el resultado del factoreo
float CalcularFactorial(float numero);



/// @fn void MostrarResultados(float, float, float, float, float, float, float, float)
/// @brief Muestra los resultados de los calculos realizados.
/// Se ejecuta cuando el usuario selecciona la opcion numero 4
/// dentro de esta misma funcion, se valida que los numeros a factorear no sean de valor negativo, asi como tambien el segundo numero no sea 0
/// para personalizar el mensaje a mostrar
/// @pre
/// @post
/// @param primerNumero --> primer numero ingresado
/// @param segundoNumero --> segundo numero ingresado
/// @param resultadoSuma --> resultado del calculo de la suma
/// @param resultadoResta --> resultado del calculo de la resta
/// @param resultadoDivision --> resultado del calculo de la division
/// @param resultadoMultiplicacion --> resultado del calculo de la multiplicacion
/// @param resultadoFactorealNumero1 --> resultado del calculo del factoreal numero 1
/// @param resultadoFactorealNumero2 --> resultado del calculo del factoreal numero 2
/// @param signoPrimerNumero --> signo del primer numero ingresado y validado por ValidarSigno()
/// @param signoSegundoNumero --> signo del segundo numero ingresado y validado por ValidarSigno()
void MostrarResultados(float primerNumero, float segundoNumero,float resultadoSuma, float resultadoResta, float resultadoDivision, float resultadoMultiplicacion, float resultadoFactorealNumero1, float resultadoFactorealNumero2, int signoPrimerNumero, int signoSegundoNumero);


void ResetearValores(float* primerNumero, float* segundoNumero,float* resultadoSuma, float* resultadoResta, float* resultadoDivision, float* resultadoMultiplicacion, float* resultadoFactorealNumero1, float* resultadoFactorealNumero2, int* signoPrimerNumero, int* signoSegundoNumero, int* contadorIngresados, int* flagCalculos);
#endif
