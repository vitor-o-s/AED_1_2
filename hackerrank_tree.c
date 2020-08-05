#include <stdio.h>
#include <stdlib.h>

typedef struct Leaf{
  int value;
  struct Leaf * left;
  struct Leaf *right;
}leaf;

typedef struct Tree{
  leaf *root;
}tree;

void init(tree* t){
  t->root = NULL;
}

leaf* create_leaf(int value){
  leaf *new = (leaf *) malloc (sizeof(leaf));
  if(new == NULL) return NULL;
  new->value = value;
  new->left = new->right = NULL;
  return new;
}

void inorder(leaf *root){

    if (root != NULL){
      inorder(root->left);
        if(root->left == NULL && root->right == NULL){
            printf(" %d", root->value);
        }
      inorder(root->right);
    }
}

int maior(int a, int b){
  if(a > b) return a;
  return b;
}

int altura(leaf *root){
  //if(root->right == NULL || root->left == NULL) return 0;
  //if() return 1;
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

int main() {

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
    if(t->root!=NULL){

      printf("%d\n",maior(altura(t->root->left),altura(t->root->right)));
    }
    else{
      printf("0\n");
    }

    return 0;
}
