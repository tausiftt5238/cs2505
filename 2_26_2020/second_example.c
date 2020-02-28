#include <stdio.h>
#include <stdlib.h>

int main(){
    int a[100]; //remember the dimension is FIXED. you can't use variable in this case. But...

    int b = 100;
    int* c = malloc(b * sizeof(int)); // this is acceptable. and in this case, we are using b as the dimension.
    int *c = calloc(b, sizeof(int));
    c[5] = 10;
    *(c + 6) = 20; //both of these way you can access array locations.

    //same goes for static allocation

    a[4] = 30;
    *(a + 5) = 60;

    printf("%d %d\n", c[6] , *(c+5));
    printf("%d %d\n", a[5] , *(a+4));

    free(c); //when you are done, make sure you free the memory.
    // you don't have to free static allocation, they have auto duration, they will be removed when they go out of scope. 


    return 0;
}