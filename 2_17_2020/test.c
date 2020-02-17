#include <stdio.h>
#include <stdlib.h>
int foo(int a, int b){
	a = 10;
	return a + b;
}

void bar(int a[], int size){
	a[2] = 100;
	a[3] = 200;
}

//If you want to return an array, make sure you do it dynamically. Usually you don't wanna return local arrays, because they
//should be lost after they get outside the scope.
int* foo_bar(){
	//int a* = malloc(100* sizeof(int));
	//int a[100] = {1,23,4,5,6,7};
	int* a = (int*)malloc(100 * sizeof(int));
	return a;
}

int main(){
	int c[100] = {1,2,3,4,5 };
	int d = 100;
	int a, b;
	a = 5;
	b = 6;
	for(int i = 0 ; i < 5; i ++){
		printf("%d\n", c[i]);
	}
	bar(c,100);	
	for(int i =0; i < 5; i++){
		printf("%d\n", c[i]);
	}	
	return 0;
}
