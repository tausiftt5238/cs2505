#include <stdio.h>

int sum(int a, int b){	//value of the two paramters won't change from where they were called.
	a = 100; 
	b = 200;
	return a + b ;
}

void swap(int *a, int *b){ //pointers are used as parameter
	int temp = *a;
	*a = *b;
	*b = temp;	
}

int main(){
	int a = 10;
	int b = 20;
	printf("%d\n", sum(a,b));
	printf("a = %d b = %d\n", a,b);
	swap(&a,&b);	//the values will change because their pointers were sent as parameters. 
	printf("a = %d b = %d\n", a,b);
	int a[100] = {1,2,3,4};
	a[1] 
	*(a + 1);
	int *p = a;
	*(p++);
	return 0;
}
