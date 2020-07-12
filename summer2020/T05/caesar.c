#include <stdio.h>
#include <stdlib.h>

#define WRONG_NUMBER_OF_PARAMS    1
#define INVALID_SHIFT_SPECIFIED   2
#define FILE_NOT_FOUND            3

char applyShift(char Original, 
                int shiftAmt) {

   char Modified = Original;
   return Modified;
}

int processFile(int shiftAmt, char* fileName) {

   int nChars = 0;
   FILE *In = fopen(fileName, "r");

   char nextIn, nextOut;
   while ( fscanf(In, "%c", &nextIn) == 1 ) {

      if ( isalpha(nextIn) ) {
         ++nChars;
         nextOut = applyShift(nextIn, shiftAmt);
      }
      else
         nextOut = nextIn;
      
      printf("%c", nextOut);
   }

   fclose(In);
   return nChars;
}


int checkParams(int nparams, char** params) {

   if ( nparams != 3 ) {
      printf("Invoke as: caesar <shift distance> <file name>\n");
      return WRONG_NUMBER_OF_PARAMS;
   }

   FILE* fp;
   if ( (fp = fopen(params[2], "r") ) == NULL ) {   //error checking of whether the file can be read (does it exist)
      printf("The file %s could not be found.\n", params[2]);
      return FILE_NOT_FOUND;
   }
   else {
      fclose(fp);
   }
   return 0;
}


int setShiftAmt(char* src) {

   char *p;
   int shiftAmt = strtol(src, &p, 10);
   return shiftAmt;
}

int main(int argc, char** argv) {

   int ckStatus;
   if ( ( ckStatus = checkParams(argc, argv) ) != 0 ) {
      return ckStatus;
   }

   int shiftAmt = setShiftAmt(argv[1]);

   printf("Shifting alphabetic input text by %d positions.\n",
          shiftAmt);

   int charsShifted = processFile(shiftAmt, argv[2]);

   printf("Shifted %d alphabetic characters.\n", charsShifted);

   return 0;
}
