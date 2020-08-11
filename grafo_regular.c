#include <stdio.h>
#include <stdlib.h>

void regular(int vet[], int n){
    int i;
    for(i=1;i<n;i++){
        if(vet[i]!=vet[i-1]){
            printf("nao\n");
            return;
        }
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
