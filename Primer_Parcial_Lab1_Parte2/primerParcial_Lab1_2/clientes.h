#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct{
    int idCliente;
    char nombre[20];
    char sexo;
}eCliente;

int validarCliente(eCliente unCliente);

#endif

