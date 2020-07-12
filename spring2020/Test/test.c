#include <stdio.h>
#include <stdbool.h>

struct foo{
//	bool a;
//	char b,c;
	int d;
	double e;
	short f;
	float g;
	double h;
	char *cptr;
	float *fptr;
	int x;
};

int main(){
	printf("%d\n",sizeof(struct foo));
	return 0;
}
