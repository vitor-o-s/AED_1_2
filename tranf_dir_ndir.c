#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, i, j, v1=0, v2=0;
    scanf(" %d",&n);
    int adj[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf(" %d",&adj[i][j]);
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(adj[i][j]==1 && adj[j][i]==0){
              adj[j][i]=1;
            }
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
