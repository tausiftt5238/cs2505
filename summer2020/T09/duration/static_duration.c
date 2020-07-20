#include <stdio.h>

void my_func(){
    static int x = 0;
    printf("%d\n", x);
    x++;
}

int main(){
    my_func();
    my_func();
    my_func();
    return 0;
}