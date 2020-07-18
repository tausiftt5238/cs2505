#include <stdio.h>
#include <inttypes.h>
#include "rFibonacci.h"

int main() {

   for (int i = 0; i < 50; i++) {
		
      printf("Fibo(%d) = %"PRIu64"\n", i, rFibonacci(i));
   }

   return 0;
}
