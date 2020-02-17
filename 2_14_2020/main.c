#include <stdio.h>

int glob = 10;

int main(){
	print("I'm going to print this\n");
	printf("%d\n", sum(4,5));
	another_function();
	return 0;
}

void another_function(){
	printf("%d\n", glob);
}
