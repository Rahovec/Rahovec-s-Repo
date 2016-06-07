// zada4a za 3-ka na david
#include <stdio.h>
#include <string.h>

struct result_t {
   int sum;
   int avr;
};

int main( ) {
  struct result_t Result;
  int i,n,sum;
  scanf("%d", &n);
  sum = 0;

  for(i=0; i <= n; i++){
    sum = sum + i;
  }


  Result.sum = sum;
  Result.avr = sum/n;

  printf("Sum is:%d\n", Result.sum );
  printf("avr is:%d\n", Result.avr );

  return 0;
}
