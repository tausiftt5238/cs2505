/*
If you want to compile this code,
``` gcc caeser.c -o run ```
for running the code,
``` ./run 5 input.txt ```
where 5 is the amount you want to shift the characters by,
input.txt is the address, the address rule is same as last code "test.c"

*/

#include <stdio.h>
#include <string.h> //This is a new header for you, string.h has nice tools that help you work with strings, you can copy (strcpy), get length (strlen), concat (strcat) and so on. You can check the documentation for more information. We will have a week where we go through String in general.

#define FILE_NOT_FOUND 1
#define NOT_ENOUGH_ARGS 2
// #define is used for "variables" (they aren't actually variables), that you can use through the code. But what's different here is compared to other variables, you can't change the value. You can't write NOT_ENOUGH_ARGS = 3, it will be a compilation error.


int checkParams(int argc, char** argv){
	if( argc != 3){
		return NOT_ENOUGH_ARGS;
	}
	return 0;
}
// There's 2 implicit parameters that main() has, argc and argv. 
// argc is the number of variables that are available in this specific C code.
// if you run the code as 
// ./run param1 param2 param3 
// then argc's value would be 4
// you can access the values by using argv.
// in the same example, argv will be represented as,
// argv[0] == './run', argv[1] == 'param1', argv[2] == 'param2', argv[3] == 'param3'
int main(int argc, char** argv){
	if ( checkParams(argc, argv) != 0){
		return NOT_ENOUGH_ARGS; //Point to note, if the main() returns anything other than 0, it's an error. SO by returning NOT_ENOUGH_ARGS (which has the value of 2), it says that there was error in the code.
	}
	FILE *f;
	// fopen returns NULL, if the file is not found, that's why we are checking whether the value we got is NULL or not. If it's not NULL, then it means it's pointing to an actual file, in our case, "input.txt". 
	if((f = fopen(argv[2], "r")) == NULL){
		return FILE_NOT_FOUND;
	}	
	char str[100];
	while(fscanf(f, "%s", str) == 1){
		int len = strlen(str); // we used strlen() to find the length of the str we just read using fscanf().
		int i = 0;
		for(i = 0; i < len; i++){
			//we are doing character arithmetic, also another thing to note, atoi() is used to turn a string to Integer. For example, atoi("1234") will return 1234 integer.
			// we are printing the characters individually in this case.
			printf("%c", str[i] + atoi(argv[1]));
		}
	}
	return 0;
}
