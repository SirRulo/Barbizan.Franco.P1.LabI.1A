#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "notebook.h"

int mostrarNotebooks(eNotebook e, eMarca marcas[], eTipo tipos[], int tam)
{
    int todoOk = 0;
    char descMarca[20];
    char descTipo[20];

    if((marcas != NULL && tam > 0) && (tipos != NULL && tam > 0))
    {
        cargarDescripcionMarca( marcas, tam, e.idMarca, descMarca);
        cargarDescripcionTipo( tipos, tam, e.idTipo, descTipo);

        printf("  %4d       %15s       %10s      %10s     %2d      %10s      %c       %2d\n",
               e.id,
               e.modelo,
               descMarca,
               descTipo,
               e.cliente.idCliente,
               e.cliente.nombre,
               e.cliente.sexo,
               e.precio
              );
        todoOk = 1;
    }
    return todoOk;
}

int inicializarNotebooks(eNotebook vec[], int tam)
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

int buscarNotebook(eNotebook vec[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL && id > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty == 0 &&  vec[i].id == id )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarNotebookLibre(eNotebook vec[], int tam, int* pIndex)
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

int altaNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip, int* pId)
{
    int todoOk = 0;
    int indice;
    char auxCad[100];
    eNotebook nuevaNotebook;
    eCliente cliente;

    if(vec != NULL && tam > 0 && pId != NULL)
    {
        if( buscarNotebookLibre(vec, tam, &indice) )
        {
            system("cls");
            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                printf("Ingrese un Id Cliente: ");
                scanf("%d", &cliente.idCliente);

                printf("\n");
                printf("Ingrese el nombre del cliente: ");
                fflush(stdin);
                gets(auxCad);

                while(strlen(auxCad) >= 20)
                {
                    printf("\n");
                    printf("Nombre demasiado largo. Reingrese nombre: ");
                    fflush(stdin);
                    gets(auxCad);
                }
                strcpy(cliente.nombre, auxCad);

                printf("\n");
                printf("Ingrese sexo del cliente('m' o 'f'): ");
                fflush(stdin);
                scanf("%c", &cliente.sexo);

                nuevaNotebook.cliente = cliente;

                system("cls");
                printf("Ingrese el modelo: ");
                fflush(stdin);
                gets(auxCad);

                while(strlen(auxCad) >= 20)
                {
                    printf("\n");
                    printf("Modelo demasiado largo. Reingrese modelo: ");
                    fflush(stdin);
                    gets(auxCad);
                }
                strcpy(nuevaNotebook.modelo, auxCad);

                listarMarcas(marcas, tamMar);

                printf("Ingrese Id marcas: ");
                scanf("%d", &nuevaNotebook.idMarca);

                while( !validarMarca(marcas,tamMar, nuevaNotebook.idMarca))
                {
                    printf("Marca invalida.Ingrese Id marca: ");
                    scanf("%d", &nuevaNotebook.idMarca);
                }

                listarTipos(tipos, tamTip);

                printf("Ingrese Id tipo: ");
                scanf("%d", &nuevaNotebook.idTipo);

                while( !validarTipo(tipos,tamTip, nuevaNotebook.idTipo))
                {
                    printf("Tipo invalido.Ingrese Id tipo: ");
                    scanf("%d", &nuevaNotebook.idTipo);
                }

                system("cls");
                printf("Ingrese precio: ");
                scanf("%d", &nuevaNotebook.precio);

                nuevaNotebook.isEmpty = 0;
                nuevaNotebook.id = *pId;
                *pId = *pId + 1;
                vec[indice] = nuevaNotebook;
                todoOk = 1;
            }
        }
        else
        {
            printf("\n");
            printf("Ocurrio un problema con los parametros\n");
        }
    }
    return todoOk;
}

