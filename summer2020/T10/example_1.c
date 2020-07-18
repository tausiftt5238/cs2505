#include <stdio.h>
#define SZ 5
void fillPrimes( int Primes[] );

int main() {

   int Primes[SZ];
   
   fillPrimes(Primes);
   
   for (int i = 0; i < SZ; i++) {
      printf("%3d:%5d\n", i, Primes[i]);
   }
   
   return 0;
}

void fillPrimes( int Primes[] ) {
	
   for (int i = 0; i < SZ; i++) {
      Primes[i] = i * i + i + 41;
   }
}