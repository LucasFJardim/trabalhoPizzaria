#include <stdio.h>
#include "ingrediente.h"
#include "pizza.h"

int main() {
    Pizza pizzas[MAX_PIZZAS];
    Ingrediente ingredientes[MAX_INGREDIENTES];
    int quantidadePizzas = 3;
    int opcao;

    inicializarPizzas(pizzas, &quantidadePizzas);

    do {
        printf("\n==== Sistema de Gerenciamento de Pizzaria ====\n");
        printf("1. Listar Pizzas\n");
        printf("2. Criar Nova Pizza\n");
        printf("3. Comprar uma Pizza\n");
        printf("4. Remover Pizza\n");
        printf("5. Sair\n\n");
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
                realizarCompra(pizzas, quantidadePizzas, ingredientes, 4);
                break;
            case 4:
                removerPizza(pizzas, &quantidadePizzas);
                break;
            case 5:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