int listarNotebooks(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip)
{
    int todoOk = 0;
    int flag = 0;
    if(vec != NULL && tam > 0)
    {
        system("cls");
        printf("                                 *** Listado de Notebooks ***\n\n");
        printf("   Id                  Modelo           Marca            Tipo      IdCliente         Nombre    Sexo      Precio\n");
        printf("--------------------------------------------------------------------------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty )
            {
                mostrarNotebooks(vec[i], marcas, tipos, tam);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("                 No hay notebooks en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int modificarNotebooks(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip)
{
    int todoOk = 0;
    int indice;
    int id;
    char salir = 'n';

    if(vec != NULL && tam > 0)
    {
        listarNotebooks(vec, tam, marcas, tamMar, tipos, tamTip);
        printf("Ingrese Id: ");
        scanf("%d", &id);
        if( buscarNotebook(vec, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("\n");
                printf("No hay una notebook con Id %d\n", id);
            }
            else
            {
                system("cls");
                printf("                                 *** Listado de Notebooks ***\n\n");
                printf("   Id                  Modelo           Marca            Tipo      IdCliente         Nombre    Sexo      Precio\n");
                printf("--------------------------------------------------------------------------------------------------------------------\n");
                mostrarNotebooks(vec[indice], marcas, tipos, tam);


                do
                {
                    printf("\n");
                    switch(menuModificarNotebook()){

                        case 1:
                            system("cls");
                            printf("Ingrese nuevo precio: ");
                            scanf("%d", &vec[indice].precio);
                            printf("\n");
                            printf("Se ha modificado el precio con exito!!!\n");
                            salir = 's';
                            break;

                        case 2:
                            listarTipos(tipos, tamTip);
                            printf("Ingrese nuevo tipo: ");
                            scanf("%d", &vec[indice].idTipo);
                            printf("\n");
                            printf("Se ha modificado el tipo con exito!!!\n");
                            salir = 's';
                            break;

                        case 3:
                            system("cls");
                            printf("Ingrese nuevo precio: ");
                            scanf("%d", &vec[indice].precio);

                            listarTipos(tipos, tamTip);
                            printf("Ingrese nuevo tipo: ");
                            scanf("%d", &vec[indice].idTipo);
                            printf("\n");
                            printf("El precio y el tipo se han modificado con exito!!!\n");
                            salir = 's';
                            break;

                        case 4:
                            salir = 's';
                            break;

                    }
                    system("pause");

                }
                while(salir != 's');
            }
        }
        else
        {
            printf("\n");
            printf("Ocurrio un problema al buscar notebook\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int menuModificarNotebook()
{
    int opcion;

    printf("*** Campos a modificar ***\n");
    printf("1- Precio\n");
    printf("2- Tipo\n");
    printf("3- Precio y Tipo\n");
    printf("4- Cancelar\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int bajaNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if(vec != NULL && tam > 0)
    {
        listarNotebooks(vec, tam, marcas, tamMar, tipos, tamTip);
        printf("Ingrese id: ");
        scanf("%d", &id);
        if( buscarNotebook(vec, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay una notebook con Id %d\n", id);
            }
            else
            {
                system("cls");
                mostrarNotebooks(vec[indice], marcas, tipos, tam);
                printf("\n");
                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma != 'S' && confirma != 's')
                {
                    printf("\n");
                    printf("Baja cancelada por el usuario\n");
                }
                else
                {
                    vec[indice].isEmpty = 1;
                    printf("\n");
                    printf("Baja realizada con el exito!!!\n");
                    todoOk = 1;
                }
            }

        }
        else
        {
            printf("\n");
            printf("Ocurrio un problema al buscar empleado\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int menu(){

    int opcion;
    system("cls");
    printf("     *** Service de Notebooks ***\n");
    printf("1- Alta Notebook\n");
    printf("2- Modificar Notebook\n");
    printf("3- Baja Notebook\n");
    printf("4- Listar Notebooks\n");
    printf("5- Listar Marcas\n");
    printf("6- Listar Tipos\n");
    printf("7- Listar Servicios\n");
    printf("8- Alta Trabajo\n");
    printf("9- Listar Trabajos\n");
    printf("10- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
