#ifndef PIZZA_H
#define PIZZA_H

#include "ingrediente.h"

#define MAX_INGREDIENTES 10
#define MAX_PIZZAS 50
#define MAX_INGREDIENTES_PIZZA 10


typedef struct {
    int id;
    char nome[50];
    char tamanho;
    float preco;
    Ingrediente ingredientes[MAX_INGREDIENTES];
    int quantidadeIngredientes;
} Pizza;

void inicializarPizzas(Pizza *pizzas, int *quantidadePizzas);
void listarPizzas(Pizza *pizzas, int quantidadePizzas);
Pizza criarPizza(int quantidadePizzas);
void realizarCompra(Pizza *pizzas, int quantidadePizzas, Ingrediente *ingredientes, int quantidadeIngredientes);
void removerPizza(Pizza *pizzas, int *quantidadePizzas);

#endif
