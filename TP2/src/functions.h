/*
 * functions.h
 *
 *  Created on: 15 Oct 2021
 *      Author: Lauta
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAM 1000

/// @fn int IngresarEntero(char[], int, int*)
/// @brief
/// recibe un numero, evalua si es un numero y resta intentos hasta que el contador llega a 0
/// el usuario tiene hasta 4 intentos antes de que no tenga mas oportunidades de ingresar
/// datos erroneos
/// @pre
/// @post
/// @param mensaje
/// @param num
/// @param validacion
/// @return
int IngresarEntero(char mensaje[], int* validacion);

/// @fn void getString(char[], char[], int, int*)
/// @brief
/// obtiene el mensaje que ingresa el usuario
/// llama a NormalizarString para generalizar los ingresos
/// devuelve un valor que oscila entre 0 y -1 para control de validaciones
/// @pre
/// @post
/// @param cadena
/// @param mensaje
/// @param tam
/// @param validacion
void getString(char cadena[], char mensaje[], int tam, int* validacion);

//Muestra el menu de opciones principal
//Retorna 0 si esta ok, -1 si hubo error
int MostrarMenu();

//Muestra el sub menu de opciones para modificaciones
//devuelve la validación por punteros : 0 esta ok, -1 hay error
// Retorna la opcion elegida
int MostrarSubMenuABM(int* pValidacion);

//Muestra el sub menu de opciones para los informes
//devuelve la validación por punteros : 0 esta ok, -1 hay error
// Retorna la opcion elegida
int MostrarSubMenuInformes(int *pValidacion);

//Recibe el mensaje a mostrar en pantalla
// Por punteros, devuelve la validacion.0 si ds un numero y -1 si no
// retorna el numero ingresado
float IngresarFlotante(char mensaje[], int* validacion);

/// @fn void NormalizarString(char[])
/// @brief
/// La primer posicion del string, la convierte en mayusculas y las demas letras en minusculas
/// @pre
/// @post
/// @param string
void NormalizarString(char string[]);

/// @fn void getString(char[], char[], int, int*)
/// @brief
/// obtiene el mensaje que ingresa el usuario
/// llama a NormalizarString para generalizar los ingresos
/// devuelve un valor que oscila entre 0 y -1 para control de validaciones
/// @pre
/// @post
/// @param cadena
/// @param mensaje
/// @param tam
/// @param validacion
void getString(char cadena[], char mensaje[], int tam, int* validacion);

/// @fn void ValidarString(string[])
/// @brief
/// Recibe una cadena como parametro y evalua si todos los caracteres
/// son de tipo char
/// @pre
/// @post
/// @param string[] --> recibe la cadena a evaluar
/// Retorna -1 si hay error / Retorna 0 si esta ok.
int ValidarString(char string[]);

/// @fn void ValidarEntero(string[])
/// @brief
/// Recibe una cadena como parametro y evalua si todos los caracteres
/// son numeros
/// @pre
/// @post
/// @param string[] --> recibe la cadena a evaluar
/// Retorna -1 si hay error / Retorna 0 si esta ok.
int ValidarNumero(char number[]);

#endif /* FUNCTIONS_H_ */
