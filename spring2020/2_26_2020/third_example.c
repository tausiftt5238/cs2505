#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int string_length(char *str){
    int length = 0;
    while (*str++ != 0){ //what about (*str)++ // it gives segmantation fault.
                        // what about *(str++). //it's same as *str++
        length++;
    }
    return length;
}

int main(){
    printf("%d\n", string_length("Hello world"));
    return 0;
}