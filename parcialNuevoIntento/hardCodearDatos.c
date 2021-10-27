#include "hardCodearDatos.h"
#include <stdio.h>
#include <stdlib.h>


int IdMarca[10]={1000, 1001, 1000, 1003, 1003, 1000, 1001, 1002, 1000, 1002};

int color[10]={5004, 5001, 5000, 5003, 5004, 5002, 5001, 5002, 5000, 5001};

char caja[10] = {'m','a','m','a','a','a','m','m','m','a'};

int harcodearAutos(eAuto autos[], int tamA, int cantidad, int* pIdAutos)
{
    int todoOk=0;
    if(autos!=NULL&&tamA>0&&cantidad>=0&&cantidad<=tamA && pIdAutos!=NULL)
    {
        for(int i=0; i<cantidad; i++)
        {
            autos[i].id= *pIdAutos;
            (*pIdAutos)++;
            autos[i].caja = caja[i];
            autos[i].idColor = color[i];
            autos[i].idMarca=IdMarca[i];
            autos[i].isEmpty=0;
            todoOk=1;
        }
    }
    return todoOk;
}


int autos[8]={0,1,5,4,4,2,8,0};

int idsServicio[8]={20001,20002,20001,20000,20003,20002,20001,20000};

eFecha fechas[8]={{5,12,1993},
                   {11,8,2015},
                   {25,10,2000},
                   {17,2,2001},
                   {15,3,2001},
                   {21,8,2000},
                   {31,12,2021},
                   {05,4,2002},
                   };


int idServicio[8]={100,101,105,104,107,108,109,110};
int harCodearTrab(eTrabajo trabajos[], int tamT, int cantidad, int* id)
{
    int todoOk=0;

	if(trabajos!=NULL && tamT>0 && cantidad>=0 && cantidad<=tamT && id!=NULL)
	{

		for(int i=0; i<cantidad; i++)
		{
			trabajos[i].id = *id;
			(*id)++;
            trabajos[i].idPatente = autos[i];
			trabajos[i].idServicio = idsServicio[i];
			trabajos[i].fecha = fechas[i];
			trabajos[i].isEmpty=0;
			todoOk=1;
		}
	}
	return todoOk;
}


