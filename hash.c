#include<stdio.h>
#include<stdlib.h>

#define M 97 //Qualquer primo menor que R
#define R 1000

typedef struct NODE{
  int key, f; //f is for frequency
  struct NODE *next;
}node;

node **tb;
tb =(node **) malloc (M * sizeof (node*));

int hash(int key){
  return key % M;
}

void contabiliza (int key) {
   int h = hash(key);
   node *p = tb[h];
   while (p != NULL && p->key != key)
      p = p->next;
   if (p != NULL)
      p->f += 1;
   else {
      p = malloc (sizeof (node));
      p->key = key;
      p->f = 1;
      p->next = tb[h];
      tb[h] = p;
   }
}

int main(void) {


  contabiliza(212);
  contabiliza(618);
  contabiliza(302);
  contabiliza(940);
  contabiliza(702);
  contabiliza(704);
  contabiliza(612);
  contabiliza(606);
  contabiliza(772);
  contabiliza(510);
  contabiliza(423);
  contabiliza(650);
  contabiliza(317);
  contabiliza(907);
  contabiliza(507);
  contabiliza(304);
  contabiliza(714);
  contabiliza(857);
  contabiliza(801);
  contabiliza(900);
  contabiliza(413);
  contabiliza(701);
  contabiliza(418);
  contabiliza(601);

  return 0;
}
