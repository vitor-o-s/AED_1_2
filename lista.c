#include<stdio.h>
//#include<
typedef struct node{
  int value;
  node *next;
};
typedef struct List{
  node *head;
};

void inicializa(List* l){
  l->head = NULL;
}

int isvoid(List*l){
  if (l->head == NULL) return 0;
  return 1;
}

void add(List *l, int v){
  if(isvoid(l)==1){
    node* aux;
    while(aux!=NULL){

    }
  }
}
/*Lista* criar_lista();

Cell* criar_celula(int key);

int lista_vazia(Lista *l);

int procurar(int key, Lista *l);

int remover_na_lista(int key, Lista *l);

void inserir_na_lista(int key, Lista *l);

void imprimir(Lista *l);

int liberar_lista(Lista *l);*/
int main(void){

  return 0;
}
