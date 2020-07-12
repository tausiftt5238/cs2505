#include <stdio.h>

int main(){
	int first_variable = 10;
	double c = 10.200; 
	int *first_pointer = &first_variable; //access the address of first_variable using &.
	int second_variable = 20; 
	printf("%d %p %d\n", first_variable, first_pointer, *first_pointer); //value of first_variable can be accessed by DEREFERENCING first_pointer using * at the beginning of it.
	first_pointer = &second_variable; //access the address of second_variable.
	int **first_pointer_of_pointer;  //pointer of a pointer
	first_pointer_of_pointer = &first_pointer; // access address of a pointer
	printf("%p %d\n", first_pointer_of_pointer, **first_pointer_of_pointer); //if you want to access the value of a pointer of a pointer, you have to dereference it twice.
	*first_pointer = 1000;
	printf("%d\n", second_variable);	
	return 0;
}
