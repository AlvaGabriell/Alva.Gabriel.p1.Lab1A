#ifndef MARCAS_H_INCLUDED
#define MARCAS_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[20];
}eMarca;

#endif // MARCAS_H_INCLUDED
/** \brief muestra 1 sola estructura
 *
 * \param marca eMarca estructura a mostrar
 * \return void
 *
 */
void mostrarMarca(eMarca marca);
/** \brief carga todas las estructuras marca
 *
 * \param marcas[] eMarca estructura a mostrar
 * \param tamM int  tamaño estrucutra
 * \return int retorna 0 si hubo error
 *
 */
int mostrarMarcas(eMarca marcas[],int tamM);
/** \brief carga descripcion marca
 *
 * \param marcas[] eMarca estructura que pide para remplazar descripcion
 * \param tamM int  tamaño estructura
 * \param idMarca int   id que busca para remplazar estructura
 * \param descripcion[] char retorna la descripcion
 * \return int 0 si hubo error
 *
 */
int cargarDescripcionMarca(eMarca marcas[],int tamM,int idMarca,char descripcion[]);
/** \brief busca marcas por id
 *
 * \param marcas[] eMarca marcas donde busca id
 * \param tamM int tamaño estructura
 * \param id id que busca para localizar el id
 * \return int -1 si hubo error.
 *
 */
int buscarMarcasId(eMarca marcas[],int tamM,int id);
