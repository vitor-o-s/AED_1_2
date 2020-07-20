#include<stdio.h>
#include<stdlib.h>
//ATENÇÃO A IMPLEMENTAÇÃO DESSE CÓDIGO É REPRODUÇÃO
//DO CÓDIGO FEITO PELO PROFº PAULO Feofiloff
//Retirado em: https://www.ime.usp.br/~pf/algoritmos/aulas/mrgsrt.html#mergesort
static void
intercala1 (int p, int q, int r, int v[])
{
   int *w;                                 //  1
   w = malloc ((r-p) * sizeof (int));      //  2
   int i = p, j = q;                       //  3
   int k = 0;                              //  4

   while (i < q && j < r) {                //  5
      if (v[i] <= v[j])  w[k++] = v[i++];  //  6
      else  w[k++] = v[j++];               //  7
   }                                       //  8
   while (i < q)  w[k++] = v[i++];         //  9
   while (j < r)  w[k++] = v[j++];         // 10
   for (i = p; i < r; ++i)  v[i] = w[i-p]; // 11
   free (w);                               // 12
}

static void
intercala2 (int p, int q, int r, int v[])
{
   int i, j, *w;
   w = malloc ((r-p) * sizeof (int));

   for (i = p; i < q; ++i) w[i-p] = v[i];
   for (j = q; j < r; ++j) w[r-p+q-j-1] = v[j];
   i = 0; j = r-p-1;
   for (int k = p; k < r; ++k)
      if (w[i] <= w[j]) v[k] = w[i++];
      else v[k] = w[j--];
   free (w);
}

void
mergesort (int p, int r, int v[])
{
   if (p < r-1) {                 // 1
      int q = (p + r)/2;          // 2
      mergesort (p, q, v);        // 3
      mergesort (q, r, v);        // 4
      intercala (p, q, r, v);     // 5
   }
}
