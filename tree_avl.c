#include <stdio.h>
#include <stdlib.h>

typedef struct Leaf{
  int value, fator_balanceamento;
  struct Leaf * left;
  struct Leaf *right;
}leaf;

typedef struct Tree{
  leaf *root;
  //int balanceamento;
}tree;

void init(tree* t){
  t->root = NULL;
  //t->balanceamento = 0;
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

    return 0;
}

/*

void balanceamentoFolha(Arvore *t,Folha *f)
{
    int esquerda=altura(f->sae);
    int direita=altura(f->sad);
    f->balanceamento=direita-esquerda;
    if(f->balanceamento>1 || f->balanceamento<-1)
        t->AVL=0;
}

void balanceamentoArvore(Arvore *t,Folha *root)
{
    if(root==NULL);
    else
    {
        balanceamentoFolha(t,root);
        if(root->sae==NULL);
        else
        {
            balanceamentoFolha(t,root->sae);
            balanceamentoArvore(t,root->sae);
        }
        if(root->sad==NULL);
        else
        {
            balanceamentoFolha(t,root->sad);
            balanceamentoArvore(t,root->sad);
        }
    }
}



int main()
{
    int insercoes,i,insert;
    Arvore *t=novaArvore();
    scanf("%d",&insercoes);
    for(i=0;i<insercoes;i++)
    {
        scanf("%d",&insert);
        insertBinario(t,t->root,insert);
    }
    balanceamentoArvore(t,t->root);
    printf("%d\n",t->AVL);
    return 0;
}
*/
