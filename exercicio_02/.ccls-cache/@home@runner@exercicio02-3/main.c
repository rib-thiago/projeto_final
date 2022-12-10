#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "fila.h"

void limpabuffer (void) {
    char c;
    while ((c = getchar()) != '\n' );
}

void display (void)
{

    printf("\33[H\33[2J");
    printf("Menu:\n");
    printf("1 - Inserir Nó na fila\n2 - Retirar Nó da fila\n");
    printf("3 - Imprimir Nós da fila\n4 - Buscar Nó na fila\n");
    printf("5 - Quantidade de Nós da fila\n6 - A fila está cheia?\n7 - A fila está vazia?\n");
    printf("8 - Sair\n\n");

}

int main(void) {

  
  setlocale(LC_ALL, "Portuguese");

  char menu;
  int num, opcao;
  
  Queue *q = (Queue*)malloc(sizeof(Queue));
  if(!q) {
    printf("Erro: Memoria Insuficiente");
    EXIT_FAILURE;
  } 

  inicializacaoFila(q);

  do {

    display();
    scanf("%c", &menu);
    limpabuffer();

    switch (menu) {

      case '1':
            printf("\33[H\33[2J");
            printf("\nDigite um número a ser inserido: ");
            scanf("%d",&num);
            limpabuffer();
            enfileirar (num, q);
            break;

        case '2':
            printf("\33[H\33[2J");
            num = desenfileirar(q);
            printf("\n\tValor retirado da pilha: %d", num);
            break;

        case '3':
            printf("\33[H\33[2J");
            imprimeFila(q);
            break;

        case '4':
            printf("\33[H\33[2J");
            printf("\nDigite um número a ser buscado: ");
            scanf("%d",&num);
            limpabuffer();
            buscaElementoNaFila(num, q);
            break;

        case '5':
            printf("\33[H\33[2J");
            num = size(q);
            printf("\n\tQuantidade de Nós: %d", num);
            break;

        case '6':
            printf("\33[H\33[2J");
            is_full(q);
            break;

        case '7':
            printf("\33[H\33[2J");
            is_empty(q);
            break;

        case '8':
            // sair do programa
            break;

        default:
            printf("\nOpção Inválida! Escolha um número entre 1 e 5\n");
        }

        printf("\nPressione 1 (um) para retornar ao menu ou 0 (zero) para sair\n");
        scanf("%d", &opcao);
        limpabuffer();

    } while (opcao != 0);

  free (q);
  return EXIT_SUCCESS;
}


