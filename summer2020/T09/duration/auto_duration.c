#include <stdio.h>

int my_function(){
    int x = 0;
    printf("%d\n", x);
}

int main(){
    my_function();

    //x = 10;     //this is going to be error.

    for(int i = 0; i < 10; i++){
        int y = 0;
        printf("%d\n", i);
    }
    // printf("%d\n", i); //this is also an error, because i stops existing after the block.
    //printf("%d\n", y);      // same for y.

    return 0;
}