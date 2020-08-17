#include <stdio.h>
#include <stdlib.h>

int max(int vet[], int n){
  int i, max = 0;
  for (i = 0; i <n; i++){
    if(vet[i]>max) max = vet[i];
  }
  return max;
}

int min(int vet[], int n){
  int i, min = 1000;
  for (i = 0; i <n; i++){
    if(vet[i]<min) min = vet[i];
  }
  return min;
}

void regular(int vet[], int n){

        if(max(vet,n)!=min(vet,n)){
            printf("nao\n");
            return;
        }

    printf("sim\n");
    return;
}

int main() {

    int n, i, j;
    scanf(" %d",&n);
    int adj[n][n], v[n];
    for(i=0;i<n;i++){
        v[i] = 0;
        for(j=0;j<n;j++){
            scanf(" %d",&adj[i][j]);
            if(adj[i][j]==1){
                v[i] = v[i] + 1;
            }
        }
    }


    regular(v,n);

    return 0;
}
/*
int tamanho,i,j,todos0,todos1;
    todos0=1;
    todos1=1;

    for(i=0;i<tamanho;i++)
    {
        for(j=0;j<tamanho;j++)
        {
            if(matriz[i][j]!=0 && i!=j)
            {
                todos0=0;
            }
            if(matriz[i][j]!=1 && i!=j)
            {
                todos1=0;
            }
        }
    }
    if(todos0==1 || todos1==1)
        printf("sim\n");
    else
        printf("nao\n");
    return 0;

*/
