#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "servicio.h"

int listarServicios(eServicio servicios[], int tam){
int todoOk = 0;

    if(servicios != NULL && tam > 0){
        system("cls");
        printf("   *** Lista de Servicios  ***\n");
        printf("    Id         Descripcion   Precio\n");
        printf("-------------------------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %4d   %15s    %2d\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}

int buscarServicio(eServicio servicios[], int tam, int id, int* pIndice){
    int todoOk = 0;
    if(servicios != NULL && tam > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tam; i++){
                if(servicios[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}

int validarServicio(eServicio servicios[], int tam, int id){
    int esValido = 0;
    int indice;

    buscarServicio(servicios, tam, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}


int cargarDescripcionServicio(eServicio servicios[], int tam, int id, char descripcion[]){
int todoOk = 0;
int indice;

    buscarServicio(servicios,tam, id,&indice);

    if(descripcion != NULL && indice != -1 ){
       strcpy(descripcion, servicios[indice].descripcion);
       todoOk = 1;
    }
  return todoOk;
}
