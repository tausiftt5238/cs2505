#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
int main(){
	int a = 10;
	int b = 20;
	int *c = &a; 
	int *d = &b;
	int *e = &a;
	printf("%d\n", c == d); //will return false, because they point to different variable's addresses.
	printf("%d\n", c == e);	// will return true, because they point to the same address.
	int *f; 
	printf("%d\n", *f);
	int *p = NULL; 
	uint8_t ac[100] = {1,2,3,4,5};
	uint8_t *bd = ac; 
	printf("%d\n", *bd);
	printf("%d\n", *(uint16_t*)bd);
	return 0;
}
