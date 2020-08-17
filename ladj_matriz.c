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

int isvoid(List*l){
  //Verifica se lista está vazia para fins de add
  //Retorna 0 se vazia e 1 se contem elementos
  if (l->head == NULL) return 0;
  return 1;
}

int procurarVertice(List *l, int value){
  //Retorna 1 caso ja exista o valor do nó
  //E 0 caso não seja encontrado
  node* aux;
  aux = l->head;
  while(aux!=NULL){
    if(aux->value == value) return 1;
    aux = aux->next;
  }
  if(aux == NULL) return 0;
  return 1;

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

void addA(List *l, int v1, int v2){
  //Função chama wrapper
  if(procurarVertice(l,v1)==1 && procurarVertice(l,v2)==1){
    w_add(l,v1,v2);
    w_add(l,v2,v1);
  }
}

int main(void){

  int n, i, edge;
  scanf(" %d",&n);
  List *L = (List*) malloc (sizeof(List));
  List *L2 = (List*) malloc (sizeof(List));
  inicializa(L2);
  addV(L2,0);
  addV(L2,1);
  addV(L2,2);
  addV(L2,3);
  addV(L2,4);
  w_add(L2,0,1);
  w_add(L2,0,2);
  w_add(L2,1,0);
  w_add(L2,1,4);
  w_add(L2,2,0);
  w_add(L2,2,3);
  w_add(L2,2,4);
  w_add(L2,3,2);
  w_add(L2,3,4);
  w_add(L2,4,1);
  w_add(L2,4,2);
  w_add(L2,4,3);

  inicializa(L);
  for(i=0;i<n;i++)
    addV(L,i);

  char buffer;

  for(i=0;i<n;i++){
    //printf("okay\n");
    //for(j=0;j<n;j++){
    //  if(scanf("%s\n", );)
    //}
    while (scanf("%c%d",&buffer,&edge)==2 && buffer!='\n'){

      w_add(L,i,edge);
      //printf("while\n");
    }
    //printf("saiu\n");
  }
  imprimirGrafo(L);
  imprimirGrafo(L2);





  return 0;
}
