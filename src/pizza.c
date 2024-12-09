#include <stdio.h>
#include <string.h>
#include "pizza.h"

void inicializarPizzas(Pizza *pizzas, int *quantidadePizzas) {
    pizzas[0].id = 1;
    strcpy(pizzas[0].nome, "Pizza de Calabresa");
    pizzas[0].tamanho = 'M';  
    pizzas[0].preco = 30.0;
    pizzas[0].quantidadeIngredientes = 2; 
    strcpy(pizzas[0].ingredientes[0].nome, "Calabresa");
    pizzas[0].ingredientes[0].preco = 5.0;
    strcpy(pizzas[0].ingredientes[1].nome, "Queijo");
    pizzas[0].ingredientes[1].preco = 4.0;

    pizzas[1].id = 2;
    strcpy(pizzas[1].nome, "Pizza Margherita");
    pizzas[1].tamanho = 'M';
    pizzas[1].preco = 25.0;
    pizzas[1].quantidadeIngredientes = 2;
    strcpy(pizzas[1].ingredientes[0].nome, "Tomate");
    pizzas[1].ingredientes[0].preco = 3.0;
    strcpy(pizzas[1].ingredientes[1].nome, "Queijo");
    pizzas[1].ingredientes[1].preco = 4.0;

    pizzas[2].id = 3;
    strcpy(pizzas[2].nome, "Pizza de Frango com Catupiry");
    pizzas[2].tamanho = 'M';
    pizzas[2].preco = 35.0;
    pizzas[2].quantidadeIngredientes = 2;
    strcpy(pizzas[2].ingredientes[0].nome, "Frango");
    pizzas[2].ingredientes[0].preco = 6.0;
    strcpy(pizzas[2].ingredientes[1].nome, "Catupiry");
    pizzas[2].ingredientes[1].preco = 7.0;

    *quantidadePizzas = 3; 
}

void listarPizzas(Pizza *pizzas, int quantidadePizzas) {
    if (quantidadePizzas == 0) {
        printf("Nenhuma pizza cadastrada.\n");
        return;
    }

    for (int i = 0; i < quantidadePizzas; i++) {
        printf("Pizza %d: %s - Tamanho: %c - Preco: %.2f\n", pizzas[i].id, pizzas[i].nome, pizzas[i].tamanho, pizzas[i].preco);
        printf("Ingredientes: ");
        for (int j = 0; j < pizzas[i].quantidadeIngredientes; j++) {
            printf("%s ", pizzas[i].ingredientes[j].nome);
        }
        printf("\n\n");
    }
}

Pizza criarPizza(int quantidadePizzas) {
    Pizza novaPizza;
    novaPizza.id = quantidadePizzas + 1;

    printf("Digite o nome da nova pizza: ");
    scanf(" %[^\n]", novaPizza.nome);

    printf("Digite o tamanho da pizza (P, M, G): ");
    scanf(" %c", &novaPizza.tamanho);

    printf("Digite o preco da pizza: ");
    scanf("%f", &novaPizza.preco);

    printf("Digite a quantidade de ingredientes (max %d): ", MAX_INGREDIENTES);
    scanf("%d", &novaPizza.quantidadeIngredientes);

    for (int i = 0; i < novaPizza.quantidadeIngredientes; i++) {
        printf("Digite o nome do ingrediente %d: ", i + 1);
        scanf(" %[^\n]", novaPizza.ingredientes[i].nome);

        printf("Digite o preco do ingrediente %d: ", i + 1);
        scanf("%f", &novaPizza.ingredientes[i].preco);
    }

    printf("Pizza '%s' Criada!!\n", novaPizza.nome);
    return novaPizza;
}


void realizarCompra(Pizza *pizzas, int quantidadePizzas, Ingrediente *ingredientes, int quantidadeIngredientes) {
    int escolhaPizza, ingredientesExtras[10], quantidadeExtras = 0;
    char tamanhoEscolha;
    char opcaoIngrediente;

    printf("Escolha uma pizza para comprar (1 a %d): \n", quantidadePizzas);
    for(int i = 0; i < quantidadePizzas; i++){
        printf("%d- %s\n", pizzas[i].id, pizzas[i].nome);
    }

    scanf("%d", &escolhaPizza);

    if (escolhaPizza < 1 || escolhaPizza > quantidadePizzas) {
        printf("Pizza inválida.\n");
        return;
    }

    Pizza pizzaEscolhida = pizzas[escolhaPizza - 1];

    printf("Escolha o tamanho da pizza (P, M, G): ");
    printf("\nO valor no tamanho P sera de: %.2f", pizzaEscolhida.preco*0.8);
    printf("\nO valor no tamanho M sera de: %.2f", pizzaEscolhida.preco);
    printf("\nO valor no tamanho G sera de: %.2f\n", pizzaEscolhida.preco*1.2);

    scanf(" %c", &tamanhoEscolha);
    if (tamanhoEscolha == 'P') {
        pizzaEscolhida.preco *= 0.8;  
    } else if (tamanhoEscolha == 'G') {
        pizzaEscolhida.preco *= 1.2; 
    }

    printf("Escolha ingredientes extras (separados por espacos):\n");
    printf("1. Queijo\n2. Cebola\n3. Catupiry\n4. Azeitona\n");
    printf("Digite os numeros dos ingredientes extras, e 0 para finalizar: ");
    while (1) {
        scanf("%d", &ingredientesExtras[quantidadeExtras]);
        if (ingredientesExtras[quantidadeExtras] == 0) break;
        quantidadeExtras++;
    }

    for (int i = 0; i < quantidadeExtras; i++) {
        if (ingredientesExtras[i] >= 1 && ingredientesExtras[i] <= 4) {
            pizzaEscolhida.preco += ingredientes[ingredientesExtras[i] - 1].preco;
        }
    }

    printf("Preco final: %.2f\n", pizzaEscolhida.preco);
}

void removerPizza(Pizza *pizzas, int *quantidadePizzas) {
    if (*quantidadePizzas == 0) {
        printf("Não há pizzas para remover.\n");
        return;
    }

    int id;
    printf("Digite o ID da pizza que deseja remover: ");
    scanf("%d", &id);

    int indiceRemover = -1;

    for (int i = 0; i < *quantidadePizzas; i++) {
        if (pizzas[i].id == id) {
            indiceRemover = i;
            break;
        }
    }

    if (indiceRemover == -1) {
        printf("ID %d Invalido!!\n", id);
        return;
    }

    for (int i = indiceRemover; i < *quantidadePizzas - 1; i++) {
        pizzas[i] = pizzas[i + 1];
    }

    (*quantidadePizzas)--;

    for (int i = 0; i < *quantidadePizzas; i++) {
        pizzas[i].id = i + 1;
    }

    printf("Pizza removida com sucesso.\n");
}

