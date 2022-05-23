#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}eMarca;

int listarMarcas(eMarca marcas[], int tam);
int cargarDescripcionMarca(eMarca marcas[], int tam, int id, char descripcion[]);
int buscarMarca(eMarca marcas[], int tam, int id, int* pIndice);
int validarMarca(eMarca marcas[], int tam, int id);


#endif

