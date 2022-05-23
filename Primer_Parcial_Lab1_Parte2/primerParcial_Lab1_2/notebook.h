#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED

#include "marca.h"
#include "tipo.h"
#include "clientes.h"

typedef struct{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    int precio;
    int isEmpty;
    eCliente cliente;
}eNotebook;

int altaNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip, int* pId);//
int bajaNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip);//
int modificarNotebooks(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip);//
int inicializarNotebooks(eNotebook vec[], int tam); //
int buscarNotebookLibre(eNotebook vec[], int tam, int* pIndex); //
int buscarNotebook(eNotebook vec[], int tam, int id, int* pIndex); //
int mostrarNotebooks(eNotebook e, eMarca marcas[], eTipo tipos[], int tam);//
int listarNotebooks(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip);//
int menuModificarNotebook();//
int menu();

#endif

