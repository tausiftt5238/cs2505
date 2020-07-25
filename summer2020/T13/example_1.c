#include <stdio.h>
#include <stdlib.h>

int main(){
    int N = 10; //as you can see, it's not static number, but a dynamic. You can change it in runtime, unlike static array allocation

    int *pA = malloc(N * sizeof(int)); // N = dimension, sizeof(int) = how much data EACH ELEMENT require

    if(pA == NULL){     // should always do error checking. malloc returns 0/NULL if it fails to allocate memory.
        fprintf(stderr, "Allocation failed.\n");
        exit(1);
    }

    for(int i = 0; i < N ; i++){
        pA[i] = i * i; // yes you can use array notation.
        // or 
        *(pA + i) = i * i; // This is the pointer notation.
        printf("[] = %d, * = %d\n", pA[i], *(pA + i));      // using both notation to print the values.
    }

    free(pA); //always make sure you free your dynamically allocated array. Otherwise there will be memory leak.

    return 0;
}