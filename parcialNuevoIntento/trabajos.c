#include <stdio.h>
#include <stdlib.h>
#include "trabajos.h"
#include "servicios.h"
#include "autos.h"
#include "validaciones.h"
#include "fechas.h"
int inicializarTrabajo(eTrabajo trabajos[],int tamT)
{
    int todoOk=0;
    if(trabajos!=NULL&&tamT>0)
    {
        for(int i=0;i<tamT;i++)
        {
            trabajos[i].isEmpty=1;
        }
    todoOk=1;
    }
    return todoOk;
}
int buscarLugarTrabajo(eTrabajo trabajos[],int tamT)
{
    int indice=-1;
    if(trabajos!=NULL&&tamT>0)
    {
        for(int i=0;i<tamT;i++)
        {
            if(trabajos[i].isEmpty==1)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}


int altaTrabajo(eTrabajo trabajos[],int tamT,eServicio servicios[],int tamS,eAuto autos[],int tamA,
                eColor colores[],int tamC,eMarca marcas[],int tamM,eCliente clientes[],int tamCLI,int* pId)
{


    int todoOk=0;
    eTrabajo auxTrabajo;
    int indice;
    if(trabajos!=NULL&&tamT>0)
    {
        system("cls");
        printf("     ***** Alta trabajos *******\n");
        indice=buscarLugarTrabajo(trabajos,tamT);
        if(indice==-1)
        {
            printf("No hay lugar en el sistema.\n");
        }
        else
        {
            auxTrabajo.id=*pId;
            mostrarAutos(autos,tamA,colores,tamC,marcas,tamM,clientes,tamCLI);
            pedirPatente(&auxTrabajo.idPatente,autos,tamA);
            mostrarServicios(servicios,tamS);
            pedirIdServicio(&auxTrabajo.idServicio,servicios,tamS);
            pedirFecha(&auxTrabajo.fecha.dia,&auxTrabajo.fecha.mes,&auxTrabajo.fecha.anio);
            auxTrabajo.isEmpty=0;
            trabajos[indice]=auxTrabajo;


            (*pId)++;
            todoOk=1;
        }
    }
    return todoOk;
}

void mostrarTrabajo(eTrabajo trabajo,eServicio servicios[],int tamS)
{
    char descServicio[25];
    cargarDescripcionServicio(servicios,tamS,trabajo.idServicio,descServicio);
    printf("    %d               %d                  %10s            %02d/%02d/%d\n",
    trabajo.id,
    trabajo.idPatente,
    descServicio,
    trabajo.fecha.dia,
    trabajo.fecha.mes,
    trabajo.fecha.anio);
}
int mostrarTrabajos(eTrabajo trabajos[],int tamT,eServicio servicios[],int tamS)
{
    int todoOk=0;
    if(trabajos!=NULL&&tamT>0)
    {
        system("cls");
        printf("            ***Listado trabajos ****\n");
        printf("    id            patente                servicio              fecha         \n");
        printf("--------------------------------------------------------------------\n");
        for(int i=0;i<tamT;i++)
        {
            if(trabajos[i].isEmpty==0)
            {
               mostrarTrabajo(trabajos[i],servicios,tamS);
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarTrabajoId(eTrabajo trabajos[],int tamT,int id)
{
    int indice=-1;
    if(trabajos!=NULL&&tamT>0)
    {
        for(int i=0; i<tamT; i++)
        {
            if(trabajos[i].isEmpty==0 && trabajos[i].id==id)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int informePedirAutoYmostrarTrab(eTrabajo trabajos[],int tamT,eAuto autos[], int tamA,eColor colores[],int tamC,eMarca marcas[],int tamM,
                                 eServicio servicios[],int tamS,eCliente clientes[],int tamCLI)
{
    int todoOk=0;
    int idAuto;
    int indice;
    int flag=1;
    if(trabajos!=NULL&&tamT>0&&autos!=NULL&&tamA>0&&colores!=NULL&&tamC>0&&marcas!=NULL&&tamM>0)
    {
        mostrarAutos(autos,tamA,colores,tamC,marcas,tamM,clientes,tamCLI);
        printf("Ingrese id patente del auto.\n");
        scanf("%d",&idAuto);
        indice=buscarAutosId(autos,tamA,idAuto);
        while(indice==-1)
        {
            printf("Error, ingrese patente nuevamente.\n");
            scanf("%d",&idAuto);
            indice=buscarAutosId(autos,tamA,idAuto);
        }
        system("cls");
        printf("                ***Listado de servicios por id patente***\n\n");
        printf("    id            patente                servicio              fecha         \n");
        printf("--------------------------------------------------------------------\n");
        for(int i=0;i<tamT;i++)
        {
            if(trabajos[i].isEmpty==0&&trabajos[i].idPatente==indice)
            {
                mostrarTrabajo(trabajos[i],servicios,tamS);
                todoOk=1;
                flag=0;
            }
        }
    }
    if(flag)
    {
        printf("No se encuentran servicios de la patente indicada...\n");

    }
    return todoOk;
}

int informePedirAutoYmostrarImporte(eAuto autos[],int tamA,eTrabajo trabajos[],int tamT,eColor colores[],int tamC,eMarca marcas[],int tamM,
                                    eServicio servicios[],int tamS,eCliente clientes[],int tamCLI)
{
    int idAuto;
    int todoOk=0;
    int indice;
    int acumImporte=0;

    if(autos!=NULL&&tamA>0&&trabajos!=NULL&&tamT>0&&colores!=NULL&&tamC>0&&marcas!=NULL&&tamM>0&&servicios!=NULL&&tamS>0)
    {
        mostrarAutos(autos,tamA,colores,tamC,marcas,tamM,clientes,tamCLI);
        printf("Ingrese id \n");
        scanf("%d",&idAuto);
        indice=buscarAutosId(autos,tamA,idAuto);
        if(indice==-1)
        {
            printf("no existe un auto con el id ingresado. \n");
        }
        else
        {
            for(int i=0;i<tamT;i++)
            {
                for(int j=0;j<tamS;j++)
                {
                    if(trabajos[i].idPatente==indice&&servicios[j].id==trabajos[i].idServicio)
                    {
                        acumImporte+=servicios[j].precio;
                    }
                }
            }
        }
        printf(" importe acumulado : %d\n",acumImporte);
        todoOk=1;
    }
    return todoOk;
}

