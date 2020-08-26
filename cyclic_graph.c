#include<stdio.h>
#include<stdlib.h>

void cyclic(int n, int adj_matrix[n][n]){
  //se é
  printf("ciclico\n");
  //se não
  printf("aciclico\n");
}
/*
code from: https://www.thedailyprogrammer.com/2015/03/depth-first-search-adjacency-matrix.html
int visited[20];
void DFS(int i)
{
    int j;
    visited[i]=1;
    //printf(" %d->",i+1);
    for(j=0;j<V;j++)
    {
        if(G[i][j]==1&&visited[j]==0)
            DFS(j);
    }
}
int main()
{
    for(i=0;i<n;i++)
      DFS(source-1);
    return 0;
}*/

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
