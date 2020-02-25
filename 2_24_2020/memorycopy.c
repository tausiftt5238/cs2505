#include <stdio.h>
#include <string.h>

int main(){
	char a[20] = "Hello world\n";
	char b[7] = "foobar";
	printf("%s\n", a);
	printf("%s\n", b);
	strncpy(a,b,2);
	printf("%s\n", a);
	printf("%s\n", b);
	return 0;
}
