#include<stdio.h>
#include<stdlib.h>

#define RED   5
#define BLACK 10

typedef struct Leaf{
  int value;
  struct Leaf *left;
  struct Leaf *right;
  struct Leaf *parent;
  int color;
  int balance_value;
}leaf;

typedef struct Tree{
  leaf *root;
  int balance;
}tree;

void init(tree* t){
  t->root = NULL;
  t->balance = 0;
}

leaf* create_leaf(int value){
  leaf *new = (leaf *) malloc (sizeof(leaf));
  if(new == NULL) return NULL;
  new->value = value;
  new->color = RED;
  new->left = new->right = new->parent = NULL;
  return new;
}

leaf* insert(tree* root, int value){

  if(root == NULL){
    return create_leaf(value);
  }
  if(value < root->value){
    root->left = insert(root->left,value);
    root->left->parent = root;
  }
  if(value > root->value){
    root->right = insert(root->right,value);
    root->right->parent = root;
  }

  return root;
}

int maior(int a, int b){
  if(a>b) return a;
  return b;
}

int bh(leaf* root){

}


int main(void){

  int n;
  scanf(" %d",&n);

  tree *t = (tree*) malloc (sizeof(tree));
  init(t);
  int i, key;
  scanf(" %d",&key);
  t->root = insert(t->root, key);

  for(i=1; i<n; i++){
      scanf(" %d",&key);
      insert(t->root, key);
  }
  //Inserir ordenado ou ordenar depois
  while(t->balance > 1 || t->balance < -1){
    //Reorganiza
    //calcula fator de balanceamento

  }

  printf("%d\n",maior(bh(t->root->left),bh(t->root->left)));

  return 0;
}
