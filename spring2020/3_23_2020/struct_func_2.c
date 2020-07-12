#include <stdio.h>
#include "struct_func.h"

Location updateLocation(Location Old, Location Move){
    Location Updated;   //we can statically declare a struct and send them as a return. You don't have to do dynamic allocation all the time. 
    Updated.x = Old.x + Move.x;
    Updated.y = Old.y + Move.y;
    return Updated;
}

typedef struct _Quadrilateral{
    Location Corners[10];
}Quadrilateral; // yes you can use array as elements of struct, but you have to initialize them manually one by one. 


int main(){

    Location A;
    initLocation(&A, 2, 3);
    printf("%d %d\n", A.x, A.y);

    Location B;
    initLocation(&B, 4, 5);
    printf("%d %d\n", B.x, B.y);

    Location C = updateLocation(A, B);
    printf("%d %d\n", C.x, C.y);

    return 0;
}