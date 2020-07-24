#include<stdio.h>
#include<stdlib.h>
//ATENÇÃO esse cogido é uma adaptação
//do código presente no site do Profº Paulo Feofiloff
//Retirado em: https://www.ime.usp.br/~pf/algoritmos/aulas/mrgsrt.html#mergesort
//

////Outra opção para função intercalar

// void intercala (int p, int q, int r, int v[])
// {
//    int *w;
//    w = malloc ((r-p) * sizeof (int));
//    int i = p, j = q;
//    int k = 0;
//
//    while (i < q && j < r) {
//       if (v[i] <= v[j])  w[k++] = v[i++];
//       else  w[k++] = v[j++];
//    }
//    while (i < q)  w[k++] = v[i++];
//    while (j < r)  w[k++] = v[j++];
//    for (i = p; i < r; ++i)  v[i] = w[i-p];
//    free (w);
// }

void intercala (int left, int mean, int right, int v[])
{
   int i, j, *w;
   w = malloc ((right-left) * sizeof (int));

   for (i = left; i < mean; ++i) w[i-left] = v[i];
   for (j = mean; j < right; ++j) w[right-left+mean-j-1] = v[j];
   i = 0; j = right-left-1;
   for (int k = left; k < right; ++k)
      if (w[i] <= w[j]) v[k] = w[i++];
      else v[k] = w[j--];
   free (w);
}

void mergesort (int left, int right, int v[]){

   if(left < right -1){

      int mean = (left + right)/2;
      mergesort (left, mean, v);
      mergesort (mean, right, v);
      intercala (left, mean, right, v);
   }
}

int main(void){

  int vetor[10] = {5,2,4,3,6,7,10,8,1,9};
  mergesort(0,10,vetor);

  int i;
  for(i=0; i<10; i++){
    printf(" %d",vetor[i]);
  }

  return 0;
}
