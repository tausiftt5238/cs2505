#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main(){
    char name[] = "TAUSIF";
    printf("%d\n", *(uint8_t*)name);
    printf("%d\n", *(uint16_t*) name);      // (41 == A),  (54 == T) 
    printf("%d\n", *(uint32_t*) name);      // (53 == S),  (55 == U), (41 == A),  (54 == T) 
    printf("%ld\n", *(uint64_t*) name);      // (46 == F),  (49 == I), (53 == S),  (55 == U), (41 == A),  (54 == T) 
    return 0;
}
