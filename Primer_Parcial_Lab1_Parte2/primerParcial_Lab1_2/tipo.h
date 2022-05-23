#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}eTipo;

int listarTipos(eTipo tipos[], int tam);
int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[]);
int buscarTipo(eTipo tipos[], int tam, int id, int* pIndice);
int validarTipo(eTipo tipos[], int tam, int id);

#endif

