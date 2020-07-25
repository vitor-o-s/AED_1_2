#include<stdio.h>
#include<stdlib.h>

#define N 100

static int queue[N];
static int first, last;

int dequeue (void){
  return queue[first++];
}

void enqueue (int value){
  queue[last++] = value;
}

int isvoid(void){
  if(last = first) return 0;
  return 1;
  //return p >= u;
}

void createqueue(void){
   first = last = 0;
}

int isfull(void){
  if(last >= N) return 1;
  return 0;
  //return u > N;
}

void printqueue(void){
  int i;
  for(i = first; i < last; i++)
    printf("%d\t", queue[i]);
  printf("\n");
}

int main(void){

  createqueue();

  enqueue(3);
  enqueue(2);
  printqueue();
  dequeue();
  printqueue();
  enqueue(6);
  dequeue();
  printqueue();
  return 0;
}
