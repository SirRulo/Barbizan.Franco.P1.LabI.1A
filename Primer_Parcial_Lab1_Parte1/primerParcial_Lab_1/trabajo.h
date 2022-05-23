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

int inicializarTrabajos(eTrabajo vec[], int tam);
int buscarTrabajoLibre(eTrabajo vec[], int tam, int* pIndex);
int altaTrabajo(eTrabajo trabajos[], int tamTr, eNotebook notebooks[], int tamNot, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip, eServicio servicios[], int tamSer, int* pIdTrabajo);
int listarTrabajos(eTrabajo trabajos[], int tamTr, eNotebook notebooks[], int tamNot, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip, eServicio servicios[], int tamSer);

#endif
