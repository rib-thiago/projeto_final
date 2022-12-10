#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "fila.h"

/*
  Função que gera valores aleatórios para a fila e já traz ordenado os valores dentro dela
*/
void geraValoresParaFila(Queue *q);

/*
    Função que ordena os valores de uma fila
*/
void ordenaFila(Queue *q);

/*
    Método de ordenação escolhido, Selection Sort
*/
void selectionsort(int v[],int n);

int main() {
    
  setlocale(LC_ALL, "");

  Queue *q1 = (Queue*)malloc(sizeof(Queue));
  Queue *q2 = (Queue*)malloc(sizeof(Queue));
  Queue *q3 = (Queue*)malloc(sizeof(Queue));
    
  if(q1 == NULL || q2 == NULL || q3 == NULL)  {
    printf("Erro: Memoria Insuficiente");
    EXIT_FAILURE;
  } 

  inicializacaoFila(q1);
  geraValoresParaFila(q1);
  printf("1º Fila: \n");
  imprimeFila(q1);

  inicializacaoFila(q2);
  geraValoresParaFila(q2);
  printf("2º Fila: \n");
  imprimeFila(q2);

  inicializacaoFila(q3);
  
  while(q1->head != NULL || q2->head != NULL) {
    if(q1->head == NULL && q2->head != NULL)
      enfileirar(desenfileirar(q2), q3);
    else if(q2->head == NULL && q1->head != NULL)
      enfileirar(desenfileirar(q1), q3);
    else if(q1->head->number < q2->head->number )
      enfileirar(desenfileirar(q1), q3);
    else enfileirar(desenfileirar(q2), q3);
  }
  printf("\n3º Fila: \n");
  imprimeFila(q3);
  

        /*
            Estou imprimindo as duas primeiras filas para verificar que de fato os valores delas
            foram atribuidos a 3º fila e elas estão vazias

  printf("\n1º Fila");
        imprimirFila(f1);
        printf("\n2º Fila");
        imprimirFila(f2);
        */
      
    
    return 0;
}

void geraValoresParaFila(Queue *q)
{
    int i;
    for(i = 0; i < q->max_itens/2; i++)
    {
        enfileirar(rand() % 101, q);
    }
    ordenaFila(q);
}

void ordenaFila(Queue *q)
{
    int n[q->max_itens], i, qtd;
    qtd = q->qty;

    for(i = 0; i < qtd; i++)
    {
        n[i] = desenfileirar(q);
    }

    selectionsort(n, qtd);

    for(i = 0; i < qtd; i++)
    {
        enfileirar(n[i], q);
    }
}

void selectionsort(int v[],int n) {
  int i, j, max, aux;

  for (i = 0; i < (n - 1); i++) {
    max = i;
    for (j = i+1; j < n; j++) {
      if (v[j] < v[max]) {
        max = j;
      }
    }
    if (i != max) {
      aux = v[i];
      v[i] = v[max];
      v[max] = aux;
    }
  }
}