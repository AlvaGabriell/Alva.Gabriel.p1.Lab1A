#include "servicios.h"
#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include <string.h>

void mostrarServicio(eServicio servicio)
{

    printf("    %d      %10s      %d\n",
           servicio.id,
           servicio.descServicio,
           servicio.precio
           );

}

int mostrarServicios(eServicio servicios[],int tamS)
{
    int todoOk=0;
    if(servicios!=NULL&&tamS>0)
    {
        system("cls");
        printf("***listado servicios ****\n");
        printf("    id         servicio        precio\n");
        printf("---------------------\n");
        for(int i=0;i<tamS;i++)
        {
            mostrarServicio(servicios[i]);
        }
        todoOk=1;
    }
    return todoOk;
}


int pedirIdServicio(int* entero, eServicio servicios[],int tamS)
{
    int auxInt;
    int todoOk;
    if(servicios&&entero!=NULL&&tamS>0)
    {
        printf("Ingrese id patente : \n");
        scanf("%d",&auxInt);
        while(validarIdServicio(&auxInt,servicios,tamS)==0)
        {
           printf("Error ingrese id patente valido : \n");
            scanf("%d",&auxInt);
        }
        *entero=auxInt;
        todoOk=1;
    }
    return todoOk;
}

int cargarDescripcionServicio(eServicio servicios[],int tamS,int idServicio,char descripcion[])
{
    int todoOk=0;
    if(servicios!=NULL&&tamS>0&&descripcion!=NULL)
    {
        for(int i=0; i<tamS; i++)
        {
            if(servicios[i].id==idServicio)
            {
                strcpy(descripcion, servicios[i].descServicio);
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;
}
