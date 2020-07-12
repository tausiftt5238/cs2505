#include <stdio.h>

int main(){
    int i = 1, j = 1;
    double x = 1.5;
    scanf("%d, %d, %lf", &i, &j, &x);
    printf("%5d  %5d  %7.4f\n", i, j, x);


    return 0;
}