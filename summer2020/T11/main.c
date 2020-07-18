#include <stdio.h>
#include "test.h"
// This code is for you to test the functions.
// for compilation:
// gcc -o my_exec -W -Wall -std=c11 main.c example_1.c example_2.c 
int main(){
    char my_string[] = "Hello world.";

    char *dupe_string = dupeString_wo_memcpy(my_string);

    printf("duplicate without memcpy: %s\n", dupe_string);

    char *dupe_string_1 = dupeString_w_memcpy(my_string);

    printf("duplicate with memcpy: %s\n", dupe_string_1);

    printf("trunc with o in string: %d\n", truncString(my_string, 'o'));

    return 0;
}