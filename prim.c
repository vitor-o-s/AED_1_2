#include<stdio.h>
#include<stdlib.h>

#define N 100

static int stack[N];
static int last, first;

int unstack(int n, int chave[n]){

  int menor = 10000, i, j;

  i = first;
  while(i < last && chave[i] > menor){
    i++;
  }

  int vertice;
  vertice = stack[i];

  if(i != first && i != last){
    for ( j = i; j < last; j++) {
      stack[j] = stack[j + 1];
    }
    last--;
  }
  if(i == first) first++;
  if(i == last) last--;

  return vertice;
}

void stackup(int value){
  stack[last++] = value;
}

int isvoid(void){
  if(last == first) return 0;
  return 1;
  //return p >= u;
}

void createstack(void){
  first = last = 0;
}

int Estack(int n){

  int i;

  for ( i = first; i < last; i++) {
    if(stack[i] == n) return 1;
  }
  return 0;
}

void prim(int n, int matrix[n][n]){

  int pai[n], chave[n], i, u;

  for (i = 0; i < n; i++){
    pai[i] = -1;
    chave[i] = 10000;
  }
  chave[0] = 0;
  createstack();
  for ( i = 0; i < n; i++) {
    stackup(i);
  }

  while(isvoid() != 0){
    u = unstack(n, chave);
    for ( i = 0; i < n; i++) {
      if (matrix[u][i] != 0) {
        if(Estack(i) == 1 && matrix[u][i] < chave[i]){
          pai[i] = u;
          chave[i] = matrix[u][i];
        }
      }
    }
  }

  printf("0: -\n");
  for (i = 1; i < n; i++) {
    printf("%d: %d\n",i,pai[i]);
  }
}

int main(void) {

  int i, j, n;
  scanf(" %d",&n);
  int adj_matrix[n][n];
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      scanf(" %d",&adj_matrix[i][j]);
    }
  }

  prim(n, adj_matrix);

  return 0;
}
