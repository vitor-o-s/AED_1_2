#include<stdio.h>
#include<stdlib.h>
//
// RED   1
// BLACK 0
//

typedef struct Leaf{
  int value;
  struct Leaf *left;
  struct Leaf *right;
  struct Leaf *parent;
  int color;
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
  new->color = 1;
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

  return 0;
}
