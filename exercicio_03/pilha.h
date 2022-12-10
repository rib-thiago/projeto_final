# define ITENS 10

typedef struct Node {
  int number;
  struct Node *next;
} Node;

typedef struct Stack {
  Node *top;
  int max_itens;
  int qty;
} Stack;

/* Inicialização da Pilha */

void inicializacaoPilha(Stack *s) {
    s->top = NULL;
    s->max_itens = ITENS;
    s->qty = 0;
}

/* Empilhar (inserir) um novo elemento na pilha */

void empilhar(int dado, Stack *s) {
  
  Node *aux = (Node*) malloc(sizeof(Node));
  
  if(!aux) {
    printf("Erro: Memoria Insuficiente");
    EXIT_FAILURE;
  } else if (s->qty >= s->max_itens) {
    printf("\n\tPilha cheia. Não é possível inserir mais nós\n");
    EXIT_FAILURE;
  } else {
    aux->number = dado;
    aux->next = s->top;
    s->top = aux;
    s->qty ++;
    //printf("\n\tInserção feito com sucesso.\n");
    }
}

/* Desempilhar (retirar) um elemento da pilha */

int desempilhar(Stack *s) {

  Node* aux = s->top;
  int dado;
    
  if(aux == NULL) {
    printf("\n\tPilha Vazia\n");
    EXIT_FAILURE;
  } else {
    s->top = aux->next;
    aux->next = NULL;
    dado = aux->number;
    s->qty --;
    free(aux);
  }
  return dado;
}

/* Exibir os elementos presentes na pilha */

void imprimePilha(Stack *s){

  Node *aux = s->top;
  if(aux == NULL) {
    printf("\n\tPilha Vazia\n");
    EXIT_FAILURE;
  } else {
    printf("\n\t\t\tPILHA\n");
    printf("  |-TOPO\n");
    printf("  v\n");
    printf("[ ");
    while(aux != NULL) {
      printf("%d ", aux->number);
      aux = aux->next;
    }
    printf("]\n\n\n");
    }
}

/* Verificar se um elemento está presente na pilha */

void buscaElementoNaPilha(int valor, Stack *s) {
  
  Node *aux = s->top;
  
  if(aux == NULL) {
    printf("\n\tPilha Vazia\n");
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

/* Retornar a quantidade de elementos contidos na pilha */

int size(Stack *s) {
    
  return s->qty;
}

/* Verificar se a pilha está cheia */

void is_full(Stack *s) {
  if (s->qty == s->max_itens)
    printf("Is full!");
  else
    printf("Isn't full");
  }

/* Verificar se a pilha está vazia */

void is_empty(Stack *s) {
  if (s->qty == 0)
    printf("Is empty!");
  else
    printf("Isn't empty");
  }


