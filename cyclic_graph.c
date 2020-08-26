#include<stdio.h>
#include<stdlib.h>

void cyclic(int n, int adj_matrix[n][n]){
  //se é
  printf("ciclico\n");
  //se não
  printf("aciclico\n");
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
  cyclic(n,adj_matrix);

  return 0;
}
