typedef struct node{
  int value;
  node *next;
}node;

typedef struct List{
  node *head;
}List;


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

int procurar(int value, List *l){
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
    //não permite criação de valores repetidos
    if(aux->value == value) return;
    aux = aux->next;
  }
  aux->next = new;
}

int remover_da_lista(int key, List *l){

  node * aux = l->head;
  //remove cabeça
  if(aux->value == key){
    l->head = l->head->next;
    free(aux);
    return 1;
  }

  while(aux->next->value != key && aux->next!=NULL){
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
    printf("%d\t",aux->value);
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

  return 0;
}
