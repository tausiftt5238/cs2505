#include <stdio.h>
#include "my_library.h"
void print(char a[]);

int main(){

	print("I am going to print this\n");	
	return 0;
}

void print(char str[]){
	printf("%s\n", str);
}
