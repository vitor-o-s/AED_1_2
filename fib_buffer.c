#include<stdio.h>
int cache[];

int fib(int n){

  if(n==0) return 0;
  if(n==1) return 1;

  if (cache[n] == 0) {
      // only recalc if we don't have a value
      cache[n] = fib(n-1) + fib(n-2);
  }
  return cache[n];

}

int main(void){
  int n;
  scanf(" %d",&n);
  printf("%d",fib(n));
  return 0;
}
