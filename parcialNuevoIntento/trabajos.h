#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED
#include "fechas.h"
#include "colores.h"
#include "marcas.h"
#include "servicios.h"
#include "autos.h"
typedef struct
{
    int id;
    int idPatente;
    int idServicio;
    int isEmpty;
    eFecha fecha;
}eTrabajo;

#endif // TRABAJOS_H_INCLUDED
/** \brief inicializa trabajo
 *
 * \param trabajos[] eTrabajo estructura que inicializa
 * \param tamT int
 * \return int 0 si hubo error
 *
 */
int inicializarTrabajo(eTrabajo trabajos[],int tamT);
/** \brief carga datos a trabajo
 *
 * \param estructura que carga los datos
 * \param
 * \return  retorna 0 si hubo error
 *
 */
int altaTrabajo(eTrabajo trabajos[],int tamT,eServicio servicios[],int tamS,eAuto autos[],int tamA,
                eColor colores[],int tamC,eMarca marcas[],int tamM,eCliente clientes[],int tamCLI,int* pId);

/** \brief muestra todos los trabajos
 *
 * \param trabajo eTrabajo  estructura a mostrar
 * \param servicios[] eServicio referencia para mostrar servicios
 * \param tamS int  tamaño estructura
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo trabajo,eServicio servicios[],int tamS);
/** \brief muestra todos los trabajos
 *
 * \param trabajos[] eTrabajo estructura a mostrar
 * \param tamT int  tamaño estructura
 * \param servicios[] eServicio referencia para mostrar
 * \param tamS int tamaño estructura
 * \return int retorna 0 si hubo error
 *
 */
int mostrarTrabajos(eTrabajo trabajos[],int tamT,eServicio servicios[],int tamS);
/** \brief pide un auto y muestra trabajos realizados
 *
 * \param estructura donde busca
 * \param
 * \return retorna 0 si hubo error
 *
 */
int informePedirAutoYmostrarTrab(eTrabajo trabajos[],int tamT,eAuto autos[], int tamA,eColor colores[],int tamC,eMarca marcas[],int tamM,
                                 eServicio servicios[],int tamS,eCliente clientes[],int tamCLI);
/** \brief pide un auto y muestra importe
 *
 * \param estructura donde busca el auto
 * \param
 * \return retorna 0 si hubo error
 *
 */
int informePedirAutoYmostrarImporte(eAuto autos[],int tamA,eTrabajo trabajos[],int tamT,eColor colores[],int tamC,eMarca marcas[],int tamM,
                                    eServicio servicios[],int tamS,eCliente clientes[],int tamCLI);
