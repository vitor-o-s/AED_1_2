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
  new->color = RED;
  new->left = new->right = new->parent = NULL;
  return new;
}

void inorder(leaf *root){

    if (root != NULL){
      inorder(root->left);
      printf("%d %d\t", root->value,root->color);
      inorder(root->right);
    }
}

leaf* uncle(leaf* root){
  leaf* aux = NULL;

  if((root != NULL) && (root->parent != NULL)){
    if (root->parent->parent->left == root->parent){
      aux = root->parent->parent->right;
    }
    else{
      aux = root->parent->parent->left;
    }
  }
  return aux;
}

leaf* grandp(leaf *root){

  if((root != NULL) && (root->parent!= NULL)) return  root->parent->parent;

  return NULL;
}

leaf* rot_right(leaf *root){
  leaf *p = root->parent, *g = p->parent;

  p->parent = g->parent;
  g->parent = p;
  g->left   = p->right;
  p->right  = g;

  root = p;
  return root;
}

leaf* rot_left(leaf *root){
  leaf *p = root->parent, *g = p->parent;

  p->parent = g->parent;
  g->parent = p;
  g->right  = p->left;
  p->left   = g;

  root = p;
  return root;
}

leaf* rot_right_left(leaf *root){
  leaf *p = root->parent, *g = p->parent;

  root->parent = p->parent;
  p->parent    = root;
  p->left      = root->right;
  root->right  = p;

  return rot_left(p);
}

leaf* rot_left_right(leaf *root){
  leaf *p = root->parent, *g = p->parent;

  root->parent = p->parent;
  p->parent    = root;
  p->right     = root->left;
  root->left   = p;

  return rot_right(p);
}

void balance(leaf* root){

  leaf *p, *u; //parente, uncle

  if(root->parent == NULL){ //case 1
    //printf("entrou caso 1\n");
    root->color = BLACK;
  }
  else{
    p = root->parent;

    if(p->color == RED){

      u = uncle(root);

      if((u != NULL) && (u->color == RED)){//case 2
        //printf("entrou caso 2\n");
        p->color = u->color = BLACK;
        //printf("valor pai: %d cor: %d valor do tio:%d cor:%d\n", p->value, p->color,u->value,u->color);
        root = grandp(root);

        if(root->parent != NULL)
        root->color = RED;
      }

      else{//case 3
        if(p->left == root){
          if(p->parent->right == p){
            //printf("entrou caso 3c\n");
            rot_right_left(root);//case 3c
            //inorder(root);
          }
          else{
            //printf("entrou caso 3a\n");
            rot_right(root); //case 3
          }
        }
        else{
          if(p->parent->right == p){
            //printf("entrou caso 3d\n");
            rot_left_right(root);//case 3d
          }
          else{
            //printf("entrou caso 3b\n");
            rot_left(root); //case 3b
          }
        }
        //printf("fazendo pintura dos nós\n");
      //  printf("%d %d\n",root->value,root->parent->value);
        root->color = BLACK;
        if(root->left  != NULL) root->left->color  = RED;
        if(root->right != NULL)root->right->color = RED;
        //printf("saiu balance\n");

      }
    }
  }

}

leaf* insert(leaf* root, int value){

  leaf *auxP, *auxF;

  if (root == NULL){
      return create_leaf(value);
  }

  else{
    auxP = auxF = root;

    while (auxF != NULL){
      auxP = auxF;

      if (value < auxF->value)
      auxF = auxF->left;
      else
      auxF = auxF->right;
    }

    auxF = create_leaf(value);
    auxF->parent = auxP;

    if (auxF->value < auxP->value)
    auxP->left = auxF;
    else
    auxP->right = auxF;

    while ((auxF->parent != NULL)  && (auxF->color == RED) && (auxF->parent->color == RED)){
      //printf("entrou balance\n");
      balance(auxF);
    }

  }
  return root;
}

int bh(leaf* root){
  if(root== NULL) return 0;
  if(root->color == BLACK) return 1 + bh(root->left);
  return bh(root->left);
}



int main(void){

  int n;
  scanf(" %d",&n);

  tree *t = (tree*) malloc (sizeof(tree));
  init(t);
  int i, key;
  scanf(" %d",&key);
  t->root = insert(t->root, key);
  t->root->color = BLACK;


  for(i=1; i<n; i++){
      scanf(" %d",&key);
      insert(t->root, key);
  }

  //inorder(t->root);
  printf("%d\n",bh(t->root));

  return 0;
}
