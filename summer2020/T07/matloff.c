#include <stdio.h>
#include <stdbool.h>

/* prime-number finding program

   will (after bugs are fixed) report a list of all primes which are
   less than or equal to the user-supplied upper bound

   riddled with errors! */
   
#define MAXPRIMES 100
bool Prime[MAXPRIMES];  /* Prime[I] will be true if I is prime, false otherwise */

void CheckPrime(int K);

int main() {

   int N;
   int UpperBound;         /* we will check all numbers up through this one for
                              primeness */

   printf("enter upper bound\n");
   scanf("%d", UpperBound);

   Prime[2] = true;

   for (N = 3; N <= UpperBound; N += 2)
      CheckPrime(N);
      if ( Prime[N] ) printf("%d is a prime\n",N);
      
   return 0;
}

void CheckPrime(int K) {
   int J;

   /* the plan:  see if J divides K, for all values J which are
      
         (a) themselves prime (no need to try J if it is nonprime), and
         (b) less than or equal to sqrt(K) (if K has a divisor larger
             than this square root, it must also have a smaller one,
             so no need to check for larger ones) */
   
   J = 2;
   while ( true )  {
      if ( Prime[J] )
         if ( K % J == 0 )  {
            Prime[K] = false;
            return;
         }
      J++;
   }
   
   /* if we get here, then there were no divisors of K, so it is
      prime */
   Prime[K] = true; 
}