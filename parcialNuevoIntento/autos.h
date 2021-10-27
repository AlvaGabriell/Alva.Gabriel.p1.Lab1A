#ifndef AUTOS_H_INCLUDED
#define AUTOS_H_INCLUDED
#include "colores.h"
#include "marcas.h"
#include "clientes.h"
typedef struct
{
    int id;
    int idMarca;
    int idColor;
    char caja;
    int idNombre;
    int idCliente;
    int isEmpty;
}eAuto;
#endif // AUTOS_H_INCLUDED
/** \brief inicializa autos
 *
 * \param autos[] eAuto estructura que inicializa
 * \param tamA int    tamaño estructura
 * \return int   retorna si hubo error en 0
 *
 */
int inicializarAuto(eAuto autos[],int tamA);






/** \brief busca un lugar libre dentro de la estructura
 *
 * \param autos[] eAuto  estructura en la cual busca el lugar
 * \param tamA int     tamaño de la estructura
 * \return int         retorna -1 si hubo error
 *
 */
int buscarLugarAutoLibre(eAuto autos[],int tamA);





/** \brief carga los datos en la estructura
 *
 * \param autos[] eAuto    estructura donde se cargan los datos
 * \param tamA int          tamaño estructura
 * \param colores[] eColor      estructura de referencia a tomar colores en el id
 * \param tamC int              tamaño estructura
 * \param marcas[] eMarca       estructura de referencia a tomar marcas en el id
 * \param tamM int              tamaño estructura
 * \param clientes[] eCliente   estructura de referencia a tomar id nombre en el campo autos
 * \param tamCLI int            tamaño estructura
 * \param pId int*              retorna 0 si hubo error.
 * \return int
 *
 */
int altaAuto(eAuto autos[],int tamA,eColor colores[],int tamC,eMarca marcas[],int tamM,eCliente clientes[],int tamCLI,int* pId);







/** \brief  muestra una sola estructura
 *
 * \param autito eAuto  estructura que muestra
 * \param colores[] eColor  referencias para cargar descripciones y remplazar id
 * \param tamC int
 * \param marcas[] eMarca   referencias para cargar descripciones y remplazar id
 * \param tamM int
 * \param clientes[] eCliente   referencias para cargar descripciones y remplazar id
 * \param tamCLI int
 * \return void       no retorna nada
 *
 */
void mostrarAuto(eAuto autito, eColor colores[],int tamC,eMarca marcas[],int tamM,eCliente clientes[],int tamCLI);






/** \brief muestra todas las estructuras
 *
 * \param autos[] eAuto   estructura que muestra
 * \param tamA int
 * \param colores[] eColor          referencia para mostrar descripciones de color
 * \param tamC int
 * \param marcas[] eMarca           referencia para mostrar descripciones de marca
 * \param tamM int
 * \param clientes[] eCliente       referencia para mostrar descripciones de clientes
 * \param tamCLI int
 * \return int
 *
 */
int mostrarAutos(eAuto autos[],int tamA,eColor colores[],int tamC,eMarca marcas[],int tamM,eCliente clientes[],int tamCLI);








/** \brief                  modifica estructuras
 *
 * \param autos[] eAuto     esttructura a modificar
 * \param tamA int
 * \param marcas[] eMarca   estructura marca que modifica
 * \param tamM int
 * \param colores[] eColor  estructura color que modifica
 * \param tamC int
 * \param clientes[] eCliente   referencia para mostrar datos.
 * \param tamCLI int
 * \return int                  retorna 0 si hubo error.
 *
 */
int modificarAutos(eAuto autos[],int tamA, eMarca marcas[],int tamM,eColor colores[],int tamC,eCliente clientes[],int tamCLI);







/** \brief              dar de baja una estructura
 *
 * \param autos[] eAuto         estructura que da de baja por ingreso.
 * \param tamA int
 * \param marcas[] eMarca       referencia que muestra como marca
 * \param tamM int
 * \param colores[] eColor      referencia que muestra como color
 * \param tamC int
 * \param clientes[] eCliente   referencia que muestra clientes.
 * \param tamCLI int
 * \return int                  retorna 0 si hubo error.
 *
 */
int darDeBajaAuto(eAuto autos[],int tamA, eMarca marcas[],int tamM,eColor colores[],int tamC,eCliente clientes[],int tamCLI);




