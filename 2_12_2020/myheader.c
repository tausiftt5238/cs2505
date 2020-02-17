#include <stdio.h>
static void private_function(){

	printf("It's just here\n");
}

void print(char *str){
	private_function();
	printf("%s\n", str);
}
