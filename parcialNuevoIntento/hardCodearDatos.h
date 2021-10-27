#ifndef HARDCODEARDATOS_H_INCLUDED
#define HARDCODEARDATOS_H_INCLUDED
#include "trabajos.h"
#include "fechas.h"

#endif // HARDCODEARDATOS_H_INCLUDED
/** \brief cargar datos
 *
 * \param trabajos[] eTrabajo estructura que carga datos
 * \param tamT int tama�o estructura
 * \param cantidad int cantidad a cargar
 * \param id int* tama�o a cargar
 * \return int retorna 0 si hubo error
 *
 */
int harCodearTrab(eTrabajo trabajos[], int tamT, int cantidad, int* id);
/** \brief
 *
 * \param autos[] eAuto    estructura que carga datos
 * \param tamA int      tama�o estructura
 * \param cantidad int  cantidad a cargar
 * \param pIdAutos int* tama�o a cargar
 * \return int  retorna 0 si hubo error
 *
 */
int harcodearAutos(eAuto autos[], int tamA, int cantidad, int* pIdAutos);
