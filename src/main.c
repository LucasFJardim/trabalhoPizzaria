#include <stdio.h>
#include "ingrediente.h"
#include "pizza.h"

int main() {
    Pizza pizzas[50]; 
    Ingrediente ingredientes[50];  
    int quantidadePizzas = 3;  
    int quantidadeIngredientes = 4;  
    int opcao;

    inicializarPizzas(pizzas, &quantidadePizzas);
    inicializarIngredientes(ingredientes, &quantidadeIngredientes);

    do {
        printf("==== Sistema de Gerenciamento de Pizzaria ====\n");
        printf("Escolha uma opcao: \n\n");
        printf("1. Listar Pizzas\n");
        printf("2. Realizar Compra\n");
        printf("3. Sair\n");
        
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listarPizzas(pizzas, quantidadePizzas);
                break;
            case 2:
                realizarCompra(pizzas, quantidadePizzas, ingredientes, quantidadeIngredientes);
                break;
            case 3:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao inválida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
