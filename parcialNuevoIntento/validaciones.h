#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED
#include "autos.h"
#include "servicios.h"
#include "clientes.h"

#endif // VALIDACIONES_H_INCLUDED
/** \brief muestra menu
 *
 * \return int retorna opcion
 *
 */
int menu();
/** \brief muestra sub menu modificar
 *
 * \return int retorna opcion
 *
 */
int subMenu();
/** \brief pido entero
 *
 * \param entero int* devuelvo entero
 * \param rango1 int rango minimo
 * \param rango2 int rango maximo
 * \param mensaje1[] char   mensaje1
 * \param mensaje2[] char   mensaje2
 * \return int
 *
 */
int pedirEntero(int* entero, int rango1, int rango2,char mensaje1[],char mensaje2[]);
/** \brief pido caracter
 *
 * \param letra char* retorno letra
 * \param rango1 char rango letra
 * \param rango2 char   rango letra
 * \param mensaje1[] char mensaje 1
 * \param mensaje2[] char   mensaje2
 * \return int
 *
 */
int pedirChar(char* letra, char rango1, char rango2,char mensaje1[],char mensaje2[]);
/** \brief valida la patente de un auto
 *
 * \param entero int* id que recibe
 * \param autos[] eAuto donde busca el id
 * \param tamA int tamaño de estructura
 * \return int lo que retorna
 *
 */
int validarPatenteAuto(int* entero, eAuto autos[],int tamA);
int validarIdServicio(int* entero, eServicio servicios[],int tamS);
int validarFecha(int dia,int mes,int anio);
int pedirNombre(char* cliente,char mensaje1[],char mensaje2[]);
int pedirEnteroSinRango(int* entero,char mensaje1[]);
int validarEnteroIdCliente(int num,eCliente clientes[],int tamCLI);
