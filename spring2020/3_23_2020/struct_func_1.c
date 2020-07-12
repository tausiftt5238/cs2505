#include <stdio.h>

typedef struct _Location{
    int x;
    int y;
} Location;

void initLocation(Location* L, int x, int y){
    (*L).x = x;
    // *L.x = x;
    L->y = y;
}

Location updateLocation(Location Old, Location Move){
    Location Updated;   //we can statically declare a struct and send them as a return. You don't have to do dynamic allocation all the time. 
    Updated.x = Old.x + Move.x;
    Updated.y = Old.y + Move.y;
    return Updated;
}

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