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
    //return;
    }
  else{
    printf("sim\n");
      }

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
    //for(i=0;i<n;i++)
    //  printf("%d ",v[i]);


    regular(v,n);

    return 0;
}
