#include <stdio.h>
#include <stdlib.h>

void findExtrema(const int *pA, int Sz, int *pMin, int *pMax) {
	
   *pMin = *pMax = pA[0];           // prime the min/max values
	
   for (int idx = 1; idx < Sz; idx++) {

      int Current = pA[idx];      // avoid extra array 
                                  //    index operations
      if ( Current < *pMin )
         *pMin = Current;
      else if ( Current > *pMax )
         *pMax = Current;
   }
}

int main(){
    int List[5] = {34, 17, 22, 89, 4};
    int lMin = 0, lMax = 0;

    findExtrema(List, 5, &lMin, &lMax);

    printf("lMin = %d lMax = %d\n", lMin, lMax);

    return 0;
}