#include "autos.h"
#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "colores.h"
#include "marcas.h"
#include <string.h>
#include "trabajos.h"
#include "clientes.h"
int inicializarAuto(eAuto autos[],int tamA)
{
    int todoOk=0;
    if(autos!=NULL&&tamA>0)
    {
        for(int i=0;i<tamA;i++)
        {
            autos[i].isEmpty=1;
        }
    todoOk=1;
    }
    return todoOk;
}
int buscarLugarAutoLibre(eAuto autos[],int tamA)
{
    int indice=-1;
    if(autos!=NULL&&tamA>0)
    {
        for(int i=0;i<tamA;i++)
        {
            if(autos[i].isEmpty==1)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int altaAuto(eAuto autos[],int tamA,eColor colores[],int tamC,eMarca marcas[],int tamM,eCliente clientes[],int tamCLI,int* pId)
{
    int todoOk=0;
    eAuto auxAuto;
    int test;
    int indice;
    int num;
    if(autos!=NULL&&tamA>0)
    {
        system("cls");
        printf("     ***** Alta autos *******\n\n");
        indice=buscarLugarAutoLibre(autos,tamA);
        if(indice==-1)
        {
            printf("No hay lugar en el sistema.\n");
        }
        else
        {
            mostrarClientes(clientes,tamCLI);
            pedirEnteroSinRango(&num,"Ingrese id del nombre.\n");
            test=validarEnteroIdCliente(num,clientes,tamCLI);
            while(test==-1)
            {
                pedirEnteroSinRango(&num,"Ingrese id del nombre.\n");
                test=validarEnteroIdCliente(num,clientes,tamCLI);
            }
            auxAuto.id=*pId;
            mostrarMarcas(marcas,tamM);
            pedirEntero(&auxAuto.idMarca,1000,1003,"ingrese id marca\n","error, ingrese id marca nuevamente\n");
            mostrarColores(colores,tamC);
            pedirEntero(&auxAuto.idColor,5000,5004,"Ingrese id color\n","Error, ingrese id color nuevamente\n");
            pedirChar(&auxAuto.caja,'a','m',"Ingrese caja\na : automatico\nm : manual\n","Error,Ingrese caja\na : automatico\nm : manual\n");
            auxAuto.isEmpty=0;
            auxAuto.idCliente=num;
            autos[indice]=auxAuto;
            (*pId)++;
            todoOk=1;

        }
    }
    return todoOk;
}

void mostrarAuto(eAuto autito, eColor colores[],int tamC,eMarca marcas[],int tamM,eCliente clientes[],int tamCLI)
{
    char descColor[20];
    char descMarca[20];
    char descCli[20];
    cargarDescripcionClientes(clientes,tamCLI,autito.idCliente,descCli);
    cargarDescripcionMarca(marcas,tamM,autito.idMarca,descMarca);
    cargarDescripcionColores(colores,tamC,autito.idColor,descColor);
    printf("    %d            %7s          %6s          %c           %s\n",
           autito.id,
           descMarca,
           descColor,
           autito.caja,
           descCli);

}
int mostrarAutos(eAuto autos[],int tamA,eColor colores[],int tamC,eMarca marcas[],int tamM,eCliente clientes[],int tamCLI)
{

    int todoOk=0;
    if(autos!=NULL&&tamA>0&&colores!=NULL&&tamC>0&&marcas!=NULL&&marcas!=NULL&&tamM>0)
    {
        system("cls");
        printf("            ***Listado autos ****\n");
        printf("    id            marca            color        caja         nombre\n");
        printf("-------------------------------------------------------\n");
        for(int i=0;i<tamA;i++)
        {
            if(autos[i].isEmpty==0)
            {
               mostrarAuto(autos[i],colores,tamC,marcas,tamM,clientes,tamCLI);
            }
        }
        todoOk=1;
    }
    return todoOk;
}



int ordenarAutos(eAuto autos[],int tamA,eMarca marcas[],int tamM)
{
    int todoOk=0;
    eAuto auxAuto;
    char descMarcaUno[20];
    char descMarcaDos[20];
    if(autos!=NULL&&tamA>0&&marcas!=NULL&&tamM>0)
    {
        for(int i=0;i<tamA-1;i++)
        {
            for(int j=i+1;j<tamA;j++)
            {
                cargarDescripcionMarca(marcas,tamM,autos[i].idMarca,descMarcaUno);
                cargarDescripcionMarca(marcas,tamM,autos[j].idMarca,descMarcaDos);
                if((strcmp(descMarcaUno,descMarcaDos)>0) ||(strcmp(descMarcaUno,descMarcaDos)==0&&autos[i].id>autos[j].id))
                {
                    auxAuto=autos[i];
                    autos[i]=autos[j];
                    autos[j]=auxAuto;
                }
            }
        }
        todoOk=1;
    }
    return todoOk;
}


int buscarAutosId(eAuto autos[],int tamA,int id)
{
    int indice=-1;
    if(autos!=NULL&&tamA>0)
    {
        for(int i=0; i<tamA; i++)
        {
            if(autos[i].isEmpty==0 && autos[i].id==id)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int modificarAutos(eAuto autos[],int tamA, eMarca marcas[],int tamM,eColor colores[],int tamC,eCliente clientes[],int tamCLI)
{
    int todoOk=0;
    int idAuto;
    int indice;
    char confirma;

    if(autos!=NULL&&tamA>0)
    {
        system("cls");
        printf("****Modificar autos****\n\n");
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
            mostrarAuto(autos[indice],colores,tamC,marcas,tamM,clientes,tamCLI);
            printf("Confirma modificacion ?\n");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma=='s')
            {
                switch(subMenu())
                {
                case 1:
                    mostrarColores(colores,tamC);
                    pedirEntero(&autos[indice].idColor,5000,5004,"Ingrese nuevo id color\n","Error, ingrese id color valido\n");
                    break;
                case 2:
                    mostrarMarcas(marcas,tamM);
                    pedirEntero(&autos[indice].idMarca,1000,1003,"Ingrese nuevo id marca\n","Error, ingrese id marca valido\n");
                    break;
                default:
                    printf("Opcion invalida!!!\n");
                    fflush(stdin);
                }
                todoOk=1;
            }
            else
            {
                printf("Se ha cancelado la modificacion.\n");
            }
        }
    }
    return todoOk;
}

int darDeBajaAuto(eAuto autos[],int tamA, eMarca marcas[],int tamM,eColor colores[],int tamC,eCliente clientes[],int tamCLI)
{
    int todoOk=0;
    int idAuto;
    int indice;
    char confirma;
    if(autos!=NULL&&tamA>0)
    {
        system("cls");
        printf("****baja de autos****\n\n");
        mostrarAutos(autos,tamA,colores,tamC,marcas,tamM,clientes,tamCLI);
        printf("Ingrese numero id para dar de baja : \n");
        scanf("%d",&idAuto);
        indice=buscarAutosId(autos,tamA,idAuto);
        if(indice==-1)
        {
            printf("no existe un auto con el id ingresado. \n");
        }
        else
        {
            printf("Confirma borrar los datos?\n");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma=='s')
            {
                autos[indice].isEmpty=1;
                todoOk=1;
            }
            else
            {
                printf("Se ha cancelado la baja de datos.\n");

            }
        }

    }
    return todoOk;
}
int pedirPatente(int* entero, eAuto autos[],int tamA)
{
    int auxInt;
    int todoOk;
    if(autos&&entero!=NULL&&tamA>0)
    {
        printf("Ingrese id patente : \n");
        scanf("%d",&auxInt);
        while(validarPatenteAuto(&auxInt,autos,tamA)==0)
        {
           printf("Error ingrese id patente valido : \n");
            scanf("%d",&auxInt);
        }
        *entero=auxInt;
        todoOk=1;
    }
    return todoOk;
}

int informeMostrarAutosMarcaSeleccionadA(eAuto autos[],int tamA,eMarca marcas[],int tamM,eColor colores[],int tamC,eCliente clientes[],int tamCLI)
{
    int todoOk=0;
    int idMarca;
    int indice;
    if(autos!=NULL&&tamA>0&&marcas!=NULL&&tamM>0)
    {
        mostrarMarcas(marcas,tamM);
        printf("Ingrese id marca .\n");
        scanf("%d",&idMarca);
        indice=buscarMarcasId(marcas,tamM,idMarca);
        while(indice==-1)
        {
            printf("Error, ingrese id marca nuevamente.\n");
            scanf("%d",&idMarca);
            indice=buscarMarcasId(marcas,tamM,idMarca);
        }
        system("cls");
        mostrarAutosPorMarca(marcas,tamM,autos,tamA,colores,tamC,idMarca,clientes,tamCLI);
     todoOk=1;
    }
    return todoOk;
}

int mostrarAutosPorMarca(eMarca marcas[],int tamM,eAuto autos[],int tamA,eColor colores[],int tamC,int idMarca,eCliente clientes[],int tamCLI)
{
    int todoOk=0;
    int flag=1;
    if(marcas!=NULL&&autos!=NULL&&tamM>0&&tamA>0)
    {
        printf("               ***  informe de autos  ****\n\n");
        printf("    patente      marca             color        caja\n\n");
        for(int i=0;i<tamA;i++)
        {
            if(autos[i].isEmpty==0&&autos[i].idMarca==idMarca)
            {
                mostrarAuto(autos[i],colores,tamC,marcas,tamM,clientes,tamCLI);
                flag=0;
            }
        }
     todoOk=1;
    }
    if(flag)
    {
        printf("No se encuentran autos de la marca pedida!!.\n\n");
    }

    return todoOk;
}

int informarAutosCadaMarca(eMarca marcas[],int tamM,eAuto autos[],int tamA,eColor colores[],int tamC,eCliente clientes[],int tamCLI)
{
    int todoOk=0;
    int flag=1;

    if(marcas!=NULL&&tamM>0&&autos!=NULL&&tamA>0&&colores!=NULL&&tamC>0)
    {
        system("cls");
        printf("                  ***informe autos de cada marca ****\n");
        printf("    patente      marca             color        caja\n\n");
        for(int i=0; i<tamM;i++)
        {
            printf("Marcas : %s\n\n",marcas[i].descripcion);
            mostrarAutosPorMarca(marcas,tamM,autos,tamA,colores,tamC,marcas[i].id,clientes,tamCLI);
            flag=0;
        }
        if(flag)
        {
            printf("autos no localizados\n");
        }
        todoOk=1;
    }

    return todoOk;
}

int informarAutosporColorYMarca(eMarca marcas[],int tamM,eAuto autos[],int tamA,eColor colores[],int tamC)
{
    int todoOk=0;
    int flag=1;
    int indiceColor;
    int indiceMarca;
    int contador=0;
    if(marcas!=NULL&&tamM>0&&autos!=NULL&&tamA>0&&colores!=NULL&&tamC>0)
    {
        mostrarMarcas(marcas,tamM);
        pedirEntero(&indiceMarca,1000,1003,"ingrese id marca\n","error, ingrese id marca nuevamente\n");
        mostrarColores(colores,tamC);
        pedirEntero(&indiceColor,5000,5004,"Ingrese id color\n","Error, ingrese id color nuevamente\n");
        for(int i=0;i<tamA;i++)
        {
            if(autos[i].isEmpty==0&&(autos[i].idColor==indiceColor&&autos[i].idMarca==indiceMarca))
            {
                contador++;
                flag=0;
            }
        }
        if(flag)
        {
            printf("No hay autos localizados con ese criterio de busqueda.\n");

        }
        else
        {
            printf("Hay %d autos localizados con ese criterio de busqueda.\n",contador);
        }
    }
    return todoOk;
}

int contarAutosPorMarca(eMarca marcas[],int tamM,eAuto autos[],int tamA)
{
    int todoOk=0;
    int contador=0;
    if(marcas!=NULL&&autos!=NULL&&tamM>0&&tamA>0)
    {
        for(int i=0;i<tamM;i++)
        {
            printf("Marcas %s\n",marcas[i].descripcion);
            contador=0;
            for(int j=0;j<tamA;j++)
            {
                if(autos[j].isEmpty==0&&autos[j].idMarca==marcas[i].id)
                {
                    contador++;
                }
            }
            printf("cantidad de autos localizados : %d\n",contador);
        }
     todoOk=1;
    }
    return todoOk;
}
int marcasMasUsadas(eMarca marcas[],int tamM,eAuto autos[],int tamA)
{
    int todoOk=0;
    int contador[4]={0};
    int contMax;
    int flag=1;
    if(marcas!=NULL&&autos!=NULL&&tamM>0&&tamA>0)
    {
        for(int i=0;i<tamM;i++)
        {
            for(int j=0;j<tamA;j++)
            {
                if(autos[j].isEmpty==0&&autos[j].idMarca==marcas[i].id)
                {
                    contador[i]++;
                }
            }
        }
        for(int i=0;i<tamM;i++)
        {
            if(flag||contador[i]>=contMax)
            {
                flag=0;
                printf("Marca mas usada : %s\n",marcas[i].descripcion);
                contMax=contador[i];
                if(contador[i]==1)
                {
                    printf("%d auto.\n",contMax);
                }
                else
                {
                    printf("%d autos.\n",contMax);
                }
            }
        }
     todoOk=1;
    }
    return todoOk;
}
int pedirAutoYmostrarTrabajos(eAuto autos[],int tamA,eTrabajo trabajos[],int tamT,eColor colores[],int tamC,eMarca marcas[],int tamM,
                              eServicio servicios[],int tamS,eCliente clientes[],int tamCLI)
{
    int idAuto;
    int todoOk=0;
    int indice;
    if(autos!=NULL&&tamA>0&&trabajos!=NULL&&tamT>0)
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
            for(int i=0;i<tamA;i++)
            {
              for(int j=0;j<tamT;j++)
              {
                if(autos[i].isEmpty==1&&(trabajos[j].isEmpty&&(autos[i].id==trabajos[j].idPatente)))
                {
                    mostrarTrabajo(trabajos[j],servicios,tamS);
                }
              }
            }
        }
        todoOk=1;
    }

    return todoOk;

}


