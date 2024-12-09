#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#define MAX_INGREDIENTES 4
#define MAX_NOME_INGREDIENTE 50

typedef struct {
    int id;
    char nome[MAX_NOME_INGREDIENTE];
    float preco;
} Ingrediente;

void inicializarIngredientes(Ingrediente *ingredientes, int *quantidadeIngredientes);

#endif
