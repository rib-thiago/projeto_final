#include <stdio.h>
#include <stdlib.h>
# define ITENS 10

typedef struct Node {
  int number;
  struct Node *next;
} Node;

typedef struct Queue {
  Node *head;
  Node *tail;
  int max_itens;
  int qty;
} Queue;

/* Inicialização da Fila */

void inicializacaoFila(Queue *q) {
    q->head = NULL;
    q->tail = NULL;
    q->max_itens = 10;
    q->qty = 0;
}

/* Inserir um elemento na fila */

void enfileirar(int dado, Queue *q) {
    
  Node *aux = (Node*) malloc(sizeof(Node));
  
  if(!aux) {
    printf("Erro: Memoria Insuficiente");
    EXIT_FAILURE;
  } else if (q->qty >= q->max_itens) {
    printf("\n\tFila cheia. Não é possível inserir mais nós\n");
    EXIT_FAILURE;
  } else {
    aux->number = dado;
    aux->next = NULL;
    if(q->head == NULL)
        q->head = aux;
    else
        q->tail->next = aux;
    q->tail = aux;
    q->qty++;
    }
}

/* Retirar um elemento da fila */

int desenfileirar(Queue *q) {
  
  Node *aux = q->head;
  int dado;
    
  if(aux == NULL) {
      printf("\n\tFila vazia!\n");
      EXIT_FAILURE;
  } else {
    q->head = aux->next;
    aux->next = NULL;
    dado = aux->number;
    q->qty--;
    free(aux);
    if(q->head == NULL)
      q->tail = NULL;
    return dado;
    }
}

/* Exibir os elementos presentes na fila */

void imprimeFila(Queue *q) {
    
  Node *aux = q->head;

  if(aux == NULL) {
      printf("\n\tFila vazia!\n");
      EXIT_FAILURE;
  } else {
    printf("\n\t\t\tFILA\n");
    printf("  |-INÍCIO\n");
    printf("  v\n");
    printf("[ ");
    while(aux != NULL) {
      printf("%d ", aux->number);
      aux = aux->next;
    }
    printf("]\n");
  }
}

/* Verificar se um elemento está presente na fila */

void buscaElementoNaFila(int valor, Queue *q) {
    
  Node *aux = q->head;
  if(aux == NULL) {
      printf("\n\tFila vazia!\n");
      EXIT_FAILURE;
  } else {
    while(aux != NULL) {
      if(aux->number == valor) {    
        printf("\n\tValor %d encontrado!!\n", valor);
        return;
        }
      aux = aux->next;
    }
    printf("\n\tValor %d NÃO encontrado!!\n", valor);
  }
}


/* Retornar a quantidade de elementos contidos na fila */

int size(Queue *q) {
  return q->qty;
}


/* Verificar se a fila está cheia */

void is_full(Queue *q) {
  if (q->qty == q->max_itens)
    printf("Is full!");
  else
    printf("Isn't full");
}

/* Verificar se a fila  está vazia */

void is_empty(Queue *q) {
   if (q->qty == 0)
    printf("Is empty!");
  else
    printf("Isn't empty");
}




