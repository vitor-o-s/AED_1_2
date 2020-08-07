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
