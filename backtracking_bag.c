#include<stdio.h>
#include<stdlib.h>

int maior(int a, int b){
  if (a > b) return a;
  return b;
}

int valormaximo(int peso[], int valor[], int capacidade, int N){

  if(N < 0) return 0;
  if(peso[N]>capacidade) return valormaximo(peso,valor, capacidade, N-1);
  else return maior(valormaximo(peso,valor, capacidade, N-1), valor[N] + valormaximo(peso, valor, capacidade - peso[N], N-1));

}

int main(void){

  int capacidade, N, i;
  scanf(" %d",&capacidade);
  scanf(" %d",&N);
  int peso[N], valor[N];
  for(i = 0; i < N; i++){
    scanf(" %d %d",&peso[i], &valor[i]);
  }

  printf("%d\n",valormaximo(peso,valor,capacidade, N-1));
  return 0;
}
