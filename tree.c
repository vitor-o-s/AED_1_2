#include<stdio.h>
#include<stdlib.h>

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

// A utility function to create a new BST leaf
leaf* create_leaf(int value){
  leaf *new = (leaf *) malloc (sizeof(leaf));
  if(new == NULL) return NULL;
  new->value = value;
  new->left = new->right = NULL;
  return new;
}

// A utility function to do inorder traversal of BST
void inorder(leaf *root){

    if (root != NULL){
      inorder(root->left);
      printf(" %d \t", root->value);
      inorder(root->right);
    }
}

leaf* search(leaf* root, int value){
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->value == value)
       return root;

    // Key is greater than root's key
    if (root->value < value)
       return search(root->right, value);

    // Key is smaller than root's key
    return search(root->left, value);
}

// A utility function to insert a new node with given key in BST
leaf* insert(leaf *root, int value){

  // If the tree is empty, return a new node
  if (root == NULL) return create_leaf(value);

  // Otherwise, recur down the tree
  if (value < root->value)
      root->left  = insert(root->left, value);
  else if (value > root->value)
      root->right = insert(root->right, value);

  // return the (unchanged) node pointer
  return root;

}

// Driver Program to test above functions
int main(void){

  // Let us create following BST
  //            50
  //         /      |
  //        30      70
  //       /  \    / |
  //     20   40  60 80

    tree *t = (tree*) malloc (sizeof(tree));

    init(t);

    t->root = insert(t->root, 50);
    insert(t->root, 30);
    insert(t->root, 20);
    insert(t->root, 40);
    insert(t->root, 70);
    insert(t->root, 60);
    insert(t->root, 80);

    // print inoder traversal of the BST
    inorder(t->root);

    return 0;
}
