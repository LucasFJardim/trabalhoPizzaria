#include <stdio.h>
#include <string.h>
#include "ingrediente.h"

void inicializarIngredientes(Ingrediente *ingredientes, int *quantidadeIngredientes) {
    ingredientes[0].id = 1;
    strcpy(ingredientes[0].nome, "Queijo");
    ingredientes[0].preco = 4.0;

    ingredientes[1].id = 2;
    strcpy(ingredientes[1].nome, "Cebola");
    ingredientes[1].preco = 2.0;

    ingredientes[2].id = 3;
    strcpy(ingredientes[2].nome, "Catupiry");
    ingredientes[2].preco = 7.0;

    ingredientes[3].id = 4;
    strcpy(ingredientes[3].nome, "Azeitona");
    ingredientes[3].preco = 3.0;

    *quantidadeIngredientes = 4;
}


void listarIngredientes(Ingrediente *ingredientes, int quantidadeIngredientes) {
    if (quantidadeIngredientes == 0) {
        printf("Nenhum ingrediente cadastrada.\n");
        return;
    }

    for (int i = 0; i < quantidadeIngredientes; i++) {
        printf("Ingrediente %d: %s - Preco: %.2f\n", ingredientes[i].id, ingredientes[i].nome, ingredientes[i].preco);
        printf("\n\n");
    }
}


Ingrediente criarIngrediente(int quantidadeIngredientes) {
    Ingrediente novoIngrediente;
    novoIngrediente.id = quantidadeIngredientes + 1;

    printf("Digite o nome do novo Ingrediente: ");
    scanf(" %[^\n]", novoIngrediente.nome);

    printf("Digite o preco do Ingrediente: ");
    scanf("%f", &novoIngrediente.preco);

    printf("Ingrediente '%s' Criado!!\n", novoIngrediente.nome);

    return novoIngrediente;
}


void removerIngrediente(Ingrediente *ingrediente, int *quantidadeIngredientes) {
    if (*quantidadeIngredientes == 0) {
        printf("Não ha ingredientes para remover.\n");
        return;
    }

    int id;
    printf("Digite o ID do ingrediente que deseja remover: ");
    scanf("%d", &id);

    int indiceRemover = -1;

    for (int i = 0; i < *quantidadeIngredientes; i++) {
        if (ingrediente[i].id == id) {
            indiceRemover = i;
            break;
        }
    }

    if (indiceRemover == -1) {
        printf("ID %d Invalido!!\n", id);
        return;
    }

    for (int i = indiceRemover; i < *quantidadeIngredientes - 1; i++) {
        ingrediente[i] = ingrediente[i + 1];
    }

    (*quantidadeIngredientes)--;

    for (int i = 0; i < *quantidadeIngredientes; i++) {
        ingrediente[i].id = i + 1;
    }

    printf("Ingrediente removido com sucesso.\n");
}

