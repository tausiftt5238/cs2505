#include <stdio.h>  //header file to make printf() work
#include <stdlib.h> //header file to make abs() work

int main(){         //compulsory function to run a C code
    int a = 42, b = -17;    //declaration similar to Java
    
    printf("%d * %d = %d\n", a, b, a*b);    // first parameter is the format specifier, latter parameters are whatever is to be printed in the format specifier.

    printf("The absolute value of %d is %d.\n", b, abs(b) );

    printf("%d\n+ %d\n= %d\n", a, b, a + b); 

    printf("%7d\n+ %5d\n= %5d\n", a, b, a + b); // we are setting the alignment by using the number before 'd', it basically means right align in by the number that's specified. 
    
    return 0;       // must return 0 to show the compiler the code ran perfectly
}