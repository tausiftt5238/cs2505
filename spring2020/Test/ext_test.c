#include <stdio.h>

int main(){
    extern int a;
    printf("%d\n", a);
    return 0;
}