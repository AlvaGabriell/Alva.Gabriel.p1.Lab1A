#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "marcas.h"
#include "colores.h"
#include "servicios.h"
#include "autos.h"
#include "fechas.h"
#include "trabajos.h"
#include "clientes.h"
#include "hardCodearDatos.h"
#define TAM_M 4
#define TAM_C 5
#define TAM_S 4
#define TAM_A 100
#define TAM_T 100
#define TAM_CL 100
int main()
{
    //int flagTrabajo=0;
    int flag=0;
    int idAuto=0;
    int idTrabajo=0;
    int idCliente=100;
    char seguir='n';
    eCliente clientes[TAM_CL];
    eAuto autos[TAM_A];
    eTrabajo trabajos[TAM_T];
    eMarca marcas[TAM_M]=
    {
        {1000, "Renault"},
        {1001, "Ford"},
        {1002, "Fiat"},
        {1003, "Peugeot"},
    };

    eColor colores[TAM_C]=
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Rojo"},
        {5003, "Gris"},
        {5004, "Azul"}
    };
    eServicio servicios[TAM_S]=
    {
        {20000, "Lavado",450},
        {20001, "Pulido",500},
        {20002, "Encerado",600},
        {20003, "Completo",900},
    };
    inicializarAuto(autos,TAM_A);
    inicializarTrabajo(trabajos,TAM_T);
    inicializarCliente(clientes,TAM_CL);
    harCodearTrab(trabajos,TAM_T,8,&idTrabajo);
    harcodearAutos(autos,TAM_A,8,&idAuto);
    do
    {
        switch(menu())
        {
            case 1:
                altaCliente(clientes,TAM_CL,&idCliente);
                altaAuto(autos,TAM_A,colores,TAM_C,marcas,TAM_M,clientes,TAM_CL,&idAuto);
                flag++;
                break;
            case 2:
                /*if(flag!=0)
                {*/
                    modificarAutos(autos,TAM_A,marcas,TAM_M,colores,TAM_C,clientes,TAM_CL);
                /*}
                else
                {
                    printf("Error, debes ingresar datos primero\n");
                }*/
                break;
            case 3:
                /*if(flag!=0)
                {*/
                    darDeBajaAuto(autos,TAM_A,marcas,TAM_M,colores,TAM_C,clientes,TAM_CL);
                    flag--;
                /*}
                else
                {
                    printf("Error, debes ingresar datos primero\n");
                }*/
                break;
            case 4:
                /*if(flag!=0)
                {*/
                    ordenarAutos(autos,TAM_A,marcas,TAM_M);
                    mostrarAutos(autos,TAM_A,colores,TAM_C,marcas,TAM_M,clientes,TAM_CL);

                /*}
                else
                {
                    printf("Error, debes ingresar datos primero\n");
                }*/
                break;
            case 5:
                mostrarMarcas(marcas,TAM_M);
                break;
            case 6:
                 mostrarColores(colores,TAM_C);
                break;
            case 7:
                mostrarServicios(servicios,TAM_S);
                break;
            case 8:
                /*if(flag!=0)
                {*/
                    altaTrabajo(trabajos,TAM_T,servicios,TAM_S,autos,TAM_A,colores,TAM_C,marcas,TAM_M,clientes,TAM_CL,&idTrabajo);
                   //flagTrabajo=1;
                /*}
                else
                {
                    printf("Error, debes ingresar datos de un auto primero\n");
                }*/
                break;
            case 9:
                /*if(flagTrabajo)
                {*/
                    mostrarTrabajos(trabajos,TAM_T,servicios,TAM_S);

                /*}
                else
                {
                    printf("Error, debes ingresar datos de un auto primero\n");
                }*/
                break;
                case 10:
                /*if(flag!=0&&flagTrabajo!=0)
                {*/
                    informePedirAutoYmostrarTrab(trabajos,TAM_T,autos,TAM_A,colores,TAM_C,marcas,TAM_M,servicios,TAM_S,clientes,TAM_CL);
                /*}
                else
                {
                    printf("Error, debes ingresar datos de un auto y luego acceder a un servicio\n");
                }*/
                break;
                case 11:
                /*if(flag!=0)
                {*/
                    informeMostrarAutosMarcaSeleccionadA(autos,TAM_A,marcas,TAM_M,colores,TAM_C,clientes,TAM_CL);
                /*}
                else
                {
                    printf("Error, debes ingresar datos de un auto primero \n");
                }*/
                break;
                case 12:
                /*if(flag!=0)
                {*/
                    informarAutosCadaMarca(marcas,TAM_M,autos,TAM_A,colores,TAM_C,clientes,TAM_CL);
                /*}
                else
                {
                    printf("Error, debes ingresar datos de un auto primero \n");
                }*/
                break;
                case 13:
                /*if(flag!=0)
                {*/
                    informarAutosporColorYMarca(marcas,TAM_M,autos,TAM_A,colores,TAM_C);
                /*}
                else
                {
                    printf("Error, debes ingresar datos de un auto primero \n");
                }*/
                break;
                case 14:
                /*if(flag!=0)
                {*/
                    marcasMasUsadas(marcas,TAM_M,autos,TAM_A);
                /*}
                else
                {
                    printf("Error, debes ingresar datos de un auto primero \n");
                }*/
                break;
                case 15:
                /*if(flag!=0)
                {*/
                   informePedirAutoYmostrarTrab(trabajos,TAM_T,autos,TAM_A,colores,TAM_C,marcas,TAM_M,servicios,TAM_S,clientes,TAM_CL);
                /*}
                else
                {
                    printf("Error, debes ingresar datos de un auto primero \n");
                }*/
                break;
                case 16:
                /*if(flag!=0)
                {*/
                   informePedirAutoYmostrarImporte(autos,TAM_A,trabajos,TAM_T,colores,TAM_C,marcas,TAM_M,servicios,TAM_S,clientes,TAM_CL);
                /*}
                else
                {
                    printf("Error, debes ingresar datos de un auto primero \n");
                }*/
                break;
            case 20:
                seguir='s';
                break;
            default:
                printf("Opcion invalida\n");
                fflush(stdin);
        }
        system("pause");

    }while(seguir=='n');
    return 0;
}
