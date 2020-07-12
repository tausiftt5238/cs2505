#include <stdio.h>

int main(){

    double r  = 2.0;
    double pi = 3.141592;

    printf("The area of a circle of radius %.2f is about %.4f\n", r, pi * r * r);   // %.2f means 2 decimal points, also remember, it doesn't round off, it cuts off. %.4f means 4 decimal points.

    return 0;
}