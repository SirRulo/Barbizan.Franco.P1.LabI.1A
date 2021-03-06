#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}eTipo;

//listar
int listarTipos(eTipo tipos[], int tam);

//cargar
int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[]);

//buscar
int buscarTipo(eTipo tipos[], int tam, int id, int* pIndice);

//validar
int validarTipo(eTipo tipos[], int tam, int id);

#endif
