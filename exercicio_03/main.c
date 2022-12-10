#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pilha.h"

/*
  Função que gera valores aleatórios para a pilha e já traz ordenado os valores dentro dela
*/
void geraValoresParaPilha(Stack *s);

/*
    Função que ordena os valores de uma pilha
*/
void ordenaPilha(Stack *s);

/*
    Método de ordenação escolhido, Selection Sort
*/
void selectionsort(int v[],int n);



int main() {

  setlocale(LC_ALL, "");

  Stack *s1 = (Stack*)malloc(sizeof(Stack));
  Stack *s2 = (Stack*)malloc(sizeof(Stack));
  Stack *s3 = (Stack*)malloc(sizeof(Stack));

  if(s1 == NULL || s2 == NULL || s3 == NULL){
    printf("Erro: Memoria Insuficiente");
    EXIT_FAILURE;
  } 
  
  inicializacaoPilha(s1);
  geraValoresParaPilha(s1);
  printf("1º Pilha: \n");
  imprimePilha(s1);

  inicializacaoPilha(s2);
  geraValoresParaPilha(s2);
  printf("2º Pilha: \n");
  imprimePilha(s2);

  inicializacaoPilha(s3);
  while(s1->top != NULL || s2->top != NULL) {
    if(s1->top == NULL && s2->top != NULL)
      empilhar(desempilhar(s2), s3);
    else if(s2->top == NULL && s1->top != NULL)
      empilhar(desempilhar(s1), s3);
    else if(s1->top->number < s2->top->number )
      empilhar(desempilhar(s1), s3);
    else empilhar(desempilhar(s2), s3);
  }
  printf("\n3º Pilha: \n");
  imprimePilha(s3);

        /*
            Estou imprimindo as duas primeiras pilhas para verificar que de fato os valores delas
            foram atribuidos a 3º pilha e elas estão vazias

printf("\n1º Pilha");
        imprimePilha(s1);
        printf("\n2º Pilha");
        imprimePilha(s2);
        */
        
    
  return 0;
}

void geraValoresParaPilha(Stack *s) {
    
  int i;
  for(i = 0; i < s->max_itens/2; i++)
    empilhar(rand() % 101, s);
  ordenaPilha(s);
}

void ordenaPilha(Stack *s)
{
    int n[s->max_itens], i, qtd;
    qtd = s->qty;

    for(i = 0; i < qtd; i++) 
      n[i] = desempilhar(s);
    
    selectionsort(n, qtd);

    for(i = 0; i < qtd; i++)
      empilhar(n[i], s);
    
}

void selectionsort(int v[],int n) {
  int i, j, max, aux;

  for (i = 0; i < (n - 1); i++) {
    max = i;
    for (j = i+1; j < n; j++) {
      if (v[j] > v[max]) {
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