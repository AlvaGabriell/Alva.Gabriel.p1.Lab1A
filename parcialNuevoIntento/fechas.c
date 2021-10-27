#include "fechas.h"
#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
int pedirFecha(int* dia,int* mes,int* anio)
{
    int todoOk=0;
    if(dia!=NULL&&mes!=NULL&&anio!=NULL)
    {
        int auxDia;
        int auxMes;
        int auxAnio;
        printf("Ingrese fecha :\n");
        scanf("%d/%d/%d",&auxDia,&auxMes,&auxAnio);
        while(validarFecha(auxDia,auxMes,auxAnio)==-1)
        {
            printf("Error, Ingrese fecha correcta o de este año en adelante.:\n");
            scanf("%d/%d/%d",&auxDia,&auxMes,&auxAnio);
        }
        *dia=auxDia;
        *mes=auxMes;
        *anio=auxAnio;
        todoOk=1;
    }
    return todoOk;
}