/** \brief pide id del auto
 *
 * \param entero int*   devuelve por referencia el dato
 * \param autos[] eAuto   estructura en la que busca pasar el dato
 * \param tamA int
 * \return int          retorna 0 si hubo error
 *
 */
int pedirPatente(int* entero, eAuto autos[],int tamA);






/** \brief busca en la estructura autos el id ingresado
 *
 * \param autos[] eAuto estructura en la que busca el dato
 * \param tamA int  tamaño de la estructura
 * \param id int dato que busca
 * \return int retorna -1 si hubo error
 *
 */
int buscarAutosId(eAuto autos[],int tamA,int id);






/** \brief              muestra autos segun la marca seleccionada
 *
 * \param autos[] eAuto     estructura donde busca la marca
 * \param tamA int
 * \param marcas[] eMarca    marca que se pide como referencia
 * \param tamM int
 * \param colores[] eColor   como referencia que mumestra colores del auto
 * \param tamC int
 * \param clientes[] eCliente   como referencia que muestra clientes del auto.
 * \param tamCLI int
 * \return int              retorna 0 o 1 si hubo error.
 *
 */
int informeMostrarAutosMarcaSeleccionadA(eAuto autos[],int tamA,eMarca marcas[],int tamM,eColor colores[],int tamC,eCliente clientes[],int tamCLI);






/** \brief muestra todos los autos ordenados por marca.
 *
 * \param marcas[] eMarca marca donde se ubica para mostrar los autos
 * \param tamM int  tamaño de la estructura marcas
 * \param autos[] eAuto     autos que se muestran segun la marca
 * \param tamA int             tamaño de la estructura autos
 * \param colores[] eColor    sirve como referencia para mostrar el color
 * \param tamC int              tamaño de la esturctura color
 * \param idMarca int           referencia para mostrar la marca
 * \param clientes[] eCliente   sirve como referencia para mostrar los clientes.
 * \param tamCLI int
 * \return int              retorna 0 si hubo error.
 *
 */
int mostrarAutosPorMarca(eMarca marcas[],int tamM,eAuto autos[],int tamA,eColor colores[],int tamC,int idMarca,eCliente clientes[],int tamCLI);




/** \brief informa la cantidad de autos que hay en cada marca.
 *
 * \param marcas[] eMarca   estructura donde busca las marcas
 * \param tamM int          tamaño de la estructura
 * \param autos[] eAuto     estructura donde busca los autos ingresados
 * \param tamA int          tamaño de la estructura autos
 * \param colores[] eColor  muestra los colores de los autos
 * \param tamC int          tamaño de la estructura color
 * \param clientes[] eCliente muestra los clientes
 * \param tamCLI int    tamaño de la estructura clientes
 * \return int              retorna 0 si hubo error.
 *
 */
int informarAutosCadaMarca(eMarca marcas[],int tamM,eAuto autos[],int tamA,eColor colores[],int tamC,eCliente clientes[],int tamCLI);





/** \brief ordena autos segun el criterio pedido, por marca y patente.
 *
 * \param autos[] eAuto         estructura a ordernar
 * \param tamA int              tamaño estructura
 * \param marcas[] eMarca        marcas de los autos mostradas
 * \param tamM int              tamaño de la estructura marca
 * \return int                  retorna 0 si hubo error.
 *
 */
int ordenarAutos(eAuto autos[],int tamA,eMarca marcas[],int tamM);


/** \brief informa autos segun el color y marca elegidos
 *
 * \param marcas[] eMarca   muestra las marcas
 * \param tamM int          tamaño de marcas
 * \param autos[] eAuto     muestra los autos
 * \param tamA int          tamaño de los autos
 * \param colores[] eColor   muestra colores
 * \param tamC int          tamaño de los colores
 * \return int              retorna 0 si hubo error.
 *
 */
int informarAutosporColorYMarca(eMarca marcas[],int tamM,eAuto autos[],int tamA,eColor colores[],int tamC);





/** \brief muestra la cantidad de marcas mas usadas
 *
 * \param
 * \param
 * \return retorna 0 si hubo error.
 *
 */

int marcasMasUsadas(eMarca marcas[],int tamM,eAuto autos[],int tamA);

