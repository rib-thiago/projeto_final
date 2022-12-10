#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pilha.h"
#include "fila.h"

/*
  Função que gera valores aleatórios para a pilha
*/
void geraValoresParaPilha(Stack *s);

int main() {
    
  setlocale(LC_ALL, "Portuguese");

  Stack *s1 = (Stack*)malloc(sizeof(Stack));
  Queue *q1 = (Queue*)malloc(sizeof(Queue));
  Queue *q2 = (Queue*)malloc(sizeof(Queue));
    
  if(s1 == NULL || q1 == NULL || q2 == NULL) {
    printf("Erro: Memoria Insuficiente");
    EXIT_FAILURE;
  }

  int n;

  inicializacaoPilha(s1);
  geraValoresParaPilha(s1);
  printf("\t\tPILHA\n");
  imprimePilha(s1);

  inicializacaoFila(q1);
  inicializacaoFila(q2);
        
  while(s1->top != NULL) {

    n = desempilhar(s1);
    if(n % 2 == 0)
      enfileirar(n, q1);
    else enfileirar(n, q2);
  }
  
  printf("\n\t\t1º FILA - PARES\n");
  imprimeFila(q1);
  printf("\n\t\t2º FILA - IMPARES\n");
  imprimeFila(q2);
  
  return 0;
}

void geraValoresParaPilha(Stack *s) {

    int n = rand() % 100;
    while(n != 0) {
      empilhar(n, s);
      n = rand() % 100;
    }
}