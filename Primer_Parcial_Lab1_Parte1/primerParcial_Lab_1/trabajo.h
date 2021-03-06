#include "fecha.h"
#include "notebook.h"
#include "servicio.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
    int id;
    int idNotebook;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

//inicializar
int inicializarTrabajos(eTrabajo vec[], int tam);

//buscar
int buscarTrabajoLibre(eTrabajo vec[], int tam, int* pIndex);

//alta
int altaTrabajo(eTrabajo trabajos[], int tamTr, eNotebook notebooks[], int tamNot, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip, eServicio servicios[], int tamSer, int* pIdTrabajo);

//listar
int listarTrabajos(eTrabajo trabajos[], int tamTr, eNotebook notebooks[], int tamNot, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip, eServicio servicios[], int tamSer);

#endif
