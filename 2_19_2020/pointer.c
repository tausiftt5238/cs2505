#include <stdio.h>

int main(){
	int first_variable = 10;
	double c = 10.200; 
	int *first_pointer = &first_variable;
	int second_variable = 20;
	printf("%d %p %d\n", first_variable, first_pointer, *first_pointer);
	first_pointer = &second_variable;
	int **first_pointer_of_pointer; 
	first_pointer_of_pointer = &first_pointer;
	printf("%p %d\n", first_pointer_of_pointer, **first_pointer_of_pointer);
	*first_pointer = 1000;
	printf("%d\n", second_variable);	
	return 0;
}
