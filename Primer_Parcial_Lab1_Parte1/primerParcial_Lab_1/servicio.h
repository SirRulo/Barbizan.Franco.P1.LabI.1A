#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
    int precio;
}eServicio;

int listarServicios(eServicio servicios[], int tam);
int buscarServicio(eServicio servicios[], int tam, int id, int* pIndice);
int validarServicio(eServicio servicios[], int tam, int id);
int cargarDescripcionServicio(eServicio servicios[], int tam, int id, char descripcion[]);

#endif

