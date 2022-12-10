#define MAX 30

typedef struct Node {
  char nome[MAX];
  char pais[MAX];
  char tipo[MAX];
  int safra;
  //int especial;
  struct Node *next;
} Node;

typedef struct Stack {
  Node *top;
  int qty;
} Stack;

void inicializacao(Stack *s) {
  s->top = NULL;
  s->qty = 0;
}

void empilhar(Node *dado, Stack *s) {

  Node *aux = (Node*) malloc(sizeof(Node));
  int i;
    
  if(!aux) {
    printf("Erro: Memoria Insuficiente");
    EXIT_FAILURE;
  }
  
  strcpy(aux->nome, dado->nome);
  strcpy(aux->pais, dado->pais);
  strcpy(aux->tipo, dado->tipo);
  aux->safra = dado->safra;
  aux->next = s->top;
  s->top = aux;
  s->qty ++;
  
}

void desempilhar(Node *dado, Stack *s) {

  Node *aux = s->top;
  int i;

  if(!aux) {
    printf("Erro: Estoque Vazio");
    EXIT_FAILURE;
  }
  
  s->top = aux->next;
  aux->next = NULL;
  strcpy(dado->nome, aux->nome);
  strcpy(dado->pais, aux->pais);
  strcpy(dado->tipo, aux->tipo);
  dado->safra = aux->safra;
  s->qty --;
  free(aux);
  
}

void imprimePilha(Stack *s, int n) {

  Node *aux = s->top;
  int i;
    
  if(!aux) {
    printf("Erro: Estoque Vazio");
    EXIT_FAILURE;
  }
  
  if (n == 5)
    for (i = 0; i < 5 && aux != NULL; i++) {
      printf("\n\nNome do vinho: %s ", aux->nome);
      printf("\nPaís de origem: %s ", aux->pais);
      printf("\nTipo de uva: %s ", aux->tipo);
      printf("\nSafra: %d ", aux->safra);
      aux = aux->next;
    }

   while(aux != NULL) {
     printf("\n\nNome do vinho: %s ", aux->nome);
     printf("\nPaís de origem: %s ", aux->pais);
     printf("\nTipo de uva: %s ", aux->tipo);
     printf("\nSafra: %d ", aux->safra);
     aux = aux->next;
   }
    
}

