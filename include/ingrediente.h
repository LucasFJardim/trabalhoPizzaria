#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#define MAX_INGREDIENTES 10
#define MAX_INGREDIENTES_INGREDIENTE 10
#define MAX_NOME_INGREDIENTE 50

typedef struct {
    int id;
    char nome[MAX_NOME_INGREDIENTE];
    float preco;
} Ingrediente;

void inicializarIngredientes(Ingrediente *ingredientes, int *quantidadeIngredientes);
void listarIngredientes(Ingrediente *ingredientes, int quantidadeIngredientes);
Ingrediente criarIngrediente(int quantidadeIngredientes);
void removerIngrediente(Ingrediente *ingredientes, int *quantidadeIngredientes);

#endif
