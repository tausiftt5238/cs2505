#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t strlen_v1(const char* Source) {
	
   uint64_t Length = 0;
	
   while ( *Source != '\0' ) {
      Length++;
      Source++;
   }
   return Length;
}

uint64_t strlen_v2(const char* Source) {
	
   uint64_t Length = 0;
	
   while ( *Source++ != '\0' )
      Length++;
   return Length;
}

int main(){
    char my_string[] = "Hello world.";
    printf("v1 = %d, v2 = %d\n", strlen_v1(my_string), strlen_v2(my_string));
    return 0;
}
