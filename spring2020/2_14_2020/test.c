#include <stdio.h>

int foo(){
	static int a = 10;
	printf("%d\n", a);
	a++;
}


int main(){
	foo();
	foo();
	foo();
	foo();
	return 0;

}
