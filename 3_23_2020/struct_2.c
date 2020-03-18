#include <stdio.h>

// Method 1
struct _Location {
    int x;
    int y;
}; // <- ALWAYS remember to put a semicolon here.

typedef struct _Location Location; // I'm using typedef to rename the struct name to Location instead of _Location.

int main(){
    Location A; // As you can see, over here you don't have to write "struct" before Location anymore.
    A.x = 10;
    A.y = 20;

    printf("%d %d\n", A.x, A.y);
    return 0;
}