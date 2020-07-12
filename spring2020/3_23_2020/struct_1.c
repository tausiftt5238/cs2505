#include <stdio.h>

// Method 1
struct Location {
    int x;
    int y;
}; // <- ALWAYS remember to put a semicolon here.

int main(){
    struct Location A; // also notice, when declaring, i'm writing 'struct Location', instead of just Location. if you do normal struct declaration, this is how you will be declaring variables.
    A.x = 10;
    A.y = 20;

    printf("%d %d\n", A.x, A.y);
    return 0;
}