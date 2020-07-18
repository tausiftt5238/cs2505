#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_LINELENGTH 10000     // absurdly large guess

int main(int argc, char* argv[]){   // don't worry about argc not being used, we are just not using it in this example.
    char data[MAX_LINELENGTH + 1];
    FILE* in = fopen(argv[1], "r");

    while ( fgets(data, MAX_LINELENGTH + 1, in) != NULL) {

        char* token = strtok(data, "\t");
        uint32_t tokenLength = strlen(token);
        char* artist = calloc(tokenLength + 1, sizeof(char));
        strncpy(artist, token, tokenLength);

        token = strtok(NULL, "\t");
        tokenLength = strlen(token);
        char* title = calloc(tokenLength + 1, sizeof(char));
        strncpy(title, token, tokenLength);

        char* lengthField = token + strlen(token) + 1;
        int minutes, seconds;
        sscanf(lengthField, "%d%*c%d", &minutes, &seconds);
        
        printf("Artist: %s\n", artist);
        printf("Title:  %s\n", title);
        printf("Length: %dm %ds\n", minutes, seconds);
        printf("\n");
    }

    fclose(in);

}