#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void printByte(FILE *fp, uint8_t Byte) {

   uint8_t Mask = 0x80;   // 1000 0000

   for (int bit = 8; bit > 0; bit--) {

      fprintf(fp, "%c", ( (Byte & Mask) == 0 ? '0' : '1') );
      
      if ( bit == 5 ) fprintf(fp, " ");

      Mask = Mask >> 1;   // move 1 to next bit down
   }
}


void printBits(FILE *fp, const uint8_t* source, 
                                       uint32_t Length) {

   // QTP:  why is pCurrByte initialized this way?

   uint8_t* pCurrByte = source + Length - 1;

   for (uint8_t byte = 0; byte < Length; byte++) {

      uint8_t currByte = *pCurrByte;

      printByte(fp, currByte);     // print bits of
                                   //     current byte

      if ( byte < Length - 1 )     // separate the bytes
         fprintf(fp, " ");

      pCurrByte--;
   }
}

int main(){
    FILE* fp = fopen("output.txt", "w");
    constint my_array[] = {0,1,2,3,4,5,6,7,8,9};
    int length = 10;
    printBits(fp,my_array, length);
    return 0;
}