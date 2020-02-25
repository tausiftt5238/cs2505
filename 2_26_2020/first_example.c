#include <stdio.h>
#include <string.h>

int copy(char *a){
    char b[2];
    strcpy(b, a);
    printf("%s\n", b);
    // This is going to be printed, but then it's gonna fail. 
}

int main(){
    char a[10] = "Hello world";
    printf("%s\n", a);
    char b[20] = "Hello world";
    printf("%s\n", b);
    strcpy(a, b);
    printf("%s\n", a); // it may give the right output, but this is wrong. 
    printf("%s\n", b); // they were put in a consequetive memory location, thus b was corrupted thanks to a. 

    char c[20] = "This is a test";
    copy(c); //this is going to be interesting lol.
    return 0;
}