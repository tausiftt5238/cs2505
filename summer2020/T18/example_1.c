#include <stdio.h>

struct Location {        // declare type globally
   int X, Y;
};

int main() {

    struct Location A;   // declare variable of type Location
    A.X = 5;             // set its data members
    A.Y = 6;

    printf("%d %d\n", A.X, A.Y);

    struct Location B;   // declare another Location variable
    B = A;               // copy members of A into B
    return 0;

}
