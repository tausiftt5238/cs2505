#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>       //if you wish to use new convention of Integers, make sure this is in ur source code, or you can also use #include <stdint.h>

int main() {

   int32_t N = INT32_MAX;
   uint8_t nDivisions = 0;
   
   while ( (N = N / 2) > 0 ) {
       
       ++nDivisions;

       printf("%2"PRIu8"%12"PRId32"\n", nDivisions, N); // instead of %d we are using %2"PRIu8", u can think of the double quote as d in the %d
   }
   
   return 0;
}