// hexer.c
#include <stdio.h>

int main(int argc, char* argv[]) {

   int argno = 1;   // start with argument 1
   
   while ( argv[argno] != NULL ) {
		
      char* currArg = argv[argno];  // slap handle on current one
   
      // echo current argument
      printf("%10s:  ", argv[argno]);

      // print ASCII codes of characters, in hex format:
      int pos = 0;
      while ( currArg[pos] != '\0' ) {
         printf(" %X", (unsigned char) currArg[pos]);
         pos++;
      }
      printf("\n");

      argno++;   // step to next argument (if any)
   }
   return 0;
}
