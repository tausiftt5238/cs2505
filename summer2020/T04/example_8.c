#include <stdio.h>

int main(){

    int iPart = 1, dPart = 1;
    scanf("%d.%d", &iPart, &dPart);     //we are going to separate the decimal number
    printf("%d\n%d\n", iPart, dPart);

    return 0;
}