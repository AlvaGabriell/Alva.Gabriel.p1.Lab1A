#include "marcas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void mostrarMarca(eMarca marca)
{

    printf("    %d            %s\n",
           marca.id,
           marca.descripcion
           );

}

int mostrarMarcas(eMarca marcas[],int tamM)
{
    int todoOk=0;
    if(marcas!=NULL&&tamM>0)
    {
        printf("***listado marcas ****\n");
        printf("    id         marca\n");
        printf("---------------------\n");
        for(int i=0;i<tamM;i++)
        {
            mostrarMarca(marcas[i]);
        }
        todoOk=1;
    }
    return todoOk;
}
int cargarDescripcionMarca(eMarca marcas[],int tamM,int idMarca,char descripcion[])
{
    int todoOk=0;
    if(marcas!=NULL&&tamM>0&&descripcion!=NULL)
    {
        for(int i=0; i<tamM; i++)
        {
            if(marcas[i].id==idMarca)
            {
                strcpy(descripcion, marcas[i].descripcion);
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;
}


int buscarMarcasId(eMarca marcas[],int tamM,int id)
{
    int indice=-1;
    if(marcas!=NULL&&tamM>0)
    {
        for(int i=0; i<tamM; i++)
        {
            if(marcas[i].id==id)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

