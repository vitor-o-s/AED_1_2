#include<stdio.h>
#include<stdlib.h>

typedef struct Edge{
  int value, weight;
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

edge * create_edge(int value, int weight){
  edge *new;
  new = (edge *) malloc (sizeof(edge));
  if(new == NULL) return NULL;
  new->value = value;
  new->weight = weight;
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
      printf(" %d, peso: %d",edge_aux->value,edge_aux->weight);
      edge_aux = edge_aux->next;
    }
    aux = aux->next;
    printf("\n");
  }
}

void w_add(List *l, int V, int A, int W){
  node* aux = l->head;
  edge* new = create_edge(A, W);
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

List* adj_list(List *l, int n, int matrix[n][n]){

  int i, j;

  for(i = 0; i < n; i++)
    addV(l,i);

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      if(matrix[i][j] != 0)
        w_add(l,i,j,matrix[i][j]);
    }
  }
  return l;
}

void prim(){

  printf("0: -\n");
}

int main(void) {
  int i, j, n;
  scanf(" %d",&n);
  int adj_matrix[n][n];
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      scanf(" %d",&adj_matrix[i][j]);
    }
  }

  List *L = (List*) malloc (sizeof(List));
  inicializa(L);

  L = adj_list(L, n, adj_matrix);
  imprimirGrafo(L);

  return 0;
}

/* OUTPUT ESPERADO


0: -
1: 0
2: 1
3: 2
4: 3
5: 2
6: 5
7: 6
8: 2

*/
