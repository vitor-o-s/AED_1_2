#include<stdio.h>
#include<stdlib.h>

#define N ? /* ordem da árvore B */

typedef struct Leaf{
  int n;
  char chaves[N-1];
  struct Leaf *filhos[N];
  bool folha;
}leaf;
