#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "servicio.h"
#include "trabajo.h"

#define TAM 10 //notebook
#define TAMM 4 //marca
#define TAMT 4 //tipo
#define TAMS 4 //servicio
#define TAMTR 10 //trabajo

int main()
{
    char salir = 'n';
    int proximoIdNotebook = 10000;
    int proximoIdTrabajo = 20000;

    eNotebook lista[TAM];
    eTrabajo trabajos[TAMTR];

    eMarca marcas[TAMM] =
    {
        {1000, "Compac"},
        {1001, "Asus"},
        {1002, "Acer"},
        {1003, "HP"}
    };

    eTipo tipos[TAMT] =
    {
        {5000, "Gamer"},
        {5001, "Disenio"},
        {5002, "Ultrabook"},
        {5003, "Normalita"}
    };

    eServicio servicios[TAMS] =
    {
        {20000, "Bateria", 2250},
        {20001, "Display", 10300},
        {20002, "Mantenimiento", 4400},
        {20003, "Fuente", 5600}
    };

    inicializarNotebooks(lista, TAM);
    do{
        switch(menu()){
            case 1:
                //printf("1- Alta Notebook\n");
                if( altaNotebook(lista, TAM, marcas, TAMM, tipos, TAMT, &proximoIdNotebook))
                {
                    printf("\n");
                    printf("Notebook agregado con exito!!!\n");
                }
                else
                {
                    printf("\n");
                    printf("Problema al hacer el alta de Notebook\n");
                }
                break;

            case 2:
                //printf("2- Modificar Notebook\n");
                if( modificarNotebooks(lista, TAM, marcas, TAMM, tipos, TAMT))
                {
                    printf("\n");
                    printf("Notebook modificada con exito!!!\n");
                }
                else
                {
                    printf("\n");
                    printf("Problema al hacer la modificacion de notebook\n");
                }
                break;

            case 3:
                //printf("3- Baja Notebook\n");
                if( bajaNotebook(lista, TAM, marcas, TAMM, tipos, TAMT) == 0)
                {
                    printf("Problema al hacer la baja de notebook\n");
                }
                break;

            case 4:
                //printf("4- Listar Notebooks\n");
                listarNotebooks(lista, TAM, marcas, TAMM, tipos, TAMT);
                break;

            case 5:
                //printf("5- Listar Marcas\n");
                listarMarcas(marcas, TAMM);
                break;

            case 6:
                //printf("6- Listar Tipos\n");
                listarTipos(tipos, TAMT);
                break;

            case 7:
                //printf("7- Listar Servicios\n");
                listarServicios(servicios, TAMS);
                break;

            case 8:
                //printf("8- Alta Trabajo\n");
                if( altaTrabajo(trabajos, TAMTR, lista, TAM, marcas, TAMM, tipos, TAMT, servicios, TAMS, &proximoIdTrabajo))
                {
                    printf("\n");
                    printf("Trabajo agregado con exito!!!\n");
                }
                else
                {
                    printf("Problema al hacer el alta de trabajo\n");
                }
                break;

            case 9:
                //printf("9- Listar Trabajos\n");
                listarTrabajos(trabajos, TAMTR, lista, TAM, marcas, TAMM, tipos, TAMT, servicios, TAMS);
                break;

            case 10:
                //printf("7- Listar Servicios\n");
                listarServicios(servicios, TAMS);
                break;

            case 11:
                //printf("7- Listar Servicios\n");
                listarServicios(servicios, TAMS);
                break;

            case 12:
                //printf("7- Listar Servicios\n");
                listarServicios(servicios, TAMS);
                break;

            case 13:
                //printf("7- Listar Servicios\n");
                listarServicios(servicios, TAMS);
                break;

            case 14:
                //printf("7- Listar Servicios\n");
                listarServicios(servicios, TAMS);
                break;

            case 15:
                //printf("7- Listar Servicios\n");
                listarServicios(servicios, TAMS);
                break;

            case 16:
                salir = 's';
                break;
        }
        system("pause");

    }while(salir != 's');

    return 0;
}
