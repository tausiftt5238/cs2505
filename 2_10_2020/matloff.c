#include <stdio.h>
#include <stdbool.h>
/* Erroneous prime-number finding program. 
* Based on an example from Norman Matloff's website * 
* Will (after bugs are fixed) report a list of all primes 
* which are less than or equal to the user-supplied upper 
* bound. * 
* Riddled with errors! */
#define MAXPRIMES 100   // Badly named limit; actually the 
                        // upper limit on the user's input 
                        // for upperBound
void checkPrime(int K, bool Prime[]);

int main()
{
    int N;
    int upperBound;                 // We will check all numbers up 
                                    // through this one for primeness
    bool Prime[MAXPRIMES] = {0};    // Prime[I] will be true if I is 
                                    // prime, false otherwise
    printf("Enter upper bound less than %d\n", MAXPRIMES);
    scanf("%d", &upperBound);
    Prime[2] = true;                // Hardwire to "prime the pump" 
    printf("2 is a prime\n");
    for (N = 3; N <= upperBound; N += 2){
        checkPrime(N, Prime);
    if (Prime[N])
        printf("%d is a prime\n", N);
	}
    return 0;
}

void checkPrime(int K, bool Prime[])
{
    int J;
    // The plan:  see if J divides K, for all values J which are //      
    //    (a) themselves prime (no need to try J if it is nonprime), 
    // and 
    //    (b) less than or equal to sqrt(K) (if K has a divisor 
    //        larger than this square root, it must also have a //     
    //   smaller one, so no need to check for larger ones)
    J = 2;
    for(; J*J <= K ; J++)
    {
        if (Prime[J])
            if (K % J == 0)
            {
                Prime[K] = false; // Redundant, given initialization // of Prime[] in main()
                return;
            }

    }
    // If we get here, then there were no divisors of K, so K must //   be prime
    Prime[K] = true;
}
