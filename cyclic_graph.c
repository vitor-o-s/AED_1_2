#include<stdio.h>
#include<stdlib.h>

#define BRANCO 2
#define CINZA  1
#define PRETO  0
#define marca u.I

/*ENTRADAS TESTES
4
0 1 1 0
1 0 0 0
1 0 0 1
0 0 1 0
aciclico

4
0 1 1 0
1 0 0 0
1 0 0 1
0 0 1 0
ciclico
*/

int DFS(int v, int n, int adj_matrix[n][n], int cor[n]){
  int j;
  for(j = 0; j < n; j++){
    if(adj_matrix[v][j]==1){
      if(cor[j] == PRETO) continue;
      if(cor[j] == CINZA) return 1;
      cor[j] = CINZA;
      if(DFS(j, n, adj_matrix, cor) == 1) return 1;
    }
  }

  cor[v] = PRETO;
  return 0;

}

int tem_ciclo(int n, int adj_matrix[n][n]){
  //1 tem um ciclo
  //0 não possui
  int i, cor[n];
  for(i=0;i<n;i++)
    cor[i] = BRANCO;
  for(i=0;i<n;i++){
    if(cor[i]==PRETO) continue;
    cor[i] = CINZA;
    if (DFS(i, n, adj_matrix, cor) == 1) return 1;
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

/*
i


*/
