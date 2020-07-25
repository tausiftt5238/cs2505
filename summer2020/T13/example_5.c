#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINELENGTH 1024  // maximum length guaranteed?

int main(){
    // reading a line of text from a file

    FILE *fp = fopen("input.txt", "r");

    char* line = calloc( MAX_LINELENGTH + 1, sizeof(char) );

    fgets(line, MAX_LINELENGTH + 1, fp);

    // but the line is actually likely to be much shorter than
    // that, so we can offer to "shrink" it

    line = realloc( line, sizeof(char)*(strlen(line) + 1) );

    // copying a string; suppose we have line from last slide

    // first, make an array of exactly the right size:
    char* copy = calloc( strlen(line) + 1, sizeof(char) );

    // then use strncpy() to duplicate the characters:
    strncpy(copy, line, strlen(line));

    printf("%s\n", copy);

    return 0;
}