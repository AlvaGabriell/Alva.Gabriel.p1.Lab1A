#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

#endif // FECHAS_H_INCLUDED
/** \brief pido fecha
 *
 * \param dia int* dia
 * \param mes int*  mes
 * \param anio int* año
 * \return int retorna 0 si hubo error.
 *
 */
int pedirFecha(int* dia,int* mes,int* anio);
