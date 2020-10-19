#include<stdio.h>
#include<stdlib.h>

#define N 100

static int stack[N];
static int last, first;

int unstack(int n, int d[n]){

  int menor = 10000, i, j, indice = first;

  for(i = first; i < last; i++){
      if(d[stack[i]] < menor){
          menor = d[i];
          indice = i;
      }
  }

  int vertice;
  vertice = stack[indice];

  if(indice != first && indice != last){
    for ( j = indice; j < last; j++) {
      stack[j] = stack[j + 1];
    }
    last--;
  }
  if(indice == first) first++;
  if(indice == last) last--;

  return vertice;
}

void stackup(int value){
  stack[last++] = value;
}

int isvoid(void){
  if(last < first) return 0;
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

void printstack(void){
  int i;
  for(i = first; i < last; i++)
    printf("%d\t", stack[i]);
  printf("\n");
}

void dijkstra(int n, int matrix[n][n]){

  int pai[n], d[n], i, u;
    
  //initialize-single-source  
  for (i = 0; i < n; i++){
    pai[i] = -1;
    d[i] = 10000;
  }
  d[0] = 0;
    
  createstack();
  for ( i = 0; i < n; i++) {
    stackup(i);
  }

  while(isvoid() != 0){
    u = unstack(n, d);
    for ( i = 0; i < n; i++) {
      if (matrix[u][i] != 0) {
    //relax
    if(d[i] > d[u] + matrix[u][i]){
        d[i] = d[u] + matrix[u][i];
        pai[i] = u;
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

  dijkstra(n, adj_matrix);

  return 0;
}
