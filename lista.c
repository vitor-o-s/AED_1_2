#include<stdlib.h>
#include<stdio.h>

typedef struct Node{
  int value;
  struct Node* next;
}node;

typedef struct list{
  node* head;
}List;


void inicializa(List* l){
  l->head = NULL;
}

node * create_node(int value){
  node *new;
  new = (node *) malloc (sizeof(node));
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

int procurar(List *l, int value){
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

void add(List *l, int value){
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

int remover_da_lista(List *l, int value){

  //if(procurar(l, value)==0) return 0;

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

void imprimir(List *l){

  node * aux = l->head;
  while(aux!=NULL){
    printf(" %d\t",aux->value);
    aux = aux->next;
  }

}

int liberar_lista(List *l){

  node *aux;
  while(isvoid(l)!=0){
    aux = l->head;
    l->head = l->head->next;
    free(aux);
  }
  return 1;
}

int main(void){

  List *L = (List*) malloc (sizeof(List));
  inicializa(L);
  add(L,1);
  add(L,2);
  add(L,3);
  add(L,4);
  add(L,5);
  add(L,6);
  add(L,7);
  add(L,8);
  add(L,9);
  add(L,10);
  add(L,11);
  add(L,11);
  add(L,1);
  imprimir(L);
  //remover_da_lista(L,1);
  remover_da_lista(L,1);
  remover_da_lista(L,11);
  //remover_da_lista(L,11);
  imprimir(L);
  liberar_lista(L);
  imprimir(L);
  free(L);

  return 0;
}
