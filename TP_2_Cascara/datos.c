#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "datos.h"

#define LARGO_NAME 50
/** \brief Pide un dato string por pantalla
 *
 * \param mensaje[] char Mensaje a mostrar para pedir el dato
 * \param dato[] char cadena donde se devuelve el dato
 * \return void
 *
 */
void pedirDato(char mensaje[],char dato[])
{
    printf("%s",mensaje);
	fflush(stdin);
    gets (dato);
}


/** \brief Verifica si toda la cadena dato es numerica
 *
 * \param dato[] char cadena que posee el dato a analizar
 * \return int 0: Invalido - 1: Valido
 *
 */
int esSoloNumero(char dato[])
{
    int i=0;
    int bValid=1;

    while(dato[i] != '\0')
   {
       if(dato[i] < '0' || dato[i] > '9')
           {
               bValid = 0;
               break;
           }
       i++;
   }

   return bValid;
}


/** \brief  Valida si el dato string ingresado es solo letras mayusculas y minusculas.
 *
 * \param dato[] char - Cadena a analizar
 * \return int 0: Invalido - 1: Valido
 *
 */
int esSoloLetras(char dato[])
{
   int i=0;
    int bValid=1;

    while(dato[i] != '\0')
   {
       if(dato[i]!=' ')
        {
           if(dato[i] < 'A' || (dato[i] > 'Z' && dato[i] < 'a') || dato[i] > 'z' ) // Comparo por ASCII
               {
                   bValid = 0;
                   break;
               }
        }
       i++;
   }

   return bValid;
}


/** \brief Pide un dato numerico valido, hasta que lo sea.
 *
 * \param mensaje[] char - Mensaje a mostrar para pedir el dato
 * \return int - El nro validado ingresado.
 *
 */
int pedirDatoNumericoValidado(char mensaje[])
{
    int valido;
	char dato[100]; //Cadena donde recibe el dato

    pedirDato(mensaje,dato);
    valido = esSoloNumero(dato);
	while(valido == 0)
    {
		pedirDato("ERROR: No es numerico. Por favor Reingresar: ", dato);
		valido = esSoloNumero(dato);
    }
	return atoi(dato);
}


/** \brief Pide un dato string por consola, validadnod la entrada para que sena solo letras
 *
 * \param mensaje[] char Mensaje a mostrar para pedir el dato
 * \param name[] char Dato devuelto como estring de 50
 * \return void
 *
 */
void pedirDatoSoloLetrasValido(char mensaje[], char cString[])
{
	int valido;
	char dato[200]; //Cadena donde recibe el dato

    pedirDato(mensaje,dato);
    valido = esSoloLetras(dato);
	while(valido == 0)
    {
		pedirDato("ERROR: Deben ser solo letras. Por favor Reingresar: ", dato);
		valido = esSoloLetras(dato);
    }
	strncpy(cString,dato,LARGO_NAME);

	if(strlen(dato)>=50)
        cString[49] = '\0';  //Para evitar perder el final de la cadena cuando el nombre ingresado es mayor a lo esperado.
}

/** \brief Pide la respuesta y la espera en una letra
 *
 * \param mensaje[] char Mensaje con el cual pide la respuesta
 * \return char Letra de la respuesta
 *
 */
char pedirRespuesta(char mensaje[])
{
    char respuesta;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&respuesta);

    return respuesta;
}

