#include <stdio.h>
#include <string.h>

int main(){
	char a[] = "hello";
	char b[] = "hello";
	char c[] = "world";
	strcmp(a,b); //compares a against b. The whole string in this case.
	strncmp(a,b,5);	//compares 5 letters of the two strings

	strcat(a,b); //copies content of b, and puts them at the end of a. In this case, output will be "hellohello". it did a + b.
	strncat(a,b,5);	//copies 5 letters from the 2nd parameter (variable b in this case) to first parameter (a in this case)
	strcat(strcat(a,b),c); // if you want to concat multiple strings at once
	
	strlen(a); 	//to find out length of the string. It returns the number of characters before the null terminator (0 or '\0' )
	char x[10]; 
	return 0;
}