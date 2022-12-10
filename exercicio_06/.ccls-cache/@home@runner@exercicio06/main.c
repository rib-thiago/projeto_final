#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "biblioteca.h"
#include "thiago.h"

void getDados(Node *dados);
void imprimeDadosVinho(Node *dados);
void vinhoOcasiaoNaoEspecial(Stack *s);
void cincoMaisAntigos(Stack *s);

int main() {

  setlocale(LC_ALL, "Portuguese");

  char menu;
  int n;
  
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

    switch (opc) {
      case 1:
           getDados(dadosVinho);
           empilhar(dadosVinho, catalogo);
           printf("\n\tCadastro efetuado com sucesso");
           break;
      case 2:
           desempilhar(dadosVinho, catalogo);
           printf("\n\tVINHO PARA OCASIÃO ESPECIAL\n");
           imprimeDadosVinho(dadosVinho);
           break;
      case 3:
           printf("\n\tVINHO PARA OCASIÃO NÃO ESPECIAL\n");
           vinhoOcasiaoNaoEspecial(catalogo);
           break;
      case 4:
           printf("\n\n\t  EXISTEM %d VINHOS EM ESTOQUE\n", estoque->qty);
           cincoMaisAntigos(catalogo);
           break;
      case 5:
           printf("\n\n\t  EXISTEM %d VINHOS EM ESTOQUE\n", estoque->qty);
           imprimePilha(catalogo, 5);
           break;
      case 6:
           printf("\n\n\t  CATALOGO");
           imprimePilha(catalogo, catalogo->qty);
           break;
      default:
            printf("\nOpção( %d )inválido.\n", opc);
    }
        } while (opc != 0);
    
    return 0;
}
  }
  

        printf("\t\t\t\tADEGA DE VINHOS");
        do
        {
            opc = lista_operacoes();
            if(estoque->qty <=0 && opc != 1)
            {
                do
                {
                    imprimePilha(estoque, estoque->qty);
                    opc = lista_operacoes();
                }while(opc != 1);
            }
            switch (opc)
            {
                case 0:
                    break;
                case 1:
                    getDados(dadosVinho);
                    empilhar(dadosVinho, estoque);
                    printf("\n\tCadastro efetuado com sucesso");
                    break;
                case 2:
                    desempilhar(dadosVinho, estoque);
                    printf("\n\tVINHO PARA OCASIÃO ESPECIAL\n");
                    imprimeDadosVinho(dadosVinho);
                    break;
                case 3:
                    printf("\n\tVINHO PARA OCASIÃO NÃO ESPECIAL\n");
                    vinhoOcasiaoNaoEspecial(estoque);
                    break;
                case 4:
                    printf("\n\n\t  EXISTEM %d VINHOS EM ESTOQUE\n", estoque->qty);
                    cincoMaisAntigos(estoque);
                    break;
                case 5:
                    printf("\n\n\t  EXISTEM %d VINHOS EM ESTOQUE\n", estoque->qty);
                    imprimePilha(estoque, 5);
                    break;
                case 6:
                    printf("\n\n\t  ESTOQUE");
                    imprimePilha(estoque, estoque->qty);
                    break;
                default:
                    printf("\nOpção( %d )inválido.\n", opc);
            }
        }while (opc != 0);
    }
    return 0;
}

int lista_operacoes()
{
    int n;
    printf("\n\n\t  MENU\n"
           "\n  1 - Cadastrar vinho"
           "\n  2 - Retira Vinho para ocasião especial"
           "\n  3 - Retira Vinho para ocasião NÃO especial"
           "\n  4 - cinco aquisições mais antigas"
           "\n  5 - cinco aquisições mais recentes"
           "\n  6 - Lista estoque"
           "\n  0 - Sair\n");
    printf("\nDigite o número da opção desejada: ");
    fflush(stdin);scanf("%d", &n);
    return n;
}

void getDados(NO *dados)
{
    printf("\n\tDIGITE OS DADOS DO VINHO\n");

    printf("\nNome do produto: ");
    fflush(stdin); scanf("%s",dados->nome);

    printf("País de origem: ");
    fflush(stdin); scanf("%s",dados->paisOrigem);

    printf("Tipo de uva: ");
    fflush(stdin); scanf("%s",dados->tipoUva);

    printf("Safra: ");
    fflush(stdin); scanf("%d",&dados->safra);
}

void imprimeDadosVinho(NO *dados)
{
    printf("\nNome do produto: %s", dados->nome);
    printf("\nPaís de origem: %s", dados->paisOrigem);
    printf("\nTipo de uva: %s", dados->tipoUva);
    printf("\nSafra: %d", dados->safra);
}

void vinhoOcasiaoNaoEspecial(PILHA *p)
{
    PILHA *aux = (PILHA*)malloc(sizeof(PILHA));
    NO *dados = (NO*) malloc(sizeof(NO));
    if(aux == NULL || dados == NULL)
    {
        printf("\n\tErro!!!.\n");
        return;
    }
    else
    {
        inicializacaoPilha(aux);
        int i, n;
        n = p->qty;
        for(i = 0; i < n; i++)
        {
            desempilhar(dados, p);
            empilhar(dados, aux);
        }
        desempilhar(dados, aux);
        imprimeDadosVinho(dados);
        for(i = 0; i < n-1; i++)
        {
            desempilhar(dados, aux);
            empilhar(dados, p);
        }
    }
}

void cincoMaisAntigos(PILHA *p)
{
    PILHA *aux = (PILHA*)malloc(sizeof(PILHA));
    NO *dados = (NO*) malloc(sizeof(NO));
    if(aux == NULL || dados == NULL)
    {
        printf("\n\tErro!!!.\n");
        return;
    }
    else
    {
        inicializacaoPilha(aux);
        int i, n;
        n = p->qty;
        for(i = 0; i < n; i++)
        {
            desempilhar(dados, p);
            empilhar(dados, aux);
        }
        imprimePilha(aux, 5);
        for(i = 0; i < n; i++)
        {
            desempilhar(dados, aux);
            empilhar(dados, p);
        }
    }
}