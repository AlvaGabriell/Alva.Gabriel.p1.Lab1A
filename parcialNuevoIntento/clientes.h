#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
typedef struct
{
    int id;
    char nombre[25];
    char sexo;
    int isEmpty;

}eCliente;

#endif // CLIENTES_H_INCLUDED
/** \brief inicializa cliente
 *
 * \param clientes[] eCliente estructura que inicaliza
 * \param tamCLI int    tamaño estructura
 * \return int          retorna si hubo error
 *
 */
int inicializarCliente(eCliente clientes[],int tamCLI);




/** \brief busca lugar para cliente
 *
 * \param clientes[] eCliente estructura a buscar lugar
 * \param tamCLI int    tamaño estructura
 * \return int      -1 si hubo error
 *
 */
int buscarLugarCliente(eCliente clientes[],int tamCLI);



/** \brief busca clientes segun id ingresado
 *
 * \param clientes[] eCliente estructura donde busca el id
 * \param tamCLI int        tamaño estructura
 * \param id int        id que busca
 * \return int      retorna -1 si hubo error
 *
 */
int buscarclienteId(eCliente clientes[],int tamCLI,int id);



/** \brief carga los datos a la estructura
 *
 * \param clientes[] eCliente       estructura donde carga los datos
 * \param tamCLI int        tamaño estructura
 * \param pId int*          puntero id para incrementarlo
 * \return int          retorna si hubo error.
 *
 */
int altaCliente(eCliente clientes[],int tamCLI,int* pId);
/** \brief muestra una estructura cliente
 *
 * \param cliente eCliente  estructura a mostrar
 * \return void
 *
 */
void mostrarCliente(eCliente cliente);
/** \brief          muestra todas las estructuras clientes que esten ocupadas
 *
 * \param clientes[] eCliente       estructura que muestra
 * \param tamCLI int            tamaño estructura
 * \return int          retorna si hubo error.
 *
 */
int mostrarClientes(eCliente clientes[],int tamCLI);
/** \brief remplaza id por la descripcion del dato
 *
 * \param clientes[] eCliente   campo de esta estructura es remplazada.
 * \param tamCL int         tamaño estructura
 * \param idCL int              id el cual busca para remplazar la descripcion
 * \param descripcion[] char    retorna por referencia la descripcion
 * \return int          0 si hubo error.
 *
 */
int cargarDescripcionClientes(eCliente clientes[],int tamCL,int idCL,char descripcion[]);
