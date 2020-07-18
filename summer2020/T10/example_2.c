#include <stdio.h>
#include <time.h>                        // for time()
#include <stdlib.h>                      // for srand(), rand()
#include <inttypes.h>
#define SZ 10                            // constant for array dimension

void fillArray(uint32_t List[], uint32_t Sz);   // fn declarations
void Sort(uint32_t List[] , uint32_t Usage);

int main() {

   int A[SZ];                            // allocate space for array
   
   fillArray(A, SZ);                     // fill array with random values
   
   for (uint32_t i = 0; i < SZ; i++) {   // print original array
      printf("%3d:%5d\n", i, A[i]);
   }
   
   Sort(A, SZ);                          // sort the array
   
   for (uint32_t i = 0; i < SZ; i++) {   // print the sorted array
      printf("%3d:%5d\n", i, A[i]);
   }
   return 0;
}                                        

// Writes Size random integer values in [0, 1000) into List[]
// 
// Pre:
//       List[] has dimension >= Size
// Post:
//       List[0:Size-1] have been set to random values in
//       the range 0 to 999, inclusive.
//
void fillArray(uint32_t List[], uint32_t Size) {
		
   srand( (uint32_t) time(NULL) );          // initialize random
                                            //    generator
	
   for (uint32_t pos = 0; pos < Size; pos++) {

      List[pos] = rand() % 1000;
   }
}


// Uses InsertionSort algorithm to put elements of List[] into
// ascending order.
//
void Sort(uint32_t List[], uint32_t Usage) { 

   uint32_t unsortedFront = 1;
   
   while ( unsortedFront < Usage ) {
   
      uint32_t currElement = List[unsortedFront];
      uint32_t probeLocation = unsortedFront;
      
      while ( probeLocation > 0  && 
              List[probeLocation-1] > currElement) {

         List[probeLocation] = List[probeLocation-1];
         probeLocation--;
      }
      
      List[probeLocation] = currElement;
      unsortedFront++;
   }
}
