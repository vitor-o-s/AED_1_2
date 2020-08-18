#include<stdio.h>
#include<stdlib.h>

typedef struct Edge{
  int value;
  struct Edge* next;
}edge;

typedef struct Node{
  int value;
  struct edge* edge_next;
  struct Node* next;
}node;

typedef struct list{
  node* head;
  int n_vertex;
}List;

void inicializa(List* l){
  l->head = NULL;
}

node * create_node(int value){
  node *new;
  new = (node *) malloc (sizeof(node));
  if(new == NULL) return NULL;
  new->value = value;
  new->edge_next = NULL;
  new->next = NULL;
  return new;
}

edge * create_edge(int value){
  edge *new;
  new = (edge *) malloc (sizeof(edge));
  if(new == NULL) return NULL;
  new->value = value;
  new->next = NULL;
  return new;
}

void addV(List *l, int value){
  //add no fim da lista
  node* new = create_node(value);
  if(l->head==NULL){
    l->head = new;
    return;
  }
  node* aux = l->head;

  while(aux->next!=NULL){
    //não permite criação de valores repetidos
    if(aux->value == value) return;
    aux = aux->next;
  }
  if(aux->value == value) return;
  aux->next = new;
  return;
}

void imprimirGrafo(List *l){
  node * aux = l->head;
  while(aux!=NULL){
    //Imprime o Vertice
    printf(" %d: ",aux->value);
    //Imprime lista de arestas
    edge* edge_aux;
    edge_aux = aux->edge_next;
    while (edge_aux!=NULL) {
      printf(" %d",edge_aux->value);
      edge_aux = edge_aux->next;
    }
    aux = aux->next;
    printf("\n");
  }
}

void w_add(List *l, int V, int A){
  node* aux = l->head;
  edge* new = create_edge(A);
  //Busca vertice
  while(aux->value!=V){
    aux = aux->next;
  }
  //Add ini
  if(aux->edge_next == NULL){
    aux->edge_next = new;
    return;
  }
  //Add fim
  edge* edge_aux = aux->edge_next;

  while(edge_aux->next!=NULL){
    edge_aux = edge_aux->next;
  }
  edge_aux->next = new;
  return;
}

void direcionado(List *l, int n){

  node *aux = l->head;
  edge *edge_aux;
  int i, j, M[n][n];

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      M[i][j]=0;
    }
  }

  i = 0;

  while(aux!=NULL){

    edge_aux = aux->edge_next;
    j = 0;

    while(edge_aux!=NULL){
      j = edge_aux->value;
      M[i][j] = 1;
      edge_aux = edge_aux->next;
    }
    aux = aux->next;
    i++;
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(M[i][j]!=M[j][i]){
        printf("nao direcionado\n");
        return;
      }
    }
  }
  printf("direcionado\n");
  return;
}

int main(void){

  int n, i, edge;
  scanf(" %d",&n);
  List *L = (List*) malloc (sizeof(List));

  inicializa(L);
  for(i=0;i<n;i++)
    addV(L,i);
  char buffer;

  for(i=-1;i<n;i++){
    while (scanf("%c",&buffer)==1 && buffer!='\n'){

      if(buffer!=' '){
        edge = buffer - '0';
        if(edge!=-1){
          w_add(L,i,edge);
        }
      }
    }
  }
  direcionado(L,n);

  return 0;
}
