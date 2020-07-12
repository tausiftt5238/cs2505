#include <stdio.h>

int GCD(int N, int M) { //function declaration

   printf("N = %5d and M = %5d\n", N, M);   
   if ( M == 0 ) return N;
   return GCD(M, N % M);    //recursion, if you understand the concept, good, if not, ask me lol
}

int main(int argc, char** argv) {   // new stuff! these parameters work with arguments that were provided to the program. 
                                    // argc holds how many arguments were passed, argv holds the value of them.
                                    // what does ** before argv mean? wait till you reach pointers!
   
   if ( argc != 3 ) {               //checking whether enough arguments were sent
      printf("gcd X Y\n");
      return 1;
   }
   
   int X = atoi(argv[1]);           // atoi() converts string to integer, will be useful for all the assignments!
   int Y = atoi(argv[2]);
   
   printf("GCD is %d\n", GCD(X, Y));
   return 0;
}
