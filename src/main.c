#include <stdio.h>
#include "ingrediente.h"
#include "pizza.h"

int main() {
    Pizza pizzas[MAX_PIZZAS];
    Ingrediente ingredientes[MAX_INGREDIENTES];
    int quantidadePizzas = 0;
    int quantidadeIngredientes = 0;
    int opcao;

    inicializarPizzas(pizzas, &quantidadePizzas);
    inicializarIngredientes(ingredientes, &quantidadeIngredientes);


    do {
        printf("\n==== Sistema de Gerenciamento de Pizzaria ====\n");
        printf("1. Listar Pizzas\n");
        printf("2. Criar Nova Pizza\n");
        printf("3. Comprar uma Pizza\n");
        printf("4. Remover Pizza\n");
        printf("5. Listar Ingrediente\n");
        printf("6. Criar Ingrediente\n");
        printf("7. Remover Ingrediente\n");
        printf("8. Sair\n\n");
        printf("Escolha uma opcao: \n");
        scanf("%d", &opcao);
        printf("\n");


        switch (opcao) {
            case 1:
                listarPizzas(pizzas, quantidadePizzas);
                break;
            case 2:
                if (quantidadePizzas < MAX_PIZZAS) {
                    pizzas[quantidadePizzas] = criarPizza(quantidadePizzas);
                    quantidadePizzas++;
                } else {
                    printf("Capacidade maxima de pizzas atingida.\n");
                }
                break;
            case 3:
                realizarCompra(pizzas, quantidadePizzas, ingredientes, 4, quantidadeIngredientes);
                break;
            case 4:
                removerPizza(pizzas, &quantidadePizzas);
                break;
            case 5:
                listarIngredientes(ingredientes, quantidadeIngredientes);
                break;
            case 6:
                if (quantidadeIngredientes < MAX_INGREDIENTES) {
                    ingredientes[quantidadeIngredientes] = criarIngrediente(quantidadeIngredientes);
                    quantidadeIngredientes++;
                } else {
                    printf("Capacidade maxima de ingredientes atingida.\n");
                }                break;
            case 7:
                removerIngrediente(ingredientes, &quantidadeIngredientes);
                break;
            case 8:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 8);

    return 0;
}
