#include "rFibonacci.h"

uint64_t rFibonacci(uint64_t n) {
   if ( n < 2 )
      return 1;
   return rFibonacci(n - 1) +  
          rFibonacci(n - 2);
}
