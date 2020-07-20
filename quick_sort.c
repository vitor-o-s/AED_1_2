#include<stdio.h>
#include<stdlib.h>

int separa(int v[], int left, int right){
  int pivo = v[right]; //pivo
  int aux, j = left, i;

  for(i = left; i < right; i++){
    if(v[i] <= pivo){
      aux = v[j];
      v[j] = v[i];
      v[i] = aux;
      j++;
    }
  }

  aux = v[j];
  v[j] = v[right];
  v[right] = aux;
  return j;

}

void Quicksort (int v[], int left, int right){

   if (left < right){
      int j = separa (v, left, right);
      Quicksort (v, left, j-1);
      Quicksort (v, j+1, right);
   }

}

int main(void) {

  int vetor[10] = {10,7,3,4,6,1,9,5,8,2};

  Quicksort(vetor,0,9);

  int i;
  for(i=0; i<10; i++){
    printf(" %d",vetor[i]);
  }

  return 0;
}
