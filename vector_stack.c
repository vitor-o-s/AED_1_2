#include<stdio.h>
#include<stdlib.h>

#define N 100

static int stack[N];
static int last, first;

int unstack(void){
  return stack[last--];
}

void stackup(int value){
  stack[last++] = value;
}

int isvoid(void){
  if(last = first) return 0;
  return 1;
  //return p >= u;
}

void createstack(void){
   first = last = 0;
}

int isfull(void){
  if(last >= N) return 1;
  return 0;
  //return u > N;
}

void printstack(void){
  int i;
  for(i = first; i < last; i++)
    printf("%d\t", stack[i]);
  printf("\n");
}

int main(void){

  createstack();
  stackup(3);
  stackup(2);
  printstack();
  unstack();
  printstack();
  stackup(6);
  printstack();
  unstack();
  printstack();

  return 0;
}
