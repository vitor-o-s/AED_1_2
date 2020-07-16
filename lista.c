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

node* create_node(int value){
  node *new;
  new = (node*) malloc (sizeof(node));
  if(new == NULL) return NULL;
  new->value;
  new->next = NULL;
  return new;
}

int isvoid(List*l){
  //Verifica se lista está vazia para fins de add
  //Retorna 0 se vazia e 1 se contem elementos
  if (l->head == NULL) return 0;
  return 1;
}

int procurar(int value, Lista *l){
  //Retorna 1 caso ja exista o valor do nó
  //E 0 caso não seja encontrado
  node* aux;
  aux = l->head;
  while(aux->value != value && aux!=NULL){
    aux = aux->next;
  }
  if(aux == NULL) return 0;
  return 1;

}

void add(List *l, int value){
  //add no fim da lista
  node* new = create_node(value);
  if(isnull(l)==0){
    l->head = new;
    return;
  }
  node* aux = l->head;

  while(aux->next!=NULL){
    aux = aux->next;
  }
  aux->next = new;
}

int remover_da_lista(int key, Lista *l){

  node * aux = l->head;

  while(aux->value != key && aux!=NULL){
    aux = aux->next;
  }

}

void imprimir(Lista *l);

int liberar_lista(Lista *l);

int main(void){

  return 0;
}
