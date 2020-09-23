#include<stdio.h>
#include<stdlib.h>

#define BRANCO 2
#define CINZA  1
#define PRETO  0

int DFS(int v, int n, int adj_matrix[n][n], int cor[n], int tempo, int descoberta[n]){
  int j;
  tempo = tempo + 1;
  descoberta[v] = tempo;
  for(j = 0; j < n; j++){
    if(adj_matrix[v][j]==1){
      if(cor[j] == PRETO) continue;
      if(cor[j] == CINZA || (descoberta[v]  - descoberta[j]) > 2) return 1;
      descoberta[j] = tempo;
      cor[j] = CINZA;
      DFS(j, n, adj_matrix, cor, tempo, descoberta);
    }
  }

  cor[v] = PRETO;
  return 0;

}

int tem_ciclo(int n, int adj_matrix[n][n]){
  //1 tem um ciclo
  //0 não possui
  int i, cor[n],  descoberta[n], tempo=0;
  for(i=0;i<n;i++){
    cor[i] = BRANCO;
    descoberta[i] = -1;
  }

  for(i=0;i<n;i++){
    if(cor[i]==PRETO) return 0;
    cor[i] = CINZA;
    if (DFS(i, n, adj_matrix, cor, tempo, descoberta) == 1) return 1;
  }
  return 0;
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
  if(tem_ciclo(n,adj_matrix)==0){
    printf("aciclico\n");
  }
  else{
    printf("ciclico\n");
  }

  return 0;
}
