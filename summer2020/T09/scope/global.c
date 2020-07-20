#include <stdio.h>

int x = 0;

int my_func(){
    printf("%d\n", x);
    x = 20;
}

int main(){
    printf("%d\n", x);
    x = 10;
    printf("%d\n", x);
    my_func();
    printf("%d\n", x);
    return 0;
}