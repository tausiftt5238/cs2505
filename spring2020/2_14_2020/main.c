#include <stdio.h>

int glob = 10;

int main(){
	print("I'm going to print this\n");
	printf("%d\n", sum(4,5));
	another_function();
	return 0;
}
// all functions should be declared BEFORE they are used. In this case, another_function() is called in the main(), but it wasn't declared beforehand. It may not lead to an error (due to OS optimization), but it's best to avoid such cases.
// They will show up as a warning during compilation. 
void another_function(){
	printf("%d\n", glob);
}
