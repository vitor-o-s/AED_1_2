#include <stdio.h>
#include <stdlib.h>

typedef struct Leaf{
  int value, fator_balanceamento;
  struct Leaf * left;
  struct Leaf *right;
}leaf;

typedef struct Tree{
  leaf *root;
  int balanceamento;
}tree;

void init(tree* t){
  t->root = NULL;
  t->balanceamento = 1;
}

leaf* create_leaf(int value){
  leaf *new = (leaf *) malloc (sizeof(leaf));
  if(new == NULL) return NULL;
  new->value = value;
  new->left = new->right = NULL;
  new->fator_balanceamento = 0;
  return new;
}

int maior(int a, int b){
  if(a > b) return a;
  return b;
}

int altura(leaf *root){
  if(root == NULL) return 0;
  return  1 + maior(altura(root->left),altura(root->right));
}

leaf* insert(leaf *root, int value){

  if (root == NULL) return create_leaf(value);

  if (value < root->value)
      root->left  = insert(root->left, value);
  else if (value > root->value)
      root->right = insert(root->right, value);

  return root;
}

void calcula_balanceamento(leaf *root){
  if(root!=NULL){
    int altura_esq = altura(root->left);
    int altura_dir = altura(root->right);
    root->fator_balanceamento = altura_esq - altura_dir;
    calcula_balanceamento(root->left);
    calcula_balanceamento(root->right);
  }
}

void AVL(leaf *root, tree *t){
  if (root != NULL){
    if(root->fator_balanceamento>1 || root->fator_balanceamento<-1){
      t->balanceamento = 0;
      return;
    }
    AVL(root->left,t);
    AVL(root->right,t);
  }
}

int main(void) {

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

    calcula_balanceamento(t->root);
    AVL(t->root,t);
    printf("%d\n",t->balanceamento);

    return 0;
}
