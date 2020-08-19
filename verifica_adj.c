#include <stdio.h>
#include <stdlib.h>

int verifica(int n, int matriz[n][n],int v1, int v2){
  if(matriz[v1][v2]==0)  return 0;
  return 1;

}
int main() {

    int n, i, j, v1=0, v2=0;
    scanf(" %d",&n);
    int adj[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf(" %d",&adj[i][j]);
        }
    }

    while (scanf(" %d %d",&v1,&v2)==2){
        if(verifica(n,adj,v1,v2)==1 || verifica(n,adj,v2,v1)==1){
            printf("sim\n");
        }
        else{
            printf("nao\n");
        }

    }

    return 0;
}
