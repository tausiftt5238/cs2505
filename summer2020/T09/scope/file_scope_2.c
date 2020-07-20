#include <stdio.h>

static void my_func_2(){
    printf("this won't be printed\n");
}

void my_func(){
    my_func_2();
    printf("this will be printed\n");
    printf("%d\n", x);
}