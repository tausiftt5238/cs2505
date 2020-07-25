#include <stdio.h>
#include <stdlib.h>

int main(){
    int N = 10;
    
    int  *A = malloc( 1000 * sizeof(int) );   // allocate array
    int   B[1000];                            // declare array  

    for (int pos = 0; pos < N; pos++) {
    A[pos] = pos * pos;          // access using ptr name
    B[pos] = pos * pos;          // access using array name
    }

    free( A );    // OK; deallocates array A
    A = NULL;     // OK
    free( B );    // NO!  cannot deallocate static memory 
    B = NULL;     // NO!  array name is const pointer

    return 0;
}