#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED
typedef struct
{
    int id;
    char nombreColor[20];
}eColor;



#endif // COLORES_H_INCLUDED
/** \brief carga descripcion colores
 *
 * \param colores[] eColor      estructura que busca remplazar descripcion
 * \param tamC int          tamaño estructura
 * \param idColor int   id que necesita para remplazar el campo
 * \param descripcion[] char    retorna por referencia descripcion
 * \return int  0 si hubo error
 *
 */
int cargarDescripcionColores(eColor colores[],int tamC,int idColor,char descripcion[]);
/** \brief muestra una estructura color
 *
 * \param color eColor estructura que muestra
 * \return void
 *
 */
void mostrarColor(eColor color);
/** \brief muestra todos las estructuras colroes
 *
 * \param colores[] eColor estructura a mostrar
 * \param tamC int  tamaño estructura
 * \return int  0 si hubo error.
 *
 */
int mostrarColores(eColor colores[],int tamC);
