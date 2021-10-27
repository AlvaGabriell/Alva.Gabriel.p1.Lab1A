#include "clientes.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int inicializarCliente(eCliente clientes[],int tamCLI)
{
    int todoOk=0;
    if(clientes!=NULL&&tamCLI>0)
    {
        for(int i=0;i<tamCLI;i++)
        {
            clientes[i].isEmpty=1;
        }
    todoOk=1;
    }
    return todoOk;
}
int buscarLugarCliente(eCliente clientes[],int tamCLI)
{
    int indice=-1;
    if(clientes!=NULL&&tamCLI>0)
    {
        for(int i=0;i<tamCLI;i++)
        {
            if(clientes[i].isEmpty==1)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int buscarclienteId(eCliente clientes[],int tamCLI,int id)
{
    int indice=-1;
    if(clientes!=NULL&&tamCLI>0)
    {
        for(int i=0; i<tamCLI; i++)
        {
            if(clientes[i].isEmpty==0 && clientes[i].id==id)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int altaCliente(eCliente clientes[],int tamCLI,int* pId)
{
    int indice=-1;
    int todoOk=0;
    eCliente auxCliente;

    if(clientes!=NULL&&tamCLI>0)
    {
        system("cls");
        printf("     ***** Alta clientes *******\n");
        indice=buscarLugarCliente(clientes,tamCLI);
        if(indice==-1)
        {
            printf("No hay lugar en el sistema.\n");
        }
        else
        {
            auxCliente.id=*pId;
            pedirNombre(auxCliente.nombre,"Ingrese nombre\n","Error al ingresar nombre, ingrese nuevamente.");
            pedirChar(&auxCliente.sexo,'f','m',"Ingrese sexo ( f / m )\n","Error,Ingrese sexo ( f / m )");
            auxCliente.isEmpty=0;
            clientes[indice]=auxCliente;
            (*pId)++;
            todoOk=1;
        }
    }
    return todoOk;
}


void mostrarCliente(eCliente cliente)
{
    printf("    %d            %10s          %c\n",
           cliente.id,
           cliente.nombre,
           cliente.sexo);
}

int mostrarClientes(eCliente clientes[],int tamCLI)
{
    int todoOk=0;
    if(clientes!=NULL&&tamCLI>0)
    {
        system("cls");
        printf("            ***Listado clientes ****\n");
        printf("    id            nombre            sexo       \n");
        printf("----------------------------------------------------\n");
        for(int i=0;i<tamCLI;i++)
        {
            if(clientes[i].isEmpty==0)
            {
               mostrarCliente(clientes[i]);
            }
        }
        todoOk=1;
    }
    return todoOk;
}
int cargarDescripcionClientes(eCliente clientes[],int tamCL,int idCL,char descripcion[])
{
    int todoOk=0;
    if(clientes!=NULL&&tamCL>0&&descripcion!=NULL)
    {
        for(int i=0; i<tamCL; i++)
        {
            if(clientes[i].id==idCL)
            {
                strcpy(descripcion, clientes[i].nombre);
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;
}
