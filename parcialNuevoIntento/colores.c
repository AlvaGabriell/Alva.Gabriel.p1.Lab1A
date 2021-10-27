#include "colores.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void mostrarColor(eColor color)
{

    printf("    %d            %s\n",
           color.id,
           color.nombreColor
           );

}

int mostrarColores(eColor colores[],int tamC)
{
    int todoOk=0;
    if(colores!=NULL&&tamC>0)
    {
        system("cls");
        printf("***listado colores ****\n");
        printf("    id         color\n");
        printf("---------------------\n");
        for(int i=0;i<tamC;i++)
        {
            mostrarColor(colores[i]);
        }
        todoOk=1;
    }
    return todoOk;
}
int cargarDescripcionColores(eColor colores[],int tamC,int idColor,char descripcion[])
{
    int todoOk=0;
    if(colores!=NULL&&tamC>0&&descripcion!=NULL)
    {
        for(int i=0; i<tamC; i++)
        {
            if(colores[i].id==idColor)
            {
                strcpy(descripcion, colores[i].nombreColor);
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;
}
