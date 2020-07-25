#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* strcpy_v1(char* Dest, const char* Source) {

   int i = 0;
   while ( true ) {
      Dest[i] = Source[i];
      if (Dest[i] == '\0') break; // we're done
      i++;
   }
   return Dest;
}

char* strcpy_v2(char* Dest, const char* Source) {

   while ( (*Dest++ = *Source++) != '\0' ) ;
}

int main(){
    char a[100] = "Hello world.";
    char b[100];
    char c[100];
    strcpy_v1(b, a);
    printf("%s\n", b);
    strcpy_v2(c, a);
    printf("%s\n", c);
    return 0;
}