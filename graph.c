#include<stdlib.h>
#include<stdio.h>

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

int removerV(List *l, int value){

  node * aux = l->head;
  //remove cabeça
  if(aux->value == value){
    l->head = l->head->next;
    free(aux);
    return 1;
  }

  while(aux->next!=NULL  && aux->next->value!= value){
    aux = aux->next;
  }

  //remove resto
  node *erase;
  erase = aux->next;
  aux->next = erase->next;
  free(erase);
  return 1;

}

void w_removeE(List *l, int V, int E){

  node* aux;
  aux = l->head;
  while(aux->value!=V){
    aux = aux->next;
  }
  edge* edge_aux = aux->edge_next;

  if(edge_aux->value == E){
    edge *erase;
    erase = edge_aux->next;
    edge_aux->next = erase->next;
    free(erase);
  }

  while(edge_aux->next!=NULL && edge_aux->next->value!=E){
    edge_aux = edge_aux->next;
  }
  if(edge_aux->next->value == E){
    edge *erase;
    erase = edge_aux->next;
    edge_aux->next = erase->next;
    free(erase);
  }


}

int removerE(List *l, int v1, int v2){
  if(procurarVertice(l,v1)==1 && procurarVertice(l,v2)==1){
    w_removeE(l,v1,v2);
    w_removeE(l,v2,v1);
  }
}

void imprimirGrafo(List *l){
  node * aux = l->head;
  while(aux!=NULL){
    //Imprime o Vertice
    printf(" %d: ",aux->value);
    //Imprime lista de arestas
    node* edge_aux;
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
/*
int liberar_lista(List *l){

  node *aux;
  while(isvoid(l)!=0){
    aux = l->head;
    l->head = l->head->next;
    free(aux);
  }
  return 1;
}*/

int main(void){

  List *L = (List*) malloc (sizeof(List));
  inicializa(L);
  addV(L,1);
  addV(L,2);
  addV(L,3);
  addV(L,4);
  addV(L,5);
  addV(L,6);
  addV(L,7);
  addV(L,8);
  addV(L,9);
  addV(L,10);
  addV(L,11);
  addA(L,1,2);
  addA(L,1,3);
  addA(L,2,3);
  imprimirGrafo(L);
  removerE(L,1,2);
  imprimirGrafo(L);
  //free(L);

  return 0;
}
