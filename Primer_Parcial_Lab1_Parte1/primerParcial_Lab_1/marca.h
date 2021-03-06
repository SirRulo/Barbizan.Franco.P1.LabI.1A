#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}eMarca;

//listar
int listarMarcas(eMarca marcas[], int tam);

//cargar
int cargarDescripcionMarca(eMarca marcas[], int tam, int id, char descripcion[]);

//buscar
int buscarMarca(eMarca marcas[], int tam, int id, int* pIndice);

//validar
int validarMarca(eMarca marcas[], int tam, int id);


#endif
