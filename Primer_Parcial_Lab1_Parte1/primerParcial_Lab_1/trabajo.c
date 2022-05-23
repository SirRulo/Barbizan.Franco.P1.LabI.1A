#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trabajo.h"

int inicializarTrabajos(eTrabajo vec[], int tam)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }

    return todoOk;
}

int buscarTrabajoLibre(eTrabajo vec[], int tam, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaTrabajo(eTrabajo trabajos[], int tamTr, eNotebook notebooks[], int tamNot, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip, eServicio servicios[], int tamSer, int* pIdTrabajo){
    int todoOk = 0;
    int indice;
    eTrabajo nuevoTrabajo;
    eFecha fecha;

    if(trabajos != NULL && marcas != NULL && tipos != NULL && servicios != NULL && notebooks != NULL && pIdTrabajo != NULL && tamTr > 0 && tamNot > 0 && tamSer > 0 && tamMar > 0 && tamTip > 0)
    {

        system("cls");
        printf("       *** Alta Trabajo *** \n");
        printf("-------------------------------------------\n\n");


        if( buscarTrabajoLibre(trabajos, tamTr, &indice) )
        {
            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                // aca caigo cuando haya lugar
                listarNotebooks(notebooks, tamNot, marcas, tamMar, tipos, tamTip);
                printf("Ingrese Id Notebook\n");
                scanf("%d", &nuevoTrabajo.idNotebook);
                buscarNotebook(notebooks, tamNot, nuevoTrabajo.idNotebook, &indice);

                while( indice == -1){
                printf("Notebook invalida. Ingrese Id Notebook\n");
                scanf("%d", &nuevoTrabajo.idNotebook);
                buscarNotebook(notebooks, tamNot, nuevoTrabajo.idNotebook, &indice);;
                }

                listarServicios(servicios, tamSer);
                printf("Ingrese Id Servicio\n");
                scanf("%d", &nuevoTrabajo.idServicio);

                while( !validarServicio(servicios, tamSer, nuevoTrabajo.idServicio )){
                printf("Servicio invalido. Ingrese Id Servicio\n");
                scanf("%d", &nuevoTrabajo.idServicio);
                }

                printf("\n");
                printf("Ingrese Fecha  dd/mm/aaaa: ");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
                nuevoTrabajo.fecha = fecha;

                nuevoTrabajo.isEmpty = 0;
                nuevoTrabajo.id = *pIdTrabajo;
                *pIdTrabajo = *pIdTrabajo + 1;
                trabajos[indice] = nuevoTrabajo;
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }
    return todoOk;
}

int listarTrabajos(eTrabajo trabajos[], int tamTr, eNotebook notebooks[], int tamNot, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip, eServicio servicios[], int tamSer)
{
    int todoOk = 0;
    int flag = 0;
    char descripcion[20];

     if(trabajos != NULL && marcas != NULL && tipos != NULL && servicios != NULL && notebooks != NULL && tamTr > 0 && tamNot > 0 && tamSer > 0 && tamMar > 0 && tamTip > 0)
    {
        system("cls");
        printf("          *** Listado de Trabajos ***\n\n");
        printf("    Id      IdNotebook        Servicios          Fecha\n");
        printf("-------------------------------------------------------------\n");
        for(int i=0; i < tamTr; i++)
        {
            if( !trabajos[i].isEmpty )
            {
                cargarDescripcionServicio(servicios, tamSer, trabajos[i].idServicio, descripcion);
                printf("   %5d     %5d      %15s          %02d/%02d/%02d\n", trabajos[i].id, trabajos[i].idNotebook, descripcion, trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("           No hay trabajos en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}
