#include <stdio.h>

// Method 1
typedef struct _Location {
    int x;
    int y;
} Location; // <- ALWAYS remember to put a semicolon here.

// Over here, i combined the struct declaration and typedef statement. This is probably the way of declaration you will be using the most, but practice caution when you do so. In fact, in this declaration, you can also omit _Location right after struct, and it will still work. But that's a bad practice so do not do that. 

int main(){
    Location A; // As you can see, over here you don't have to write "struct" before Location anymore.
    A.x = 10;
    A.y = 20;

    printf("%d %d\n", A.x, A.y);
    return 0;
}