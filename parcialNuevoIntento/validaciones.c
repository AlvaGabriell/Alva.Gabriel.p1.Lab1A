#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include "autos.h"
#include "servicios.h"
#include <string.h>
#include <ctype.h>
#include "clientes.h"
int menu()
{
    int opcion;
    system("cls");
    printf("        *******Menu de opciones*******\n\n");
    printf("    1-  Alta auto.\n");
    printf("    2-  Modificar auto.\n");
    printf("    3-  Baja auto.\n");
    printf("    4-  Listar autos.\n");
    printf("    5-  Listar marcas.\n");
    printf("    6-  Listar colores.\n");
    printf("    7-  Listar servicios.\n");
    printf("    8-  Alta trabajo.\n");
    printf("    9-  Listar trabajos.\n");
    printf("   10-  Informe servicios por id patente.\n");
    printf("   11-  Informe autos por id marca.\n");
    printf("   12-  Informe autos por id marca.\n");
    printf("   13-  Informe autos por id marca y color seleccionado.\n");
    printf("   14-  informe marca mas elegida por clientes.\n");
    printf("   15-  informe mostrar servicios segun auto ingresado.\n");
    printf("   16-  informe mostrar suma importes que se le adjunta al auto.\n");
    printf("   20-  Salir.\n");
    scanf("%d",&opcion);

    return opcion;
}
int subMenu()
{
    int opcion;
    system("cls");
    printf("        *******Menu de opciones*******\n\n");
    printf("    1-  Modificar color.\n");
    printf("    2-  Modificar modificar Marca.\n");
    scanf("%d",&opcion);

    return opcion;
}

int pedirEntero(int* entero, int rango1, int rango2,char mensaje1[],char mensaje2[])
{
    int auxInt;
    int todoOk;
    if(entero!=NULL)
    {
        printf(mensaje1);
        scanf("%d",&auxInt);
        while(auxInt<rango1||auxInt>rango2)
        {
            printf(mensaje2);
            scanf("%d",&auxInt);
        }
        *entero=auxInt;
        todoOk=1;
    }
    return todoOk;
}
int pedirChar(char* letra, char rango1, char rango2,char mensaje1[],char mensaje2[])
{
    char auxChar;
    int todoOk;
    if(letra!=NULL)
    {
        printf(mensaje1);
        fflush(stdin);
        scanf("%c",&auxChar);
        while(auxChar!=rango1&&auxChar!=rango2)
        {
            printf(mensaje2);
            fflush(stdin);
            scanf("%c",&auxChar);
        }
        *letra=auxChar;
        todoOk=1;
    }
    return todoOk;
}

int validarPatenteAuto(int* entero, eAuto autos[],int tamA)
{
    int todoOk=0;
    if(autos!=NULL&&tamA>0)
    {
        for(int i=0;i<tamA;i++)
        {
            if(autos[i].isEmpty==0&&autos[i].id==*entero)
            {
                todoOk=1;
                break;
            }
        }
    }
    return todoOk;
}


int validarIdServicio(int* entero, eServicio servicios[],int tamS)
{
    int todoOk=0;
    if(servicios!=NULL&&tamS>0)
    {
        for(int i=0;i<tamS;i++)
        {
            if(servicios[i].id==*entero)
            {
                todoOk=1;
                break;
            }
        }
    }
    return todoOk;
}
int validarFecha(int dia,int mes,int anio)
{
    int todoOk=1;
    if((dia <=0&&dia>31)||(mes<1&&mes>12)||(anio<2021))
    {
        todoOk=-1;
    }

    return todoOk;
}

int pedirNombre(char* cliente,char mensaje1[],char mensaje2[])
{
    int todoOk=0;
    char auxCadena[51];
    if(cliente!=NULL)
    {
        printf("%s",mensaje1);
        fflush(stdin);
        gets(auxCadena);
        strlwr(auxCadena);
        while(strlen(auxCadena)<2||strlen(auxCadena)>51)
        {
            printf("%s",mensaje2);
            fflush(stdin);
            gets(auxCadena);
        }
        auxCadena[0]=toupper(auxCadena[0]);
        strcpy(cliente,auxCadena);
        todoOk=1;
    }
    return todoOk;
}


int pedirEnteroSinRango(int* entero,char mensaje1[])
{
    int auxInt;
    int todoOk;
    if(entero!=NULL)
    {
        printf(mensaje1);
        scanf("%d",&auxInt);
        *entero=auxInt;
        todoOk=1;
    }
    return todoOk;
}

int validarEnteroIdCliente(int num,eCliente clientes[],int tamCLI)
{
    int indice=-1;
    if(clientes!=NULL&&tamCLI>0)
    {
        for(int i=0; i<tamCLI; i++)
        {
            if(clientes[i].isEmpty==0&&clientes[i].id==num)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

