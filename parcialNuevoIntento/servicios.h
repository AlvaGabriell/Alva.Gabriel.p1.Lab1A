#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED
typedef struct
{
    int id;
    char descServicio[25];
    int precio;
}eServicio;
#endif // SERVICIOS_H_INCLUDED
void mostrarServicio(eServicio servicio);
int mostrarServicios(eServicio servicios[],int tamS);
int pedirIdServicio(int* entero, eServicio servicios[],int tamS);
int cargarDescripcionServicio(eServicio servicios[],int tamS,int idServicio,char descripcion[]);
