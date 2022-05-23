#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED

#include "marca.h"
#include "tipo.h"
#include "cliente.h"

typedef struct{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    int precio;
    int isEmpty;
    eCliente cliente;
}eNotebook;

//alta
int altaNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip, int* pId);

//baja
int bajaNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip);

//modificar
int modificarNotebooks(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip);

//inicializar
int inicializarNotebooks(eNotebook vec[], int tam);

//buscar
int buscarNotebookLibre(eNotebook vec[], int tam, int* pIndex);

//buscarLibre
int buscarNotebook(eNotebook vec[], int tam, int id, int* pIndex);

//mostrar
int mostrarNotebooks(eNotebook e, eMarca marcas[], eTipo tipos[], int tam);

//listar
int listarNotebooks(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip);

//menu Modificar
int menuModificarNotebook();

//menu Principal
int menu();

#endif
