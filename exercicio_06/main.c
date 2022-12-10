#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "biblioteca.h"
#include "thiago.h"

void getDados(Node *dados);
void imprimeDadosVinho(Node *dados);
void vinhoOcasiaoEspecial(Stack *s);
void cincoMaisAntigos(Stack *s);

int main() {

  setlocale(LC_ALL, "Portuguese");

  char menu;
  int opcao;
  
  Stack *catalogo = (Stack*)malloc(sizeof(Stack));
  Node *dadosVinho = (Node*) malloc(sizeof(Node));
    
  if(catalogo == NULL || dadosVinho == NULL) {
    printf("Erro: Memoria Insuficiente");
    EXIT_FAILURE;
  }

  inicializacao(catalogo);

  do {

    display();
    scanf("%c", &menu);
    limpabuffer();

    switch (menu) {
      case '1':
           getDados(dadosVinho);
           empilhar(dadosVinho, catalogo);
           printf("\n\tCadastro efetuado com sucesso");
           break;
      case '2':
           desempilhar(dadosVinho, catalogo);
           printf("\n\tVINHO PARA OCASIÃO NÃO ESPECIAL\n");
           imprimeDadosVinho(dadosVinho);
           break;
      case '3':
           printf("\n\tVINHO PARA OCASIÃO ESPECIAL\n");
           vinhoOcasiaoEspecial(catalogo);
           break;
      case '4':
           printf("\n\n\t  OS 5 VINHOS MAIS ANTIGOS DO CATALOGO\n", catalogo->qty);
           cincoMaisAntigos(catalogo);
           break;
      case '5':
           printf("\n\n\t  OS 5 VINHOS MAIS ADQUIRIDOS POR ÚLTIMO\n", catalogo->qty);
           imprimePilha(catalogo, 5);
           break;
      case '6':
           printf("\n\n\t  CATALOGO");
           imprimePilha(catalogo, catalogo->qty);
           break;
      case '7':
            // sair do programa
            break;
      default:
            printf("\nOpção( %d )inválido.\n", menu);
    }

    printf("\nPressione 1 (um) para retornar ao menu ou 0 (zero) para sair\n");
    scanf("%d", &opcao);
    limpabuffer();

  } while (menu != 0);
    
    return 0;
}
  
void getDados(Node *dados) {

  printf("\n\tDIGITE OS DADOS DO VINHO\n");

  printf("\nNome do vinho: ");
  fgets(dados->nome, MAX, stdin);
    
  printf("País de origem: ");
  fgets(dados->pais, MAX, stdin);
    
  printf("Tipo de uva: ");
  fgets(dados->tipo, MAX, stdin);
      
  printf("Safra: ");
  scanf("%d",&dados->safra);
  
}

void imprimeDadosVinho(Node *dados) {
  
  printf("\nNome do produto: %s", dados->nome);
  printf("\nPaís de origem: %s", dados->pais);
  printf("\nTipo de uva: %s", dados->tipo);
  printf("\nSafra: %d", dados->safra);
}

void vinhoOcasiaoEspecial(Stack *s) {

  Stack *aux = (Stack*)malloc(sizeof(Stack));
  Node *dados = (Node*) malloc(sizeof(Node));
    
  if(!aux) {
    printf("Erro: Memoria Insuficiente");
    EXIT_FAILURE;
  }
   
  inicializacao(aux);
  
  int i, n = s->qty;
  for(i = 0; i < n; i++) {
    desempilhar(dados, s);
    empilhar(dados, aux);
  }
  
  desempilhar(dados, aux);
  imprimeDadosVinho(dados);
  
  for(i = 0; i < n-1; i++) {
    desempilhar(dados, aux);
    empilhar(dados, s);
  }
  
}

void cincoMaisAntigos(Stack *s) {

  Stack *aux = (Stack*)malloc(sizeof(Stack));
  Node *dados = (Node*) malloc(sizeof(Node));
    
  if(!aux) {
    printf("Erro: Memoria Insuficiente");
    EXIT_FAILURE;
  }
   
  inicializacao(aux);
  
  int i, n = s->qty;
  
  for(i = 0; i < n; i++) {
    desempilhar(dados, s);
    empilhar(dados, aux);
  }

  imprimePilha(aux, 5);
  
  for(i = 0; i < n; i++) {
    desempilhar(dados, aux);
    empilhar(dados, s);
  }

}