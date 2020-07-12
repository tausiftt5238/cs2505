#include <stdio.h>

int main(){

    int iPart = 1, dPart = 1;
    scanf("%d.%3d", &iPart, &dPart);    //this time we are actually reading 3 digits instead of the whole thing
    printf("%d  %d\n", iPart, dPart);

    return 0;
}