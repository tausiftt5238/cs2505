#include <stdio.h>
#include <string.h>

int main(){
	char a[] = "hello";
	char b[] = "hello";
	char c[] = "world";
	strncmp(a,b,5);
	strncat(a,b,5);
	strcat(strcat(a,b),c);
	strlen(a); 
	char x[10]; 
