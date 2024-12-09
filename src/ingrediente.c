#include <stdio.h>
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
