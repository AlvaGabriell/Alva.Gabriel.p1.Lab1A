#ifndef HARDCODEARDATOS_H_INCLUDED
#define HARDCODEARDATOS_H_INCLUDED
#include "trabajos.h"
#include "fechas.h"

#endif // HARDCODEARDATOS_H_INCLUDED
/** \brief cargar datos
 *
 * \param trabajos[] eTrabajo estructura que carga datos
 * \param tamT int tamaño estructura
 * \param cantidad int cantidad a cargar
 * \param id int* tamaño a cargar
 * \return int retorna 0 si hubo error
 *
 */
int harCodearTrab(eTrabajo trabajos[], int tamT, int cantidad, int* id);
/** \brief
 *
 * \param autos[] eAuto    estructura que carga datos
 * \param tamA int      tamaño estructura
 * \param cantidad int  cantidad a cargar
 * \param pIdAutos int* tamaño a cargar
 * \return int  retorna 0 si hubo error
 *
 */
int harcodearAutos(eAuto autos[], int tamA, int cantidad, int* pIdAutos);
