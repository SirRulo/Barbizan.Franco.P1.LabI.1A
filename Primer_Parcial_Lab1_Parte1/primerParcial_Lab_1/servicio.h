#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
    int precio;
}eServicio;

//listar
int listarServicios(eServicio servicios[], int tam);

//buscar
int buscarServicio(eServicio servicios[], int tam, int id, int* pIndice);

//validar
int validarServicio(eServicio servicios[], int tam, int id);

//cargar
int cargarDescripcionServicio(eServicio servicios[], int tam, int id, char descripcion[]);

#endif

